/*=============================================
 SPACESHIP // BIOMODD WAR
 ----------------------------------------------
 [ SpaceShip.h ]
 -----------> PIETER STEYAERT || 28/09/2012
 ----------->				     dd/mm/yyyy
 -----------> SPACESHIP Class
                * movement of the spaceship
                * firing (?)
 ===============================================*/

#ifndef _SPACE_SHIP
#define _SPACE_SHIP
#include "ofMain.h"
#include "settings.h"

class SpaceShip {
    
public:
	
    // -------[CONSTRUCTOR]----
    SpaceShip();
    
    // -------[METHODS]----
    void init();
    void init(ofVec2f location, ofRectangle _world);
	void update();
	void draw();
    
    void rotatePlus();
    void rotateMin();
    
    void acceleratePlus();
    void accelerateMin();
    
    void addBullet();
    void removeBullet(int index);
    
    // -------[GETTERS N SETTERS]----
    ofVec2f     getLocation();
    void        setLocation(ofVec2f location);
    
    ofRectangle getWorld();
    void        setWorld(ofRectangle _world);
    
    int         getBulletAmount();
    ofVec2f     getBulletLocation(int index);
    
private:
    struct Movement {
        ofVec2f location, velocity;
        float rotation;
        float boost;
    };
    
    struct Bullet {
        ofVec2f location, velocity;
        int life;
    };
    
    // -------[PRIVATE METHODS]----
    void updateSpaceShip();
    void updateBullets();
    
    void checkEdgesSpaceship(); // eternal
    void checkEdgesBullets();
    
    // -------[GLOBAL VARIABLES]----
    Movement movement;
    ofRectangle world;
    ofMesh      spaceMesh;
    
    vector<Bullet> bullets;
};


#endif