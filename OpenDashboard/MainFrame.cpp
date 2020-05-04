#include "MainFrame.h"
#include "ODashboardApp.h"
#include "WidgetFrame.h"

BEGIN_EVENT_TABLE(MainFrame, wxFrame)
	EVT_SET_FOCUS(OnFocus)
END_EVENT_TABLE()

MainFrame::MainFrame() : wxFrame(nullptr, 10001, "OpenDashboard")
{
	initDashboard();
}
		
MainFrame::~MainFrame()	
{	
}

void MainFrame::OnFocus(wxFocusEvent& event)
{
	if(ODashboardApp::getApp()->widget != nullptr)
		ODashboardApp::getApp()->widget->Raise();
}

void MainFrame::initDashboard()
{
	ShowFullScreen(true, wxFULLSCREEN_ALL);
		
	long styleflag = GetWindowStyle();
	SetWindowStyle(styleflag | wxSTAY_ON_TOP | wxFRAME_TOOL_WINDOW);

	wxColour cl = wxTransparentColour;
	SetBackgroundColour(cl);
	SetTransparent(127.5);
}
