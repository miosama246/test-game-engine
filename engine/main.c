#include "main.h"

//uint16_t En_ScreenWidth = SCRWIDTH;
//uint16_t En_ScreenHeight = SCRHEIGHT;

int main (int argc,char * argv[]) {
	
	//Setup the game!
	printf("=== Setting up the game!\n");

	AppSetup(&AppConfig);

	ScrWidth = AppConfig.ScreenWidth;
	ScrHeight = AppConfig.ScreenHeight;
	
	StageCurrent = AppConfig.StageDefault;

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
