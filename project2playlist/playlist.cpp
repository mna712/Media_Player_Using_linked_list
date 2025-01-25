#include "playlist.h"
#include<string>
#include"DLL.h"
#include"SurahPlayer.h"
#include <iomanip>
#include "suarh.h"
SurahPlayer player;
Playlist::Playlist()
{

}
Playlist::Playlist(string n)
{
    playlist_name = n;
}
string Playlist::get_playlist_name()
{
    return playlist_name;
}

int Playlist::getSize() const {
    return surahs.get_size();
}

void Playlist::add_Surah(surah& s)
{
    if (find_surah(s.get_surah()))
    {
        cout << "This surah is already exists!!...";

    }
    else
        surahs.insert_at_end(s);
}

void Playlist::removeSurah(const string& surah_name) {
    Node<surah>* current = surahs.getHead();


    if (current == nullptr) {
        cout << "The playlist is empty!" << endl;
        return;
    }

    while (current != nullptr) {
        if (current->data.get_surah() == surah_name) {

            if (current == surahs.getHead()) {
                surahs.head = current->next;
                if (current->next != nullptr) {
                    current->next->prev = nullptr;
                }
            }

            else if (current->next == nullptr) {
                current->prev->next = nullptr;
            }

            else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }

            delete current;
            cout << "Surah '" << surah_name << "' has been removed!" << endl;
            return;
        }
        current = current->next;
    }


    cout << "Surah '" << surah_name << "' not found in the playlist!" << endl;
}
surah Playlist::getSurahAt(int index) const {
    return surahs.getAt(index);
}
surah* Playlist::find_surah(std::string name)
{
    Node<surah>* current = surahs.getHead();
    while (current) {
        if (current->data.get_surah() == name) {
            return &current->data;
        }
        current = current->next;
    }
    return nullptr;
}
void Playlist::set_playlist_name(string n)
{
    playlist_name = n;
}
void Playlist::displayPlaylist() const
{
    Node<surah>* current = surahs.getHead();
    int j = 1;
    while (current) {
        current->data.display_surah(j);
        current = current->next;
        j++;
    }

}
void Playlist::updateSurahOrder(const string& surah_name, int new_position) {
    Node<surah>* current = surahs.getHead();


    if (current == nullptr) {
        cout << "The playlist is empty!" << endl;
        return;
    }


    while (current != nullptr) {
        if (current->data.get_surah() == surah_name) {

            if (current == surahs.getHead()) {
                surahs.head = current->next;
                if (current->next != nullptr) {
                    current->next->prev = nullptr;
                }
            }
            else {
                current->prev->next = current->next;
                if (current->next != nullptr) {
                    current->next->prev = current->prev;
                }
            }


            Node<surah>* temp = surahs.getHead();
            for (int i = 1; i < new_position - 1 && temp != nullptr; i++) {
                temp = temp->next;
            }

            if (temp == nullptr) {

                surahs.insert_at_end(current->data);
            }
            else {
                current->next = temp->next;
                if (temp->next != nullptr) {
                    temp->next->prev = current;
                }
                temp->next = current;
                current->prev = temp;
            }

            cout << "Surah '" << surah_name << "' has been moved to position " << new_position << "!" << endl;
            return;
        }
        current = current->next;
    }


    cout << "Surah '" << surah_name << "' not found in the playlist!" << endl;
}
void Playlist::clearPlaylist()
{
    surahs.clear();
}
