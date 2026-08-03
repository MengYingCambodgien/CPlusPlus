#include <iostream>
#include <limits>

using namespace std;

class People{
    protected:
        string name;
        int id;
        char sex;
    public:
        People(): name("Anonymous User"), id(10), sex('M') {};
        People(string name, int id, char sex) : name(name), id(id), sex(sex) {};
        ~People() = default;
        string getName(){
            return name;
        }
        int getID(){
            return id;
        }
        char getSex(){
            return sex;
        }
        void inputName(){
            cout << "Input name >> ";
            getline(cin, name); cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        void inputID(){
            cout << "Input ID >> ";
            cin >> id;
            if(cin.fail()) id = 10;
        }
        void inputSex(){
            cout << "Input Sex >> ";
            cin >> sex;
            if(cin.fail()) sex = 'M';
        }
};

struct Subject{
    string name = "default";
    int max_score = 60;
    float score = 0;
};

class Student : public People{
    private:
        Subject subject[3];
        float average;
        char grade;

    public:
        Student();
        Student(Subject subject[3]){
            for(int i = 0; i < 3; i++){
                this->subject[i].name = subject[i].name;
                this->subject[i].max_score = subject[i].max_score;
                this->subject[i].score = subject[i].score;
            }
        }
        float getAverageScore(){
            return average;
        }
        char getGrade(){
            return grade;
        }
        void setGrade(){
            if(average >= 45){
                grade = 'A';
            }
            if(average >= 40){
                grade = 'B';
            }
            if(average >= 35){
                grade = 'C';
            }
            if(average >= 30){
                grade = 'D';
            }
            if(average >= 25){
                grade = 'E';
            }
            else{
                grade = 'F';
            }
        }
        void setAverageBySelf(){
            int tmp_score = 0;
            for(int i = 0; i < 3; i++){
                tmp_score += subject[i].score;
            }
            average = (float) tmp_score / 3;
        }
        void setAverage(int a, int b, int c){
            average = (float) (a + b + c) / 3;
        }
        void editSubjectName(int category, string name){
            if(category >= 3 || category < 0) return;
            subject[category].name = name;
        }
        void editSubjectMaxScore(int category, int score){
            if(category >= 3 || category < 0) return;
            subject[category].max_score = score;
        }
        void editSubjectScore(int category, int score){
            if(category >= 3 || category < 0) return;
            subject[category].score = score;
        }
    void display(){
        cout << "Name: " << getName() << endl;
        cout << "Sex: " << getSex() << endl;
        cout << "ID: " << getID() << endl;
        cout << "Average Score: " << getAverageScore() << endl;
        cout << "Grade: " << getGrade() << endl;
    }
};

int main(){
    Subject subject[3] = {
        {
            .name = "CPRO",
            .max_score = 50,
            .score = 35
        },
        {
            .name = "Math",
            .max_score = 50,
            .score = 25
        },
        {
            .name = "Physics",
            .max_score = 50,
            .score = 34
        }
    };

    Student s(subject);
    s.inputName();
    s.inputID();
    s.inputSex();
    s.setAverageBySelf();
    s.setGrade();
    s.display();
    
}