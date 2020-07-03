#pragma once
#include <wx/wx.h>
#include <wx/display.h>
#include "WidgetFrame.h"

class SettingsWidget : public WidgetFrame
{
public:
	SettingsWidget();
	~SettingsWidget();

	void resetPosition();

	// settings
	bool autostart = false;


private:
	void OnClose(wxCommandEvent& event) override;
	wxPanel* settChoosePanel = nullptr;
	wxPanel* settingPanel = nullptr;

	void OnAppBtn(wxCommandEvent& event);
	void OnColorsBtn(wxCommandEvent& event);
	void OnKeybBtn(wxCommandEvent& event);
};

