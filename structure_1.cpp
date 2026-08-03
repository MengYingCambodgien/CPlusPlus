#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

struct List 
{
    int id;
    char name[30];
    int age;
};

void enterData(List* student, int row)
{
    cout << endl << "Student Row " << setw(2) << setfill('0') << row + 1 << endl;
    student[row].id = row + 1;
    cout << "Enter the name >> "; 
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.seekg(0, ios::end); cin.clear();
    cin.getline(student[row].name, 30, '\n');
    cout << "Enter the age >> ";
    cin >> student[row].age;
}

void display(List* student, int row)
{
    cout << endl << "Student " << student[row].id << " , " << student[row].name << " , " << student[row].age;
}

int main()
{
    List student[50];
    cout << "Input the row >> ";
    int range;
    cin >> range; if(cin.fail()) range = 1;
    for(int i = 0; i < range; i++) enterData(student, i);
    for(int i = 0; i < range; i++) display(student, i);
    return 0;
}