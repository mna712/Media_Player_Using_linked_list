#ifndef PLAYLIST_H
#define PLAYLIST_H
#include "suarh.h"
#include<string>
#include<Windows.h>
#include<mmsystem.h>
#include <iostream>
#include"SurahPlayer.h"
#include"playlist.h"
# pragma comment (lib,"winmm.lib")
using namespace std;
class Playlist
{
public:
    Playlist();
    Playlist(string n);
   string  get_playlist_name();
    void set_playlist_name(string n);  
    int getSize() const; 
    void add_Surah(surah& surah);
    void removeSurah(const string& surah_name);;
    surah* find_surah(std::string name);
    surah getSurahAt(int index) const;
  void displayPlaylist() const;
    void updateSurahOrder(const string& surah_name, int new_position);
    void clearPlaylist();

private:
    string playlist_name;
    DLL<surah>surahs;
   
};

#endif // PLAYLIST_H


