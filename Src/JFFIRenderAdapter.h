#ifndef _JFFRENDER_H
#define _JFFRENDER_H

//  [11/22/2012 quentin]
//  ��Ⱦ�ӿ�

//  [11/24/2012 quentin]
//  �޸������� 

//  [11/25/2012 quentin]
//  �޸����������
//	D3D �޸������
//  �´��޸� OpenGL ��


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