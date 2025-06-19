void Setting()                                     //function for saving ssid and password in EEPROM
{
 ssidl=ssid.length(); 
 passl=pass.length();
 
 ssidl_total=5+ssidl;
 passl_total=51+passl;
 
 EEPROM.write(2, ssidl);                    // save length of ssid
 EEPROM.commit();
 EEPROM.write(3, passl);                  // save length of pass
 EEPROM.commit();
  for (int i = 4; i < ssidl_total; i++)              // write ssid
            {
              delay(10);
              EEPROM.write(i, ssid[i-4]);
               EEPROM.commit();           }
            
            Serial.println("ssid saved");
  for (int k = 50; k < passl_total; k++)                  // write password
            {
              delay(10);
              EEPROM.write(k, pass[k-50]);
               EEPROM.commit();           }
                
                 Serial.println("pass saved");
                EEPROM.write(1, 20);
                 EEPROM.commit();
                        delay(2000);
                         Serial.println("Device is restarting");
           ESP.restart();
}
