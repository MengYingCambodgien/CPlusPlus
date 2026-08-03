#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;
class Student{
    private:
        int id;
        char name[20];
        int math, cpro, eng;
    public:
        void input(){
            cout << "Enter Id >> ";         cin >> id;
            cout << "Enter name >> ";       cin.seekg(0, ios::end); cin.clear();
            cin.getline(name, 20);
            cout << "Enter math score >> "; cin >> math;
            cout << "Enter cpro score >> "; cin >> cpro;
            cout << "Enter eng score >> ";  cin >> eng;
        }
        float average(){
            return (math + cpro + eng) / 3;
        }
        char grade(){
            if(average() >= 45) return 'a';
            if(average() >= 40) return 'b';
            if(average() >= 35) return 'c';
            if(average() >= 30) return 'd';
            if(average() >= 25) return 'e';
            return 'f';
        }

        void output(){
            cout << setw(2) << setfill('0') << id
                 << setw(20) << setfill(' ') << name << "\t"
                 << setw(2) << setfill(' ') << math << "\t"
                 << setw(2) << setfill(' ') << cpro << "\t"
                 << setw(2) << setfill(' ') << eng << "\t"
                 << fixed << setprecision(2) << average() << "\t"
                 << grade() << endl;
        }
};

int main(){
    Student s[50];
    int n;
    cout << "Enter n >> ";
    cin >> n;
    for(int i = 0; i < n; i++) s[i].input();
    cout << "|ID\t|Name\t|Math\t|CPro\t|Eng\t|" << endl;
    for(int i = 0; i < n; i++) s[i].output();

    return 0;
}