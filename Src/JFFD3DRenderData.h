#ifndef _JFF_D3D_RENDERIMP_H
#define _JFF_D3D_RENDERIMP_H

#include "JFFIRenderData.h"

struct IDirect3DVertexBuffer9;
namespace JFF
{
	class D3DRenderData:public ID3DRenderData
	{
	public:
		D3DRenderData():m_pVertexBuffer(NULL)
		{

		}
		~D3DRenderData() {}

	public:
		virtual void Initialize(IDirect3DDevice9* pDevice);		
		virtual void Render();
		virtual void Release();
		virtual void Reset();

	public:
		struct CUSTOMVERTEX
		{
			float	x,y,z,rhw;
			DWORD	color;
		};

		static const DWORD D3DFVF_CUSTOMVERTEX;

		IDirect3DVertexBuffer9* m_pVertexBuffer;		//-Êý¾ÝÁ÷
	};
}
#endif