#include "food.h"
vector<pair<int,int> > nibbles;
pair<int,int> make_food(){
    return { rand()%(LINES-2)+1 , rand()%(COLS-2)+1 };
}


void init_food(){
    nibbles.clear();
    for(int i=0;i<FOOD_COUNT;i++){
        nibbles.push_back(make_food());
    }
}

void paint_food(){
    for(int i=0;i<nibbles.size();i++){
        move(nibbles[i].first,nibbles[i].second);
        init_pair(3,COLOR_BLACK,COLOR_YELLOW);
        attron(COLOR_PAIR(3));
        addch('$');
        attroff(COLOR_PAIR(3));
    }
}

bool try_eating_food(pair<int,int> head){
    for(int i=0;i<nibbles.size();i++){
        if(nibbles[i].first==head.first && nibbles[i].second==head.second){
            nibbles.erase(nibbles.begin()+i);
            nibbles.push_back(make_food());
            return true;
        }
    }
    return false;
}