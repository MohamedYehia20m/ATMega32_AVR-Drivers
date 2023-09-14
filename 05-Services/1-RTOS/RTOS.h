
void RTOS_StartOS ( void (*AP_CallBack) (void) );
void RTOS_CreateTask (void (*AP_CallBack) (void) , u16 A_Taskperiodecity , u8 A_Priority);
void Scheduler ( void );


