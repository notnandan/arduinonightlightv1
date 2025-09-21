# arduinonightlightv1
These are the files for my arduino night light.![image](https://github.com/user-attachments/assets/123860f2-126b-41e7-9f19-f27f7fd63a64)

btw check releases for latest version.
v1.1 coming soon!
______________________________________
Things needed:
--------------
Arduino (preferably a Uno.Might also work with Nano with a few modifications)
LDR (light dependent resistor)
LEDs (any amount)
a 220 Ohm resistor
a 10K ohm resistor
Breadboard
Jumper Wires

Wiring instructions:
--------------------
Connect a jumper wire from D2 on the Arduino and plug the other end on the positive rail on the breadboard
Next, plug a jumper wire from any GND pin to the negative rail.
Place the 220 Ohm resistor between the LEDs and the POSITIVE(keep in mind) rail.
Now place the longer leg of the LED in series with the POSITIVE rail and the smaller leg on the NEGATIVE rail.
It should look like this:
![image](https://github.com/user-attachments/assets/a5567f52-e7ae-4d4f-b0c7-f427c2e70e50)
Now take another jumper wire and plug it into another GND pin.
Plug that GND pun into another negative rail. 
Plug a jumper wire into a 5V pin and plug it into another positive rail.
Plug one end of the LDR into the negative rail and the other leg into the positive rail. Put a 10K ohm resistor between the NEGATIVE rail and the LDR and a jumper wire connecting A0 between the LDR and the resistor.
It should look like this (i have a modified Arduino Uno but the breadboard wiring should be the Same.)
![image](https://github.com/user-attachments/assets/c2838978-7a27-4c34-b145-8c42f9fe81b2)
Now, upload the .ino file into the arduino and see the magic!
It checks for light every 20seconds.
