/* Project 5C V.2: Traffic Light Controllers with Pedestrian Lights

Version History: 
Project 5A: Added Traffic Lights
Project 5B: Started Adding Functions for Traffic Lights
Project 5C: Functions for simplified code for Traffic in East and West directions
Project 5C V.2: Added Pedestrian lights
Project 5C V.3 : Added automated reset code for after pedestrian cross

Project description: Traffic Lights are functional for East and West Directions. The lights alternate from the directions. Also if the pedestrian button is pressed both pedestrian lights will stay on for 10 seconds. 
Project by: Trey Schnoor
*/
#define westButton 3
#define eastButton 13
#define pedButton 8
#define westRed 2
#define westYellow 1
#define westGreen 0
#define eastRed 12
#define eastYellow 11
#define eastGreen 10
#define yellowBlinkTime 500
#define westWhite 5  //Pedestrian Light
#define eastWhite 6  //Pedestrian Light

void changeYellowLight(int yellowDirection);
void changeGreenToRed(int greenDirection, int yellowDirection, int redDirection);
void changeRedToGreen(int redDirection, int yellowDirection, int greenDirection);
void changeWhiteLight(int pedestrianLight);
boolean trafficWest = true;  // west = true, east = false
int flowTime = 1000;         //Continues Traffic for set time
int changeDelay = 2000;      //Time in between light changes
int pedestrianDelay = 10000;
bool pedJustCrossed;  //boolean expression sets wether the pedestrian just crossed to true or false


void setup() {
  pinMode(westButton, INPUT);  //Setting up pins declared previously
  pinMode(eastButton, INPUT);
  pinMode(pedButton, INPUT);  //Pedestrian Button add-on
  pinMode(westRed, OUTPUT);
  pinMode(westYellow, OUTPUT);
  pinMode(westGreen, OUTPUT);
  pinMode(eastRed, OUTPUT);
  pinMode(eastYellow, OUTPUT);
  pinMode(eastGreen, OUTPUT);
  pinMode(westWhite, OUTPUT);  //Pedestrian add-on
  pinMode(eastWhite, OUTPUT);  //add-on

  digitalWrite(westRed, LOW);
  digitalWrite(westYellow, LOW);
  digitalWrite(westGreen, HIGH);
  digitalWrite(eastRed, HIGH);
  digitalWrite(eastYellow, LOW);
  digitalWrite(eastGreen, LOW);
  digitalWrite(westWhite, LOW);  //Pedestrian
  digitalWrite(eastWhite, LOW);
  pedJustCrossed = false;
}

void loop() {
  if ((digitalRead(westButton) == HIGH) || pedJustCrossed) {
    if (trafficWest != true) {

      trafficWest = true;
      delay(flowTime);


      /*  digitalWrite(eastGreen, LOW);

      digitalWrite(eastYellow, HIGH);
      delay(changeDelay);
      digitalWrite(eastYellow, LOW);
      digitalWrite(eastRed, HIGH);

      delay(changeDelay);*/
      if (!pedJustCrossed) changeGreenToRed(eastGreen, eastYellow, eastRed);  //Function is changing light from Green to Red
      pedJustCrossed = false;                                                 //Traffic Lights Reset automatically after pedestrian light
      /*
      for (int a = 0; a < 5; a++)  //Yellow Light will blink for 5 seconds
      {
        digitalWrite(westYellow, LOW);
        delay(yellowBlinkTime);
        digitalWrite(westYellow, HIGH);
        delay(yellowBlinkTime);
      }
    */
      changeYellowLight(westYellow);

      /*digitalWrite(westYellow, LOW);
      digitalWrite(westRed, LOW);
      digitalWrite(westGreen, HIGH);*/
      changeRedToGreen(westRed, westYellow, westGreen);  //Function is changing Red light to Green
    }
  }
  if ((digitalRead(eastButton) == HIGH) || pedJustCrossed) {
    if (trafficWest == true) {
      pedJustCrossed = false;
      trafficWest = false;
      delay(flowTime);


      /* digitalWrite(westGreen, LOW);
      digitalWrite(westYellow, HIGH);
      delay(changeDelay);
      digitalWrite(westYellow, LOW);
      digitalWrite(westRed, HIGH);
      delay(changeDelay); */

      if (!pedJustCrossed) changeGreenToRed(westGreen, westYellow, westRed);  //Function is changing Green Light to Red
      pedJustCrossed = false;                                                 //after pedestrian light the traffic lights reset automatically


      /*for ( int a = 0; a < 5; a++) //Yellow light will blink for 5 seconds
      {
        digitalWrite(eastYellow, LOW);
        delay(yellowBlinkTime);
        digitalWrite(eastYellow, HIGH);
        delay(yellowBlinkTime);
      } */
      changeYellowLight(eastYellow);

      /*digitalWrite(eastYellow, LOW);
      digitalWrite(eastRed, LOW);
      digitalWrite(eastGreen, HIGH);*/
      changeRedToGreen(eastRed, eastYellow, eastGreen);
      //changeWhiteLight(eastWhite);
    }
  }
  if (digitalRead(pedButton) == HIGH) {  //pedestrian button

    if (trafficWest == true) {
      trafficWest = false;                               //saying the West is Red meaning no traffic
      changeGreenToRed(westGreen, westYellow, westRed);  //pedestrian West
      //changeWhiteLight(eastWhite, westWhite);
    }

    else {
      changeGreenToRed(eastGreen, eastYellow, eastRed);  //pedestrian East
      trafficWest = true;
    }
    changeWhiteLight(eastWhite, westWhite);  //changing pedestrian lights with pedestrian button if traffic west is not false
    pedJustCrossed = true;
  }
}


void changeYellowLight(int yellowDirection) {  //Yellow Light is going to turn on and start blinking
  for (int a = 0; a < 5; a++)                  //Yellow light will blink for 5 seconds
  {
    digitalWrite(yellowDirection, LOW);
    delay(yellowBlinkTime);

    digitalWrite(yellowDirection, HIGH);
    delay(yellowBlinkTime);
  }
}

void changeGreenToRed(int greenDirection, int yellowDirection, int redDirection) {  //Light is changing from green to Red

  digitalWrite(greenDirection, LOW);

  digitalWrite(yellowDirection, HIGH);
  delay(changeDelay);

  digitalWrite(yellowDirection, LOW);

  digitalWrite(redDirection, HIGH);
  delay(changeDelay);
}


void changeRedToGreen(int redDirection, int yellowDirection, int greenDirection) {  // Light changes from Red to Green
  digitalWrite(yellowDirection, LOW);
  digitalWrite(redDirection, LOW);
  digitalWrite(greenDirection, HIGH);
}

void changeWhiteLight(int eastWhitePedestrianLight, int westWhitePedestrianLight) {  //function used for turning both pedestrian lights on

  digitalWrite(eastWhitePedestrianLight, HIGH);
  digitalWrite(westWhitePedestrianLight, HIGH);
  delay(pedestrianDelay);
  digitalWrite(eastWhitePedestrianLight, LOW);
  digitalWrite(westWhitePedestrianLight, LOW);
}
