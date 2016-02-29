//
//  ofxFileUtil.h
//
//  Created by Yasushi Harada
//
//

#ifndef __ofxFileUtil__
#define __ofxFileUtil__

//--------------------------------------------------------------
inline ofDirectory getDirectory(string pathString, string extensionString) {
    //some path, may be absolute or relative to bin/data
    string path = pathString;
    ofDirectory dir(path);
    //only show mov files
    dir.allowExt(extensionString);
    //populate the directory object
    dir.listDir();
    
    return dir;
}

//--------------------------------------------------------------
template<typename T>
inline string getType(const T& value) {
    string type = typeid(value).name();
    return type;
}

#endif /* defined(__ofxFileUtil__) */

