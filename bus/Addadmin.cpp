#include "Addadmin.h"
#include "Admin2.h"
#include <wx/msgdlg.h>
#include<mysql.h>


using namespace std;
    MYSQL* conn2;

    MYSQL_RES *res2;
    int qstate2;


//(*InternalHeaders(Addadmin)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(Addadmin)
const long Addadmin::ID_STATICTEXT1 = wxNewId();
const long Addadmin::ID_TEXTCTRL1 = wxNewId();
const long Addadmin::ID_STATICTEXT2 = wxNewId();
const long Addadmin::ID_STATICTEXT3 = wxNewId();
const long Addadmin::ID_TEXTCTRL2 = wxNewId();
const long Addadmin::ID_STATICTEXT4 = wxNewId();
const long Addadmin::ID_TEXTCTRL3 = wxNewId();
const long Addadmin::ID_STATICTEXT5 = wxNewId();
const long Addadmin::ID_TEXTCTRL4 = wxNewId();
const long Addadmin::ID_TOGGLEBUTTON1 = wxNewId();
const long Addadmin::ID_TOGGLEBUTTON2 = wxNewId();
const long Addadmin::ID_STATICTEXT6 = wxNewId();
const long Addadmin::ID_TEXTCTRL5 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Addadmin,wxFrame)
	//(*EventTable(Addadmin)
	//*)
END_EVENT_TABLE()

Addadmin::Addadmin(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(Addadmin)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("SOURCE"), wxPoint(48,72), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("Text"), wxPoint(128,64), wxSize(172,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("ENTER BUS DETAILS"), wxPoint(96,16), wxSize(240,32), wxST_NO_AUTORESIZE|wxALIGN_LEFT, _T("ID_STATICTEXT2"));
	wxFont StaticText2Font(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText2->SetFont(StaticText2Font);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("DESTINATION"), wxPoint(48,120), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, _("Text"), wxPoint(128,112), wxSize(168,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("DEPARTURE TIME"), wxPoint(24,176), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL3, _("Text"), wxPoint(128,168), wxSize(168,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("price"), wxPoint(72,224), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	TextCtrl4 = new wxTextCtrl(this, ID_TEXTCTRL4, _("Text"), wxPoint(128,216), wxSize(168,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	ToggleButton1 = new wxToggleButton(this, ID_TOGGLEBUTTON1, _("ADD DETAILS"), wxPoint(264,328), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TOGGLEBUTTON1"));
	ToggleButton2 = new wxToggleButton(this, ID_TOGGLEBUTTON2, _("BACK"), wxPoint(64,328), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TOGGLEBUTTON2"));
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("CAPACITY"), wxPoint(64,288), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	TextCtrl5 = new wxTextCtrl(this, ID_TEXTCTRL5, _("Text"), wxPoint(128,280), wxSize(160,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));

	Connect(ID_TOGGLEBUTTON1,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&Addadmin::OnToggleButton1Toggle);
	Connect(ID_TOGGLEBUTTON2,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&Addadmin::OnToggleButton2Toggle);
	Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&Addadmin::OnClose);
	//*)
	 conn2 = mysql_init(0);
    conn2 = mysql_real_connect(conn2,"localhost","root","","bus system",0,NULL,0);
    if(conn2)

        wxMessageBox("wrong username and password","try again");
     else

        wxMessageBox("wrong username and password","incfo");
}

Addadmin::~Addadmin()
{
	//(*Destroy(Addadmin)
	//*)
	mysql_close(conn2);
}


void Addadmin::OnToggleButton1Toggle(wxCommandEvent& event)
{
    string s=(TextCtrl1->GetValue()).ToStdString();
    string d=(TextCtrl2->GetValue()).ToStdString();
    string d_time=(TextCtrl3->GetValue()).ToStdString();
    string p=(TextCtrl4->GetValue()).ToStdString();
    string caps=(TextCtrl5->GetValue()).ToStdString();

    string q31="insert into bus_details(source,destination,depart_time,price,capacity) values('"+s+"','"+d+"','"+d_time+"','"+p+"','"+caps+"');";
    const char* q3 = q31.c_str();

    qstate2 = mysql_query(conn2,q3);
    if(!qstate2)
            wxMessageBox("record added . go back to login","info");
    else

          wxMessageBox("record not added ","info");


}

void Addadmin::OnToggleButton2Toggle(wxCommandEvent& event)
{
   Admin2 *bt=new Admin2(0);
   this->Hide();
   bt->Show();
}

void Addadmin::OnClose(wxCloseEvent& event)
{
}
