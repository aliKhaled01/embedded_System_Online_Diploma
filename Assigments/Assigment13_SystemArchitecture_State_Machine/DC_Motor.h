#include "state.h"
typedef enum
{
DC_Motor_idle,
DC_Motor_busy
}DC_Motor_state_id;

/*
states declrations for the DC_Motor SWC
*/
STATE_define(DC_Motor_idle);
STATE_define(DC_Motor_busy);

/*
State pointer to function
*/
extern void(*DC_Motor_state)(void) ;


/*
Init Function
*/
void DC_Init();