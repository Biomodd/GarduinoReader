import oscP5.*;
import netP5.*;
 
OscP5 oscP5;
NetAddress myRemoteLocation;
 
int msgCount;

void setup() {
  
  msgCount = 0; 
  
  size(400,400);
 
  // start oscP5, telling it to listen for incoming messages at port 5001 */
  oscP5 = new OscP5(this, 5001);
 
  // set the remote location to be the localhost on port 5001
  myRemoteLocation = new NetAddress("127.0.0.1",5001);
}
 
void draw()
{
 
}
 
void mousePressed() {  
  
  msgCount ++;
  
  // create an osc message
  OscMessage myMessage = new OscMessage("/test");
 
  myMessage.add("msg received: "); // add a float to the osc message 
  myMessage.add(msgCount); // add a string to the osc message
 
  // send the message
  oscP5.send(myMessage, myRemoteLocation); 
}

 
/*
void oscEvent(OscMessage theOscMessage) 
{  
  // get the first value as an integer
  int firstValue = theOscMessage.get(0).intValue();
 
  // get the second value as a float  
  float secondValue = theOscMessage.get(1).floatValue();
 
  // get the third value as a string
  String thirdValue = theOscMessage.get(2).stringValue();
 
  // print out the message
  print("OSC Message Recieved: ");
  print(theOscMessage.addrPattern() + " ");
  println(firstValue + " " + secondValue + " " + thirdValue);
}
*/
