// -*-C++-*-
/*!
 * @file  myPowerPoint.h
 * @brief PowerPoint�̑���
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
*@brief PowerPoint�𑀍삷��N���X
*/
ref class myPowerPoint
{
public:
	/**
	*@brief �R���X�g���N�^
	*/
	myPowerPoint();

	static myPowerPoint ^Obj; /**<�@@brief  */

	
	/**
	*@brief PowerPoint�t�@�C�����J���֐�
	* @param fn �t�@�C���p�X
	*/
	void Open(System::String^ fn);
	
	/**
	*@brief COM�I�u�W�F�N�g���������֐�
	*/
	void Close();

	/**
	*@brief �X���C�h�V���[�J�n
	*/
	void Run();

	/**
	*@brief �X���C�h�V���[�J�n�̏I��
	*/
	void End();

	/**
	*@brief �X���C�h�ԍ��̕ύX
	*/
	bool GotoSlide(int num);

	

	/**
	*@brief ���̃X���C�h��\��
	*/
	void Next();

	/**
	*@brief �O�̃X���C�h��\��
	*/
	void Previous();

	/**
	*@brief �y���ŕ`��
	*/
	void DrawLine(int bx, int by, int ex, int ey);

	/**
	*@brief �y��������
	*/
	void EraseDrawing();
	
	

	
	


	System::String^ filename; /**<�@@brief  */
	PowerPoint::Application^ ptApplication; /**<�@@brief  */
	PowerPoint::Presentations^ ptPresentations; /**<�@@brief  */
	PowerPoint::Presentation^ ptPresentation; /**<�@@brief  */
	PowerPoint::SlideShowWindow ^ptSlideShowWindow; /**<�@@brief  */
	PowerPoint::SlideShowView ^ptSlideShowView; /**<�@@brief  */

	
	
	

	
	
};



#endif