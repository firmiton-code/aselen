#ifndef NETWORK_H_
#define NETWORK_H_

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <string.h>
#include <Firebase_ESP_Client.h>
#include <DNSServer.h>
#include <ESPAsyncTCP.h>
#include "ESPAsyncWebServer.h"
#include "credentials.h"
#include "../device_config.h"
#include "web_handle.h"

#define NET_TAG "Network"

class CaptiveRequestHandler : public AsyncWebHandler {
public:
  CaptiveRequestHandler() {}
  virtual ~CaptiveRequestHandler() {}

  bool canHandle(AsyncWebServerRequest *request){
    //request->addInterestingHeader("ANY");
    return true;
  }

  void handleRequest(AsyncWebServerRequest *request) {
    request->send_P(200, "text/html", index_html); 
  }
};

class NetworkClass{
  public:
    NetworkClass(void);
    void setupServer();
    void connect(String ssid, String pass);
    bool get_status();
    void begin();
    void reconnect(String ap_name);
    String get_ssid();
    String get_ip();

  private:
    bool _connection_status = false;
    String ssid, pass;
};

extern NetworkClass net;

#endif // NETWORK_H_