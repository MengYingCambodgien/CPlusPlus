#include "thebooks.h"
#include <iostream>
#include <iomanip>

using namespace std;

void sortArrayByPrice(Book* book, int size, char order){
    Book tmp;
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(book[j+1].get_price() < book[j].get_price() && order == 'a'){
                tmp = book[j+1];
                book[j+1] = book[j];
                book[j] = tmp;
            }
            if(book[j+1].get_price() > book[j].get_price() && order == 'd'){
                tmp = book[j+1];
                book[j+1] = book[j];
                book[j] = tmp;
            }
        }
    }
}

int main(){
    Book book[5] = {
        {
            "The Wither Rose",
            "Lay Punlue",
            50.0
        },
        {
            "The Distance Of Descendants",
            "Hav Mengying",
            100.02
        },
        {
            "The Breaking Old Habit",
            "Chan Sophary",
            48.90
        },
        {
            "Acting Self-Centered Person",
            "Reach Bunnaseth",
            65.25
        },
        {
            "Being Self-Awareness",
            "Chheng Hungdy",
            80.4
        }
    };

    // book[2].manageDataBook("title");

    sortArrayByPrice(book, (int) sizeof(book) / sizeof(Book), 'd');

    for(Book seq : book){
        cout << "(" << fixed << setprecision(2) << seq.get_price() << "$" << ", " << seq.get_title_name() << ", " << seq.get_author_name() << ")" << endl;
    }
    
    return 0;
}