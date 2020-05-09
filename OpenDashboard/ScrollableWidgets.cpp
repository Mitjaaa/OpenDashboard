#include "ScrollableWidgets.h"
#include "WidgetMenu.h"
#include "ODashboardApp.h"

ScrollableWidgets::ScrollableWidgets(wxWindow* parent, wxPoint pos, wxSize size) : wxScrolledWindow(parent, wxID_ANY, pos, size)
{
    sizer = new wxBoxSizer(wxVERTICAL);
}

ScrollableWidgets::~ScrollableWidgets()
{
}       
    
void ScrollableWidgets::addToSizer(WidgetFrame* widget) {
    wxButton* button = new wxButton(this, widget->handlerID, widget->widgetName, wxDefaultPosition, wxSize(142, 25), wxBORDER_NONE);
    
    button->SetBackgroundColour(wxColour(64, 64, 64));
    button->SetForegroundColour(wxColour(105, 203, 214));
    button->SetCursor(wxCURSOR_HAND);

    button->Bind(wxEVT_BUTTON, &ScrollableWidgets::WidgetSelected, this);

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