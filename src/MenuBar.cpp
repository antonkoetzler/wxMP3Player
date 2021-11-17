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

	edit = new wxMenu();

	addsongs = new wxMenuItem(
		nullptr,
		ADDSONGS,
		"Add songs to your directory\tCtrl+A",
		"Add songs",
		wxITEM_NORMAL,
		nullptr
	);

	refresh = new wxMenuItem(
		nullptr,
		REFRESHSONGS,
		"Refresh's the directory and media\tCtrl+R",
		wxEmptyString,
		wxITEM_NORMAL,
		nullptr
	);

	edit->Append(addsongs);
	edit->Append(refresh);
	this->Append(edit, "Edit");
}

void MenuBar::Exit(wxCommandEvent& evt) { Close(true); }

void MenuBar::AddSongs(wxCommandEvent& evt)
{
	std::cout << "Is it working" << std::endl;
	wxDialog* dialogWindow = new wxDialog(
		nullptr,
		wxID_ANY,
		"Adding songs to listen to",
		wxDefaultPosition,
		wxDefaultSize
	);
	wxStaticText* message = new wxStaticText(
		dialogWindow,
		wxID_ANY,
		"Go to the project's root directory, then add songs in ./songs/ :)",
		wxDefaultPosition,
		wxDefaultSize
	);
	dialogWindow->Show(true);
}
