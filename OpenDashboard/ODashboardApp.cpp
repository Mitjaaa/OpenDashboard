#include "ODashboardApp.h"
#include "Colors.h"

wxIMPLEMENT_APP(ODashboardApp);

template<typename Base, typename T>
inline bool instanceof(const T*) {
	return std::is_base_of<Base, T>::value;
}

ODashboardApp* ODashboardApp::instance = new ODashboardApp();

ODashboardApp::ODashboardApp() {}
ODashboardApp::~ODashboardApp() {}

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

void ODashboardApp::initWidgetclasses()	
{
	addToWidgetclasses(new TimeWidget(true));
	addToWidgetclasses(new ImageWidget());

	implementWidgets();
	menu->scroller->configureSizer();
}

bool ODashboardApp::OnInit()
{
	initColours();

	menu = new WidgetMenu();
	widgets = *new std::vector<WidgetFrame*>();

	mainframe = new MainFrame();
	changeState();
	initWidgetclasses();

	settings = new SettingsWidget();

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


void ODashboardApp::RefreshWidgetsWithColours(wxColour newColour, bool setts) {
	unsigned int vSize = widgets.size();
	for (unsigned int i = 0; i < vSize; i++) {

		unsigned int cSize = widgets[i]->GetChildren().size();
		for (unsigned int j = 0; j < cSize; j++) {
			((WidgetFrame*)widgets[i]->GetChildren()[j])->RefreshForeBackground(newColour);
		}

		widgets[i]->wname->SetForegroundColour(textcolours[1].clr);
		widgets[i]->Refresh();
		widgets[i]->Update();
	}
		
	unsigned int cSize = menu->GetChildren().size();	
	for (unsigned int j = 0; j < cSize; j++) {
		((WidgetFrame*)menu->GetChildren()[j])->RefreshForeBackground(newColour);
	}

	menu->RefreshForeBackground(newColour);
	menu->Refresh();
	menu->Update();

	if (setts) {
		settings->RefreshPanels(newColour);
		settings->RefreshForeBackground(newColour);
	}
}

void ODashboardApp::UpdateWidgets() {
	unsigned int vSize = widgets.size();
	for (unsigned int i = 0; i < vSize; i++) {
		if (!widgets[i]->IsShown())
			widgets[i]->Show();
	}
}

void ODashboardApp::implementWidgets() {
	unsigned int vSize = widgetClasses.size();
	for (unsigned int i = 0; i < vSize; i++) {
		menu->scroller->addToSizer(widgetClasses[i]);
	}
}

void ODashboardApp::createSelectedWidget(wxCommandEvent& event)
{
	unsigned int vSize = widgetClasses.size();
	for (unsigned int i = 0; i < vSize; i++) {
		if (event.GetId() == widgetClasses[i]->handlerID) {
			addToWidgets(widgetClasses[i]->createNewObj());
			break;
		}
	}

	UpdateWidgets();
}

void ODashboardApp::addToWidgets(WidgetFrame* widget)
{
	widgets.push_back(widget);
	widget->SetVectorIndex(widgets.size());
}


void ODashboardApp::addToWidgetclasses(WidgetFrame* widget)
{
	widgetClasses.push_back(widget);
}


void ODashboardApp::removeFromWidgets(WidgetFrame* widget)
{
	unsigned int vSize = widgets.size();
	for (unsigned int i = 0; i < vSize; i++) {
		if (widgets[i] == widget) {
			widgets.erase(widgets.begin() + i);
			break;
		}	
	}
}