#include<iostream>

using namespace std;

int main(){
    string name;
    int age;
    float salary;

    cout << "Input your name" << endl << ">> ";
    cin >> name;
    cout << endl << "Enter your age" << endl << ">> ";
    Back:
    cin >> age;
    if(cin.fail()) {
        cerr << "You must type your age" << endl;
        cin.seekg(0, ios::end);
        cin.clear();
        goto Back;
    }
    
    cout << "YOur name";

    return 0;
}