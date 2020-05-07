#include "MainFrame.h"
#include "ODashboardApp.h"
#include "WidgetFrame.h"

BEGIN_EVENT_TABLE(MainFrame, wxFrame)
	EVT_SET_FOCUS(OnFocus)
END_EVENT_TABLE()

MainFrame::MainFrame() : wxFrame(nullptr, 10001, "OpenDashboard")
{
	wxStaticText* placeholder = new wxStaticText(this, wxID_ANY, "");
	initDashboard();
}
		
MainFrame::~MainFrame()	
{	
}

void MainFrame::OnFocus(wxFocusEvent& event)
{
	unsigned int vSize = ODashboardApp::getApp()->widgets.size();
	for (unsigned int i = 0; i < vSize; i++) {
		if (ODashboardApp::getApp()->widgets[i] != nullptr)
			ODashboardApp::getApp()->widgets[i]->Raise();
	}
	
	ODashboardApp::getApp()->menu->Raise();
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
