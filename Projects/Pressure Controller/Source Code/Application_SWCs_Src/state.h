/*
State function automation
*/
#define  STATE_define(statFUN) void ST##_##statFUN(void)
#define  STATE(statFUN) ST##_##statFUN