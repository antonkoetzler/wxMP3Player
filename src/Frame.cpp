#include "Frame.h"

BEGIN_EVENT_TABLE(Frame, wxFrame)
	EVT_MENU(wxID_EXIT, Frame::Exit)
END_EVENT_TABLE()

Frame::Frame() : wxFrame(nullptr, wxID_ANY, "wxMP3Player", wxDefaultPosition, wxSize(800, 600))
{
	// File
	file = new wxMenu();

	// File: Exit
	exit = new wxMenuItem(
		nullptr,
		wxID_EXIT,
		"Exit\tCtrl+Q",
		"",
		wxITEM_NORMAL,
		nullptr
	);
	file->Append(exit);

	// Actual menubar configuration
	menubar = new wxMenuBar();
	menubar->Append(file, "File");

	// Setting the menubar
	SetMenuBar(menubar);



	// Listing the user's music directory
	songs = new SongList(this, wxID_ANY);
}

Frame::~Frame() { this->Destroy(); }

void Frame::Exit(wxCommandEvent& evt) { Close(true); }

