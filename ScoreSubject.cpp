#include <iostream>
#include <initializer_list>
#include <vector>

#define MAX_INPUT_SUBJECT 20

using namespace std;

struct Subject{
    string name;
    int max = 0;
    int score = 0;
};

class Score{
    private:
        Subject subject[MAX_INPUT_SUBJECT];
    public:
        Score(initializer_list<Subject> sub_tmp){
            for(int i = 0; i < MAX_INPUT_SUBJECT; i++){
                for(Subject sub1 : sub_tmp) if(subject[i].name[0] == '\0') subject[i] = sub1;
            }
        }

        int get_score(string subject_name){
            for(Subject sub1 : subject) if(subject_name == sub1.name) return sub1.score;
        }

        int get_max_score(string subject_name){
            for(Subject sub1 : subject) if(subject_name == sub1.name) return sub1.max;
        }

        string get_subject_highest_score(){
            int canidate = 0;
            for(Subject sub1 : subject) if(sub1.score > canidate) canidate = sub1.score;
            for(Subject sub1 : subject) if(canidate == sub1.score) return sub1.name;
        }

        int* sumRaw(){
            int output[2] = {0, 0};
            for(Subject sub1 : subject) if(sub1.max != 0) {output[0] += sub1.score; output[1]++;}
            return output;
        }

        double get_average(){
            int* raw = sumRaw();
            return raw[0]/raw[1];
        }

        char get_grade(string target_subject = "all-subjects"){
            int canidate = 0;
            int max = 0;
            if(target_subject == "all-subject") {canidate = sumRaw()[0]; max = sumRaw()[1];}
            else{
                for(Subject sub1 : subject)
                    {
                        if(sub1.name == target_subject){
                            canidate = sub1.score;
                            max = sub1.max;
                            break;
                        }
                    }
            }
            if(canidate >= max * .9 ) return 'A';
            else if(canidate >= max * .8) return 'B';
            else if(canidate >= max * .7) return 'C';
            else if(canidate >= max * .6) return 'D';
            else if(canidate >= max * .5) return 'E';
            else return 'F';
        }
};

