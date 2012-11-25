#ifndef _JFFRENDER_H
#define _JFFRENDER_H

//  [11/22/2012 quentin]
//  渲染接口

//  [11/24/2012 quentin]
//  修改类名称 

//  [11/25/2012 quentin]
//  修改类名称完成
//	D3D 修改完成了
//  下次修改 OpenGL 的


#include "JFFPreHeader.h"

namespace JFF{

	class IRenderData;
	class IRenderAdapter
	{
	public:
		IRenderAdapter(HWND hWnd):m_hWnd(hWnd) {}
		virtual ~IRenderAdapter(){}
	public:
		virtual void Init3DEnvironment() =0;
		virtual void Render(void) =0;
		virtual void Relase3DEnviromment() =0;
		virtual void Reset3DEnviroment()=0;
		virtual void setRenderData(IRenderData* pData) =0;
	protected:
		HWND	m_hWnd;
	};

};
#endif