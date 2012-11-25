#ifndef  _JFF_RENDERIMP_H
#define  _JFF_RENDERIMP_H

#include "JFFPreHeader.h"

struct IDirect3DDevice9;

namespace JFF
{
	class IRenderData
	{
	public:
		IRenderData() {}
		virtual ~IRenderData(){}
	public:
		virtual void	Render() =0;			//-‰÷»æ ˝æ›
		virtual void	Release()=0;			//- Õ∑≈
		virtual void	Reset() = 0;
	};

	class ID3DRenderData :public IRenderData
	{
	public:
		ID3DRenderData():m_pDevice(0)	{}
		virtual void Initialize(IDirect3DDevice9* pDevice)
		{m_pDevice = pDevice;}

	protected:
		IDirect3DDevice9*	m_pDevice;		//-
		
	};

	class IOGLRenderData:public IRenderData
	{
	public:

	};

};
#endif