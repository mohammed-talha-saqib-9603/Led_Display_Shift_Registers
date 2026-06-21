# MAKING 8x8 LED DISPLAY USING SHIFT REGISTERS
<br>

**author**-mohammed talha saqib
<br>
This is the project with some bunch of leds(64), a microcontroller and shift registers (sipo) to increase number of output pins of microcontroller and to easily control output parallel pins with just strings of binary code or binary numbers.
Here to control all leds only two shift registers as rows and columns are used, and a general problem of ghosting is solved by just switching on only one row at a time. Ghosting here refers to the condition where when only two leds at R1C1 and R2C2 is to be switched on but to switching on these: R1,R2,C1,C2 lines are opened and because of this, R1C2 and R2C1 leds will also glow, that means instead of two leds in diagonal four leds as a square they start glowing.
Connections: all anodes of first column are connected to each other and then connected to Q0 of shift register-1 then anodes of column-2 leds to Q1 of shift register-1 and so on... then similarly cathodes of row-1 to Q0 of shift register-2, row-2 to Q1 of shift register-2 and so on.., like in circuit_image.png(will be added soon)/diagram.json file.

*font files*:
This is the file from where anyone can easily access any array of character to display that character or any simple emoji.(will be added soon...)

**Simulation**:
To simulate this on wokwi, just open this link:https://wokwi.com/projects/467422138756908033 or anyone can simulate this using diagram.json and code.cpp file from this repository and pasting that whole content in wokwi simulator.

# Real-World scenario:
This same circuit cannot directly implemented in real world scenario instead the connections should be like circuit_image_2.png(will be added soon) which includes simple transistors and external power supply for this led matrix.
16 transistors are to be added on every parallel out pin of shift registers.