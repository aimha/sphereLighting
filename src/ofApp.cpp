#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(15);
	
	lighting.load("shadersGL3/lighting");
	
	sphere.setRadius(200);
	sphere.setResolution(400);

	plane.set(800, 800);
	plane.setPosition(0, 0, 0);
	plane.setResolution(400, 400);

	mesh = plane.getMesh();
}

//--------------------------------------------------------------
void ofApp::update(){
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	lighting.begin();

	lighting.setUniform1f("time", ofGetElapsedTimef());

	ofEnableDepthTest();

		ofPushMatrix();
		ofTranslate(ofGetWidth() / 2., ofGetHeight() / 2.);
		ofRotateX(60);
		mesh.draw(); 
		ofPopMatrix();
		
	ofDisableDepthTest();

	lighting.end();
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
