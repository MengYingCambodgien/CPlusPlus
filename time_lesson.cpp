#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

class MyTime{
    private:
        int hh, mm, ss;
    public:
        MyTime():hh(0),mm(0),ss(0){}
        MyTime(int h, int m, int s){
            hh=h; mm=m; ss=s;
        }
        void setTime(int h, int m, int s){
            hh=h; mm=m; ss=s;
        }
        void setHour(int h){hh=h;}
        void setMinute(int m){mm=m;}
        void setSecond(int s){ss=s;}
        int getHour(){return hh;}
        int getMinute(){return mm;}
        int getSecond(){return ss;}
        static MyTime CurrentTime(){
            MyTime mt;
            time_t t = time(0);
            tm *now = localtime(&t);
            mt.setHour(now->tm_hour);
            mt.setMinute(now->tm_min);
            mt.setSecond(now->tm_sec);
            return mt;
        }
        MyTime operator-(MyTime &tt){
            MyTime t; int h,m,s;
            h=hh-tt.hh;
            m=mm-tt.mm;
            s=ss-tt.ss;
            if(s<0){
                m--;
                s=60+s;
            }
            if(m<0){
                h--;
                m=60+m;
            }
            t.setTime(h,m,s);
            return t;
        }
        MyTime operator+(MyTime &tt){
            MyTime t; int h, m, s;
            h=hh+tt.hh;
            m=mm+tt.mm;
            s=ss+tt.ss;
            if(s>=60){
                m++;
                s=s%60;
            }
            if(m>=60){
                h++;
                m=m%60;
            }
            t.setTime(h,m,s);
            return t;
        }
        void print(){
            cout <<setw(2)<<setfill('0')<<hh<<":";
            cout <<setw(2)<<setfill('0')<<mm<<":";
            cout <<setw(2)<<setfill('0')<<ss<<"\n";
        }
        friend istream& operator>>(istream& input, MyTime& tt){
            input >> tt.hh >> tt.mm >> tt.ss;
            return input;
        }
        friend ostream& operator<<(ostream& output, MyTime& tt){
            output <<setw(2)<<setfill('0')<<tt.hh<<":";
            output <<setw(2)<<setfill('0')<<tt.mm<<":";
            output <<setw(2)<<setfill('0')<<tt.ss<<"\n";
            return output;
        }
};

int main(){
    MyTime current = MyTime::CurrentTime();
    current.print();
    MyTime t1(2,30,40);
    MyTime t2(1,40,30);
    MyTime t3;
    cout << "\nInput the time hh mm ss >> ";
    cin >> t3;
    cout << t3;
    MyTime total = t1 - t2;
    cout << "total time is " << total.getHour()
         << " hours and " << total.getMinute()
         << " minutes and " << total.getSecond() << " seconds\n";
    return 0;
}