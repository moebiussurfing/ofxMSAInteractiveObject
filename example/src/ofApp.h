#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"

#include "DoubleClicker.h"

class testApp : public ofBaseApp {
	
public:
	
	DoubleClicker clicker;
	void setup();
    void draw();

	bool bState1 = false;
	bool bState2 = false;
};

#endif

