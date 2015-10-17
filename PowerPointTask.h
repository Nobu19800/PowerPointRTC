// -*- C++ -*-
/*!
 * @file  PowerPointTask.h
 * @brief PowerPointの起動、COMの参照をするスレッド
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
 * @brief PowerPointの起動、COMの参照をするスレッド
 *
 */
class PowerPointTask : public virtual coil::Task
{
public:
		/**
		*@brief コンストラクタ
		*/
		PowerPointTask(PowerPointControl *m_rtc);
		/**
		*@brief スレッドを実行
		* @return 
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