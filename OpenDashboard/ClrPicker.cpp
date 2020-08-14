#include "ClrPicker.h"
#include "ODashboardApp.h"
#include "PickWidget.h"

bool picking = false;


ClrPicker::ClrPicker(wxWindow* parent,
	wxWindowID id,
	int section,
	int index,
	bool mf,		
	const wxString& label,
	const wxPoint& pos,
	const wxSize& size,
	long style,
	const wxValidator& validator,
	const wxString& name) : wxButton(parent, id, label, pos, size, style, validator, name), section(section), index(index), mainframe(mf)
{
	SetCursor(wxCURSOR_HAND);

	Bind(wxEVT_PAINT, [=](wxPaintEvent& event) {
		wxPaintDC dc(this);
		wxRect rect(0, 0, dc.GetSize().GetWidth(), dc.GetSize().GetHeight());

		if (section == 1) {
			dc.SetBrush(wxBrush(textcolours[index].clr));
			dc.SetTextForeground(textcolours[index].clr);
		}
		else if (section == 2) {
			dc.SetBrush(wxBrush(bgcolours[index].clr));
			dc.SetTextForeground(bgcolours[index].clr);
		}
		else {
			dc.SetBrush(wxBrush(colours[index].clr));
			dc.SetTextForeground(colours[index].clr);
		}

		dc.DrawRectangle(rect);
	});

	Bind(wxEVT_BUTTON, &ClrPicker::OnPick, this);
}

ClrPicker::~ClrPicker()
{
}

PickWidget* pickWidget = nullptr;

void ClrPicker::OnPick(wxCommandEvent& event)
{
	if (picking) {
		ODashboardApp::getApp()->removeFromWidgets(pickWidget);
		pickWidget->Destroy();
		pickWidget = nullptr;
	}
	else {
		if (section == 1) {
			pickWidget = new PickWidget(textcolours[index], mainframe);
		}
		else if (section == 2) {
			pickWidget = new PickWidget(bgcolours[index], mainframe);
		}
		else {
			OutputDebugStringA(std::to_string(mainframe).c_str());
			pickWidget = new PickWidget(colours[index], mainframe);
		}	

		pickWidget->Show();
		ODashboardApp::getApp()->addToWidgets(pickWidget);
	}

	picking = !picking;
}