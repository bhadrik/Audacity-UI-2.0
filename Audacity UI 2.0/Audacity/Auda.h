#pragma once

#include "AudaColor.h"
#include "AudaPanel.h"
#include "AudaMenuBar.h"


class AudaFrame : public wxFrame
{
public:
    AudaFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

    /*static wxLog* logger;

    static void Log(wxString msg) {
        logger->LogText(msg);
    }*/
};