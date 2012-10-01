#pragma once

#include "ofMain.h"
#include "SpaceShip.h"
#include "Asteroid.h"
#include "Explosion.h"

#define ROTATION 10

/*=============================================
 Biomodd War // Space War Mockup
 
 This is a simple mock up, in order to experiment
 with the biomodd [NYC4] mixed reality system.
 
 In line with hacker ethic history we chose
 for a simple Space War setup. The creation/
 behavior of the "Asteroids" will be generated
 by sensor inputs, hooked up with a "GARDUINO"
 to one or more plants.

 ----------------------------------------------
 [ DEPENDENCIES ]
    * open frameworks
 
 ----------------------------------------------
 [ WIP ]
    
    * create the game
    * implement data
        - speed
        - amount of replication
        - maxSize
 
    Alternatives:
        - lighting = lighting around ship
        - heat = ship color
    * R/D texturing
 
 ----------------------------------------------
 [ CONTRIBUTORS ]

 -----------> Biomodd Github Portal
              [https://github.com/Biomodd]

 *  Bruno Kruse (bkruse)
 *  Pieter Steyaert (subtiv)
 
 ----------------------------------------------
 -----------> BIOMODD [NYC4] || 28/09/2012
 ----------->				    dd/mm/yyyy
 ===============================================*/

class biomoddWar : public ofBaseApp{
	public:
    
        // -------[FUNCTIONS]----
		void setup();
		void update();
		void draw();
    
    
        // -------[CUSTOM FUNCTIONS]----

    
        // -------[I / O]----
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        // -------[GLOBALS]----
        SpaceShip spaceShip;
        vector<Asteroid> asteroids;
        ofRectangle world;
        Explosion explosions;
        
};
