int led = 13;
int bouton = 3;
int etatBouton;
int valeurBouton = 1;
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
  etatBouton = digitalRead(3);
  if(etatBouton == 0)
  {
    delay(1000);
    valeurBouton = valeurBouton + 1;
    Serial.print("Niova");
  }
  
  
  if(valeurBouton%2 == 0){
    digitalWrite(led,HIGH);
    Serial.println(valeurBouton);
  }
  else
  {
    digitalWrite(led,LOW);
    Serial.println(valeurBouton);
  }
}
