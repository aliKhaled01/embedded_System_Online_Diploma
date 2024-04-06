#ifndef ALRAM_GUARH_H
#define ALRAM_GUARH_H
#include "state.h"
#include "Platfrom_Types.h"
#ifndef ALARM_HIGH
#define ALARM_HIGH 1
#endif

#ifndef ALARM_LOW
#define ALARM_LOW 0
#endif

typedef enum
{
AM_idle,
AM_alarming
}AM_state_id;

/*
states declrations for the CA SWC
*/
STATE_define(AM_idle);
STATE_define(AM_alarming);

/*
State pointer to function
*/
extern void(*AM_state)(void) ;

/*
Prototypes
*/
void Alram_Write_Data(uint8 emergancy_flag , uint8 duration);

#endif