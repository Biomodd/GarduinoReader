

#ifndef __emptyExample__Explosion__
#define __emptyExample__Explosion__

#include <iostream>


/*=============================================
 EXPLOSION CLASS
 
 This class will be dealing with the explosions
 of the spaceShip when it is destroyed & with
 the explosion of asteroids when they are hit.
 ----------------------------------------------
 [Explosion.h ]
 -----------> BIOMODD [NYC4]  || 27/09/2012
 -----------> PIETER STEYAERT
 ===============================================*/

#include "ofMain.h"
struct Explode {
    ofVec2f location;
    int size;
    int life;
};

class Explosion {
    
public:
	
    // -------[CONSTRUCTOR]----
    Explosion();
    
    // -------[METHODS]----
    void addExplosion(ofVec2f location, int size);
	void update();
	void draw();
    
    // -------[GETTERS N SETTERS]----
    
private:
    
    // -------[PRIVATE METHODS]----
    
    
    // -------[GLOBAL VARIABLES]----
        vector<Explode> explosions;
        ofFbo fbo;
    
};


#endif