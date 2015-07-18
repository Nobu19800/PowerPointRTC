// -*- C++ -*-
/*!
 * @file  PowerPointTask.h
 * @brief PowerPoint�̋N���ACOM�̎Q�Ƃ�����X���b�h
 * $Id$
 */


#ifndef PowerPointTASK_H
#define PowerPointTASK_H

#include <rtm/RTC.h>



#include <rtm/Manager.h>
#include <rtm/PeriodicExecutionContext.h>

#include "PowerPointControl.h"


class PowerPointControl;

/*!
 * @class PowerPointTask
 * @brief PowerPoint�̋N���ACOM�̎Q�Ƃ�����X���b�h
 *
 */
class PowerPointTask : public virtual coil::Task
{
public:
		/**
		*@brief �R���X�g���N�^
		*/
		PowerPointTask(PowerPointControl *m_rtc);
		/**
		*@brief �X���b�h�����s
		*/
		virtual int svc();
		PowerPointControl *mrtc;
		


};

template <class T>
void getProperty(coil::Properties& prop, const char* key, T& value)
{
if (prop.findNode(key) != 0)
  {
    T tmp;
    if (coil::stringTo(tmp, prop[key].c_str()))
      {
        value = tmp;
      }
  }
}


#endif