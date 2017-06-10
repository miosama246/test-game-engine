
void ProcessCleanAll () {
	for (uint8_t i = 0;i<PROCESSMAX;i++) {
		Processes[i].Func = NULL;
	}
	ProcessCount = 0;
}

void ProcessPlayAll () {
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
	printf("add process %d address %x to stage %d\n",current,Func,StageCurrent);
	return current;

}

