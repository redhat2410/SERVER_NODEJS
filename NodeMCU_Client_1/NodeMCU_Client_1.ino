#include <ESP8266WiFi.h>
#include <SocketIOClient.h>

SocketIOClient client;
const char* ssid = "TP-LINK_E9FF2A";
const char* password = "";

char host[] = "192.168.0.101";
int port = 3484;

extern String RID;
extern String Rfull;

unsigned long previousMillis = 0;
long interval = 2000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(10);
  Serial.print("Ket noi vao mang");
  Serial.println(ssid);

  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print('.');
  }
  Serial.println();
  Serial.println(F("Da ket noi WiFi"));
  Serial.println(F("Dia chi IP cua ESP8266 (Socket Client ESP8266):"));
  Serial.println(WiFi.localIP());

  if(!client.connect(host, port)){
    Serial.println(F("ket noi den Socket server that bai"));
    return;  
  }
  if(client.connected()){
    client.send("connection", "message", "Connected !!!!");  
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if(millis() - previousMillis > interval){
    previousMillis = millis();
    client.send("atime", "message", "Time please?");  
  }

  if(client.monitor()){
    Serial.println(RID);
    Serial.println(Rfull);  
  }

  if(!client.connected()){
    client.reconnect(host, port);  
  }
}
