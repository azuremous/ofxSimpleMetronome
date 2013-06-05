//
//  ofxSimpleMetronome.cpp
//
//  Created by kim jung un on 6/5/13.
//  Copyright (c) 2012 azuremous.net All rights reserved.
//

#include "ofxSimpleMetronome.h"


//--------------------------------------------------------------
/*public */ofxMetronome::ofxMetronome()
:bangColor(255,255,0)
,grayColor(90)
,bang(false)
,startMetro(false)
,appear(true)
{
    leftCircleColor = bangColor;
    rightCircleColor = grayColor;
}

//--------------------------------------------------------------
/*public */ofxMetronome::~ofxMetronome(){}

//--------------------------------------------------------------
/*public */void ofxMetronome::setup(int bpm, float x, float y){
    
    setTempo(bpm);
    millis = ofGetElapsedTimeMillis();
    posRect.set(x, y, 0, 0);
    
    ofAddListener(ofEvents().update, this, &ofxMetronome::update);
    ofAddListener(ofEvents().draw, this, &ofxMetronome::render);
    
}

//--------------------------------------------------------------
/*public */void ofxMetronome::update(ofEventArgs &event){
    
    if (startMetro) {
        checkBang();
        if (bang) {
            leftCircleColor = bangColor;
            rightCircleColor = grayColor;
        }else{
            leftCircleColor = grayColor;
            rightCircleColor = bangColor;
        }
    }
}

//--------------------------------------------------------------
/*public */void ofxMetronome::render(ofEventArgs &event){
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
/*protected */bool ofxMetronome::checkBang(){
    
    if (fabs(ofGetElapsedTimeMillis() - millis) >= speed) {
        
        bang = !bang;
        millis += speed ;
        return true;
    }
    return false;
}


