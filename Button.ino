void button_start(){
  Statuscheck = "CandleDevices/";
Statuscheck += UserID2;
Statuscheck += "/";
Statuscheck += DeviceGroup2;
Statuscheck += "/";
Statuscheck += DeviceID2;  
Statuscheck += "/";
Statuscheck += "on";


String status_B = Firebase.getString(Statuscheck);
       Serial.print("on_status : ");
      Serial.println(status_B);

if (status_B == "ru" && buttonnumber ==0 ){
  Serial.println("BUTTON SY ON");
  if (flame_value == 0){
  digitalWrite (spark,HIGH); Serial.println("Candle ON"); delay (3000); digitalWrite (spark,LOW);}

if (flame_value == 1){
Serial.println("Candle is already running");}  

flame_value = 1;
buttonnumber=1;  
}

if (status_B == "als" && buttonnumber ==1 ){
  Serial.println("BUTTON SY OFF");
   digitalWrite (fan,HIGH); Serial.println("Candle OFF"); delay (5000); digitalWrite (fan,LOW);buttonnumber=0; flame_value = 0;
}



}
