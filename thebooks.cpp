#include "thebooks.h"
#include <iostream>
#include <string.h>

using namespace std;

Book::Book(){
    strcpy(__title__, "Default");
    strcpy(__author__, "Default");
    __price__ = 0.0f;
}

Book::Book(const char title[30], const char author[20], const float price){
    strcpy(__title__, title);
    strcpy(__author__, author);
    __price__ = price;
}

void Book::manageDataBook(const char mode[10]){
    if(strcmp(mode, "title") == 0){
        cout << "Enter the title name >> ";
        char entry_input[30];
        cin.getline(entry_input, 30); cin.seekg(0, ios::end); cin.clear();
        strcpy(__title__, entry_input);
    }
    if(strcmp(mode, "author") == 0){
        cout << "Enter the author name >> ";
        char entry_input[20];
        cin.getline(entry_input, 20); cin.seekg(0, ios::end); cin.clear();
        strcpy(__author__, entry_input);
    }
    if(strcmp(mode, "price") == 0){
        cout << "Enter the price >> ";
        float tmp_price;
        cin >> tmp_price;
        __price__ = tmp_price;
    }
}

char* Book::get_author_name(){
    return __author__;
}

char* Book::get_title_name(){
    return __title__;
}

double Book::get_price(){
    return __price__;
}