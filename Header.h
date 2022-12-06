#include<iostream>
#include<string> 
#include<vector>
#include<fstream>
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

