#pragma once
#include "WidgetFrame.h"
#include "globalColour.h"
#include "Colors.h"

class PickWidget : public WidgetFrame
{
public:
	PickWidget(globalColour clr, bool mfupdating);
	PickWidget(wxColour clr, bool mfupdating);

	~PickWidget();

private:
	globalColour gcolour = globalColour();
	wxColour colour;

	wxTextCtrl* r = nullptr;
	wxTextCtrl* g = nullptr;
	wxTextCtrl* b = nullptr;

	bool mainfUpdating = true;
	void Constructor();

	void Cancel(wxCommandEvent& event);
	void Apply(wxCommandEvent& event);

	void OnClose(wxCommandEvent& event) override;
};

