void motion_sense(){
                                            //Motion Sensor part begin
val = digitalRead(sensor);
if (val == HIGH){
      Serial.print("Motion detected!");
      count = count +1;
      
      if (count ==1 ){
          if (flame_value == 0){
  digitalWrite (spark,HIGH); Serial.println("Candle ON"); delay (3000); digitalWrite (spark,LOW);}

if (flame_value == 1){
Serial.println("Candle is already running");}  

flame_value = 1; 

        Serial.print("Current time ");
        Serial.print(HR);
        Serial.print(":");
        Serial.println(MN);

        if (MN>39 && MN<60){
  
MNs = map(MN,40,59,0,19);
if (HR==23){HRs = 0;}
if (HR<23){HRs = HR + 1;}
}


if(MN>-1 && MN<40) {
  MNs = MN + 20;
  HRs = HR;}
  
  
  }
  Serial.print("End Time ");
  Serial.print(HRs);
  Serial.print(":");
  Serial.println(MNs);

}   
          
  
            
  if (val == LOW && count > 1) {
      Serial.println("Motion stopped!");
      count = 0;
      }


if ((HRs==HR) && (MNs==MN)){
        digitalWrite (fan,HIGH);
        delay (1000);
        digitalWrite(fan,LOW);
        Serial.println("Candle OFF");
        flame_value = 0;
}



}
