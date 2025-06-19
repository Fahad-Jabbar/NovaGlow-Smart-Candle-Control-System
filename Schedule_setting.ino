void schedule(){
 // CandleDevices/tpPfC1ylOmPLxvjledxn0FJ3PXJ3/OFFICE/Office Candles/scheduleEnd
path_t_start = "CandleDevices/";
path_t_start += UserID2;
path_t_start += "/";
path_t_start += DeviceGroup2;
path_t_start += "/";
path_t_start += DeviceID2;
path_t_start += "/";
path_t_start += "scheduleStart";


path_T_end = "CandleDevices/";
path_T_end += UserID2;
path_T_end += "/";
path_T_end += DeviceGroup2;
path_T_end += "/";
path_T_end += DeviceID2;  
path_T_end += "/";
path_T_end += "scheduleEnd";


//Data_check = "CandleDevices/";
//Data_check += "tpPfC1ylOmPLxvjledxn0FJ3PXJ3";
//Data_check += "/";
//Data_check += "OFFICE";
//Data_check += "/";
//Data_check += "Office Candles";
//Data_check += "/";
//Data_check += "scheduleEnd";
  
//   String End = Firebase.getString("CandleDevices/tpPfC1ylOmPLxvjledxn0FJ3PXJ3/OFFICE/Office Candles/scheduleEnd");       //getting scheduleEnd time from firebase
     String End = Firebase.getString(path_T_end);       //getting scheduleEnd time from firebase
  Serial.print("End : ");
  Serial.println(End);
// Endhr=End.substring(0,1);
// Serial.println(Endhr);
 int frst = End.indexOf(':');                                          //separating hours and minutes from firebase string
  //Serial.println("The index of > in the string " + string + " is " + first);
  Endhr=End.substring(0,frst);
  Serial.println ("End Hours");
  Serial.println (Endhr);
  delay (100);
  int secondOpn = frst + 1;
  int secondClo = End.indexOf(' ', secondOpn);
  //Serial.println("The index of  the second > in the string " + string + " is " + secondClos);
   Endmn=End.substring(secondOpn,secondClo);
  Serial.println ("End Minutes");
  Serial.println (Endmn);
  delay (100);
 int endhr=Endhr.toInt();
 int endmn=Endmn.toInt();
if (HR==endhr && MN==endmn && ScheduleOFF==0)
{digitalWrite (fan,HIGH); Serial.println("Candle OFF"); delay (5000); digitalWrite (fan,LOW); flame_value = 0;ScheduleOFF =1;}

if ((HR>endhr || MN>endmn) && ScheduleOFF==1) 
{ScheduleOFF=0;}










//getting scheduleStart time from firebase

 //String Start = Firebase.getString("CandleDevices/tpPfC1ylOmPLxvjledxn0FJ3PXJ3/OFFICE/Office Candles/scheduleStart");
  String Start = Firebase.getString(path_t_start);
  Serial.print("start : ");
  Serial.println(Start);
// Endhr=End.substring(0,1);
// Serial.println(Endhr);
 int first = Start.indexOf(':');
  //Serial.println("The index of > in the string " + string + " is " + first);
  StartHr=Start.substring(0,first);
  Serial.println ("Start Hours");
  Serial.println (StartHr);
  delay (100);
  int secondOpen = first + 1;
  int secondClose = Start.indexOf(' ', secondOpen);
  //Serial.println("The index of  the second > in the string " + string + " is " + secondClos);
   StartMn=Start.substring(secondOpen,secondClose);
  Serial.println ("Start Minutes");
  Serial.println (StartMn);
  delay (100);
 int startHr=StartHr.toInt();
 int startMn=StartMn.toInt();

if (HR==startHr && MN==startMn){ 
      if (flame_value == 0){
digitalWrite(spark,HIGH); Serial.println("Candle ON"); delay (3000); digitalWrite (spark,LOW);}

      if (flame_value == 1){
Serial.println("Candle is already running");}  

flame_value = 1;
  }
 
                                           
                                           
                                           
                                           
      
}
