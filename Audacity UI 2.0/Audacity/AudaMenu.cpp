#include "AudaMenu.h"

AudaMenu::AudaMenu(wxWindow* parent, const wxString &title, const wxColour& borderColor, int borderSize, wxWindowID windowId, const wxPoint& position, const wxSize& size, long style, const wxString& panelName)
	: AudaPanel(parent, borderColor, 0, windowId, position, size, style, panelName)
{
	// Events listening 
	Bind(wxEVT_ENTER_WINDOW, &AudaMenu::OnMouseEnter, this);
	Bind(wxEVT_LEAVE_WINDOW, &AudaMenu::OnMouseExit, this);
	Bind(wxEVT_LEFT_DOWN, &AudaMenu::OnMouseDown, this);

	wxFont mainFont = wxFont(9, wxFontFamily::wxFONTFAMILY_SCRIPT, wxFontStyle::wxFONTSTYLE_NORMAL, wxFontWeight::wxFONTWEIGHT_NORMAL);
	SetFont(mainFont);

	m_menuSizer = new wxBoxSizer(wxHORIZONTAL);

	SetBackgroundColour(TEST_GREEN);
	//SetBackgroundColour(L2_100_COLOR);

	m_titleText = new wxStaticText((wxWindow*)this, wxID_ANY, title, wxDefaultPosition, wxDefaultSize, wxBG_STYLE_TRANSPARENT);
	m_titleText->SetForegroundColour(*wxWHITE);
	m_titleText->Bind(wxEVT_ENTER_WINDOW, &AudaMenu::Text_OnMouseEnter, this);
	m_titleText->Bind(wxEVT_LEAVE_WINDOW, &AudaMenu::Text_OnMouseExit, this);
	m_titleText->Bind(wxEVT_LEFT_DOWN, &AudaMenu::OnMouseDown, this);

	m_menuSizer->Add(m_titleText, 0, wxALIGN_CENTER | wxRIGHT | wxLEFT, 10);
	m_menuSizer->SetMinSize(wxSize(10, 14));

	this->SetSizerAndFit(m_menuSizer);
	Layout();
}

void AudaMenu::OnMouseEnter(wxMouseEvent& event)
{
	m_overPanel = true;
	this->SetBackgroundColour(TEST_BLUE);
	Refresh();
}

void AudaMenu::OnMouseExit(wxMouseEvent& event)
{
	m_overPanel = false;

	if (!m_overText) {
		this->SetBackgroundColour(TEST_GREEN);
		Refresh();
	}
}

void AudaMenu::OnMouseDown(wxMouseEvent& event)
{
	
}

void AudaMenu::Text_OnMouseEnter(wxMouseEvent& event) {
	m_overText = true;

	this->SetBackgroundColour(TEST_BLUE);
	Refresh();
}

void AudaMenu::Text_OnMouseExit(wxMouseEvent& event) {
	m_overText = false;

	this->SetBackgroundColour(TEST_GREEN);
	Refresh();
}