#include "game.h"

int direction;
int game_state=BEFORE_START;

int score;
int high_score=0;
int level;

void start_game(){
    init_snake();
    init_food();
    score=0;
    direction=LEFT;
    game_state=START;
}

void endgame(){
    game_state=ENDED;
}
void paint_score(int k){
    move(0,6);
    char s[10];
    char s1[10]="Easy",s2[10]="Medium",s3[10]="Hard";
    
    if(k==1)strcpy(s,s1);
    else if(k==2)strcpy(s,s2);
    else if(k==3)strcpy(s,s3);
    addstr("|||                  Score ");
    printw("%d High Score %d  Difficulty %s           |||",score,high_score,s);
}

bool game_logic(int k){
    int key=getch();
    paint_border();
    paint_score(k);
    if(game_state==BEFORE_START){
        move(10,15);
        addstr("press spacebar to start playing best playing when full screen");

            if(key==32){
                start_game();
            }
        }
    else if(game_state==START)
    {
        if((key==UP||key==UPA||key==UPB) && direction!=DOWN){
            direction=UP;
        }
        else if((key==DOWN||key==DOWNB||key==DOWNA) && direction!=UP){
            direction=DOWN;
        }
        else if((key==LEFT||key==LEFTA||key==LEFTB) && direction!=RIGHT){
            direction=LEFT;
        }
        else if((key==RIGHT||key==RIGHTA||key==RIGHTB) && direction!=LEFT){
            direction=RIGHT;
        }
        pair<int,int> head=move_snake(direction);

        if(try_eating_food(head)){
            grow_snake();
            score++;
        }
        if(has_collision()){
            //make game state
            endgame();
            if(score>high_score)
            high_score=score;
        }
        paint_snake();
        paint_food();

    }
        // if(direction== UP){
        //     x--;
        // }
        // if(direction== LEFT){
        //     y--;
        // }
        // if(direction==DOWN){
        //     x++;
        // }
        // if(direction==RIGHT){
        //     y++;
        // }
        // move(x,y);
        // addch('#');


    else {
        move(10,45);
        addstr("GAME OVER!!!\n \t\t\t\t\t\t press spacebar to restart \n \t\t\t\t\t\t press q to quit");
        
        if(key==32){
            game_state=START;
            start_game();
        }
        else if(key==113){
            return false;
        }
    }
   return true; 
}