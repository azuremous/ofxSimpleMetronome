//
//  ofxSimpleMetronome.cpp
//
//  Created by kim jung un on 6/5/13.
//  Copyright (c) 2012 azuremous.net All rights reserved.
//

#include "ofxSimpleMetronome.h"


//--------------------------------------------------------------
/*public */ofxSimpleMetronome::ofxSimpleMetronome()
:bangColor(255,255,0)
,grayColor(90)
,bang(false)
,lastBang(false)
,appear(true)
{
    leftCircleColor = bangColor;
    rightCircleColor = grayColor;
}

//--------------------------------------------------------------
/*public */ofxSimpleMetronome::~ofxSimpleMetronome(){}

//--------------------------------------------------------------
/*public */void ofxSimpleMetronome::setup(int bpm, float x, float y){
    
    setTempo(bpm);
    millis = ofGetElapsedTimeMillis();
    posRect.set(x, y, 0, 0);
    
    ofAddListener(ofEvents().draw, this, &ofxSimpleMetronome::render);
}

//--------------------------------------------------------------
/*public */void ofxSimpleMetronome::threadedFunction(){
    
    while (isThreadRunning() != 0) {
        if (lock()) {
            checkBang();
            if(bang != lastBang){
                lastBang = !lastBang;
                ofNotifyEvent(bangAlert, lastBang, this);
            }
            
            if (bang) {
                leftCircleColor = bangColor;
                rightCircleColor = grayColor;
            }else{
                leftCircleColor = grayColor;
                rightCircleColor = bangColor;
            }
            unlock();
        }
    }
}

//--------------------------------------------------------------
/*public */void ofxSimpleMetronome::render(ofEventArgs &event){
    if (appear) {
        ofPushMatrix();
        ofTranslate(posRect.x, posRect.y);
        ofSetColor(leftCircleColor);
        ofRect(0, 0, 5, 5);
        ofTranslate(10, 0);
        ofSetColor(rightCircleColor);
        ofRect(0, 0, 5 ,5);
        ofPopMatrix();
    }
}

//--------------------------------------------------------------
/*protected */bool ofxSimpleMetronome::checkBang(){
    
    if (fabs(ofGetElapsedTimeMillis() - millis) >= speed) {
        
        bang = !bang;
        millis += speed ;
        return true;
    }
    return false;
}


