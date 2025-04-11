# DESK15 - Calculator Suite (including a Spreadsheet) for the DM-15

-----

## *** Coming Soon ***
## *** If you can't wait - try beta.hex ***

-----

See a short video of Version 1 of DESK15 at: https://youtu.be/

-----
# Pictures

![Image](https://github.com/user-attachments/assets/d231b53a-d2a7-45ee-83c7-3972496cfeb8)
![Image](https://github.com/user-attachments/assets/bd67d6db-1d2b-4793-a091-3f5fe8a7a563)
-----
# Manual

```
This software is protected by the BSD 3 Clause Licence
and copyright (c) 2025 by deetee. All rights reserved.


____________________

PREAMBLE
____________________

The HP-15c was probably the most simple butversatile scientific calculator.
Similar to DESK42 (for the DM42) DESK15 offers an alternative firmware for the
DM15/DM15L replica of Swissmicros with a suite of some applications like a
complex number calculator, a spreadsheet, a symbolic and a tabletop calculator.

See more at: github.com/zooxo/desk15

and have fun!
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
    SWAP      Swap X and Y
    ROT up/dn Rotate 3 stack elements
    STO RCL   Store TOS or push stored number to stack (store 0 to delete)
  Complex number operations
    fTAN      Convert X and Y (real values) to complex number (and vice versa)
    f1 g1     Display number in rectangular or polar view
    f-        Swap real and imaginary part of complex number
    fCHS      Conjugate complex number
  Advanced mathematics
    SQRT, SQR, EXP, LN, 10^X, LOG, Y^X, %, 1/X, delta%,
    FRAC, INT, ABS, PI, Pxy, Cxy, lnGAMMA, QuadraticEquation
    SIN, COS, TAN, aSIN, aCOS, aTAN, SINH, COSH, TANH, aSINH, aCOSH, aTANH
  Statistics
    SUM+ SUM- Add/remove number to/from statistics registers
    g0 g.     Mean value and standard deviation
    fSUM      Parameters a and b of linear regression (y=a*x+b)
    gBSP      Clears statistics registers (and stack)
  Function analysis
    gR/S      Start key recorder to input f(x)
    R/S       Stop key recorder, calculate y=f(X)
    fg/ fg*   Solve, slope, integrate, plot
    g-        Calculate 2 roots of quadratic equation axx+bx+c=0 (enter a b c)
  Conversions
    fg7 8 9   cm<>in, km<>mi, km<>nmi
    fg4 5 6   kg<>lbs, °C<>°F, l<>gal
    fg1 2 3   rect/polar view, h<>h.ms, deg<>rad
  Menu
    GSB       QUIT, View (pol/rect), Size of font, HEX mode
    fGSB      BATTERY, set LCD brightness/voltage, set OFFTIME
    gGSB      Get/set DATE, get/set TIME

    Please note:
    When in HEX mode enter numbers >9 with a dot (ie .1=a, .6=f).
    To set the OFFTIME enter the desired value (5-300) in seconds to the stack
    and press Toff (fGSB6).
    Be careful when setting the lcd brightness (fGSB4, 0-64) or lcd voltage
    (fGSB5, 0-5-7). The default values are 0 and 5.
    Get/set date and time from/to the real time clock (RTC) with the gGSB menu.
    The format for the date on the stack is YY.MMDDw (where w is the number of
    the weekday (0=Monday). The format for the time is HH.MM.


____________________

RAX
____________________

RAX is the spreadsheet application of DESK15. When starting RAX you are in the
navigation mode, where the number keys work as cursor pad (see below). The
navigation mode is also active when you refer in a formula to a specific cell.

Keys in navigation mode:
  2 4 6 8  Navigation (Down/Left/Up/Right)
  ENTER    Edit selected cell
  R/S      Define and edit a new text cell
  BSP      Delete cell
  STO RCL  Save/load spreadsheet from/to one of 6 slots
           Please note that a text in the last cell (D8) is used as slot name.
  GSB      Menu: Quit RAX, New sheet, Copy&Glue/Paste, Hex mode (see PLEX)

Keys in edit mode (ENTER to select and quit):
  SST GTO        Cursor left/right
  SUM+           Insert a stack enter command to separate numbers
  BSP            Backspace - delete character
  RCL            Reference (Select reference cell and enter)
  ENTER GSB R/S  Quit edit mode to navigation mode

____________________

FLEX
____________________

The symbolic calculator FLEX has the look and feel of PLEX, but actually
calculates  in the first cell of a RAX spreadsheet. Hence you can see and edit
(with R/S) the formula that yields to the result.

Quit FLEX (and go back to the DESK menu) with GSB.

____________________

TTOP
____________________

TTOP is a tabletop calculator that enables (simple) calculations with big
numbers (even in HEX format) with up to 17 digits. If desired two digits are
used for decimals (ie for cent amounts).

TTOP supports the following functions:
  + - * / Basic operation
  CHS     Negate TOS (ends number input)
  EEX     Push Y*10^X to the stack (Y*16^X in HEX mode)
  ENTER   Enter number (stack lift) or duplicate TOS
  SWAP    Swap X and Y
  ROT     Rotate 3 stack elements
  BSP     Clear last number
  SQRT    Calculate square root
  STO RCL Store TOS or push stored number to stack (store 0 to delete)
  GSB     Menu: Quit TTOP, 0/2 decimals, HEX mode




```
