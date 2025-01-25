
#ifndef SURAH_H
#define SURAH_H
#include<string>
#include<iostream>
#include <iomanip>
#include"DLL.h"

using namespace std;
class surah
{
    string surah_name;
    string path;
    string surah_type;


public:
    surah();
    surah(string surah_name, string path, string surah_type);
    void set_surah_name(string surah_name);
    string get_surah();
    void set_path(string path);
    string get_path();
    void set_surah_type(string surah_type);
    string get_surah_type();
    void display_surah(int& i);
};
#endif