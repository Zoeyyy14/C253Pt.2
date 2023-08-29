const int buttonPin=2;
const int ledPin=13;
int x=1;
int ledState=LOW;
int buttonState;
int lastButtonState=LOW;
unsigned long lastDebounceTime=0;
unsigned long debounceDelay=10;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  digitalWrite(ledPin, ledState);
}

void loop() {
  int reading=digitalRead(buttonPin);
  if(reading != lastButtonState){
    lastDebounceTime=millis();
  }
  if((millis()-lastDebounceTime)>debounceDelay){
    if(reading != buttonState){
      buttonState=reading;
      if(buttonState == HIGH){
        ledState=!ledState;
        Serial.println(x);
        x++;
        if(x>10){
          x=1;
        }
      }
    }
  }
  digitalWrite(ledPin, ledState);
  lastButtonState=reading;
}
