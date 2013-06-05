//
//  ofxSimpleMetronome.h
//
//  Created by kim jung un a.k.a azuremous on 4/25/12.
//  Copyright (c) 2012 azuremous.net All rights reserved.
//

#pragma once

#include "ofMain.h"

class ofxMetronome {
    
private:
    
    ofColor bangColor;
    ofColor grayColor;
    ofColor leftCircleColor;
    ofColor rightCircleColor;
    
    int speed;
    int millis;
    
    bool bang;
    bool startMetro;
    bool appear;
    ofRectangle posRect;
    
protected:
    void setTempo(int bpm){ speed = (int)(60000 / bpm); }
    bool checkBang();
    
public:
    
    explicit ofxMetronome();
    virtual~ofxMetronome();
    void setup(int bpm , float x, float y);
    void start(){ startMetro = true; }
    void stop(){ startMetro = false; }
    void show(){ appear = true; }
    void hide(){ appear = false; }
    void showToggle(){ appear = !appear; }
    void updateTempo(int bpm){ setTempo(bpm); }
    void update(ofEventArgs &event);
    void render(ofEventArgs &event);
    bool getBang()const{ return bang; }
};
