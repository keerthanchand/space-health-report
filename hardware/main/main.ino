#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>
#include <WiFiUdp.h>
#include "GlobalVar.h"

#include <Wire.h>
//#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char* ssid = "Cortana";
const char* password = "daddy@6T7";
char* light1;
char* fan1;
#define TOKEN "xxxxxxxxxxxxxx" 
char ThingsboardHost[] = "demo.thingsboard.io";

WiFiClient wifiClient;
PubSubClient client(wifiClient);
int status = WL_IDLE_STATUS;

void setup(){
    Wire.begin();
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
    delay(200);
    Serial.print(".");
  }
  client.setServer( ThingsboardHost, 1883 );

}


void loop(){
  if ( !client.connected() ) 
{
    reconnect();
}
for(int i=0; i< Data_sampling_rate; i++){
  Collect_and_send_data();
}
delay(Wait_time);

}

void Collect_and_send_data(){
  String payload = "{";
  payload +=  "\"Gama\":";
    payload+= gsr_capture_data(); payload += ",";
  payload +=  "\"Radiation Count\":";
    payload+= Radiation_count_capture_data(); payload += ",";
  payload +=  "\"uSvh\":";
    payload+= uSvh_capture_data(); payload += ",";
  payload +=  "\"Body Temperature\":";
    payload+= Get_body_temperature(); payload += ",";
  payload +=  "\"GSR\":";
    payload+= gsr_capture_data(); payload += ",";
  payload +=  "\"Heart Rate\":";
    payload+= Get_heart_rate(); payload += ",";
  payload +=  "\"SpO2\":";
    payload+= Get_SpO2(); payload += ",";
  payload += "}";


   char attributes[1000];
  payload.toCharArray( attributes, 1000 );
  client.publish( "v1/devices/me/telemetry",attributes);
}


void reconnect() {
  while (!client.connected()) {
    status = WiFi.status();
    if ( status != WL_CONNECTED) {
      WiFi.begin(ssid, password);
      while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
      }
      Serial.println("Connected to AP");
    }
    Serial.print("Connecting to ThingsBoard node ...");
    if ( client.connect("Esp8266", TOKEN, NULL) ) {
      Serial.println( "[DONE]" );
    } else {
      Serial.print( "[FAILED] [ rc = " );
      Serial.println( " : retrying in 5 seconds]" );
      delay( 500 );
    }
  }
}
