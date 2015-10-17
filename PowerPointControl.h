// -*- C++ -*-
/*!
 * @file  PowerPointControl.h
 * @brief PowerPoint Control Component
 * @date  $Date$
 *
 * $Id$
 */

#ifndef POWERPOINTCONTROL_H
#define POWERPOINTCONTROL_H

#include <rtm/Manager.h>
#include <rtm/DataFlowComponentBase.h>
#include <rtm/CorbaPort.h>
#include <rtm/DataInPort.h>
#include <rtm/DataOutPort.h>
#include <rtm/idl/BasicDataTypeSkel.h>
#include <rtm/idl/ExtendedDataTypesSkel.h>
#include <rtm/idl/InterfaceDataTypesSkel.h>

// Service implementation headers
// <rtc-template block="service_impl_h">

// </rtc-template>

// Service Consumer stub headers
// <rtc-template block="consumer_stub_h">
#include "BasicDataTypeStub.h"

#include "PowerPointObject.h"
#include "PowerPointTask.h"


class PowerPointTask;
class PowerPointControl;

// </rtc-template>

using namespace RTC;

/*!
 * @class PowerPointControl
 * @brief PowerPoint Control Component
 *
 */
class PowerPointControl
  : public RTC::DataFlowComponentBase
{
 public:
  /*!
   * @brief constructor
   * @param manager Maneger Object
   */
  PowerPointControl(RTC::Manager* manager);

  /*!
   * @brief destructor
   */
  ~PowerPointControl();

  /**
   * @brief コンフィギュレーションパラメータが更新されたときにファイルを再読み込みする関数
   */
  void PowerPointControl::ConfigUpdate();

  /**
  *@brief ファイル名の取得の関数
  * @return ファイル名
  */
   std::string getFileName();

   /**
   *@brief ファイル名のコンフィギュレーションパラメータ変更の関数
   * @param FP ファイル名
   */
   void SetFilePath(std::string FP);

  // <rtc-template block="public_attribute">
  
  // </rtc-template>

  // <rtc-template block="public_operation">
  
  // </rtc-template>

   /**
   *@brief 初期化処理用コールバック関数
   * @return RTC::ReturnCode_t
   */
   virtual RTC::ReturnCode_t onInitialize();

  /***
   *
   * The finalize action (on ALIVE->END transition)
   * formaer rtc_exiting_entry()
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onFinalize();

  /***
   *
   * The startup action when ExecutionContext startup
   * former rtc_starting_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onStartup(RTC::UniqueId ec_id);

  /***
   *
   * The shutdown action when ExecutionContext stop
   * former rtc_stopping_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onShutdown(RTC::UniqueId ec_id);

   /**
   *@brief 活性化時のコールバック関数
   * @param ec_id
   * @return
   */
   virtual RTC::ReturnCode_t onActivated(RTC::UniqueId ec_id);

   /**
   *@brief 不活性化時のコールバック関数
   * @param ec_id target ExecutionContext Id
   * @return RTC::ReturnCode_t
   */
   virtual RTC::ReturnCode_t onDeactivated(RTC::UniqueId ec_id);

   /**
   *@brief 周期処理用コールバック関数
   * @param ec_id target ExecutionContext Id
   * @return RTC::ReturnCode_t
   */
   virtual RTC::ReturnCode_t onExecute(RTC::UniqueId ec_id);

  /***
   *
   * The aborting action when main logic error occurred.
   * former rtc_aborting_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onAborting(RTC::UniqueId ec_id);

  /***
   *
   * The error action in ERROR state
   * former rtc_error_do()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onError(RTC::UniqueId ec_id);

  /***
   *
   * The reset action that is invoked resetting
   * This is same but different the former rtc_init_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onReset(RTC::UniqueId ec_id);
  
  /***
   *
   * The state update action that is invoked after onExecute() action
   * no corresponding operation exists in OpenRTm-aist-0.2.0
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onStateUpdate(RTC::UniqueId ec_id);

  /***
   *
   * The action that is invoked when execution context's rate is changed
   * no corresponding operation exists in OpenRTm-aist-0.2.0
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onRateChanged(RTC::UniqueId ec_id);


 protected:
  // <rtc-template block="protected_attribute">
  
  // </rtc-template>

  // <rtc-template block="protected_operation">
  
  // </rtc-template>

  // DataInPort declaration
  // <rtc-template block="inport_declare">
  TimedShort m_SlideNumberIn;
  /*!
   */
  InPort<TimedShort> m_SlideNumberInIn;
  TimedShort m_EffectNumberIn;
  /*!
   */
  InPort<TimedShort> m_EffectNumberInIn;
  TimedShortSeq m_Pen;
  /*!
   */
  InPort<TimedShortSeq> m_PenIn;
  
  // </rtc-template>


  // DataOutPort declaration
  // <rtc-template block="outport_declare">
  TimedShort m_SlideNumberOut;
  /*!
   */
  OutPort<TimedShort> m_SlideNumberOutOut;
  
  // </rtc-template>

  // CORBA Port declaration
  // <rtc-template block="corbaport_declare">
  
  // </rtc-template>

  // Service declaration
  // <rtc-template block="service_declare">
  
  // </rtc-template>

  // Consumer declaration
  // <rtc-template block="consumer_declare">
  
  // </rtc-template>

 private:
	 std::string file_path;	/**<　@brief  */
	int SlideFileInitialNumber;
	int SlideNumberInRelative;
	PowerPointTask *pt;
	int slidenum;
	
	
  // <rtc-template block="private_attribute">
  
  // </rtc-template>

  // <rtc-template block="private_operation">
  
  // </rtc-template>

};


//コンフィギュレーションパラメータが更新されたときのコールバック
class PowerPointConfigUpdateParam
    : public RTC::ConfigurationSetListener
{
public:
    PowerPointConfigUpdateParam(PowerPointControl *e_rtc)
    {
		m_rtc = e_rtc;
    }
    void operator()(const coil::Properties& config_set)
	{
		
		m_rtc->ConfigUpdate();
		
    }
	PowerPointControl *m_rtc;

};

extern "C"
{
  DLL_EXPORT void PowerPointControlInit(RTC::Manager* manager);
};

#endif // POWERPOINTCONTROL_H
