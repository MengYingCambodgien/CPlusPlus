#include<iostream>

using namespace std;

class Test1{
    public:
        static int n;
        Test1(){
            n++;
        }
        ~Test1(){
            n--;
        }
};


int Test1::n=0;

int main(){
    Test1 t1;
    Test1 t2;
    Test1 t3;

    cout<<"count object= " <<Test1::n<<endl;
    cout<<"count object= " <<t1.n<<endl;
    cout<<"count object= " <<t2.n<<endl;
    cout<<"count object= " <<t3.n<<endl;

    return 0;
}