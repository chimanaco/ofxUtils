//
//  ofxEasyTimer.h
//
//  Created by Yasushi Harada
//
//

#ifndef __ofxEasyTimer__
#define __ofxEasyTimer__


#include "ofMain.h"

class ofxEasyTimer
{
public:
    ofxEasyTimer();
    void setTimerSeconds(int sec, bool isLoop);
    void setTimer(int sec, bool isLoop);
    void sendEvent(float currentTime);
    bool getStatus();
    bool getIsLoop();
    void update();
    void stop();
    
    ofEvent<float> isCompleted;  // will send an event with a float
    
    float start;
    float goal;
    int limit;
    bool isLoop;

private:
    bool isPlaying;
};

#endif /* defined(__ofxEasyTimer__) */
