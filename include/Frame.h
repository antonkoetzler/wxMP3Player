#pragma once

#include <wx/wx.h>

class Frame : public wxFrame
{
	public:
		Frame();
		~Frame();

		// Event functions
		void Exit(wxCommandEvent&);

private:
	wxDECLARE_EVENT_TABLE();

	// Menubar
	wxMenuBar* menubar;
		wxMenu* file;
			wxMenuItem* exit;
};

