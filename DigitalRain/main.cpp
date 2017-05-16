//
//  main.cpp
//  DigitalRain
//
//  Created by haijian on 2017/05/16.
//  Copyright © 2017 haijian. All rights reserved.
//

#include <iostream>
#include <curses.h>
#include "Rain.hpp"

#define HEAVY (30)

int main(int argc, const char * argv[]) {
  // curses initialize stdscr
  initscr();
  // sets the cursor state to invisible
  curs_set(0);
  noecho();
  // set timeout (ms) frametime
  timeout(1);
  // initialize random seed
  srand((unsigned)time(NULL));
  // initialize main class
  Rain rain[HEAVY];
  // framerate check
  while (-getch()) {
    for (int i = 0; i < HEAVY; i++) {
      rain[i].Fall();
    }
  }
  // curses end stdscr
  endwin();
  return 0;
}
