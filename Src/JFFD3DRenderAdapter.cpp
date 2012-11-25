#include "JFFD3DRenderAdapter.h"
#include "JFFD3DRenderData.h"


#pragma comment(lib,"d3d9.lib")
namespace JFF{

	D3DRenderAdapter::D3DRenderAdapter(HWND hWnd):
		mDirect3D9(NULL),
		mDevice9(NULL),
		m_pRenderData(NULL),
		IRenderAdapter(hWnd)
	{

	}

	D3DRenderAdapter::~D3DRenderAdapter()
	{

	}

	VOID D3DRenderAdapter::Init3DEnvironment(/*int w,int h*/)
	{
		do 
		{
			mDirect3D9 = Direct3DCreate9(D3D_SDK_VERSION);
			if (NULL == mDirect3D9)
				break;

			D3DPRESENT_PARAMETERS d3dpp;
			ZeroMemory( &d3dpp, sizeof( d3dpp ) );
			d3dpp.Windowed = TRUE;
			d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
			d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
			mDirect3D9 ->CreateDevice(D3DADAPTER_DEFAULT,D3DDEVTYPE_HAL,m_hWnd,D3DCREATE_SOFTWARE_VERTEXPROCESSING,\
				&d3dpp,&mDevice9);
			if (NULL == mDevice9)
				break;			

		} while (0);
		



	}

	VOID D3DRenderAdapter::Relase3DEnviromment()
	{
		if (m_pRenderData)
		{
			m_pRenderData->Release();
			delete m_pRenderData;
			m_pRenderData = NULL;
		}

		if (mDevice9 != NULL)
		{
			mDevice9->Release();
		}
		
		if (mDirect3D9 != NULL)
		{
			mDirect3D9 ->Release();
		}

	}

	VOID D3DRenderAdapter::Render()
	{
		if (m_pRenderData)
		{
			m_pRenderData ->Render();
		}
	}

	VOID D3DRenderAdapter::Reset3DEnviroment()
	{
		if (m_pRenderData)
		{
			m_pRenderData ->Reset();
		}
	}
	VOID D3DRenderAdapter::setRenderData(IRenderData* pData)
	{
		if (pData)
		{
			m_pRenderData = static_cast<ID3DRenderData*> (pData);
			if (m_pRenderData != NULL)
			{
				m_pRenderData ->Initialize(mDevice9);
			}
		}


	}
};