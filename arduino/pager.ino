/* 
SlackPager - Code for Adafruit Feather HUZZAH ESP8266
Daniel Davidson/danieliscrazy 2025 
https://github.com/danieliscrazy/SlackPager
Licensed under the GNU GPLv3.
Made for Hack Club's Highway program.
This code is not AI generated, but AI was used to assist debugging. 
Modifications to this code must be stated within the comment block, below the following line.
Redistributions of any kind must contain this line and the above text (lines 1-9) unmodified at the top of the file.
*/

#include "config.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

AdafruitIO_Feed *message = io.feed("message"); // feed for incoming messages
AdafruitIO_Feed *sender = io.feed("sender"); // feed for who sent incoming messages
AdafruitIO_Feed *sending = io.feed("sending"); // feed for messages being sent out

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET 5
#define OLED_DC 16
#define OLED_CS 15
#define BUTTON1 2  // Arrow button
#define BUTTON2 0  // Select

String storeMessage = "";
String storeSender = "Last Message:";
bool current = false;
bool last = false;
bool selectCurrent = false;
bool selectLast = false;
int option = 1;
int lastopt = 1;
bool menuopen = false;
bool thistime = false;
int countdown = 60;
Adafruit_SH1106G display(SCREEN_WIDTH, SCREEN_HEIGHT, &SPI, OLED_DC, OLED_RESET, OLED_CS);

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  pinMode(4, OUTPUT);
  while (!Serial)
    ;
  Serial.print("Connecting to Adafruit IO");
  display.begin(0x3C, true);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(0, 0);
  display.println("Waiting for boot...");
  display.display();
  io.connect();
  sender->onMessage(handleSender);
  message->onMessage(handleMessage);
  while (io.mqttStatus() < AIO_CONNECTED) {
    Serial.print(".");
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("Waiting for boot...");
    display.println("");
    display.print(countdown);
    display.print("s");
    display.display();
    countdown--;
    delay(1000);
  }

  message->get();

  Serial.println();
  Serial.println(io.statusText());

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(0, 0);
  display.println("Startup!");
  display.display();
  ringtone();
}

void loop() {
  io.run();
  if (digitalRead(BUTTON1) == LOW) {  // pullup resistor on this pin for me
    current = true;
    Serial.println("Startup! button 1");
  } else {
    current = false;
  }
  if (digitalRead(BUTTON2) == LOW) {
    selectCurrent = true;
    Serial.println("Startup! 2");

  } else {
    selectCurrent = false;
  }

  if (menuopen == false && selectCurrent == true && selectLast != selectCurrent) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SH110X_WHITE);
    display.setCursor(0, 0);
    display.println("Exit <");
    display.println("Okay");
    display.println("Give me a sec");
    display.println("Yes");
    display.println("No");
    display.println("Heart");
    display.println("Goosepheus");
    display.display();
    menuopen = true;
    option = 1;
    thistime = true;
  }

  if (menuopen == true && current == true && last != current) {
    if (option != 7) {
      option++;
      Serial.println("Option up!");
      Serial.println(option);
    } else {
      option = 1;
      Serial.println("Looping!");
      Serial.println(option);
    }
  }

  if (menuopen == true && option == 1 && lastopt != option) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SH110X_WHITE);
    display.setCursor(0, 0);
    display.println("Exit <");
    display.println("Okay");
    display.println("Give me a sec");
    display.println("Yes");
    display.println("No");
    display.println("Heart");
    display.println("Goosepheus");
    display.display();
  }
  if (menuopen == true && option == 2 && lastopt != option) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SH110X_WHITE);
    display.setCursor(0, 0);
    display.println("Exit");
    display.println("Okay <");
    display.println("Give me a sec");
    display.println("Yes");
    display.println("No");
    display.println("Heart");
    display.println("Goosepheus");
    display.display();
  }
  if (menuopen == true && option == 3 && lastopt != option) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SH110X_WHITE);
    display.setCursor(0, 0);
    display.println("Exit");
    display.println("Okay");
    display.println("Give me a sec <");
    display.println("Yes");
    display.println("No");
    display.println("Heart");
    display.println("Goosepheus");
    display.display();
  }
  if (menuopen == true && option == 4 && lastopt != option) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SH110X_WHITE);
    display.setCursor(0, 0);
    display.println("Exit");
    display.println("Okay");
    display.println("Give me a sec");
    display.println("Yes <");
    display.println("No");
    display.println("Heart");
    display.println("Goosepheus");
    display.display();
  }
  if (menuopen == true && option == 5 && lastopt != option) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SH110X_WHITE);
    display.setCursor(0, 0);
    display.println("Exit");
    display.println("Okay");
    display.println("Give me a sec");
    display.println("Yes");
    display.println("No <");
    display.println("Heart");
    display.println("Goosepheus");
    display.display();
  }

  if (menuopen == true && option == 6 && lastopt != option) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SH110X_WHITE);
    display.setCursor(0, 0);
    display.println("Exit");
    display.println("Okay");
    display.println("Give me a sec");
    display.println("Yes");
    display.println("No");
    display.println("Heart <");
    display.println("Goosepheus");
    display.display();
  }
  if (menuopen == true && option == 7 && lastopt != option) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SH110X_WHITE);
    display.setCursor(0, 0);
    display.println("Exit");
    display.println("Okay");
    display.println("Give me a sec");
    display.println("Yes");
    display.println("No");
    display.println("Heart");
    display.println("Goosepheus <");
    display.display();
  }
  if (menuopen == true && selectCurrent == true && selectLast != selectCurrent && thistime == false) {
    if (option == 2) {
      String response = "Ok";
      sending->save(response);
      sentIt();
    }
    if (option == 3) {
      String response = "Give me a sec";
      sending->save(response);
      sentIt();
    }
    if (option == 4) {
      String response = "Yes";
      sending->save(response);
      sentIt();
    }
    if (option == 5) {
      String response = "No";
      sending->save(response);
      sentIt();
    }
    if (option == 6) {
      String response = ":sparkling_heart:";
      sending->save(response);
      sentIt();
    }
    if (option == 7) {
      String response = ":goosepheus:";
      sending->save(response);
      sentIt();
    }
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SH110X_WHITE);
    display.setCursor(0, 0);
    display.println(storeSender);
    display.println(storeMessage);
    display.display();
    menuopen = false;
    option = 1;
  }
  lastopt = option;
  last = current;
  selectLast = selectCurrent;
  thistime = false;
}

void ringtone() {
  tone(4, 622.25);
  delay(300);
  noTone(4);
  tone(4, 311.12);
  delay(300);
  noTone(4);
  tone(4, 415.3);
  delay(300);
  noTone(4);
  tone(4, 311.12);
  delay(300);
  noTone(4);
  tone(4, 466.16);
  delay(300);
  noTone(4);
}

void sentIt() {
  tone(4, 622.25);
  delay(150);
  noTone(4);
  tone(4, 622.25);
  delay(150);
  noTone(4);
  tone(4, 622.25);
  delay(150);
  noTone(4);
}
void handleMessage(AdafruitIO_Data *data) {

  Serial.print("message <- ");
  Serial.println(data->value());
  storeMessage = data->toString();
}

void handleSender(AdafruitIO_Data *data) {

  Serial.print("received <- ");
  Serial.println(data->value());
  storeSender = data->toString();

  display.setTextColor(SH110X_WHITE);
  display.setCursor(0, 0);
  display.clearDisplay();
  display.println(data->toString());
  display.display();
  ringtone();
  delay(1000);

  display.setCursor(0, 0);
  display.clearDisplay();
  display.display();
  delay(1000);

  display.setCursor(0, 0);
  display.clearDisplay();
  display.println(data->toString());
  display.display();
  delay(1000);

  display.setCursor(0, 0);
  display.clearDisplay();
  display.display();
  delay(1000);

  display.setCursor(0, 0);
  display.clearDisplay();
  display.println(data->toString());
  display.display();
  delay(2000);
  display.println(storeMessage);
  display.display();
}
