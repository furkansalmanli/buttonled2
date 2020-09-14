int delayTime = 40;    // A variable to set a delay time between each LED
int currentLED = 0;     // A variable to store which LED we are currently working on
int current2LED= 3;
int current3LED = 3;
int dir = 1;    // A variable to store the direction of travel
int dir2= -1;
long timeChanged = 0;     // A variable to store the last time we changed something
byte ledPin[] = {3,4, 5, 6, 7, 8, 9};      // An array to hold the value for each LED pin
const int BUTTON = 10;
const int BUTTON2 = 11;
const int BUTTON3 = 12;
int val = 0;
int val1=0;
int val2=0;

void setup() {
for (int i=0; i<7; i++) {// Set all pins for OUTPUT
pinMode(ledPin[i], OUTPUT);
}
    // Record the time once the setup has completed
pinMode(BUTTON, INPUT); 
pinMode(BUTTON2, INPUT);
pinMode(BUTTON3, INPUT);
timeChanged = millis();
}
void loop() {
  val = digitalRead(BUTTON); 
  val1= digitalRead(BUTTON2);
  val2= digitalRead(BUTTON3);
  if (val == HIGH) {
      if ((millis() - timeChanged) > delayTime) {     // Check whether it has been long enough
      for (int i=0; i<7; i++) {    //turn off all of the LEDs
      digitalWrite(ledPin[i], LOW);
      }
      delay(200);
      digitalWrite(ledPin[currentLED], HIGH);    // Light the current LED
      currentLED = currentLED + dir;      // Increase the direction value (up or down)
      if (currentLED == 7) {       // If we are at the end of a row, change direction
      dir = -1;
      }
      if (currentLED == 0) {
      dir = 1;
      }
      timeChanged = millis();     // store the current time as the time we last changed LEDs
      }

    } if(val1 == HIGH) {
       
      if ((millis() - timeChanged) > delayTime) {     // Check whether it has been long enough
      for (int i=0; i<7; i++) {    //turn off all of the LEDs
      digitalWrite(ledPin[i], LOW);
      }
      delay(500);
      
      digitalWrite(ledPin[current2LED], HIGH);    // Light the current LED
      digitalWrite(ledPin[current3LED], HIGH); 
      
      current2LED = current2LED + dir;      // Increase the direction value (up or down)
      current3LED = current3LED + dir2;
     
      if (current2LED ==6) {       // If we are at the end of a row, change direction
      dir = -1;
      }
      if (current2LED == 3 ) {
      dir = 1;
      }
      if(current3LED == 3){
       dir2 = -1;
      }
      if(current3LED == 0){
        dir2 = 1;
      }
      timeChanged = millis();     // store the current time as the time we last changed LEDs
      }
          
      }

      if(val2 == HIGH) {
       
      digitalWrite(ledPin[0],HIGH); 
      digitalWrite(ledPin[1],HIGH);  
      digitalWrite(ledPin[2],HIGH);  
      digitalWrite(ledPin[3],HIGH);  
      digitalWrite(ledPin[4],HIGH);  
      digitalWrite(ledPin[5],HIGH);  
      digitalWrite(ledPin[6],HIGH);   
      delay(200);
      digitalWrite(ledPin[0],LOW); 
      digitalWrite(ledPin[1],LOW);  
      digitalWrite(ledPin[2],LOW);  
      digitalWrite(ledPin[3],LOW);  
      digitalWrite(ledPin[4],LOW);  
      digitalWrite(ledPin[5],LOW);  
      digitalWrite(ledPin[6],LOW); 
      }
     
      

}

