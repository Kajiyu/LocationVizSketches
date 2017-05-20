#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetLogLevel(OF_LOG_VERBOSE);
    
    // GUI
    gui.setup();
    ImGui::GetIO().MouseDrawCursor = false;
    backgroundColor = ofColor(30, 30, 30, 255);
    lineColor = ofColor(230, 230, 230, 100);
    
    //Camera
    camDistance = 30.0f;
    
    
    
    //CSV
    csv.load("location_03150520.csv", ",");
    currentIndex = 0;
    
    cameraMode = 1;
    
    timelineText.load("MyriadHebrew-Regular.otf", 20);
}

//--------------------------------------------------------------
void ofApp::update(){
    if(doSetTheme)
    {
        doSetTheme = false;
        gui.setTheme(new ThemeTest());
    }
    
    
    if (currentIndex >= csv.getNumRows()) {
        currentIndex = 0;
        polyline.clear();
    }
    float x = csv.getRow(currentIndex).getFloat(1) * 1000;
    float y = csv.getRow(currentIndex).getFloat(2) * 1000;
    float z = ofGetFrameNum()*0.05;
    currentPoint = ofVec3f(x, y, z);
    if (cameraMode == 1) {
        camera.lookAt(ofVec3f(x, y, z));
        camera.setPosition(x+camDistance*cos(ofGetElapsedTimef()*0.3-0.4), y+camDistance*sin(ofGetElapsedTimef()*0.3 - 0.4), z +30);
    } else if (cameraMode == 2) {
        camera.lookAt(ofVec3f(x, y, z));
        camera.setPosition(x, y, z + camDistance);
    } else if (cameraMode == 3) {
        camera.lookAt(ofVec3f(x, y, z));
        camera.setPosition(x+camDistance, y, z);
    }
    if (polyline.getVertices().size() > 0) {
        polyline.curveTo(x, y, z);
    } else {
        polyline.addVertex(x, y, z);
    }
    currentIndex++;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetBackgroundColor(backgroundColor);
    ofSetLineWidth(lineWidth);
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
    
    gui.begin();
    
    {
        ImGui::Text("Hello, world!");
        ImGui::SliderFloat("Camera Distance", &camDistance, 0.0f, 100.0f);
        ImGui::SliderFloat("Line Width", &lineWidth, 0.0f, 7.0f);
        
        //this will change the app background color
        ImGui::ColorEdit3("Background Color", (float*)&backgroundColor);
        ImGui::ColorEdit4("LineColor", (float*)&lineColor);
        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
    }
    
    gui.end();
    
    camera.begin();
    ofSetColor(lineColor);
    polyline.draw();
    ofSetColor(0, 255, 0);
    ofDrawSphere(currentPoint, 0.8);
    camera.end();
    
    ofSetColor(255, 255);
    timelineText.drawString(csv.getRow(currentIndex).getString(0), ofGetWidth()*4/5, 40);
    timelineText.drawString("Longitude :: " + csv.getRow(currentIndex).getString(1), ofGetWidth()*4/5, 70);
    timelineText.drawString("Latitude :: " + csv.getRow(currentIndex).getString(2), ofGetWidth()*4/5, 100);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == '1') {
        cameraMode = 1;
    } else if (key == '2') {
        cameraMode = 2;
    } else if (key == '3') {
        cameraMode = 3;
    }
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
