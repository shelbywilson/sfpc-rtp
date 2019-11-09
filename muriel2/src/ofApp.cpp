#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    font.load("Avenir Next.ttc", 60, true, true, true);
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    
    vector < ofPath > letters = font.getStringAsPoints(input, true, false);
    float height = ofGetHeight() - 50;
    float width = ofGetWidth() - 50;
    
    ofPushMatrix();
    ofTranslate(25, 200, 0);
    ofSetLineWidth(2);
    
    float numLetters = (float)letters.size();
    
    for (int i = 0; i < numLetters; i++){
        
        vector < ofPolyline > lines = letters[i].getOutline();
        
        if (timer[i] < 90) {
            timer[i]++;
        }
        
        for (int j = 0; j < lines.size(); j ++) {
            
            ofSetColor(0, 0, 255, 180);
            lines[j].draw();
            
            ofSetColor(255, 0, 0, 180);
            ofPolyline temp = lines[j].getResampledBySpacing(40);
            
            for (int k = 0; k < temp.size(); k ++) {
                temp[k].y = cos(timer[i] * PI/180) * temp[k].y;

                temp.draw();
            }
            
            
        }
    }
    
    ofPopMatrix();
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
