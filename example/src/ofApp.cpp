#include "ofApp.h"

void testApp::setup() {
	//clicker.set(300, 50, 100, 200);//button

	clicker.set(0, 0, ofGetWidth(), ofGetHeight());//full screen
	clicker.setDebug(false);
}

void testApp::draw() {

	// flip bg colors on double and triple click
	if (clicker.isMouseDoubleClick()) bState1 = !bState1;
	if (clicker.isMouseTripleClick()) bState2 = !bState2;

	if (bState2) ofClear(bState1 ? ofColor::blue : ofColor::yellow);
	else ofClear(bState1 ? ofColor::black : ofColor::white);

	stringstream s;
	s << "isMouseOver: " << clicker.isMouseOver() << endl;
	s << "isMousePressed(0): " << clicker.isMousePressed(0) << endl;
	s << "isMousePressed(1): " << clicker.isMousePressed(1) << endl;
	s << "isMousePressed(2): " << clicker.isMousePressed(2) << endl;
	s << "getStateChangeMillis(): " << clicker.getStateChangeMillis() << endl;
	s << endl;
	s << "DoubleClick changes color." << endl;
	s << "TripleClick changes RGB / Black&White." << endl;
	s << "number Clicks: " << clicker.clickCounter << endl;
	//NOTE:can't check these easycallbakcs twice on same frame
	//s << "doubleClicked: " << "[" << (obj.isMouseDoubleClick() ? "x" : " ") << "]" << endl;
	//s << "tripleClicked: " << "[" << (obj.isMouseTripleClick() ? "x" : " ") << "]" << endl;
	ofDrawBitmapStringHighlight(s.str(), 10, 30);
}



