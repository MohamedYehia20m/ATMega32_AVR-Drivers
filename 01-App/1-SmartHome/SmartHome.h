#ifndef SMARTHOME_H_
#define SMARTHOME_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO.h"
#include "ADC.h"
#include "LCD2.h"
#include "KBD.h"
#include "internalEEPROM.h"

#define num_of_users 4

void SH_VidLogin(void);

void SH_VidSimpleLogin(void);

u8 K_Pad_Conversation(void);
u16 get_id(void);
u16 get_pass(void);

void SH_VidInitAC(void);

void SH_VidInitLightSystem(void);

void SH_VidInitDCMotor(void);

u8 safe_pass_status(u16 address);

u32 safe_read_pass(u16* address);

void safe_set_pass( u16* address, u16 pass_status);

u8 safe_check_pass(u16* address);

#endif

