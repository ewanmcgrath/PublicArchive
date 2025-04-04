#include "BasicDemo.h"
#include "FreeGLUTCallbacks.h"

int main(int argc, char** argv)
{
	BasicDemo demo;
	//PlaySound("Music.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
	return glutmain(argc, argv, 1920, 1080, "Pachinko Demo", &demo);
}