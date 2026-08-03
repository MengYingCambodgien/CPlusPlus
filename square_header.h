#ifndef Square_h
#define Square_h

class Square{
    private:
        int length;
    public:
        Square(){}
        Square(Square &s) {length = s.length;}
        Square(int len) {length=len;}
        int area() {return length*length;}
        void setLength(int l) {length = l;}
        int getLength() {return length;}
};

#endif