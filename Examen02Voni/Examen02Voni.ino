int led = 13;
int bp = 3;
int val_prec;
int bp_stat;
int led_stat;
int a;
int push1 , push2 , bp_stat2 , bp_stat3 , attente;
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
  push1 = 0; push2 = 0; bp_stat2 = 0; bp_stat3 = 0; attente = 0;
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
          if(bp_stat <= 1500 && led_stat == 0 && push1 != 1){
            push1 = 1;
          }
          else{
            push1 = 0;
          }
          if(attente != 0 && led_stat == 0){
            bp_stat3 = bp_stat3 + 10;
            if(bp_stat3 <=  1000 ){
                 push2 = 1;
            }
            else{   B
              push2 = 0;
            }
          }²
          bp_stat2 = 0;
      }
      else{
          if(push1 == 1){
              bp_stat2 = bp_stat2 + 10;
              if(bp_stat2 > 1500 && bp_stat2 <= 2500){
                Serial.print("ok ok");
                  attente = 1;
              } 
              else{
                attente = 0;
              }
          }
          else{
            attente = 0;
          }
          bp_stat = 0;
          bp_stat3 = 0;   
          a = 1;
      }
 }
  if(bp_stat >  1000 && a != 0){
      if(led_stat == 0 && push2 == 1){
         led_stat = 1;
         digitalWrite(led,HIGH);
         Serial.println(".......ON");
         push1 = 0;push2 = 0;
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
