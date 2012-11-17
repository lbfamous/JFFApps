#ifndef _JFFAPPENGINE_H_
#define _JFFAPPENGINE_H_


//namespace JFF
//{
//	class RenderSystem
//	{
//
//	};
//
//};
//class JFF_RenderSystem
//{
//public:
//
//};
//
//class ResourceManager
//{
//public:
//
//};
//template <class T>
//class JFF_Application
//{
//	typedef T	RenderSystem;
//public:
//	JFF_Apllication();
//
//
//private:
//	
//	RenderSystem		mRender;		//-渲染器
//	ResourceManager		mResManager;	//-资源管理这
//	TimeManager			mTimerManager;	//-
//};
//
//class application;
//class renderSystem;
//class renderManager;
//
//
//template <class AppType>
//AppType& refApplication()
//{
//	static AppType	app_system;
//	return app_system;
//}


#include <windows.h>
#include <tchar.h>		//For JFFCLASS NAME

namespace JFF
{
	class JFFSystemUtility
	{
	public:
		static const TCHAR* _JFFAPP_CLASS_NAME;
		static const TCHAR* _JFFAPP_DEFAULT_WIN_NAME;
		static LRESULT WINAPI WindowProc(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam);
	};

	class JFFSystem
	{
	public:
		static JFFSystem& getSystem()
		{
			static JFFSystem	system;
			return system;
		}

	public:
		void	Initinalize(int width,int height);	//-初始化大小
		void	Run		   ();
		void	MainLoop   ();

	public:
		void	setPosition(int x,int y);

		HWND	getHwnd	   () const {return mhWnd;}
	private:
		HWND	mhWnd;			//-
	private:
		JFFSystem(){}
	};
}
#endif