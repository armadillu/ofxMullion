//
//  ofxMullion.h
//  BaseApp
//
//  Created by Oriol Ferrer Mesià on 24/04/14.
//
//

#ifndef __BaseApp__ofxMullion__
#define __BaseApp__ofxMullion__


#include "ofMain.h"

class ofxMullion{

	public:

	void setup(int w, int h){
		enabled = false;
		m.setMode(OF_PRIMITIVE_LINES);
		float stepX = 1.0f / (float) w;
		float stepY = 1.0f / (float) h;
		for(int i = 0; i <= w; i++){
			m.addVertex( ofVec3f(i * stepX, 0.0f) );
			m.addVertex( ofVec3f(i * stepX, 1.0f) );
		}
		for(int i = 0; i <= h; i++){
			m.addVertex( ofVec3f(0.0f, stepY * i) );
			m.addVertex( ofVec3f(1.0f, stepY * i) );
		}
	}

	void toggle(){ enabled ^= true; }
	void enable(){ enabled = true; }
	void disable(){ enabled = false; }

	void draw(float w = ofGetWidth(), float h = ofGetHeight()){
		if(enabled){
			ofPushView();
				ofSetupScreen();
				ofScale(w, w);
				m.draw();
			ofPopView();
		}
	}

	ofVboMesh m;
	bool enabled;
};

#endif /* defined(__BaseApp__ofxMullion__) */
