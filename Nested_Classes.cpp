#include<iostream>

using namespace std;
class B;
class A{
    private:
        int x;
    public:
        void setdata(int i){
            x=i;
        }
        friend int Calculate(A a, B b);
};

class B{
    private:
        int x;
    public:
        void setdata(int i){
            x=i;
        }
        friend int Calculate(A a, B b);
};

int Calculate(A a, B b){
    return a.x + b.x;
}

int main(){
    A a; B b;
    a.setdata(20); b.setdata(40);
    cout << Calculate(a, b);
    return 0;
}