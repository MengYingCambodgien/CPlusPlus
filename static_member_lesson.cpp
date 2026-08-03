#include<iostream>

class Calculate{
    public:
        static int areaSquare(int length){
            return length*length;
        }
        static double areaCircle(int r){
            return (r*r*3.14);
        }
        static int max2(int a, int b){
            return (a>b?a:b);
        }
        static int min(int a, int b){
            return (a<b?b:a);
        }
        static double average(int a, int b){
            return (a+b)/2.00f;
        }
};

int main(){
    std::cout << "Average: " << Calculate::average(80, 30) << std::endl;
    std::cout << "Max: " << Calculate::max2(10, 30);
    return 0;
}