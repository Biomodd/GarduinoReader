/*=============================================
 ASTEROID 
 ----------------------------------------------
 [ Asteroid.cpp ]
 ===============================================*/

#include "Asteroid.h"

/////////////////////////////////////
//  C O N S T R U C T O R
/////////////////////////////////////

Asteroid::Asteroid(){
    init(ofRandom(ASTEROIDS_BEGIN_SIZE_MIN, ASTEROIDS_BEGIN_SIZE_MAX));
}


/////////////////////////////////////
//  M E T H O D S
/////////////////////////////////////

void Asteroid::init(int _radius){
    world = ofRectangle(0, 0, ofGetWidth(), ofGetHeight());
    movement.location = ofVec2f(ofRandom(world.x+world.width), ofRandom(world.y+world.height));
    movement.velocity = ofVec2f(1,1);
    movement.velocity.rotate(ofRandom(255));
    movement.velocity.normalize();
    movement.velocity.scale(0.01);
    
    radius = _radius;
}

void Asteroid::init(ofVec2f location, ofRectangle _world, int _radius){
    world = _world;
    movement.location = location;
    movement.velocity = ofVec2f(1,1);
    movement.velocity.rotate(ofRandom(255));
    movement.velocity.normalize();
    movement.velocity.scale(0.01);
    
    radius = _radius;
}

void Asteroid::update(){
    checkEdges();
    
    movement.location += movement.velocity;
}

void Asteroid::draw(){
    ofCircle(movement.location, radius);
}


/////////////////////////////////////
//  P R I V A T E   M E T H O D S
/////////////////////////////////////

void Asteroid::checkEdges(){
    if (movement.location.x<world.x) {
        movement.location.x = world.x+world.width;
    } else if (movement.location.x>world.x+world.width){
        movement.location.x = world.x;
    }
    
    if (movement.location.y<world.y) {
        movement.location.y = world.y+world.height;
    } else if (movement.location.y>world.y+world.height){
        movement.location.y = world.y;
    }
}

/////////////////////////////////////
//  G E T T E R S  N  S E T T E R S
/////////////////////////////////////

ofVec2f Asteroid::getLocation(){
    return movement.location;
}

int Asteroid::getRadius(){
    return radius;
}

