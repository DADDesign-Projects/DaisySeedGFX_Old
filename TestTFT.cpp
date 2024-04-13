#include "Debug.h"
#include "daisy_seed.h"
#include "daisysp.h"
#include "GFX.h"
#include "Vanilla20pt.h"
#include "Pap.h"

using namespace daisy;
using namespace daisysp;

DaisySeed hw;


FIFO_Data DMA_BUFFER_MEM_SECTION __Fifo;
RGB DSY_SDRAM_BSS __FrameBuff[TFT_WIDTH*TFT_HEIGHT];
cGFX __Display;
cFont Vanilla20(&VanillaExtractRegular20pt7b);

void AudioCallback(AudioHandle::InputBuffer in, AudioHandle::OutputBuffer out, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		out[0][i] = in[0][i];
		out[1][i] = in[1][i];
	}
}

int main(void)
{
	hw.Init();
	hw.SetAudioBlockSize(4); // number of samples handled per callback
	hw.SetAudioSampleRate(SaiHandle::Config::SampleRate::SAI_48KHZ);
	hw.StartAudio(AudioCallback);
	hw.StartLog(false);
	D_PRINT("Debut ----------\r\n");
	__Display.Init(__FrameBuff, &__Fifo, TFT_WIDTH, TFT_HEIGHT);
	__Display.setRotation(Rotation::Degre_90);

	uint8_t TabColorMax = 12;
	cColor TabColor[] = {
		cColor(255, 0, 0),
		cColor(0, 255, 0),
		cColor(0, 0, 255),
		cColor(52, 225, 235),
		cColor(52, 235, 171),
		cColor(95, 235, 52),
		cColor(232, 235, 52),
		cColor(235, 171, 52),
		cColor(235, 89, 52),
		cColor(235, 52, 95),
		cColor(217, 52, 235),
		cColor(52, 52, 235),
	};

	uint16_t x = 110;
	uint16_t y = 140;
	__Display.drawR8G8B8Image(x, y, 100, 100, Pap_map);

	cColor Color(0,0,0);
	uint8_t CtColor = 0;
	
	while(1) {
		x = 30;
		y = 50;

		Color = TabColor[CtColor];
		__Display.setCursor(x, y);
		__Display.setFont(&Vanilla20);

		__Display.setTextFrontColor(Color);
		__Display.setTextBackColor(cColor(0,0,0));
		__Display.drawTransText("Bonjour !");
		__Display.drawLine(x,y+1, x+Vanilla20.getTextWidth("Bonjour !"), y+1, Color);	
		__Display.drawLine(x,y+2, x+Vanilla20.getTextWidth("Bonjour !"), y+2, Color);	
		
		y = y + 20;
		uint16_t dx = 50;
		uint16_t dy = 60;

		__Display.drawRect(x, y, dx, dy, Color);
		__Display.drawLine(x, y, x+dx, y+dy, Color);
		__Display.drawLine(x, y+dy, x+dx, y, Color);

		x = x + 50 + 20;

		__Display.drawFillRect(x, y, dx, dy, Color);
		__Display.drawLine(x, y, x+dx, y+dy, cColor(0,0,0));
		__Display.drawLine(x, y+dy, x+dx, y, cColor(0,0,0));

		x = x + 50 + 45;
		y = y + 25;
		dx = 25;

		__Display.drawCircle(x, y, dx, Color);
		__Display.drawLine(x-dx, y, x+dx, y, Color);
		__Display.drawLine(x, y-dx, x, y+dx, Color);

		x = x + 20 + 50;

		__Display.drawFillCircle(x, y, dx, Color);
		__Display.drawLine(x-dx, y, x+dx, y, cColor(0,0,0));
		__Display.drawLine(x, y-dx, x, y+dx, cColor(0,0,0));

		__Display.drawArc(x, y+100, dx, 90, 270, Color);
		
		char Buff[20];
		
		__Display.setCursor(30, 200);
		sprintf(Buff, "%02d", CtColor);
		__Display.drawText(Buff,true);
		
		CtColor += 1;
		if(CtColor >= TabColorMax) CtColor = 0;
		
		__Display.setCursor(30, 200);
		sprintf(Buff, "%02d", CtColor);
		__Display.drawText(Buff);

		__Display.FlushFrame();

		System::Delay(1500);
	}
}
