// -*-C++-*-
/*!
 * @file  PowerPointObject.cpp
 * @brief PowerPoint�̑���
 *
 */

#include "PowerPointObject.h"


#include <locale.h>


/**
*@brief PowerPoint�𑀍삷��N���X�̃R���X�g���N�^
*/
PowerPointObject::PowerPointObject()
{
	ptApplication = nullptr;
	ptPresentations = nullptr;
	ptPresentation = nullptr;
	ptSlideShowWindow = nullptr;
	ptSlideShowView = nullptr;

	

	

	
}

/**
*@brief �y���ŕ`��
*/
void PowerPointObject::drawLine(int bx, int by, int ex, int ey)
{
	if(ptSlideShowView != nullptr)
	{
		HWND c_window = GetDesktopWindow();
		RECT rect;

		GetWindowRect(c_window, &rect);

		float tmp = ptPresentation->Slides[1]->CustomLayout->Height/rect.bottom;
		ptSlideShowView->DrawLine(bx*tmp, by*tmp, ex*tmp, ey*tmp);
		
		
	}
}

/**
*@brief �y��������
*/
void PowerPointObject::eraseDrawing()
{
	if(ptSlideShowView != nullptr)
	{
		ptSlideShowView->EraseDrawing();
	}
}

/**
*@brief �X���C�h�ԍ��̕ύX
*/
bool PowerPointObject::gotoSlide(int num)
{
	
	if(ptSlideShowView != nullptr)
	{
		if(0 < num && num <= ptPresentation->Slides->Count)
		{
			ptSlideShowView->GotoSlide(num, Microsoft::Office::Core::MsoTriState::msoCTrue);
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}


/**
*@brief �X���C�h�V���[�J�n
*/
void PowerPointObject::run()
{
	
	if(ptSlideShowView == nullptr)
	{
		ptSlideShowWindow = ptPresentation->SlideShowSettings->Run();
		ptSlideShowView = ptSlideShowWindow->View;
	}
}

/**
*@brief �X���C�h�V���[�J�n�̏I��
*/
void PowerPointObject::end()
{
	
	if(ptSlideShowView != nullptr)
	{
		try
		{
			ptSlideShowView->Exit();
		}
		catch(...)
		{

		}
	
		ptSlideShowWindow = nullptr;
		ptSlideShowView = nullptr;
	}
}

/**
*@brief ���̃X���C�h��\��
*/
void PowerPointObject::next()
{
	
	if(ptSlideShowView != nullptr)
	{
		ptSlideShowView->Next();
	}
}

/**
*@brief �O�̃X���C�h��\��
*/
void PowerPointObject::previous()
{
	
	if(ptSlideShowView != nullptr)
	{
		ptSlideShowView->Previous();
	}
}

/**
*@brief PowerPoint�t�@�C�����J���֐�
* @param fn �t�@�C���p�X
*/
void PowerPointObject::Open(System::String^ fn)
{
	if(filename == fn)
		return;
	filename = fn;

	PowerPoint::Application^ t_ptApplication;
	PowerPoint::Presentations^ t_ptPresentations;
	PowerPoint::Presentation^ t_ptPresentation;
	
	
	try {
		 try {
			System::Object^tObject = System::Runtime::InteropServices::Marshal::GetActiveObject("PowerPoint.Application");
			t_ptApplication = static_cast<PowerPoint::Application^>(tObject);
			}
		 catch(...){
				t_ptApplication = gcnew PowerPoint::Application();
			}
			t_ptApplication->Visible = Microsoft::Office::Core::MsoTriState::msoCTrue;
			
			try {
				t_ptPresentations = t_ptApplication->Presentations;
				if(filename == "")
				{
					t_ptPresentation = t_ptPresentations->Add(Microsoft::Office::Core::MsoTriState::msoCTrue);
					t_ptPresentation->Slides->Add(1, PowerPoint::PpSlideLayout::ppLayoutTitleOnly);

				}
				else
				{
					t_ptPresentation = t_ptPresentations->Open(filename, Microsoft::Office::Core::MsoTriState::msoCTrue, Microsoft::Office::Core::MsoTriState::msoCTrue, Microsoft::Office::Core::MsoTriState::msoCTrue);
				}
				
				Close();
				ptApplication = t_ptApplication;
				ptPresentations = t_ptPresentations;
				ptPresentation = t_ptPresentation;
			}
			catch(...){

			}
	}
	catch(...){

	}
}

/**
*@brief COM�I�u�W�F�N�g���������֐�
*/
void PowerPointObject::Close()
{
	if (ptPresentations != nullptr) {
		System::Runtime::InteropServices::Marshal::ReleaseComObject(ptPresentations);
	}
	ptPresentations = nullptr;

	if (ptPresentation != nullptr) {
		System::Runtime::InteropServices::Marshal::ReleaseComObject(ptPresentation);
	}
	ptPresentation = nullptr;
}
