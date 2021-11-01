#include "Frame.h"

BEGIN_EVENT_TABLE(Frame, wxFrame)
	EVT_MENU(wxID_EXIT, MenuBar::Exit)
END_EVENT_TABLE()

Frame::Frame() : wxFrame(nullptr, wxID_ANY, "wxMP3Player", wxDefaultPosition, wxSize(800, 600))
{
	menubar = new MenuBar();
	// Setting the menubar
	SetMenuBar(menubar);



	// Listing the user's music directory
	songs = new SongList(this, wxID_ANY);
}

Frame::~Frame() { this->Destroy(); }
