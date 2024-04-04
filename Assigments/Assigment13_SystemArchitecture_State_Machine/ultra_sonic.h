#include "state.h"
typedef enum
{
Ultra_Sonic_busy
}Ultra_Sonic_state_id;

void UltraSonic_init(void);
/*
states declrations for the Ultra_Sonic SWC
*/
STATE_define(Ultra_Sonic_busy);

/*
State pointer to function
*/
extern void(*Ultra_Sonic_state)(void) ;