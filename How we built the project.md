How we built the project


We wanted to create a device which would be able to notify the caretakers of Dementia patients when the patient stepped out of a set radius of location via SMS. This will help reduce the panic and constant concern of the caretakers as to if the patient is safe or has wandered away. This will reduce the threat of a patient wandering away into unknown locations and injuring themselves. 


Step 1: Establishing ESP Now Protocol

We decided to use two ESP32 devices and establish wireless communication or ESP Now Protocol between them. 

1 ESP32 would act as a sender and the other one would act as a receiver

We uploaded the MAC address of the receiving ESP to the sending ESP and paired the devices. 

A detailed tutorial of this has been uploaded on the reference folder and the codes uploaded for both the sender and the receiver have been uploaded on the code folder


Step 2: Establishing a safe threshold and coding the receiver  

We coded the sender to send RSSI signals to the receiver

We set a safe threshold in the code of the receiver and coded it to recognize and send a message on the serial monitor when the RSSI signals drop below the safe threshold(-90dbm)

When the RSSI dropped below -90 it would display on the serial monitor that the patient has left the safe boundary



Step 3: Soldering battery on sender ESP32 

To make sure the sending ESP works without a power bank we connected a battery and a charging module to the ESP32

We connected a battery and soldered its positive and negative wires on a charging module.

We then soldered the positive and negative wires of the charging module to the VN and GND pins on the sender ESP32

We mounted the battery and charging module on the ESP32 and stuck them with double tape


Step 4: Connecting the serial monitor to SMS

To make sure the caretaker receives an alert directly on their phone, we connected a GSM module (SIM800L) to the receiving ESP32 and programmed it to send SMS notifications automatically.

We connected the SIM800L GSM module to the receiving ESP32 using UART communication.  
The TX and RX pins of the GSM module were connected to the RX and TX pins of the ESP32 respectively, while the GSM module was powered using an external power source.  
We inserted an active SIM card into the GSM module and checked if the module was communicating properly with the ESP32 using AT commands on the serial monitor.

After establishing communication, we coded the receiving ESP32 to connect the RSSI readings to the GSM module.  
When the RSSI value dropped below the safe threshold (-90 dBm), the receiving ESP32 automatically instructed the GSM module to send an SMS to the caretaker’s phone number stored in the code.

We also added an additional safety feature to the code. In situations where the signal is completely lost or the sending ESP32 stops transmitting, the receiver recognizes this as a ‘Signal Lost’ condition and sends a separate SMS alert to the caretaker.

This converted the serial monitor notifications into real mobile phone alerts, allowing caretakers to receive immediate notifications even when they are away from the monitoring device.


Step 5: 3D printing cases

We measured the ESP32 devices and designed an enclosure for the Sending ESP32 on FreeCAD and the receiving ESP32 and GSM module on Autodesk Fusion. You can use either of them.

Then send the deign to a slicer, we used Bambu Labs and then send it to the 3D printer

We then 3D printed the cases and fit the devices inside them


Step 6: Attaching pins for the badge

We soldered 2 holes at the back of the casing for the sending ESP or the badge and superglued pins on each of them. You can now pin the badge anywhere, in pockets, T-shirts etc. of the Dementia patient.


Step 7: Laser cutting the lids of the casing

We 3D printed the casing but laser cut the lids of the casing so its transparent and faster to print than a 3D printer. 

We designed the casing on Lightburn and then sent it to the laser cutter to laser cut.

We then fit the lid on the casing with all the devices inside it and the prototype was ready!


Step 8: Try it!

Take the sender ESP and move with it as if you are a patient away from the receiving ESP32 which will be kept in the centre of the house. 

Once the sender moves out of the safe threshold, an SMS notifying the caretaker that the patient has moved out of the safe zone will automatically be sent to the mobile number written down in the code.

Platforms used: 

Coding- ArduinoIDE

CAD designing for casing: FreeCAD and Autodesk Fusion

Slicing for 3D printing: Bambu Labs
