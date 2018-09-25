#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(239);
	ofSetColor(39);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	float radius = 45;
	int edge_half_length = radius * cos(30 * DEG_TO_RAD);
	float triangle_height = sqrt(3) / 2 * (edge_half_length * 2);
		
	int y_gap = 0;
	int deg_start = 0;
	for (int y = 0; y < ofGetHeight() + triangle_height; y += triangle_height) {

		for (int x = 0; x < ofGetWidth() + edge_half_length; x += edge_half_length) {
	
			float triangle_radius = radius * ofNoise(x * 0.005, y * 0.005, ofGetFrameNum() * 0.01);
			if (x % (edge_half_length * 2) == 0) {

				deg_start = 270;
				ofSetColor(69, 69, 239);
				y_gap = 0;
			}
			else {

				deg_start = 90;
				ofSetColor(239, 69, 69);
				y_gap = radius - triangle_height;
			}

			ofBeginShape();
			for (int deg = deg_start; deg < deg_start + 360; deg += 120) {

				ofVertex(x + triangle_radius * cos(deg * DEG_TO_RAD), (y + y_gap) + triangle_radius * sin(deg * DEG_TO_RAD));
			}
			ofEndShape();
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}