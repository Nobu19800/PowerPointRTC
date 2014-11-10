// -*-C++-*-
/*!
 * @file  PowerPointObject.h
 * @brief PowerPointの操作
 */
#ifndef PowerPointObject_H
#define PowerPointObject_H


#define PowerPoint   Microsoft::Office::Interop::PowerPoint

#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

#include "SubFunction.h"


/**
 * @class PowerPointObject
*@brief PowerPointを操作するクラス
*/
ref class PowerPointObject
{
public:
	/**
	*@brief コンストラクタ
	*/
	PowerPointObject();

	static PowerPointObject ^Obj; /**<　@brief  */

	
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
	void run();

	/**
	*@brief スライドショー開始の終了
	*/
	void end();

	/**
	*@brief スライド番号の変更
	*/
	bool gotoSlide(int num);

	

	/**
	*@brief 次のスライドを表示
	*/
	void next();

	/**
	*@brief 前のスライドを表示
	*/
	void previous();

	/**
	*@brief ペンで描画
	*/
	void drawLine(int bx, int by, int ex, int ey);

	/**
	*@brief ペンを消去
	*/
	void eraseDrawing();
	
	

	
	


	System::String^ filename; /**<　@brief  */
	PowerPoint::Application^ ptApplication; /**<　@brief  */
	PowerPoint::Presentations^ ptPresentations; /**<　@brief  */
	PowerPoint::Presentation^ ptPresentation; /**<　@brief  */
	PowerPoint::SlideShowWindow ^ptSlideShowWindow; /**<　@brief  */
	PowerPoint::SlideShowView ^ptSlideShowView; /**<　@brief  */

	
	
	

	
	
};



#endif