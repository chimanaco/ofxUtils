//
//  ofxEasyMathUtil.h
//
//  Created by Yasushi Harada
//
//

#ifndef __ofxEasyMathUtil__
#define __ofxEasyMathUtil__

#include "ofMain.h"

//--------------------------------------------------------------
inline string addZeroToSingleDegit(int num){
    string str = to_string(num);
    if(num < 10) {
        str = "0" + str;
    }
    return str;
}

//--------------------------------------------------------------
inline int getRandomInt(int num){
    int randomNum = floor(ofRandom(num));
    return randomNum;
}

//--------------------------------------------------------------
inline int getZeroIfGreaterThanMaxValue(int currentValue, int maxValue){
    int value = currentValue;
    int max = maxValue;
    if(value > max) {
        value = 0;
    }
    return value;
}

//--------------------------------------------------------------
template<typename T>
inline vector<T> addNewValueAndEraseFirstValue(vector<T>& values, const T& newValue){
    // add new elements:
    values.push_back(newValue);
    // erase the first elements:
    values.erase (values.begin());
    return values;
}

// FIXME: Error when put floats without f. (double or float or something....)
//--------------------------------------------------------------
template<typename T>
inline bool checkIfExistsInVector(const vector<T>& values, const T& newValue) {
    bool isExist = false;
    for(int i = 0; i < values.size(); i++) {
        T valueExists = values[i];
        if( valueExists == newValue) {
            isExist = true;
        }
    }
    return isExist;
}

/* 3D */

//--------------------------------------------------------------
inline ofVec3f latLonToSphericalCoordinates(float latitude, float longitude, float radius) {
    float x, y, z;
    float phi = (latitude) * M_PI / 180;
    float theta = (longitude - 180) * M_PI / 180;
    x = -(radius) * cos(phi) * cos(theta);
    y = (radius) * sin(phi);
    z = (radius) * cos(phi) * sin(theta);
    
    return ofVec3f(x, y, z);
}


#endif /* defined(__ofxEasyMathUtil__) */

