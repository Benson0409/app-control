#include <BluetoothSerial.h>
BluetoothSerial BT;  
int n=0;
int k=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  BT.begin("Bitch");//請改名 
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(26,OUTPUT);
  pinMode(25,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (BT.available()) {
    //讀取藍芽資料
    String BTdata=BT.readString();
    
  if(BTdata=="p1 get one point" && n==0){
    digitalWrite(13,HIGH);
    n++;
  }
  else if(BTdata=="p1 get one point" && n==1){
    digitalWrite(12,HIGH);
    n=0;
  }
  
  if(BTdata=="p2 get one point"&& k==0){
    digitalWrite(26,HIGH);
    k++;
  }
  else if(BTdata=="p2 get one point" && k==1){
    digitalWrite(25,HIGH);
    k=0;
  }

  if(BTdata=="new game"){
    digitalWrite(12,LOW);
    digitalWrite(13,LOW);
    digitalWrite(26,LOW);
    digitalWrite(25,LOW);
    n=0;
    k=0;
  }
  
    //顯示在序列視窗
    Serial.println(BTdata);
  }
  delay(1);
}
