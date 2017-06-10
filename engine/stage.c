//uint8_t En_StageDefault = 0;

void StageCleanUp () {
		ProcessCleanAll();
	}

void En_StageSwitch (uint8_t ID) {

	StageCleanUp();
	StageCurrent = ID;
	if (!(ID < StageCount)) {
		printf("Cannot switch to stage with this ID:%d\n",ID);
		exit(0);
	} else {
		printf("Preparing stage %d...\n",ID);
		Stages[ID].SetupFunc();
		}
}

uint8_t StageAdd (void (*SetupFunc)()) {
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

