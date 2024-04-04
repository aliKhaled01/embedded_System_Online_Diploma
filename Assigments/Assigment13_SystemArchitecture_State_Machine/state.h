/*
State function automation
*/
#define  STATE_define(statFUN) void ST##_##statFUN(void)
#define  STATE(statFUN) ST##_##statFUN

/*
States Connections
*/
void US_Get_Distance(int* d);
void DC_Motor_Set_Speed(int s);