#include "Menubar.h"
#include "Frame.h"

Menubar::Menubar() : wxMenuBar()
{
	file = new wxMenu();

	exit = new wxMenuItem(
		nullptr,
		wxID_EXIT,
		"Exit\tCtrl+Q",
		"",
		wxITEM_NORMAL,
		nullptr
	);
	file->Append(exit);

	this->Append(file, "File");
}

void Menubar::Exit(wxCommandEvent& evt) { Close(true); }
