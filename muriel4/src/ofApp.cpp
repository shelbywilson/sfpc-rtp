#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    font.load("ArchivoBlack-Regular.ttf", 100, true, true, true);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    ofSetColor(255, 0, 0);
    
    vector < ofPath > letters = font.getStringAsPoints(input, true, false);
    float height = ofGetHeight() - 50;
    float width = ofGetWidth() - 50;
    float numLetters = (float)letters.size();
    
    ofPushMatrix();
    ofTranslate((width - letters.size() * 80)/2, 200, 0);
    ofSetLineWidth(2);
    ofRectangle bbox;
    
    ofSetColor(255, 0, 0, 180);
    
    for (int i = 0; i < numLetters; i++){
        
        vector < ofPolyline > lines = letters[i].getOutline();
        
        if (timer[i] < 90) {
            timer[i] += 3;
        }
        
        ofPushMatrix();
        ofRotateZDeg(cos(timer[i]));
        
       for (int j = 0; j < lines.size(); j ++) {
           lines[j].draw();
           
           for (int k = 1; k < 5; k ++) {
               ofPolyline temp = lines[j].getSmoothed(k);
               temp.draw();
           }
        }
        
        ofPopMatrix();
    }
    
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == OF_KEY_DEL || key == OF_KEY_BACKSPACE){
        input = input.substr(0, input.length()-1);
        
        timer.pop_back();
    } else if(key != OF_KEY_RETURN && key > 31 && key != 3681){
        isInit = true;
        input.append(1, (char)key);
        
        timer.push_back(0);
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
