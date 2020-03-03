#include "Admin2.h"
#include "Addadmin.h"
#include "adminadd2.h"
#include "Admin1.h"
#include<winsock.h>
#include<mysql.h>
#include <wx/msgdlg.h>
using namespace std;
    MYSQL* con5;
    MYSQL_ROW row5;
    MYSQL_RES *res5;
    int qstate5,qstate55;

//(*InternalHeaders(Admin2)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)


//(*IdInit(Admin2)
const long Admin2::ID_TOGGLEBUTTON1 = wxNewId();
const long Admin2::ID_TOGGLEBUTTON2 = wxNewId();
const long Admin2::ID_TOGGLEBUTTON3 = wxNewId();
const long Admin2::ID_STATICTEXT1 = wxNewId();
const long Admin2::ID_STATICTEXT2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Admin2,wxFrame)
	//(*EventTable(Admin2)
	//*)
END_EVENT_TABLE()

Admin2::Admin2(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(Admin2)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	ToggleButton1 = new wxToggleButton(this, ID_TOGGLEBUTTON1, _("LOG OUT"), wxPoint(304,24), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TOGGLEBUTTON1"));
	ToggleButton2 = new wxToggleButton(this, ID_TOGGLEBUTTON2, _("ADD ADMIN"), wxPoint(72,112), wxSize(248,23), 0, wxDefaultValidator, _T("ID_TOGGLEBUTTON2"));
	ToggleButton3 = new wxToggleButton(this, ID_TOGGLEBUTTON3, _("ADD BUS DETAILS"), wxPoint(72,208), wxSize(248,23), 0, wxDefaultValidator, _T("ID_TOGGLEBUTTON3"));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("HELLO ADMIN!!"), wxPoint(32,24), wxSize(160,40), wxST_NO_AUTORESIZE|wxALIGN_LEFT, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Label"), wxPoint(216,24), wxSize(47,48), wxST_NO_AUTORESIZE|wxALIGN_LEFT, _T("ID_STATICTEXT2"));
	wxFont StaticText2Font(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText2->SetFont(StaticText2Font);

	Connect(ID_TOGGLEBUTTON1,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&Admin2::OnToggleButton1Toggle);
	Connect(ID_TOGGLEBUTTON2,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&Admin2::OnToggleButton2Toggle);
	Connect(ID_TOGGLEBUTTON3,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&Admin2::OnToggleButton3Toggle);
	Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&Admin2::OnClose);
	//*)
	 con5 = mysql_init(0);
    con5 = mysql_real_connect(con5,"localhost","root","","bus system",0,NULL,0);
string co11="select uname from admin where stat='logged in'";
     const char* q39 = co11.c_str();
     qstate5 = mysql_query(con5,q39);

     res5 = mysql_store_result(con5);
     row5=mysql_fetch_row(res5);

     wxString mystring = wxString::FromUTF8(row5[0]);
     StaticText2->SetLabel(mystring);
}

Admin2::~Admin2()
{
	//(*Destroy(Admin2)
	//*)
	  mysql_close(con5);
}


void Admin2::OnClose(wxCloseEvent& event)
{
}

void Admin2::OnToggleButton1Toggle(wxCommandEvent& event)
{
    string dd="update admin set stat='logged out' where stat='logged in'";
      const char* q66 = dd.c_str();
         qstate55 = mysql_query(con5,q66);
    if(!qstate55){
             wxMessageBox(" logged out sucessfully","try again");
    Admin1 *bt=new Admin1(0);
    this->Hide();
    bt->Show();
}
}

void Admin2::OnToggleButton2Toggle(wxCommandEvent& event)
{
    adminadd2 *rt=new adminadd2(0);
    this->Hide();
    rt->Show();

}

void Admin2::OnToggleButton3Toggle(wxCommandEvent& event)
{
     Addadmin *aa=new Addadmin(0);
    this->Hide();
    aa->Show();
}
