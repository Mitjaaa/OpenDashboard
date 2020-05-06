#include "WidgetFrame.h"
#include "ODashboardApp.h"
#include <thread>

BEGIN_EVENT_TABLE(WidgetFrame, wxFrame)
    EVT_LEFT_DOWN(OnLeftDown)
    EVT_LEFT_UP(OnLeftUp)
    EVT_MOTION(OnMouseMove)
END_EVENT_TABLE()

WidgetFrame::WidgetFrame(std::string name) : wxFrame(nullptr, wxID_ANY, name)
{
	SetWindowStyle(wxSTAY_ON_TOP | wxFRAME_TOOL_WINDOW);
    wxStaticText* placeholder = new wxStaticText(this, wxID_ANY, "");
}

WidgetFrame::~WidgetFrame()
{
}



void WidgetFrame::OnLeftDown(wxMouseEvent& event)
{
    CaptureMouse();
    capturing = true;

    const auto eventSource = static_cast<wxWindow*>(event.GetEventObject());
    const auto screenPosClicked = eventSource->ClientToScreen(event.GetPosition());
    const auto origin = GetPosition();

    mouseDownPos = screenPosClicked - origin;
}

void WidgetFrame::OnMouseMove(wxMouseEvent& event)
{
    if (event.Dragging() && event.LeftIsDown())
    {
        const auto screenPosCurrent = ClientToScreen(event.GetPosition());
        Move(screenPosCurrent - mouseDownPos);
    }
}

void WidgetFrame::OnLeftUp(wxMouseEvent& event)
{
    if (capturing) {
        ReleaseMouse();
        capturing = false;
    }
}

WidgetFrame* WidgetFrame::getWidgetFrame()
{
    return this;
}
		