#include <iostream>
#include<thread>
#pragma comment(lib, "Winmm.lib")
#include <conio.h>
#include<time.h>
#include<string>
#include <windows.h>
#include<unistd.h>
#include<bits/stdc++.h>
#include<conio.h>
#include<math.h>
#include <cstdlib>
#include <ctime>
#include<vector>
#include <sstream>
using namespace std;

int cnt = 0 ;

struct Data{
	string id;
    string title;
    string price;
    string user_id;
    string profileName;
    string review_helpfulness;
    string review_score;
    string review_time;
    string review_sumary;
    string review_text;
};

struct Book_ID{
    
    Data data;
    Book_ID *next;
};

