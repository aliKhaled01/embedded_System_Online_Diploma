#include "HPressure_Avoidance.h"
#include "Alarm_Monitoring.h"
#include "Platfrom_Types.h"
#include "../HW_AB_Src/driver.h"

/*
SWC ATTRIBUTES
*/
uint32 pressure_current_value = 0;
/*
State pointer to functions
*/

void(*HPA_state)(void) = NULL ;

STATE_define(HPA_idle)
{

/*
State ID
*/
HPA_state_id state_id =  HPA_idle;

/*
State Name
*/
HPA_state = STATE(HPA_idle);

/*
Event Check
*/
if(pressure_current_value > MAX_PRESSURE)
{
/*
State Transition
*/
HPA_state = STATE(HPA_notifing);
}

else
{
    HPA_state = STATE(HPA_idle);
    /*
    Do no thing , stay in the same state checking for the pressure values 
    */
}
}

STATE_define(HPA_notifing)
{

/*
State ID
*/
HPA_state_id state_id =  HPA_notifing;

/*
State Name
*/
HPA_state = STATE(HPA_notifing);

/*
Action
*/
Alram_Write_Data(TRUE, ALARM_DURATION);

/*
State Transition
*/
HPA_state = STATE(HPA_idle);
}
void Pressure_write_data(uint32 pressure_value)
{
    pressure_current_value = pressure_value;
}