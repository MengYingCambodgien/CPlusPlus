#include <iostream>

using namespace std;

class Square{
    protected:
        int x;
    public:
        void getData(){
            cout << "Enter the value of side x : ";
            cin >> x;
        }
        int area(){
            int temp = x * x;
            return temp;
        }
        void display(){
            cout << "Value of x = y = " << x << endl;
            cout << "Area of Square = " << area();

        }
};

class Rectangle : public Square{
    protected:
        int y;
    public:
        void getData(){
            cout << "Enter the value of side x and y : ";
            cin >> x >> y;
        }
        int area(){
            int temp = x * y;
            return temp;
        }
        void display(){
            cout << "Value of x = " << x << ", y = " << y << endl;
            cout << "Area of Square = " << area();

        }
};

int main(){
    Square sob;
    Rectangle rob;
    Square* ptr;
    ptr = &sob;
    ptr = &rob;
    ptr->getData();
    ptr->display();
    return 0;
}