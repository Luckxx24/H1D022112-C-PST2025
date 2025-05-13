#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

// put function declarations here:

const char* ssid = "prothotspot";
const char* password = "87654321";

ESP8266WebServer server (80);
String webpage;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay (10);

  pinMode(D3,OUTPUT);
  pinMode(D4,OUTPUT);
  pinMode(D6,OUTPUT);

  Serial.println();
  Serial.println("konfigurasi akses poin");

  WiFi.mode(WIFI_AP);
  WiFi.begin(ssid,password);

  Serial.println("IP ADDRESS");
  Serial.println(WiFi.softAPIP());

  webpage = "<h1>Web Kontrol ESP8266</h1>";
  webpage += "<h2>Muhammad Lucky Rahman</h2>";
  webpage += "<p>LED 1: <a href=\"/LED1ON\"><button>ON</button></a> <a href=\"/LED1OFF\"><button>OFF</button></a></p>";
  webpage += "<p>LED 2: <a href=\"/LED2ON\"><button>ON</button></a> <a href=\"/LED2OFF\"><button>OFF</button></a></p>";
  webpage += "<p>LED 3: <a href=\"/LED3ON\"><button>ON</button></a> <a href=\"/LED3OFF\"><button>OFF</button></a></p>";

  //TAMPILAN WEB PAGE
  server.on("/",[](){
    server.send(200,"text/html",webpage);
  });
  //merespon perintah masuk
  server.on("/LED1ON", [](){
    digitalWrite(D3,HIGH);
    server.send(200,"text/html",webpage);
  });
  server.on("/LED2ON", [](){
    digitalWrite(D4,HIGH);
    server.send(200,"text/html",webpage);
  });
  server.on("/LED3ON", [](){
    digitalWrite(D6,HIGH);
    server.send(200,"text/html",webpage);
  });

  //mematikan led
  server.on("/LED1OFF", [](){
    digitalWrite(D3,LOW);
    server.send(200,"text/html",webpage);
  });
  server.on("/LED2OFF", [](){
    digitalWrite(D4,LOW);
    server.send(200,"text/html",webpage);
  });
  server.on("/LED3OFF", [](){
    digitalWrite(D6,LOW);
    server.send(200,"text/html",webpage);
  });

  server.begin();
  Serial.println("webserver dijalankan");
}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();
}