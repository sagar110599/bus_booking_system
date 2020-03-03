/***************************************************************
 * Name:      busMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2019-07-09
 * Copyright:  ()
 * License:
 **************************************************************/

#include "busMain.h"
#include <wx/msgdlg.h>
#include<windows.h>
#include "Admin1.h"
#include <mysql.h>
#include "user1.h"
using namespace std;
    MYSQL* conn;

    MYSQL_RES *res;
    int qstate;



//(*InternalHeaders(busFrame)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(busFrame)
const long busFrame::ID_TOGGLEBUTTON2 = wxNewId();
const long busFrame::ID_STATICTEXT1 = wxNewId();
const long busFrame::ID_TOGGLEBUTTON1 = wxNewId();
const long busFrame::ID_TOGGLEBUTTON3 = wxNewId();
const long busFrame::idMenuQuit = wxNewId();
const long busFrame::idMenuAbout = wxNewId();
const long busFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(busFrame,wxFrame)
    //(*EventTable(busFrame)
    //*)
END_EVENT_TABLE()

busFrame::busFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(busFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    ToggleButton2 = new wxToggleButton(this, ID_TOGGLEBUTTON2, _("exit"), wxPoint(32,224), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TOGGLEBUTTON2"));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("welcome to oneclick bus system"), wxPoint(16,40), wxSize(280,32), wxST_NO_AUTORESIZE|wxALIGN_LEFT, _T("ID_STATICTEXT1"));
    wxFont StaticText1Font(18,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    StaticText1->SetFont(StaticText1Font);
    ToggleButton1 = new wxToggleButton(this, ID_TOGGLEBUTTON1, _("ADMIN LOGIN"), wxPoint(144,120), wxSize(176,23), 0, wxDefaultValidator, _T("ID_TOGGLEBUTTON1"));
    ToggleButton3 = new wxToggleButton(this, ID_TOGGLEBUTTON3, _("USER LOGIN"), wxPoint(144,184), wxSize(176,23), 0, wxDefaultValidator, _T("ID_TOGGLEBUTTON3"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(ID_TOGGLEBUTTON2,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&busFrame::OnToggleButton2Toggle);
    Connect(ID_TOGGLEBUTTON1,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&busFrame::OnToggleButton1Toggle1);
    Connect(ID_TOGGLEBUTTON3,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&busFrame::OnToggleButton3Toggle);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&busFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&busFrame::OnAbout);
    //*)

}

busFrame::~busFrame()
{
    //(*Destroy(busFrame)
    //*)

}

void busFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void busFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void busFrame::OnToggleButton2Toggle(wxCommandEvent& event)
{
    Destroy();
}



void busFrame::OnToggleButton1Toggle1(wxCommandEvent& event)
{
    Admin1 *a1 =new Admin1(0);
    this->Hide();
    a1->Show();
}

void busFrame::OnToggleButton3Toggle(wxCommandEvent& event)
{
    user1 *u=new user1(0);
    this->Hide();
    u->Show();
}
