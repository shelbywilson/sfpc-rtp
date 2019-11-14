#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    grabber.setup(640, 480);
}

//--------------------------------------------------------------
void ofApp::update(){
    grabber.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    //grabber.draw(0,0);
    
    cam.begin();
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
    ofRotateDeg(180);
    
    ofPolyline line;
    
    for (int y = 0; y < grabber.getHeight(); y += 4) {
        for (int x = 140; x < 500; x += 4) {
            
            int index = (y * grabber.getWidth() + x) * 3;
            unsigned char r = grabber.getPixels().getData()[index];
            unsigned char g = grabber.getPixels().getData()[index + 1];
            unsigned char b = grabber.getPixels().getData()[index + 2];

            ofSetColor(r, g, b);
            
            float xCoord = ofMap(x, 140, 500, 0, ofGetWidth());
            float yCoord = ofMap(y, 0, 480, 0, ofGetHeight());
//            ofDrawRectangle(xCoord, yCoord, 6, 6);
            
            float rZ = ofMap(r, 0, 255, 0, 400);
            ofSetColor(r, 0, 0);
            ofDrawBox(xCoord, yCoord, 0, 4, 2, rZ);
        
            float bZ = ofMap(b, 0, 255, 0, 400);
            ofSetColor(0, 0, b);
            ofDrawBox(xCoord, yCoord + 2, 0, 4, 2, bZ);
        
            float gZ = ofMap(g, 0, 255, 0, 400);
            ofSetColor(0, g, 0);
            ofDrawBox(xCoord, yCoord + 4, 0, 4, 2, gZ);
        }
    }
    
    ofSetColor(0);
    line.draw();
    
    ofPopMatrix();
    
    cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
