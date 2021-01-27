#include "ui.h"

char border_char='#';
void init_ui(){
    initscr();
    
    nodelay(stdscr,TRUE);
    noecho();
    curs_set(0);
}

void tear_down_ui(){
    endwin();
}

void paint_border(){
    start_color();
    init_pair(1,COLOR_RED,COLOR_BLACK);
    attron(COLOR_PAIR(1));
    for(int i=0;i<COLS;i++){
        move(0,i);
        addch(border_char);
        move(LINES-1,i);
        addch(border_char);
    }

    for(int i=1;i<LINES-1;i++){
        move(i,0);
        addch(border_char);
        move(i,COLS-1);
        addch(border_char);
    }
    attroff(COLOR_PAIR(1));
    //getch();
}
