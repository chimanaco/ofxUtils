#include "ofxEasyTimer.h"

//--------------------------------------------------------------
ofxEasyTimer::ofxEasyTimer(){
}

//--------------------------------------------------------------
void ofxEasyTimer::setTimerSeconds(int sec, bool isLoop){
    setTimer(sec, isLoop);
}

//--------------------------------------------------------------
void ofxEasyTimer::setTimer(int sec, bool isLoop){
    this->isLoop = isLoop;
    isPlaying = true;
    limit = sec;
    start = ofGetElapsedTimef();
    cout << "start Timer! \n"; // prints Output sentence on screen
}

//--------------------------------------------------------------
void ofxEasyTimer::update(){
    float elapsedTimef = ofGetElapsedTimef();
    float currentTime = elapsedTimef;
    
    if( (currentTime - start) > limit) {
        if(isPlaying) {
            sendEvent(currentTime);
            if(isLoop) {
                start = elapsedTimef;
            } else {
                isPlaying = false;
            }
        }
    } else {
    }
}

//--------------------------------------------------------------
void ofxEasyTimer::stop(){
    start = 0;
}

//--------------------------------------------------------------
void ofxEasyTimer::sendEvent(float currentTime){
    ofNotifyEvent(isCompleted, currentTime, this);
}

//--------------------------------------------------------------
bool ofxEasyTimer::getIsLoop(){
    return isLoop;
}

//--------------------------------------------------------------
bool ofxEasyTimer::getStatus(){
    return isPlaying;
}

/* EOF */