/* Project 5A: Traffic Light Controllers
Project description: This program uses code to program traffic lights. The lights are East and West oriented. 
They vary inversley the time on for the green and red lights are 10 seconds. 
The yellow light will flash for 5 seconds in between green and red.
*/
#define westButton 3
#define eastButton 13
#define westRed 2
#define westYellow 1
#define westGreen 0
#define eastRed 12
#define eastYellow 11
#define eastGreen 10
#define yellowBlinkTime 500

void changeYellowLight(int yellowDirection);
void changeGreenToRed(int greenDirection, int yellowDirection, int redDirection);
void changeRedToGreen(int redDirection, int yellowDirection, int greenDirection);
boolean trafficWest = true;  // west = true, east = false
int flowTime = 1000;         //Continues Traffic for set time
int changeDelay = 2000;      //Time in between light changes



void setup() {
  pinMode(westButton, INPUT);  //Setting up pins declared previously
  pinMode(eastButton, INPUT);
  pinMode(westRed, OUTPUT);
  pinMode(westYellow, OUTPUT);
  pinMode(westGreen, OUTPUT);
  pinMode(eastRed, OUTPUT);
  pinMode(eastYellow, OUTPUT);
  pinMode(eastGreen, OUTPUT);

  digitalWrite(westRed, LOW);
  digitalWrite(westYellow, LOW);
  digitalWrite(westGreen, HIGH);
  digitalWrite(eastRed, HIGH);
  digitalWrite(eastYellow, LOW);
  digitalWrite(eastGreen, LOW);
}

void loop() {
  if (digitalRead(westButton) == HIGH) {
    if (trafficWest != true) {
      trafficWest = true;
      delay(flowTime);


      /*  digitalWrite(eastGreen, LOW);

      digitalWrite(eastYellow, HIGH);
      delay(changeDelay);
      digitalWrite(eastYellow, LOW);
      digitalWrite(eastRed, HIGH);

      delay(changeDelay);*/
      changeGreenToRed(eastGreen, eastYellow, eastRed);  //Function is changing light from Green to Red
      
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
      changeRedToGreen(westRed, westYellow, westGreen); //Function is changing Red light to Green
    }
  }
  if (digitalRead(eastButton) == HIGH) {
    if (trafficWest == true) {
      trafficWest = false;
      delay(flowTime);


      /* digitalWrite(westGreen, LOW);
      digitalWrite(westYellow, HIGH);
      delay(changeDelay);
      digitalWrite(westYellow, LOW);
      digitalWrite(westRed, HIGH);
      delay(changeDelay); */

      changeGreenToRed(westGreen, westYellow, westRed); //Function is changing Green Light to Red


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
    }
  }
}


void changeYellowLight(int yellowDirection) { //Yellow Light is going to turn on and start blinking
  for (int a = 0; a < 5; a++)  //Yellow light will blink for 5 seconds
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


void changeRedToGreen(int redDirection, int yellowDirection, int greenDirection) { // Light changes from Red to Green
  digitalWrite(yellowDirection, LOW);
  digitalWrite(redDirection, LOW);
  digitalWrite(greenDirection, HIGH);
}
