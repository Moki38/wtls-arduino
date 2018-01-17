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

int v=100;          //  comparison variable (may need some adjustment)

#ifdef VS_TANK
int vs_1_quarter;
int vs_2_quarter;
int vs_3_quarter;
int vs_full;
int vs_1_pin = A0;
int vs_2_pin = A1;
int vs_3_pin = A2;
int vs_full_pin = A3;
#endif

#ifdef AS_TANK
int as_1_quarter;
int as_2_quarter;
int as_3_quarter;
int as_full;
int as_1_pin = A4;
int as_2_pin = A5;
int as_3_pin = A6;
int as_full_pin = A7;
#endif

#ifdef WS_TANK
int ws_3_quarter;
int ws_full;
int ws_3_pin = A8;
int ws_full_pin = A9;
#endif

//
// Setup
//
void setup() {
    // Open serial communications
    Serial.begin(115200);

#ifdef VS_TANK
    pinMode(vs_1_pin,INPUT);
    pinMode(vs_2_pin,INPUT);
    pinMode(vs_3_pin,INPUT);
    pinMode(vs_full_pin,INPUT);
#endif

#ifdef AS_TANK
    pinMode(as_1_pin,INPUT);
    pinMode(as_2_pin,INPUT);
    pinMode(as_3_pin,INPUT);
    pinMode(as_full_pin,INPUT);
#endif

#ifdef WS_TANK
    pinMode(ws_3_pin,INPUT);
    pinMode(ws_full_pin,INPUT);
#endif

}

//
// Main loop
//
void loop() {

#ifdef DEBUG
    Serial.print("Debug: ");
    Serial.print(vs_1_quarter);
    Serial.print(", ");
    Serial.print(vs_2_quarter);
    Serial.print(", ");
    Serial.print(vs_3_quarter);
    Serial.print(", ");
    Serial.println(vs_full);
#endif

#ifdef VS_TANK
    vs_1_quarter = analogRead(vs_1_pin);
    vs_2_quarter = analogRead(vs_2_pin);
    vs_3_quarter = analogRead(vs_3_pin);
    vs_full = analogRead(vs_full_pin);
#endif

#ifdef AS_TANK
    as_1_quarter = analogRead(as_1_pin);
    as_2_quarter = analogRead(as_2_pin);
    as_3_quarter = analogRead(as_3_pin);
    as_full = analogRead(as_full_pin);
#endif

#ifdef WS_TANK
    ws_3_quarter = analogRead(ws_3_pin);
    ws_full = analogRead(ws_full_pin);
#endif

#ifdef VS_TANK
    Serial.print("VS:");
    if(vs_full>v && vs_3_quarter>v && vs_2_quarter>v && vs_1_quarter>v ) {
        Serial.println("100");
    } else if(vs_full<v && vs_3_quarter>v && vs_2_quarter>v && vs_1_quarter>v) {
        Serial.println("75");
    } else if(vs_full<v && vs_3_quarter<v && vs_2_quarter>v && vs_1_quarter>v) {
        Serial.println("50");
    } else if(vs_full<v && vs_3_quarter<v && vs_2_quarter<v && vs_1_quarter>v) {
        Serial.println("25");
    }
#endif
 
#ifdef AS_TANK
    Serial.print("AS:");
    if(as_full>v && as_3_quarter>v && as_2_quarter>v && as_1_quarter>v ) {
        Serial.println("100");
    } else if(as_full<v && as_3_quarter>v && as_2_quarter>v && as_1_quarter>v) {
        Serial.println("75");
    } else if(as_full<v && as_3_quarter<v && as_2_quarter>v && as_1_quarter>v) {
        Serial.println("50");
    } else if(as_full<v && as_3_quarter<v && as_2_quarter<v && as_1_quarter>v) {
        Serial.println("25");
    }
#endif

#ifdef WS_TANK
    Serial.print("WS:");
    if(ws_full>v && ws_3_quarter>v ) {
        Serial.println("100");
    } else if(ws_full<v && ws_3_quarter>v ) {
        Serial.println("75");
    }
#endif
 
    delay(2000);
}
