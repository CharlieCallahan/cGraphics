//
//  cgTiming.hpp
//  cGraphics
//
//  Created by Charles callahan on 2/6/21.
//  Copyright © 2021 Charles callahan. All rights reserved.
//

#ifndef cgTiming_hpp
#define cgTiming_hpp

#include <stdio.h>
#include <chrono>

namespace cgTiming{
    class Stopwatch{
    public:
        Stopwatch(){};
        void start();
        double stop_time();
        void print_stop_time();
    private:
        std::chrono::high_resolution_clock::time_point t1;
        std::chrono::high_resolution_clock::time_point t2;
    };
}
#endif /* cgTiming_hpp */
