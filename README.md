Embedded-Systems-Project
========================

Embedded systems task for XIOT company

1. Project Name: Light & Temperature Control
2. Date: 27/6/2018
3. Developer : karim Goda Sharabash


Introduction
============

My project was to control the light of the place ,and display the state of the light and the temperature in the place .
It can display it on a serial monitor or send it to your mobile via bluetooth .

Hardware Design
===============
I used an AVR atmega32 microcontroller , led , switch ,temperature sensor(lm35) ,and USBTTL (to send the data to me laptop as i used it  as a serial monitor ).
and i conneted them as following :
>led to PORTD pin5 
>switch to PORTD pin3 (hadware interrupt (INT1)).
>LM35 to PORTA pin 1 (channel 1 of the ADC).
>Serial monitor to PORTD pin 1 (TX of the UART ). 

Software Design
===============

I used Eclipse IDE 

The hierarchy of the software :
-----------------------------
MCAL layer :
This layer has the drivers for the peripherals of the MCU which i used ,
which are [IO - UART - ADC - hardware interrupt].

HAL layer :
this layer has the drivers for the hardware components which i used ,
which are [LED - Switch - serial monitor - temperature sensor ] 

service stack :
which have type definition for all the data types ,which is more specific and easy to use .

Application layer : 
This layer has the main file (the entry point of the project).



