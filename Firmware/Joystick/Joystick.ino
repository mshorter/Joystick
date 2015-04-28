//Writen by Michelle Shorter 4/10/15 under beef licence (like beer licence, but I prefer a steak)

//Pins for buttons/joystick
//The I2C pins (D2,D3)are also brokent out as are the SPI pins on the ISP header
#define UP 7
#define RIGHT 5
#define DOWN 6
#define LEFT 4
#define JOYSTICK 8
#define Y A0
#define X A1

//variables
int up, right, down, left, joystick, y, x;

void setup() {
  Serial1.begin(9600); //XBee slot
  pinMode(UP,INPUT);
  pinMode(RIGHT,INPUT);
  pinMode(DOWN,INPUT);
  pinMode(LEFT,INPUT);
  pinMode(JOYSTICK,INPUT);
}

void loop() {
  // read all states
  up = digitalRead(UP);
  right = digitalRead(RIGHT);
  down = digitalRead(DOWN);
  left = digitalRead(LEFT);
  joystick = digitalRead(JOYSTICK);
  y = analogRead(Y);
  x = analogRead(X);
  
  // write to XBee
  if (up==1) Serial1.print("W");
  if (right==1) Serial1.print("D");
  if (down==1) Serial1.print("S");
  if (left==1) Serial1.print("A");
  if (joystick==1) Serial1.print("Z");
  if (y<400) Serial1.print("W");
  if (y>600) Serial1.print("S");
  if (x>600) Serial1.print("D");
  if (x<400) Serial1.print("A");
  if (up==0 && right==0 && down==0 && left==0 && y>450 && y<550 && x>450 && x<550) Serial1.print("Z");
  
  //delay to we aren't tripping over ourselves
  delay(25);

}

