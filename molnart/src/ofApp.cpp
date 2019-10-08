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
    cout << mouseX << endl;
    
    
    //    for (int i = 0; i < 40; i++){
    //        for (int j = 0; j < 40; j++){
    //
    //            float x = ofMap(i, 0, 40, 50, 750);
    //            float y = ofMap(j, 0, 40, 50, 750);
    //
    //            if (ofNoise(i*0.09, j*0.09, mouseX*0.01) < .85){
    //                ofPushMatrix();
    //                ofTranslate(x,y);
    //                ofRotateZ(ofRandom(0,360));
    //                ofDrawLine(0-15,0,0+15, 0);
    //                ofPopMatrix();
    //            }
    //        }
    //    }
    
    //    for (int i = 0; i < 400; i++){
    //        for (int j = 0; j < 400; j++){
    //            ofSetColor(ofNoise(i*0.01, j*0.01) * 255);
    //            ofDrawRectangle(i*2, j*2, 2,2);
    //        }
    //    }
    
    carresNoir();
    //shallWeTakeAWalk();
    //untitled6_1972();
}

//--------------------------------------------------------------
// 25 carres noir
void ofApp::carresNoir() {
    int size = 768;
    ofSetColor(ofRandom(0,255), ofRandom(0,255), ofRandom(0,255), 150);
    
    int margin = 50;
    int sq = ofRandom(3, 10);
    int actualSize = (size - margin)/sq;
    
    for (int i = 0; i < sq; i++) {
        for (int j = 0; j < sq; j ++) {
            ofPushMatrix();
            ofTranslate(i * actualSize + ofRandom(0,40) + margin + 128, j * actualSize + ofRandom(0,40) + margin);
            ofRotateZ(ofRandom(-20,20));
            ofDrawBox(0, 0, 0, actualSize, actualSize, 0);
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

