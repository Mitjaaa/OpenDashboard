#include "ClrPicker.h"
#include "Colors.h"
#include "ODashboardApp.h"
#include "PickWidget.h"

ClrPicker::ClrPicker(wxWindow* parent,
	wxWindowID id,
	wxColour colour,
	const wxString& label,
	const wxPoint& pos,
	const wxSize& size,
	long style,
	const wxValidator& validator,
	const wxString& name) : wxButton(parent, id, label, pos, size, style, validator, name), clr(colour)
{
	Bind(wxEVT_PAINT, [=](wxPaintEvent& event) {
		wxPaintDC dc(this);
		wxRect rect(0, 0, dc.GetSize().GetWidth(), dc.GetSize().GetHeight());

		dc.SetBrush(wxBrush(color5));
		dc.DrawRectangle(rect);

		dc.SetTextForeground(clr);
	});

	Bind(wxEVT_BUTTON, &ClrPicker::OnPick, this);
}

ClrPicker::~ClrPicker()
{
}

bool picking = false;
PickWidget* pickWidget = nullptr;

void ClrPicker::OnPick(wxCommandEvent& event)
{
	if (picking) {
		ODashboardApp::getApp()->removeFromWidgets(pickWidget);
		pickWidget->Destroy();
	}
	else {
		if (pickWidget == nullptr || pickWidget->IsBeingDeleted())
			pickWidget = new PickWidget();

		pickWidget->Show();
		ODashboardApp::getApp()->addToWidgets(pickWidget);
	}

	picking = !picking;
}
