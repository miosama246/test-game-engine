#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"
#define SCRWIDTH 640
#define SCRHEIGHT 480
#include "engine.h"
#define STAGEMAX 255
#define PROCESSMAX 255
#define true 1
#include "unistd.h"

uint16_t En_ScreenWidth = SCRWIDTH;
uint16_t En_ScreenHeight = SCRHEIGHT;

static void MainLoop();

//Screen Config ==========================================================

static uint16_t ScrWidth;
static uint16_t ScrHeight;

//Stage ================================================================

uint8_t En_StageDefault = 0;

static uint8_t StageCurrent;
static uint8_t StageCount = 0;


typedef struct {
	uint8_t ID;
	void (*SetupFunc)();	
} Stage;

static Stage Stages[STAGEMAX];

//Process ============================================================

static void ProcessPlayAll();

static uint8_t ProcessCount = 0;
static uint8_t ProcessCurrent;

typedef struct {
	uint8_t ID;
	void (*Func)();
} Process;

static Process Processes[PROCESSMAX];


// main ==============================================================

int main (int argc,char * argv[]) {
	
	//Setup the game!
	printf("=== Setting up the game!\n");

	AppSetup();

	ScrWidth = En_ScreenWidth;
	ScrHeight = En_ScreenHeight;
	
	StageCurrent = En_StageDefault;

	//Print Debug
	printf("ScreenWidth=%d\nScreenHeight=%d.\nWill not be able to change during runtime.\n",ScrWidth,ScrHeight);
	printf("Default Stage ID:%d\n",StageCurrent);
	printf("=== End of setup debug message\n");	
	//Done setup
	printf("Let us play the default Stage\n");
	En_StageSwitch(StageCurrent);
	
	MainLoop();
}

	void MainLoop () {
	while (true) {
		sleep(1);
		printf("Begin frame\n");
		ProcessPlayAll();
		printf("End frame\n");
	}
}

// ==================================================================

static void ProcessCleanAll () {
	for (uint8_t i = 0;i<PROCESSMAX;i++) {
		Processes[i].Func = NULL;
	}
	ProcessCount = 0;
}

static void ProcessPlayAll () {
	for (uint8_t i = 0;i<ProcessCount;i++) {
		ProcessCurrent = i;
		Processes[i].Func();
	}
}

uint8_t En_ProcessGetCurrent() {
	return ProcessCurrent;
}

uint8_t En_ProcessAdd (void (*Func)()) {
	uint8_t current = ProcessCount;

	if (Func==NULL) {
		printf("Func is NULL !! \n");
		exit(0);
	}
	if (!(ProcessCount < PROCESSMAX)) {
		printf("Cannot add more process! \n");
		exit(0);
	}
	ProcessCount++;
	Processes[current].ID = current;
	Processes[current].Func = Func;
	printf("add process %d to stage %d\n",current,StageCurrent);
	return current;

}

//Stage ==============================================================

static void StageCleanUp () {
		ProcessCleanAll();
	}

void En_StageSwitch (uint8_t ID) {

	StageCleanUp();
	StageCurrent = ID;
	Stages[ID].SetupFunc();
	if (!(ID < StageCount)) {
		printf("Cannot switch to stage with this ID:%d\n",ID);
		exit(0);
	} else {
		printf("Preparing stage %d...\n",ID);
		}
}

uint8_t En_StageAdd (void (*SetupFunc)()) {
	uint8_t current = StageCount;
	if (StageCount < STAGEMAX) {
		StageCount++;
	
		Stages[current].ID = current;
		Stages[current].SetupFunc = SetupFunc;
		
		printf("add stage ID %d\n",current);
		
		if (SetupFunc == NULL) {
			printf("SetupFunc is null%x\n",SetupFunc);
			exit(0);
		} else {
			printf("OK! SetupFunc is not null %x\n",SetupFunc);
		}


		return current;
	} else {
		printf("Can not add more stages\n");
		exit(0);
	}

}

uint8_t En_StageCount () {
	return StageCount;
}

// ====================================================================
