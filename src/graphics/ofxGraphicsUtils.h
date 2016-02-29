//
//  ofxGraphicsUtil.h
//
//  Created by Yasushi Harada
//
//

#ifndef __ofxGraphicsUtil__
#define __ofxGraphicsUtil__

//--------------------------------------------------------------
inline void loadDisabledArbTex(ofImage &img, string fileName){
    // use old fashioned texture coordinates
    ofDisableArbTex();
    img.load(fileName);
    // use default
    ofEnableArbTex();
}

//--------------------------------------------------------------
inline void loadDAT(shared_ptr<ofImage> img, string fileName){
    // use old fashioned texture coordinates
    ofDisableArbTex();
    img->load(fileName);
    // use default
    ofEnableArbTex();
}

//--------------------------------------------------------------
inline void ofDrawRectangleWithCenteredOrigin(float x, float y, float w, float h){
    ofPushMatrix();
    ofTranslate(x, y);
    ofDrawRectangle(- w / 2, - h / 2, w, h);
    ofPopMatrix();
}

/* ofPoint, ofPolyline */

//--------------------------------------------------------------
inline vector<ofPoint> polylinesToPoints(vector<ofPolyline> polylines) {
    vector<ofPoint> points;
    for(int k = 0; k < polylines.size(); k++){
        vector<ofPoint> p;
        p = polylines[k].getVertices();
        for(int h = 0; h < p.size(); h++){
            points.push_back(p[h]);
        }
    }
    return points;
}

/* Mesh */

//--------------------------------------------------------------
inline void setTexCoordToMesh(ofMesh &mesh, ofImage &tex){
    for (int i = 0; i < mesh.getVertices().size(); i++) {
        ofVec2f texCoord = mesh.getTexCoord(i);
        texCoord.x *= tex.getWidth();
        texCoord.y = (1.0 - texCoord.y) * tex.getHeight();
        mesh.setTexCoord(i, texCoord);
    }
}


/* Font */

//--------------------------------------------------------------
inline void drawTrueTypeWithCenteredOrigin(ofTrueTypeFont &font, string str){
    ofPushMatrix();
    ofRectangle bounds = font.getStringBoundingBox(str, 0, 0);
    ofTranslate(- bounds.width / 2, - bounds.height / 2, 0);
    font.drawString(str, 0, 0 );
    ofPopMatrix();
}



#endif /* defined(__ofxGraphicsUtil__) */

