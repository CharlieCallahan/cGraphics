#include "cgHeightMap.hpp"

int main()
{
    cg2DFloatArray dat = cg2DFloatArray(100,100);
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            dat.set(i, j, sin(float(i)/100.0*20*M_PI) + sin(float(j)/100.0*10*M_PI));
            //dat.set(i, j, (float(i)/100.0 + float(j)/100.0)/2);
        }
    }
    cgHeightMapWindow* wind = new cgHeightMapWindow(dat);
    
    wind->run();
}

