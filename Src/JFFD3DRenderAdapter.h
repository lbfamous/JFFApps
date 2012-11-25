#ifndef _JFFD3D_RENDER_H
#define _JFFD3D_RENDER_H

#include "JFFIRenderAdapter.h"
struct  IDirect3D9;
struct  IDirect3DDevice9;

namespace JFF
{
	class ID3DRenderData;
	class D3DRenderAdapter: public IRenderAdapter
	{
		typedef IRenderAdapter	Base;
	public:
		D3DRenderAdapter(HWND hWnd);
		~D3DRenderAdapter();
	public:
		virtual void Init3DEnvironment();
		virtual void Relase3DEnviromment();
		virtual void Render();
		virtual void Reset3DEnviroment();
		virtual void setRenderData(IRenderData* pData);

	private:
		IDirect3D9 *		mDirect3D9;
		IDirect3DDevice9*	mDevice9;
		ID3DRenderData*		m_pRenderData;
	};
}
#endif