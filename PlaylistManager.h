#pragma once
#pragma once
#include "DLL.h"
#include "Playlist.h"  
#include <fstream>
#include <iomanip>
#include<Windows.h>
#include<mmsystem.h>
#include<string>
#include"SurahPlayer.h"
# pragma comment (lib,"winmm.lib")
#include<iostream>
class PlaylistManager {
private:
    DLL<Playlist> playlists;
    SurahPlayer surahPlayer;
public:
    Playlist* findPlaylist(const std::string& name) {
        Node<Playlist>* current = playlists.getHead();
        while (current)
        {
            if (current->data.get_playlist_name() == name)
            {
                return &current->data;
            }
            current = current->next;
        }
        return nullptr;
    }

    void addPlaylist(const Playlist& playlist) {
        playlists.insert_at_end(playlist);
    }


    void playSurahFromPlaylist(Playlist* p) {
        if (findPlaylist(p->get_playlist_name()) && p->getSize() > 0) 
        {
            surahPlayer.playPlaylistWithControls(p);
        }
        
        else {
            cout << "\033[1;31mPlaylist is empty or invalid.\033[0m" << endl;
        }
    }


    void removePlaylist(const std::string& name) {
        Node<Playlist>* current = playlists.getHead();
        int position = 1;
        while (current) {
            if (current->data.get_playlist_name() == name) {
                playlists.delete_at_pos(position);
                std::cout << "Playlist '" << name << "' removed.\n";
                return;
            }
            current = current->next;
            position++;
        }
        std::cout << "Playlist '" << name << "' not found.\n";
    }

    void displayAllPlaylists() const {
        Node<Playlist>* current = playlists.getHead();
        int i = 1;
        while (current) {
            cout << i << ". " << current->data.get_playlist_name() << "\n";
            current = current->next;
            i++;
        }
    }



    void addSurahToPlaylist(const string& playlist_name) {

        if (findPlaylist(playlist_name)) {
            string surah_name, shiekh, path, surah_type;
            cout << "Enter Surah Name: ";
            cin.ignore();
            getline(cin, surah_name);
            cout << "Enter Path: ";
            cin.ignore();
            getline(cin, path);
            cout << "Enter Surah Type: ";
            getline(cin, surah_type);

            surah new_surah(surah_name, path, surah_type);

            findPlaylist(playlist_name)->add_Surah(new_surah);

            cout << "Surah added successfully to playlist '" << playlist_name << "'!\n";
        }
        else {
            cout << "Playlist not found!\n";
        }
    }

    void displayPlaylistheader(string n) const
    {
        cout << "\t\t";
        cout << n << "\n";

        cout << left;
        cout << setw(10) << "ID" << setw(20) << "Surah Name" << setw(15) << "Sheikh" << setw(25) << "Path" << setw(15) << "Surah Type" << endl;
        cout << string(80, '-') << endl;

    }
    void traverse_all_playlists_surahs() {
        Node<Playlist>* current = playlists.getHead();
        int i = 1;

        while (current) {
            cout << "Playlist " << i << ": " << current->data.get_playlist_name() << "\n";
            cout << "-----------------------------------\n";

            current->data.displayPlaylist();
            cout << "-----------------------------------\n";
            current = current->next;
            i++;
        }
    }

    void savePlaylistsToFile() {
        ofstream outFile("D:\\codes\\Audio_player\\files\\file.txt");
        if (outFile.is_open()) {
            Node<Playlist>* current = playlists.getHead();
            while (current) {
                outFile << current->data.get_playlist_name() << endl;
                current = current->next;
            }
            outFile.close();
            cout << "Playlists saved successfully!" << endl;
        }
        else {
            cout << "Failed to open the file for saving!" << endl;
        }
    }

    void loadPlaylistsFromFile() {
        ifstream inFile("D:\\codes\\Audio_player\\files\\file.txt");
        if (inFile.is_open()) {
            string playlistName;
            while (getline(inFile, playlistName)) {
                Playlist newPlaylist(playlistName);
                addPlaylist(newPlaylist);
            }
            inFile.close();
            cout << "Playlists loaded successfully!" << endl;
        }
        else {
            cout << "Failed to open the file for loading!" << endl;
        }
    }

    /*void displaySurahFromPlaylist(const std::string& playlistName, string s)
    {
        Node<Playlist>* current = playlists.getHead();

        while (current) {
            if (current->data.get_playlist_name() == playlistName) {
                if (current->data.find_surah(s))
                {
                    cout << "Playing: " << current->data.find_surah(s)->get_surah() << endl;
                    current->data.find_surah(s)->play_surah();
                }
                else
                {
                    cout << "No surah to play!" << endl;
                }
            }
            return;

            current = current->next;
            std::cout << "Playlist '" << playlistName << "' not found.\n";
        }
    }
    */

    void removeSurahFromPlaylist(const std::string& playlist_name, const std::string& surah_name)
    {

        Playlist* playlist = findPlaylist(playlist_name);
        if (playlist)
        {
            playlist->removeSurah(surah_name);
            std::cout << "Surah '" << surah_name << "' removed from playlist '" << playlist_name << "'!" << std::endl;
        }
        else
        {
            std::cout << "Playlist '" << playlist_name << "' not found!" << std::endl;
        }
    }

    void updateSurahOrderInPlaylist(const std::string& playlist_name, const std::string& surah_name, int new_position)

    {
        Playlist* playlist = findPlaylist(playlist_name);
        if (playlist)
        {
            playlist->updateSurahOrder(surah_name, new_position);
            std::cout << "Surah order updated successfully!" << std::endl;
        }
        else {
            std::cout << "Playlist '" << playlist_name << "' not found!" << std::endl;
        }
    }
};

