#include "UpdateGauge.h"

UpdateGauge::UpdateGauge(wxMediaCtrl* mediaPlayerArg, wxSlider* musicGaugeArg, SongList* playlistArg) : wxTimer()
{
	mediaPlayer = mediaPlayerArg;
	musicGauge = musicGaugeArg;
	playlist = playlistArg;
	Start(500);
}

void UpdateGauge::Notify()
{
	// Setting the duration of the song
	wxLongLong songLength = mediaPlayer->Length();
	int songLengthSeconds = (int) (songLength / 1000).GetValue();
	musicGauge->SetRange(0, songLengthSeconds);

	// Setting where the slider should be in the song
	wxLongLong songAt = mediaPlayer->Tell();
	int songAtSeconds = (int) (songAt / 1000).GetValue();
	musicGauge->SetValue(songAtSeconds);

	if (musicGauge->GetValue() == musicGauge->GetMax())
	{
		int nextSongIndex =  playlist->GetSelection() + 1;

		// Checking to see if we're currently on the last song of the playlist
		if (nextSongIndex > (playlist->GetCount() - 1))
			nextSongIndex = 0;

		// Loading the next song
		wxString songName = playlist->GetString(nextSongIndex);
		wxString songDirectory = wxGetCwd() + "/../songs/" + songName;

		mediaPlayer->Load(songDirectory);
		mediaPlayer->Play();

		playlist->SetSelection(nextSongIndex);
	}
}
