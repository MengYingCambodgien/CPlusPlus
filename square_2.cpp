#include <iostream>

#include "square_header.h"

using namespace std;

int main(){
    Square s[10];
    int i, n, length;
    cout << "Input: n >> ";
    cin >> n;
    for(i=0;i<n;i++){
        cout << "Length square: ";
        cin >> length;
        s[i].setLength(length);
    }
    for(i=0;i<n;i++)
        cout << "Square " << i+1 << "= " << s[i].area() << endl;

    return 0;
}