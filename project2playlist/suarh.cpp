#include "suarh.h"
#pragma once
#include<string>
#include <iomanip>
#include<Windows.h>
#include<mmsystem.h>
#include <iostream>
# pragma comment (lib,"winmm.lib")
surah::surah() {}
surah::surah(string surah_name, string path, string surah_type)
{
    this->surah_name = surah_name;
    this->path = path;
    this->surah_type = surah_type;
}
void surah::set_surah_name(string surah_name)
{
    this->surah_name = surah_name;

}
string surah::get_surah()
{
    return surah_name;
}
void surah::set_path(string path)
{
    this->path = path;
}
string surah::get_path()
{
    return path;
}
void surah::set_surah_type(string surah_type)
{
    this->surah_type = surah_type;
}
string surah::get_surah_type()
{
    return surah_type;
}
void surah::display_surah(int& i)
{
    cout << left;
    cout << setw(10) << i << setw(20) << surah_name << setw(25) << path << setw(15) << surah_type << endl;
    cout << string(80, '-') << endl;
}
