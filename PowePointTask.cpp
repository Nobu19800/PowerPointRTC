// -*-C++-*-
/*!
 * @file  PowerPointTask.cpp
 * @brief PowerPointの起動、COMの参照をするスレッド
 *
 */



#include "PowerPointTask.h"
#include "myPowerPoint.h"


PowerPointTask::PowerPointTask()
{
	
}





int PowerPointTask::svc()
{
	
	myPowerPoint::Obj = gcnew myPowerPoint();
	std::string filePath = "";
	coil::Properties& prop(::RTC::Manager::instance().getConfig());
	getProperty(prop, "powerpoint.filename", filePath);
	//filePath = Replace(filePath, "/", "\\");

	myPowerPoint::Obj->Open(gcnew System::String(filePath.c_str()));
	
	return 0;
}


