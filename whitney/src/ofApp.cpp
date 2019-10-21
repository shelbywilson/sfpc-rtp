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
    } else if (t >= cues[3] && isDrawWhite == false) {
        drawMatrix(cues[3]);
    } else if (isDrawWhite == true) {
        drawWhite();
    }
}

void ofApp::drawRed() {
    float currDeg = redIterator;
    float radian = 0;
    float x = 0;
    float y = 0;
    float p = 0;
    float n = 0.5;
    
    if (redIterator < 720) {
        redIterator++;
    } else {
        drawGreen();
    }
    
    redT += 0.001;
    
    ofSetColor(243, 15, 35);
    
    if (redT > 0.95) {
        n = ofMap(redT - 0.95, 0, 14, 0.5, 30);
    }
    
    while (currDeg > 0) {
        radian = getRadian(currDeg);
        
        p = defaultAmp * cos(n*radian + (PI/4));
        x = x0 + p * cos(radian);
        y = y0 + p * sin(radian);
        
        ofDrawCircle(x, y, 5);
        currDeg -= 4;
    }
}

void ofApp::drawGreen() {
    ofSetColor(80, 176, 118);
    ofSetLineWidth(1);
    int j = 0;
    float radian = 0;
    float x = 0;
    float y = 0;
    float p = 0;
    
    greenT += 1;
    
    for (int i = 0; i < 540; i += 4) {
        radian = getRadian(i);
        p = defaultAmp*cos(0.5*radian + (PI/4));
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
        
        x = ofMap(MIN(greenT * 5, 1000), 0, 1000, x, x0 + defaultAmp * cos(radian));
        y = ofMap(MIN(greenT * 5, 1000), 0, 1000, y, y0 + defaultAmp * sin(radian));
        
        line.addVertex(x,y);
    
        line.draw();
        
        if (i == 180) {
            i = 356;
        }
        j++;
    }
}

void ofApp::drawBlue() {
    float currDeg = 360;
    float radian;
    float x;
    float y;
    float r = defaultAmp * 1.07;
    
    ofSetColor(39, 123, 226);
    
    blueT += 0.001;
    
    if (blueT > 2) {
        r = ofMap(MIN((blueT - 2) * 5, 3), 0, 3, defaultAmp * 1.07, ofGetHeight * 0.45);
    }
    
    while (currDeg > 0) {
        radian = getRadian(currDeg);
        
        if (blueT > 1) {
            x = cos((cos(blueT - 1) * radian) + ((blueT - 1) * 20));
            y = sin(radian);
        } else {
             x = cos(radian);
             y = sin(radian);
        }
        
        x *= r;
        y *= r;
        
        x += x0;
        y += y0;
        
        ofDrawCircle(x, y, MIN(ofMap(blueT, 0, 0.1, 0, 5), 5));
        currDeg -= 4;
    }
}

void ofApp::drawWhite() {
    float radian;
    float x1;
    float y1;
    float x2;
    float y2;
    float startX2;
    float startY2;
    float r = defaultAmp * 1.2;
    
    whiteT += 0.001;
    
    if (whiteT > 0.3) {
        drawRed();
    }
    if (whiteT > 0.5) {
        drawBlue();
    }
    
    ofSetColor(255, 255, 255);
    ofPolyline line;
    ofSetLineWidth(1.5);
    
    for (int i = 0; i < 4; i ++) {
        for (int j = 1; j < 16; j ++) {
            line.clear();
            
            float iterator = j;
            
            if (i%2 == 1) {
                iterator = 16 - j;
                
                startX2 = x0+r*cos(getRadian(90 + (90*i)));
                startY2 = y0+r*sin(getRadian(90 + (90*i)));
            } else {
                startX2 = x0+r*cos(getRadian(90*i));
                startY2 = y0+r*sin(getRadian(90*i));
            }
            
            radian = getRadian((90 * iterator/16) + (90*i));
            
            x1 = x0;
            y1 = y0;
            
            switch(i) {
                case 0:
                    x1 += r;
                    y1 += r;
                    break;
                case 1:
                    x1 -= r;
                    y1 += r;
                    break;
                case 2:
                    x1 -= r;
                    y1 -= r;
                    break;
                default:
                    x1 += r;
                    y1 -= r;
                    break;
            }
            
            line.addVertex(x1,y1);
            
            if (whiteT > 1.3) {
                x2 = ofMap(MIN((whiteT - 1.3) * j * 4, 1), 0, 1, x0+r*cos(radian), startX2);
                y2 = ofMap(MIN((whiteT - 1.3) * j * 4, 1), 0, 1, y0+r*sin(radian), y1);
            } else {
                x2 = ofMap(MIN(whiteT * j/2, 1), 0, 1, startX2, x0+r*cos(radian));
                y2 = ofMap(MIN(whiteT * j/2, 1), 0, 1, startY2, y0+r*sin(radian));
            }

            line.addVertex(x2,y2);

            line.draw();
            
//            ofDrawBitmapString(to_string(j), x2, y2);
        }
    }
}

void ofApp::drawHarmonicLines() {
    float radian;
    float x;
    float y;
    
    
    float maxY = ofGetHeight();
    float minY = 0; 
    
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
        
        for (float j = 0; j < maxJ; j += 0.25) {
            radian = getRadian(j);
            
            if (t > cues[1]) {
                amp = amp * cos((t - cues[1]) / 5);
            }
            
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

void ofApp::drawMatrix(float startTime) {
    ofSetColor(255);
    ofSetLineWidth(2);
    
    int maxAmp = floor(ofGetWidth() * 1/3);
    float amp = MIN((t - startTime)*(t - startTime), maxAmp);
    
    if (amp >= maxAmp/2) {
        matrixT += 0.001;
    }
    
    for (int i = 0; i < 18; i += 1) {
        float x = ofGetWidth()/2 + amp * cos((t - startTime) + (i * matrixT));
        float y = ofGetHeight()/2;
        
        if (matrixT > 0.5) {
            y += cos(i * 2) * amp * MIN(matrixT - 0.5, 0.5);
        }
        
        float lineH = MIN((200 * (matrixT - 1)) + 2.25, 140);
        
        if (matrixT > 2.5) {
            float matrixTDiff = sin(MIN(getRadian(matrixT - 2.5) * 400, PI/2));
            
            lineH = ofMap(matrixTDiff, 0, 1, 140, defaultAmp * 1.2);
            ofSetLineWidth(ofMap(matrixTDiff, 0, 1, 2, 1.5));
            
            if (matrixTDiff == 1) {
                isDrawWhite = true;
            }
            
            switch(i%4) {
                case 0:
                    x = ofMap(matrixTDiff, 0, 1, x, ofGetWidth()/2 - (defaultAmp * 1.2));
                    y = ofMap(matrixTDiff, 0, 1, y, ofGetHeight()/2 - (defaultAmp * 1.2) + lineH/2);
                    break;
                case 1:
                    x = ofMap(matrixTDiff, 0, 1, x, ofGetWidth()/2 + (defaultAmp * 1.2));
                    y = ofMap(matrixTDiff, 0, 1, y, ofGetHeight()/2 + (defaultAmp * 1.2) - lineH/2);
                    break;
                case 2:
                    x = ofMap(matrixTDiff, 0, 1, x, ofGetWidth()/2 - (defaultAmp * 1.2));
                    y = ofMap(matrixTDiff, 0, 1, y, ofGetHeight()/2 + (defaultAmp * 1.2) - lineH/2);
                    break;
                case 3:
                    x = ofMap(matrixTDiff, 0, 1, x, ofGetWidth()/2 + (defaultAmp * 1.2));
                    y = ofMap(matrixTDiff, 0, 1, y, ofGetHeight()/2 - (defaultAmp * 1.2) + lineH/2);
                    break;
                default:
                    break;
            }
        }
    
        if (matrixT > 1) {
            ofDrawLine(x, y - lineH/2, x, y + lineH/2);
        } else {
            ofDrawCircle(x, y, 2);
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
