#include <M5Stack.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <string>

#define GROVE_PIN 22 // Example GPIO pin connected to the Grove connector
#define pompe_pin 22
#define valve1_pin 16
#define valve2_pin 19
const char* ssid = "insta:_alexandre_masson";
const char* password = "Alexandre";

int pump_state = 0, valve1_state = 0, valve2_state = 0;

void setup() {
  M5.begin();
  M5.Power.begin();
  M5.Lcd.print("Initiaisation en cours \n");
  pinMode(pompe_pin, OUTPUT);
  pinMode(valve1_pin, OUTPUT);
  pinMode(valve2_pin, OUTPUT);

  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    afficher("Connecting to WiFi..");
  }
  afficher("Connected to WiFi");
  delay(1000);
}

void loop() {
  /////////////////////////////////////////////////////////////////////////////////////////
    // Initialize HTTPClient object
  HTTPClient http;
  String url = "http://5.57.109.48:8080/control"; // Replace with your web server endpoint

  // Make GET request
  http.begin(url); // Specify the URL
  int httpCode = http.GET(); // Send the GET request

  // Check the response
  String payload = http.getString(); // Get the response payload
  Serial.println("Response : \n");
  Serial.println(payload); // Print the response payload

  http.end(); // Close connection
  /////////////////////////////////////////////////////////////////////////////////////////
  parsePayload(payload, pump_state, valve1_state, valve2_state);

  if (pump_state == 1){
    digitalWrite(pompe_pin, HIGH);
  } else if (pump_state == 0){
    digitalWrite(pompe_pin, LOW);
  }

  if (valve1_state == 1){
    digitalWrite(valve1_pin, HIGH);
  } else if (valve1_state == 0){
    digitalWrite(valve1_pin, LOW);
  }

  if (valve2_state == 1){
    digitalWrite(valve2_pin, HIGH);
  } else if (valve2_state == 0){
    digitalWrite(valve2_pin, LOW);
  }
}

void afficher(String msg){
  // Initialize the LCD
  M5.Lcd.fillScreen(TFT_BLACK);
  M5.Lcd.setCursor(100, 100);
  M5.Lcd.setTextColor(TFT_WHITE);
  M5.Lcd.setTextSize(2);
  M5.Lcd.print(msg);
}

// Function to parse payload string and extract values into variables
void parsePayload(const String& payload, int& pump, int& valve1, int& valve2) {
    // Find the positions of commas in the payload string
    int commaPos1 = payload.indexOf(',');
    int commaPos2 = payload.indexOf(',', commaPos1 + 1);

    // Extract substrings between commas and convert them to integers
    if (commaPos1 != -1 && commaPos2 != -1) {
        pump = payload.substring(0, commaPos1).toInt();
        valve1 = payload.substring(commaPos1 + 1, commaPos2).toInt();
        valve2 = payload.substring(commaPos2 + 1).toInt();
    }
}
