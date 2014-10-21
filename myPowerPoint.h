// -*-C++-*-
/*!
 * @file  myPowerPoint.h
 * @brief PowerPointの操作
 */
#ifndef MYPOWERPOINT_H
#define MYPOWERPOINT_H


#define PowerPoint   Microsoft::Office::Interop::PowerPoint

#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

#include "MyObject.h"


/**
 * @class myPowerPoint
*@brief PowerPointを操作するクラス
*/
ref class myPowerPoint
{
public:
	/**
	*@brief コンストラクタ
	*/
	myPowerPoint();

	static myPowerPoint ^Obj; /**<　@brief  */

	
	/**
	*@brief PowerPointファイルを開く関数
	* @param fn ファイルパス
	*/
	void Open(System::String^ fn);
	
	/**
	*@brief COMオブジェクトを解放する関数
	*/
	void Close();

	/**
	*@brief スライドショー開始
	*/
	void Run();

	/**
	*@brief スライドショー開始の終了
	*/
	void End();

	/**
	*@brief スライド番号の変更
	*/
	bool GotoSlide(int num);

	

	/**
	*@brief 次のスライドを表示
	*/
	void Next();

	/**
	*@brief 前のスライドを表示
	*/
	void Previous();

	/**
	*@brief ペンで描画
	*/
	void DrawLine(int bx, int by, int ex, int ey);

	/**
	*@brief ペンを消去
	*/
	void EraseDrawing();
	
	

	
	


	System::String^ filename; /**<　@brief  */
	PowerPoint::Application^ ptApplication; /**<　@brief  */
	PowerPoint::Presentations^ ptPresentations; /**<　@brief  */
	PowerPoint::Presentation^ ptPresentation; /**<　@brief  */
	PowerPoint::SlideShowWindow ^ptSlideShowWindow; /**<　@brief  */
	PowerPoint::SlideShowView ^ptSlideShowView; /**<　@brief  */

	
	
	

	
	
};



#endif