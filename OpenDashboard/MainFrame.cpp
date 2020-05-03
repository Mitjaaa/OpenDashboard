#include "MainFrame.h"
#include "ODashboardApp.h"

MainFrame::MainFrame() : wxFrame(nullptr, 11001, "OpenDashboard")
{
	ShowFullScreen(true, wxFULLSCREEN_ALL);
	
	long styleflag = GetWindowStyle();
	SetWindowStyle(styleflag | wxSTAY_ON_TOP | wxFRAME_TOOL_WINDOW);

	wxColour cl = wxTransparentColour;
	SetBackgroundColour(cl);
	SetTransparent(127.5);
}
		
MainFrame::~MainFrame()
{
}
