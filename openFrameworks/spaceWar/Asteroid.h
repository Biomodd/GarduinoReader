/*=============================================
 ASTEROID
 ----------------------------------------------
 [ Asteroid.h ]
 -----------> PIETER STEYAERT || 28/09/2012
 ----------->				     dd/mm/yyyy
 -----------> Additional Information
 ===============================================*/

#ifndef _ASTEROID
#define _ASTEROID

#include "ofMain.h"
#include "settings.h"

class Asteroid {
    
public:
	
    // -------[CONSTRUCTOR]----
    Asteroid();
    
    // -------[METHODS]----
    void init(int _radius);
    void init(ofVec2f location, ofRectangle _world, int _radius);
    
	void update();
	void draw();
    
    // -------[GETTERS N SETTERS]----
    ofVec2f getLocation();
    int getRadius();
    
private:
    struct Movement {
        ofVec2f location, velocity;
    };
    
    // -------[PRIVATE METHODS]----
    void checkEdges();
    
    // -------[GLOBAL VARIABLES]----
    Movement movement;
    ofRectangle world;
    int radius;
};


#endif