#include "ODashboardApp.h"
#include <thread>
#include "windows_listener.h"
#include "TimeWidget.h"
#include <list>

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

ODashboardApp* ODashboardApp::getApp()
{
	if (instance == NULL) {
		instance = new ODashboardApp();
	}
	
	return instance;
}

bool ODashboardApp::OnInit()
{
	widgets = *new std::vector<WidgetFrame*>();
	addToVector(widgets, new TimeWidget());

	ODashboardApp::getApp()->mainframe = new MainFrame();
	//ODashboardApp::getApp()->widget = new TestWidget();
	ODashboardApp::getApp()->changeState();

	std::thread t1(listenForActivation);
	t1.detach();

	return true;
}

void ODashboardApp::changeState()
{
	if (ODashboardApp::getApp()->mainframe->IsShown()) {
		ODashboardApp::getApp()->mainframe->Hide();

		unsigned int vSize = widgets.size();
		for (unsigned int i = 0; i < vSize; i++) {
			widgets[i]->Hide();
		}
	}
	else {
		ODashboardApp::getApp()->mainframe->Show();
					
		unsigned int vSize = widgets.size();
		for (unsigned int i = 0; i < vSize; i++) {
			widgets[i]->Show();
		}
	}
}

void ODashboardApp::addToVector(std::vector<WidgetFrame*> &widgets, WidgetFrame* widget)
{
	//if (instanceof<WidgetFrame>(widget)) {
		//WidgetFrame* widget = new TimeWidget;
		widgets.push_back(widget);
	//}
}
	