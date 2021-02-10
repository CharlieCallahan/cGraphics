#include "cgPlotLine.hpp"
cgPlotLine::cgPlotLine(float* xdata, float* ydata, int count, float thickness,cgVec2 xlimits, cgVec2 ylimits, cgRect inRect): Drawable(inRect){
    //ylimits = min,max
    lineSegments = new cgQuad*[count-1];
    float xSpan = xlimits.y-xlimits.x;
    float ySpan = ylimits.y-ylimits.x;
    cgVec2 start;
    cgVec2 end;
    for(int i = 0; i < count-1; i++){
        start = cgVec2((xdata[i] - xSpan/2)/xSpan*inRect.size.x, (ydata[i] - ylimits.x)/ySpan*inRect.size.y - inRect.size.y/2)+inRect.center;
        end = cgVec2((xdata[i+1] - xSpan/2)/xSpan*inRect.size.x, (ydata[i+1] - ylimits.x)/ySpan*inRect.size.y - inRect.size.y/2)+inRect.center;
        lineSegments[i] = new cgQuad(start,end, thickness,color);
    }
    numLines = count-1;
}
void cgPlotLine::draw(){
    for(int i = 0; i < numLines; i++){
        lineSegments[i]->draw();
    }
}
