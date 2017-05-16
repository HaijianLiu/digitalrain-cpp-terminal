//
//  TimeMachine.hpp
//  DigitalRain
//
//  Created by haijian on 2017/05/16.
//  Copyright © 2017 haijian. All rights reserved.
//

#ifndef TimeMachine_hpp
#define TimeMachine_hpp

#include <iostream>
#include <sys/time.h>
#include <math.h>

class TimeMachine{
public:
  const std::string CurrentDateTime();
  const std::string CurrentTime();
};

#endif /* TimeMachine_hpp */
