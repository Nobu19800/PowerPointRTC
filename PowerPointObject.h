// -*-C++-*-
/*!
 * @file  PowerPointObject.h
 * @brief PowerPoint�̑���
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
*@brief PowerPoint�𑀍삷��N���X
*/
ref class PowerPointObject
{
public:
	/**
	*@brief �R���X�g���N�^
	*/
	PowerPointObject();

	static PowerPointObject ^Obj; /**<�@@brief  */

	
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
	void run();

	/**
	*@brief �X���C�h�V���[�J�n�̏I��
	*/
	void end();

	/**
	*@brief �X���C�h�ԍ��̕ύX
	*/
	bool gotoSlide(int num);

	

	/**
	*@brief ���̃X���C�h��\��
	*/
	void next();

	/**
	*@brief �O�̃X���C�h��\��
	*/
	void previous();

	/**
	*@brief �y���ŕ`��
	*/
	void drawLine(int bx, int by, int ex, int ey);

	/**
	*@brief �y��������
	*/
	void eraseDrawing();
	
	

	
	


	System::String^ filename; /**<�@@brief  */
	PowerPoint::Application^ ptApplication; /**<�@@brief  */
	PowerPoint::Presentations^ ptPresentations; /**<�@@brief  */
	PowerPoint::Presentation^ ptPresentation; /**<�@@brief  */
	PowerPoint::SlideShowWindow ^ptSlideShowWindow; /**<�@@brief  */
	PowerPoint::SlideShowView ^ptSlideShowView; /**<�@@brief  */

	
	
	

	
	
};



#endif