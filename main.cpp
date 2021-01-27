#include<iostream>
#include<unistd.h>
#include<curses.h>
#include "settings_constant.h"
#include <chrono>
#include "ui.h"
#include "game.h"
using namespace std;
int k;
int time_delay_bf;

int set_delay(int k){
    if(k==3){
        time_delay_bf=time_delay_1;
    }
    else if(k==2){
        time_delay_bf=time_delay_2;
    }
    else if(k==1){
        time_delay_bf=time_delay_3;
    }
    else{
        k=k%3+1;
        set_delay(k);
    }
    return k;
}

void event_loop(int q){
    int dt;
    while(true){
        auto last_time=chrono::system_clock::now();
        erase();
    
        bool a=game_logic(q);
        if(a==false)break;
        refresh();
        

        do{
            auto current_time=chrono::system_clock::now();
            dt=chrono::duration_cast<std::chrono::microseconds>(current_time-last_time).count();
        }while(dt<time_delay_bf);
    }
}

int main(){
   cout<<"\n\n HI AND WELCOME TO SNAKE GAME\n\n";
   cout<<"Choose game mode\n\n";
   cout<<" 1.Easy \n 2.Medium \n 3.Hard \n";
   cout<<"Enter choice : ";
   
   cin>>k;
   int c=set_delay(k);

   init_ui();
   event_loop(c);
   tear_down_ui();
   cout<<"THANKS FOR PLAYING THE GAME"<<endl; 
}