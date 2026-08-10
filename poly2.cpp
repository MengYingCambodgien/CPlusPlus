#include <iostream>

using namespace std;

class Square{
    protected:
        int len;
    public:
        virtual void input(){
            cout << "Input len of Square >> ";
            cin >> len;
        }
        virtual int area(){
            return len * len;
        }
        virtual void output(){
            cout << "Length of Square : " << len << endl;
            cout << "Area of Square : " << area() << endl;
        }
};
class Rectangle : public Square{
    protected:
        int len2;
    public:
        void input() override {
            cout << "Input len and len2 of Square >> ";
            cin >> len >> len2;
        }
        int area() override {
            return len * len2;
        }
        void output() override {
            cout << "horizontal lenght of Rectangle : " << len << endl;
            cout << "veritcal lenght of Rectangle : " << len2 << endl;
            cout << "Area of Rectangle : " << area() << endl;
        }
};


int main(){
    Square* ptr;
    Square sq;
    Rectangle rect;
    ptr = &sq;
    ptr->input();
    ptr->output();
    ptr = &rect;
    ptr->input();
    ptr->output();
    return 0;
}