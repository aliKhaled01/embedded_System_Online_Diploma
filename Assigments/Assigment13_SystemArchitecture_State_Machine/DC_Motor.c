#include "DC_Motor.h"
#include <stdio.h>
#include  <stdlib.h>
/*
SWC ATTRIBUTES
*/

int DC_Motor_speed = 0;

/*
State pointer to functions
*/

void(*DC_Motor_state)(void) =NULL ;

void DC_Init()
{
	printf("DC INIT");
}
STATE_define(DC_Motor_idle)
{
printf("idle_STATE\n");
//state name
DC_Motor_state_id state_id =  DC_Motor_idle;
DC_Motor_state = STATE(DC_Motor_idle);
}

STATE_define(DC_Motor_busy)
{
printf("busy_STATE\n");
//state name
DC_Motor_state_id state_id =  DC_Motor_busy;
/*
write the speed PWM(...)
*/
DC_Motor_state = STATE(DC_Motor_idle);
}

void DC_Motor_Set_Speed(int speed)
{
	DC_Motor_speed = speed;
	DC_Motor_state = STATE(DC_Motor_busy);
}