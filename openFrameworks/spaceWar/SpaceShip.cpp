/*=============================================
 FULL NAME // FUNCTIONALITY
 ----------------------------------------------
 [ SpaceShip.mm ]
 ===============================================*/

#include "SpaceShip.h"

/////////////////////////////////////
//  C O N S T R U C T O R
/////////////////////////////////////

SpaceShip::SpaceShip(){
    init();
    
    movement.rotation = ofRandom(255); // change this so it is centered towards the center
    movement.velocity = ofVec2f(0,0);
    movement.boost = 0;
    
    spaceMesh.addVertex(ofVec3f(-1*SPACE_SHIP_SIZE, -1*SPACE_SHIP_SIZE,0));
    spaceMesh.addVertex(ofVec3f(1*SPACE_SHIP_SIZE, -1*SPACE_SHIP_SIZE));
    spaceMesh.addVertex(ofVec3f(0, 2*SPACE_SHIP_SIZE));
    
    spaceMesh.addColor(ofColor::green);
    spaceMesh.addColor(ofColor::green);
    spaceMesh.addColor(ofColor::red);

    

}


/////////////////////////////////////
//  M E T H O D S
/////////////////////////////////////

void SpaceShip::init(){
    movement.location   = ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
    world               = ofRectangle(0, 0, ofGetWidth(), ofGetHeight());
}

void SpaceShip::init(ofVec2f location, ofRectangle _world){
    movement.location   = location;
    world               = _world;
}

void SpaceShip::update(){

    checkEdgesSpaceship();
    checkEdgesBullets();
    
    updateSpaceShip();
    updateBullets();
}

void SpaceShip::draw(){
 
//    draw Spaceship
    ofPushStyle();
    ofPushMatrix();
    
    ofSetColor(ofColor::white);
    
    ofTranslate(movement.location.x, movement.location.y);
    ofRotate(movement.rotation-45);
    spaceMesh.draw();
    
    
    ofPopMatrix();
    ofPopStyle();
    
//    draw bullets
    for (int i = 0; i < bullets.size(); i++) {
        ofCircle(bullets.at(i).location, 2);
    }
}

//  --------------------------------

void SpaceShip::rotatePlus(){
    movement.rotation+= ROTATION;
}

void SpaceShip::rotateMin(){
    movement.rotation-= ROTATION;
}

void SpaceShip::acceleratePlus(){
    movement.boost +=0.5;
}

void SpaceShip::accelerateMin(){
    
}

void SpaceShip::addBullet(){
    Bullet bullet;
    bullet.location = movement.location;
    bullet.life = BULLET_LIFE;
    bullet.velocity = ofVec2f(1,1);
    bullet.velocity.rotate(movement.rotation);
    bullet.velocity.normalize();
    bullet.velocity.scale(BULLET_SPEED);
    bullets.push_back(bullet);
    
}

void SpaceShip::removeBullet(int index){
    bullets.erase(bullets.begin()+index);
}


/////////////////////////////////////
//  P R I V A T E   M E T H O D S
/////////////////////////////////////

void SpaceShip::updateSpaceShip(){

    movement.boost -= 0.001;
    movement.boost = MAX(movement.boost, 0);
    movement.boost = MIN(movement.boost, 2);
    
    movement.velocity = ofVec2f(1,1);
    movement.velocity.rotate(movement.rotation);
    movement.velocity.normalize();
    movement.velocity.scale(movement.boost);
    movement.location += movement.velocity;
    
}

void SpaceShip::updateBullets(){
    for (int i = 0; i < bullets.size(); i++) {
        if (bullets.at(i).life<=0) {
            bullets.erase(bullets.begin()+i);
        }
    }
    
    for (int i = 0; i < bullets.size(); i++) {
        bullets.at(i).life --;
        
        bullets.at(i).location += bullets.at(i).velocity;
    }
    
}

void SpaceShip::checkEdgesSpaceship(){
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

void SpaceShip::checkEdgesBullets(){
    for (int i = 0; i < bullets.size(); i++) {
        if (bullets.at(i).location.x<world.x) {
            bullets.at(i).location.x = world.x+world.width;
        } else if (bullets.at(i).location.x>world.x+world.width){
            bullets.at(i).location.x = world.x;
        }
        
        if (bullets.at(i).location.y<world.y) {
            bullets.at(i).location.y = world.y+world.height;
        } else if (bullets.at(i).location.y>world.y+world.height){
            bullets.at(i).location.y = world.y;
        }

    }
}


/////////////////////////////////////
//  G E T T E R S  N  S E T T E R S
/////////////////////////////////////

ofVec2f SpaceShip::getLocation(){
    return movement.location;
}

void SpaceShip::setLocation(ofVec2f location){
    movement.location = location;
}

ofRectangle SpaceShip::getWorld(){
    return world;
}

void SpaceShip::setWorld(ofRectangle _world){
    world = _world;
}

int SpaceShip::getBulletAmount(){
    return bullets.size();
}

ofVec2f SpaceShip::getBulletLocation(int index){
    return bullets.at(index).location;
}




