# Project Name
TARGET = TestTFT

# Sources
CPP_SOURCES = TestTFT.cpp TFT_SPI.cpp Frame.cpp GFX.cpp
# Library Locations
LIBDAISY_DIR = ../../../../Desktop/DaisyExamples/libDaisy/
DAISYSP_DIR = ../../../../Desktop/DaisyExamples/DaisySP/

# Core location, and generic Makefile.
SYSTEM_FILES_DIR = $(LIBDAISY_DIR)/core
include $(SYSTEM_FILES_DIR)/Makefile
