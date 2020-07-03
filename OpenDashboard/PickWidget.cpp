#include "PickWidget.h"
#include "Colors.h"

PickWidget::PickWidget() : WidgetFrame("Color", true, true, 24003)
{
	SetBackgroundColour(color3);
	UpdateSize(wxSize(250, 150), true);

	WidgetText* title = new WidgetText(this, wxID_ANY, "Enter a RGB Color Code:", wxPoint(20, 20), wxSize(130, 15), 0, "");
	title->SetForegroundColour(textcolor5);
	title->SetFont(wxFont(8,
		wxFONTFAMILY_DECORATIVE,
		wxFONTSTYLE_NORMAL,
		wxFONTWEIGHT_BOLD,
		false));


}

PickWidget::~PickWidget()
{
}
