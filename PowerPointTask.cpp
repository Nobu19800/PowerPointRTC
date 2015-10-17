// -*-C++-*-
/*!
 * @file  PowerPointTask.cpp
 * @brief PowerPoint�̋N���ACOM�̎Q�Ƃ�����X���b�h
 *
 */



#include "PowerPointTask.h"
#include "PowerPointObject.h"


/**
*@brief PowerPoint�̋N���ACOM�̎Q�Ƃ�����X���b�h�̃R���X�g���N�^
*/
PowerPointTask::PowerPointTask(PowerPointControl *m_rtc)
{
	mrtc = m_rtc;
}




/**
*@brief �X���b�h�����s
* @return
*/
int PowerPointTask::svc()
{
	
	PowerPointObject::Obj = gcnew PowerPointObject();
	std::string filePath = mrtc->getFileName();
	if (filePath == "NewFile")
	{
		filePath = "";
	}
	//coil::Properties& prop(::RTC::Manager::instance().getConfig());
	//getProperty(prop, "powerpoint.filename", filePath);
	//filePath = Replace(filePath, "/", "\\");
	coil::replaceString(filePath, "/", "\\");

	PowerPointObject::Obj->Open(gcnew System::String(filePath.c_str()));
	
	return 0;
}


