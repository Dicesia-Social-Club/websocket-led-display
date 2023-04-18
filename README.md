### ESP8266 WebSocket Message Display :clipboard:

Description: This is a repository that contains the code for an ESP8266-based app that displays messages on a 8x8 LED matrix using WebSocket communication. The app allows users to enter a message through a WebSocket connection and displays the message in scrolling text format on the LED matrix.

> ### Configuration for your project
### WiFi configuration:

- Replace "your_wifi_ssid" with the name of your WiFi network.
- Replace "your_wifi_password" with the password for your WiFi network.

### WebSocket configuration:

- Replace "websocket_server_url" with the URL of your WebSocket server.

### Matrix configuration:

- Set "numDevices" to the number of LED matrix devices you have connected.
- Set "font" to the font you want to use for displaying text.

### Custom messages:

- Add or remove strings to the "customMessages" array as needed.
- Set "numCustomMessages" to the number of strings in the "customMessages" array.
- Set "currentCustomMessageIndex" to the index of the initial custom message you want to display.

That's it! Once you have configured these variables, you should be able to run the code and display messages on your LED matrix.


