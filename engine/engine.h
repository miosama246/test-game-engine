//screen
extern uint16_t En_ScreenWidth;
extern uint16_t En_ScreenHeight;


//App setup function

extern void AppSetup();



//Stage

extern uint8_t En_StageAdd (void (*SetupFunc)());
extern uint8_t En_StageCount();
extern uint8_t En_StageDefault;
extern void En_StageSwitch(uint8_t ID);

//Process

extern uint8_t En_ProcessAdd (void (*Func)());
extern uint8_t En_ProcessGetCurrent();
