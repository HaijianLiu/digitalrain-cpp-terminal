//
//  TimeMachine.cpp
//  DigitalRain
//
//  Created by haijian on 2017/05/16.
//  Copyright © 2017 haijian. All rights reserved.
//

#include "TimeMachine.hpp"

const std::string TimeMachine::CurrentDateTime() {
  char            fmt[64], buf[64];
  struct timeval  tv;
  struct tm       *tm;
  gettimeofday(&tv, NULL);
  tm = localtime(&tv.tv_sec);
  strftime(fmt, sizeof fmt, "%Y-%m-%d %H:%M:%S.%%06u", tm);
  snprintf(buf, sizeof buf, fmt, tv.tv_usec);
  return buf;
}

const std::string TimeMachine::CurrentTime() {
  char            fmt[64], buf[64];
  struct timeval  tv;
  struct tm       *tm;
  gettimeofday(&tv, NULL);
  tm = localtime(&tv.tv_sec);
  strftime(fmt, sizeof fmt, "%H%M%S.%%06u", tm);
  snprintf(buf, sizeof buf, fmt, tv.tv_usec);
  return buf;
}

// printf("%f\n",std::stof(tm.CurrentTime()));
