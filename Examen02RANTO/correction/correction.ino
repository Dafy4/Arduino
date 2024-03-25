int led=13;
int bp=3;
int val_prec;
int bp_stat;
int bp_stat2;
int led_stat;
int a=0;
int b,c,e=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(bp,INPUT_PULLUP);
  digitalWrite(led,LOW);
  val_prec=1;
  bp_stat=0;
  bp_stat=0;
  led_stat=0;
}

void loop() {
  delay(10);
  int val=digitalRead(bp);
  if(val!=val_prec){
    Serial.print(val_prec);
    Serial.print("_to_");
    Serial.print(val);
    
  }else{
    if(val==0){
      bp_stat=bp_stat+10;
      if(bp_stat>1000){
        Serial.print("condition 1 verifier");
        if(e!=0){
          b=1;
        }else{
          b=0;
        }
      }
      bp_stat2=0;
    }else{
      if (b==1) {
        bp_stat2=bp_stat2+10;
        if (bp_stat2>2000 && bp_stat2<3000) {//miandry 2s à 3s
          Serial.print("condition 2 verifier");
          c=1;
        }
        else{
          c=0;
          Serial.print("condition 2 desactivé"); //miotrany 3s
        }
      }

      bp_stat=0;
      a = 0;
      e=1;
    }
    if(bp_stat>1000 && a!=1){
      if(led_stat==0){
        if(c==1){
          led_stat=1;
          digitalWrite(led,HIGH);
          Serial.println(".....on");
          c=0;e=0;
        }
      }else{
        led_stat=0;
        digitalWrite(led,LOW);
        Serial.println(".......off");
        b=0;c=0;e=0;
      }
      bp_stat=0;
      a=1;
    }
  }
  val_prec=val;
}
