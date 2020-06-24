#include "ImageWidget.h"

ImageWidget::ImageWidget() : WidgetFrame("Image", true, true, 24001)
{
	wxInitAllImageHandlers();

	SetBackgroundColour(wxColour(46, 46, 46));
	UpdateSize(wxSize(300, 500), true);

	filepath = new wxTextCtrl(this, wxID_ANY, "Choose a file...", wxPoint(20, 30), wxSize(200, 15), wxBORDER_NONE);
	filepath->SetBackgroundColour(wxColour(74, 74, 74));
	filepath->SetForegroundColour(wxColour(39, 232, 167));
	filepath->SetEditable(false);

	chooseFile = new wxButton(this, wxID_ANY, "Choose", wxPoint(230, 30), wxSize(50, 15), wxBORDER_NONE);
	chooseFile->SetBackgroundColour(wxColour(74, 74, 74));
	chooseFile->SetForegroundColour(wxColour(39, 232, 167));
	chooseFile->SetCursor(wxCURSOR_HAND);

	chooseFile->Bind(wxEVT_BUTTON, &ImageWidget::OnChoose, this);

	wxInitAllImageHandlers();

	image = new ImageWindow(this, wxPoint(20, 70), /*wxSize(260, 400)*/ wxSize(800, 800), this);
	sizer = new wxBoxSizer(wxHORIZONTAL);

	arrow_down.LoadFile("Resources\\arrow_down.png", wxBITMAP_TYPE_PNG);
	openFileDialog = new wxFileDialog(this, _("Open Image..."), "", "", "PNG files (*.png)|*.png|JPG files (*jpg)|*jpg", wxFD_OPEN);
}

ImageWidget::~ImageWidget() {}

void ImageWidget::OnChoose(wxCommandEvent& event)
{
	if (openFileDialog->ShowModal() == wxID_CANCEL)
		return;

	filepath->SetLabel(openFileDialog->GetPath());
	int x = 0;
	int y = 0;

	if (factorText == nullptr) {
		factorText = new wxStaticText(this, wxID_ANY, "Factor:", wxPoint(10, 10), wxSize(40, 20));
	}

	factorText->SetForegroundColour(wxColour(191, 191, 191));

	if (!sizer->IsEmpty()) sizer->Clear();

	if (openFileDialog->GetPath().EndsWith(".png")) {
		image->setImage(openFileDialog->GetPath(), wxBITMAP_TYPE_PNG);
		image->Update();
		image->Refresh();

		x = image->GetSize().x + image->GetPosition().x * 2;
		y = image->GetSize().y + image->GetPosition().y + image->GetPosition().x;

		UpdateWidgetSize(wxSize(x, y + 35), false);
		Refresh();
	}
	else {
		image->setImage(openFileDialog->GetPath(), wxBITMAP_TYPE_JPEG);
		image->Update();
		image->Refresh();

		x = image->GetSize().x + image->GetPosition().x * 2;
		y = image->GetSize().y + image->GetPosition().y + image->GetPosition().x;

		UpdateWidgetSize(wxSize(x, y + 35), false);
		Refresh();
	}

	factorText->SetPosition(wxPoint(image->GetPosition().x, y - 4));

	if (factorChoice != nullptr)		factorChoice->Destroy();
	factorChoice = new wxChoice(this, wxID_ANY, wxPoint(image->GetPosition().x + factorText->GetSize().x, y - 5), wxSize(20, 20));

	factorChoice->AppendString("");
	factorChoice->AppendString("1");
	factorChoice->AppendString("2");
	factorChoice->AppendString("3");
	factorChoice->AppendString("4");

	factorChoice->Bind(wxEVT_PAINT, [=](wxPaintEvent& event) {

		wxPaintDC dc(factorChoice);
		wxRect rect(0, 0, dc.GetSize().GetWidth(), dc.GetSize().GetHeight());
		const wxString sel = factorChoice->GetStringSelection();

		dc.SetBrush(wxBrush(wxColour(46, 46, 46)));
		dc.SetPen(wxPen(wxColour(66, 66, 66)));
		dc.DrawRectangle(rect);

		wxBitmap resized;

		resized = wxBitmap(arrow_down.Scale(arrow_down.GetSize().x / 25, arrow_down.GetSize().y / 25, wxIMAGE_QUALITY_HIGH));

		if (!sel.IsEmpty())
		{
			dc.SetTextForeground(wxColour(191, 191, 191));
			dc.DrawLabel(sel, rect, wxALIGN_CENTER);
		}
		else {
			dc.DrawBitmap(resized, rect.GetWidth() - 16, (rect.GetHeight() / 2) - 2, false);
		}
		});

	factorChoice->Bind(wxEVT_CHOICE, [=](wxCommandEvent& event) {
		const wxString sel = factorChoice->GetStringSelection();
		if (!sel.IsEmpty()) {
			image->factor = std::stoi(sel.wc_str());
			image->Update();
			image->resize();
			image->Refresh();

			int x = image->GetSize().x + image->GetPosition().x * 2;
			int y = image->GetSize().y + image->GetPosition().y + image->GetPosition().x;

			UpdateWidgetSize(wxSize(x, y + 35), true);
		}
		});
}

void ImageWidget::UpdateWidgetSize(wxSize size, bool isImageShowing)
{
	UpdateSize(size, true);
	filepath->SetSize(wxSize(size.x - 100, 15));
	chooseFile->SetPosition(wxPoint(size.x - 70, 30));

	if (isImageShowing) {
		factorChoice->SetPosition(wxPoint(image->GetPosition().x + factorText->GetSize().x, (size.y - 35) - 5));
		factorText->SetPosition(wxPoint(image->GetPosition().x, (size.y - 35) - 4));
	}
}

WidgetFrame* ImageWidget::createNewObj()
{
	return new ImageWidget();
}
