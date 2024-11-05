int segPoint = 2;
int segA = 3;
int segB = 4;
int segC = 5;
int segD = 6;
int segE = 10;
int segF = 8;
int segG = 9;

int buttonPin = 7;


const int displayPins[8] = {
  segA,
  segB,
  segC,
  segD,
  segE,
  segF,
  segG,
  segPoint
};

const byte digitPatterns[10][7] = {
    
  // A, B, C, D, E, F, G
    {1, 1, 1, 1, 1, 1, 0}, //0
    {0, 1, 1, 0, 0, 0, 0}, //1
    {1, 1, 0, 1, 1, 0, 1}, //2
    {1, 1, 1, 1, 0, 0, 1}, //3
    {0, 1, 1, 0, 0, 1, 1}, //4
    {1, 0, 1, 1, 0, 1, 1}, //5
    {1, 0, 1, 1, 1, 1, 1}, //6
    {1, 1, 1, 0, 0, 0, 0}, //7
    {1, 1, 1, 1, 1, 1, 1}, //8
    {1, 1, 1, 1, 0, 1, 1} //9

  };


//Declare variables for button
int currentButtonState = LOW;
int lastButtonState = LOW;
int buttonPressCounter = 0;
bool isIncrementing = true;


void setup() {
  // put your setup code here, to run once:
  
  //Begin serial reading
  Serial.begin(9600);

  //Declare Button pin on 7 as input
  pinMode(buttonPin, INPUT);

  //For each segment declare their pin as output 
  for(int i = 0; i < 8; i++){
    pinMode(displayPins[i], OUTPUT);
  }
  

  //Start animation

  //Turn on each of the segments individually, then after 100 ms turn them off
  for(int i = 0; i < 8; i++){
    digitalWrite(displayPins[i], HIGH);
    delay(100);
    digitalWrite(displayPins[i], LOW);
  }

  delay(200);
  //
  for(int i = 0; i < 8; i++){
    digitalWrite(displayPins[i], HIGH);
  }

  delay(300);

  for(int i = 0; i < 8; i++){
    digitalWrite(displayPins[i], LOW);
  }

  delay(200);
  //
  for(int i = 0; i < 8; i++){
    digitalWrite(displayPins[i], HIGH);
  }

  delay(300);

  for(int i = 0; i < 8; i++){
    digitalWrite(displayPins[i], LOW);
  }
  delay(100);


   for(int i = 0; i < 8; i++){
      digitalWrite(displayPins[i], digitPatterns[0][i]);
    }

}

void loop() {
  // put your main code here, to run repeatedly:

  currentButtonState = digitalRead(buttonPin);
  Serial.println("Button state: ");
  Serial.println(currentButtonState);
  if(currentButtonState == HIGH && lastButtonState == LOW){
    Serial.println("Press count: ");
   
      
    
    if(isIncrementing){
      buttonPressCounter++;
      
      if(buttonPressCounter < 10){
        
        for(int i = 0; i < 7; i++){
          digitalWrite(displayPins[i], digitPatterns[buttonPressCounter][i]);
        }
      }

      if(buttonPressCounter == 10){
        isIncrementing = false;
      }
    } 
    if(!isIncrementing){
      buttonPressCounter--;
      if(buttonPressCounter == 0){
        isIncrementing = true;
      }
      if(buttonPressCounter >= 0){
        
        for(int i = 6; i > -1; i--){
          digitalWrite(displayPins[i], digitPatterns[buttonPressCounter][i]);
        }
      }

      
    }
   

    



  }
    lastButtonState = currentButtonState;
  
}
