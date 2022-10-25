#include "Auda.h"
#include "wx/log.h"

AudaFrame::AudaFrame(const wxString& title, const wxPoint& pos, const wxSize& size) : 
    wxFrame(NULL, wxID_ANY, title, pos, size)
{
    SetBackgroundColour(AudaColor::L1_100);
    //Maximize(true);
    
    AudaMenuBar* menuBar = new AudaMenuBar(this, wxDefaultPosition, wxSize(200, 20), L2_100_COLOR);

    AudaMenu* fileMenu = new AudaMenu(menuBar, "File", OUTLINE_COLOR, 0, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBG_STYLE_TRANSPARENT);
    AudaMenu* editMenu = new AudaMenu(menuBar, "Edit", OUTLINE_COLOR, 0, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBG_STYLE_TRANSPARENT);
    AudaMenu* selectMenu = new AudaMenu(menuBar, "Select", OUTLINE_COLOR, 0, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBG_STYLE_TRANSPARENT);
    AudaMenu* viewMenu = new AudaMenu(menuBar, "View", OUTLINE_COLOR, 0, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBG_STYLE_TRANSPARENT);
    AudaMenu* transportMenu = new AudaMenu(menuBar, "Transport", OUTLINE_COLOR, 0, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBG_STYLE_TRANSPARENT);
    AudaMenu* tracksMenu = new AudaMenu(menuBar, "Tracks", OUTLINE_COLOR, 0, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBG_STYLE_TRANSPARENT);
    AudaMenu* analyzeMenu = new AudaMenu(menuBar, "Analyze", OUTLINE_COLOR, 0, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBG_STYLE_TRANSPARENT);
    AudaMenu* toolMenu = new AudaMenu(menuBar, "Tool", OUTLINE_COLOR, 0, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBG_STYLE_TRANSPARENT);
    menuBar->Append(fileMenu);
    menuBar->Append(editMenu);
    menuBar->Append(selectMenu);
    menuBar->Append(viewMenu);
    menuBar->Append(transportMenu);
    menuBar->Append(tracksMenu);
    menuBar->Append(analyzeMenu);
    menuBar->Append(toolMenu);


    AudaPanel* mainPanel = new AudaPanel(this, OUTLINE_COLOR, 1, wxID_ANY, wxDefaultPosition, wxSize(500, 400));
    mainPanel->SetBackgroundColour(L1_100_COLOR);

    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(menuBar, 0, wxEXPAND);
    sizer->Add(mainPanel, 1, wxEXPAND);

    this->SetSizerAndFit(sizer);

    Layout();

    wxLog::SetActiveTarget(new wxLogStderr());
}