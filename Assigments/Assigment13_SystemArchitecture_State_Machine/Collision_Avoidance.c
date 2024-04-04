#include "Collision_Avoidance.h"
#include <stdio.h>
#include  <stdlib.h>
/*
SWC ATTRIBUTES
*/
int CA_speed = 0;
int CA_distance = 0;
int CA_threshould = 50;

/*
State pointer to functions
*/

void(*CA_state)(void) =NULL ;

STATE_define(CA_waiting)
{
printf("WAITING_STATE\n");
//state name
CA_state_id state_id =  CA_waiting;

//Get Distance Interface
US_Get_Distance(&CA_distance);

//event check
if(CA_distance <=CA_threshould)
{
CA_state = STATE(CA_waiting);
CA_speed=0;
}
else
{
CA_state = STATE(CA_driving);
CA_speed=30;
}
DC_Motor_Set_Speed(CA_speed);
}

STATE_define(CA_driving)
{
printf("DRIVING_STATE");
//state name
CA_state_id state_id =  CA_driving;

//Get Distance Interface
US_Get_Distance(&CA_distance);

//event check
if(CA_distance <=CA_threshould)
{
CA_state = STATE(CA_waiting);
CA_speed=0;
}
else
{
CA_state = STATE(CA_driving);
CA_speed=30;
}
DC_Motor_Set_Speed(CA_speed);
}
