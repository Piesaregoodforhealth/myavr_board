#ifndef LINK2_H
#define LINK2_H

#include <ESP8266WebServer.h>

extern ESP8266WebServer server;

void handleLink2() {
  String html = "<h2>This is Link 2 Page</h2><a href=\"/\">Back to Home</a>";
  server.send(200, "text/html", html);
}

#endif
