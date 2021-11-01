#pragma once

#include <wx/wx.h>

class MenuBar : public wxMenuBar
{
public:
	MenuBar();

	void Exit(wxCommandEvent&);

private:
	wxMenu* file;
		wxMenuItem* exit;
};
