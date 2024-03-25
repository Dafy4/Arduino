//Traceur serie
int cap = 3;
void setup() {
  // put your setup code here, to run once:
  pinMode(cap,INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = digitalRead(cap);
  Serial.println(val);
  delay(100);
}
