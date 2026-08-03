#include <iostream>

using namespace std;

class Rect{
    private:
        int width;
        int height;
    public:
        Rect(){
            width = 0;
            height = 0;
        }
        Rect(int n){
            width = n;
            height = n;
        }
        Rect(int a, int b){
            width = a;
            height = b;
        }
        ~Rect(){}
        void input(){
            cout << "Enter Width >> ";
            cin >> width; if(cin.fail()) width = 0;
            cout << "Enter Height >> ";
            cin >> height; if(cin.fail()) height = 0;
        }
        void output(){
            cout << endl << "Width : " << width << " Height : " << height;
        }
        void setData(int a, int b){
            width = a;
            height = b;
        }
        void setWidth(int a){
            width = a;
        }
        int getWidth(){
            return width;
        }
        void setHeight(int b){
            height = b;
        }
        int getHeight(){
            return height;
        }
        int perimeter(){
            return 2 * width + 2 * height;
        }
        int area(){
            return width * height;
        }
};

int main(){
    Rect a;
    a.input();
    a.output();

    a.setData(20, 20);
    a.output();

    a.setWidth(5);
    cout << endl << "Width : " << a.getWidth();

    a.setHeight(5);
    cout << endl << "Height : " << a.getHeight();

    cout << endl << "Perimeter : " << a.perimeter();
    cout << endl << "Area : " << a.area();

    return 0;
}