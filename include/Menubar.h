#pragma once

#include <wx/wx.h>

class Menubar : public wxMenuBar
{
public:
	Menubar();

	void Exit(wxCommandEvent&);

private:
	wxMenu* file;
		wxMenuItem* exit;
};
