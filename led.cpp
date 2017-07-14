#include <SoftwareSerial.h> // Include software serial library, ESP8266 library dependency
#include <SparkFunESP8266WiFi.h> // Include the ESP8266 AT library

if (esp8266.begin()) // Initialize the ESP8266 and check it's return status
    Serial.println("ESP8266 ready to go!"); // Communication and setup successful
else
    Serial.println("Unable to communicate with the ESP8266 :(");

int retVal;
retVal = esp8266.connect("myNetwork", "myNetworkPassword");     //must be changed per network im on
if (retVal < 0)
{
    Serial.print(F("Error connecting: "));
    Serial.println(retVal);
}

IPAddress myIP = esp8266.localIP(); // Get the ESP8266's local IP
Serial.print(F("My IP is: ")); Serial.println(myIP);


ESP8266Client client; // Create a client object

retVal = client.connect("sparkfun.com", 80); // Connect to sparkfun (HTTP port)
if (retVal > 0)
    Serial.println("Successfully connected!");


client.print("GET / HTTP/1.1\nHost: example.com\nConnection: close\n\n");

while (client.available()) // While there's data available
    Serial.write(client.read()); // Read it and print to serial
