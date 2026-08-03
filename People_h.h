#ifndef People_h
#define People_h
#include<string.h>
#include<iostream>
using namespace std;
   class People{
    protected:
        char id[10],name[20],gender[20];
    public:
    	People();
    	People( char id[10] , char name[20], char gender[20] ){
    		strcpy(this->id,id);
            strcpy(this->name,name);
            strcpy(this->gender,gender);
		}
        void setData(char i[10],char n[20],char g[20]){
            strcpy(id,i);
            strcpy(name,n);
            strcpy(gender,g);
			}
            static void header(){
                cout<<"ID\tName\tGender\n";
            }
            void print(){
                cout<<id<<"\t"<<name<<"\t"<<gender;
            }
        };
        #endif