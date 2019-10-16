#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
//    float xorig = 500;
//    float yorig = 500;
//    float radius = 200;
//    float angle = ofGetElapsedTimef();
//    float x = xorig + radius * cos(angle*1.0);
//    float y = yorig + radius * sin(angle*3.0);
//
//    ofDrawCircle(x,y,3);
//
//    if (line.size() > 300){
//        line.getVertices().erase(line.getVertices().begin());
//    }
//    line.addVertex(x,y);
//    line.draw();
    
    drawGreen();
    drawRed();
    drawBlue();
    drawWhite();
}

void ofApp::drawRed() {
    float currDeg = degree;
    float radian = 0;
    float x = 0;
    float y = 0;
    float p = 0;
    
    ofSetColor(255, 0, 0);
    float petals = 1/2; // number of petals
    
    while (currDeg > 0) {
        
        radian = getRadian(currDeg);
        p = amp*cos(0.5*radian + (PI/4)); //do the polar coordinates
        x = x0+p*cos(radian); // convert to Cartesian
        y = y0+p*sin(radian); // convert to Cartesian
        
        //    if (line.size() > 700){
        //        line.getVertices().erase(line.getVertices().begin());
        //    }
        //    line.addVertex(x,y);
        //    line.draw();
        
        ofDrawCircle(x, y, 5);
        currDeg -= 4;
    }
    
    if (currDeg != 360) {
        degree++;
    } else {
        degree = 0;
    }
}

void ofApp::drawGreen() {
    ofSetColor(0, 255, 20);
    float petals = 1/2; // number of petals
    int j = 0;
    float radian = 0;
    float x = 0;
    float y = 0;
    float p = 0;
    
    for (int i = 0; i < 540; i += 4) {
        radian = getRadian(i);
        p = amp*cos(0.5*radian + (PI/4));
        x = x0+(p*1.2)*cos(radian);
        y = y0+(p*1.3)*sin(radian);
        
        ofPolyline line;
        line.addVertex(x,y);
        
        //        ofSetColor(255);
        //
        //        ofDrawCircle(x, y, 3);
        //        ofDrawBitmapString(std::to_string(j), x, y);
        
        if (j == 45) {
            line.getVertices().erase(line.getVertices().begin());
        } else if (j < 23) {
            radian = PI/180*(j * 4);
        } else if (j >= 23 && j <= 44) {
            radian = PI/180*((j+45) * 4);
        } else if (j > 45 && j <= 68) {
            radian = PI/180*((j - 1) * 4);
        } else {
            radian = PI/180*((j - 46) * 4);
        }
        
        x = x0 + amp * cos(radian);
        y = y0 + amp * sin(radian);
        line.addVertex(x,y);
        
        //        ofDrawCircle(x, y, 5);
        //        ofDrawBitmapString(std::to_string(j), x0 + amp * cos(radian), y0 + amp * sin(radian));
        
        //        ofSetColor(0, 255, 20);
        line.draw();
        
        if (i == 180) {
            i = 356;
        }
        j++;
    }
    
    //    for (int i = 270; i < 360; i += 6) {
    //
    //        radian = PI/180*(i);
    //        p = amp*cos(0.25*radian + (PI/4));
    //        x = x0+p*cos(radian) - amp/4;
    //        y = y0+p*sin(radian);
    //
    //        ofPolyline line;
    //
    //        //    if (line.size() > 700){
    //        //        line.getVertices().erase(line.getVertices().begin());
    //        //    }
    //
    //        ofSetColor(255);
    //        ofDrawCircle(x,y, 3);
    //
    //        ofDrawBitmapString(std::to_string(i), x, y);
    //
    ////        if (((i <= 360 && i >= 180) || i >= 540) == true) {
    ////            line.addVertex(x,y);
    ////
    ////            ofSetColor(0, 255, 20);
    //////            ofDrawCircle(x0 + amp*cos(radian), y0 + amp*sin(radian), 8);
    //////            ofDrawBitmapString(std::to_string(i), x0 + amp*cos(radian) + 5, y0 + amp*sin(radian));
    //////
    //////            ofSetColor(255, 0, 0);
    //////            ofDrawCircle(x,y, 3);
    ////
    //////            radian = PI/180*(i - 360);
    //////            p = amp*cos(0.5*radian + (PI/4));
    //////            x = x0+p*cos(radian);
    //////            y = y0+p*sin(radian);
    //////            line.addVertex(x, y);
    ////
    ////
    ////            line.draw();
    ////        }
    //        ofSetColor(0, 255, 20);
    //    }
}

void ofApp::drawBlue() {
    float currDeg = 360;
    float radian;
    float x;
    float y;
    
    ofSetColor(10, 40, 255);
    
    while (currDeg > 0) {
        radian = getRadian(currDeg);
        x = x0+ (amp * 1.1) *cos(radian);
        y = y0+ (amp * 1.1) *sin(radian);
        
        ofDrawCircle(x, y, 5);
        currDeg -= 4;
    }
}

void ofApp::drawWhite() {
    float radian;
    float x;
    float y;
    float r = amp * 1.2 - (ofGetElapsedTimef()/360);
    
    ofSetColor(255, 255, 255);
    ofPolyline line;
    
    for (int i = 0; i < 4; i ++) {
        for (int j = 0; j < 16; j ++) {
            radian = getRadian((90 * j/16) + (90*i));
            x = x0+ r*cos(radian);
            y = y0+ r*sin(radian);

            line.addVertex(x,y);
            
            //ofDrawBitmapString(std::to_string(j), x, y);
            
            x = x0;
            y = y0;
            
            switch(i) {
                case 0:
                    x += r;
                    y += r;
                    break;
                case 1:
                    x -= r;
                    y += r;
                    break;
                case 2:
                    x -= r;
                    y -= r;
                    break;
                default:
                    x += r;
                    y -= r;
                    break;
            }
            
            line.addVertex(x,y);

            line.draw();
        }
    }
}

float ofApp::getRadian(float degree) {
    return PI/180*(degree);
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
