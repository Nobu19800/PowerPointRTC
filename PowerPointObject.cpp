// -*-C++-*-
/*!
 * @file  PowerPointObject.cpp
 * @brief PowerPointの操作
 *
 */

#include "PowerPointObject.h"


#include <locale.h>


/**
*@brief PowerPointを操作するクラスのコンストラクタ
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
*@brief ペンで描画
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
*@brief ペンを消去
*/
void PowerPointObject::eraseDrawing()
{
	if(ptSlideShowView != nullptr)
	{
		ptSlideShowView->EraseDrawing();
	}
}

/**
*@brief スライド番号の変更
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
*@brief スライドショー開始
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
*@brief スライドショー開始の終了
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
*@brief 次のスライドを表示
*/
void PowerPointObject::next()
{
	
	if(ptSlideShowView != nullptr)
	{
		ptSlideShowView->Next();
	}
}

/**
*@brief 前のスライドを表示
*/
void PowerPointObject::previous()
{
	
	if(ptSlideShowView != nullptr)
	{
		ptSlideShowView->Previous();
	}
}

/**
*@brief PowerPointファイルを開く関数
* @param fn ファイルパス
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
*@brief COMオブジェクトを解放する関数
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
