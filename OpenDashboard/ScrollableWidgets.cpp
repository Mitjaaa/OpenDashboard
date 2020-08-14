#include "ScrollableWidgets.h"
#include "ODashboardApp.h"
#include "Colors.h"

ScrollableWidgets::ScrollableWidgets(wxWindow* parent, wxPoint pos, wxSize size) : wxScrolledWindow(parent, wxID_ANY, pos, size)
{
    sizer = new wxBoxSizer(wxVERTICAL);
}

ScrollableWidgets::~ScrollableWidgets() {}

void ScrollableWidgets::addToSizer(WidgetFrame* widget) {
    wxSize btnSize;

    if (ODashboardApp::getApp()->menuEntries > 30) btnSize = wxSize(126, 25);
    else btnSize = wxSize(142, 25);

    wxButton* button = new wxButton(this, widget->handlerID, widget->widgetName, wxDefaultPosition, btnSize, wxBORDER_NONE);

    button->SetBackgroundColour(bgcolours[0].clr);
    button->SetForegroundColour(textcolours[1].clr);
    button->SetCursor(wxCURSOR_HAND);

    button->Bind(wxEVT_BUTTON, &ScrollableWidgets::WidgetSelected, this);
    button->Bind(wxEVT_PAINT, [=](wxPaintEvent& event) {
        button->SetBackgroundColour(bgcolours[0].clr);
        button->SetForegroundColour(textcolours[1].clr);
    });

    sizer->Add(button, 0, wxALL, 3);
}

void ScrollableWidgets::configureSizer() {
    this->SetSizer(sizer);

    this->FitInside();
    this->SetScrollRate(5, 5);
}


void ScrollableWidgets::WidgetSelected(wxCommandEvent& event)
{
    ODashboardApp::getApp()->createSelectedWidget(event);
}