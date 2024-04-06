#include "Pressure_Interfacing.h"
#include "HPressure_Avoidance.h"
#include "Platfrom_Types.h"
#include "../HW_AB_Src/driver.h"

/*
SWC ATTRIBUTES
*/
boolean pressure_value_is_updated = TRUE;
uint32 pressure_sensor_current_value =0;
/*
State pointer to functions
*/

void(*PI_state)(void) = NULL ;

STATE_define(PressureRx)
{

/*
State ID
*/
PI_state_id state_id =  PressureRx;

/*
State Name
*/
PI_state = STATE(PressureRx);

/*
Read Pressure Value
*/

pressure_sensor_current_value = getPressureVal(&pressure_value_is_updated);
if(pressure_value_is_updated == TRUE)
{
/*
State Transition
*/
PI_state = STATE(PressureTx);
}


else
{
PI_state = STATE(PressureRx);
/*
Do No Thing , Stay in the Rx State as the pointer PI_state is still points to the RX state
*/
}

}

STATE_define(PressureTx)
{

/*
State ID
*/
PI_state_id state_id =  PressureTx;

/*
State Name
*/
PI_state = STATE(PressureTx);

/*
Write Data
*/
Pressure_write_data(pressure_sensor_current_value);

/*
State Transition
*/
PI_state = STATE(PressureRx);
}

