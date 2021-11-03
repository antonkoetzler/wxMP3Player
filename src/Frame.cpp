#include "Frame.h"

BEGIN_EVENT_TABLE(Frame, wxFrame)
	// MenuBar events
	EVT_MENU(wxID_EXIT, MenuBar::Exit)

	// SongList events
	EVT_LISTBOX_DCLICK(SONGLIST, Frame::EnableMusicControls)
END_EVENT_TABLE()

Frame::Frame() : wxFrame(nullptr, wxID_ANY, "wxMP3Player", wxDefaultPosition, wxSize(800, 600))
{
	// Menubar
	menubar = new MenuBar();
	SetMenuBar(menubar);

	// Main sizer for songlist, music controls, and youtube-dl
	controller = new wxBoxSizer(wxVERTICAL);

	// SongList
	songlist = new SongList(this);
	songlist->Append("Hello");

	controller->Add(songlist, 1, wxEXPAND);

	SetSizer(controller);
}

Frame::~Frame() { this->Destroy(); }

void Frame::EnableMusicControls(wxCommandEvent& evt)
{
	wxSize parentSize = this->GetSize();
	wxSize musiccontrolsSize = wxSize(parentSize.GetWidth(), 100);
	musiccontrols = new MusicControls(this, musiccontrolsSize);

	controller->Add(musiccontrols, 0, wxEXPAND);

	controller->Layout();
}

