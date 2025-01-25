#include "SurahPlayer.h"
#include <iostream>
#include <conio.h>

SurahPlayer::SurahPlayer() {
    engine = createIrrKlangDevice();
    currentSurahIndex = 0;
    currentPlaylist = nullptr;
}
SurahPlayer::~SurahPlayer() {
    if (engine) {
        engine->drop();
    }
}
void SurahPlayer::playSurah(const string& surahFilePath) {
    if (engine) {
        engine->play2D(surahFilePath.c_str(), true);
    }
    else {
        cout << "Error initializing sound engine!" << endl;
    }
}
void SurahPlayer::stopSurah() {
    if (engine) {
        engine->stopAllSounds();
    }
}
void SurahPlayer::pauseSurah() {
    if (engine) {
        engine->setAllSoundsPaused(true);
    }
}
void SurahPlayer::resumeSurah() {
    if (engine) {
        engine->setAllSoundsPaused(false);
    }
}
void SurahPlayer::playPlaylistWithControls(Playlist* playlist) {
    currentPlaylist = playlist;
    currentSurahIndex = 0;

    if (currentPlaylist && currentPlaylist->getSize() > 0) {
        playSurah(currentPlaylist->getSurahAt(currentSurahIndex).get_path());
    }

    while (true) {
        if (_kbhit()) {
            int input = _getch();

            if (input == 'q') {
                stopSurah();
                cout << "\033[1;32mExited playlist playback.\033[0m" << endl;
                break;
            }
            else if (input == 75) {
                changeSurah(-1);
            }
            else if (input == 77) {
                changeSurah(1);
            }
            else if (input == 72) { 
                pauseSurah();
            }
            else if (input == 80) { 
                resumeSurah();
            }

        }
    }
}
void SurahPlayer::changeSurah(int direction) {
    int newSurahIndex = currentSurahIndex + direction;

    if (newSurahIndex >= 0 && newSurahIndex < currentPlaylist->getSize()) {
        currentSurahIndex = newSurahIndex;
        stopSurah();
        playSurah(currentPlaylist->getSurahAt(currentSurahIndex).get_path());
    }
}
void SurahPlayer::updateSurahIndex(int index) {
    currentSurahIndex = index;
}
