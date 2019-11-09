#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    font.load("ArchivoBlack-Regular.ttf", 60, true, true, true);
    fontSmall.load("HelveticaNeueDeskInterface.ttc", 10, true, true, true);
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
    float xOffset = 0;
    
    if (isInit == false) {
        ofRectangle empty = fontSmall.getStringBoundingBox("type something", 0, 0);
        ofPushMatrix();
        fontSmall.drawString("type something", width/2 - (empty.getMax().x - empty.getMin().x)/2, 200);
        ofPopMatrix();
    }
    
    ofPushMatrix();
    ofTranslate((width - letters.size() * 45)/2, 200, 0);
    ofSetLineWidth(2);
    ofRectangle bbox;
    
    ofDisableAlphaBlending();
    ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
    
    for (int i = 0; i < numLetters; i++){
        string letter = input.substr(i, 1);
        
        if (timer[i] > 15) {
            ofSetColor(255, 215, 40, 180);
            ofPushMatrix();
            ofTranslate(xOffset, ofMap(timer[i], 15, 90, 0, -10));
            font.drawString(letter, 0, 0);
            ofPopMatrix();
        }
        
        ofSetColor(240, 81, 0, 180);
        ofPushMatrix();
        ofTranslate(xOffset, 0);
        font.drawString(letter, 0, 0);
        ofPopMatrix();
        
        if (timer[i] > 15) {
            ofSetColor(33, 149, 205, 180);
            ofPushMatrix();
            ofTranslate(xOffset, ofMap(timer[i], 15, 90, 0, 10));
            font.drawString(letter, 0, 0);
            ofPopMatrix();
        }
        
        if (timer[i] < 90) {
            timer[i] += 3;
        }
        
        xOffset += font.getStringBoundingBox(input.substr(i, 1), 0, 0).width;
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


