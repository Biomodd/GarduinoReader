import processing.serial.*;     // import the Processing serial library
Serial myPort;                  // The serial port


boolean firstContact = false;        // Whether we've heard from the microcontroller

int sensor1;
int sensor2;
int sensor3;

void setup() {
  // List all the available serial ports
  println(Serial.list());

  // I know that the first port in the serial list on my mac
  // is always my  Arduino module, so I open Serial.list()[0].
  // Change the 0 to the appropriate number of the serial port
  // that your microcontroller is attached to.
  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 9600);
}

void draw() {
  // twiddle your thumbs
  
  //if (readRequest){
    
  //  myPort.write('r');
    
  //}
  
}

void serialEvent(Serial myPort) { 
  // read the serial buffer:
  String myString = myPort.readStringUntil('\n');
  // if you got any bytes other than the linefeed:
  if (myString != null) {

    myString = trim(myString);

    // if you haven't heard from the microncontroller yet, listen:
    if (firstContact == false) {
      if (myString.equals("hello")) { 
        myPort.clear();          // clear the serial port buffer
        firstContact = true;     // you've had first contact from the microcontroller
        myPort.write('r');       // ask for more
      } 
    } 
    // if you have heard from the microcontroller, proceed:
    else {
      // split the string at the commas
      // and convert the sections into integers:
      int sensors[] = int(split(myString, ','));

      // print out the values you got:
      for (int sensorNum = 0; sensorNum < sensors.length; sensorNum++) {
        print("Sensor " + sensorNum + ": " + sensors[sensorNum] + "\t"); 
      }
      // add a linefeed after all the sensor values are printed:
      println();
      
      if (sensors.length > 1) {
        
        sensor1 = sensors[0];
        sensor2 = sensors[1];
        sensor3 = sensors[2];
              
        //xpos = map(sensors[0], 430,580,0,width);
        //pos = map(sensors[1], 430,580,0,height);
        //fgcolor = sensors[2] * 255;
      }
    }
    // when you've parsed the data you have, ask for more:
    myPort.write("r");
  }
}
 

void keyPressed() {

  if (key == 'q') {
      myPort.write('q');
  }
  
  if (key =='w') {
      myPort.write('w');
  }
    
}
