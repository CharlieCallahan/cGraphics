#pragma once
#include "cgWindowBase.h"
#include "cgPlotBox.hpp"
#include "Shader.h"
#include "cgLog.hpp"

class plotWindow : public cgWindowBase
{
public:
	plotWindow();
    ~plotWindow(){delete test;delete shader;};
protected:
	// Inherited via cgWindowBase
	virtual void draw() override;
	virtual void processInput() override;
private:
	void initVAO();
private:
    cgPlotBox* test;
	Shader* shader; // need to set shader before rendering
    
};

