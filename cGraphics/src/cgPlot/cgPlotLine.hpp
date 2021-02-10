#ifndef cgPlotLine_hpp
#define cgPlotLine_hpp
#include <stdio.h>
#include "Drawable.h"
#include "cgQuad.h"
class cgPlotLine : public Drawable{
public:
    cgPlotLine(float* xdata, float* ydata, int count, float thickness,cgVec2 xlimits, cgVec2 ylimits, cgRect inRect);
    ~cgPlotLine(){for(int i = 0; i < numLines;i++){delete lineSegments[i];}delete [] lineSegments;};
    void setColor(cgColor to){this->color = to; for(int i = 0; i < numLines; i++){lineSegments[i]->changeColor(to);}};
    virtual void draw() override;
private:
    int numLines;
    //std::vector<cgQuad> lineSegments
    cgQuad** lineSegments;
    cgColor color = cgColor(0,1,0);
};
#endif /* cgPlotLine_hpp */
