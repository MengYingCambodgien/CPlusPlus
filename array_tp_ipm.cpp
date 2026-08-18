#include <iostream>

using namespace std;

template<class T>
class ArrayList{
    private:
        int size = 0;
        T* arr;
    public:
        ArrayList() : size(0), arr(nullptr){}

        ArrayList(arr, size){
            this->arr = new T[size];
            for(auto tmp : arr){
                this->arr[this->size++];
            }
        }
};