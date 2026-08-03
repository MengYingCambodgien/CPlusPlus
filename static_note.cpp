#include <iostream>

using namespace std;

class player{
    public:
        static int value;
};

int player::value = 0;

int main(){
    
    player p[3];
    p[0].value = 1;
    p[1].value = 2;
    p[2].value = 3;
    cout << p[2].value << " | " << p[1].value << " | " << p[2].value; 
    return 0;
}