#ifndef _UTIL_UTIL_H
#define _UTIL_UTIL_H

namespace UTIL
{
	namespace UTIL
	{
		void ASSERT(bool condition,const char* szDesc)
		{
			//__asm{int 3;}
		}

		void ASSERT(const char* szDesc) 
		{
	
		}

		template<typename T>
		void SAFE_DELETE(T* p)
		{
			if (p)
			{
				delete p;
				p = NULL;
			}
		}

		template <typename T>
		void SAFE_RELEASE(T* p)
		{
			if (p)
			{
				p->Release();
				p = NULL;
			}
		}
	};
};
#endif