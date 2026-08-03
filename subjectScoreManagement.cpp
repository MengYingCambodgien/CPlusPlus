#include <iostream>

#define DEFUALT_AMOUNT_STUDENT_INTEND_CLASS 10
#define DEFUALT_AMOUNT_SUBJECT_REQUIRED 10

using namespace std;

struct Subject{
    string name;
    int max;
    int score;
    char grade;
    double average;
    bool is_active;
};

struct Student{
    int id;
    string name;
    Subject s[DEFUALT_AMOUNT_SUBJECT_REQUIRED];
};

class Classroom{
    private:
        int default_amount_student = 4;
        int default_amount_subject = 5;
        Student student[DEFUALT_AMOUNT_STUDENT_INTEND_CLASS];

    
    public:
        Classroom(){
            Student student_tmp[default_amount_student] = {
                {
                    .id = 20105,
                    .name = "Hav Mengying"
                },
                {
                    .id = 20190,
                    .name = "Chheng Hundy"
                },
                {
                    .id = 20220,
                    .name = "Seng Menghong"
                },
                {
                    .id = 20250,
                    .name = "Song Kimneang"
                },
                {
                    .id = 20300,
                    .name = "Leang Nieagpin"
                }
            };

            Subject sub_tmp[default_amount_subject] = {
                {
                    .name = "Khmer",
                    .max = 60,
                    .score = 0,
                    .grade = 'f',
                    .average = 0.00f,
                    .is_active = false
                },
                {
                    .name = "English",
                    .max = 60,
                    .score = 0,
                    .grade = 'f',
                    .average = 0.00f,
                    .is_active = false
                },
                {
                    .name = "Math",
                    .max = 120,
                    .score = 0,
                    .grade = 'f',
                    .average = 0.00f,
                    .is_active = false
                },
                {
                    .name = "CProgram",
                    .max = 50,
                    .score = 0,
                    .grade = 'f',
                    .average = 0.00f,
                    .is_active = false
                },
                {
                    .name = "Physics",
                    .max = 60,
                    .score = 0,
                    .grade = 'f',
                    .average = 0.00f,
                    .is_active = false
                }
            };

            for(int n = 0; n < default_amount_student; n++){
                student[n] = student_tmp[n];
            }

            for(Student &indiviual : student){
                for(int c = 0; c < default_amount_subject; c++)
                    indiviual.s[c] = sub_tmp[c];
            }
            
        }

        void Input_Student_Account(){

        }

        void Input_Student_Subject(){

        }

        void get_Student_Account(){

        }

        void Insert_Subject(){

        }

        void Output_All_Accounts(){

        }
};

void decorateRuler(int n, char chr){
    for(int i = 0; i < n; i++) cout << chr;
}

void initualizing(){
    Classroom classroom;
    char command_line[20];
    int n = 25, u = 10;

    decorateRuler(n, '='); cout << endl;
    decorateRuler(u, '_'); cout << "Commands"; decorateRuler(u, '_'); cout << endl;
    cout << "Enter the command >> ";
    cin.getline(command_line, 20); cin.seekg(0, ios::end); cin.clear();
    if(command_line == "Add Account"){

    }
}

int main(){
    return 0;
}