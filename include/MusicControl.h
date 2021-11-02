#pragma once

#include <wx/wx.h>

enum { MUSICCONTROL = wxID_HIGHEST + 1 };

class MusicControl : public wxPanel
{
public:
	MusicControl(wxWindow*);
};

