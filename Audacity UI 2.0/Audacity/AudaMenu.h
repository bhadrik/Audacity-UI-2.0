#pragma once
#include "AudaPanel.h"

using namespace std;

class AudaMenu : public AudaPanel{
private:
	wxStaticText* titleText;

public:
    AudaMenu(
        wxWindow* parent,
        const wxString& title,
        const wxColour& borderColor = OUTLINE_COLOR,
        int borderSize = 5,
        wxWindowID windowId = wxID_ANY,
        const wxPoint& position = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = wxBackgroundStyle::wxBG_STYLE_TRANSPARENT,
        const wxString& panelName = wxString::FromAscii(wxPanelNameStr)
    );
};