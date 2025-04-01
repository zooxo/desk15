# DESK15 - Scientific Calculator and Spreadsheet for the DM-15

-----

## *** Coming Soon ***

-----

See a short video of Version 1 of DESK15 at: https://youtu.be/

-----
# Pictures

![Image](https://github.com/user-attachments/assets/d231b53a-d2a7-45ee-83c7-3972496cfeb8)

-----
# Manual


```
____________________

PREAMBLE
____________________

The HP-15c was probably the most versatile scientific calculator. Similar to
DESK42 (for the DM42) DESK15 offers an alternative firmware for the
DM15C/DM15L replica of Swissmicros with primarily a complex number calculator
and a spreadsheet.
The restrictions of the NPX-ARM-Cortex-M0 microcontroller with 64 kilobytes of
flash memory and 8 kilobytes SRAM are vincible with efficient programming and
accepting the 7 digits precision for floating numbers.

Have fun
deetee

____________________

INSTALLATION
____________________

To install a new firmware to a DM-15 (Voyager) calculator have a look at
chapter Firmware Update of the Swissmicros Voyager Series User Manual at:
  https://technical.swissmicros.com/voyager/firmware/

On linux computers for example install the package lpc21isp and flash the
desired firmware (hex file) to the calculator with:
  sudo lpc21isp <firmware.hex> /dev/ttyUSB0 115200 12000

After starting this command press the reset button on the backside of the
calculator with a paperclip. After the flashing procedure ends you might need to
reset the calculator again.


____________________

PLEX
____________________

PLEX is a scientific calculator generically designed to work with complex
numbers. Many routines of PLEX are used by other applications (even if they work
with real numbers only). Beside advanced mathematic functions it even offers an
extensive function analysis (function value, slope, solve, integrate and plot).

PLEX supports the following functions:
  Basic
    0-9.      Number input
    ENTER     Enter number (stack lift) or duplicate TOS
    + - * /   Basic operation
    CHS       Negate TOS (ends number input)
    EEX       Push Y*10^X to the stack
    BSP gBSP  Clear number entry or TOS, clear stack and statistics data
    LASTx     Push last ENTERed number to stack
    ROT up/dn Rotate 3 stack elements
    STO RCL   Store TOS or push stored number to stack (store 0 to delete)
  Complex number operations
    fTAN      Convert X and Y (real values) to complex number (and vice versa)
    f1 g1     Display number in rectangular or polar view
    f-        Swap real and imaginary part of complex number
    fCHS      Conjugate complex number
  Advanced mathematics
    SQRT, SQR, EXP, LN, 10^X, LOG, Y^X, %, 1/X, delta%,
    FRAC, INT, ABS, PI, Pxy, Cxy, lnGAMMA
    SIN, COS, TAN, aSIN, aCOS, aTAN, SINH, COSH, TANH, aSINH, aCOSH, aTANH
  Statistics
    SUM+ SUM- Add/remove number to/from statistics registers
    g0 g.     Mean value and standard deviation
    fSUM      Parameters a and b of linear regression (y=a*x+b)
    gBSP      Clears statistics registers (and stack)
  Function analysis
    gRS       Start key recorder to input f(x)
    R/S       Stop key recorder, calculate y=f(X)
    fg/ fg*   Solve, slope, integrate, plot
  Conversions
    fg7 8 9   cm<>in, km<>mi, km<>nmi
    fg4 5 6   kg<>lbs, °C<>°F, l<>gal
    fg1 2 3   rect/polar view, h<>h.ms, deg<>rad
  Menu
    GSB       QUIT, pol/rect view, number size, HEX
    fGSB      BATTERY, set LCD brightness/voltage, ONtime, set OFFTIME
    gGSB      Get/set DATE, get/set TIME

    Please note:
    To set the OFFTIME enter the desired value (5-300) in seconds to the stack
    and press Toff (fGSB6).
    Be careful when setting the lcd brightness (fGSB4, 0-64) or lcd voltage
    (fGSB5, 0-5-7). The default values are 0 and 5.
    Get/set date and time from/to the real time clock (RTC) with the gGSB menu.
    The format for the date on the stack is YY.MMDDw (where w is the number of
    the weekday (0=monday). The format for the time is HH.MM.




```
