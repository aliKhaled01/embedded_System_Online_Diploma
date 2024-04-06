#ifndef PRESSURE_INTERFACING_GUARH_H
#define PRESSURE_INTERFACING_GUARH_H
#include "state.h"

typedef enum
{
PressureRx,
PressureTx
}PI_state_id;

/*
states declrations for the CA SWC
*/
STATE_define(PressureRx);
STATE_define(PressureTx);

/*
State pointer to function
*/
extern void(*PI_state)(void) ;

#endif