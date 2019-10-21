#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        void drawRed();
        void drawGreen();
        void drawBlue();
        void drawWhite();
    
        void drawHarmonicLines();
    
        void drawMatrix(float startTime);
    
        float getRadian(float degree);
		
        ofPolyline line;
    
        float t;
    
        float cues [5] = {2, 10.5, 15, 21, 83.2};
        //float cues [3] = {0, 0.5, 5};
    
        // global
        int defaultAmp = 260; // size of the rose
        float x0 = ofGetWidth()/2;
        float y0 = ofGetHeight()/2;
    
        // white
        float whiteT = 0;
    
        // red
        float redIterator = 0;
        float redT = 0;
    
        // blue
        float blueT = 0;
    
        // green
        float greenT = 0;
    
        // matrix
        float matrixT = 0;
        float matrixPos [18];
};
