#include "MenuBar.h"

MenuBar::MenuBar() : wxMenuBar()
{
	file = new wxMenu();
	
	exit = new wxMenuItem(
		nullptr,
		wxID_EXIT,
		"Exit\tCtrl+Q",
		wxEmptyString,
		wxITEM_NORMAL,
		nullptr
	);

	file->Append(exit);
	this->Append(file, "File");
}

void MenuBar::Exit(wxCommandEvent& evt) { Close(true); }

