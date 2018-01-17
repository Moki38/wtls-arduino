# wtls-arduino

![Screenshot 1](http://wiki.team-moki.nl/download/attachments/16547884/IMG_0624.jpg?version=1&modificationDate=1514731941631&api=v2)

## Description

Water level sensor display, using Arduino/Teensy

- Raspberry PI
- PlatformIO
- Teensy 3.2
- OLED Yellow/Blue 128x64
- Water Tank Level Sensor (https://www.svb24.com/en/bavaria-water-tank-level-sensor.html)

## If you use a Raspberry Pi like me, use these commands to setup your enviromment
```console
sudo su -
apt-get install -y locate htop git i2c-tools build-essential

cd 
wget https://downloads.arduino.cc/arduino-1.8.5-linuxarm.tar.xz 
cd /usr/share 
tar xfJ ~/arduino-1.8.5-linuxarm.tar.xz 
ln -s arduino-1.8.5 arduino

cd /etc/udev/rules.d/ 
wget https://github.com/platformio/platformio-core/blob/develop/scripts/99-platformio-udev.rules 
systemctl restart udev 

cd 
wget https://raw.githubusercontent.com/platformio/platformio/develop/scripts/get-platformio.py 
python get-platformio.py
pip install -U platformio 

git clone https://github.com/Moki38/wtls-arduino.git
cd wtls-arduino
```

## Installation
```console
pio init -b teensy31

pio lib install git+https://github.com/adafruit/Adafruit-GFX-Library
pio lib install git+https://github.com/adafruit/Adafruit_SSD1306

pio run -t upload
```

## More documentation
http://wiki.team-moki.nl/x/dID8

