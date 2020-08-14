#include "PickWidget.h"
#include "ODashboardApp.h"
#include "ClrPicker.h"
#include "Globals.h"


PickWidget::PickWidget(globalColour clr, bool mfupdating) : WidgetFrame("Color", true, true, 24003), gcolour(clr), colour(gcolour.clr), mainfUpdating(mfupdating)
{
	Constructor();
}

PickWidget::PickWidget(wxColour clr, bool mfupdating) : WidgetFrame("Color", true, true, 24003), colour(clr), mainfUpdating(mfupdating)
{
	Constructor();
}

PickWidget::~PickWidget()
{
}


void PickWidget::Constructor() 
{
	SetBackgroundColour(bgcolours[2].clr);
	UpdateSize(wxSize(250, 150), true);

	WidgetText* title = new WidgetText(this, wxID_ANY, "Enter a RGB Color Code:", wxPoint(55, 30), wxSize(130, 15), 0, "");
	title->SetForegroundColour(textcolours[4].clr);
	title->SetFont(wxFont(8,
		wxFONTFAMILY_DECORATIVE,
		wxFONTSTYLE_NORMAL,
		wxFONTWEIGHT_BOLD,
		false));

	r = new wxTextCtrl(this, wxID_ANY, std::to_string(colour.Red()), wxPoint(37, 60), wxSize(30, 15), wxBORDER_NONE);
	r->SetBackgroundColour(bgcolours[0].clr);
	r->SetForegroundColour(textcolours[0].clr);
	r->Bind(wxEVT_TEXT, [=](wxCommandEvent& event) {
		if (!isStrDigit(r->GetValue().ToStdString()))
			r->SetValue(removeLetters(r->GetValue().ToStdString()));

		if (atoi(r->GetValue()) > 255)
			r->SetValue("255");
		});

	g = new wxTextCtrl(this, wxID_ANY, std::to_string(colour.Green()), wxPoint(107, 60), wxSize(30, 15), wxBORDER_NONE);
	g->SetBackgroundColour(bgcolours[0].clr);
	g->SetForegroundColour(textcolours[0].clr);
	g->Bind(wxEVT_TEXT, [=](wxCommandEvent& event) {
		if (!isStrDigit(g->GetValue().ToStdString()))
			g->SetValue(removeLetters(g->GetValue().ToStdString()));

		if (atoi(g->GetValue()) > 255)
			g->SetValue("255");
		});

	b = new wxTextCtrl(this, wxID_ANY, std::to_string(colour.Blue()), wxPoint(177, 60), wxSize(30, 15), wxBORDER_NONE);
	b->SetBackgroundColour(bgcolours[0].clr);
	b->SetForegroundColour(textcolours[0].clr);
	b->Bind(wxEVT_TEXT, [=](wxCommandEvent& event) {
		if (!isStrDigit(b->GetValue().ToStdString()))
			b->SetValue(removeLetters(b->GetValue().ToStdString()));

		if (atoi(b->GetValue()) > 255)
			b->SetValue("255");
		});

	wxButton* cancel = new wxButton(this, wxID_ANY, "Cancel", wxPoint(34, 100), wxSize(70, 20), wxBORDER_NONE);
	cancel->SetBackgroundColour(wxColour(bgcolours[0].clr));
	cancel->SetForegroundColour(wxColour(textcolours[6].clr));
	cancel->SetCursor(wxCURSOR_HAND);
	cancel->Bind(wxEVT_BUTTON, &PickWidget::Cancel, this);


	wxButton* apply = new wxButton(this, wxID_ANY, "Apply", wxPoint(140, 100), wxSize(70, 20), wxBORDER_NONE);
	apply->SetBackgroundColour(wxColour(bgcolours[0].clr));
	apply->SetForegroundColour(wxColour(textcolours[0].clr));
	apply->SetCursor(wxCURSOR_HAND);
	apply->Bind(wxEVT_BUTTON, &PickWidget::Apply, this);
}



void PickWidget::Cancel(wxCommandEvent& event)
{
	picking = false;
	ODashboardApp::getApp()->removeFromWidgets(this);
	Destroy();
}

void PickWidget::Apply(wxCommandEvent& event)
{
	if (!mainfUpdating) 
	{
		oldColour = gcolour;
		if (gcolour.section == 1) {
			textcolours[gcolour.index] = globalColour(std::stoi(r->GetValue().ToStdString()), std::stoi(g->GetValue().ToStdString()), std::stoi(b->GetValue().ToStdString()), gcolour.section, gcolour.index, true);
			ODashboardApp::getApp()->RefreshWidgetsWithColours(textcolours[gcolour.index].clr, true);
		}
		else if (gcolour.section == 2) {
			bgcolours[gcolour.index] = globalColour(std::stoi(r->GetValue().ToStdString()), std::stoi(g->GetValue().ToStdString()), std::stoi(b->GetValue().ToStdString()), gcolour.section, gcolour.index, true);
			ODashboardApp::getApp()->RefreshWidgetsWithColours(bgcolours[gcolour.index].clr, true);
		}
		else {
			colours[gcolour.index] = globalColour(std::stoi(r->GetValue().ToStdString()), std::stoi(g->GetValue().ToStdString()), std::stoi(b->GetValue().ToStdString()), gcolour.section, gcolour.index, true	);
			ODashboardApp::getApp()->RefreshWidgetsWithColours(colours[gcolour.index].clr, true);	
		}
	}
	else 
	{
		// temp solution
		colours[1].clr = wxColour(std::stoi(r->GetValue().ToStdString()), std::stoi(g->GetValue().ToStdString()), std::stoi(b->GetValue().ToStdString()));
		ODashboardApp::getApp()->mainframe->SetBackgroundColour(colours[1].clr);
		ODashboardApp::getApp()->mainframe->Refresh();
		ODashboardApp::getApp()->mainframe->Update();
	}

	picking = false;
	ODashboardApp::getApp()->removeFromWidgets(this);
	Destroy();
}

void PickWidget::OnClose(wxCommandEvent& event)
{
	picking = false;
	ODashboardApp::getApp()->removeFromWidgets(this);
	Destroy();
}