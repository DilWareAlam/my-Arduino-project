int sensorPin = A0;   //Microphone Sensor Pin on analog 0
int WhiteLed   = 2;        
int greenLed = 3;           // voice detection led.
int buzzer   = 4;          // buzzer alarm.

int sensorValue = 0 ;

int threshold = 130; // sets threshold value for crying baby 100-130

void setup()
{

  Serial.begin(9600);
  pinMode(WhiteLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(sensorPin, INPUT);
  pinMode(greenLed, OUTPUT);
}

void loop()
{
  sensorValue = analogRead(sensorPin);         // read the analog value from the sound sensor

  if (sensorValue < threshold) // Sound of the crying baby (Measured by dBs)
  {
    digitalWrite(WhiteLed, HIGH);
    Serial.println("WhiteLed is on");

    digitalWrite(buzzer, LOW);
    Serial.println("Alarm is off");
    Serial.println("\n\n");
    //delay(5000);
    // The White LEDs stay on for 2 seconds

  }
  else {
    digitalWrite(WhiteLed, LOW);
    digitalWrite(greenLed, HIGH);
    Serial.println("grenLed is ON");

    digitalWrite(buzzer, HIGH);
    Serial.println("Alarm is on...!!! Baby is crying");

    Serial.println("");
  }
  delay(1000);
  digitalWrite(WhiteLed, LOW);
  digitalWrite(buzzer, LOW);
  digitalWrite(greenLed, LOW);

}
