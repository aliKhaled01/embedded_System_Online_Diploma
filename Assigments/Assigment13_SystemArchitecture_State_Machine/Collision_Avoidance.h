#include "state.h"
typedef enum
{
CA_waiting,
CA_driving
}CA_state_id;

/*
states declrations for the CA SWC
*/
STATE_define(CA_waiting);
STATE_define(CA_driving);

/*
State pointer to function
*/
extern void(*CA_state)(void) ;