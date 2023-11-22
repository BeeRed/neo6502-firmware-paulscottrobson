// *******************************************************************************************************************************
// *******************************************************************************************************************************
//
//		Name:		hardware.c
//		Purpose:	Hardware Emulation
//		Created:	22nd November 2023
//		Author:		Paul Robson (paul@robsons.org.uk)
//
// *******************************************************************************************************************************
// *******************************************************************************************************************************

#include "sys_processor.h"
#include "hardware.h"
#include "gfx.h"
#include <stdio.h>
#include "common.h"
#include "interface/kbdcodes.h"

// *******************************************************************************************************************************
//												Reset Hardware
// *******************************************************************************************************************************

void HWReset(void) {
}

// *******************************************************************************************************************************
//												  Reset CPU
// *******************************************************************************************************************************

void HWSync(void) {
}

// *******************************************************************************************************************************
//												Read 100Hz timer
// *******************************************************************************************************************************

uint32_t TMRRead(void) {
	return GFXTimer() / 10;
}

// *******************************************************************************************************************************
//											Keyboard Sync/Initialise dummies
// *******************************************************************************************************************************

void KBDSync(void) { }
void KBDInitialise(void) { }

// *******************************************************************************************************************************
//											   Sound system initialise
// *******************************************************************************************************************************

int SNDInitialise(void) {
	return 1; 	
}

// *******************************************************************************************************************************
//										  Receive SDL Keyboard events
// *******************************************************************************************************************************

#include "hid2sdl.h"

void HWQueueKeyboardEvent(int sdlCode,int isDown) {
	int found = -1;
	for (int i = 0;i < SDL2HIDSIZE;i++) {
		if (SDL2HIDMapping[i] == sdlCode) found = i;
	}
	if (found >= 0) {
		int modifier = 0;
		if (GFXIsKeyPressed(GFXKEY_SHIFT)) modifier |= KEY_SHIFT;
		if (GFXIsKeyPressed(GFXKEY_CONTROL)) modifier |= KEY_CONTROL;
		KBDEvent(isDown,found,modifier);
	}
}