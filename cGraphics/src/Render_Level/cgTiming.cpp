//
//  cgTiming.cpp
//  cGraphics
//
//  Created by Charles callahan on 2/6/21.
//  Copyright © 2021 Charles callahan. All rights reserved.
//

#include "cgTiming.hpp"

void cgTiming::Stopwatch::start(){
    t1 = std::chrono::high_resolution_clock::now();
}
double cgTiming::Stopwatch::stop_time(){
    t2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
    return time_span.count();
}
void cgTiming::Stopwatch::print_stop_time(){
    printf("Time: %f\n", stop_time());
}
