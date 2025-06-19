void EEPROMread(){
    UserID1=(EEPROM.read(400));                                 // read UserID length
    DeviceGroup1=(EEPROM.read(500));                    // read DeviceGroup length
    DeviceID1=(EEPROM.read(600));                                 // read DeviceID length
   
   UserID1_total=402+UserID1;                            //read UserID from EEPROM locations 401 to 499
   DeviceGroup1_total=502+DeviceGroup1;                     //read DeviceGroupword from EEPROM locations 501 to 599
    DeviceID1_total=602+DeviceID1;                            //read DeviceID from EEPROM locations 601 to 700
   
   for (int i = 401; i < UserID1_total; i++)
    {
      UserID += char(EEPROM.read(i));                                  // read character by character
   
    }

     for (int k = 501; k < DeviceGroup1_total; k++)                        // read and write(+=) DeviceGroupword
            {
               DeviceGroup += char(EEPROM.read(k));
                          }
  
   for (int q = 601; q < DeviceID1_total; q++)
    {
      DeviceID += char(EEPROM.read(q));                                  // read character by character
   
    }                            
  
  String test = UserID + '{' ;
  Serial.println (test);
  
     int first1 = test.indexOf('{');
  //Serial.println("The index of > in the string " + string + " is " + first);
  UserID2=test.substring(0,first1);
  Serial.print ("UserID2 : ");
  Serial.println (UserID2);
  delay (1000);

///////////////////////////////////////////////////////////////////////////////////////////////
  
  String test1 = DeviceGroup + '{' ;
  Serial.println (test1);
  
     int first2 = test1.indexOf('{');
  //Serial.println("The index of > in the string " + string + " is " + first);
  DeviceGroup2=test1.substring(0,first2);
  Serial.print ("DeviceGroup2 : ");
  Serial.println (DeviceGroup2);
  delay (1000);

//////////////////////////////////////////////////////////////////////////////////////////////

     String test2 = DeviceID + '{' ;
  Serial.println (test2);
  
     int first3 = test2.indexOf('{');
  //Serial.println("The index of > in the string " + string + " is " + first);
  DeviceID2=test2.substring(0,first3);
  Serial.print ("DeviceID2 : ");
  Serial.println (DeviceID2);
  delay (1000);
//////////////////////////////////////////////////////////////////////////////////////////////////
}


void EEPROMwrite(){
  
 UserID1 = UserID.length(); 
 DeviceGroup1 = DeviceGroup.length();
 DeviceID1 = DeviceID.length();


 
 UserID1_total = 402+UserID1;
 DeviceGroup1_total=502+DeviceGroup1;
 DeviceID1_total=602+DeviceID1;

 
 EEPROM.write(400, UserID1);                    // save length of UserID
 EEPROM.commit();
 EEPROM.write(500, DeviceGroup1);                  // save length of DeviceGroup
 EEPROM.commit();
 EEPROM.write(600, DeviceID1);                    // save length of DeviceID
 EEPROM.commit();

 
  for (int i = 401; i < UserID1_total; i++)              // write UserID
            {
              delay(10);
              EEPROM.write(i, UserID[i-401]);
               EEPROM.commit();           }

            
            Serial.println("UserID saved");
  for (int k = 501; k < DeviceGroup1_total; k++)                  // write DeviceGroup
            {
              delay(10);
              EEPROM.write(k, DeviceGroup[k-501]);
               EEPROM.commit();           }
                
                 Serial.println("DeviceGroup saved");



  for (int q = 601; q < DeviceID1_total; q++)              // write DeviceID
            {
              delay(10);
              EEPROM.write(q, DeviceID[q-601]);
               EEPROM.commit();           }
            
            Serial.println("DeviceID saved");

}
