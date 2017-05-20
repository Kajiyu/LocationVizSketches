#pragma once

#include "ofMain.h"
#include "ofxCsv.h"
#include "ofxImGui.h"
#include "ofxTweenzor.h"
#include "ThemeTest.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofxCsv csv;
    ofCamera camera;
    ofPolyline polyline;
    
    ofxImGui::Gui gui;
    ImVec4 backgroundColor;
    ImVec4 lineColor;
    float camDistance;
    float lineWidth;
    
    bool doSetTheme = false;
    
    ofTrueTypeFont timelineText;
    
    int currentIndex;
    ofVec3f currentPoint;
    int cameraMode;
};
