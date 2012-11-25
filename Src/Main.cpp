#define WIN32_LEAN_AND_MEAN

#include "JFF.h"
using namespace JFF;

//-
#define JFFStartApp(RenderAdapter,pRenderData,width,height) //-


INT WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpcmdLine,int nShowCmd)
{
	JFFSystem::getSystem().Initinalize(300,300);
	JFFSystem::getSystem().InitRenderEnvironment(JFFSystem::_RENDER_TYPE_D3D);	//-��ʼ����Ⱦ����
	JFFSystem::getSystem().setRenderData(new D3DRenderData());	//-������Ⱦ����
	JFFSystem::getSystem().MainLoop();
	JFFSystem::getSystem().Terminate();
	return 0;
}
