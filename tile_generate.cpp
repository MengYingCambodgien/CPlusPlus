#include <iostream>
#include <random>
#include <time.h>

#define MAX 120

using namespace std;

int main(){
    srand(time(nullptr));
    int vector[MAX][2];
    int choice[3] = {-1, 0, 1};
    int u = 0;
    for(int x = 0; x < MAX; x++){
        int y = rand() % 3;
        vector[x][0] = x;
        u += choice[y];
        vector[x][1] = u;
        cout << vector[x][0] << ", " << vector[x][1] << endl;
    }
    for(int y = -30; y < 20; y++){
        for(int x = 0; x < MAX; x++){
            if(vector[x][1] == y ) cout << "x";
            else cout << " ";
        }
        cout << "\n";
    }
    
    return 0;
}