#pragma once
#include "cgWindowBase.h"
#include "Shader.h"
#include "cgQuad.h"
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
    float angle = 0;
    cgQuad* test;
	Shader* shader;
};

