#include "register_user.h"
#include <wx/msgdlg.h>
#include<mysql.h>

using namespace std;
    MYSQL* con1;


    int qstate11;
//(*InternalHeaders(register_user)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(register_user)
const long register_user::ID_STATICTEXT1 = wxNewId();
const long register_user::ID_STATICTEXT2 = wxNewId();
const long register_user::ID_STATICTEXT3 = wxNewId();
const long register_user::ID_STATICTEXT4 = wxNewId();
const long register_user::ID_STATICTEXT5 = wxNewId();
const long register_user::ID_TEXTCTRL1 = wxNewId();
const long register_user::ID_TEXTCTRL2 = wxNewId();
const long register_user::ID_TEXTCTRL3 = wxNewId();
const long register_user::ID_TEXTCTRL4 = wxNewId();
const long register_user::ID_STATICTEXT6 = wxNewId();
const long register_user::ID_TEXTCTRL5 = wxNewId();
const long register_user::ID_TOGGLEBUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(register_user,wxFrame)
	//(*EventTable(register_user)
	//*)
END_EVENT_TABLE()

register_user::register_user(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(register_user)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("REGISTER HERE"), wxPoint(72,24), wxSize(240,40), wxST_NO_AUTORESIZE|wxALIGN_LEFT, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(18,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("NAME"), wxPoint(72,96), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("ADDRESS"), wxPoint(72,152), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("CONTACT NO"), wxPoint(56,208), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("USERNAME"), wxPoint(64,264), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(136,88), wxSize(184,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(136,144), wxSize(184,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxPoint(136,200), wxSize(184,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	TextCtrl4 = new wxTextCtrl(this, ID_TEXTCTRL4, wxEmptyString, wxPoint(136,256), wxSize(184,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("PASSWORD"), wxPoint(56,320), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	TextCtrl5 = new wxTextCtrl(this, ID_TEXTCTRL5, wxEmptyString, wxPoint(136,312), wxSize(184,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
	ToggleButton1 = new wxToggleButton(this, ID_TOGGLEBUTTON1, _("REGISTER"), wxPoint(216,384), wxSize(147,23), 0, wxDefaultValidator, _T("ID_TOGGLEBUTTON1"));

	Connect(ID_TOGGLEBUTTON1,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&register_user::OnToggleButton1Toggle);
	//*)
	con1 = mysql_init(0);
    con1 = mysql_real_connect(con1,"localhost","root","","bus system",0,NULL,0);
}

register_user::~register_user()
{
	//(*Destroy(register_user)
	//*)

     mysql_close(con1);
}


void register_user::OnToggleButton1Toggle(wxCommandEvent& event)
{
    string name=(TextCtrl1->GetValue()).ToStdString();
    string add=(TextCtrl2->GetValue()).ToStdString();
    string telno_s=(TextCtrl3->GetValue()).ToStdString();

    string username=(TextCtrl4->GetValue()).ToStdString();
    string password=(TextCtrl5->GetValue()).ToStdString();

    string query11="insert into customer values('"+name+"','"+add+"','"+telno_s+"','"+username+"','"+password+"','LOGGED OUT');";

    const char* q11 = query11.c_str();

    qstate11 = mysql_query(con1,q11);
    if(!qstate11)
            wxMessageBox("record added . go back to login","info");
    else

          wxMessageBox("record not added ","info");


}
