#include<iostream>
#include<conio.h>
#include "People_h.h"
#include<string.h>
 class Science:public People{
 	protected:
 		int math,english;
	public:
		Science (): People (){}
		Science( char i[10],char n[20],char g[6],int m, int e):
			People(i,n,g){
			math=m;
			english=e;
		}
		void setDate(char i[10],char n[20], char g[6],int m,int e){
			People::setData(i,n,g);
			math=m;
			english=e;
		}	
		void output(){
			print();
			cout<<"\t"<<math<<"\t"<<english;
		}
 };
 class IT: public Science{
 	protected:
 		int fund,cpro;
 	public:
 		IT():Science(){}
		IT( char i[10], char n[20], char g[20], int m, int e, int f, int c):
		Science(i,n,g,m,e){
		fund=f;
		cpro=c;
	}
	void setData(char i[10], char n[20], char g[20], int m, int e, int f, int c){
		Science::setDate(i,n,g,m,e);
		fund=f;
		cpro=c;
	}
	void output(){
		print();
		cout<<"\t"<<math<<"\t"<<english<<"\t"<<fund<<"\t"<<cpro;
	}
 };
  int main(){
  	IT s("ID086","KONKLA","STRANGER",50,25,35,12);
  	s.output();
  	return 0;
  }
 
 
 