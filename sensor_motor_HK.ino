#define sensorPin A0

#define motorA_1 2
#define motorA_2 3

#define motorB_1 4
#define motorB_2 5

#define pump 8

int sensorValue = 0;

 
void setup()
{
   pinMode(sensorPin, INPUT);

   pinMode(motorA_1, OUTPUT);
   pinMode(motorA_2, OUTPUT);
   
   pinMode(motorB_1, OUTPUT);
   pinMode(motorB_2, OUTPUT);

   pinMode(pump, OUTPUT);

   Serial.begin(9600);
}


void loop()
{
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);

  if(sensorValue > 100)
  {
    digitalWrite(motorA_1, HIGH);
    digitalWrite(motorA_2, LOW);
    digitalWrite(motorB_1, HIGH);
    digitalWrite(motorB_2, LOW);

    digitalWrite(pump, LOW);

    Serial.println("Rotating, no fire, pump not working");
  }
  else if(sensorValue < 100)
  {
    digitalWrite(motorA_1, LOW);
    digitalWrite(motorA_2, LOW);
    digitalWrite(motorB_1, LOW);
    digitalWrite(motorB_2, LOW);

    digitalWrite(pump, HIGH);

    Serial.println("Not rotating, fire detected, pump working");
  }
  else
  {
    Serial.println("Error");
  }

  delay(300);
}
