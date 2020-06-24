#include "SettingsWidget.h"

SettingsWidget::SettingsWidget() : WidgetFrame("Settings", true, true, 26000)
{
	int width = wxDisplay().GetGeometry().GetWidth();
	int height = wxDisplay().GetGeometry().GetHeight();

	SetWindowStyle(wxSTAY_ON_TOP | wxFRAME_TOOL_WINDOW);
	UpdateSize(wxSize(500, 400), true);
	SetPosition(wxPoint(((width / 2) - GetSize().x / 2) - 150, (height / 2) - GetSize().y / 2));
	SetBackgroundColour(wxColour(46, 46, 46));

	settingsPanel = new wxPanel(this, wxID_ANY, wxPoint(0, 15), wxSize(125, this->GetSize().y - 15));
	settingsPanel->SetBackgroundColour(wxColour(66, 66, 66));
}

SettingsWidget::~SettingsWidget() {}
