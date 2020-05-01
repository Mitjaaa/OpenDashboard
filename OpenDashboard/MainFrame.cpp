#include "MainFrame.h"


MainFrame::MainFrame() : wxFrame(nullptr, wxID_ANY, "OpenDashboard")
{
	ShowFullScreen(true, wxFULLSCREEN_ALL);
	
	long styleflag = GetWindowStyle();
	SetWindowStyle(styleflag | wxSTAY_ON_TOP);

	SetBackgroundColour(*new wxColour(0, 0, 0));
	SetTransparent(127.5);
}

MainFrame::~MainFrame()
{
}
