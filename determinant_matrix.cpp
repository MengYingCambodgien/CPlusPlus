#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

void input_matrix_value(int** matrix_square, const int dimenstion){
    
    string assigning, temp, arr[2];
    cout << "Enter the which variable will be assigned x y >> ";
    getline(cin, assigning);
    stringstream ss(assigning);

    int row = 0;

    while(ss >> temp){
        if(row < 2){
            arr[row++] = temp;
        }
    }

    if(stoi(arr[0]) > dimenstion || stoi(arr[1]) > dimenstion) cerr << "Assigned to variable that is out of bound!";

    cout << "Enter the value (enter: default 0)>> ";
    int num;
    cin >> num; if(cin.fail()) num = 0;
    matrix_square[stoi(arr[1])][stoi(arr[0])] = num;
    
}

int** determinant_process(){
    return;
}

int main(){
    const int N = 100;
    int matrix_square[N][N];
    int n;

    cout << "Input the dimension of matrix square >> ";
    cin >> n; if(cin.fail()) n = 0;
}