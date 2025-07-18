#ifndef LINK1_H
#define LINK1_H

#include <ESP8266WebServer.h>

extern ESP8266WebServer server;

void handleLink1() {
  String html = "<h2>This is Link 1 Page</h2><a href=\"/\">Back to Home</a>";
  server.send(200, "text/html", html);
}

#endif
