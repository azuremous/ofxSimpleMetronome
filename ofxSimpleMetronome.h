//
//  ofxSimpleMetronome.h
//  ofxSimpleMetronome
//
//  Created by kim jung un a.k.a azuremous on 4/25/12.
//  Copyright (c) 2012 azuremous.net All rights reserved.
//

#ifndef emptyExample_ofxSimpleMetronome_h
#define emptyExample_ofxSimpleMetronome_h

#include "ofMain.h"

class metronome {
    
private:
    
    ofColor bangColor;
    ofColor grayColor;
    ofColor leftCircleColor;
    ofColor rightCircleColor;
    
    int speed;
    int millis;
    
    bool bang;
    ofRectangle posRect;
    
public:
    
    bool start;
    
    metronome():bangColor(255,255,0),grayColor(90),bang(false),start(false)
    {
        
        leftCircleColor = bangColor;
        rightCircleColor = grayColor;
        
    }
    void setup(int bpm , float x, float y){
        
        setTempo(bpm);
        millis = ofGetElapsedTimeMillis();
        posRect.set(x, y, 0, 0);
        
        ofAddListener(ofEvents.update, this, &metronome::update);
        ofAddListener(ofEvents.draw, this, &metronome::render);
        
    }
    
    void setTempo(int bpm){
        
        speed = (int)(60000 / bpm);
        
    }
    
    bool checkBang(){
        
        if (abs(ofGetElapsedTimeMillis() - millis) >= speed) {
            
            bang = !bang;
            
            millis += speed ;
            
            return true;
        }
        return false;
    }
    
    void update(ofEventArgs &event){
        
        if (start) {
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
    void render(ofEventArgs &event){
        
        ofPushMatrix();
        ofTranslate(posRect.x, posRect.y);
        ofSetColor(leftCircleColor);
        ofRect(0, 0, 5, 5);
        ofTranslate(10, 0);
        ofSetColor(rightCircleColor);
        ofRect(0, 0, 5 ,5);
        ofPopMatrix();
    }
    
    bool getBang()const{
        
        return bang;
    }
};



#endif
