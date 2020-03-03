#ifndef USER_RESEVE_H
#define USER_RESEVE_H

//(*Headers(user_reseve)
#include <wx/choice.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>
#include <wx/frame.h>
#include <wx/grid.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/tglbtn.h>
//*)

class user_reseve: public wxFrame
{
	public:

		user_reseve(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~user_reseve();

		//(*Declarations(user_reseve)
		wxChoice* Choice1;
		wxChoice* Choice2;
		wxDatePickerCtrl* DatePickerCtrl1;
		wxGrid* Grid1;
		wxGrid* Grid2;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxStaticText* StaticText4;
		wxStaticText* StaticText5;
		wxStaticText* StaticText6;
		wxStaticText* StaticText7;
		wxStaticText* StaticText8;
		wxTextCtrl* TextCtrl1;
		wxToggleButton* ToggleButton1;
		wxToggleButton* ToggleButton2;
		wxToggleButton* ToggleButton3;
		wxToggleButton* ToggleButton4;
		//*)

	protected:

		//(*Identifiers(user_reseve)
		static const long ID_TOGGLEBUTTON1;
		static const long ID_STATICTEXT1;
		static const long ID_CHOICE1;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		static const long ID_CHOICE2;
		static const long ID_GRID1;
		static const long ID_TOGGLEBUTTON2;
		static const long ID_STATICTEXT4;
		static const long ID_GRID2;
		static const long ID_TOGGLEBUTTON3;
		static const long ID_STATICTEXT5;
		static const long ID_TEXTCTRL1;
		static const long ID_DATEPICKERCTRL1;
		static const long ID_STATICTEXT6;
		static const long ID_STATICTEXT7;
		static const long ID_STATICTEXT8;
		static const long ID_TOGGLEBUTTON4;
		//*)

	private:

		//(*Handlers(user_reseve)
		void OnClose(wxCloseEvent& event);
		void OnToggleButton1Toggle(wxCommandEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		void OnGrid1CellLeftClick(wxGridEvent& event);
		void OnChoice1Select(wxCommandEvent& event);
		void OnToggleButton2Toggle(wxCommandEvent& event);
		void OnChoice2Select(wxCommandEvent& event);
		void OnToggleButton3Toggle(wxCommandEvent& event);
		void OnDatePickerCtrl1Changed(wxDateEvent& event);
		void OnTextCtrl1Text(wxCommandEvent& event);
		void OnToggleButton4Toggle(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
