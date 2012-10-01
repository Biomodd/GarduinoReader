#include "biomoddWar.h"

/*=============================================
  Biomodd War // Space War Mockup
 ----------------------------------------------
 [ biomoddWar.cpp ]
 ===============================================*/

/////////////////////////////////////
//  S E T U P
/////////////////////////////////////

void biomoddWar::setup(){
    ofBackground(0);
    spaceShip.init();
    
    for (int i = 0; i < 30; i++) {
        Asteroid asteroid;
        asteroid.init(ofRandom(ASTEROIDS_BEGIN_SIZE_MIN, ASTEROIDS_BEGIN_SIZE_MAX));
        asteroids.push_back(asteroid);
    }

    world = ofRectangle(0, 0, ofGetWidth(), ofGetHeight());
}


/////////////////////////////////////
//  U P D A T E
/////////////////////////////////////

void biomoddWar::update(){

    spaceShip.update();
    
    if (ofGetFrameNum()%10==0) {
        explosions.update();        
    }

    
    for (int i = 0; i < asteroids.size(); i++) {
        asteroids.at(i).update();
    }
    
    for (int i = 0; i < asteroids.size(); i++) {
        if (spaceShip.getLocation().distance(asteroids.at(i).getLocation())<= asteroids.at(i).getRadius() + SPACE_SHIP_SIZE) {
            spaceShip.init();
        }
    }
    
    vector<int> newRadius;
    vector<ofVec2f>newLocation;
    
    bool erase = false;
    int eraseAsteroid;
    int eraseBullet;
    
    for (int i = 0; i < asteroids.size(); i++) {
        for (int j = 0; j < spaceShip.getBulletAmount(); j++) {
            if (asteroids.at(i).getLocation().distance(spaceShip.getBulletLocation(j)) <= asteroids.at(i).getRadius()) {

                if (asteroids.at(i).getRadius()>ASTEROIDS_BEGIN_SIZE_MIN) {
                    int newAmount = ofRandom(1, 5);
                    for (int k = 0; k < newAmount; k++) {
                        newRadius.push_back(ofRandom(ASTEROIDS_BEGIN_SIZE_MIN, asteroids.at(i).getRadius()));
                        newLocation.push_back(asteroids.at(i).getLocation());
                    }
                }
                
                eraseAsteroid = i;
                eraseBullet = j;
                erase = true;
                
                i == asteroids.size();
                j == spaceShip.getBulletAmount();
                
                explosions.addExplosion(asteroids.at(i).getLocation(), asteroids.at(i).getRadius());
            }
        }
    }
    
    if (erase==true) {
        asteroids.erase(asteroids.begin()+eraseAsteroid);
        spaceShip.removeBullet(eraseBullet);
    }
    
    for (int i = 0; i < newRadius.size(); i++) {
        Asteroid asteroid;
        asteroid.init(newLocation.at(i), world, newRadius.at(i));
        asteroids.push_back(asteroid);
    } 
    

    

}


/////////////////////////////////////
//  D R A W
/////////////////////////////////////

void biomoddWar::draw(){
    spaceShip.draw();
    for (int i = 0; i < asteroids.size(); i++) {
        asteroids.at(i).draw();
    }
    ofEnableAlphaBlending();
    explosions.draw();

}

/////////////////////////////////////
//  C U S T O M  F U N C T I O N S
/////////////////////////////////////



/////////////////////////////////////
//  I / O
/////////////////////////////////////

void biomoddWar::keyPressed(int key){
    
    if (key=='q') {
        spaceShip.rotateMin();
    } else if (key=='d'){
        spaceShip.rotatePlus();
    }
    
    if (key==' ') {
        spaceShip.addBullet();
    }
    
    if (key=='z') {
        spaceShip.acceleratePlus();
    }
    
}

//--------------------------------------------------------------
void biomoddWar::keyReleased(int key){

}

//--------------------------------------------------------------
void biomoddWar::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void biomoddWar::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void biomoddWar::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void biomoddWar::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void biomoddWar::windowResized(int w, int h){

}

//--------------------------------------------------------------
void biomoddWar::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void biomoddWar::dragEvent(ofDragInfo dragInfo){ 

}