//
//  Rain.cpp
//  DigitalRain
//
//  Created by haijian on 2017/05/16.
//  Copyright © 2017 haijian. All rights reserved.
//

#include "Rain.hpp"

Rain::Rain(){
  startASC = 48; // random characters starts from ASCII (48 means '0')
  rangeASC = 75; // how many characters to random (78 means from '0' to 'z')
  timer = std::stof(tm.CurrentTime()) + (float)(random()%10); // set timer to zero
  // get stdscr size to initialize the start point
  getmaxyx(stdscr,stdscrY,stdscrX);
  startX = rand()%stdscrX; // random: rain start point coordinate X
  delay = 50+rand()%101; // random speed: 4 levels
  length = 5*(rand()%2+2); // random length: 2 levels
  i = 0; // counter
}

void Rain::Fall(){
  // check time
  if (timer < std::stof(tm.CurrentTime())) {
    // check counter
    if (i < stdscrY+length) {
      // print start number
      if (i < stdscrY) {
        attron(A_REVERSE);
        mvprintw(i,startX,"%c",startASC+rand()%rangeASC);
        attroff(A_REVERSE);
        if (i > 0) {
          mvprintw(i-1,startX,"%c",startASC+rand()%rangeASC);
        }
      }
      // erase end number
      if (i >= length) {
        mvprintw(i-length,startX," ");
      }
      i++; // update counter
    }else{
      // the rain is over then restart a new one
      getmaxyx(stdscr,stdscrY,stdscrX); // get stdscr size to initialize the start point
      startX = rand()%stdscrX; // random: rain start point coordinate X
      delay = 50+rand()%101; // random speed: 4 levels
      length = 5*(rand()%2+2); // random length: 2 levels
      i = 0; // counter
    }
    // update timer
    timer = std::stof(tm.CurrentTime()) + (float)delay*0.001;
  }
}
