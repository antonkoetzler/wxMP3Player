#pragma once

#include <wx/wx.h>

enum { ADDSONGS, REFRESHSONGS };

class MenuBar : public wxMenuBar
{
public:
	MenuBar();
	void Exit(wxCommandEvent&);
	void AddSongs(wxCommandEvent&);

private:
	wxMenu* file;
		wxMenuItem* exit;
	
	wxMenu* edit;
		wxMenuItem* addsongs;
		wxMenuItem* refresh;
};
