//
//  cgPlotBox.cpp
//  cGraphics
//
//  Created by Charles callahan on 2/9/21.
//  Copyright © 2021 Charles callahan. All rights reserved.
//

#include "cgPlotBox.hpp"

cgPlotBox::cgPlotBox(cgRect rect, cgVec2 xlim, cgVec2 ylim):Drawable(rect){
    background = new cgQuad(rect, cgColor(.24,.25,.26));
    this->xlim = xlim;
    this->ylim = ylim;
}
void cgPlotBox::draw(){
    background->draw();
    for(int i = 0; i < lines.size();i++){
        lines[i]->draw();
    }
}
void cgPlotBox::addLine(float* xdata,float* ydata,int count, cgColor color){
    lines.push_back(new cgPlotLine(xdata ,ydata ,count, lineWidth , xlim, ylim, this->rect));
}
