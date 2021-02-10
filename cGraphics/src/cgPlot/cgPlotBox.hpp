//
//  cgPlotBox.hpp
//  cGraphics
//
//  Created by Charles callahan on 2/9/21.
//  Copyright © 2021 Charles callahan. All rights reserved.
//

#ifndef cgPlotBox_hpp
#define cgPlotBox_hpp

#include <stdio.h>
#include "cgPlotLine.hpp"
#include <vector>
class cgPlotBox : public Drawable{
public:
    cgPlotBox(cgRect rect, cgVec2 xlim, cgVec2 ylim);
    ~cgPlotBox(){delete background; for(int i = 0; i < lines.size();i++){delete lines[i];}};
    void addLine(float* xdata,float* ydata,int count, cgColor color);
    virtual void draw() override;
    
private:
    cgQuad* background;
    std::vector<cgPlotLine*> lines;
    const float lineWidth = 0.0015;
    cgVec2 ylim = cgVec2(-1, 1);
    cgVec2 xlim = cgVec2(-1,1);
};
#endif /* cgPlotBox_hpp */
