#include<iostream>

using namespace std;

class Calculation{
    private:
        double currency_convert = 4000.00f;
    public:
        Calculation() : currency_convert(3000.00f) {}
        Calculation(double currency) : currency_convert(currency) {}
        friend int total(int n, double price, Calculation c);
};

inline double Summary(double price, double price_2){
    return price + price_2;
}

int total(int n, double price, Calculation c){
    return n * price * c.currency_convert;
}


int main(){
    cout << Summary(4300.00f, 7800.30f) << endl;
    Calculation c;
    cout << total(30, 5000.00, c);
    return 0;
}