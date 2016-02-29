//
//  ofxSvgUtil.h
//
//  Created by Yasushi Harada
//
//

#ifndef __ofxSvgUtil__
#define __ofxSvgUtil__

#include "ofMain.h"
#include "ofxSvg.h"

//--------------------------------------------------------------
inline vector<ofPolyline> svgToPolylines(ofxSVG svg) {
    vector<ofPolyline> polylines;

    for (int i = 0; i < svg.getNumPath(); i++){
        ofPath p = svg.getPathAt(i);
        // svg defaults to non zero winding which doesn't look so good as contours
        p.setPolyWindingMode(OF_POLY_WINDING_ODD);
        
        vector<ofPolyline>& lines = const_cast<vector<ofPolyline>&>(p.getOutline());
        for(int j = 0; j < (int)lines.size() ; j++){
            polylines.push_back(lines[j].getResampledBySpacing(1));
        }
    }
    return polylines;
}

#endif /* defined(__ofxSvgUtil__) */

