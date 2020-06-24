#pragma once
#include <wx/wx.h>
#include <wx/display.h>
#include "WidgetFrame.h"

class SettingsWidget : public WidgetFrame
{
public:
	SettingsWidget();
	~SettingsWidget();

private:
	wxPanel* settingsPanel = nullptr;
};

