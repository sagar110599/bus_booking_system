#ifndef ADMIN2_H
#define ADMIN2_H

//(*Headers(Admin2)
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/tglbtn.h>
//*)

class Admin2: public wxFrame
{
	public:

		Admin2(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~Admin2();

		//(*Declarations(Admin2)
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxToggleButton* ToggleButton1;
		wxToggleButton* ToggleButton2;
		wxToggleButton* ToggleButton3;
		//*)

	protected:

		//(*Identifiers(Admin2)
		static const long ID_TOGGLEBUTTON1;
		static const long ID_TOGGLEBUTTON2;
		static const long ID_TOGGLEBUTTON3;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		//*)

	private:

		//(*Handlers(Admin2)
		void OnClose(wxCloseEvent& event);
		void OnToggleButton1Toggle(wxCommandEvent& event);
		void OnToggleButton2Toggle(wxCommandEvent& event);
		void OnToggleButton3Toggle(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
