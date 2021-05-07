#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"

#include "doubleClicker.h"

class testApp : public ofBaseApp {
	
public:
	
	doubleClicker clicker;
	void setup();
    void draw();

	bool bState1 = false;
	bool bState2 = false;
};

#endif

