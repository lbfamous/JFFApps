#include "JFFSystem.h"

namespace JFF
{

	const TCHAR* JFFSystemUtility:: _JFFAPP_CLASS_NAME	= L"JFF_CLASS_";
	const TCHAR* JFFSystemUtility::_JFFAPP_DEFAULT_WIN_NAME = L"JFF_Ĭ�ϴ���";
	LRESULT WINAPI JFFSystemUtility::WindowProc(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
	{
		switch(uMsg)
		{
		case WM_DESTROY:
			{
				PostQuitMessage(0);
				return 0;
			}
			break;
		default:
			break;
		}
		return ::DefWindowProc(hWnd,uMsg,wParam,lParam);
	}

	void JFFSystem::Initinalize(int width, int height)
	{

		HINSTANCE hInstance = ::GetModuleHandle(0);
		WNDCLASS  JFFAppClass;
		JFFAppClass.cbClsExtra = 0L;
		JFFAppClass.cbWndExtra = 0L;
		JFFAppClass.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
		JFFAppClass.hCursor		  = ::LoadCursor(NULL,IDC_ARROW);
		JFFAppClass.hIcon		  = ::LoadIcon(NULL,IDI_APPLICATION);
		JFFAppClass.hInstance	  = hInstance;
		JFFAppClass.lpfnWndProc	  = (WNDPROC)JFFSystemUtility::WindowProc;
		JFFAppClass.lpszClassName = JFFSystemUtility::_JFFAPP_CLASS_NAME;
		JFFAppClass.lpszMenuName  = NULL;
		JFFAppClass.style		  = CS_CLASSDC;
		RegisterClass(&JFFAppClass);

		mhWnd = CreateWindow(
			JFFSystemUtility::_JFFAPP_CLASS_NAME,
			JFFSystemUtility::_JFFAPP_DEFAULT_WIN_NAME,
			WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT,CW_USEDEFAULT,width,height,NULL,NULL,hInstance,
			NULL);
	
		ShowWindow(mhWnd,SW_SHOW);
		UpdateWindow(mhWnd);


	}

	void JFFSystem::MainLoop()
	{
		MSG msg;
		msg.message = WM_NULL;
		PeekMessage(&msg,NULL,0,0,PM_NOREMOVE);
		while(msg.message != WM_QUIT)
		{
			if(::PeekMessage(&msg,NULL,0,0,PM_REMOVE))
			{
				::TranslateMessage(&msg);
				::DispatchMessage(&msg);
			}
			else
			{
				//--do nothing;
			}
		}
		UnregisterClass(JFFSystemUtility::_JFFAPP_CLASS_NAME,::GetModuleHandle(0));
	}
}