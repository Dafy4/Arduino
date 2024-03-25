int led = 13;
int bp = 3;
int val_prec;
int bp_stat;
int led_stat;
int a;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(bp,INPUT_PULLUP);
  digitalWrite(led,LOW);
  val_prec = 1;
  bp_stat = 0; 
  led_stat = 0;
  a = 1;
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(10);
  int val = digitalRead(bp);
  if(val!=val_prec){
    Serial.print(val_prec);
    Serial.print("_to_");
    Serial.println(val);
  }
  else{
      if(val == 0){
          bp_stat = bp_stat + 10;
      }
      else{
          bp_stat = 0;   
          a = 1;
      }
 }
  if(bp_stat > 1000 && a != 0){
      if(led_stat == 0){
         led_stat = 1;
         digitalWrite(led,HIGH);
         Serial.println(".......ON");
      }
      else{
          led_stat = 0;
          digitalWrite(led,LOW);
          Serial.println("........OFF");
      }
      bp_stat = 0;
      a = 0;
    }
  val_prec = val;
}
