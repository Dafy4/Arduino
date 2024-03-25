int led = 13;
void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  digitalWrite(led,LOW);
  delay(2000);
  Serial.begin(9600);//Moniteur serie
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led,HIGH);
  Serial.println("Mirehitra");
  delay(1000);
  
  digitalWrite(led,LOW);
  Serial.print("Maty");
  delay(2000);
}
