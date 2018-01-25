/*
 Copyright (C) 2018 Eric van Dijken <eric@team-moki.nl>
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
*/

#include "Main.h"
#include "Config.h"

#if DISPLAY_TYPE == 1
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
#endif

#if DISPLAY_TYPE == 2
#include <Wire.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd( 8, 9, 4, 5, 6, 7 );
#endif

int v=100;          //  comparison variable (may need some adjustment)

#ifdef VS_TANK
int vs_1q_value;
int vs_2q_value;
int vs_3q_value;
int vs_4q_value;
bool vs_alarm;
bool vs_blink;
#endif

#ifdef AS_TANK
int as_1q_value;
int as_2q_value;
int as_3q_value;
int as_4q_value;
bool as_alarm;
bool as_blink;
#endif

#ifdef WS_TANK
int ws_3q_value;
int ws_4q_value;
bool ws_alarm;
bool ws_blink;
#endif

//
// Setup
//
void setup() {
    // Open serial communications
    Serial.begin(115200);

#if DISPLAY_TYPE == 1
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
    display.clearDisplay();
#endif

#if DISPLAY_TYPE == 2
    lcd.begin(16, 2);
#endif

#ifdef VS_TANK
    pinMode(VS_1Q_PIN,INPUT);
    pinMode(VS_2Q_PIN,INPUT);
    pinMode(VS_3Q_PIN,INPUT);
    pinMode(VS_4Q_PIN,INPUT);
#endif

#ifdef AS_TANK
    pinMode(AS_1Q_PIN,INPUT);
    pinMode(AS_2Q_PIN,INPUT);
    pinMode(AS_3Q_PIN,INPUT);
    pinMode(AS_4Q_PIN,INPUT);
#endif

#ifdef WS_TANK
    pinMode(WS_3Q_PIN,INPUT);
    pinMode(WS_4Q_PIN,INPUT);
#endif

} // Setup

//
// Main loop
//
void loop() {

#ifdef DEBUG
    Serial.print("Debug: ");
    Serial.print("VS Valuesi: ");
    Serial.print(vs_1q_value);
    Serial.print(", ");
    Serial.print(vs_2q_value);
    Serial.print(", ");
    Serial.print(vs_3q_value);
    Serial.print(", ");
    Serial.println(vs_4q_value);
#endif

#ifdef VS_TANK
    vs_1q_value = analogRead(VS_1Q_PIN);
    vs_2q_value = analogRead(VS_2Q_PIN);
    vs_3q_value = analogRead(VS_3Q_PIN);
    vs_4q_value = analogRead(VS_4Q_PIN);
#endif

#ifdef AS_TANK
    as_1q_value = analogRead(AS_1Q_PIN);
    as_2q_value = analogRead(AS_2Q_PIN);
    as_3q_value = analogRead(AS_3Q_PIN);
    as_4q_value = analogRead(AS_4Q_PIN);
#endif

#ifdef WS_TANK
    ws_3q_value = analogRead(WS_3Q_PIN);
    ws_4q_value = analogRead(WS_4Q_PIN);
#endif

#if DISPLAY_TYPE == 1
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);

    display.setCursor(0,0);
    display.println("Water Tank Levels");
#endif

#ifdef VS_TANK
#if DISPLAY_TYPE == 0
    Serial.print("VS:");
#endif

#if DISPLAY_TYPE == 1
    display.print("VS: ");
    display.drawRect(25, 8, 50, 7, WHITE);
#endif

    if(vs_4q_value>v && vs_3q_value>v && vs_2q_value>v && vs_1q_value>v ) {
        vs_alarm = false;

#if DISPLAY_TYPE == 0
        Serial.println("100");
#endif

#if DISPLAY_TYPE == 1
        display.fillRect(25, 8, 50, 7, 1);
        display.setCursor(80,8);
        display.println("(100%)");
#endif

    } else if(vs_4q_value<v && vs_3q_value>v && vs_2q_value>v && vs_1q_value>v) {
        vs_alarm = false;

#if DISPLAY_TYPE == 0
        Serial.println("75");
#endif

#if DISPLAY_TYPE == 1
        display.fillRect(25, 8, 38, 7, 1);
        display.setCursor(80,8);
        display.println("(75%)");
#endif

    } else if(vs_4q_value<v && vs_3q_value<v && vs_2q_value>v && vs_1q_value>v) {
        vs_alarm = false;

#if DISPLAY_TYPE == 0
        Serial.println("50");
#endif

#if DISPLAY_TYPE == 1
        display.fillRect(25, 8, 25, 7, 1);
        display.setCursor(80,8);
        display.println("(50%)");
#endif

    } else if(vs_4q_value<v && vs_3q_value<v && vs_2q_value<v && vs_1q_value>v) {
        vs_alarm = false;

#if DISPLAY_TYPE == 0
        Serial.println("25");
#endif

#if DISPLAY_TYPE == 1
        display.fillRect(25, 8, 13, 7, 1);
        display.setCursor(80,8);

        display.println("(25%)");
#endif

    } else if(vs_4q_value<v && vs_3q_value<v && vs_2q_value<v && vs_1q_value<v) {
        vs_alarm = true;

#if DISPLAY_TYPE == 0
        Serial.println("0");
#endif

#if DISPLAY_TYPE == 1
        display.fillRect(25, 8, 1, 7, 1);
        display.setCursor(80,8);

        if (vs_alarm) {
            if (vs_blink) {
                display.setTextColor(BLACK);
                vs_blink = false;
            } else {
                display.setTextColor(WHITE);
                vs_blink = true;
            }
        }
        display.println("( 0%)");
        display.setTextColor(WHITE);
#endif

    }
#endif // VS_TANK
 
#ifdef AS_TANK
    Serial.print("AS:");

#if DISPLAY_TYPE == 1
    display.print("AS: ");
    display.drawRect(25, 16, 50, 7, WHITE);
#endif

    if(as_4q_value>v && as_3q_value>v && as_2q_value>v && as_1q_value>v ) {
        Serial.println("100");

#if DISPLAY_TYPE == 1
        display.fillRect(25, 16, 50, 7, 1);
        display.setCursor(80,16);
        display.println("(100%)");
#endif

    } else if(as_4q_value<v && as_3q_value>v && as_2q_value>v && as_1q_value>v) {
        Serial.println("75");

#if DISPLAY_TYPE == 1
        display.fillRect(25, 16, 38, 7, 1);
        display.setCursor(80,16);
        display.println("(75%)");
#endif

    } else if(as_4q_value<v && as_3q_value<v && as_2q_value>v && as_1q_value>v) {
        Serial.println("50");

#if DISPLAY_TYPE == 1
        display.fillRect(25, 16, 25, 7, 1);
        display.setCursor(80,16);
        display.println("(50%)");
#endif

    } else if(as_4q_value<v && as_3q_value<v && as_2q_value<v && as_1q_value>v) {
        Serial.println("25");

#if DISPLAY_TYPE == 1
        display.fillRect(25, 16, 13, 7, 1);
        display.setCursor(80,16);
        display.println("(25%)");
#endif

    } else if(as_4q_value<v && as_3q_value<v && as_2q_value<v && as_1q_value<v) {
        Serial.println("0");

#if DISPLAY_TYPE == 1
        display.fillRect(25, 16, 1, 7, 1);
        display.setCursor(80,16);

        if (as_alarm) {
            if (as_blink) {
                display.setTextColor(BLACK);
                as_blink = false;
            } else {
                display.setTextColor(WHITE);
                as_blink = true;
            }
        }
        display.println("( 0%)");
        display.setTextColor(WHITE);
#endif

    }

#endif

#ifdef WS_TANK
    Serial.print("WS:");

#if DISPLAY_TYPE == 1
    display.print("WS: ");
    display.drawRect(25, 24, 50, 7, WHITE);
#endif

    if(ws_4q_value>v && ws_3q_value>v ) {
        vs_alarm = true;
        Serial.println("100");

#if DISPLAY_TYPE == 1
        display.fillRect(25, 24, 50, 7, 1);
        display.setCursor(80,24);

        if (ws_alarm) {
            if (ws_blink) {
                display.setTextColor(BLACK);
                ws_blink = false;
            } else {
                display.setTextColor(WHITE);
                ws_blink = true;
            }
        }
        display.println("(100%)");
        display.setTextColor(WHITE);
#endif

    } else if(ws_4q_value<v && ws_3q_value>v ) {
        vs_alarm = true;
        Serial.println("75");

#if DISPLAY_TYPE == 1
        display.fillRect(25, 24, 38, 7, 1);
        display.setCursor(80,24);

        if (ws_alarm) {
            if (ws_blink) {
                display.setTextColor(BLACK);
                ws_blink = false;
            } else {
                display.setTextColor(WHITE);
                ws_blink = true;
            }
        }
        display.println("(75%)");
        display.setTextColor(WHITE);
#endif

    } else {
        vs_alarm = false;
        display.setCursor(80,24);
        display.println("( 0%)");
        display.setTextColor(WHITE);
    }

#endif

#if DISPLAY_TYPE == 1
    display.display();
#endif
 
    delay(2000);
}
