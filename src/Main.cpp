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

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

int v=100; //comparison variable(needs some adjustment)

int vs_1_quarter;
int vs_2_quarter;
int vs_3_quarter;
int vs_full;
int vs_1_pin = A0;
int vs_2_pin = A1;
int vs_3_pin = A2;
int vs_full_pin = A3;

int as_1_quarter;
int as_2_quarter;
int as_3_quarter;
int as_full;
int as_1_pin = A4;
int as_2_pin = A5;
int as_3_pin = A6;
int as_full_pin = A7;

int ws_3_quarter;
int ws_full;
int ws_3_pin = A8;
int ws_full_pin = A9;

void setup() {
    // Open serial communications
    Serial.begin(115200);

    // initialize with the I2C addr 0x3D (for the 128x64)
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    display.clearDisplay();

    pinMode(vs_1_pin,INPUT);
    pinMode(vs_2_pin,INPUT);
    pinMode(vs_3_pin,INPUT);
    pinMode(vs_full_pin,INPUT);

    pinMode(as_1_pin,INPUT);
    pinMode(as_2_pin,INPUT);
    pinMode(as_3_pin,INPUT);
    pinMode(as_full_pin,INPUT);

    pinMode(ws_3_pin,INPUT);
    pinMode(ws_full_pin,INPUT);
}

void loop() {
    vs_1_quarter = analogRead(vs_1_pin);
    vs_2_quarter = analogRead(vs_2_pin);
    vs_3_quarter = analogRead(vs_3_pin);
    vs_full = analogRead(vs_full_pin);

    as_1_quarter = analogRead(as_1_pin);
    as_2_quarter = analogRead(as_2_pin);
    as_3_quarter = analogRead(as_3_pin);
    as_full = analogRead(as_full_pin);

    ws_3_quarter = analogRead(ws_3_pin);
    ws_full = analogRead(ws_full_pin);

    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);

    display.setCursor(0,0);
    display.print("Water Tank Levels: ");

    display.setTextSize(2);
    display.setCursor(0,8);

    if(vs_full>v && vs_3_quarter>v && vs_2_quarter>v && vs_1_quarter>v ) {
        display.println("FULL");
    } else if(vs_full<v && vs_3_quarter>v && vs_2_quarter>v && vs_1_quarter>v) {
        display.println("75%");
    } else if(vs_full<v && vs_3_quarter<v && vs_2_quarter>v && vs_1_quarter>v) {
        display.println("50%");
    } else if(vs_full<v && vs_3_quarter<v && vs_2_quarter<v && vs_1_quarter>v) {
        display.println("25%");
    }
 
    delay(2000);
}
