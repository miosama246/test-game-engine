static void ProcessPlayAll();
static void ProcessCleanAll();

static uint8_t ProcessCount = 0;
static uint8_t ProcessCurrent;

typedef struct {
	uint8_t ID;
	void (*Func)();
} Process;

static Process Processes[PROCESSMAX];

