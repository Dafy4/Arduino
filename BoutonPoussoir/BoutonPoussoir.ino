int led = 13; 
int bouton = 3;
int valeur;
void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  pinMode(bouton,INPUT_PULLUP);
  digitalWrite(led,LOW);
  digitalWrite(bouton,LOW);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  valeur = digitalRead(3);
  if(valeur == 1){
    digitalWrite(led,HIGH);
    //valeur = analogRead(3);
    Serial.println(valeur);
  }
  else
  {
    digitalWrite(led,LOW);
    //valeur = analogRead(3);
    Serial.println(valeur);
  }
}
