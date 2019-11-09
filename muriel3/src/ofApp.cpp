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
    
    for (int i = 0; i < numLetters; i++){
        
        vector < ofPolyline > lines = letters[i].getOutline();
        
        if (timer[i] < 90) {
            timer[i] += 1.5;
        }
        
        for (int j = 0; j < lines.size(); j ++) {
            ofPolyline front = lines[j];//.getResampledBySpacing(40);
            ofPolyline back = lines[j];
            float frontX;
            float backX;
            
            float cosTime = cos(timer[i] * PI/180);
            if (j == 0) {
                bbox = front.getBoundingBox();
            }
            
            for (int k = 0; k < front.size(); k ++) {
                
                frontX = ofMap(cosTime, 1, 0, front[k].x, -6 + (bbox.getMin().x + bbox.getMax().x)/2);
                backX = ofMap(cosTime, 1, 0, back[k].x, 6 + (bbox.getMin().x + bbox.getMax().x)/2);
                
                front[k].x = frontX;
                back[k].x = backX;
                
                ofPolyline connect;
                
                connect.addVertex(frontX, front[k].y);
                connect.addVertex(backX, front[k].y);
                
                connect.draw();
            }
            
            front.draw();
            back.draw();
            
        }
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

