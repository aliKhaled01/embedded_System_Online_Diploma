#include "Ultra_Sonic.h"
#include <stdio.h>
#include  <stdlib.h>
/*
SWC ATTRIBUTES
*/
int Ultra_Sonic_distance = 0;
/*
State pointer to functions
*/

void(*Ultra_Sonic_state)(void) =NULL ;
void UltraSonic_init()
{
	printf("ULTRASNOC_INIT");
}
STATE_define(Ultra_Sonic_busy)
{
printf("busy_STATE\n");
//state name
Ultra_Sonic_state_id state_id =  Ultra_Sonic_busy;

//Get Distance Interface
Ultra_Sonic_distance = UltraSonic_GET_distance_randomly(10);

Ultra_Sonic_state = STATE(Ultra_Sonic_busy);

}

int UltraSonic_GET_distance_randomly(int rand_upper)
{
int rand_num = (rand()%rand_upper);
return rand_num ;
}

void US_Get_Distance(int* d)
{
	*d = Ultra_Sonic_distance;
}