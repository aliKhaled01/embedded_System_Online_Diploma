#ifndef HPAVOIDANCE_GUARH_H
#define HPAVOIDANCE_GUARH_H
#include "state.h"


#define MAX_PRESSURE 20
#define ALARM_DURATION 60
typedef enum
{
HPA_idle,
HPA_notifing
}HPA_state_id;

/*
states declrations for the CA SWC
*/
STATE_define(HPA_idle);
STATE_define(HPA_notifing);

/*
State pointer to function
*/
extern void(*HPA_state)(void) ;

/*
Prototypes
*/


#endif