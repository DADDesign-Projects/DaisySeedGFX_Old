# DaisySeedGFX

## Author

DAD Design

## Description
TFT graphical display library for Daisy Seed. ST7789 driver

Présentation
-----------------
DaisySeedGFX est une bibliothèque graphique pour la plateforme Daisy Seed de Electrosmith.
La bibliothèque prend en charge pour le moment uniquement le contrôleur ST7789. Je pense intégrer rapidement le contrôleur ST7735. A priori la bibliothèque doit pouvoir être adaptée à n’importe quel contrôleur assez facilement.

La bibliothèque utilise un frame buffer intermédiaire ente les primitives graphiques et le contrôleur. Les modifications réalisées dans le frame buffer sont transmises au contrôleur utilisant les transferts SPI sous DMA. Afin de réduire les transferts le frame buffer est divisé en blocs -> seuls les blocs modifiés sont transférés vers l’écran.

Les primitives graphiques sont minimalistes, elles pourront être complétées en fonction des besoins.

Configuration
-----------------
Le fichier UserConfig.h permet d’adapter la bibliothèque aux différentes implémentations matérielles.

Le fichier Font.h est utilisé pour définir les fonts chargées. Chaque font est décrite dans un fichier xxx.h ce fichier peut être créé en utilisant l’outil https://rop.nl/truetype2gfx/

Outil de développement
--------------------------------
Le code est modifiable et compilable sous VS Code dans l’environnement de développement du Daisy Seed (voir le https://github.com/electro-smith).

Le fichier Makefile est à adapter en fonction de l’emplacement des librairies : 
  LIBDAISY_DIR = ../../../Desktop/DaisyExamples/libDaisy/
  DAISYSP_DIR = ../../../Desktop/DaisyExamples/DaisySP/

Le fichier c_cpp_properties.json est aussi à adapter :
"includePath": [
  "${workspaceFolder}/**",
  "${workspaceFolder}/../../../Desktop/DaisyExamples/libDaisy//**",
  "${workspaceFolder}/../../../Desktop/DaisyExamples/DaisySP//**"


