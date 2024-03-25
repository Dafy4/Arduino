unsigned long start_times[100];
unsigned long stop_times[100];
unsigned long values[100];
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Test lancé\n");
  delay(1000);
  for(int i = 0;i < 100;i++)
  {
    start_times[i] = micros();
    values[i] = analogRead(2);
    stop_times[i] = micros();
    delay(100);
  }
  Serial.println("Resultats : ");
  for(int i = 0;i < 100;i++)
  {
    Serial.print("Valeur lue : ");
    Serial.print(values[i]);
    Serial.print(values[i]);
    Serial.print("en");
    Serial.print(stop_times[i]-start_times[i]);
    Serial.print("microsecondes");
  }
  delay(5000);
}
