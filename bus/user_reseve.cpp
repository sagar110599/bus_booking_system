#include "user_reseve.h"
#include "user1.h"
#include <wx/msgdlg.h>
#include <winsock.h>
#include<mysql.h>

using namespace std;
    MYSQL* con3;
MYSQL_ROW row3,ro,row34,row12;
MYSQL_RES *res33,*re,*res34,*res12;
    int qstate33,qstate34,qstate20,qstate35,qstate36,qstate39,qstate37;
    int n,quant;
    string date11,time1,s1,d1,de,cap;


//(*InternalHeaders(user_reseve)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(user_reseve)
const long user_reseve::ID_TOGGLEBUTTON1 = wxNewId();
const long user_reseve::ID_STATICTEXT1 = wxNewId();
const long user_reseve::ID_CHOICE1 = wxNewId();
const long user_reseve::ID_STATICTEXT2 = wxNewId();
const long user_reseve::ID_STATICTEXT3 = wxNewId();
const long user_reseve::ID_CHOICE2 = wxNewId();
const long user_reseve::ID_GRID1 = wxNewId();
const long user_reseve::ID_TOGGLEBUTTON2 = wxNewId();
const long user_reseve::ID_STATICTEXT4 = wxNewId();
const long user_reseve::ID_GRID2 = wxNewId();
const long user_reseve::ID_TOGGLEBUTTON3 = wxNewId();
const long user_reseve::ID_STATICTEXT5 = wxNewId();
const long user_reseve::ID_TEXTCTRL1 = wxNewId();
const long user_reseve::ID_DATEPICKERCTRL1 = wxNewId();
const long user_reseve::ID_STATICTEXT6 = wxNewId();
const long user_reseve::ID_STATICTEXT7 = wxNewId();
const long user_reseve::ID_STATICTEXT8 = wxNewId();
const long user_reseve::ID_TOGGLEBUTTON4 = wxNewId();
//*)

BEGIN_EVENT_TABLE(user_reseve,wxFrame)
	//(*EventTable(user_reseve)
	//*)
END_EVENT_TABLE()

user_reseve::user_reseve(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(user_reseve)
	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(906,560));
	ToggleButton1 = new wxToggleButton(this, ID_TOGGLEBUTTON1, _("LOG OUT"), wxPoint(792,16), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TOGGLEBUTTON1"));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("WELCOME BOOK YOUR RIDE "), wxPoint(168,24), wxSize(336,24), wxST_NO_AUTORESIZE|wxALIGN_LEFT, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(16,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	Choice1 = new wxChoice(this, ID_CHOICE1, wxPoint(152,72), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("ENTER SOURCE"), wxPoint(16,88), wxSize(80,13), 0, _T("ID_STATICTEXT2"));
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("ENTER DESTINATION"), wxPoint(16,144), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	Choice2 = new wxChoice(this, ID_CHOICE2, wxPoint(152,136), wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
	Grid1 = new wxGrid(this, ID_GRID1, wxPoint(0,176), wxSize(424,184), 0, _T("ID_GRID1"));
	Grid1->CreateGrid(8,6);
	Grid1->EnableEditing(true);
	Grid1->EnableGridLines(true);
	Grid1->SetColLabelValue(0, _("source"));
	Grid1->SetColLabelValue(1, _("destination"));
	Grid1->SetColLabelValue(2, _("departure"));
	Grid1->SetColLabelValue(3, _("cost"));
	Grid1->SetColLabelValue(4, _("capacity"));
	Grid1->SetColLabelValue(5, _("seat_avail"));
	Grid1->SetDefaultCellFont( Grid1->GetFont() );
	Grid1->SetDefaultCellTextColour( Grid1->GetForegroundColour() );
	ToggleButton2 = new wxToggleButton(this, ID_TOGGLEBUTTON2, _("CLICK TO SEARCH"), wxPoint(304,104), wxSize(179,23), 0, wxDefaultValidator, _T("ID_TOGGLEBUTTON2"));
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("HELLO!!!"), wxPoint(56,24), wxSize(88,24), wxST_NO_AUTORESIZE|wxALIGN_LEFT, _T("ID_STATICTEXT4"));
	wxFont StaticText4Font(16,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText4->SetFont(StaticText4Font);
	Grid2 = new wxGrid(this, ID_GRID2, wxPoint(480,176), wxSize(424,192), 0, _T("ID_GRID2"));
	Grid2->CreateGrid(8,6);
	Grid2->EnableEditing(true);
	Grid2->EnableGridLines(true);
	Grid2->SetRowLabelSize(10);
	Grid2->SetColLabelValue(0, _("book_time"));
	Grid2->SetColLabelValue(1, _("ride_date"));
	Grid2->SetColLabelValue(2, _("source"));
	Grid2->SetColLabelValue(3, _("destination"));
	Grid2->SetColLabelValue(4, _("depart_time"));
	Grid2->SetColLabelValue(5, _("price"));
	Grid2->SetDefaultCellFont( Grid2->GetFont() );
	Grid2->SetDefaultCellTextColour( Grid2->GetForegroundColour() );
	ToggleButton3 = new wxToggleButton(this, ID_TOGGLEBUTTON3, _("YOUR PREVIOUS BOOKING"), wxPoint(616,96), wxSize(248,23), 0, wxDefaultValidator, _T("ID_TOGGLEBUTTON3"));
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _(" ENTER THE NO OF TICKETS"), wxPoint(24,456), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("Text"), wxPoint(168,448), wxSize(152,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	DatePickerCtrl1 = new wxDatePickerCtrl(this, ID_DATEPICKERCTRL1, wxDefaultDateTime, wxPoint(168,392), wxSize(152,21), wxDP_DEFAULT|wxDP_SHOWCENTURY, wxDefaultValidator, _T("ID_DATEPICKERCTRL1"));
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("PICK YOUR DATE"), wxPoint(72,400), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("YOUR TOTAL AMOUNT"), wxPoint(40,504), wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	StaticText8 = new wxStaticText(this, ID_STATICTEXT8, _("Label"), wxPoint(200,504), wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	ToggleButton4 = new wxToggleButton(this, ID_TOGGLEBUTTON4, _("Label"), wxPoint(304,504), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TOGGLEBUTTON4"));

	Connect(ID_TOGGLEBUTTON1,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&user_reseve::OnToggleButton1Toggle);
	Connect(ID_CHOICE1,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&user_reseve::OnChoice1Select);
	Connect(ID_CHOICE2,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&user_reseve::OnChoice2Select);
	Connect(ID_GRID1,wxEVT_GRID_CELL_LEFT_CLICK,(wxObjectEventFunction)&user_reseve::OnGrid1CellLeftClick);
	Connect(ID_TOGGLEBUTTON2,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&user_reseve::OnToggleButton2Toggle);
	Connect(ID_TOGGLEBUTTON3,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&user_reseve::OnToggleButton3Toggle);
	Connect(ID_DATEPICKERCTRL1,wxEVT_DATE_CHANGED,(wxObjectEventFunction)&user_reseve::OnDatePickerCtrl1Changed);
	Connect(ID_TOGGLEBUTTON4,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&user_reseve::OnToggleButton4Toggle);
	Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&user_reseve::OnClose);
	//*)
	con3 = mysql_init(0);
    con3 = mysql_real_connect(con3,"localhost","root","","bus system",0,NULL,0);
    string co="select source,destination from bus_details";
     const char* q3 = co.c_str();
     qstate33 = mysql_query(con3,q3);
     if(!qstate33)
     {
           res33 = mysql_store_result(con3);
            while(row3=mysql_fetch_row(res33))
            {
                Choice1->Append(row3[0]);
                Choice2->Append(row3[1]);

            }

     }
     string co1="select cname from customer where stat='logged in'";
     const char* q35 = co1.c_str();
     qstate35 = mysql_query(con3,q35);

     res34 = mysql_store_result(con3);
     row34=mysql_fetch_row(res34);

     wxString mystring = wxString::FromUTF8(row34[0]);
     StaticText1->SetLabel(mystring);

}

user_reseve::~user_reseve()
{
	//(*Destroy(user_reseve)
	//*)
	mysql_close(con3);
}
string source,destination;

void user_reseve::OnClose(wxCloseEvent& event)
{

}

void user_reseve::OnToggleButton1Toggle(wxCommandEvent& event)
{
    wxString mystring8 = wxString::FromUTF8(row34[0]);
 string qu20="update customer set stat='logged out' where stat='logged in'";
      const char* q20 = qu20.c_str();
         qstate20 = mysql_query(con3,q20);
    if(!qstate20){
             wxMessageBox(" customer "+mystring8.ToStdString()+" logged out sucessfully","info");
    user1 *uu=new user1(0);
    this->Hide();
    uu->Show();
}
    }
void user_reseve::OnButton1Click(wxCommandEvent& event)
{

}

void user_reseve::OnGrid1CellLeftClick(wxGridEvent& event)
{


      int rowindex =event.GetRow();
       s1=(Grid1->GetCellValue(rowindex,0)).ToStdString();
       d1=(Grid1->GetCellValue(rowindex,1)).ToStdString();
       de=(Grid1->GetCellValue(rowindex,2)).ToStdString();
       time1=(Grid1->GetCellValue(rowindex,3)).ToStdString();
       cap=(Grid1->GetCellValue(rowindex,5)).ToStdString();

        n = stoi(cap);





}



void user_reseve::OnToggleButton2Toggle(wxCommandEvent& event)
{
    int row=0,col=0;
   string cs="select * from bus_details where source='"+source+"' and destination='"+destination+"'";
     const char* q34 = cs.c_str();
      qstate34 = mysql_query(con3,q34);
      if(!qstate34)
     {
          re = mysql_store_result(con3);
            while(ro=mysql_fetch_row(re))
            {
               Grid1->SetCellValue(row,col,ro[0]);
               Grid1->SetCellValue(row,++col,ro[1]);
               Grid1->SetCellValue(row,++col,ro[2]);
               Grid1->SetCellValue(row,++col,ro[3]);
               Grid1->SetCellValue(row,++col,ro[4]);
               Grid1->SetCellValue(row,++col,ro[5]);
               row++;
               col=0;

            }





     }
}

void user_reseve::OnChoice2Select(wxCommandEvent& event)
{
    destination = event.GetString();
}
void user_reseve::OnChoice1Select(wxCommandEvent& event)
{
    source=event.GetString();
}


void user_reseve::OnToggleButton3Toggle(wxCommandEvent& event)
{
     int row=0,col=0;
     wxString mystring2 = wxString::FromUTF8(row34[0]);
   string css="select book_time,ride_date,source,destination,depart_time,price from booking where cname='"+mystring2.ToStdString()+"'";
     const char* q59 = css.c_str();
      qstate39 = mysql_query(con3,q59);
      if(!qstate39)
     {
          res12 = mysql_store_result(con3);
            while(row12=mysql_fetch_row(res12))
            {
               Grid2->SetCellValue(row,col,row12[0]);
               Grid2->SetCellValue(row,++col,row12[1]);
               Grid2->SetCellValue(row,++col,row12[2]);
               Grid2->SetCellValue(row,++col,row12[3]);
               Grid2->SetCellValue(row,++col,row12[4]);
                Grid2->SetCellValue(row,++col,row12[5]);
               row++;
               col=0;

            }





     }
}


void user_reseve::OnDatePickerCtrl1Changed(wxDateEvent& event)
{

}



void user_reseve::OnToggleButton4Toggle(wxCommandEvent& event)
{
     date11=((DatePickerCtrl1->GetValue()).FormatISODate()).ToStdString();
    wxString mystring1 = wxString::FromUTF8(row34[0]);
     string l=(TextCtrl1->GetValue()).ToStdString();
    quant=stoi(l);
    int total=quant*stoi(time1);
    StaticText8->SetLabel(to_string(total));
     wxMessageDialog *dial = new wxMessageDialog(NULL,
      wxT("confirm booking?"), wxT("CONFIRMATION"),
      wxYES_NO | wxNO_DEFAULT | wxICON_QUESTION);

  if ( dial->ShowModal() == wxID_YES )
  {
      n--;
      string co7="update bus_details set seat_taken='"+to_string(n)+"' where source='"+s1+"' and destination='"+d1+"'; ";
      const char* q37 = co7.c_str();
     qstate37 = mysql_query(con3,q37);
string co3="insert into booking(source,ride_date,destination,depart_time,price,cname,no_of_tickets) values ('"+s1+"','"+date11+"','"+d1+"','"+de+"','"+to_string(total)+"','"+mystring1.ToStdString()+"','"+l+"');";

       const char* q36 = co3.c_str();
     qstate36 = mysql_query(con3,q36);
     if(!qstate36)
       wxMessageBox("thank u for booking","info");
  }
}
