// ***************************************************************************************
// ***************************************************************************************
//
//		Name : 		common.h	
//		Author :	Paul Robson (paul@robsons.org.uk)
//		Date : 		20th November 2023
//		Reviewed :	No
//		Purpose :	General Include File.
//
// ***************************************************************************************
// ***************************************************************************************

#ifndef _COMMON_H
#define _COMMON_H
//
//		Void Function Pointer.
//
typedef void (*VOIDFUNC)();
//
//		RP2040 specific includes
//
#ifdef PICO
#include "pico/stdlib.h"
#include "pico/stdio.h"
#include "hardware/gpio.h"
#endif
//
//		Neo6502 Includes
//
#include "interface/keyboard.h"
#include "interface/graphics.h"
#include "interface/console.h"
#include "interface/timer.h"
#include "interface/sound.h"
#include "interface/memory.h"
#include "interface/dispatch.h"
//
//		Other Includes
//
#include "string.h"

#endif