#include "Auda.h"

AudaFrame::AudaFrame(const wxString& title, const wxPoint& pos, const wxSize& size) : 
    wxFrame(NULL, wxID_ANY, title, pos, size)
{
    SetBackgroundColour(AudaColor::L1_100);
    Maximize(true);

    
    AudaPanel* one = new AudaPanel(this, OUTLINE_COLOR, 0, wxID_ANY, wxDefaultPosition, wxSize(200,20));
    one->SetBackgroundColour(L2_100_COLOR);

    AudaPanel* two = new AudaPanel(this, OUTLINE_COLOR, 1, wxID_ANY, wxDefaultPosition, wxSize(500, 400));
    two->SetBackgroundColour(L1_100_COLOR);

    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(one, 0, wxEXPAND);
    sizer->Add(two, 1, wxEXPAND);

    this->SetSizerAndFit(sizer);
    //SetSizer(sizer);

    Layout();
}