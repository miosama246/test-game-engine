#include "stdint.h"
#include "engine/engine.h"
#include "stdio.h"

static uint16_t time = 0;



static void A () {
	printf("Hello from A\n");
	time++;
	if (time == 10) {
		En_StageSwitch(1);
	}
}
static void B () {
	printf("Hello from B\n");
}

static void C () {
	printf("Hello from C %d\n",En_ProcessGetCurrent());
}

static void HelloWorldStage () {
	En_ProcessAdd(A);
	En_ProcessAdd(B);
}

static void ByeWorldStage () {
	En_ProcessAdd(B);
	En_ProcessAdd(C);
	}	

void AppSetup (En_AppConfig* Config) {

	Config->ScreenWidth = 1024;
	Config->ScreenHeight = 768;
	Config->StageDefault = 0;
	Config->StageAdd(HelloWorldStage);
	Config->StageAdd(ByeWorldStage);
	/*
	for (int i = 0;i<255;i++) {
		//printf("%d\n",En_StageAdd(NULL));
		//printf("%d\n",En_StageCount());
	}
	*/
}
