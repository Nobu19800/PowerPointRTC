// -*-C++-*-
/*!
 * @file  MyObject.cpp
 * @brief ï∂éöóÒÇÃëÄçÏìô
 *
 */

#include "MyObject.h"

using namespace std;

std::string Replace( std::string String1, std::string String2, std::string String3 )
{
    std::string::size_type  Pos( String1.find( String2 ) );

    while( Pos != std::string::npos )
    {
        String1.replace( Pos, String2.length(), String3 );
        Pos = String1.find( String2, Pos + String3.length() );
    }

    return String1;
}


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

std::string MarshalString ( System::String ^ s) {
   using namespace System::Runtime::InteropServices;
   const char* chars = 
      (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
   std::string os = chars;
   Marshal::FreeHGlobal(System::IntPtr((void*)chars));

   return os;
}

vector<string> split(const string &str, const string &delim){
  vector<string> res;
  size_t current = 0, found, delimlen = delim.size();
  while((found = str.find(delim, current)) != string::npos){
    res.push_back(string(str, current, found - current));
    current = found + delimlen;
  }
  res.push_back(string(str, current, str.size() - current));
  return res;
}