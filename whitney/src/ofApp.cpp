#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    t = ofGetElapsedTimef();
    
    if (t >= cues[0] && t < cues[3]) {
        drawHarmonicLines();
    } else if (t >= cues[3]) {
        drawVerticalLines();
    }
//    } else if (t >= cues[2]) {
//            drawGreen();
//            drawRed();
//            drawBlue();
//            drawWhite();
//    }
    
    cout << t << endl;
}

void ofApp::drawRed() {
    float currDeg = redIterator;
    float radian = 0;
    float x = 0;
    float y = 0;
    float p = 0;
    
    ofSetColor(243, 15, 35);
    
    while (currDeg > 0) {
        
        radian = getRadian(currDeg);
        p = amp*cos(0.5*radian + (PI/4));
        x = x0+p*cos(radian);
        y = y0+p*sin(radian);
        
        ofDrawCircle(x, y, 5);
        currDeg -= 4;
    }
    
    if (redIterator < 720) {
        redIterator++;
    }
}

void ofApp::drawGreen() {
    ofSetColor(80, 176, 118);
    int j = 0;
    float radian = 0;
    float x = 0;
    float y = 0;
    float p = 0;
    
    for (int i = 0; i < 540; i += 4) {
        radian = getRadian(i);
        p = amp*cos(0.5*radian + (PI/4));
        x = x0+(p*1.2)*cos(radian);
        y = y0+(p*1.35)*sin(radian);
        
        ofPolyline line;
        line.addVertex(x,y);
        
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
        
        
        //if (greenIterator >= 720) {
            line.draw();
//        } else {
//            ofDrawCircle(x, y, greenIterator/720);
//        }
        
        if (i == 180) {
            i = 356;
        }
        j++;
    }
    
    if (greenIterator < 720) {
        greenIterator++;
    }
}

void ofApp::drawBlue() {
    float currDeg = 360;
    float radian;
    float x;
    float y;
    
    ofSetColor(39, 123, 226);
    
    while (currDeg > 0) {
        radian = getRadian(currDeg);
        x = x0+ (amp * 1.07) *cos(radian);
        y = y0+ (amp * 1.07) *sin(radian);
        
        ofDrawCircle(x, y, 5);
        currDeg -= 4;
    }
}

void ofApp::drawWhite() {
    float radian;
    float x;
    float y;
    float r = amp * 1.2;
    
    ofSetColor(255, 255, 255);
    ofPolyline line;
    
    for (int i = 0; i < 4; i ++) {
        for (int j = 0; j < 16; j ++) {
            line.clear();
            radian = getRadian((90 * j/16) + (90*i));
            x = x0+r*cos(radian); //* sin(ofGetElapsedTimef() //1.5 * sin(ofGetElapsedTimef())
            y = y0+r*sin(radian); //(1.5 * -sin(ofGetElapsedTimef())

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

void ofApp::drawHarmonicLines() {
    float radian;
    float x;
    float y;
    
    
    float maxY = ofGetHeight();//ofGetHeight()*3/4 + (cos(t/2) * ofGetHeight()/4);
    float minY = 0; //ofGetHeight()*1/4 - (cos(t/2) * ofGetHeight()/4);
    
    float maxJ = MIN((t - cues[0]) * 45, 360);
    
    if (t > cues[2]) {
        minY = ofGetHeight()*1/4 - (cos((t - cues[2])/2) * ofGetHeight()/4);
        maxY = ofGetHeight()*3/4 + (cos((t - cues[2])/2) * ofGetHeight()/4);
    } 
    
    for (int i = 1; i < 11; i ++) {
        ofSetColor(200 * i/5 + 10, 140 * sin(i) + 10, 251 * cos(i) + 30);
        ofPolyline line;
        ofSetLineWidth(3);
        
        float amp = 20 * 10/i;
        
        if (i == 10) {
            ofSetColor(255,255,255);
        }
        
        if (t > cues[1]) {
            //        maxY *= (t - cues[1])/5;
            //        minY = ofGetHeight() - maxY;
            //amp *= 1/(t - cues[1] + 1);
        }
        
        for (float j = 0; j < maxJ; j += 0.25) {
            radian = getRadian(j);
            
            if (t > cues[1]) {
                amp = amp * cos((t - cues[1]) / 5);
            }
//            if (t > cues[2]) {
//                radian = (t - cues[2] + PI/6);
//            }
            
            radian = radian * i + PI;
            
            x = x0+amp*sin(radian);
            y = ofMap(j, 360, 0, minY, maxY);
            
            if (j + 0.25 > maxJ) {
                ofDrawCircle(x,y,3);
            }
            line.addVertex(x,y);
        }
        
        line.draw();
    }
}

void ofApp::drawVerticalLines() {
    ofSetColor(255);
    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, 2);
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
