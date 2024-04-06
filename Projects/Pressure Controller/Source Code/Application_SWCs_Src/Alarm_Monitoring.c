#include "Alarm_Monitoring.h"
#include "Platfrom_Types.h"
#include "../HW_AB_Src/driver.h"
/*
SWC ATTRIBUTES
*/
static uint8 alarm_emergancy_flag = 0;
static uint8 alarm_duration = 0 ;
/*
State pointer to functions
*/

void (*AM_state)(void) =NULL ;

STATE_define(AM_idle)
{
/*
State ID
*/
AM_state_id state_id =  AM_idle;
/*
State Name
*/
AM_state = STATE(AM_idle);

/*
Event Check
*/
if(alarm_emergancy_flag == ALARM_HIGH)
{
/*
State Transition
*/
AM_state = STATE(AM_alarming);
alarm_emergancy_flag = ALARM_LOW;
}
else
{
/*
stay in idle state
*/
AM_state = STATE(AM_idle);
}

}

STATE_define(AM_alarming)
{

/*
State ID
*/
AM_state_id state_id =  AM_alarming;
/*
State Name
*/
AM_state = STATE(AM_alarming);

/*
State Action
*/
Set_Alarm_actuator(ALARM_LOW);
Delay(alarm_duration);
Set_Alarm_actuator(ALARM_HIGH);

/*
State Transition
*/
AM_state = STATE(AM_idle);

}

void Alram_Write_Data(uint8 emergancy_flag , uint8 duration)
{
alarm_emergancy_flag = emergancy_flag;
alarm_duration = duration ;
}