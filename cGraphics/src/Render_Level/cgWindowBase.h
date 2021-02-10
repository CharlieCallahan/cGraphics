#pragma once
#include "cGraphics.h"
#include <iostream>

class cgWindowBase
{
public:
    cgWindowBase(int width,int height, const char* name);
	~cgWindowBase();
	//Runs loop until window is closed
	void run();
protected:
	GLFWwindow* window;
	//Called each loop iteration
	virtual void draw()=0;
	virtual void processInput()=0;
};

