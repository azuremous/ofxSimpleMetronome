//
//  ofxSimpleMetronome.cpp
//
//  Created by kim jung un a.k.a azuremous on 6/5/13.
//
//

#include "ofxSimpleMetronome.h"

//--------------------------------------------------------------
/*public */ofxSimpleMetronome::ofxSimpleMetronome()
:bangColor(255,255,0)
,grayColor(90)
,interval(0)
,count(0)
,pos(ofPoint(20, 20))
,bang(false)
,isActive(false)
,appear(true)
{
    leftCircleColor = bangColor;
    rightCircleColor = grayColor;
}

//--------------------------------------------------------------
/*public */ofxSimpleMetronome::~ofxSimpleMetronome(){
    stopThread();
}

//--------------------------------------------------------------
/*public */void ofxSimpleMetronome::setup(int bpm, float numerators, float denominator){
    
    updateTempo(bpm, numerators, denominator);
    
    ofAddListener(ofEvents().draw, this, &ofxSimpleMetronome::render);
    startThread(true);
}

//--------------------------------------------------------------
/*public */void ofxSimpleMetronome::start(){
    isActive = true;
    millis = ofGetElapsedTimeMillis();
}

//--------------------------------------------------------------
/*public */void ofxSimpleMetronome::setPosition(float x, float y){
    pos.set(x, y);
}

//--------------------------------------------------------------
/*public */void ofxSimpleMetronome::updateTempo(int bpm, float numerators, float denominator){
    count = 0;
    beats = numerators;
    unit = denominator;
    setTempo(bpm, unit);
    if(isActive) millis = ofGetElapsedTimeMillis();
}

//--------------------------------------------------------------
/*protected */void ofxSimpleMetronome::threadedFunction(){
    
    while (isThreadRunning() != 0) {
        if (lock()) {
            checkBeat();
            updateColor();
            unlock();
        }
    }
}

//--------------------------------------------------------------
/*protected */void ofxSimpleMetronome::render(ofEventArgs &event){
    if (appear) {
        ofPushMatrix();
        ofTranslate(pos);
        ofSetColor(leftCircleColor);
        ofDrawRectangle(0, 0, 5, 5);
        ofTranslate(10, 0);
        ofSetColor(rightCircleColor);
        ofDrawRectangle(0, 0, 5 ,5);
        ofPopMatrix();
    }
}

//--------------------------------------------------------------
/*protected */void ofxSimpleMetronome::checkBeat(){
    if(isActive && fabs(ofGetElapsedTimeMillis() - millis) >= interval){
        count++;
        bang = !bang;
        if(count > beats) count = 1;
        ofNotifyEvent(beat, count, this);
        millis += interval;
    }
}

//--------------------------------------------------------------
/*protected */void ofxSimpleMetronome::updateColor(){
    if (bang) {
        leftCircleColor = bangColor;
        rightCircleColor = grayColor;
    }else{
        leftCircleColor = grayColor;
        rightCircleColor = bangColor;
    }
}


