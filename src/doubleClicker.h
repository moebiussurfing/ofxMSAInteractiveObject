/********  Test sample for ofxInteractiveObject									********/
/********  Make sure you open your console to see all the events being output	********/


#pragma once

#include "ofxMSAInteractiveObject.h"

class doubleClicker : public ofxMSAInteractiveObject {
private:
	ofColor	IDLE_COLOR;
	ofColor	OVER_COLOR;
	ofColor	DOWN_COLOR;
	ofColor	DOUBLE1_COLOR;
	ofColor	DOUBLE2_COLOR;
	ofColor	DOUBLE3_COLOR;
	ofColor	DOUBLE4_COLOR;

	bool bDoubleClicked = false;
	bool bTripleClicked = false;
	int timerClick = 0;
	int timerMin = 50;
	int timerMax = 500;
	bool bDebug = true;
public:
	int clickCounter = 0;
	//--------------------------------------------------------------
	void setDebug(bool b) {
		bDebug = b;
	}
	//--------------------------------------------------------------
	bool isMouseDoubleClick() {
		if (bDoubleClicked) {
			bDoubleClicked = false;
			return true;
		}
		else return false;
	}
	//--------------------------------------------------------------
	bool isMouseTripleClick() {
		if (bTripleClicked) {
			bTripleClicked = false;
			return true;
		}
		else return false;
	}

	void setup() {
		IDLE_COLOR = ofColor(100);
		OVER_COLOR = ofColor(150);
		DOWN_COLOR = ofColor(200);
		DOUBLE1_COLOR = ofColor(ofColor::yellow);
		DOUBLE2_COLOR = ofColor(ofColor::green);
		DOUBLE3_COLOR = ofColor(ofColor::blue);
		DOUBLE4_COLOR = ofColor(ofColor::black);

		ofLogVerbose(__FUNCTION__) << "hello!\n";
		enableMouseEvents();
		enableKeyEvents();
	}


	void exit() {
		ofLogVerbose(__FUNCTION__) << "goodbye!\n";
	}


	void update() {
		//x = ofGetWidth()/2 + cos(ofGetElapsedTimef() * 0.2) * ofGetWidth()/4;
		//y = ofGetHeight()/2 + sin(ofGetElapsedTimef() * 0.2) * ofGetHeight()/4;
	}


	void draw() {
		if (isMousePressed()) ofSetColor(DOWN_COLOR);
		else if (isMouseOver()) ofSetColor(OVER_COLOR);
		//else ofSetColor(IDLE_COLOR);

		ofColor c;

		auto t = ofGetElapsedTimeMillis();

		switch (clickCounter)
		{

		case 0: ofSetColor(IDLE_COLOR); break;
		case 1:
		{
			ofSetColor(DOUBLE1_COLOR);
			if (t - timerClick > timerMax) clickCounter = 0;
		}
		break;

		case 2:
		{
			ofSetColor(DOUBLE2_COLOR);
			if (t - timerClick > timerMax) clickCounter = 0;
		}
		break;

		case 3:
		{
			ofSetColor(DOUBLE3_COLOR);
			if (t - timerClick > timerMax) clickCounter = 4;
		}
		break;

		case 4:
		{
			ofSetColor(DOUBLE4_COLOR);
			clickCounter = 0;
		}
		break;

		}

		if (bDebug) ofRect(x, y, width, height);
	}

	virtual void onRollOver(int x, int y) {
		ofLogVerbose(__FUNCTION__) << x << y;
	}

	virtual void onRollOut() {
		ofLogVerbose(__FUNCTION__);
	}

	virtual void onMouseMove(int x, int y) {
		ofLogVerbose(__FUNCTION__) << x << y;
	}

	virtual void onDragOver(int x, int y, int button) {
		ofLogVerbose(__FUNCTION__) << x << y << button;
	}

	virtual void onDragOutside(int x, int y, int button) {
		ofLogVerbose(__FUNCTION__) << x << y << button;
	}

	virtual void onPress(int x, int y, int button) {
		ofLogVerbose(__FUNCTION__) << x << y << button;

		auto t = ofGetElapsedTimeMillis();
		timerClick = t;

		if (clickCounter == 0) {
			clickCounter++;
		}
		else if (clickCounter == 1) {
			if (t - timerClick > timerMin) clickCounter++;
			clickCounter++;
			bDoubleClicked = true;
		}
		else if (clickCounter == 2) {
			if (t - timerClick > timerMin) clickCounter++;
			clickCounter++;
			bTripleClicked = true;
		}
		else if (clickCounter == 3) {
			clickCounter++;
		}
	}

	virtual void onRelease(int x, int y, int button) {
		ofLogVerbose(__FUNCTION__) << x << y << button;
	}

	virtual void onReleaseOutside(int x, int y, int button) {
		ofLogVerbose(__FUNCTION__) << x << y << button;
	}

	virtual void keyPressed(int key) {
		ofLogVerbose(__FUNCTION__) << key;
	}

	virtual void keyReleased(int key) {
		ofLogVerbose(__FUNCTION__) << key;
	}

};