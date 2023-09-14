#ifndef EX_INT_H_
#define EX_INT_H_


void EX_INT0VidInit(void);
void EX_INT1VidInit(void);
void EX_INT2VidInit(void);

void TOGGLE_LED0(void);
void TOGGLE_LED1(void);
void TOGGLE_LED2(void);

void EX_INT0VidSetCallBack(void (*ptr)(void)  );
void EX_INT1VidSetCallBack(void (*ptr)(void)  );
void EX_INT2VidSetCallBack(void (*ptr)(void)  );


#endif
