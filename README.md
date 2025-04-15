# DESK15 - Calculator Suite (including a Spreadsheet) for the DM-15

-----

## *** Coming Soon ***
## *** If you can't wait - try beta.hex ***

-----

See a short video of Version 1 of DESK15 at: https://youtu.be/

-----
# Pictures

![Image](https://github.com/user-attachments/assets/bd67d6db-1d2b-4793-a091-3f5fe8a7a563)

![Image](https://github.com/user-attachments/assets/bc5c9a2d-d0ef-484d-9f09-6aca62368779)

-----
# Manual

```
This software is protected by the BSD 3 Clause Licence
and copyright (c) 2025 by deetee. All rights reserved.


DESK15 - Calculator suite (including a Spreadsheet) for the DM-15

____________________

PREAMBLE
____________________

The HP-15c was probably the most simple but versatile scientific calculator.
Similar to DESK42 (for the DM42) DESK15 offers an alternative firmware for the
DM15/DM15L replica of Swissmicros with a suite of some applications like a
complex number calculator, a spreadsheet, a symbolic, a tabletop calculator
and even a sliderule and a simple text editor.

Have fun!
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

DESK
____________________

When you start DESK15 the first time you see the application launcher DESK. You
can launch the desired application with the keys 7, 8, 9 and 4, 5, 6:

  7 PLEX ... Complex Number Calculator
  8 FLEX ... Symbolic Calculator
  9 RAX  ... Spreadsheet
  4 TTOP ... Table Top Calculator
  5 RULE ... Slide Rule Simulation
  6 TEX  ... Text Editor

On the right side of the screen you see some extra information like the battery
level, date (day) and time (24 hour format).

Please note that the battery level is a momentarily value that varies due to the
momentarily activity of the calculator. But if you see the empty battery symbol
quite often you might consider changing the battery.

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
    R/S       Stop key recorder, calculate y=f(x)
    fg/ fg*   Solve, slope, integrate, plot
    g-        Calculate 2 roots of quadratic equation axx+bx+c=0 (enter a b c)
    GSB 8/9   SAVE/LOAD a recorded function to/from one of 6 slots
  Conversions
    fg7 8 9   cm<>in, km<>mi, km<>nmi
    fg4 5 6   kg<>lbs, °C<>°F, l<>gal
    fg1 2 3   rect/polar view, h<>h.ms, deg<>rad
  Menu
    GSB       QUIT, SAVE/LOAD, Physical Constant, Size of font, HEX mode
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

  Physical constants keys (GSB4):
    ENTER     Select (push) constant
    2 8 3 9   Down, Up, PgDown, PgUp
    GSB       Quit (without selecting)

  Physical constants;
    0  c    299792458         Speed of light
    1  g    9.80665           Acceleration of gravity
    2  G    6.67430e-11       Newton constant of gravity
    3  Vm   0.02271095464     Molar volume of ideal gas
    4  NA   6.02214076e23     Avogadro constant
    5  Rinf 10973731.568160   Rydberg constant
    6  h    6.62607015e-34    Planck constant
    7  Phi0 2.067833848e-15   Magnetic flux quantum
    8  a0   5.29177210903e-11 Bohr radius
    9  k    1.380649e-23      Boltzmann constant
    10 R    8.314462618       Molar gas constant
    11 F    96485.33212       Faraday constant
    12 t    273.15            Celsius temperature
    13 atm  101325            Standard atmosphere
    14 e    1.602176634e-19   Elementary charge
    15 eps0 8.8541878128e-12  Vacuum electric permittivity
    16 mu0  1.25663706212e-6  Vacuum magnetic permeability
    17 Z0   376.730313668     Impedance of vacuum
    18 mU   1.6605390666e-27  Atomic mass constant
    19 re   2.8179403262e-15  Electron radius
    20 me   9.1093837015e-31  Electron mass
    21 mp   1.67262192369e-27 Proton mass
    22 mn   1.67492749804e-27 Neutron mass
    23 mmu  1.883531627e-28   Muon mass
    24 muB  9.2740100783e-24  Bohr magneton
    25 muN  5.0507837461e-27  Nuclear magneton
    26 mue  -9.2847647043e-24 Electron magnetic moment
    27 mup  1.41060679736e-26 Proton magnetic moment
    28 mun  -9.6623651e-27    Neutron magnetic moment
    29 mumu -4.4904483e-26    Muon magnetic moment
    30 alph 7.2973525693e-3   Fine structure constant
    31 sigm 5.670374419e-8    Stefan-Boltzmann constant
    32 G0   7.748091729       Conductance quantum
    33 gamp 2.6752218744e8    Proton gyromagnetic ratio
    34 C1   3.741771852e-16   First radiation constant
    35 C2   1.438776877e-2    Second radiation constant


____________________

RAX
____________________

RAX is the spreadsheet application of DESK15. When starting RAX you are in the
navigation mode, where the number keys work as cursor pad (see below). The
navigation mode is also active when you refer in a formula to a specific cell.

Keys in navigation mode:
  2 4 6 8  Navigation (Down/Left/Right/Up)
  ENTER    Edit selected cell, edit new formula cell
  R/S      Define and edit a new text cell
  BSP      Delete cell
  STO RCL  Save/load spreadsheet to/from one of 6 slots
           Please note that a text in the last cell (D8) is used as slot name.
  GSB      Menu: Quit RAX, New sheet, Copy&Glue/Paste, Hex mode (see PLEX)

Keys in edit mode (ENTER to select and quit):
  SST GTO        Cursor left/right
  SUM+           Insert a stack enter command to separate numbers
  BSP            Backspace - delete character
  RCL            Reference (Select reference cell and enter)
  ENTER GSB R/S  Quit edit mode to navigation mode

Keys in text edit mode (R/S):
  2 4 6 8    Navigation (Down/Left/Right/Up)
  7 1 5      Pos1, End, Center
  SST GTO    Cursor left/right
  BSP        Delete character (left of cursor)
  R/S ENTER  Exit text editing mode
  Any other key inserts the selected character.


____________________

FLEX
____________________

The symbolic calculator FLEX has the look and feel of PLEX, but actually
calculates in the first cell of a RAX spreadsheet. Hence you can see and edit
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


____________________

RULE
____________________

RULE is a simulation of a historic slide rule for reasons of education and
reminiscence.

RULE supports the following functions:
  SQRT /   Slide one pixel left/right
  EXP 9    Slide 5 pixel left/right
  POW10 8  Slide 10 pixel left/right
  POW 7    Slide 20 pixel left/right
  GSB      Quit RULE


____________________

TEX
____________________

TEX is a (very) simple line oriented text editor. But as entering a text with
cursor keys is quite a pain TEX is sufficient to manage a ToDo or shopping list
or some important formulae. Please note that TEX can manage a maximum of 255
characters (with not more than 18 characters per line).

TTOP supports the following functions:
  4 8 3 9  Navigation (Down/Up/PdDown/PgUp)
  ENTER    Edit (top) line
  /        Edit line but split line at cursor position after editing
  *        Join two lines
  - BSP    Delete (top) line
  +        Insert line before top line
  STO RCL  Save/load TEX document to/from one of 6 slots
  GSB      Quit TEX

  To enter a new line after the last line edit with split option (/) and
  leave editor immediately (ENTER).
  To edit a text TEX uses the text editing routines of RAX (see above).



```
