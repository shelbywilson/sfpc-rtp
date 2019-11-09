#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    font.load("SFCompactText-Regular.otf", 16, true, true, true);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    
    vector < ofPath > letters = font.getStringAsPoints(input, true, false);
    float height = ofGetHeight();
    float width = ofGetWidth() - 6;
    
    int numLetters = letters.size();
    float rH = 100; //MAX((1/(numLetters + 1)) * height/3, 200);
    
//    ofDisableAlphaBlending();
//    ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);

    for (int i = 0; i < numLetters; i++){
        if (timer[i] < 90) {
            timer[i]++;
        }
        
        if ((int)input.at(i) % 3 == 1) {
            ofSetColor(255, 0, 0, 150);
        } else if ((int)input.at(i) % 3 == 2) {
            ofSetColor(0, 0, 255, 150);
        } else {
            ofSetColor(255, 255, 0, 150);
        }
        
        vector < ofPolyline > lines = letters[i].getOutline();
        
        float numPoints = 0;
        
        for (int j = 0; j < lines.size(); j++){            
            numPoints += lines[j].size();
        }
        
        float y;
        
        if (numLetters == 1) {
            y = height/2;
        } else {
            y = height * ((float)i/(numLetters - 1));
        }
        y -= rH/2;
        
       // lines[i].draw();
        
        for (int j = 0; j < numPoints; j ++) {
            ofPushMatrix();
//            ofTranslate(cos(timer[i] * PI/180) * (width * j/(numPoints - 1)), y);
            ofTranslate(ofMap(cos(timer[i] * PI/180), 1, 0, width/2, (width * j/(numPoints - 1))), y);
            
            ofDrawRectangle(0,0,6,rH);
            
            ofPopMatrix();
        }
    }
    
    for (int i = 0; i < numLetters; i++){
        float y;
        
        if (numLetters == 1) {
            y = height/2;
        } else {
            y = height * ((float)i/(numLetters - 1));
        }
        y -= rH/2;
        
        ofPushMatrix();
        ofTranslate(10, MAX(40, y + rH/2));
        ofSetColor(0,0,0, 150);
        std::string s(1, input.at(i));
        font.drawString(s, 0, 0);
        ofPopMatrix();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    input.append(1, (char)key);
    timer.push_back(0);
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
