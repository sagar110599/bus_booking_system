/***************************************************************
 * Name:      busMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2019-07-09
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef BUSMAIN_H
#define BUSMAIN_H

//(*Headers(busFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
#include <wx/tglbtn.h>
//*)

class busFrame: public wxFrame
{
    public:

        busFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~busFrame();

    private:

        //(*Handlers(busFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnToggleButton2Toggle(wxCommandEvent& event);
        void OnToggleButton1Toggle(wxCommandEvent& event);
        void OnToggleButton1Toggle1(wxCommandEvent& event);
        void OnToggleButton3Toggle(wxCommandEvent& event);
        //*)

        //(*Identifiers(busFrame)
        static const long ID_TOGGLEBUTTON2;
        static const long ID_STATICTEXT1;
        static const long ID_TOGGLEBUTTON1;
        static const long ID_TOGGLEBUTTON3;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(busFrame)
        wxStaticText* StaticText1;
        wxStatusBar* StatusBar1;
        wxToggleButton* ToggleButton1;
        wxToggleButton* ToggleButton2;
        wxToggleButton* ToggleButton3;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // BUSMAIN_H
