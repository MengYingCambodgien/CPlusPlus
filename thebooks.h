#ifndef THEBOOKS_H
#define THEBOOKS_H

class Book{
    private:
        char __title__[30];
        char __author__[20];
        float __price__;
    public:
        Book();
        Book(const char title[30], const char author[20], const float price);
        void manageDataBook(const char mode[10]);
        char* get_title_name();
        char* get_author_name();
        double get_price();
};

#endif