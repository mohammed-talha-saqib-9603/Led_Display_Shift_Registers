# MAKING 8x8 LED DISPLAY USING SHIFT REGISTERS
<br>

**author**-mohammed talha saqib
<br>
This is the project with some bunch of leds(64), a microcontroller and shift registers (sipo) to increase number of output pins of microcontroller and to easily control output parallel pins with just strings of binary code or binary numbers.<br>

Here to control all leds only two shift registers as rows and columns are used, and a general problem of ghosting is solved by just switching on only one row at a time. Ghosting here refers to the condition where when only two leds at R1C1 and R2C2 is to be switched on but to switching on these: R1,R2,C1,C2 lines are opened and because of this, R1C2 and R2C1 leds will also glow, that means instead of two leds in diagonal four leds as a square they start glowing.<br>

Connections: all anodes of first column are connected to each other and then connected to Q0 of shift register-1 then anodes of column-2 leds to Q1 of shift register-1 and so on... then similarly cathodes of row-1 to Q0 of shift register-2, row-2 to Q1 of shift register-2 and so on.., like in circuit_image.png/diagram.json file.<br>

## Important Notes

- The display refresh is handled using Timer1 interrupts.
- Functions such as delay() will not turn off the display.
- However, animations and scrolling stop while the processor is inside delay().
- Maximum supported scrolling string length is 46 characters.
- This library is designed for 8×8 matrices driven using two 74HC595 shift registers.

*font files*:
This is the file from where anyone can easily access any array of character to display that character or any simple emoji. but this is added in library as an array or different character's bitmaps.<br>

**LIBRARY**:
simple library with some functions is added and can be downloaded as a zip file.
<br>

To include library navigate and select: SKETCH --> INCLUDE LIBRARY --> ADD .ZIP LIBRARY --> select downloaded library zip file.
<br>

Functions:
`display_begin(int ,int ,int );` //call this function in setup before using any function from this library so that It can map all the pins correctly.
`displayChar (char);` argument in this is a character that is displayed on display(any ascii character).
`displayEmoji(const uint8_t *str);` some of the emojis are already stored and can be used directly by calling this function simply :'displayEmoji(EMOJI_HAPPY);'
standard emojis: EMOJI_HAPPY, EMOJI_SAD, EMOJI_NEUTRAL, EMOJI_WINK, EMOJI_HEART, EMOJI_STAR, EMOJI_CHECK, EMOJI_CROSS, EMOJI_THUMBSUP, EMOJI_MUSICNOTE, EMOJI_SUN, EMOJI_LIGHTNING.
`displayImage(const uint8_t *str);` Any simple custom images can be displayed and can refer to Example_image.ino
`Scroll(char str[], int x_shift);` to scroll string from right to left, call this function and to control speed, no. of pixels shift of x can be passed to this function generally pass 1 for smoothness.

## Scrolling Algorithm
The scrolling function combines two adjacent character bitmaps and shifts them column by column.
For every refresh:
Current Character << shift OR Next Character >> (8 - shift)
This creates a smooth transition between characters.
<br>

**Simulation**:
To simulate this on wokwi, just open this link:https://wokwi.com/projects/467422138756908033 or anyone can simulate this using diagram.json and code.cpp file from this repository and pasting that whole content in wokwi simulator.<br>

# Features

- Displays all standard ASCII characters.
- Displays predefined emojis stored in PROGMEM.
- Supports custom 8×8 bitmap images.
- Smooth text scrolling from right to left.
- Uses Timer1 interrupt for flicker-free display refresh.
- Uses only 3 microcontroller pins to control the entire matrix.
- Uses PROGMEM to save SRAM.

# Real-World scenario:
This same circuit cannot directly implemented in real world scenario instead the connections should be like circuit_image_2.png(will be added soon) which includes simple transistors and external power supply for this led matrix.<br>
Every row and column should be driven with transistors because microcontroller and shift registers can't handle that much current.

## Future Improvements

- Multiple font sizes.
- Vertical scrolling.
- Animated emojis.
- Support for larger matrices.
- Brightness control using PWM.
- Chained 8×8 matrices.

## License

This project is open-source and may be modified and distributed freely for educational purposes.