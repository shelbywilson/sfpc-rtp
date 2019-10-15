#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    ofSetColor(0);
    
    ofSeedRandom(mouseX * 1000);
    
    //carresNoir();
    //shallWeTakeAWalk();
    //untitled6_1972();
    //grisSurArgent();
    //dispersesParLeVentAuLarge();
    //hommageADurer();
    hommageADurer1990();
}

//--------------------------------------------------------------
// 25 carres noir
void ofApp::carresNoir() {
    int height = 768;
    int width = 1024;
    
    int margin = 80;
    int sq = MAX(mouseX%20 + 3, 3);
    int sqSize = (height - margin)/sq;
    
    ofSetColor(sq*7,0,0,150);
    
    for (int i = 0; i < sq; i++) {
        for (int j = 0; j < sq; j ++) {
            ofPushMatrix();
            ofTranslate((i * sqSize * 0.9) + ofRandom(-sqSize/10,sqSize/10) + ((width-height)/2) + margin/2 + sqSize/3, j * sqSize + ofRandom(0,sqSize/3) + margin/2 + sqSize/3);
            ofDrawBox(0, 0, 0, sqSize, sqSize, 0);
            ofPopMatrix();
        }
    }
}

//--------------------------------------------------------------
// gris sur argent
void ofApp::grisSurArgent() {
    int height = 768;
    int width = 1024;
    
    int margin = 80;
    int sq = MAX(mouseX%12 + 3, 3);
    int sqSize = ((height - margin)/sq);
    int sqStep = sqSize/6;
    
//    ofBackground(234,226,215);
//    ofSetColor(228,231,235);
//    ofPushMatrix();
//    ofTranslate((width-height)/2, 0);
//    ofDrawRectangle(0, 0, width-(width-height), height);
//    ofPopMatrix();
    
    for (int i = 0; i < sq; i++) {
        for (int j = 0; j < sq; j ++) {
            int b = (sq - j - 1) * (255/sq+1);
            ofSetColor(b - 20, b - 10, b,190);
            ofPushMatrix();
            ofTranslate((i * sqSize) + (width-height)/2 + margin/2, (j * sqSize) + margin/2);
            ofDrawRectangle(0, ofRandom(-sqStep/2,sqStep/2), sqSize - sqStep, sqSize - sqStep);
            ofPopMatrix();
        }
    }
}

//--------------------------------------------------------------
// dispersés par le vent au large, 1999
void ofApp::dispersesParLeVentAuLarge() {
    int height = 768;
    int width = 1024;
    
    int margin = 10;
    int sq = MAX(mouseX%30 + 3, 3);
    int sqSize = ((height - margin)/sq);
    int sqStep = sqSize/6;
    
    ofBackground(230);
    ofDisableAlphaBlending();
    ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
    
    
    for (int i = 0; i < sq; i++) {
        for (int j = 0; j < sq; j ++) {
            ofPushMatrix();
            ofTranslate((i * sqSize) + (width-height)/2 + margin/2 + (ofNoise(i,j) * sqSize), (j * sqSize) + margin/2 + (ofNoise(i,j) * sqSize));
            ofRotate(ofRandom(-30,30));
            //ofFill();
            ofSetColor(160,24,38);
            ofDrawRectangle(0, -sqSize/2, sqSize - 5, sqSize - 5);
            ofPopMatrix();
        }
    }
}

//--------------------------------------------------------------
// shall we take a walk
void ofApp::shallWeTakeAWalk() {
    int width = 1024;
    int height = 768;
    int midY = height/2;
    int prevX = 0;
    int prevY = midY;
    int x = 0;
    int y = 0;
    
    ofBackground(45,46,143);
    ofSetColor(41, 89, 170);
    ofSetLineWidth(3);
    
    while (x < width) {
        x += ofRandom(-20, 50);
        y = ofRandom(-80, 80) + midY;
        ofDrawLine(prevX, prevY, x, y);
        
        prevX = x;
        prevY = y;
    }
}

//--------------------------------------------------------------
// untitled (6) (1972)
void ofApp::untitled6_1972() {
    int width = 1024;
    int height = 768;
    int marginX = width - height;
    int marginY = 160;
    int verticalStep = (height - marginY) / 19;
    int x1 = 0;
    int x2 = 0;
    int y = 0;
    int temp = 0;
    int maxX = width - marginX/2;
    
    for (int i = 0; i < 20; i += 1) {
        y = i * verticalStep + marginY/2;
        x1 = marginX/2 + ofRandom(-marginX/4, marginX/2);
        x2 = ofRandom(x1 + 300, width - marginX/2 + ofRandom(-marginX/2, marginX/4));
        ofDrawLine(x1, y, x2, y);
        
        x2 += ofRandom(20, width/2);
        
        while (x2 < maxX - 40) {
            temp = ofRandom(15, 30);
            ofDrawLine(x2, y, x2 + temp, y);
            x2 += temp;
            x2 += ofRandom(20, width/2);
        }
    }
}

//--------------------------------------------------------------
// hommage à dürer, disparition
void ofApp::hommageADurer() {
    int height = 768;
    int width = 1024;
    int marginX = 20 + (width - height)/2;
    int sq = (height - 50) /10;
    
    ofBackground(255,255,255);
    ofSetColor(0,0,0);
    ofSetLineWidth(3);
    
    for (int i = 10; i > 0; i--) {
        for (int j = 10; j > 0; j --) {
            int oX = (10 - j) * sq + 5 + marginX;
            int oY = (10 - i + 1) * sq + 20;
            int prevX = 0;
            int prevY = 0;
            
            int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
            int n = sizeof(arr) / sizeof(arr[0]);
            for (int x = n - 1; x > 1; x--)
            {
                int z = ofRandom(0,x);
                
                int* a = &arr[x];
                int* b = &arr[z];
                int temp = *a;
                *a = *b;
                *b = temp;
            }
            
            for (int k = 0; k < i + 1; k ++)
            {
                int r = arr[k];
                int x = (sq/4) * (r%4);
                int y = (-sq/4) * floor(r/4);
                ofDrawLine(prevX + oX, prevY + oY, x + oX, y + oY);
                
                prevX = x;
                prevY = y;
            }
        }
    }
}

//--------------------------------------------------------------
// hommage à dürer, 1990
void ofApp::hommageADurer1990() {
    int height = 768;
    int width = 1024;
    int sq = (height - 50) /6;
    
    int marginX = 35 + (width - ((sq + 5) * 8)) /2;
    
    ofBackground(238,239,244);
    ofSetColor(232,125,130);
    ofSetLineWidth(2);
    
    for (int i = 6; i > 0; i--)
    {
        for (int j = 8; j > 0; j --)
        {
            int oX = (8 - j) * sq + 5 + marginX;
            int oY = (6 - i + 1) * sq + 20;
            int prevX = 0;
            int prevY = 0;
            
            int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
            int n = sizeof(arr) / sizeof(arr[0]);
            for (int x = n - 1; x > 0; x--)
            {
                int z = ofRandom(0,x);
                
                int* a = &arr[x];
                int* b = &arr[z];
                int temp = *a;
                *a = *b;
                *b = temp;
            }

            for (int k = 0; k < n; k ++)
            {
                int r = arr[k];
                int x = (sq/4) * (r%4);
                int y = (-sq/4) * floor(r/4);
                ofDrawLine(prevX + oX, prevY + oY, x + oX, y + oY);
                
                prevX = x;
                prevY = y;
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
    
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

