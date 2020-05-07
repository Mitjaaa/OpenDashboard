#include "ODashboardApp.h"

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
	menu = new WidgetMenu();
	widgets = *new std::vector<WidgetFrame*>();

	mainframe = new MainFrame();
	changeState();
	addWidgetsToMenu();

	std::thread t1(listenForActivation);
	t1.detach();

	return true;
}

void ODashboardApp::changeState()
{
	if (mainframe->IsShown()) {
		mainframe->Hide();
		menu->Hide();

		unsigned int vSize = widgets.size();
		for (unsigned int i = 0; i < vSize; i++) {
			widgets[i]->Hide();
		}
	}
	else {
		mainframe->Show();
		menu->Show();

		UpdateWidgets();
	}
}

void ODashboardApp::UpdateWidgets() {
	unsigned int vSize = widgets.size();
	for (unsigned int i = 0; i < vSize; i++) {
		if(!widgets[i]->IsShown())
			widgets[i]->Show();
	}
}
	
void ODashboardApp::addWidgetsToMenu()
{
	menu->scroller->addToSizer(new TimeWidget(true));
	//Add more Widgets

	menu->scroller->configureSizer();
}

void ODashboardApp::createSelectedWidget(wxCommandEvent& event)
{
	if (event.GetId() == 24000) addToVector(widgets, new TimeWidget(true));
	//Add more WidgetIDs				

	UpdateWidgets();
}

void ODashboardApp::addToVector(std::vector<WidgetFrame*> &widgets, WidgetFrame* widget)
{
	//if (instanceof<WidgetFrame>(widget)) {
		//WidgetFrame* widget = new TimeWidget;
		widgets.push_back(widget);
	//}
}
	