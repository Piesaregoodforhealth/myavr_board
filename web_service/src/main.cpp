#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "pagecontroller.h"

// Replace with your credentials
const char* ssid = "Vodafone-0C74";
const char* password = "4bc3AaPRp3XnKJgp";

ESP8266WebServer server(80);


PageController pageController;

void handleRequest() {
  auto uri = server.uri();  
  auto page = pageController.getPage(uri.c_str());
  auto content = page.getContent();
  auto code = page.getCode();
  server.send(code, "text/html",String(content.c_str()));
}


void setup() {
  Serial.begin(115200);
  delay(100);

  WiFi.begin(ssid, password);
  Serial.println();

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected!");
  Serial.println(WiFi.localIP());

  //server.on("/", handleRequest);
  //server.on("/link1", handleRequest);  
  //server.on("/link2", handleRequest);  
  server.onNotFound(handleRequest);

  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}
