#include "UpdateGauge.h"

UpdateGauge::UpdateGauge(wxMediaCtrl* mediaPlayerArg, wxSlider* musicGaugeArg) : wxTimer()
{
	mediaPlayer = mediaPlayerArg;
	musicGauge = musicGaugeArg;
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
}
