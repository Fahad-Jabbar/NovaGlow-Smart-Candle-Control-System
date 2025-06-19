/*
 * Candle Code (Hotspot, Wifi, Firebase, Strings_Separation, NTP)
 * 
 */
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <WiFi.h>
#include <WiFiClient.h> 
#include <WebServer.h>
#include <EEPROM.h>
WebServer server(80); 
#include "time.h"
#include <AsyncTCP.h>
#include <IOXhop_FirebaseESP32.h>
#define FIREBASE_HOST "candle-base-default-rtdb.firebaseio.com"                         // the project name address from firebase id
#define FIREBASE_AUTH "sLAnL7aheYCA57zqTBGxJaXqjTPs9J69D5XlE4KA"                    // the secret key generated from firebase
const char *h_ssid = "Smart Candle"; // The name of the Wi-Fi network that will be created
const char *h_password = "cAnDlE123";  // Pointer to password (ppass) string- editable

                                                                                   //initilazing pins of ESP32
int sensor =12;  
int spark= 26;
int fan= 5;


int ScheduleOFF = 0;
int flame_value = 0;
int buttonnumber = 0;

int val = 0;
int count = 0;
int coun = 0;

String Endhr;
String Endmn;
String StartHr;
String StartMn;
int HR;
int MN;
int HRs;
int MNs;


const long utcOffsetInSeconds =5*3600;                             //setting time according to Pakistan

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

                                                                               // Define NTP Client to get real time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);

String ssid;      // ssid of wifi
String pass;     // password of wifi
String ssid1;   // string for eeprom read
String pass1;
String ssid2;    // sgtring for string cnversionString pass2=;
String pass2;
int hotspot;

String Data_check;
String Statuscheck;
String path_t_start;
String path_T_end;

String string;
String UserID;
String DeviceGroup;
String DeviceID;


int UserID1;
int DeviceGroup1;
int DeviceID1;
int UserID1_total;
int DeviceGroup1_total;
int DeviceID1_total;

String UserID2;
String DeviceGroup2; 
String DeviceID2; 


int ssidl;
int passl;
int ssidl_total;
int passl_total;
int reset_button=23;
String  pass_ol;
String  userid_ol;
String device_id;
                                                                       
void handleRoot() {
  server.send(200, "text/plain", "Ready");                            //to make server ready
}

                                                                  //Getting data strings from server
void handleGet() {
  if (server.hasArg("data")) {
     string = server.arg("data");
    Serial.println("Data: " + string);
  }
  data_separatorr();
  Setting();                                                            //calling function for saving wifi credentials into EEPROM
}


                                                                            //telling server that data is processing
void handlePost() {
  server.send(200, "text/plain", "Processing Data");
}

                                                               //uploading the data (Credentials) on ESP
void handleUpload() {
  HTTPUpload& upload = server.upload();
  if (upload.status == UPLOAD_FILE_START) {
    Serial.println("Receiving data:");
  } else if (upload.status == UPLOAD_FILE_WRITE) {
    Serial.write(upload.buf, upload.currentSize);
  } else if (upload.status == UPLOAD_FILE_END) {
    server.send(200, "text/plain", "Data: ");
  }
}





//////////////////////////////////////////////////////////

void setup()   // Setup Begin
{
 pinMode(reset_button,INPUT);                     //declaring pins as input and output
 pinMode(sensor, INPUT);
 pinMode(spark, OUTPUT);
 pinMode(fan, OUTPUT);
 
  EEPROM.begin(700);
  Serial.begin(115200);                                    // baud rate changed
  
    hotspot =(EEPROM.read(1));                                     // read value of hotspot             
    Serial.println(hotspot);
    
       if (hotspot != 20)
   {
  WiFi.mode(WIFI_AP);                                                  //AP mode (hotspot) start
    WiFi.softAP(h_ssid, h_password);
  server.on("/", handleRoot);
  server.on("/get", HTTP_GET, handleGet);                                //server is getting data(ssid, password)     
  server.on("/post", HTTP_POST, handlePost, handleUpload);
  server.begin();
   Serial.println(WiFi.macAddress());
   delay (3000);
   }
   
   if (hotspot == 20){wifi_turn_onn();}
   }
 
 void loop(){
 digitalWrite(spark,LOW);
if (digitalRead(reset_button)==1){          //if reset button is pressed, ESP reset  (pull down)
    Serial.println("Reseting Your Device");
     delay(1000);
    for (int p = 0; p < 700; p++) {
      EEPROM.write(p, 1);
      EEPROM.commit();
      delay(5);}
      Serial.println("Device is restarting");
      ESP.restart();
      }

   if (hotspot==1){ 
  server.handleClient();
  delay(1000);}
  else
    timeClient.update();                                   //getting time from time server
                                                         
  Serial.print(daysOfTheWeek[timeClient.getDay()]);
  Serial.print(", ");
  HR=(timeClient.getHours());
  Serial.print(HR);
  Serial.print(":");
  MN=(timeClient.getMinutes());
  Serial.print(MN);
  Serial.print(":");
  int secs=timeClient.getSeconds();
  Serial.println(secs);

  motion_sense();
  schedule();
  button_start();
  
  Serial.print("Start time PATH : "); 
   Serial.println(path_t_start);
   Serial.print("End time PATH : "); 
   Serial.println(path_T_end);
      Serial.println("");
         Serial.println(UserID);
            Serial.println(DeviceGroup);
               Serial.println(DeviceID);
}
                                
