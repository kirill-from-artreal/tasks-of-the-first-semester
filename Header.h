#pragma once

#include <Windows.h>
#include <iostream>
#include <sstream>

#include <vector>
#include <string>
#include <list> // queue 

#include <cstdlib>
#include <cmath> 
#include <conio.h>
#include <limits> 
#include <iomanip>

#undef max

using namespace std;

typedef int (*PFunc)();
//typedef vector<Item>* PMenu;


//========================================================
struct Item 
{
    string title = "NoName";
    PFunc pfunc = NULL;
    vector<Item>* pmenu = NULL;
    int selected_item = 0;
};

struct FuncDB
{
	int id = 0;
	PFunc pfunc = NULL;
	string description = "Îïèñàíèå ôóíêöèè îòñóòñòâóåò.";
};

struct ItemDB
{
	int id = 0;
	int funcID = -1;
	int menuID = -1;
	string title = "Çàãîëîâîê ïóíêòà îòñóòñòâóåò.";
	string description = "Îïèñàíèå ïóíêòà îòñóòñòâóåò.";
};

struct MenuDB
{
	int id = 0;
	vector<int> itemID;
	string title = "Çàãîëîâîê ìåíþ îòñóòñòâóåò.";
};
//========================================================

int safe_input_int(const string& prompt);

#define ERR_INCORRECT_NUMBER -1
#define ERR_INCORRECT_NUMBER_TYPE -2


template <typename T>
T check_input(string s)
{
    T value;
    stringstream ss;
    ss << s;
    ss >> value;

    if (ss.fail())
        return ERR_INCORRECT_NUMBER; //std::cout << "Îøèáêà: ââåäèòå êîððåêòíîå ÷èñëî\n"; //ss.clear(); //ss.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    else {
        std::string str;
        ss >> str;
        if (!str.empty())
            return ERR_INCORRECT_NUMBER_TYPE; //std::cout << "Îøèáêà: íåâåðíûé ÷èñëîâîé òèï. Ñòðîêà: "<< str <<"\n"; // ss.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return value;
    }
}

template <typename T>
vector<T> parseInput(string s, const string &sep)
{ 
    vector<T> v;
    for (size_t pos = 0; (pos = s.find(sep)) != string::npos; )
    {
        v.push_back(check_input<T>(s.substr(0, pos)));
        s.erase(0, pos + sep.length());
    }
    if (!s.empty())
        v.push_back(check_input<T>(s));
    return v;
}

template <typename T>
vector<T> safeInputVec(const std::string& prompt)
{
    string s;

    std::cout << prompt;
    getline(cin, s);

    return parseInput<T>(s, " ");
}


template <typename T>
T safeInput(const std::string& prompt)
{
    string s;

    std::cout << prompt;
    getline(cin, s);

    return check_input<T>(s);
}

int task0(void);
int task1(void);
int task2(void);
int task3(void);
int task4(void);
int task5(void);
int task6(void);
int task7(void);
int task8(void);
int task9(void);
int task10(void);
int task11(void);
int task12(void);
int SF(void);

//item(std::string title, int (*function_pointer)(), vector<item>* sub_items)
//{
//    title = title;
//    function_pointer = function_pointer;
//    sub_items = sub_items;
//}

/* some links *
 https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file
 https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-sep-standard-c
 https://habr.com/ru/articles/326578/
/**/
