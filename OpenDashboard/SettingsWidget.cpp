#include "SettingsWidget.h"
#include <wx\display.h>

SettingsWidget::SettingsWidget() : WidgetFrame("Settings", true, true, 26000)
{
	OutputDebugStringA("aa");
	int width = wxDisplay().GetGeometry().GetWidth();
	int height = wxDisplay().GetGeometry().GetHeight();

	SetWindowStyle(wxSTAY_ON_TOP | wxFRAME_TOOL_WINDOW);
	UpdateSize(wxSize(500, 400), true);
	SetPosition(wxPoint(((width / 2) - GetSize().x / 2) - 150, (height / 2) - GetSize().y / 2));
	SetBackgroundColour(wxColour(46, 46, 46));
}

SettingsWidget::~SettingsWidget()
{
}
