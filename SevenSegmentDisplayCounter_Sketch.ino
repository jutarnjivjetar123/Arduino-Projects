  int led = 9;
  int sevenSegDisplayDP = 6;
  int sevenSegDisplayA = 2;
  int sevenSegDisplayB = 3;
  int sevenSegDisplayC = 4;
  int sevenSegDisplayD = 5;
  int sevenSegDisplayE = 7;
  int sevenSegDisplayF = 8;
  int sevenSegDisplayG = 10;


  const int displayPins[7] = {
    sevenSegDisplayA,
    sevenSegDisplayB,
    sevenSegDisplayC,
    sevenSegDisplayD,
    sevenSegDisplayE,
    sevenSegDisplayF,
    sevenSegDisplayG 
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
    {1, 1, 1, 1, 0, 1, 1} //8

  };
void setup() {
  
  for(int i = 0; i < 7; i++){
    pinMode(displayPins[i], OUTPUT);
  }
  

}

void loop() {

  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 7; j++){
      digitalWrite(displayPins[j], digitPatterns[i][j]);
    }
    delay(1000);
  }
  
  delay(1000);
  for (int i = 9; i >= 0; i--){
    for(int j = 6; j >= 0; j--){
      digitalWrite(displayPins[j], digitPatterns[i][j]);
    }
    delay(1000);
  }
 

}
