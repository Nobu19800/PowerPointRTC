// -*-C++-*-
/*!
 * @file  myPowerPoint.cpp
 * @brief PowerPointÇÃëÄçÏ
 *
 */

#include "myPowerPoint.h"


#include <locale.h>



myPowerPoint::myPowerPoint()
{
	ptApplication = nullptr;
	ptPresentations = nullptr;
	ptPresentation = nullptr;
	ptSlideShowWindow = nullptr;
	ptSlideShowView = nullptr;

	

	

	
}

void myPowerPoint::DrawLine(int bx, int by, int ex, int ey)
{
	if(ptSlideShowView != nullptr)
	{
		
		ptSlideShowView->DrawLine(bx, by, ex, ey);
		
		
	}
}

void myPowerPoint::EraseDrawing()
{
	if(ptSlideShowView != nullptr)
	{
		ptSlideShowView->EraseDrawing();
	}
}

bool myPowerPoint::GotoSlide(int num)
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



void myPowerPoint::Run()
{
	
	if(ptSlideShowView == nullptr)
	{
		ptSlideShowWindow = ptPresentation->SlideShowSettings->Run();
		ptSlideShowView = ptSlideShowWindow->View;
	}
}

void myPowerPoint::End()
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

void myPowerPoint::Next()
{
	
	if(ptSlideShowView != nullptr)
	{
		ptSlideShowView->Next();
	}
}

void myPowerPoint::Previous()
{
	
	if(ptSlideShowView != nullptr)
	{
		ptSlideShowView->Previous();
	}
}


void myPowerPoint::Open(System::String^ fn)
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

void myPowerPoint::Close()
{

}
