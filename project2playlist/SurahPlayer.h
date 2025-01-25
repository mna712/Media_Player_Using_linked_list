#pragma once
#ifndef SURAHPPLAYER_H
#define SURAHPPLAYER_H
#include <string>
#include <irrKlang.h>
#include "Playlist.h"
using namespace irrklang;
using namespace std;

class SurahPlayer {
private:
    ISoundEngine* engine;
    int currentSurahIndex;
    Playlist* currentPlaylist;

public:
    SurahPlayer();
    ~SurahPlayer();
    void playSurah(const string& surahFilePath);
    void stopSurah();
    void pauseSurah();
    void resumeSurah();
    void playPlaylistWithControls(Playlist* p);
    void changeSurah(int direction);
    void updateSurahIndex(int index);
};


#endif