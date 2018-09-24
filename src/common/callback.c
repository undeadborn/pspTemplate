#include <pspkernel.h>

static int exitRequest  = 1;

int isRunning() {
	return exitRequest;
}

int exitCallback(int arg1, int arg2, void *common) {
	exitRequest = 0; 
	return 0;
} 

int callbackThread(SceSize args, void *argp) {
	int callbackID = sceKernelCreateCallback("Exit Callback", exitCallback, NULL);
	sceKernelRegisterExitCallback(callbackID);
	sceKernelSleepThreadCB();
	return 0;
} 

int setupExitCallback() {
	int threadID = sceKernelCreateThread("Callback Update Thread", callbackThread, 0x11, 0xFA0, THREAD_ATTR_USER, 0);
	if (threadID >= 0) {
		sceKernelStartThread(threadID, 0, 0);
	}
	return threadID; 
}