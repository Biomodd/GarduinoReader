#include "biomoddWar.h"
#include "ofAppGlutWindow.h"

//--------------------------------------------------------------
int main(){
	ofAppGlutWindow window; // create a window
	// set width, height, mode (OF_WINDOW or OF_FULLSCREEN)
	ofSetupOpenGL(&window, 1920, 1200, OF_FULLSCREEN);
	ofRunApp(new biomoddWar()); // start the app
}