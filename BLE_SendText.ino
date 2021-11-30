#include <BluetoothSerial.h>
BluetoothSerial BT;  
bool LED_ON=false;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  BT.begin("HI-Bitch");//請改名 
  pinMode(13,OUTPUT);

 
}

void loop() {
  // put your main code here, to run repeatedly:
  while (BT.available()) {
    //讀取藍芽資料
    String BTdata=BT.readString();
    if(BTdata=="HI"){
    LED_ON=!LED_ON;
  }
  if(LED_ON==true){
      digitalWrite(13,HIGH);
  }
  else{
      digitalWrite(13,LOW);
  }
    //顯示在序列視窗
    Serial.println(BTdata);
  }
  delay(1);
}
