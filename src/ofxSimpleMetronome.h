//
//  ofxSimpleMetronome.h
//
//  Created by kim jung un a.k.a azuremous on 4/25/12.
//  Copyright (c) 2012 azuremous.net All rights reserved.
//

#pragma once

#include "ofMain.h"

class ofxSimpleMetronome: public ofThread {
    
private:
    
    ofColor bangColor;
    ofColor grayColor;
    ofColor leftCircleColor;
    ofColor rightCircleColor;
    
    int speed;
    int millis;
    
    bool bang;
    bool lastBang;
    bool appear;
    ofRectangle posRect;
    
protected:
    void setTempo(int bpm){ speed = (int)(60000 / bpm); }
    bool checkBang();
    
public:
    ofEvent<bool> bangAlert;
    explicit ofxSimpleMetronome();
    virtual~ofxSimpleMetronome();
    void setup(int bpm , float x, float y);
    void start(bool _verbose = false){ startThread(true, _verbose); }
    void stop(){ stopThread(); }
    void threadedFunction();
    void show(){ appear = true; }
    void hide(){ appear = false; }
    void showToggle(){ appear = !appear; }
    void updateTempo(int bpm){ setTempo(bpm); }
    void render(ofEventArgs &event);
    void sendBang(bool &b);
};
