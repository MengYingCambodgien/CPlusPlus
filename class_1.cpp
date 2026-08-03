#include<iostream>
#include<conio.h>
using namespace std;
class Product{
    private:
        int id, qty;
        char name[20];
        float price;
    public:
        void input() {
            cout << "id: "; cin >> id;
            cout << "name: "; cin.seekg(0, ios::end); cin.clear();
            cin.getline(name, 20);
            cout << "qty: "; cin >> qty;
            cout << "price: "; cin >> price;
        }
        void print(){
            cout << "id: " << id << " name: " << name << " qty: " << qty << " price: " << price << endl;
        }
        void println(){
            cout << "id: " << id << endl << " name: " << name << endl <<  "qty: " << qty << endl << "price: " << price << endl;
        }
        void amount(){
            cout << "amount: " << qty * price << endl;
        }
};

int main(){
    Product p;
    p.input();
    p.print();
    p.println();
    p.amount();
    return 0;
}