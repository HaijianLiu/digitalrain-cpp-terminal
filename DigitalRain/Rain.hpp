//
//  Rain.hpp
//  DigitalRain
//
//  Created by haijian on 2017/05/16.
//  Copyright © 2017 haijian. All rights reserved.
//

#ifndef Rain_hpp
#define Rain_hpp

#include <iostream>
#include <curses.h>
#include "TimeMachine.hpp"

class Rain
{
public:
  Rain();
  void Fall();
private:
  TimeMachine tm;
  // current stdscr size X Y
  int stdscrX;
  int stdscrY;
  // rain parameters
  int startX; // rain start point coordinate X
  int delay; // delay = 0.001s * delay
  int startASC; // random characters starts from ASCII (48 means '0')
  int rangeASC; // how many characters to random (78 means from '0' to 'z')
  int length;
  float timer;
  int i;
};

#endif /* Rain_hpp */
