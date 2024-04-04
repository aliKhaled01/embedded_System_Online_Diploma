#include "Collision_Avoidance.h"
#include "DC_Motor.h"
#include "ultra_sonic.h"
void setup()
{
//init all drivers
//init IRQ...
//init SWCs
UltraSonic_init();
DC_Init();
//set states pointer for each SWC
CA_state = STATE(CA_waiting);
Ultra_Sonic_state = STATE(Ultra_Sonic_busy);
DC_Motor_state = STATE(DC_Motor_idle);
}

void main()
{
setup();
while(1)
{
//call state for each SWC
Ultra_Sonic_state();
CA_state();
DC_Motor_state();
}
}