#include <WiFi.h>
#include <ArduinoWebsockets.h>
#include <LedMatrix.h>
#include <SPI.h>

// WiFi configuration
const char* ssid = "your_wifi_ssid";
const char* password = "your_wifi_password";

// WebSocket configuration
const char* webSocketUrl = "websocket_server_url";
WebSocketClient webSocket;

// Matrix configuration
const int numDevices = 5;
LedMatrix ledMatrix(numDevices, 0, 15, 12, 14, 13);
const char* font = "5x7";

// Custom messages
const char* customMessages[] = {"No message received", "Message 1", "Message 2", "Message 3"};
const int numCustomMessages = 4;

// Index of the current custom message
int currentCustomMessageIndex = 0;

// Flag to indicate if a message has been received
bool messageReceived = false;

void setup() {
  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
  }

  // Initialize matrix
  ledMatrix.init();
  ledMatrix.setIntensity(5);
  ledMatrix.setTextWrap(false);

  // Connect to WebSocket server
  while (!webSocket.connect(webSocketUrl)) {
    delay(1000);
  }

  // Subscribe to WebSocket events
  webSocket.onEvent(webSocketEvent);
}

void loop() {
  // Handle WebSocket events
  webSocket.loop();

  // If no message has been received, show the next custom message
  if (!messageReceived) {
    ledMatrix.clear();
    ledMatrix.setFont(font);
    ledMatrix.setScrollSpeed(50);
    ledMatrix.setCharSpacing(1);
    ledMatrix.drawString(0, 0, customMessages[currentCustomMessageIndex]);
    ledMatrix.display();

    // Increment the index of the current custom message
    currentCustomMessageIndex = (currentCustomMessageIndex + 1) % numCustomMessages;
  }
}

void webSocketEvent(WStype_t type, uint8_t* payload, size_t length) {
  switch (type) {
    case WStype_DISCONNECTED:
      break;
    case WStype_CONNECTED:
      break;
    case WStype_TEXT:
      // Convert payload to string
      String message = (char*)payload;

      // Set flag to true and display message on matrix
      messageReceived = true;
      ledMatrix.clear();
      ledMatrix.setFont(font);
      ledMatrix.setScrollSpeed(50);
      ledMatrix.setCharSpacing(1);
      ledMatrix.drawString(0, 0, message.c_str());
      ledMatrix.display();
      break;
  }
}
