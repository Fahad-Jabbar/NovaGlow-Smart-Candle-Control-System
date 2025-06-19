void data_separatorr(){
                                                                         //separating it in substrings (Credentials)
  int first = string.indexOf('@');
  //Serial.println("The index of > in the string " + string + " is " + first);
  UserID=string.substring(0,first);
  Serial.println ("UserID");
  Serial.println (UserID);
  delay (1000);


  
  int secondOpen = first + 1;
  int secondClos = string.indexOf('@', secondOpen);
  //Serial.println("The index of  the second > in the string " + string + " is " + secondClos);
   DeviceGroup=string.substring(secondOpen,secondClos);
  Serial.println ("Device Group");
  Serial.println (DeviceGroup);
  delay (1000);



   int thirdOpen= secondClos + 1;
   int thirdClose = string.indexOf('@',thirdOpen);
  //Serial.println("The index of > in the string " + string + " is " + first);
  DeviceID=string.substring(thirdOpen,thirdClose);
  Serial.println ("Device ID");
  Serial.println (DeviceID);
  delay (1000);
  
EEPROMwrite();

  
  int forthOpen = thirdClose + 1;
  int forthClose = string.indexOf('@',forthOpen);
  //Serial.println("The index of  the second > in the string " + string + " is " + secondClos);
   ssid=string.substring(forthOpen,forthClose);
  Serial.println ("SSID");
  Serial.println (ssid);
  delay (1000);




  
   int fifthOpen = forthClose + 1;
  int fifthClose = string.indexOf('@',fifthOpen);
  //Serial.println("The index of  the second > in the string " + string + " is " + secondClos);
  pass=string.substring(fifthOpen,fifthClose);
  Serial.println ("Password");
  Serial.println (pass);
  delay (1000);


  
  server.send(200, "text/plain", "Data Received");

  

}
