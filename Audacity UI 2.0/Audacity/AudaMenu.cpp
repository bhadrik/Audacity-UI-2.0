#include "AudaMenu.h"

AudaMenu::AudaMenu(wxWindow* parent, const wxString &title, const wxColour& borderColor, int borderSize, wxWindowID windowId, const wxPoint& position, const wxSize& size, long style, const wxString& panelName)
	: AudaPanel(parent, borderColor, 0, windowId, position, size, style, panelName)
{
	wxFont mainFont = wxFont(9, wxFontFamily::wxFONTFAMILY_SCRIPT, wxFontStyle::wxFONTSTYLE_NORMAL, wxFontWeight::wxFONTWEIGHT_NORMAL);
	SetFont(mainFont);

	SetBackgroundColour(L2_100_COLOR);
	//SetBackgroundColour(wxTransparentColor);

	titleText = new wxStaticText((wxWindow*)this, wxID_ANY, title, wxDefaultPosition, wxDefaultSize, wxBG_STYLE_TRANSPARENT);
	titleText->SetForegroundColour(*wxWHITE);
	//titleText->SetBackgroundColour(wxColor(200,50,50));
	//titleText->SetBackgroundColour(wxTransparentColor);
	titleText->SetupColours();
}