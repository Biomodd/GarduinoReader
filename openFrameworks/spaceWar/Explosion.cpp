
#include "Explosion.h"

/*=============================================
 EXPLOSION CLASS
 
 This class will be dealing with the explosions
 of the spaceShip when it is destroyed & with
 the explosion of asteroids when they are hit.
 ----------------------------------------------
 [ Explosion.cpp]
 ===============================================*/


/////////////////////////////////////
//  C O N S T R U C T O R
/////////////////////////////////////

Explosion::Explosion(){
    fbo.allocate(10,10);
}


/////////////////////////////////////
//  M E T H O D S
/////////////////////////////////////
void Explosion::addExplosion(ofVec2f location, int size){
    Explode explode;
    explode.location = location;
    explode.life = 10;
    explode.size = size;
    explosions.push_back(explode);
    
    
}

void Explosion::update(){
    
    ofImage img;
    // this defines the quality, for example dividing by 8 results worst quality
    fbo.allocate(10,10, GL_RGB);
    fbo.readToPixels(img.getPixelsRef());
    
    string compressedFilename = "compressed.jpg";
    img.saveImage(compressedFilename, OF_IMAGE_QUALITY_WORST);
    ofBuffer file = ofBufferFromFile(compressedFilename);
    
    
    int fileSize = file.size();
    char * buffer = file.getBinaryBuffer();
    int whichByte = (int) ofRandom(fileSize);
    int whichBit = ofRandom(8);
    char bitMask = 1 << whichBit;
    buffer[whichByte] |= bitMask;
    ofBufferToFile(compressedFilename, file);
    img.loadImage(compressedFilename);
    
    for (int y = 0; y < img.height; y++) {
        for (int x = 0; x < img.width; x++) {
//            float angle = ofMap(y*img.width+x, 0, img.width*img.height, 0, 360);
//            ofVec2f loc = ofVec2f(sin(angle)*img.width/4 + img.width/2, cos(angle)*img.width/4 + img.width/2);
            
            if (ofVec2f(x,y).distance(ofVec2f(img.width/2,img.height/2))> img.width/2) {
                img.setColor(x, y, ofColor::black);
            }
            

        }
    }
    ofEnableAlphaBlending();
    fbo.allocate(100, 100, GL_RGBA);
    fbo.begin();
    img.draw(0,0, 100, 100);
    fbo.end();
    

    for (int i = 0; i < explosions.size(); i++) {
        explosions.at(i).life --;
        if (explosions.at(i).life < 0) {
            explosions.erase(explosions.begin()+i);
        }
    }

    /*
    for (int i = 0; i<explosions.size(); i++) {
        cout << "updating explosion " << i << endl;
        ofImage img;
        img.allocate(explosions.at(i).size, explosions.at(i).size, OF_IMAGE_COLOR
                     );
        
        explosions.at(i).life --;
        explosions.at(i).fbo.allocate(explosions.at(i).size, explosions.at(i).size, GL_RGB);
        explosions.at(i).fbo.readToPixels(img.getPixelsRef());
        
        string compressedFilename = "compressed.jpg";
        img.saveImage(compressedFilename, OF_IMAGE_QUALITY_WORST);
        ofBuffer file = ofBufferFromFile(compressedFilename);
        
        
        int fileSize = file.size();
        char * buffer = file.getBinaryBuffer();
        int whichByte = (int) ofRandom(fileSize);
        int whichBit = ofRandom(8);
        char bitMask = 1 << whichBit;
        buffer[whichByte] |= bitMask;
        ofBufferToFile(compressedFilename, file);
        img.loadImage(compressedFilename);
        
        explosions.at(i).fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGB);
        explosions.at(i).fbo.begin();
        img.draw(0,0,explosions.at(i).size, explosions.at(i).size);
        explosions.at(i).fbo.end();
    }
     
     */

    
}

void Explosion::draw(){

    for (int i = 0; i < explosions.size(); i++) {
        ofVec2f location = explosions.at(i).location;
        int size = explosions.at(i).size  * 4;
        location.x = location.x - size/2;
        location.y = location.y - size/2;
        fbo.draw(location.x, location.y, size, size);
    }
    
}


/////////////////////////////////////
//  P R I V A T E   M E T H O D S
/////////////////////////////////////


/////////////////////////////////////
//  G E T T E R S  N  S E T T E R S
/////////////////////////////////////


