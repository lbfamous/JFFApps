#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <tchar.h>
#include "JFFSystem.h"



using namespace JFF;

INT WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpcmdLine,int nShowCmd)
{
	JFFSystem::getSystem().Initinalize(640,480);
	JFFSystem::getSystem().MainLoop();
	return 0;
}
