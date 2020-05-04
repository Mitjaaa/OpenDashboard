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
	ODashboardApp::getApp()->widget = new WidgetFrame();
	ODashboardApp::getApp()->changeState();

	std::thread t1(listenForActivation);
	t1.detach();

	return true;
}

void ODashboardApp::changeState()
{
	if (ODashboardApp::getApp()->mainframe->IsShown()) {
		ODashboardApp::getApp()->mainframe->Hide();
		ODashboardApp::getApp()->widget->Hide();

		active = false;
	}
	else {
		ODashboardApp::getApp()->mainframe->Show();
		ODashboardApp::getApp()->widget->Show();

		ODashboardApp::getApp()->widget->Raise();
		ODashboardApp::getApp()->widget->Raise();
		ODashboardApp::getApp()->widget->Raise();
		ODashboardApp::getApp()->widget->Raise();

		active = true;
	}
}
