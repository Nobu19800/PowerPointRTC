// -*-C++-*-
/*!
 * @file  PowerPointObject.cpp
 * @brief PowerPoint�̑���
 *
 */

#include "PowerPointObject.h"


#include <locale.h>



PowerPointObject::PowerPointObject()
{
	ptApplication = nullptr;
	ptPresentations = nullptr;
	ptPresentation = nullptr;
	ptSlideShowWindow = nullptr;
	ptSlideShowView = nullptr;

	

	

	
}

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

void PowerPointObject::eraseDrawing()
{
	if(ptSlideShowView != nullptr)
	{
		ptSlideShowView->EraseDrawing();
	}
}

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



void PowerPointObject::run()
{
	
	if(ptSlideShowView == nullptr)
	{
		ptSlideShowWindow = ptPresentation->SlideShowSettings->Run();
		ptSlideShowView = ptSlideShowWindow->View;
	}
}

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

void PowerPointObject::next()
{
	
	if(ptSlideShowView != nullptr)
	{
		ptSlideShowView->Next();
	}
}

void PowerPointObject::previous()
{
	
	if(ptSlideShowView != nullptr)
	{
		ptSlideShowView->Previous();
	}
}


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

void PowerPointObject::Close()
{

}
