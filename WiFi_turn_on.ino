void wifi_turn_onn(){

   Serial.print("Station mode initiated");
   WiFi.mode(WIFI_STA);                                                      //station mode (Wifi) start
   ssidl=(EEPROM.read(2));                                 // read ssid length
   passl=(EEPROM.read(3));                    // read ssid length
   ssidl_total=5+ssidl;                            //read ssid from EEPROM locations 5 to 50
   passl_total=51+passl;                     //read password from EEPROM locations 51 to onwards
   for (int i = 4; i < ssidl_total; i++)
    {
      ssid += char(EEPROM.read(i));                                  // read character by character
   
    }

     for (int k = 50; k < passl_total; k++)                        // read and write(+=) password
            {
               pass += char(EEPROM.read(k));
                          }
             ssid2 = String(ssid);
             pass2 = String(pass);    
         const char *ssid3 = ssid2.c_str();                      //making structure of ssid2
         const char *pass3 = pass2.c_str();             
    Serial.println("Connecting soon ");
    WiFi.begin(ssid3, pass3);                                         //wifi mode started
   
  Serial.println("Connecting to ");

  Serial.println(ssid3);
  Serial.println(pass3);
   while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
     delay(1000);
    if (digitalRead(reset_button)==1)                        // Reset device if not connected with wifi
    {
    Serial.println("Reset Device");
    EEPROM.write(1, 1);
                 EEPROM.commit();
     delay(1000);
        Serial.println("Device is restarting");
      ESP.restart();
    }
     
  }
   Serial.println("Connected");
   EEPROMread();
   timeClient.begin();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);        // FireBase Start

//  String timezone = Firebase.getString("CandleDevices/xYQ9HLzYlrNu05OoTRsRlIpmxHp2/First Floor/-Mb-rXa0sF6sxpoiOBqH/timeZone");        //not using
//
//  String hr=timezone.substring(4,6);
//  delay(500);
//       String mi=timezone.substring(7);
//  int g1=hr.toInt();
//int g2=mi.toInt();
//  
//Serial.print("Time Zone in minutes: ");Serial.println(g1*60+g2);
//  
//  const long  utcOffsetInSeconds = ((g1*60+g2)-540)*60; //3600;
// timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);
}
