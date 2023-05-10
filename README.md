# Arduino MEGA 2560 Custom PCB Design
This custom board is a Solar battery powered product that requires some peripherals attached to it to function. The product will be powered via Arduino Framework

The product should be offered as a single SKU, with external antenna for LTE CAT-M1 and GPS/GNSS.

## Requirements
* LCSC parts to be preferred for selection of components
* There will be 3 x MicroUSB inputs to the PCB. First USB input will provide 5V to power the board. Second USB input will be used to program the Arduino MEGA on board and the third USB input will be used to update firmware / debug the SIM7000A.
* One 12V output to power a Wika Pressure Sensor A-10 with GND
* Two analog inputs via screw terminals
* Analog inputs for 4 K-type thermocouples via screw terminals
* Separate antennae for LTE and GNSS
* SIM Card holder (preferably for Nano SIM)
* A screen is also required to display some helpful information to the user. Preference is to choose ILI9341 TFT LCD.
* SD card for logging values
* Reset and other necessary indications for SIMCOM module and MEGA 2560.

## Additional Information
The battery that will be used for input is https://voltaicsystems.com/amp/v75/


![image](https://user-images.githubusercontent.com/76909080/209631772-a6bcf645-6061-4da5-9e98-db27b5c935af.png)

![image](https://user-images.githubusercontent.com/76909080/209631864-0b5c67e2-68c8-4860-b638-d2efe5090fa7.png)

## Change log v2.0
1. 10K pull up on ON/OFF pin of LM2596S (U2) to prevent it turning ON in unknown/floating state
2. Write label/overlay text of both OLED LED connector pinout on PCB to know the pinouts easily.
3. Solder Bridge added between the inductor and GNSS_ANT netlabel to provide selection between Active and Passive GPS antenna.
4. ADC1 has the capability to drive a 4..20mA sensor using 250ohm resistance. ADC0 stays as is for applying direct 0..5V. RC filter, buffer and necessary input protection added on analog inputs.
5. Added another 4-pin OLED header LED10 and marked LED7 as DNP.
