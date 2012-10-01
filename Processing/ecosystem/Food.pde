// Evolution EcoSystem
// Daniel Shiffman <http://www.shiffman.net>
// Spring 2007, The Nature of Code

// A collection of food in the world

class Food {
  ArrayList food;
 
  Food(int num) {
    // Start with some food
    food = new ArrayList();
    for (int i = 0; i < num; i++) {
       food.add(new PVector(random(width),random(height))); 
    }
  } 
  
  // Add some food at a location
  void add(PVector l) {
     food.add(l.get()); 
  }
  
  // Display the food
  void run() {
    for (int i = 0; i < food.size(); i++) {
       PVector loc = (PVector) food.get(i);
       rectMode(CENTER);
       fill(0,255,0);
       rect(loc.x,loc.y,8,8);
    } 
    
    // There's a small chance food will appear randomly
    if (gMoisture > 300) {
      int genChecker = int(random(gMoisture, gMoisture+10));
      
      if (genChecker == gMoisture + 1) {
         food.add(new PVector(random(width),random(height))); 
      }
    }
    
    gFoodCount = food.size();
    
    if (food.size() <= 10 && !isTempOn) {
      myPort.write('q');
      isTempOn = true;
    }
    
    if (food.size() > 11 && isTempOn) {
      myPort.write('w');
      isTempOn = false;
    }
    
    
  }
  
  // Return the list of food
  ArrayList getFood() {
    return food; 
  }
}
