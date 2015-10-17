// -*-C++-*-
/*!
 * @file  SubFunction.cpp
 * @brief 文字列の操作等
 *
 */

#include "SubFunction.h"

using namespace std;



/**
*@brief セルの番号を数値に変換する関数
* @param m_str セルの番号(アルファベット)
* @return 対応する数値
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
*@brief System::Stringをstd::stringに変換する関数
* @param s 変換前の文字列
* @return 変換後の文字列
*/
std::string MarshalString ( System::String ^ s) {
   using namespace System::Runtime::InteropServices;
   const char* chars = 
      (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
   std::string os = chars;
   Marshal::FreeHGlobal(System::IntPtr((void*)chars));

   return os;
}

