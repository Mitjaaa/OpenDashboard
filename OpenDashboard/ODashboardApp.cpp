#include "ODashboardApp.h"
#include <thread>
#include "windows_listener.h"
#include "TestWidget.h"
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
	addToVector(widgets, 0);
	addToVector(widgets, 0);
	addToVector(widgets, 0);								

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
		//ODashboardApp::getApp()->widget->Hide();

		unsigned int vSize = widgets.size();
		for (unsigned int i = 0; i < vSize; i++) {
			widgets[i]->Hide();
		}
	}
	else {
		ODashboardApp::getApp()->mainframe->Show();
		//ODashboardApp::getApp()->widget->Show();
					
		unsigned int vSize = widgets.size();
		for (unsigned int i = 0; i < vSize; i++) {
			if (widgets[i] == NULL) {
				widgets[i] = new TestWidget();
			}
			widgets[i]->Show();
		}
	}
}

void ODashboardApp::addToVector(std::vector<WidgetFrame*> &widgets, int index)
{
	if (index == 0) {
		WidgetFrame* widget = new TestWidget;
		widgets.push_back(widget);
	}
	else if (index == 1) {

	}
}
	