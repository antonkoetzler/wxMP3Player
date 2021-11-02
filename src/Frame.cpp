#include "Frame.h"

BEGIN_EVENT_TABLE(Frame, wxFrame)
	EVT_MENU(wxID_EXIT, MenuBar::Exit)
END_EVENT_TABLE()

Frame::Frame() : wxFrame(nullptr, wxID_ANY, "wxMP3Player", wxDefaultPosition, wxSize(800, 600))
{
	menubar = new MenuBar();
	SetMenuBar(menubar);

	controller = new wxBoxSizer(wxVERTICAL);

	songlist = new SongList(this);
	songlist->Append("Hello");

	controller->Add(songlist, 1, wxEXPAND);

	wxSize parentSize = this->GetSize();
	wxSize musiccontrolsSize = wxSize(parentSize.GetWidth(), 100);
	musiccontrols = new MusicControls(this, musiccontrolsSize);

	controller->Add(musiccontrols, 0, wxEXPAND);

	SetSizer(controller);
}

Frame::~Frame() { this->Destroy(); }

