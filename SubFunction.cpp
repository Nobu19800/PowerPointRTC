// -*-C++-*-
/*!
 * @file  SubFunction.cpp
 * @brief ������̑��쓙
 *
 */

#include "SubFunction.h"

using namespace std;



/**
*@brief �Z���̔ԍ��𐔒l�ɕϊ�����֐�
* @param m_str �Z���̔ԍ�(�A���t�@�x�b�g)
* @return �Ή����鐔�l
*/
int convertStrToVal(std::string m_str)
{
	char m_c = m_str.c_str()[0] - 64;
	
	if(m_str.length() == 1)
	{
		return int(m_c);
	}
	else
	{
		
		if(m_str.c_str()[1] < 91 && m_str.c_str()[1] > 64)
		{
			char m_c2 = m_str.c_str()[1] - 64;
			return int(m_c2) + int(m_c)*26;
		}
		else
			return int(m_c);
		
	}
	 
}

/**
*@brief System::String��std::string�ɕϊ�����֐�
* @param s �ϊ��O�̕�����
* @return �ϊ���̕�����
*/
std::string MarshalString ( System::String ^ s) {
   using namespace System::Runtime::InteropServices;
   const char* chars = 
      (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
   std::string os = chars;
   Marshal::FreeHGlobal(System::IntPtr((void*)chars));

   return os;
}

