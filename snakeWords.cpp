#include <iostream>
#include <fstream>
#include <chrono>
#include <conio.h>
#include <vector>

#define FrameDuration           0.4
#define DefaultDimension        {50, 20}
#define DefualtPLayerPosition   {1, 1}
#define DefualtAmountObjects    20

#define RESET_COLOR            "\x1b[0m"
#define COLOR_LIGHT_GRAY       "\e[0;37m"
#define BACKGROUND_COLOR_GREEN "\e[0;102m"
#define COLOR_B_G              "\033[34;42m"
#define COLOR_R_G              "\033[31;42m"
#define COLOR_Y_G              "\033[33;42m"

using namespace std;

class game{
    private:

        int display_dimension[2];
        
        struct object{

            char display_char;
            int is_tailed;
            int order;
            int pos[2];
            int previous_pos[2];

        }obj[DefualtAmountObjects];

        struct Player{

            int player_pos[2];
            int player_head_direction[2];
            int amount_tail;
            int previous_pos[2];
            int is_crashed;

        }player;
        
    public:

        game(){
            player.player_pos[0]            =   1;
            player.player_pos[1]            =   1;
            player.player_head_direction[0] =   0;
            player.player_head_direction[1] =   0;
            player.amount_tail              =   0;
            player.is_crashed               =   0;
            display_dimension[0]            =  20;
            display_dimension[1]            =  20;
        }

        game(vector<int> pos, vector<int> dimension){
            player.player_pos[0]                =        pos[0];
            player.player_pos[1]                =        pos[1];
            player.player_head_direction[0]     =             0;
            player.player_head_direction[1]     =             0;
            player.amount_tail                  =             0;
            player.is_crashed                   =             0;
            display_dimension[0]                =  dimension[0];
            display_dimension[1]                =  dimension[1];
        }

        void clearOutput(){
            cout << "\033[2J\033[1;1H";
        }

        void objectGenerate(){
            for(int x = 0; x < sizeof(obj) / sizeof(object); x++){
                obj[x] = {
                            .display_char = static_cast<char>(97 + rand() % 25),
                            .is_tailed = 0,
                            .order = 0,
                            .pos          = {
                                                rand() % (display_dimension[0] - 1) + 1,
                                                rand() % (display_dimension[1] - 1) + 1
                                            },
                         };
            }
        }

        void bountryCheck(){
            player.is_crashed = 0; // Assume safe at the start of check

            if(player.player_pos[0] <= 0) {
                player.player_pos[0] = 1; 
                player.is_crashed = 1; // Hit left wall
            }
            if(player.player_pos[0] >= display_dimension[0]) {
                player.player_pos[0] = display_dimension[0] - 1; 
                player.is_crashed = 1; // Hit right wall
            }
            if(player.player_pos[1] <= 0) {
                player.player_pos[1] = 1; 
                player.is_crashed = 1; // Hit top wall
            }
            if(player.player_pos[1] >= display_dimension[1]) {
                player.player_pos[1] = display_dimension[1] - 1; 
                player.is_crashed = 1; // Hit bottom wall
            }
        }

        void controller(){
            if(_kbhit()){
                char key = _getch();
                if(key=='a' || key=='A') {player.player_head_direction[0] = -1; player.player_head_direction[1] = 0;}
                else if(key=='d' || key=='D') {player.player_head_direction[0] = 1; player.player_head_direction[1] = 0;}
                if(key=='s' || key=='S') {player.player_head_direction[1] = 1;player.player_head_direction[0] = 0;}
                else if(key=='w' || key=='W') {player.player_head_direction[1] = -1;player.player_head_direction[0] = 0;}
            }
        }

        void movement(){
            if(player.player_head_direction[0] == -1)   player.player_pos[0]--;
            if(player.player_head_direction[0] == 1)    player.player_pos[0]++;
            if(player.player_head_direction[1] == 1)    player.player_pos[1]++;
            if(player.player_head_direction[1] == -1)   player.player_pos[1]--;
        }

        void collisionObjectCheck(){
            // Use &o so we modify the actual objects in the array
            for(object &o : obj){
                if(player.player_pos[0] == o.pos[0] && player.player_pos[1] == o.pos[1] && !o.is_tailed) {

                    o.is_tailed = 1; 
                    o.order = ++player.amount_tail;

                    if(player.amount_tail == 1){
                        o.pos[0] = player.previous_pos[0]; 
                        o.pos[1] = player.previous_pos[1];
                    }
                    else{
                        // Use &o2 here as well
                        for(object &o2 : obj){
                            if(o.order == o2.order) continue;
                            if(!o2.is_tailed) continue;
                            o.pos[0] = o2.previous_pos[0];
                            o.pos[1] = o2.previous_pos[1];
                        }
                    }
                }
            }
        }

        void leadingTail(){
            // If the head hit a wall, STOP the tail instantly
            if (player.is_crashed == 1) {
                return; 
            }

            for(object &o : obj){
                if(!o.is_tailed) continue;
                if(o.order == 1){
                    o.pos[0] = player.previous_pos[0];
                    o.pos[1] = player.previous_pos[1];
                }
                else{
                    for(object &o2 : obj){
                        if(!o2.is_tailed) continue;
                        if(o.order == o2.order) continue;
                        if(o.order - o2.order == 1){
                            o.pos[0] = o2.previous_pos[0];
                            o.pos[1] = o2.previous_pos[1];
                        }
                    }
                }
            }
        }

        void updatePosition(){
            player.previous_pos[0] = player.player_pos[0];
            player.previous_pos[1] = player.player_pos[1];
            
            // Use &o and make sure to save BOTH index 0 (X) and index 1 (Y)
            for(object &o : obj){
                if(!o.is_tailed) continue;
                o.previous_pos[0] = o.pos[0];
                o.previous_pos[1] = o.pos[1]; // Fixed: Added this line
            }
        }

        void display(){
            int x = 0, y = 0;

            while(true){
                if(x>=display_dimension[0]+1) {x=0; y++; cout << "\n";}
                if(y>=display_dimension[1]+1) break;

                if(x == player.player_pos[0] && y == player.player_pos[1]) cout << RESET_COLOR COLOR_R_G "$" RESET_COLOR;
                else if(x == 0 || y == 0 || x == display_dimension[0] || y == display_dimension[1]) cout << RESET_COLOR COLOR_LIGHT_GRAY "#" RESET_COLOR;
                else {
                    int found = 0;
                    for(object o : obj){
                        if(x == o.pos[0] && y == o.pos[1]) {
                            if(o.is_tailed) cout << RESET_COLOR COLOR_B_G << o.display_char << RESET_COLOR;
                            else cout << RESET_COLOR  COLOR_Y_G << o.display_char << RESET_COLOR;
                            found = 1; 
                            break;
                        }
                    }
                    if(!found) cout << RESET_COLOR BACKGROUND_COLOR_GREEN " " RESET_COLOR;
                }

                x++;
            }
        }

        void display_panel(){
            cout << "\n" << "Objects : " << sizeof(obj) / sizeof(object);
            cout << "\n" << "Direction : " << player.player_head_direction[0] << ", " << player.player_head_direction[1];
            cout << "\n" << "length of tail : " << player.amount_tail;
        }

        void update_once(){
            objectGenerate();
            updatePosition();
        }

        void update(){
            updatePosition(); // 1. Save old positions first
            movement();       // 2. Move the player head
            bountryCheck();   // 3. Keep player inside screen
            leadingTail();    // 4. Move the tail to follow the head
            collisionObjectCheck(); // 5. Check if we hit a new item
            clearOutput();
            display();
            display_panel();
        }
};

int main(){
    game snake(DefualtPLayerPosition, DefaultDimension);
    snake.update_once(); 
    auto previous_time = chrono::steady_clock::now();

    while (true){
        snake.controller();

        auto current_time = chrono::steady_clock::now();
        chrono::duration<double> elapsed = current_time - previous_time;
        if(elapsed.count() >= FrameDuration) 
            {snake.update(); previous_time = current_time;}
    }

    return 0;
}