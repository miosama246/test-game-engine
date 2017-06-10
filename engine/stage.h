static void StageCleanUp ();
static uint8_t StageAdd(void (*SetupFunc)());

//uint8_t En_StageDefault = 0;

static uint8_t StageCurrent;
static uint8_t StageCount = 0;



typedef struct {
	uint8_t ID;
	void (*SetupFunc)();	
} Stage;

static Stage Stages[STAGEMAX];
