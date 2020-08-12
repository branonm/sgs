// Libraries for SD card
//#include "FS.h"
//#include "SD.h"
//#include <SPI.h>

#include "OTAUpdateWebServer.h"
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <RTClib.h>


#include <SPI.h>
#include "TFT_eSPI.h"
#include <WiFi.h>

#include "free_fonts.h"


// // Text that will be printed on screen in any font
// Use hardware SPI
TFT_eSPI tft = TFT_eSPI();

RTC_DS3231 rtc;

const char* ssid = "ATT9mPG3IF";
const char* password = "3br6sg6f7cb2";
const char* host = "sgs-esp32";

const int port = 11232;

void setup() {


    // Start serial communication for debugging purposes
    Serial.begin(115200);
    // Wait for serial connection to spin up.
    delay(250);

    if (!rtc.begin()) {
        Serial.println("Couldn't find RTC");
        while (1);
    }

    tft.begin();
    tft.setRotation(2);
    tft.fillScreen(TFT_BLACK);            // Clear screen
    tft.setTextColor(TFT_WHITE, TFT_BLACK);


    // Connect to Wi-Fi network with SSID and password
    Serial.printf("Connecting to %s", ssid);
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println();
    WiFi.setHostname(host);

    Serial.printf("WiFi connected : %s (%s)\n", WiFi.getHostname(), WiFi.localIP().toString().c_str());

    // Turn on webserver for OTA firmware updates.
    doOTAUpdates(host, port);

    if (rtc.lostPower()) {
        Serial.println("RTC lost power, setting time");

        WiFiUDP ntpUDP;
        NTPClient timeClient(ntpUDP, "us.pool.ntp.org", -18000, 60000);
        Serial.println("Grabbing current time from NTP.");

        timeClient.begin();
        timeClient.update();
        rtc.adjust(DateTime(timeClient.getEpochTime()));
        timeClient.end();
        Serial.println("Done");

    }

    // Initialize SD card
//    SD.begin(SD_CS);
//    if(!SD.begin(SD_CS)) {
//        Serial.println("Card Mount Failed");
//        return;
//    }
//    uint8_t cardType = SD.cardType();
//    if(cardType == CARD_NONE) {
//        Serial.println("No SD card attached");
//        return;
//    }
//    Serial.println("Initializing SD card...");
//    if (!SD.begin(SD_CS)) {
//        Serial.println("ERROR - SD card initialization failed!");
//        return;    // init failed
//    }

    // If the data.txt file doesn't exist
    // Create a file on the SD card and write the data labels
//    File file = SD.open("/data.txt");
//    if(!file) {
//        Serial.println("File doens't exist");
//        Serial.println("Creating file...");
//        writeFile(SD, "/data.txt", "Reading ID, Date, Hour, Temperature \r\n");
//    }
//    else {
//        Serial.println("File already exists");
//    }
//    file.close();


}

void loop() {

   // otaWebServer.handleClient();
    // Serial.println(rtc.now().timestamp());
String TEXT = rtc.now().timestamp();





    tft.setTextDatum(TR_DATUM);
    tft.drawString(TEXT, 160, 120, GFXFF);// Print the string name of the font
    delay(1000);


}



//// Write the sensor readings on the SD card
//void logSDCard() {
//    dataMessage = String(readingID) + "," + String(dayStamp) + "," + String(timeStamp) + "," +
//                  String(temperature) + "\r\n";
//    Serial.print("Save data: ");
//    Serial.println(dataMessage);
//    appendFile(SD, "/data.txt", dataMessage.c_str());
//}
//
//// Write to the SD card (DON'T MODIFY THIS FUNCTION)
//void writeFile(fs::FS &fs, const char * path, const char * message) {
//    Serial.printf("Writing file: %s\n", path);
//
//    File file = fs.open(path, FILE_WRITE);
//    if(!file) {
//        Serial.println("Failed to open file for writing");
//        return;
//    }
//    if(file.print(message)) {
//        Serial.println("File written");
//    } else {
//        Serial.println("Write failed");
//    }
//    file.close();
//}
//
//// Append data to the SD card (DON'T MODIFY THIS FUNCTION)
//void appendFile(fs::FS &fs, const char * path, const char * message) {
//    Serial.printf("Appending to file: %s\n", path);
//
//    File file = fs.open(path, FILE_APPEND);
//    if(!file) {
//        Serial.println("Failed to open file for appending");
//        return;
//    }
//    if(file.print(message)) {
//        Serial.println("Message appended");
//    } else {
//        Serial.println("Append failed");
//    }
//    file.close();
//}