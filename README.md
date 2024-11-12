Connection

P10 Display pins out           Arduino Pin No
OE                             10
A                              6
B                              7
C                              8
S                              13
L                              9
R                              11
G                              Not Connected
D                              Not Connected
N                              Arduino groung
And other N pind are not connected



ESP8266 Pins                 ArduinoPins
3.3V                         3.3V vcc
Ground                       groung
TX                           2(SoftwareSerial)
RX                           3(SoftwareSerial)

Hc05 same connection


this project wokt with ESP8266,Arduino uno and P10 matrix module
this is the project in which we interface wifi and Bluetooth in order to display the message in P10 display


//////////////////////////////////////////////P10///////////////////////////////////////////////////////////////////
First Thing First 
we have use the "DMD" libarary in programming in order to interface the P10 display with Arduino and print the message and also scroll it
some other libaray are also use with DMD libarary like 

1.#include <SystemFont5x7.h>  it is use to set font and size of text 
2.#include <SPI.h>            it is use to build wire SPI communication with board 
3.#include <TimerOne.h>       it is use to creat interrupts and refresh the led panel
4.#include <SoftwareSerial.h> it is use to crat our own TX and RX pin in Arduino

connection of Arduino with P10 display :--
P10 Display pins out           Arduino Pin No
     OE                             10
     A                              6
     B                              7
     C                              8
     S                              13
     L                              9
     R                              11
     G                              Not Connected
     D                              Not Connected
     N                              Arduino groung
And other N pind are not connected

//////////////////////////////////////////// HC05 BLUETOOTH/////////////////////////////////////////////////////////
Second Thing Second
we have connected the Bluetooth module which is hc05 with Arduino uno in order to build Bluetooth communication 
we have connected tx and rx of hc05 to Arduino pin 0 and 1 respectively 
         its work as when we send the text over hc05 Arduino read that message and translate its and convert it into string and disply it on P10 display its 
         use "if(Serial.available()){}" command to check for any incoming message 


/////////////////////////////////////////////ESP8266////////////////////////////////////////////////////////////////
last but not least
We have connected the esp8266 with Arduino and we use SoftwareSerial libarary to creat our own tx and rx pin in arduini we have use esp8266 same similar as Bluetooth. tx and rx of a ESP8266 are connected with Arduino pin 2 and 3 respectivily
         Working esp creat its own wifi poin in which user have to connect and then user have to note the IP address which is scrolling through P10 board already, then write that IP address to any browser like chrome, brave, fire fox etc and hit enter then the basic page should apper ware it provide to write the message user can write the message and hit submit then esp will take that message and transfer it to Arduino ware Arduino take that message and display it on P10 display



this project and write message in Three form 
ESP, wifi
HC05 Bluetooth
wire, Arduino wire 


