#include "ofApp.h"




//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(163, 173, 184);
	ofEnableDepthTest();
	ofSetFrameRate(30);
	lightVec.set(-3000, 1000, 0);
	light.setOrientation(lightVec);
	light.setDirectional();
	light.enable();
	rod = Fishing_rod();
	goldfish.load_model("goldfish\\GOLDFISH.3ds", rod.get_hook_point());
	island.loadModel("background\\3DS\\Tropical Islands.3ds", 20);
	boat.loadModel("boat\\boat.3ds", 20);
	boat.setRotation(0, 175, 1, 0, 0);
	boat.setPosition(-100.0, -100.0, 0.0);
	island.setRotation(0, 180, 1, 0, 0);
	island.setRotation(1, -5, 0, 1, 0);
	island.setScale(100.0, 100.0, 100.0);
	island.setPosition(1600.0, -100.0, 5000.0);

	// screen message
	msg = "Author: Piotr Skorupa \nTo fullscreen press 'F' \nTo To start simulation press 'KEY_DOWN' \nTo exit press 'Esc'";
	msg += "\n\nfps: " + ofToString(ofGetFrameRate(), 2);
}

//--------------------------------------------------------------
void ofApp::update(){
	rod.update_tension(goldfish);
}

//--------------------------------------------------------------
void ofApp::draw(){
	camera.begin();
	ofPushMatrix();
	island.drawFaces();
	rod.draw();
	goldfish.draw();
	boat.drawFaces();
	ofPopMatrix();
	camera.end();
	ofSetColor(255);
	ofDrawBitmapStringHighlight(msg, 10, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key) {
	case 'f':
		ofToggleFullscreen();
		break;
	case OF_KEY_DOWN:
		// next fish on rod
		// play sonund of changing
		// write on screen the name of fish	
		
		rod.tension();
		//rod.update();
		break;
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
