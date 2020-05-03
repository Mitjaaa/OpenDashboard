#include "ODashboardApp.h"
#include <thread>
#include "windows_listener.h"

wxIMPLEMENT_APP(ODashboardApp);	

ODashboardApp* ODashboardApp::instance = new ODashboardApp();

ODashboardApp::ODashboardApp()
{
}

ODashboardApp::~ODashboardApp()
{
}

void listenForActivation()
{
	windows_listener listen = *new windows_listener();
}

bool active = false;

ODashboardApp* ODashboardApp::getApp()
{
	if (instance == NULL)
		instance = new ODashboardApp();

	return instance;
}

bool ODashboardApp::OnInit()
{
	ODashboardApp::getApp()->mainframe = new MainFrame();
	ODashboardApp::getApp()->mainframe->Hide();

	std::thread t1(listenForActivation);
	t1.detach();	

	return true;
}
