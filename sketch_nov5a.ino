const int LED_PIN = 3;
const int BUTTON_PIN = 7;

bool ledState = LOW;
bool lastButtonState = LOW;
bool currentButtonState;
int buttonPressCounter = 0;
void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  

  currentButtonState = digitalRead(BUTTON_PIN);
  
}

void loop() {

lastButtonState = currentButtonState;

  currentButtonState = digitalRead(BUTTON_PIN);

  if(lastButtonState == HIGH && currentButtonState == LOW){

    
      ledState = !ledState;
      digitalWrite(LED_PIN, ledState);
      buttonPressCounter++;
      Serial.println(buttonPressCounter);
    
    delay(50);
  }

  
}
