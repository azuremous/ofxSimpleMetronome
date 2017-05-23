//
//  ofxSimpleMetronome.h
//
//  Created by kim jung un a.k.a azuremous on 4/25/12.
//
//

#pragma once

#include "ofMain.h"

class ofxSimpleMetronome: public ofThread {
    
private:
    ofPoint pos;
    
    ofColor bangColor;
    ofColor grayColor;
    ofColor leftCircleColor;
    ofColor rightCircleColor;
    
    float unit;
    float beats;
    int count;
    
    int interval;
    int millis;
    
    bool bang;
    bool isActive;
    bool appear;
    
protected:
    void checkBeat();
    void checkCount();
    void updateColor();
    void threadedFunction();
    void setTempo(int bpm, float unit){ interval = (int)(60 * 1000 / bpm) / (unit / 4.); }
    void render(ofEventArgs &event);
    
    
public:
    ofEvent<int>beat;
    
    explicit ofxSimpleMetronome();
    virtual~ofxSimpleMetronome();
    
    void setup(int bpm , float numerators = 4, float denominator = 4);
    void setPosition(float x, float y);
    void start();
    void pause(){ isActive = false; }
    
    void show(){ appear = true; }
    void hide(){ appear = false; }
    void showToggle(){ appear = !appear; }
    
    void updateTempo(int bpm, float numerators = 4, float denominator = 4);
    
};
