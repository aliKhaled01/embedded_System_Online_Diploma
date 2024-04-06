#include "../HW_AB_Src/driver.h"
#include "HPressure_Avoidance.h"
#include "Pressure_Interfacing.h"
#include "Alarm_Monitoring.h"
void setup()
{
/*
init all drivers
*/
GPIO_INITIALIZATION();
//init IRQ...
//init SWCs

/*
set states pointer for each SWC
*/
HPA_state = STATE(HPA_idle);
AM_state = STATE(AM_idle);
PI_state = STATE(PressureRx);

}

int main()
{
    setup();
	while (1)
	{
        PI_state();
        HPA_state();
        AM_state();
	}

}
