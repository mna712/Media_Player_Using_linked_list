
#include"DLL.h"

#include <iostream>
#include "suarh.h"
#include"playlist.h"
#include <fstream>
#include <iomanip>
#include"SurahPlayer.h"
#include"PlaylistManager.h"

# pragma comment (lib,"winmm.lib")

using namespace std;

void displayMenu() {

    cout << "\t\t\t\t\t\t+=============================================================+" << endl;
    cout << "\t\t\t\t\t\t|                Quraan Playlist Manager Menu                 |" << endl;
    cout << "\t\t\t\t\t\t+=============================================================+" << endl;
    cout << "\t\t\t\t\t\t| 1.Add a new playlist                                        |" << endl;
    cout << "\t\t\t\t\t\t| 2.Add Surah to an exisiting playlist                        |" << endl;
    cout << "\t\t\t\t\t\t| 3. Remove Surah from an exisiting playlist                  |" << endl;
    cout << "\t\t\t\t\t\t| 4.Update the order of an existing order                     |" << endl;
    cout << "\t\t\t\t\t\t| 5.Display all current playlists                             |" << endl;
    cout << "\t\t\t\t\t\t| 6.Display all playlists Surah                               |" << endl;
    cout << "\t\t\t\t\t\t| 7.Display Surah in a specific playlist                      |" << endl;
    cout << "\t\t\t\t\t\t| 8.Display Surah from a specific playlist                    |" << endl;
    cout << "\t\t\t\t\t\t|    Use left arrow (<-) to play the previous surah           |" << endl;
    cout << "\t\t\t\t\t\t|    Use right arrow (->) to play the next surah              |" << endl;
    cout << "\t\t\t\t\t\t|    Use up arrow (^) to pause the current surah              |" << endl;
    cout << "\t\t\t\t\t\t|    Use down arrow (v) to resume the current surah           |" << endl;
    cout << "\t\t\t\t\t\t|    Press q to exit current playlist & return back to menu   |" << endl;
    cout << "\t\t\t\t\t\t| 9.Save an existing playlist to a file                       |" << endl;
    cout << "\t\t\t\t\t\t| 10. Load an existing playlist from a file                   |" << endl;
    cout << "\t\t\t\t\t\t| 11. Remove an existing playlist                             |" << endl;
    cout << "\t\t\t\t\t\t| 12. Exit                                                    |" << endl;
    cout << "\t\t\t\t\t\t+=============================================================+" << endl;
    cout << endl;

}
void playSurahFromPlaylist(PlaylistManager& manager) {
    cout << "\033[1;33m|--------------------------------------------|\033[0m" << endl;
    cout << "\033[1;33m| 8. Play Surah from specific playlist       |\033[0m" << endl;
    cout << "\033[1;33m|  Use left arrow (<-) to play the previous  |\033[0m" << endl;
    cout << "\033[1;33m|  Use right arrow (->) to play the next     |\033[0m" << endl;
    cout << "\033[1;33m|  Use up arrow (^) to pause the current     |\033[0m" << endl;
    cout << "\033[1;33m|  Use down arrow (v) to resume the curre    |\033[0m" << endl;
    cout << "\033[1;33m|  Press q to exit current playlist          |\033[0m" << endl;
    cout << "\033[1;33m|  & return back to menu                     |\033[0m" << endl;
    cout << "\033[1;33m|--------------------------------------------|\033[0m" << endl;
    manager.displayAllPlaylists();
    string playlistName;
    cout << "Enter the playlist name to play surahs: ";
    cin.ignore();
    getline(cin, playlistName);
   
    if (manager.findPlaylist(playlistName)) {
        manager.playSurahFromPlaylist(manager.findPlaylist(playlistName));
    }
    else {
        cout << "\033[1;31mPlaylist not found!\033[0m" << endl;
    }
}

string surah_name;
string playlist_nam;
Playlist* playlist;
int main()
{
    bool m;
    string s;
    int i = 0;
    int choice;
    bool r = true;
    PlaylistManager manager;

    while (r)
    {
        displayMenu();
        bool b = true;
        cout << "Enter your choice: ";
        cin >> choice;
        string x;
        Playlist newPlaylist(" ");
        switch (choice)
        {
        case 1:
            cout << "Enter playlist name: ";
            cin.ignore();

            cin >> playlist_nam;

            if ((manager.findPlaylist(playlist_nam)))
            {
                cout << "This playlist is already exists !!....";
                break;
            }
            else
            {
                newPlaylist.set_playlist_name(playlist_nam);
                manager.addPlaylist(newPlaylist);
                cout << "Added Sucesfully .... " << endl;
                break;

        case 2:
            cout << "Enter playlist name to add surah to: ";
            cin.ignore();
            cin >> playlist_nam;
            while (b)
            {

                if (manager.findPlaylist(playlist_nam))
                {
                    string surah_name, shiekh, path, surah_type;
                    cout << "Enter Surah name: ";
                    cin.ignore();
                    getline(cin, surah_name);
                    cout << "Enter Sheikh: ";
                    cin.ignore();
                    getline(cin, shiekh);
                    cout << "Enter Path: ";
                    cin.ignore();
                    getline(cin, path);
                    cout << "Enter Surah Type: ";
                    cin.ignore();
                    getline(cin, surah_type);
                    surah newSurah(surah_name, path, surah_type);
                    manager.findPlaylist(playlist_nam)->add_Surah(newSurah);
                    cout << "new Surah has been added succesfully ^-^ \n";
                }
                else
                {
                    cout << "Playlist not found!\n";
                }
                cout << "Add another surah to the current playlist? (y/n)  ";
                char c;
                cin >> c;
                if (c == 'y')
                {
                    b = true;
                }
                else
                    b = false;

            }
            break;
        case 3:
        {
            string surah_name;
            cout << "Enter playlist name to remove surah from: ";
            cin.ignore();
            getline(cin, playlist_nam);
            cout << "Enter Surah name to remove: ";
            getline(cin, surah_name);
            manager.removeSurahFromPlaylist(playlist_nam, surah_name);
            break;
        }


        case 4:
        {
            string surah_name_update;
            cout << "Enter playlist name to update surah order: ";
            cin.ignore();
            getline(cin, playlist_nam);
            cout << "Enter Surah name to update: ";
            getline(cin, surah_name_update);
            cout << "Enter new position for the Surah: ";
            int new_position;
            cin >> new_position;
            manager.updateSurahOrderInPlaylist(playlist_nam, surah_name_update, new_position);
            break;
        }


        case 5:

            manager.displayAllPlaylists();
            break;

        case 6:

            manager.traverse_all_playlists_surahs();
            break;

        case 7:
        {

            cout << "Enter playlist name:  ";
            cin.ignore();
            getline(cin,playlist_nam);
            cout << "Enter surah name:  ";
            cin.ignore();
            getline(cin, surah_name);
            playSurahFromPlaylist(manager);
            break;
        }

        case 8:
        playSurahFromPlaylist(manager);
            break;
        case 9:
            manager.savePlaylistsToFile();
            cout << "Saving playlist to a file..." << endl;
            break;

        case 10:
            manager.loadPlaylistsFromFile();
            cout << "Loading playlist from a file..." << endl;
            break;

        case 11:
        {
            cout << "Enter playlist name: ";
            cin.ignore();
            getline(cin, playlist_nam);
            manager.removePlaylist(playlist_nam);
            cout << "Removing an existing playlist..." << endl;
            break;
        }

        case 12:
            cout << "Exiting program..." << endl;
            r = false;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
            cout << endl;
            }
        }
    }
    return 0;
}