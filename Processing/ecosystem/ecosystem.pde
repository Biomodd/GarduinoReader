// Evolution EcoSystem + Garduino
// Daniel Shiffman <http://www.shiffman.net>
// The Nature of Code
// Modified by: Bruno Kruse

// A World of creatures that eat food
// The more they eat, the longer they survive
// The longer they survive, the more likely they are to reproduce
// The bigger they are, the easier it is to land on food
// The bigger they are, the slower they are to find food
// When the creatures die, food is left behind
// Now Garduino supported!

// serial stuff
import processing.serial.*;     // import the Processing serial library
Serial myPort;                  // The serial port
boolean firstContact = false;   // Whether we've heard from the microcontroller

// Global parameters from Arduino to control the virtual world
int gMoisture;
int gLight;
int gTemperature;

int gFoodCount;
int gOrgCount;

boolean isTempOn = false;
boolean isLightOn = false;

// Game stuff
World world;

// Draw debug information
PFont font;

void setup() {
  size(600,400);
  
  rectMode(CORNER);
  
  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 9600);
 
  // World starts with 20 creatures and 20 pieces of food
  world = new World(20);
  smooth();
  
  font = loadFont("DINNeuzeitGroteskStd-Light-20.vlw");
  textFont(font, 16);
  
}

void draw() {
  
  // Control background of game via light value
  if (gLight >= 255) {
    gLight = 220;
  }
  
  background(gLight,gLight + 25, gLight);
  
  world.run();
  
  // Display debug information
  stroke(0);
  strokeWeight(1);
  
  fill(255,20,20);
  text("moisture: " + gMoisture, 10, 30);
  text("light: " + gLight, 10, 50);
  text("temperature: " + gTemperature, 10, 70);
  
  fill(255,20,20);
  text("totalFood: " + gFoodCount, 10, 120);
  text("totalOrganisms: " + gOrgCount, 10, 150);
}


// We can add a creature manually if we so desire
void mousePressed() {
  world.born(mouseX,mouseY); 
}

// Hard controls
void keyPressed() {
  
  if (key == 'q') {
      myPort.write('q');
  }
  
  if (key =='w') {
      myPort.write('w');
  }
  
}


