import processing.serial.*;
 
Serial myPort;
String myString = null;

int angle = 0;
int distance1 = 0;
 
void setup(){
  fullScreen();
  background(0);
  
  // open the serial port
  // change "COM3" to your arduino port name such as "COM~" in Windows, "/dev/tty~~~" in Mac
  myPort = new Serial(this, "COM3", 9600);
  
}
 
void draw(){
  
  noStroke();
  fill(0,10);
  rect(0,0,width,height);
  drawRader();
  drawLine();
}

void serialEvent(Serial p){
  
  try{
    myString = p.readStringUntil('.');
    String[] list = split(myString, ',');
    angle = int(list[0]);
    distance1 = int(list[1]);
    
  }catch(Exception e){    
  }
}
 
void drawRader(){
  
  pushMatrix();
  
  translate(width/2, height); //line length
  noFill();
  strokeWeight(2); //line thicknes
  stroke(98, 245, 31);
  
  // draw the arc lines
  arc(0, -width/2, width, width, 0, TWO_PI);
  arc(0, -width/2, width*3/4, width*3/4, 0, TWO_PI);
  arc(0, -width/2, width*2/4, width*2/4, 0, TWO_PI);
  arc(0, -width/2, width*1/4, width*1/4, 0, TWO_PI);
  
  arc(0, 0, width, width, PI, PI);
  
  textSize(15);
  fill(98, 245, 31);
  textAlign(RIGHT);
  text("10cm", width*1/8, -350);
  text("20cm", width*2/8, -350);
  text("30cm", width*3/8, -350);
  text("40cm", width*4/8, -350);
  
  popMatrix();
}
 
void drawLine(){
  
  pushMatrix();
  
  strokeWeight(10); //point thickness
  stroke(255,10, 10); // red color
  
  float d1 = (width/2.0/40.0)*(float)distance1;
  line(width/2,width/2, width/2-(d1*cos(radians(angle))),width/2-(d1*sin(radians(angle))));
  
  popMatrix();
}
