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

#define TFT_MISO 19
#define TFT_MOSI 23
#define TFT_SCLK 18
#define TFT_CS   5  // Chip select control pin
#define TFT_DC    17  // Data Command control pin
#define TFT_RST   16  // Reset pin (could connect to RST pin)
//#define TFT_RST  -1  // Set TFT_RST to -1 if display RESET is connected to ESP32 board RST

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

    tft.setRotation(1);

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
String TEXT = "My Text";
    // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    // Show all 48 fonts in centre of screen ( x,y coordinate 160,120)
    // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

    // Where font sizes increase the screen is not cleared as the larger fonts overwrite
    // the smaller one with the background colour.

    // Set text datum to middle centre
    tft.setTextDatum(MC_DATUM);

    // Set text colour to orange with black background
    tft.setTextColor(TFT_WHITE, TFT_BLACK);

    tft.fillScreen(TFT_BLACK);            // Clear screen
    tft.setFreeFont(FF18);                 // Select the font
    tft.drawString(sFF1, 160, 60, GFXFF);// Print the string name of the font
    tft.setFreeFont(FF1);                 // Select the font
    tft.drawString(TEXT, 160, 120, GFXFF);// Print the string name of the font
    delay(1000);
    //tft.fillScreen(TFT_BLACK);
    tft.setFreeFont(FF18);                 // Select the font
    tft.drawString(sFF2, 160, 60, GFXFF);// Print the string name of the font
    tft.setFreeFont(FF2);
    tft.drawString(TEXT, 160, 120, GFXFF);
    delay(1000);
    //tft.fillScreen(TFT_BLACK);
    tft.setFreeFont(FF18);                 // Select the font
    tft.drawString(sFF3, 160, 60, GFXFF);// Print the string name of the font
    tft.setFreeFont(FF3);
    tft.drawString(TEXT, 160, 120, GFXFF);
    delay(1000);
    //tft.fillScreen(TFT_BLACK);
    tft.setFreeFont(FF18);                 // Select the font
    tft.drawString(sFF4, 160, 60, GFXFF);// Print the string name of the font
    tft.setFreeFont(FF4);
    tft.drawString(TEXT, 160, 120, GFXFF);
    delay(1000);

    tft.fillScreen(TFT_BLACK);
    tft.setFreeFont(FF18);                 // Select the font
    tft.drawString(sFF5, 160, 60, GFXFF);// Print the string name of the font
    tft.setFreeFont(FF5);
    tft.drawString(TEXT, 160, 120, GFXFF);
    delay(1000);
    //tft.fillScreen(TFT_BLACK);
    tft.setFreeFont(FF18);                 // Select the font
    tft.drawString(sFF6, 160, 60, GFXFF);// Print the string name of the font
    tft.setFreeFont(FF6);
    tft.drawString(TEXT, 160, 120, GFXFF);
    delay(1000);
    //tft.fillScreen(TFT_BLACK);
    tft.setFreeFont(FF18);                 // Select the font
    tft.drawString(sFF7, 160, 60, GFXFF);// Print the string name of the font
    tft.setFreeFont(FF7);
    tft.drawString(TEXT, 160, 120, GFXFF);
    delay(1000);
    //tft.fillScreen(TFT_BLACK);
    tft.setFreeFont(FF18);                 // Select the font
    tft.drawString(sFF8, 160, 60, GFXFF);// Print the string name of the font
    tft.setFreeFont(FF8);
    tft.drawString(TEXT, 160, 120, GFXFF);
    delay(1000);

    tft.fillScreen(TFT_BLACK);
    tft.setFreeFont(FF18);                 // Select the font
    tft.drawString(sFF9, 160, 60, GFXFF);// Print the string name of the font
    tft.setFreeFont(FF9);
    tft.drawString(TEXT, 160, 120, GFXFF);
    delay(1000);
    //tft.fillScreen(TFT_BLACK);
    tft.setFreeFont(FF18);                 // Select the font
    tft.drawString(sFF10, 160, 60, GFXFF);// Print the string name of the font
    tft.setFreeFont(FF10);
    tft.drawString(TEXT, 160, 120, GFXFF);
    delay(1000);
    //tft.fillScreen(TFT_BLACK);
    tft.setFreeFont(FF18);                 // Select the font
    tft.drawString(sFF11, 160, 60, GFXFF);// Print the string name of the font
    tft.setFreeFont(FF11);
    tft.drawString(TEXT, 160, 120, GFXFF);
    delay(1000);
    //tft.fillScreen(TFT_BLACK);
    tft.setFreeFont(FF18);                 // Select the font
    tft.drawString(sFF12, 160, 60, GFXFF);// Print the string name of the font
    tft.setFreeFont(FF12);
    tft.drawString(TEXT, 160, 120, GFXFF);
    delay(1000);

    tft.fillScreen(TFT_BLACK);
    tft.setFreeFont(FF18);                 // Select the font
    tft.drawString(sFF13, 160, 60, GFXFF);// Print the string name of the font
    tft.setFreeFont(FF13);
    tft.drawString(TEXT, 160, 120, GFXFF);
    delay(1000);
    //tft.fillScreen(TFT_BLACK);
    tft.setFreeFont(FF18);                 // Select the font
    tft.drawString(sFF14, 160, 60, GFXFF);// Print the string name of the font
    tft.setFreeFont(FF14);
    tft.drawString(TEXT, 160, 120, GFXFF);
    delay(1000);
    //tft.fillScreen(TFT_BLACK);
    tft.setFreeFont(FF18);                 // Select the font
    tft.drawString(sFF15, 160, 60, GFXFF);// Print the string name of the font
    tft.setFreeFont(FF15);
    tft.drawString(TEXT, 160, 120, GFXFF);
    delay(1000);
    //tft.fillScreen(TFT_BLACK);
    tft.setFreeFont(FF18);                 // Select the font
    tft.drawString(sFF16, 160, 60, GFXFF);// Print the string name of the font
    tft.setFreeFont(FF16);
    tft.drawString(TEXT, 160, 120, GFXFF);
    delay(1000);

    tft.fillScreen(TFT_BLACK);
    tft.setFreeFont(FF18);                 // Select the font
    tft.drawString(sFF17, 160, 60, GFXFF);// Print the string name of the font
    tft.setFreeFont(FF17);
    tft.drawString(TEXT, 160, 120, GFXFF);
    delay(1000);
    //tft.fillScreen(TFT_BLACK);
    tft.setFreeFont(FF18);                 // Select the font
    tft.drawString(sFF18, 160, 60, GFXFF);// Print the string name of the font
    tft.setFreeFont(FF18);
    tft.drawString(TEXT, 160, 120, GFXFF);
    delay(1000);
    //tft.fillScreen(TFT_BLACK);
    tft.setFreeFont(FF18);                 // Select the font
    tft.drawString(sFF19, 160, 60, GFXFF);// Print the string name of the font
    tft.setFreeFont(FF19);
    tft.drawString(TEXT, 160, 120, GFXFF);
    delay(1000);
    //tft.fillScreen(TFT_BLACK);
    tft.setFreeFont(FF18);                 // Select the font
    tft.drawString(sFF20, 160, 60, GFXFF);// Print the string name of the font
    tft.setFreeFont(FF20);
    tft.drawString(TEXT, 160, 120, GFXFF);
    delay(1000);

    tft.fillScreen(TFT_BLACK);
    tft.setFreeFont(FF18);                 // Select the font
    tft.drawString(sFF21, 160, 60, GFXFF);// Print the string name of the font
    tft.setFreeFont(FF21);
    tft.drawString(TEXT, 160, 120, GFXFF);
    delay(1000);
    //tft.fillScreen(TFT_BLACK);
    tft.setFreeFont(FF18);                 // Select the font
    tft.drawString(sFF22, 160, 60, GFXFF);// Print the string name of the font
    tft.setFreeFont(FF22);
    tft.drawString(TEXT, 160, 120, GFXFF);
    delay(1000);
    //tft.fillScreen(TFT_BLACK);
    tft.setFreeFont(FF18);                 // Select the font
    tft.drawString(sFF23, 160, 60, GFXFF);// Print the string name of the font
    tft.setFreeFont(FF23);
    tft.drawString(TEXT, 160, 120, GFXFF);
    delay(1000);
    //tft.fillScreen(TFT_BLACK);
    tft.setFreeFont(FF18);                 // Select the font
    tft.drawString(sFF24, 160, 60, GFXFF);// Print the string name of the font
    tft.setFreeFont(FF24);
    tft.drawString(TEXT, 160, 120, GFXFF);
    delay(1000);

    tft.fillScreen(TFT_BLACK);
    tft.setFreeFont(FF18);                 // Select the font
    tft.drawString(sFF25, 160, 60, GFXFF);// Print the string name of the font
    tft.setFreeFont(FF25);
    tft.drawString(TEXT, 160, 120, GFXFF);
    delay(1000);
    //tft.fillScreen(TFT_BLACK);
    tft.setFreeFont(FF18);                 // Select the font
    tft.drawString(sFF26, 160, 60, GFXFF);// Print the string name of the font
    tft.setFreeFont(FF26);
    tft.drawString(TEXT, 160, 120, GFXFF);
    delay(1000);
    //tft.fillScreen(TFT_BLACK);
    tft.setFreeFont(FF18);                 // Select the font
    tft.drawString(sFF27, 160, 60, GFXFF);// Print the string name of the font
    tft.setFreeFont(FF27);
    tft.drawString(TEXT, 160, 120, GFXFF);
    delay(1000);
    //tft.fillScreen(TFT_BLACK);
    tft.setFreeFont(FF18);                 // Select the font
    tft.drawString(sFF28, 160, 60, GFXFF);// Print the string name of the font
    tft.setFreeFont(FF28);
    tft.drawString(TEXT, 160, 120, GFXFF);
    delay(1000);

    tft.fillScreen(TFT_BLACK);
    tft.setFreeFont(FF18);                 // Select the font
    tft.drawString(sFF29, 160, 60, GFXFF);// Print the string name of the font
    tft.setFreeFont(FF29);
    tft.drawString(TEXT, 160, 120, GFXFF);
    delay(1000);
    //tft.fillScreen(TFT_BLACK);
    tft.setFreeFont(FF18);                 // Select the font
    tft.drawString(sFF30, 160, 60, GFXFF);// Print the string name of the font
    tft.setFreeFont(FF30);
    tft.drawString(TEXT, 160, 120, GFXFF);
    delay(1000);
    //tft.fillScreen(TFT_BLACK);
    tft.setFreeFont(FF18);                 // Select the font
    tft.drawString(sFF31, 160, 60, GFXFF);// Print the string name of the font
    tft.setFreeFont(FF31);
    tft.drawString(TEXT, 160, 120, GFXFF);
    delay(1000);
    //tft.fillScreen(TFT_BLACK);
    tft.setFreeFont(FF18);                 // Select the font
    tft.drawString(sFF32, 160, 60, GFXFF);// Print the string name of the font
    tft.setFreeFont(FF32);
    tft.drawString(TEXT, 160, 120, GFXFF);
    delay(1000);

    tft.fillScreen(TFT_BLACK);
    tft.setFreeFont(FF18);                 // Select the font
    tft.drawString(sFF33, 160, 60, GFXFF);// Print the string name of the font
    tft.setFreeFont(FF33);
    tft.drawString(TEXT, 160, 120, GFXFF);
    delay(1000);
    //tft.fillScreen(TFT_BLACK);
    tft.setFreeFont(FF18);                 // Select the font
    tft.drawString(sFF34, 160, 60, GFXFF);// Print the string name of the font
    tft.setFreeFont(FF34);
    tft.drawString(TEXT, 160, 120, GFXFF);
    delay(1000);
    //tft.fillScreen(TFT_BLACK);
    tft.setFreeFont(FF18);                 // Select the font
    tft.drawString(sFF35, 160, 60, GFXFF);// Print the string name of the font
    tft.setFreeFont(FF35);
    tft.drawString(TEXT, 160, 120, GFXFF);
    delay(1000);
    //tft.fillScreen(TFT_BLACK);
    tft.setFreeFont(FF18);                 // Select the font
    tft.drawString(sFF36, 160, 60, GFXFF);// Print the string name of the font
    tft.setFreeFont(FF36);
    tft.drawString(TEXT, 160, 120, GFXFF);
    delay(1000);

    tft.fillScreen(TFT_BLACK);
    tft.setFreeFont(FF18);                 // Select the font
    tft.drawString(sFF37, 160, 60, GFXFF);// Print the string name of the font
    tft.setFreeFont(FF37);
    tft.drawString(TEXT, 160, 120, GFXFF);
    delay(1000);
    //tft.fillScreen(TFT_BLACK);
    tft.setFreeFont(FF18);                 // Select the font
    tft.drawString(sFF38, 160, 60, GFXFF);// Print the string name of the font
    tft.setFreeFont(FF38);
    tft.drawString(TEXT, 160, 120, GFXFF);
    delay(1000);
    //tft.fillScreen(TFT_BLACK);
    tft.setFreeFont(FF18);                 // Select the font
    tft.drawString(sFF39, 160, 60, GFXFF);// Print the string name of the font
    tft.setFreeFont(FF39);
    tft.drawString(TEXT, 160, 120, GFXFF);
    delay(1000);
    //tft.fillScreen(TFT_BLACK);
    tft.setFreeFont(FF18);                 // Select the font
    tft.drawString(sFF40, 160, 60, GFXFF);// Print the string name of the font
    tft.setFreeFont(FF40);
    tft.drawString(TEXT, 160, 120, GFXFF);
    delay(1000);

    tft.fillScreen(TFT_BLACK);
    tft.setFreeFont(FF18);                 // Select the font
    tft.drawString(sFF41, 160, 60, GFXFF);// Print the string name of the font
    tft.setFreeFont(FF41);
    tft.drawString(TEXT, 160, 120, GFXFF);
    delay(1000);
    //tft.fillScreen(TFT_BLACK);
    tft.setFreeFont(FF18);                 // Select the font
    tft.drawString(sFF42, 160, 60, GFXFF);// Print the string name of the font
    tft.setFreeFont(FF42);
    tft.drawString(TEXT, 160, 120, GFXFF);
    delay(1000);
    //tft.fillScreen(TFT_BLACK);
    tft.setFreeFont(FF18);                 // Select the font
    tft.drawString(sFF43, 160, 60, GFXFF);// Print the string name of the font
    tft.setFreeFont(FF43);
    tft.drawString(TEXT, 160, 120, GFXFF);
    delay(1000);
    //tft.fillScreen(TFT_BLACK);
    tft.setFreeFont(FF18);                 // Select the font
    tft.drawString(sFF44, 160, 60, GFXFF);// Print the string name of the font
    tft.setFreeFont(FF44);
    tft.drawString(TEXT, 160, 120, GFXFF);
    delay(1000);

    tft.fillScreen(TFT_BLACK);
    tft.setFreeFont(FF18);                 // Select the font
    tft.drawString(sFF45, 160, 60, GFXFF);// Print the string name of the font
    tft.setFreeFont(FF45);
    tft.drawString(TEXT, 160, 120, GFXFF);
    delay(1000);
    //tft.fillScreen(TFT_BLACK);
    tft.setFreeFont(FF18);                 // Select the font
    tft.drawString(sFF46, 160, 60, GFXFF);// Print the string name of the font
    tft.setFreeFont(FF46);
    tft.drawString(TEXT, 160, 120, GFXFF);
    delay(1000);
    //tft.fillScreen(TFT_BLACK);
    tft.setFreeFont(FF18);                 // Select the font
    tft.drawString(sFF47, 160, 60, GFXFF);// Print the string name of the font
    tft.setFreeFont(FF47);
    tft.drawString(TEXT, 160, 120, GFXFF);
    delay(1000);
    //tft.fillScreen(TFT_BLACK);
    tft.setFreeFont(FF18);                 // Select the font
    tft.drawString(sFF48, 160, 60, GFXFF);// Print the string name of the font
    tft.setFreeFont(FF48);
    tft.drawString(TEXT, 160, 120, GFXFF);
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