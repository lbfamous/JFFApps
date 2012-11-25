#include "JFFD3DRenderData.h"
#include <d3d9.h>

namespace JFF
{
	const DWORD D3DRenderData::D3DFVF_CUSTOMVERTEX = D3DFVF_XYZRHW|D3DFVF_DIFFUSE;

	void D3DRenderData::Initialize(IDirect3DDevice9* pDevice)
	{
		ID3DRenderData::Initialize(pDevice);

		CUSTOMVERTEX Vertices[] =
		{
			{ 150.0f,  50.0f, 0.5f, 1.0f, 0xffff0000, }, // x, y, z, rhw, color
			{ 250.0f, 250.0f, 0.5f, 1.0f, 0xff00ff00, },
			{  50.0f, 250.0f, 0.5f, 1.0f, 0xff00ffff, }, 
		};

		do 
		{
			if (pDevice == NULL) break;

			//-需要保证 m_pVertexBuffer == NULL
			HRESULT hr = pDevice ->CreateVertexBuffer(3 * sizeof( CUSTOMVERTEX ),
				0, D3DFVF_CUSTOMVERTEX,
				D3DPOOL_DEFAULT, &m_pVertexBuffer, NULL ) ;

			if (FAILED(hr)) break; //-创建VertexBuffer 失败了

			VOID* pVertices = NULL;
			if( FAILED( m_pVertexBuffer->Lock( 0, sizeof( Vertices ), ( void** )&pVertices, 0 ) ) )
				break;
			memcpy( pVertices, Vertices, sizeof( Vertices ) );
			m_pVertexBuffer->Unlock(); //-lock 数据 进入m_pVertexBuffer 





		} while (0);

	}
	void D3DRenderData::Release()
	{
		if (m_pVertexBuffer)
		{
			m_pVertexBuffer->Release();
		}
	}
	void D3DRenderData::Render()
	{
		if (m_pDevice)
		{
			m_pDevice->Clear( 0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB( 0, 0, 255 ), 1.0f, 0 );
			HRESULT hr =m_pDevice->BeginScene();
			if (FAILED(hr)) return;

			m_pDevice->SetStreamSource(0,m_pVertexBuffer,0,sizeof(CUSTOMVERTEX));
			m_pDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
			m_pDevice->DrawPrimitive(D3DPT_TRIANGLELIST,0,1);
			m_pDevice->EndScene();

			m_pDevice->Present(NULL,NULL,NULL,NULL);
		}
	}
	void D3DRenderData::Reset()
	{

	}
};