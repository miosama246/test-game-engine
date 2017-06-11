
#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"
#include "unistd.h"
#include "engine.h"


#define true 1
#define STAGEMAX 255
#define PROCESSMAX 255
#define SCRWIDTH 640
#define SCRHEIGHT 480

#include "process.h"
#include "stage.h"

#include "stage.c"
#include "process.c"



// main stuff =================================================================================
static void MainLoop();

En_AppConfig AppConfig = {
	SCRWIDTH,
	SCRHEIGHT,
	0,
	StageAdd
};



//Screen Config ===============================================================================

static uint16_t ScrWidth;
static uint16_t ScrHeight;


