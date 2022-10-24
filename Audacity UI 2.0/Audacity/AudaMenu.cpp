#include "AudaMenu.h"

AudaMenu::AudaMenu(wxWindow* parent, const wxString &title, const wxColour& borderColor, int borderSize, wxWindowID windowId, const wxPoint& position, const wxSize& size, long style, const wxString& panelName)
	: AudaPanel(parent, borderColor, 0, windowId, position, size, style, panelName)
{
	// Events listening 
	Bind(wxEVT_ENTER_WINDOW, &AudaMenu::OnMouseEnter, this);
	Bind(wxEVT_LEAVE_WINDOW, &AudaMenu::OnMouseExit, this);

	wxFont mainFont = wxFont(9, wxFontFamily::wxFONTFAMILY_SCRIPT, wxFontStyle::wxFONTSTYLE_NORMAL, wxFontWeight::wxFONTWEIGHT_NORMAL);
	SetFont(mainFont);

	m_menuSizer = new wxBoxSizer(wxHORIZONTAL);

	SetBackgroundColour(TEST_GREEN);
	//SetBackgroundColour(L2_100_COLOR);

	m_titleText = new wxStaticText((wxWindow*)this, wxID_ANY, title, wxDefaultPosition, wxDefaultSize, wxBG_STYLE_TRANSPARENT);
	m_titleText->SetForegroundColour(*wxWHITE);
	m_titleText->Bind(wxEVT_ENTER_WINDOW, &AudaMenu::PendingOnMouseEnter, this);
	m_titleText->Bind(wxEVT_LEAVE_WINDOW, &AudaMenu::PendingOnMouseExit, this);
	//m_titleText->Bind(wxEVT_ENTER_WINDOW, &AudaMenu::OnMouseEnter, this);
	//m_titleText->Bind(wxEVT_LEAVE_WINDOW, &AudaMenu::OnMouseExit, this);

	m_menuSizer->Add(m_titleText, 0, wxALIGN_CENTER | wxRIGHT | wxLEFT, 10);
	m_menuSizer->SetMinSize(wxSize(10, 14));

	this->SetSizerAndFit(m_menuSizer);
	Layout();
}

void AudaMenu::OnMouseEnter(wxMouseEvent& event)
{
	this->SetBackgroundColour(TEST_BLUE);
	Refresh();
}

void AudaMenu::OnMouseExit(wxMouseEvent& event)
{
	this->SetBackgroundColour(TEST_GREEN);
	Refresh();
}

void AudaMenu::PendingOnMouseEnter(wxMouseEvent& event) {
	this->AddPendingEvent(wxCommandEvent(wxEVT_ENTER_WINDOW));
}

void AudaMenu::PendingOnMouseExit(wxMouseEvent& event) {
	this->AddPendingEvent(wxCommandEvent(wxEVT_LEAVE_WINDOW));
}

//BEGIN_EVENT_TABLE(AudaMenu, wxPanel)
//
//EVT_ENTER_WINDOW(AudaMenu::OnMouseEnter)
//EVT_LEAVE_WINDOW(AudaMenu::OnMouseExit)
//
//END_EVENT_TABLE()