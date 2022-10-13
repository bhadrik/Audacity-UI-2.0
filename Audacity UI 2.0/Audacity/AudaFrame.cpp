#include "Auda.h"

AudaFrame::AudaFrame(const wxString& title, const wxPoint& pos, const wxSize& size) : 
    wxFrame(NULL, wxID_ANY, title, pos, size)
{
    SetBackgroundColour(*AudaColor::L1_100);

    // Creating custome Auda title bar
    AudaTitleBar* titleBar = new AudaTitleBar(this, wxDefaultPosition, 30, *AudaColor::L2_100);

    AudaPanel* mainPanel = new AudaPanel(this, wxDefaultSize, wxDefaultPosition);

    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(titleBar, 0, wxEXPAND);
    //sizer->Add(mainPanel, 1, wxEXPAND);

    //SetSizer(sizer);
    Layout();
}