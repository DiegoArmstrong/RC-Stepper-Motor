/*const int dirPin = 2;
const int stepPin = 5;
const int stepsPerRevolution = 200;

bool clockwise;  // Default direction is clockwise

void setup()
{
  Serial.begin(9600);
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
}

void loop()
{
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    int commaIndex = input.indexOf(',');

    if (commaIndex != -1) {
      clockwise = (input.substring(0, commaIndex) == "1");
      float angle = input.substring(commaIndex + 1).toFloat();

      int steps = angle * (float(stepsPerRevolution) / 360.0);

      digitalWrite(dirPin, clockwise ? HIGH : LOW);

      for (int i = 0; i < steps; i++) {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(2000);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(2000);
      }

      Serial.print(steps);
      Serial.println(clockwise);
    }

    while (Serial.available() > 0) {
      // Clear any remaining input in the serial buffer
      Serial.read();
    }
  }

  delay(1000);  // Add a small delay before next iteration
}*/

const int dirPin = 2;
const int stepPin = 5;
const int stepsPerRevolution = 200;

bool clockwise;  // Default direction is clockwise

void setup()
{
  Serial.begin(9600);
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
}

void loop()
{
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    
    if (input.charAt(0) == 'd') {
      clockwise = (input.charAt(2) == '1');
      Serial.println(clockwise);
      if(clockwise == true){
        digitalWrite(dirPin, HIGH);
      }
      else if(clockwise == false){
        digitalWrite(dirPin, LOW);
      }
    }
    else if (input.charAt(0) == 'a') {
      float angle = input.substring(2).toFloat();

      int steps = angle * (float(stepsPerRevolution) / 360.0);

      //digitalWrite(dirPin, clockwise ? HIGH : LOW);

      for (int i = 0; i < steps; i++) {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(2000);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(2000);
      }

      Serial.print(steps);
      //Serial.println(clockwise);
    }
  }

  delay(1000);  // Add a small delay before next iteration
}

