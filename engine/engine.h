typedef struct {
	uint16_t ScreenWidth;
	uint16_t ScreenHeight;
	uint8_t StageDefault;
	uint8_t (*StageAdd)(void (*SetupFunc)());
} En_AppConfig;





//App setup function

extern void AppSetup(En_AppConfig*);



//Stage

//extern uint8_t En_StageAdd (void (*SetupFunc)());
extern uint8_t En_StageCount();
extern void En_StageSwitch(uint8_t ID);

//Process

extern uint8_t En_ProcessAdd (void (*Func)());
extern uint8_t En_ProcessGetCurrent();
