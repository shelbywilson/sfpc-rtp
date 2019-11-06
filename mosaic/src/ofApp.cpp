#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    lillian.load("lillian 2.jpg");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    
//    int step = mouseX / 50.0;
//    if (step < 1) { step = 1; }
//
//    for (int i = 0; i < lillian.getWidth(); i += step) {
//        for(int j = 0; j < lillian.getHeight(); j += step) {
//            ofColor c = lillian.getColor(i, j);
//
//            ofSetColor(c);
//            ofDrawCircle(i, j, step / 2.0);
//        }
//    }
    
//    float ratio = lillian.getWidth() / lillian.getHeight();
//
//    lillian.draw(0,0,ofGetWidth(), ofGetWidth() / ratio);
    
//        int step = mouseX / 50.0;
//        if (step < 1) { step = 1; }
    
    int step = 1;
    map< int, ofPolyline > lookup;
    
    for (int i = 0; i < lillian.getWidth(); i += step) {
        for(int j = 0; j < lillian.getHeight(); j += step) {
            ofColor c = lillian.getColor(i, j);
            
            int cHex = c.getHex();
            
            if ( lookup.find(cHex) == lookup.end() ) {
                ofPolyline points;
                lookup[cHex] = points;
            }
            
            lookup[cHex].addVertex(i, j);

            //ofSetColor(c);
            //ofDrawRectangle(i, j, 2, 2);
        }
    }
    
    std::map< int, ofPolyline >::iterator iter = lookup.begin();
    float count = 0;
    while (iter != lookup.end())// && count < mouseX)
    {
        int cHex = iter->first;
        ofPolyline line =  iter->second;
        
        ofSetHexColor(cHex);
        line.draw();
        
        iter++;
        count+=0.01;
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
