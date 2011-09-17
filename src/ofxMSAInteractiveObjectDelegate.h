/*
 *  ofxMSAInteractiveObjectDelegate.h
 *  THIS_Editor
 *
 *  Created by Jim on 9/23/10.
 *  Copyright 2010 FlightPhase. All rights reserved.
 *
 */

#pragma once


#include "ofMain.h"
#include "ofxMSAInteractiveObject.h"

#define		IDLE_COLOR		0xFFFFFF
#define		OVER_COLOR		0x00FF00
#define		DOWN_COLOR		0xFF0000


class ofxMSAInteractiveObjectDelegate 
{
  public:
 	virtual void objectDidRollOver(ofxMSAInteractiveObject* object, int x, int y) = 0;
    virtual void objectDidRollOut(ofxMSAInteractiveObject* object, int x, int y) = 0;
	virtual void objectDidPress(ofxMSAInteractiveObject* object, int x, int y, int button) = 0;	
	virtual void objectDidRelease(ofxMSAInteractiveObject* object, int x, int y, int button) = 0;	
    virtual void objectDidMouseMove(ofxMSAInteractiveObject* object, int x, int y) = 0;
};


class ofxMSAInteractiveObjectWithDelegate : public ofxMSAInteractiveObject {

  public:
	
	ofxMSAInteractiveObjectWithDelegate(){
		delegate = NULL;
	}
	
	void setup() {
		//printf("MyTestObject::setup() - hello!\n");
		enableMouseEvents();
		enableKeyEvents();
	}	
	
	void setDelegate(ofxMSAInteractiveObjectDelegate* _delegate)
	{
		delegate = _delegate;
		if(delegate == NULL) cout << "Setting a DULL delegate" << endl;
		else cout << "set delegate!" << endl;
	}
	
	void exit() {
		//printf("MyTestObject::exit() - goodbye!\n");
	}
	
	
	void update() {
		//		x = ofGetWidth()/2 + cos(ofGetElapsedTimef() * 0.2) * ofGetWidth()/4;
		//		y = ofGetHeight()/2 + sin(ofGetElapsedTimef() * 0.2) * ofGetHeight()/4;
	}
	
	
	void draw() {
        ofPushStyle();
        
		if(isMouseDown()) ofSetColor(DOWN_COLOR);
		else if(isMouseOver()) ofSetColor(OVER_COLOR);
		else ofSetColor(IDLE_COLOR);
		
		ofRect(x, y, width, height);
        
        ofPopStyle();
	}
	
	virtual void onRollOver(int x, int y) {
		if(delegate != NULL){
			delegate->objectDidRollOver(this, x, y);
		}
		//printf("MyTestObject::onRollOver(x: %i, y: %i)\n", x, y);
	}
	
	virtual void onRollOut() {
        if(delegate != NULL){
			delegate->objectDidRollOut(this, x, y);
		}
	}
	
	virtual void onMouseMove(int x, int y){
		if(delegate != NULL){
			delegate->objectDidMouseMove(this, x, y);
		}
	}
	
	virtual void onDragOver(int x, int y, int button) {
		//printf("MyTestObject::onDragOver(x: %i, y: %i, button: %i)\n", x, y, button);
	}
	
	virtual void onDragOutside(int x, int y, int button) {
		//printf("MyTestObject::onDragOutside(x: %i, y: %i, button: %i)\n", x, y, button);
	}
	
	virtual void onPress(int x, int y, int button) {
		if(delegate != NULL){
			delegate->objectDidPress(this, x, y, button);
		}
		//printf("MyTestObject::onPress(x: %i, y: %i, button: %i)\n", x, y, button);
	}
	
	virtual void onRelease(int x, int y, int button) {
		if(delegate != NULL){
			delegate->objectDidRelease(this, x, y, button);
		}
		
		//printf("MyTestObject::onRelease(x: %i, y: %i, button: %i)\n", x, y, button);
	}
	
	virtual void onReleaseOutside(int x, int y, int button) {
		//printf("MyTestObject::onReleaseOutside(x: %i, y: %i, button: %i)\n", x, y, button);
	}
	
	virtual void keyPressed(int key) {
		//printf("MyTestObject::keyPressed(key: %i)\n", key);
	}
	
	virtual void keyReleased(int key) {
		//printf("MyTestObject::keyReleased(key: %i)\n", key);
	}
	
  private:
	ofxMSAInteractiveObjectDelegate* delegate;
};