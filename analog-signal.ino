int analog = A0;
int led[] = {8, 9, 10};
int i;
int temperature;
void setup() {
  Serial.begin(9600);
  for (i = 0; i < 3; i++) {
    pinMode(led[i], OUTPUT);

  }

}

void loop() {

  int value = analogRead(analog);
  Serial.print("Gia tri Analog: ");
  Serial.print(value);
  temperature = map(value, 0, 1023, 0, 100);
  Serial.print("  - Gia tri nhiet do: ");
  Serial.println(temperature);
  delay(2000);
  if (temperature < 30) {
    digitalWrite(led[0], LOW);
    digitalWrite(led[1], LOW);
    digitalWrite(led[2], LOW);
  }
  else if ((temperature <= 50) and (temperature >= 30)) {
    digitalWrite(led[0], HIGH);
    digitalWrite(led[1], LOW);
    digitalWrite(led[2], LOW);
  }
  else if ((temperature > 50) and (temperature <= 80)) {
    digitalWrite(led[0], LOW);
    digitalWrite(led[1], HIGH);
    digitalWrite(led[2], LOW);
  }
  else if (temperature > 80) {
    digitalWrite(led[0], LOW);
    digitalWrite(led[1], LOW);
    digitalWrite(led[2], HIGH);
  }
}

