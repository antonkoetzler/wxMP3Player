#include "Frame.h"

BEGIN_EVENT_TABLE(Frame, wxFrame)
	// Menubar events
	EVT_MENU(wxID_EXIT, MenuBar::Exit)

	// SongList events
	EVT_LISTBOX_DCLICK(SONGLIST, Frame::foo)
END_EVENT_TABLE()

Frame::Frame() : wxFrame(nullptr, wxID_ANY, "wxMP3Player", wxDefaultPosition, wxSize(800, 600))
{
	menubar = new MenuBar();
	// Setting the menubar
	SetMenuBar(menubar);



	// Listing the user's music directory
	songs = new SongList(this);
}

Frame::~Frame() { this->Destroy(); }

void Frame::foo(wxCommandEvent& evt)
{
	std::cout << evt.GetString() << std::endl;
}

