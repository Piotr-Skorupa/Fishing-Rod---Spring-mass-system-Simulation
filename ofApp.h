#pragma once

#include "ofxAssimpModelLoader.h"
#include "ofMain.h"
#include "Spring.h"
#include "Point.h"
#include "Fishing_rod.h"
#include "Fish.h"
#include <iostream>
#include <vector>


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

		ofEasyCam camera;
		ofLight light;
		Fishing_rod rod;
		Fish goldfish;
		ofVec3f lightVec;
		ofxAssimpModelLoader island;
		ofxAssimpModelLoader boat;
		std::string msg;
		
};
