#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    myMetronome.setup(30,4);
    myMetronome.start();
    
    ofAddListener(myMetronome.beat,
                  this,
                  &ofApp::onBeat);
    
    beats.load("click.mp3");
    beats.setMultiPlay(true);
    beats2.load("cow-bell.mp3");
    beats2.setMultiPlay(true);
    
}
//--------------------------------------------------------------

void ofApp::onBeat(int & count){
    
    if(count==1){
        beats2.play();
        cout << "beats 1" << endl;
    }
    
    if(count!=1){
        beats.play();
        cout << "beats 0" << endl;
    }
}


//--------------------------------------------------------------
void ofApp::update(){
    ofSoundUpdate();
}

//--------------------------------------------------------------
void ofApp::draw(){
    //
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
