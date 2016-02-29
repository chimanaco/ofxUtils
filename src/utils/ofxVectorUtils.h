//
//  ofxVectorUtil.h
//
//  Created by Yasushi Harada
//
//

#ifndef __ofxVectorUtil__
#define __ofxVectorUtil__

//--------------------------------------------------------------
template<typename T>
inline vector<shared_ptr<T>> pushFirstVectorElementToLast( vector<shared_ptr<T>> vec) {
    vector<shared_ptr<T> > tempVec;
    
    for(int i = 0; i < vec.size(); i++) {
        auto p = vec[i];
        tempVec.push_back(p);
    }
    
    for(int i = 0; i < vec.size(); i++) {
        if(i == vec.size() - 1) {
            vec[i] = tempVec[0];
        } else {
            vec[i] = tempVec[i + 1];
        }
    }
    
    tempVec.clear();
    return vec;
}

#endif /* defined(__ofxVectorUtil__) */

