// -*- C++ -*-
/*!
 * @file  PowerPointControl.cpp
 * @brief PowerPoint Control Component
 * @date $Date$
 *
 * $Id$
 */

#include "PowerPointControl.h"

// Module specification
// <rtc-template block="module_spec">
static const char* powerpointcontrol_spec[] =
  {
    "implementation_id", "PowerPointControl",
    "type_name",         "PowerPointControl",
    "description",       "PowerPoint Control Component",
    "version",           "1.0.0",
    "vendor",            "Miyamoto Nobuhiko",
    "category",          "TES",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
	"conf.default.file_path", "NewFile",
	"conf.default.SlideFileInitialNumber", "1",
	"conf.default.SlideNumberInRelative", "1",
	"conf.__widget__.file_path", "text",
	"conf.__widget__.SlideFileInitialNumber", "spin",
	"conf.__widget__.SlideNumberInRelative", "radio",
	"conf.__constraints__.SlideFileInitialNumber", "1<=x<=100",
	"conf.__constraints__.SlideNumberInRelative", "(0,1)",
    ""
  };
// </rtc-template>



//コンフィギュレーションパラメータが更新されたときのコールバック
class MyConfigUpdateParam
    : public RTC::ConfigurationSetListener
{
public:
    MyConfigUpdateParam(PowerPointControl *e_rtc)
    {
		m_rtc = e_rtc;
    }
    void operator()(const coil::Properties& config_set)
	{
		
		m_rtc->ConfigUpdate();
		
    }
	PowerPointControl *m_rtc;

};

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
PowerPointControl::PowerPointControl(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_SlideNumberInIn("SlideNumberIn", m_SlideNumberIn),
    m_EffectNumberInIn("EffectNumberIn", m_EffectNumberIn),
	m_PenIn("Pen", m_Pen),
    m_SlideNumberOutOut("SlideNumberOut", m_SlideNumberOut)

    // </rtc-template>
{
	pt = new PowerPointTask();
	pt->activate();
}

/*!
 * @brief destructor
 */
PowerPointControl::~PowerPointControl()
{
}


void PowerPointControl::SetFilePath(std::string FP)
{

	coil::Properties file_confSet("default");
	file_confSet.setProperty("file_path", FP.c_str());
	this->m_configsets.setConfigurationSetValues(file_confSet);
	this->m_configsets.activateConfigurationSet("default");
	


	this->m_configsets.update("default", "file_path");
	
}


void PowerPointControl::ConfigUpdate()
{
	this->m_configsets.update("default","file_path");
	std::string sfn = Replace(file_path, "/", "\\");
	System::String ^tfn = gcnew System::String(sfn.c_str());
	//System::Console::WriteLine(tfn);
	
	if(sfn ==  "NewFile")
	{
		PowerPointObject::Obj->Open("");
	}
	else if(PowerPointObject::Obj->filename != tfn)
	{
		
		PowerPointObject::Obj->Open(tfn);
		 
		
	}
	
}


RTC::ReturnCode_t PowerPointControl::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("SlideNumberIn", m_SlideNumberInIn);
  addInPort("EffectNumberIn", m_EffectNumberInIn);
  addInPort("Pen", m_PenIn);
  
  // Set OutPort buffer
  addOutPort("SlideNumberOut", m_SlideNumberOutOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  bindParameter("file_path", file_path, "NewFile");
  bindParameter("SlideFileInitialNumber", SlideFileInitialNumber, "1");
  bindParameter("SlideNumberInRelative", SlideNumberInRelative, "1");

  std::string filePath = "";
  coil::Properties& prop(::RTC::Manager::instance().getConfig());
  getProperty(prop, "powerpoint.filename", filePath);
  SetFilePath(filePath);


  this->addConfigurationSetListener(ON_SET_CONFIG_SET, new MyConfigUpdateParam(this));

  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t PowerPointControl::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t PowerPointControl::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t PowerPointControl::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t PowerPointControl::onActivated(RTC::UniqueId ec_id)
{
	PowerPointObject::Obj->run();
	PowerPointObject::Obj->gotoSlide(SlideFileInitialNumber);
	slidenum = SlideFileInitialNumber;
  return RTC::RTC_OK;
}


RTC::ReturnCode_t PowerPointControl::onDeactivated(RTC::UniqueId ec_id)
{
	PowerPointObject::Obj->end();
  return RTC::RTC_OK;
}


RTC::ReturnCode_t PowerPointControl::onExecute(RTC::UniqueId ec_id)
{
  if(m_SlideNumberInIn.isNew())
  {
	m_SlideNumberInIn.read();

	if(SlideNumberInRelative == 0)
	{
		if(PowerPointObject::Obj->gotoSlide(m_SlideNumberIn.data))
			slidenum = m_SlideNumberIn.data;
	}
	else
	{
		if(PowerPointObject::Obj->gotoSlide(slidenum+m_SlideNumberIn.data))
			slidenum += m_SlideNumberIn.data;
	}
	m_SlideNumberOut.data = slidenum;
	m_SlideNumberOutOut.write();
  }

  if(m_EffectNumberInIn.isNew())
  {
	m_EffectNumberInIn.read();
	
	if(m_SlideNumberIn.data > 0)
	{
		for(int i=0;i < m_EffectNumberIn.data;i++)
		{
			PowerPointObject::Obj->next();
		}
	}
	else
	{
		for(int i=0;i < -m_EffectNumberIn.data;i++)
		{
			PowerPointObject::Obj->previous();
		}
	}
	
  }

  if(m_PenIn.isNew())
  {
	  m_PenIn.read();
	  int len = m_Pen.data.length();
	  for(int i=0;i < len/2;i++)
	  {
		  if(i == 0)
			 PowerPointObject::Obj->drawLine(m_Pen.data[i*2],m_Pen.data[i*2+1],m_Pen.data[i*2],m_Pen.data[i*2+1]);
		  else
			 PowerPointObject::Obj->drawLine(m_Pen.data[i*2-2],m_Pen.data[i*2-1],m_Pen.data[i*2],m_Pen.data[i*2+1]);
			 
	  }
  }
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t PowerPointControl::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t PowerPointControl::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t PowerPointControl::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t PowerPointControl::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t PowerPointControl::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void PowerPointControlInit(RTC::Manager* manager)
  {
    coil::Properties profile(powerpointcontrol_spec);
    manager->registerFactory(profile,
                             RTC::Create<PowerPointControl>,
                             RTC::Delete<PowerPointControl>);
  }
  
};


