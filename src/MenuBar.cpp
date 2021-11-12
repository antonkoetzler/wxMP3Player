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

	add = new wxMenu();

	yt2mp3 = new wxMenuItem(
		nullptr,
		YT2MP3,
		"Add song from youtube\tCtrl+Y",
		"Youtube to mp3's a song and adds to your library",
		wxITEM_NORMAL,
		nullptr
	);
	add->Append(yt2mp3);
	this->Append(add, "Add");
}

void MenuBar::Exit(wxCommandEvent& evt) { Close(true); }

void MenuBar::Youtube2MP3(wxCommandEvent& evt)
{
	// ./youtube-dl -x --audio-format=mp3 -o <directory> <url>
	wxExecute("echo hi");

	/*
	wxFrame* newWindow = new wxFrame(
		nullptr,
		wxID_ANY,
		"Paste your YT video to convert to MP3",
		wxDefaultPosition,
		wxDefaultSize
	);

	wxTextCtrl* link = new wxTextCtrl(
		newWindow,
		wxID_ANY,
		wxEmptyString,
		wxDefaultPosition,
		wxSize(300, 20)
	);

	wxBoxSizer* container = new wxBoxSizer(wxHORIZONTAL);
	container->Add(link, 1, wxEXPAND);
	container->Add(
		new wxButton(newWindow, CONVERT2MP3, "Click to Convert", wxDefaultPosition, wxDefaultSize),
		0,
		wxEXPAND
	);

	newWindow->SetSizerAndFit(container);

	newWindow->Show(true);
	*/
}
