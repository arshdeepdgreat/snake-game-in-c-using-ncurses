#include "snake.h"
int x,y;
vector<pair <int , int>> body;

void init_snake(){
    body.clear();
    body.push_back({10,10});
    body.push_back({10,11});
    body.push_back({10,12});    
}


void paint_snake(){
    for (int i=0;i<body.size();i++){
        pair<int , int>location=body[i];
        move(location.first,location.second);
        //start_color();
        init_pair(2,COLOR_GREEN,COLOR_BLUE);
        attron(COLOR_PAIR(2));
        addch('*');
        attroff(COLOR_PAIR(2));
        
    }
}

pair<int , int> tail;

pair<int , int> move_snake(int direction){
    tail=body[body.size()-1];
    body.pop_back();
    pair<int , int>old_head=body[0];
    pair<int , int>new_head=old_head;

        if (direction==UP){
            new_head.first--;
        }
        else if(direction==DOWN){
            new_head.first++;
        }
        else if(direction==LEFT){
            new_head.second--;
        }
        else if(direction==RIGHT){
            new_head.second++;
        }
    body.insert(body.begin(), new_head);
    return new_head;
}

void grow_snake(){
    body.push_back(tail);
}


bool has_collision(){
    pair<int,int> head=body[0];
    int x=head.first,y=head.second;

    if(x==0 || y==0 || x==LINES-1 || y==COLS-1){
        return true;
    }

    for(int i=1;i<body.size();i++){
        if(head==body[i]){
            return true;
        }
    }
    return false;
}