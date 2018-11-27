#include <ESP8266WiFi.h>

const char* ssid = "TP-LINK_E9FF2A";
const char* password = "";
const int PORT = 3000;

IPAddress server(129,168,0,101);
WiFiClient client;

int status = WL_IDLE_STATUS;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println();
  Serial.print("Connecting to ...");
  Serial.println(ssid);
  status = WiFi.begin(ssid, password);
  if(status != WL_CONNECTED){
      delay(500);
      Serial.print(".");
  }
  Serial.println();
  Serial.println("Wifi connected");

  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(client.connect(server, PORT)){
    Serial.println("Connect to Server success!!");
    
  }
}
