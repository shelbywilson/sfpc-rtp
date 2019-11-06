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
    grabber.draw(0,0);
    
    for (int x = 0; x < grabber.getWidth(); x += 10) {
        for (int y = 0; y < grabber.getHeight(); y += 10) {
            
//            ofColor c = grabber.getPixels().getColor(x,y);
//
//            ofSetColor(c);
//            ofDrawCircle(x, y, 5);
            
            int index = (y * grabber.getWidth() + x) * 3;
            unsigned char r = grabber.getPixels().getData()[index];
            unsigned char g = grabber.getPixels().getData()[index + 1];
            unsigned char b = grabber.getPixels().getData()[index + 2];

            ofSetColor(r,g,b);
            ofDrawCircle(x, y, 5);
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
