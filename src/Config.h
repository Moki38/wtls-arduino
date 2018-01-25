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

//
// Version
//
#define VERSION 0.0.2

//
// Debug
//
//#define DEBUG 1

//
// Display
//     0: Serial Only
//     1: OLED Yelllow/Blue 128x64 (i2c 0x3c)
//     2: 1602 LCD Board Keypad Shield (Sainsmart)
//
#define DISPLAY_TYPE 1

//
// Define Tanks used
//
#define VS_TANK
#define AS_TANK
#define WS_TANK

//
// Defne Tank analog pins
//
#define VS_1Q_PIN A0
#define VS_2Q_PIN A1
#define VS_3Q_PIN A2
#define VS_4Q_PIN A3

#define AS_1Q_PIN A6
#define AS_2Q_PIN A7
#define AS_3Q_PIN A8
#define AS_4Q_PIN A9

#define WS_3Q_PIN A14
#define WS_4Q_PIN A14

