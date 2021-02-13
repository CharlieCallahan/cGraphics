#pragma once
#include "cgWindowBase.h"
#include "cgPlotBox.hpp"
#include "Shader.h"
#include "cgLog.hpp"

class plotWindow : public cgWindowBase
{
public:
	plotWindow(cgVec2 xlim, cgVec2 ylim);
    ~plotWindow(){delete plotBox;delete shader;};
    void addLine(float* xdata, float*ydata, int count);
    void addLine(float*ydata, int count);
    void addLine(double* ydata, int count);
protected:
	// Inherited via cgWindowBase
	virtual void draw() override;
	virtual void processInput() override;
private:
    cgColor getNextColor();
private:
    cgPlotBox* plotBox;
    cgVec2 xlim;
    cgVec2 ylim;
	Shader* shader; // need to set shader before rendering
    cgColor colors[3] = {{.41,.73,.95},{0,1,0},{0,0,1}};
    int currentColor = 0;
};
void plotTest();
