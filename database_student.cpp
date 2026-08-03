#include<iostream>

using namespace std;

class Date{
    private:
        static string date;
    public:
        Date(){
            date = "20/5/2008";
        }
        Date(string date){
            this->date = date;
        }
    void print(){
        cout << date;
    }
    void edit(){
        cout << "Input your name >> ";
        getline(cin, date);
    }
    string getDate(){
        return date;
    }
    class Time{
        private:
            static string time;
        public:
            Time(){
                time = "8:00PM";
            }
            Time(string time){
                this->time = time;
            }
            void print(){
                cout << time;
            }
            void edit(){
                cout << "Input your name >> ";
                getline(cin, time);
            }
            string getTime(){
                return time;
            }

    };
};

int main(){
    
}