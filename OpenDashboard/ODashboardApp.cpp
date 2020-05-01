#include "ODashboardApp.h"

wxIMPLEMENT_APP(ODashboardApp);


ODashboardApp::ODashboardApp()
{
}


ODashboardApp::~ODashboardApp()
{
}

bool ODashboardApp::OnInit()
{
	mainframe = new MainFrame();
	mainframe->Show();

	return true;
}
