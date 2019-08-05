#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(15);

	// shaders
	lighting.load("shadersGL3/lighting");
	displace.load("shadersGL3/displace");
	normals.load("shadersGL3/normals");
	
	fboDisplaceMap.allocate(800, 800);
	fboNormalsMap.allocate(800, 800);

	displacePlane.set(800, 800);
	displacePlane.setPosition(0, 0, 0);
	displacePlane.setResolution(10, 10);

	normalsPlane.set(800, 800);
	normalsPlane.setPosition(0, 0, 0);
	normalsPlane.setResolution(10, 10);

	normalsPlane.mapTexCoordsFromTexture(fboDisplaceMap.getTexture());

}

//--------------------------------------------------------------
void ofApp::update(){
	fboDisplaceMap.begin();
		displace.begin();
			ofPushMatrix();
			ofTranslate(400., 400.);
			displacePlane.draw();
			ofPopMatrix();
		displace.end();
	fboDisplaceMap.end();

	fboNormalsMap.begin();
		normals.begin();
		normals.setUniformTexture("tex0", fboDisplaceMap.getTexture(), 0);
			ofPushMatrix();
			ofTranslate(400., 400.);
			normalsPlane.draw();
			ofPopMatrix();
		normals.end();
	fboNormalsMap.end();
}

//--------------------------------------------------------------
void ofApp::draw(){
	fboDisplaceMap.draw(0, 0, 800, 800);
	fboNormalsMap.draw(850, 0, 800, 800);
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
