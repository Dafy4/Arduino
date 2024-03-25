int led = 13;
int bp = 3;
int val_prec;
int bp_stat , bp_stat2 ;
int led_stat;
int a , b , c ,d , e;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(bp,INPUT_PULLUP);
  digitalWrite(led,LOW);
  val_prec = 1;
  bp_stat = 0;
  bp_stat2 = 0;
  led_stat = 0;
  a = 0 ; b = 0 ; c = 0 ; d = 0;e = 0;
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
      if(bp_stat > 1000){
        if( e == 1 && a != 1){
          digitalWrite(led,LOW);
          e = 0;
        }
        b = 1;
      }
      if(bp_stat > 1000 && c == 1){
        d = 1;
        bp_stat2 = 0;
      }
  }
  else{
    if(b = 1){
      bp_stat2 = bp_stat2 + 10;
      if(bp_stat2 > 2000){
       c = 1;  
      }
    }
    bp_stat = 0;
    a = 0;   
  }

  if(bp_stat > 1000 && a != 1){
      if(led_stat == 0 && d == 1){
         led_stat = 1;
         digitalWrite(led,HIGH);
         Serial.println(".......ON");
         b = 0; c = 0; d = 0; e = 1;
      }
      else{
          led_stat = 0;
          digitalWrite(led,LOW);
          Serial.println("........OFF");
        }
        
        bp_stat = 0;
        a = 1;
    }
  }
  val_prec = val;
}
