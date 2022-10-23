#include "Auda.h"

AudaFrame::AudaFrame(const wxString& title, const wxPoint& pos, const wxSize& size) : 
    wxFrame(NULL, wxID_ANY, title, pos, size)
{
    SetBackgroundColour(AudaColor::L1_100);
    Maximize(true);
    
    AudaMenuBar* menuBar = new AudaMenuBar(this, wxDefaultPosition, wxSize(200, 20), L2_100_COLOR);

    AudaMenu* fileMenu = new AudaMenu(this, "File", OUTLINE_COLOR, 0, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBG_STYLE_TRANSPARENT);
    AudaMenu* helpMenu = new AudaMenu(this, "Help", OUTLINE_COLOR, 0, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBG_STYLE_TRANSPARENT);
    menuBar->Append(fileMenu);
    menuBar->Append(helpMenu);
    menuBar->SetupSizer();

    AudaPanel* mainPanel = new AudaPanel(this, OUTLINE_COLOR, 1, wxID_ANY, wxDefaultPosition, wxSize(500, 400));
    mainPanel->SetBackgroundColour(L1_100_COLOR);

    //wxStaticText* demo = new wxStaticText(mainPanel, wxID_ANY, "Demo text here");

    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(menuBar, 0, wxEXPAND);
    sizer->Add(mainPanel, 1, wxEXPAND);

    this->SetSizerAndFit(sizer);
    //SetSizer(sizer);

    Layout();

    /*wxMenu* menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
        "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    wxMenu* menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar* menuBar = new wxMenuBar(0L);
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
    menuBar->SetBackgroundColour(L2_100_COLOR);
    menuBar->SetForegroundColour(L2_100_COLOR);*/
}

