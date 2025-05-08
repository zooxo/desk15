/*

//--v----1----v----2----v----3----v----4----v----5----v----6----v----7----v----8

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
reset the calculator again. Every Swissmicros-Calculator has a reset button
on the PCB (even if there is no hole to reach it).


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
    FRAC, INT, ABS, PI, Pxy, Cxy, lnGAMMA (f0),
    SIN, COS, TAN, aSIN, aCOS, aTAN, SINH, COSH, TANH, aSINH, aCOSH, aTANH
    fENTER    NAND ~(X & Y) ... useful in HEX mode
    g-        Calculate 2 roots of quadratic equation xx+px+q=0 (enter p q)
    fCOS      PV (present value) of interest rate (%) and duration (periods)
  Statistics
    SUM+ SUM- Add/remove number to/from statistics registers
    g0 g.     Mean value and standard deviation
    fSUM      Parameters a and b of linear regression (y=a*x+b)
    gBSP      Clears statistics registers (and stack)
  Function analysis
    gR/S      Start key recorder to input f(x) (gR/S R/S to delete)
    R/S       Stop key recorder, calculate y=f(x)
    fg/ fg*   Solve, slope, integrate, plot
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
    To set the OFFTIME (default is 60s) enter the desired value (5-300) in
    seconds to the stack and press Toff (fGSB6).
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
  ENTER 5  Edit selected cell, edit new formula cell
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
used for decimals (ie for cent amounts). PLease note that entering decimals
(after pressing ".") always "shifts the pressed number key in".

TTOP supports the following functions:
  + - * / Basic operation
  CHS     Negate TOS (ends number input)
  EEX     Push Y*10^X to the stack (Y*16^X in HEX mode)
  ENTER   Enter number (stack lift) or duplicate TOS
  SWAP    Swap X and Y
  ROT     Rotate 3 stack elements
  BSP     Clear last number
  SQRT    Calculate square root
  SUM+    NAND ~(X & Y) ... useful in HEX mode
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





The restrictions of the NPX-ARM-Cortex-M0 microcontroller with 64 kilobytes of
flash memory and 8 kilobytes SRAM are vincible with efficient programming and
accepting the 7 digits precision for floating numbers.


*/


//--v----1----v----2----v----3----v----4----v----5----v----6----v----7----v----8
//  I N C L U D E S ,   P R O T O T Y P E S ,   G L O B A L

#include <string.h>
#include "sysinit.h"
#include "core/cpu/cpu.h"
#include "core/pmu/pmu.h"
#include "drivers/lcd/bitmap/st7565/st7565.h"
#include "drivers/keyboard/keyboard.h"
#include "drivers/vref/vref.h"
#include "rtc.h"
#include <math.h>

static void _inv(void); // 1/X
static void _mult(void); // *
static void _sinh(void); // SINH
static void _exp(void); // EXP
static void _dup(void); // DUP
static void _div(void); // DIV
static void _asin(void); // ASIN
static void _neg(void); // NEG
static void _add(void); // ADD
static void _sqr(void); // SQR
static void _sqrt(void); // SQRT
static void _swap(void); // SWAP
static void _ln(void); // LN
static void _sub(void); // SUB
static void _rot(void); // ROT
static void _rotup(void); // ROT
static void _perm(void); // PERM
static void _int(void); // INT
static void _frac(void); // FRAC
static void _statclr(void); // Clear sum
static void ttmult(void); // MULT *
static void ttrot(void); // ROT
static void ttswap(void); // %
static void printslot(void); // Print slots

#define byte uint8_t // Define byte
#define sbyte int8_t // Define signed byte
#define END 255 // End byte, terminator
#define BLACK 1
#define WHITE 0
#define PI 3.1415926535897932F // PI
#define CM2IN 2.54F // Conversions
#define KG2LBS 2.2046226218F
#define L2GAL 3.785411784F
#define KM2STATMI 0.6213711922373F
#define KM2NAUTMI 0.53995680345572F


//--v----1----v----2----v----3----v----4----v----5----v----6----v----7----v----8
//  F O N T

#define FSIZES 1 // Font size (small or large)
#define FSIZEL 2
static byte fsize=FSIZES, fshift=0; // Font attributes
#define FW 5 // Font width
#define FWW (FW+1) // Font width (including separator pixel)
#define FOFFSET ' '

static const byte font[]={ // 6x8 font
  0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, // spc
  0b00000000, 0b00000000, 0b00101111, 0b00000000, 0b00000000, // !
  0b00000000, 0b00000111, 0b00000000, 0b00000111, 0b00000000, // "
  0b00010100, 0b01111111, 0b00010100, 0b01111111, 0b00010100, // #
  0b00101110, 0b00101010, 0b01111111, 0b00101010, 0b00111010, // $
  0b00100011, 0b00010011, 0b00001000, 0b01100100, 0b01100010, // %
  0b00110110, 0b01001001, 0b01010101, 0b00100010, 0b01010000, // &
  0b00000000, 0b00001011, 0b00000111, 0b00000000, 0b00000000, // '
  0b00000000, 0b00011100, 0b00100010, 0b01000001, 0b00000000, // (
  0b00000000, 0b01000001, 0b00100010, 0b00011100, 0b00000000, // )
  0b00010100, 0b00001000, 0b00111110, 0b00001000, 0b00010100, // *
  0b00001000, 0b00001000, 0b00111110, 0b00001000, 0b00001000, // +
  0b00000000, 0b01011000, 0b00111000, 0b00000000, 0b00000000, // ,
  0b00001000, 0b00001000, 0b00001000, 0b00001000, 0b00001000, // -
  0b00000000, 0b01100000, 0b01100000, 0b00000000, 0b00000000, // .
  0b00100000, 0b00010000, 0b00001000, 0b00000100, 0b00000010, // /
  0b01111111, 0b01000001, 0b01000001, 0b01000001, 0b01111111, // 0
  0b01000000, 0b01000010, 0b01111111, 0b01000000, 0b01000000, // 1
  0b01111001, 0b01001001, 0b01001001, 0b01001001, 0b01001111, // 2
  0b01000001, 0b01001001, 0b01001001, 0b01001001, 0b01111111, // 3
  0b00001111, 0b00001000, 0b00001000, 0b01111111, 0b00001000, // 4
  0b01001111, 0b01001001, 0b01001001, 0b01001001, 0b01111001, // 5
  0b01111111, 0b01001001, 0b01001001, 0b01001001, 0b01111000, // 6
  0b00000011, 0b00000001, 0b00000001, 0b00000001, 0b01111111, // 7
  0b01111111, 0b01001001, 0b01001001, 0b01001001, 0b01111111, // 8
  0b00001111, 0b01001001, 0b01001001, 0b01001001, 0b01111111, // 9
  0b00000000, 0b00110110, 0b00110110, 0b00000000, 0b00000000, // :
  0b00000000, 0b01011011, 0b00111011, 0b00000000, 0b00000000, // ;
  0b00001000, 0b00010100, 0b00100010, 0b01000001, 0b00000000, // <
  0b00010100, 0b00010100, 0b00010100, 0b00010100, 0b00010100, // =
  0b00000000, 0b01000001, 0b00100010, 0b00010100, 0b00001000, // >
  0b00000011, 0b00000001, 0b01011001, 0b00001001, 0b00001111, // ?
  0b01111011, 0b01001001, 0b01111001, 0b01000001, 0b01111111, // @
  0b01111111, 0b00001001, 0b00001001, 0b00001001, 0b01111111, // A
  0b01111111, 0b01001001, 0b01001001, 0b01001111, 0b01111000, // B
  0b01111111, 0b01000001, 0b01000001, 0b01000001, 0b01000000, // C
  0b01111111, 0b01000001, 0b01000001, 0b01100011, 0b00111110, // D
  0b01111111, 0b01001001, 0b01001001, 0b01001001, 0b01000001, // E
  0b01111111, 0b00001001, 0b00001001, 0b00001001, 0b00000001, // F
  0b01111111, 0b01000001, 0b01001001, 0b01001001, 0b01111001, // G
  0b01111111, 0b00001000, 0b00001000, 0b00001000, 0b01111111, // H
  0b01000001, 0b01000001, 0b01111111, 0b01000001, 0b01000001, // I
  0b01100000, 0b01000001, 0b01000001, 0b01000001, 0b01111111, // J
  0b01111111, 0b00001000, 0b00001000, 0b00001111, 0b01111000, // K
  0b01111111, 0b01000000, 0b01000000, 0b01000000, 0b01000000, // L
  0b01111111, 0b00000001, 0b00001111, 0b00000001, 0b01111111, // M
  0b01111111, 0b00000010, 0b00000100, 0b00001000, 0b01111111, // N
  0b01111111, 0b01000001, 0b01000001, 0b01000001, 0b01111111, // O
  0b01111111, 0b00001001, 0b00001001, 0b00001001, 0b00001111, // P
  0b01111111, 0b01000001, 0b01110001, 0b01000001, 0b01111111, // Q
  0b01111111, 0b00001001, 0b00001001, 0b01111001, 0b01001111, // R
  0b01101111, 0b01001001, 0b01001001, 0b01001001, 0b01111011, // S
  0b00000001, 0b00000001, 0b01111111, 0b00000001, 0b00000001, // T
  0b01111111, 0b01000000, 0b01000000, 0b01000000, 0b01111111, // U
  0b00011111, 0b00100000, 0b01000000, 0b00100000, 0b00011111, // V
  0b01111111, 0b01000000, 0b01111000, 0b01000000, 0b01111111, // W
  0b01100011, 0b00010100, 0b00001000, 0b00010100, 0b01100011, // X
  0b01001111, 0b01001000, 0b01111000, 0b01001000, 0b01001111, // Y
  0b01100001, 0b01010001, 0b01001001, 0b01000101, 0b01000011, // Z
  0b00000000, 0b01111111, 0b01000001, 0b01000001, 0b00000000, // [
  0b00000010, 0b00000100, 0b00001000, 0b00010000, 0b00100000, // backslash
  0b00000000, 0b01000001, 0b01000001, 0b01111111, 0b00000000, // ]
  0b00000100, 0b00000010, 0b00000001, 0b00000010, 0b00000100, // ^
  0b01000000, 0b01000000, 0b01000000, 0b01000000, 0b01000000, // _
  0b00100010, 0b00100111, 0b00100010, 0b01110010, 0b00100010, // ` leftright
  0b01110000, 0b01010100, 0b01010100, 0b01010100, 0b01111100, // a
  0b01111111, 0b01000100, 0b01000100, 0b01000100, 0b01111100, // b
  0b01111100, 0b01000100, 0b01000100, 0b01000100, 0b01000000, // c
  0b01111100, 0b01000100, 0b01000100, 0b01000100, 0b01111111, // d
  0b01111100, 0b01010100, 0b01010100, 0b01010100, 0b00011100, // e
  0b00000000, 0b00000100, 0b01111111, 0b00000101, 0b00000001, // f
  0b00011100, 0b01010100, 0b01010100, 0b01010100, 0b01111100, // g
  0b01111111, 0b00000100, 0b00000100, 0b00000100, 0b01111100, // h
  0b01000000, 0b01000100, 0b01111101, 0b01000000, 0b01000000, // i
  0b01100000, 0b01000000, 0b01000100, 0b01111101, 0b00000000, // j
  0b01111111, 0b00010000, 0b00010000, 0b00011100, 0b01110000, // k
  0b00000000, 0b01111111, 0b01000000, 0b01000000, 0b00000000, // l
  0b01111100, 0b00000100, 0b00011100, 0b00000100, 0b01111100, // m
  0b01111100, 0b00000100, 0b00000100, 0b00000100, 0b01111100, // n
  0b01111100, 0b01000100, 0b01000100, 0b01000100, 0b01111100, // o
  0b01111100, 0b00100100, 0b00100100, 0b00100100, 0b00111100, // p
  0b00111100, 0b00100100, 0b00100100, 0b00100100, 0b01111100, // q
  0b01111100, 0b00000100, 0b00000100, 0b00000100, 0b00001100, // r
  0b01011100, 0b01010100, 0b01010100, 0b01010100, 0b01110100, // s
  0b00000000, 0b00000100, 0b01111111, 0b01000100, 0b01000000, // t
  0b01111100, 0b01000000, 0b01000000, 0b01000000, 0b01111100, // u
  0b00000100, 0b01111100, 0b00100000, 0b00010000, 0b00001100, // v
  0b01111100, 0b01000000, 0b01110000, 0b01000000, 0b01111100, // w
  0b01000100, 0b00100100, 0b01111100, 0b01001000, 0b01000100, // x
  0b00011100, 0b01010000, 0b01010000, 0b01010000, 0b01111100, // y
  0b01000100, 0b01100100, 0b01010100, 0b01001100, 0b01000100, // z
  0b00001000, 0b01111111, 0b01000001, 0b01000001, 0b00000000, // {
  0b00000000, 0b00000000, 0b01111111, 0b00000000, 0b00000000, // |
  0b00000000, 0b01000001, 0b01000001, 0b01111111, 0b00001000, // }
  0b00011100, 0b00000100, 0b00011100, 0b00010000, 0b00011100, // ~
#define FBLACK 127 // black
 0b11111111, 0b11110111, 0b11100011, 0b11000001, 0b11111111,
//// INVERS, LETTERS
#define FI0 128 // 0 invers
  0b01111111, 0b01000001, 0b01011101, 0b01000001, 0b01111111,
#define FI1 129 // 1 invers
  0b01111111, 0b01011011, 0b01000001, 0b01011111, 0b01111111,
#define FI2 130 // 2 invers
  0b01111111, 0b01000101, 0b01010101, 0b01010001, 0b01111111,
#define FI3 131 // 3 invers
  0b01111111, 0b01010101, 0b01010101, 0b01000001, 0b01111111,
#define FI4 132 // 4 invers
  0b01111111, 0b01110001, 0b01110111, 0b01000001, 0b01111111,
#define FI5 133 // 5 invers
  0b01111111, 0b01010001, 0b01010101, 0b01000101, 0b01111111,
#define FI6 134 // 6 invers
  0b01111111, 0b01000001, 0b01010101, 0b01000101, 0b01111111,
#define FI7 135 // 7 invers
  0b01111111, 0b01111001, 0b01111101, 0b01000001, 0b01111111,
#define FI8 136 // 8 invers
  0b01111111, 0b01000001, 0b01010101, 0b01000001, 0b01111111,
#define FI9 137 // 9 invers
  0b01111111, 0b01010001, 0b01010101, 0b01000001, 0b01111111,
#define FIA 138 // A invers
  0b01111111, 0b01000001, 0b01110101, 0b01000001, 0b01111111,
#define FIB 139 // B invers
  0b01111111, 0b01000001, 0b01010101, 0b01000001, 0b01111111,
#define FIC 140 // C invers
 0b01111111, 0b01000001, 0b01011101, 0b01011101, 0b01111111,
#define FID 141 // D invers
 0b01111111, 0b01000001, 0b01011101, 0b01100011, 0b01111111,
#define FIE 142 // E invers
  0b01111111, 0b01000001, 0b01010101, 0b01010101, 0b01111111,
#define FIF 143 // E invers
  0b01111111, 0b01000001, 0b01110101, 0b01110101, 0b01111111,
#define FAEL 144 // Ä
  0b01111100, 0b00010101, 0b00010100, 0b00010101, 0b01111100,
#define FAES 145 // ä
  0b01110000, 0b01010101, 0b01010100, 0b01010101, 0b01111100,
#define FAOL 146 // Ao
  0b01111100, 0b00010111, 0b00010101, 0b00010111, 0b01111100,
#define FAOS 147 // ao
  0b01110100, 0b01010111, 0b01010101, 0b01010111, 0b01111100,
#define FANEL 148 // AE
  0b01111111, 0b00001001, 0b01111111, 0b01001001, 0b01001001,
#define FANES 149 // ae
  0b01110100, 0b01010100, 0b01111100, 0b01010100, 0b01011100,
#define FOEL 150 // Ö
  0b01111100, 0b01000101, 0b01000100, 0b01000101, 0b01111100,
#define FOES 151 // ö
  0b01111000, 0b01001010, 0b01001000, 0b01001010, 0b01111000,
#define FNTILDEL 152 // N~
  0b01111100, 0b00001001, 0b00010001, 0b00100001, 0b01111100,
#define FNTILDES 153 // n~
  0b01111000, 0b00001010, 0b00001010, 0b00001010, 0b01111000,
#define FUEL 154 // Ü
  0b01111100, 0b01000001, 0b01000000, 0b01000001, 0b01111100,
#define FUES 155 // ü
  0b01111000, 0b01000010, 0b01000000, 0b01000010, 0b01111000,
#define FQMFLIP 156 // ? flipped
  0b01100000, 0b01000000, 0b01001101, 0b01001000, 0b01111000,
//// GREEK
#define FALPHA 157 // alpha
  0b01111100, 0b01000100, 0b01000100, 0b00111000, 0b01000100,
#define FBETA 158 // beta
  0b01111111, 0b00000001, 0b00000101, 0b00100111, 0b00111100,
#define FDELTAL 159 // delta
  0b01100000, 0b01011000, 0b01000110, 0b01011000, 0b01100000,
#define FDELTAS 160 // delta small
  0b01111100, 0b01000100, 0b01000111, 0b01111101, 0b00000001,
#define FMU 161 // mu
  0b01111110, 0b01010000, 0b00010000, 0b00011110, 0b00010000,
#define FPI 162 // PI
  0b00000110, 0b01111110, 0b00000010, 0b01111110, 0b00000010,
#define FSUM 163 // sum
  0b01110111, 0b01011101, 0b01001001, 0b01000001, 0b01100011,
#define FSIGMA 164 // sigma
  0b01111100, 0b01000100, 0b01000100, 0b01111100, 0b00000100,
#define FTHETA 165 // theta
  0b00111110, 0b01001001, 0b01001001, 0b01001001, 0b00111110,
#define FOMEGA 166 // omega
  0b01011111, 0b01110001, 0b00000001, 0b01110001, 0b01011111,
//// ARROWS
#define FARRL 167 // arrow left
  0b00001000, 0b00011100, 0b00111110, 0b00001000, 0b00001000,
#define FARRD 168 // arrow down
  0b00001000, 0b00011000, 0b00111111, 0b00011000, 0b00001000,
#define FARRU 169 // arrow up
  0b00001000, 0b00001100, 0b01111110, 0b00001100, 0b00001000,
#define FARRR 170 // arrow right
  0b00001000, 0b00001000, 0b00111110, 0b00011100, 0b00001000,
#define FARRLU 171 // arrow left up
  0b00111110, 0b00000110, 0b00001010, 0b00010010, 0b00100010,
#define FARRRU 172 // arrow right up
  0b00100010, 0b00010010, 0b00001010, 0b00000110, 0b00111110,
#define FARRLD 173 // arrow left down
  0b00111110, 0b00110000, 0b00101000, 0b00100100, 0b00100010,
#define FARRRD 174 // arrow right down
  0b00100010, 0b00100100, 0b00101000, 0b00110000, 0b00111110,
#define FCURL 175 // cursor left
  0b00001000, 0b00011100, 0b00111110, 0b01111111, 0b00000000,
#define FCURD 176 // cursor down
  0b00000110, 0b00011110, 0b01111110, 0b00011110, 0b00000110,
#define FCURU 177 // cursor up
  0b00110000, 0b00111100, 0b00111111, 0b00111100, 0b00110000,
#define FCURR 178 // cursor right
  0b00000000, 0b01111111, 0b00111110, 0b00011100, 0b00001000,
#define FCURUD 179 // cursor up down
  0b00010100, 0b00110110, 0b01110111, 0b00110110, 0b00010100,
#define FSHIFT 180 // shift
  0b00000100, 0b01111110, 0b01111111, 0b01111110, 0b00000100,
#define FNAV 181 // navigation
  0b00011100, 0b01001001, 0b01100011, 0b01001001, 0b00011100,
#define FDIST 182 // distance
  0b00000000, 0b00100010, 0b01111111, 0b00100010, 0b00000000,
#define FENTER 183 // enter
  0b00010000, 0b00111000, 0b01111100, 0b00010000, 0b00011111,
//// MATH
#define FDEG 184 // degree
  0b00000000, 0b00000111, 0b00000101, 0b00000111, 0b00000000,
#define FDIV 185 // divide
  0b00001000, 0b00001000, 0b00101010, 0b00001000, 0b00001000,
#define FMULT 186 // mult
  0b00100010, 0b00010100, 0b00001000, 0b00010100, 0b00100010,
#define FEE 187 // enterexponent
  0b01111111, 0b01111111, 0b01001001, 0b01001001, 0b01000001,
#define FABS 188 // ABS
  0b00000000, 0b01111111, 0b00000000, 0b01111111, 0b00000000,
#define FANGLE 189 // angle
  0b00111110, 0b00101000, 0b00111000, 0b00100000, 0b00100000,
#define FANGLE45 190 // angle45
  0b00100000, 0b00110000, 0b00101000, 0b00100100, 0b00100010,
#define FSQRT 191 // sqrt
  0b00001000, 0b01111111, 0b00000001, 0b00000001, 0b00000011,
#define FINT 192 // integral
  0b01100000, 0b01000000, 0b01111111, 0b00000001, 0b00000011,
#define FPLUSMINUS 193 // +/-
  0b01000100, 0b01000100, 0b01011111, 0b01000100, 0b01000100,
#define FEXP 194 // exp
  0b01111100, 0b01111100, 0b01010100, 0b01010100, 0b00011100,
#define FSQR 195 // squared
  0b00000000, 0b00011101, 0b00010101, 0b00010111, 0b00000000,
#define FINV 196 // invers
  0b00000100, 0b00000100, 0b00010010, 0b00011111, 0b00010000,
#define FMEAN 197 // x mean
  0b01000101, 0b00100101, 0b01111101, 0b01001001, 0b01000101,
#define FYMEAN 198 // ymean
  0b00011101, 0b01010001, 0b01010001, 0b01010001, 0b01111101,
#define FINF 199 // infinite
  0b00011100, 0b00100010, 0b00011100, 0b00100010, 0b00011100,
#define FLE 200 // <=
  0b01010000, 0b01011000, 0b01010100, 0b01010010, 0b01010001,
#define FNE 201 // !=
  0b00010100, 0b01110100, 0b00011100, 0b00010111, 0b00010100,
#define FGE 202 // >=
  0b01010001, 0b01010010, 0b01010100, 0b01011000, 0b01010000,
//// SYMBOL
#define FSEP 203 // separate
  0b00000000, 0b00000000, 0b01010101, 0b00000000, 0b00000000,
#define F3DOT 204 // 3 dots
  0b01000000, 0b00000000, 0b01000000, 0b00000000, 0b01000000,
#define FDOT 205 // big middle dot
  0b00000000, 0b00011100, 0b00010100, 0b00011100, 0b00000000,
#define FMDOT 206 // middle dot
  0b00000000, 0b00000000, 0b00001000, 0b00000000, 0b00000000,
#define FGRID 207 // power grid
  0b00001000, 0b01001100, 0b00111110, 0b00011001, 0b00001000,
#define FBAT4 208 // battery full
  0b01111110, 0b01111111, 0b01111111, 0b01111111, 0b01111110,
#define FBAT3 209 // battery 3q
  0b01111110, 0b01111011, 0b01111011, 0b01111011, 0b01111110,
#define FBAT2 210 // battery medium
  0b01111110, 0b01110011, 0b01110011, 0b01110011, 0b01111110,
#define FBAT1 211 // battery 1q
  0b01111110, 0b01100011, 0b01100011, 0b01100011, 0b01111110,
#define FBAT0 212 // battery empty
  0b01111110, 0b01000011, 0b01000001, 0b01000011, 0b01111110,
#define FSQUARE 213 // square
  0b00111110, 0b00100010, 0b00100010, 0b00100010, 0b00111110,
#define FSQUAREF 214 // square filled
  0b00111110, 0b00111110, 0b00111110, 0b00111110, 0b00111110,
#define FCIRCLE 215 // circle
  0b00011100, 0b00110110, 0b00100010, 0b00110110, 0b00011100,
#define FCIRCLEF 216 // circle filled
  0b00011100, 0b00111110, 0b00111110, 0b00111110, 0b00011100,
#define FEXIT 217 // exit
  0b01110100, 0b01000110, 0b01011111, 0b01000110, 0b01110100,
#define FLINK 218 // link
  0b01110111, 0b01000001, 0b01011101, 0b01000001, 0b01110111,
#define FHOME 219 // home
  0b01111100, 0b01111110, 0b00001111, 0b01111110, 0b01111100,
#define FCALC 220 // calculator
  0b01010101, 0b00000001, 0b01010101, 0b00000001, 0b01010101,
#define FSCREEN 221 // display
  0b00011110, 0b01010010, 0b01110010, 0b01010010, 0b00011110,
#define FGAME 222 // game
  0b00111110, 0b00101110, 0b00111110, 0b00111010, 0b00111110,
#define FTXT 223 // text
  0b00000011, 0b01000001, 0b01111111, 0b01000001, 0b00000011,
#define FCAL 224 // calendar
  0b01111110, 0b01000011, 0b01011010, 0b01000011, 0b01111110,
#define FCLOCK 225 // clock
  0b00111110, 0b01100011, 0b01101111, 0b01101011, 0b00111110,
#define FSAND 226 // sandclock
  0b01100011, 0b01010101, 0b01001001, 0b01010101, 0b01100011,
#define FDISK 227 // save
  0b01111110, 0b01001110, 0b01001010, 0b01001010, 0b01111100,
#define FPAINT 228 // paint
  0b00111000, 0b01101100, 0b01111111, 0b01111100, 0b00111000,
#define FKBD 229 // keyboard
  0b00101010, 0b00100000, 0b00101010, 0b00100000, 0b00101010,
#define FTABLE 239 // table
  0b01010101, 0b01010101, 0b00000000, 0b01010101, 0b01010101,
#define FPLANE 231 // plane
  0b00001000, 0b01001100, 0b01111111, 0b01001100, 0b00001000,
#define FRAM 232 // ram
  0b00111110, 0b01100011, 0b00100010, 0b01100011, 0b00111110,
#define FHP 233 // HP
  0b00011111, 0b00000100, 0b01111100, 0b00010100, 0b00011100,
#define FPARA 234 // §
  0b00000000, 0b01011111, 0b01010101, 0b01111101, 0b00000000,
#define FSMILE 235 // smiley
  0b00100011, 0b01000011, 0b01001000, 0b01000011, 0b00100011,
#define FHEX 236 // hex16
 0b00111110, 0b00000000, 0b00111110, 0b00101010, 0b00111010,
#define FTICK 237 // tick
  0b01111000, 0b00110000, 0b00011000, 0b00001100, 0b00000110,
#define FTARGET 238 // crosshair
  0b01100111, 0b01000001, 0b01011100, 0b01000001, 0b01100111,
#define F10X 239 // 10^x
  0b01111000,0b00000000,0b01111000, 0b01001011, 0b01111011,
};


//--v----1----v----2----v----3----v----4----v----5----v----6----v----7----v----8
//  S Y S T E M

#define SX 132 // Screen dimensions
#define SY 16
#define SBYTES (SX*SY/8)
static byte sbuf[SBYTES]; // Screen buffer
static byte isbigdisplay=FALSE, isbigdtmp=FALSE; // Display format
static byte ishex=FALSE, isAF; // HEX mode, hex input demanded

static byte offtime=60; // Offtime in s

#define X1 3 // 1st column (small margin)
#define XS 109 // Status

#define _min(a,b) ({__typeof__(a) _a=(a);__typeof__(b) _b=(b); _a<_b?_a:_b;}) // Min
#define _max(a,b) ({__typeof__(a) _a=(a);__typeof__(b) _b=(b); _a>_b?_a:_b;}) // Max
#define _abs(a) ({__typeof__(a) _a=(a); _a<0?-_a:_a;}) // Absolute

#define c2s(c) (char[2]){(c),'\0'} // Convert char to string
#define cc2s(c1,c2) (char[3]){(c1),(c2),'\0'} // Convert 2 chars to string

static void getdate(dt_t* d, tm_t* t){pcf8563_read_time(); rtc_mask_time(d,t);} // Get date and time
static int timer(void){dt_t d; tm_t t; getdate(&d,&t); return(t.min*60+t.sec);} // Get timestamp from RTC (in sec)

static byte batt(void){ // Battery level
  int a=2100, b=2800; return((_max(_min(battery_voltage(),b-1),a)-a)*10/(b-a));
}

static byte expand4(byte b){ // Expand 4 bits (0000abcd->aabbccdd)
  b&=0x0f; b=(b|(b<<2))&0x33; b=(b|(b<<1))&0x55; return (b|(b<<1));
}
static byte reversebyte(byte b){ // Reverse bits in byte b
  b=((b>>1)&0x55)|((b<<1)&0xaa); b=((b>>2)&0x33)|((b<<2)&0xcc); return((b>>4)|(b<<4));
}

static void cat(byte c, byte x, byte row){ // Print character at x|row
  for(byte w=0;w<FW;w++){ // Font width
    byte isres=FALSE, data=font[(c-FOFFSET)*FW+w], b=data << fshift; // Residual (big), font data
    for(byte i=0; i<fsize; i++,x++) for(byte l=0;l<fsize;l++){  // Bold, Lines
      if(fsize==FSIZEL){ // Prepare big font (with residual)
        b=(expand4(data >> (l*4))) << 1;
        if(l){if(isres) b|=0x01;} else if(b & 0x80) isres=TRUE;
      }
      sbuf[x+(row+l)*SX]=reversebyte(b);
    }
  }
}

static void sat(char* s, byte x, byte r){for(; *s; s++,x+=fsize*FWW) cat(*s,x,r);} // Print string at x|r
static void satdot(char* s, byte x, byte r){ // Print string at x|row with slim dot
  for(; *s; s++,x+=fsize*FWW){byte pos=x; if(*s=='.'){pos=x-fsize; x-=fsize*2;} cat(*s,pos,r);}
}

static void i2s2(char* s,byte n){s[1]=n%10+'0'; s[0]=(n/10)%10+'0';} // Copy 2 digit int to string
static void i2s20(char* s,byte n){i2s2(s,n); if(n<10) s[0]=' ';} // Copy 2 digit int to string (supress 10th zero)
static void intat2(byte n,byte x,byte r){char s[2+1]; s[2]='\0'; i2s20(s,n); sat(s,x,r);} // Print 2 digit int

/*static byte idigits(int n){ // Count digits of n
  byte i=0; do i++; while(n/=10);
  return(i);
}
static void intat(int n, byte x, byte row){ // Print int at x|row
  byte i=0, d=idigits(n);
  do{cat(n%10+'0', x+(d-i-1)*FWW, row); i++;} while(n/=10);
}*/

static void strdelat(char* s, byte pos){ // Delete char at pos in string
  memcpy(s+pos,s+pos+1,strlen(s)-pos);
}
static void strcharat(char* s, char c, byte pos){ // Write S1 to s at position pos
  memmove(s+pos+1,s+pos,strlen(s)-pos+1); s[pos]=c;
}
static void strstrat(char* s, char* s1, byte pos){memcpy(s+pos,s1,strlen(s1));} // Write S1 to s at position pos

static void slead(char* s){ // Delete leading spaces in string
  byte i=0, len=strlen(s); while(i<len && s[i]==' ') i++; // Count
  memcpy(s,s+i,len-i+1);
}
static void strail(char* s){ // Delete trailing zeros in string
  for(byte i=strlen(s)-1; i && s[i]=='0'; i--) s[i]='\0';
}

static void strfill(char* s, char c, byte n){memset(s,c,n); s[n]='\0';} // Fill string with n chars c

static void vline(byte x){sbuf[x]=sbuf[x+SX]=0xff;} // Vertictal line

static void pixat(byte x, byte y){ // Set pixel in sbuf
  int p=y/8*SX+x; if(p<SBYTES) sbuf[p] |= (1 << (7-y%8)); // prereverse (7-)
}

#define NUMPLACES 8 // 7 digits + dot or 4+ee
static byte dnum=FALSE, decimals=0; // Num indicator, Decimals
static byte isprintx=FALSE; // Enable trailing zeros while number input

#define ALMOSTZERO 1e-99
#define ALMOSTINF 1e100
#define FIXMIN 1e-3
#define FIXMAX 1e7

static long double p10(sbyte e){ // Returns 10 raised to the power of e
  long double f=1.0F;
  if(e>0) while(e--) f*=10.0F; else while(e++) f/=10.0F;
  return(f);
}

static byte ldigits(long n){ // Counts digits of long variable
  byte i=0; for(;n;i++) n/=10;
  return(i);
}
static void f2sfix(char* str, long double f){ // Float to string (fixed format)
  byte sgn=0; if(f<0.0F){sgn=1; f=-f;} // Signum
  byte places=NUMPLACES-1-sgn; // Digits
  char* s=str+NUMPLACES; // Prepare string pointer (aligned right)

  if(f==0.0F){ // Zero value
    str[0]='0';
    if(decimals) str[0]='.';
    for(byte i=1; i<decimals && i<NUMPLACES; i++) str[i]='0';
  }
  else{
    sbyte e=0; while(f<1.0F){f*=10.0F; e--;} while(f>=1.0F){f/=10.0F; e++;} // Align 0<f<1
    long mant=(long)(f*p10(places)+0.5F); // Mantissa (+rounding for exact mantissa)
    long mant2=(long)(f*p10(places)); // Mantissa (without rounding)
    if(ldigits(mant)>ldigits(mant2)){mant/=10L; e++;} // Compensate digit leap when rounding
    long hi=mant/p10(places-e), lo=mant%((long)p10(places-e)); // High/low part of mantissa
    if(e<0) lo=((long double)lo/p10(-e)+0.5F); // Reduce digits of lo (+ rounding)
    byte loplaces=places-((e<0)?0:e); if(dnum && isprintx) for(byte i=0; i<loplaces; i++){ // Process lo
      if(i<loplaces-decimals+1) *--s=' '; else *--s=(lo%10)+'0';
      lo/=10;
    }
    else for(byte i=0; i<loplaces; i++){*--s=(lo%10)+'0'; lo/=10;}
    *--s='.'; // Process dot
    while(hi){*--s=(hi%10)+'0'; hi/=10;} // Process hi
    if(sgn) *--s='-'; // Sign
    if(!dnum || !isprintx) strail(s); // Trail everything but the input number
  }
}

static void f2ssci(char* str, long double f){ // Float to string (sci format)
  byte sgn=0; if(f<0.0F){sgn=1; f=-f;} // Signum
  byte places=NUMPLACES-1-sgn; // Digits
  char* s=str+NUMPLACES; // Prepare string pointer (aligned right)
  int e=0; while(f<1.0F){f*=10.0F; e--;} while(f>=1.0F){f/=10.0F; e++;} // Align 0<f<1
  if(e>-9 && e<=10) places++; // Provide one place more for single exponent
  long mant=(long)(f*p10(places-3)+0.5F); // Mantissa

  long mant2=(long)(f*p10(places-3)); // Mantissa (without rounding)
  if(ldigits(mant)>ldigits(mant2)){mant/=10L; e++;} // Compensate digit leap when rounding

  long hi=mant/p10(places-3-1), lo=mant%((long)p10(places-3-1));
  byte esgn=((e<0)?1:0); // Sign of exponent
  e--; if(e<0) e*=-1; // Compensate negative exponent
  *--s=e%10+'0'; e/=10; if(e) *--s=e%10+'0'; // Process exponent
  if(esgn) *--s='-'; else *--s='+'; // Process sign of exponent
  //while(lo){*--s=(lo%10)+'0'; lo/=10;} // Process lo //+++++ 02-error
  for(byte i=0; i<places-3-1; i++){*--s=(lo%10)+'0'; lo/=10;} // Process lo
  *--s='.'; // Process dot
  while(hi){*--s=(hi%10)+'0'; hi/=10;} // Process hi
  if(sgn) *--s='-'; // Sign
}

static void num2s(char* s, long double f) { // Convert number to string
  byte powsgn=1; if(f<0.0F) powsgn=10; // Compensate limit for negative number
  long double a=_abs(f);
  if(a>=ALMOSTINF || (a<=ALMOSTZERO && a>0.0F) || isnan(a) || isinf(a)) strcpy(s, "---"); // Beyond limits
  else if(a<ALMOSTZERO ||(a>=FIXMIN && a<FIXMAX/powsgn)) f2sfix(s, f); // Fixed format
  else f2ssci(s, f); // Scientific format
}

static void hex2s(char* str, unsigned long long n){ // Convert number to hex string
  char* s=str+NUMPLACES;
  while(n && s>str){ // Limit length to NUMPLACES
    char c=n%16LL+'0'; if(c>'9') c+=('a'-'9'-1);
    *--s=c; n/=16LL;
  }
  if(n) strcpy(s,"---"); // Overflow
  else slead(str);
}

static void printnum(long double a, byte x, byte row){ // Print (trailed) number or hex string at x|row
  char s[NUMPLACES+1]; strfill(s,' ',NUMPLACES);
  if(ishex){
    if(_abs(a)<1.0F) s[0]='0'; else hex2s(s,a);
    sat(s,x,row);
  }
  else{num2s(s,a); slead(s); satdot(s,x,row);}
}

static void printmenu(char* str){ // Print menu (6 bullet points)
  char s[5]; s[4]='\0';
  const byte x[]={X1,X1+6*FWW,X1+12*FWW}, b[]={7,8,9,4,5,6};
  for(byte i=0;i<6;i++){
    fshift=i/3; memcpy(s,str+i*4,4);
    cat(FI0+b[i],x[i%3],i/3); sat(s,x[i%3]+FWW,i/3);
  }
}


//--v----1----v----2----v----3----v----4----v----5----v----6----v----7----v----8
//  K E Y B O A R D

static byte key=0; // Global keypress variable

#define KEYROWS 4 // Keyboard dimensions
#define KEYCOLS 10
#define KEYS 39 // Number of keys

#define row(x) keymatrix_h[x][0],keymatrix_h[x][1] // Keymatrix (pins and keycodes)
#define col(x) keymatrix_v[x][0],keymatrix_v[x][1]
static const byte keymatrix_h[KEYROWS][2]={
  {KEYBOARD_H0_PORT, KEYBOARD_H0_PIN},{KEYBOARD_H1_PORT, KEYBOARD_H1_PIN},
  {KEYBOARD_H2_PORT, KEYBOARD_H2_PIN},{KEYBOARD_H3_PORT, KEYBOARD_H3_PIN}
};
static const byte keymatrix_v[KEYCOLS][2]={
  {KEYBOARD_V0_PORT, KEYBOARD_V0_PIN},{KEYBOARD_V1_PORT, KEYBOARD_V1_PIN},
  {KEYBOARD_V2_PORT, KEYBOARD_V2_PIN},{KEYBOARD_V3_PORT, KEYBOARD_V3_PIN},
  {KEYBOARD_V4_PORT, KEYBOARD_V4_PIN},{KEYBOARD_V5_PORT, KEYBOARD_V5_PIN},
  {KEYBOARD_V6_PORT, KEYBOARD_V6_PIN},{KEYBOARD_V7_PORT, KEYBOARD_V7_PIN},
  {KEYBOARD_V8_PORT, KEYBOARD_V8_PIN},{KEYBOARD_V9_PORT, KEYBOARD_V9_PIN}
};
#define K0 0 // Key codes
#define K1 1
#define K2 2
#define K3 3
#define K4 4
#define K5 5
#define K6 6
#define K7 7
#define K8 8
#define K9 9
#define KDOT 10
#define KSUM 11
#define KADD 12
#define KSUB 13
#define KMUL 14
#define KDIV 15
#define KCHS 16
#define KEE 17
#define KENTER 18
#define KSQRT 19
#define KEXP 20
#define KPOW10 21
#define KPOW 22
#define KINV 23
#define KSST 24
#define KGTO 25
#define KSIN 26
#define KCOS 27
#define KTAN 28
#define KRS 29
#define KGSB 30
#define KROT 31
#define KSWAP 32
#define KBSP 33
#define KON 34
#define KF 35
#define KG 36
#define KSTO 37
#define KRCL 38
static const byte keycode[KEYCOLS*KEYROWS]={ // Keycode matrix
  34, 29, 24, 19,
  35, 30, 25, 20,
  36, 31, 26, 21,
  37, 32, 27, 22,
  38, 33, 28, 23,
  18, 18, 17, 16,
   0,  1,  4,  7,
  10,  2,  5,  8,
  11,  3,  6,  9,
  12, 13, 14, 15
};

const char keyname[]={ // Key names (characters)
  '0','1','2','3','4','5','6','7','8','9', //0
  '.',FSIGMA,'+','-',FMULT,FDIV, //10 DOT
  FPLUSMINUS,FEE,FENTER, //16 CHS
  FSQRT,FEXP,F10X,FARRU,FINV, //19 SQRT
  FARRR,'h','S','C','T', //24 SST
  FCURR,FEXIT,FARRD,'`',FARRL, //29 RS
  FGRID,'f','g',FDISK,FDISK, //34 ON
};

static void setcolin(byte c){gpioSetDir(col(c), 1); gpioSetValue(col(c), 0);} // Set col c to input
static void setcolout(byte c){gpioSetDir(col(c), 0); gpioSetValue(col(c), 1);} // Set col c to output
static byte scankey(void){ // Get/Scan (one) key
  if(read_on_key_pin(1)) return(KON); // ON key
  for(byte i=0,k=0; i<KEYCOLS; i++){
    setcolin(i); // Set col i to input
    for(sbyte j=KEYROWS-1; j>=0; j--,k++)
      if(!gpioGetValue(row(j))){setcolout(i); return(keycode[k]);} // Set col i to output and return
    setcolout(i); // Set col i to output
  }
  return(END); // Default keypress code
}

static void keyrelease(){ // Wait for key release
  for(byte k,i=0;i<3;i++){k=scankey(); systickDelay(1); if(k!=END) i=0;}
}

void sleep(){ // Sleep mode
  keyrelease();
  rtc_disable_int(); st7565TurnOff();
  sleep_ds(0, WT_ON);
  if(!read_rtcint_pin()) // No sleep workaround
  sleep_ds(0, WT_ON);
  st7565Init(); //st7565ClearScreen(); st7565Refresh();
}


//--v----1----v----2----v----3----v----4----v----5----v----6----v----7----v----8
//  L C D   S C R E E N

static int isprintscreen=TRUE; // Print screen

static void lcdsend(byte b){ // Send byte b to lcd
  gpioSetValue(ST7565_SCLK_PORT, ST7565_SCLK_PIN, 1); // Make sure clock pin starts high
  for(int8_t i=7; i>=0; i--){ // Write from MSB to LSB
    gpioSetValue(ST7565_SCLK_PORT, ST7565_SCLK_PIN, 0); // Set clock pin low
    gpioSetValue(ST7565_SDAT_PORT, ST7565_SDAT_PIN, b & (1<<i)?1:0); // Set data pin high or low
    gpioSetValue(ST7565_SCLK_PORT, ST7565_SCLK_PIN, 1); // Set clock pin high
  }
}
static void lcdcmd(byte c){ // Send command to lcd
  gpioSetValue(ST7565_A0_PORT, ST7565_A0_PIN, 0);
  lcdsend(c);
}
static void lcddata(byte d){ // Send data to lcd
  gpioSetValue(ST7565_A0_PORT, ST7565_A0_PIN, 1);
  lcdsend(d);
}

void sbuf2lcd(void){ // Send screenbuffer to LCD
  __disable_irq();
  lcdcmd(ST7565_CMD_SET_PAGE | 1); // 1st row - row by row is faster than in a loop
  lcdcmd(ST7565_CMD_SET_COLUMN_LOWER); lcdcmd(ST7565_CMD_SET_COLUMN_UPPER);
  lcdcmd(ST7565_CMD_RMW);
  for(int c=0; c<SX; c++) lcddata(sbuf[c]);  // Chars with head up ("prereversed" in cat)
  lcdcmd(ST7565_CMD_SET_PAGE | 0); // 2nd row
  lcdcmd(ST7565_CMD_SET_COLUMN_LOWER); lcdcmd(ST7565_CMD_SET_COLUMN_UPPER);
  lcdcmd(ST7565_CMD_RMW);
  for(int c=SX; c<2*SX; c++) lcddata(sbuf[c]);  // Chars with head up ("prereversed" in cat)
  __enable_irq();
}


//--v----1----v----2----v----3----v----4----v----5----v----6----v----7----v----8
//  P L O T  -  Plot Graph

static byte isplot=FALSE;
#define PLOTX 32
#define PLOTY 16
static long double plotmin=0.0F, plotmax=0.0F;
static long double limita=0.0F, limitb=0.0F;
static byte plot[PLOTX];

static void plotstart(void){isplot=TRUE;} // Start plotting

static void printplot(void){ // Print plot
  byte x1=2, x2=50, xp=98, x=limita/(limita-limitb)*PLOTX, y=PLOTY-plotmin/(plotmin-plotmax)*PLOTY;
  fshift=FALSE; printnum(plotmin,x1,0); printnum(plotmax,x2,0); // Print limits
  fshift=TRUE; printnum(limita,x1,1); printnum(limitb,x2,1);
  for(byte i=0;i<PLOTX;i++){pixat(xp+i,PLOTY-1-plot[i]); pixat(xp+i,y);} // Plot x, x-axis
  vline(xp+x); // y-axis
}


//--v----1----v----2----v----3----v----4----v----5----v----6----v----7----v----8
//  G E T S T R I N G

static byte isgets=FALSE, isgots=FALSE, getscurpos=0;

#define MAXGETS 18 // Input string (formula string has double length)
static char gots[MAXGETS+1]="";

#define ASCCOLS 16 // Number of columns in ascii table
static byte ascrow=0, asccol=0; // Row and col in ascii table

static void printgets(void){ // Print gets-screen
  fshift=FALSE;
  if(strlen(gots)){strcharat(gots,FBLACK,getscurpos); sat(gots,X1,0); strdelat(gots,getscurpos);} // gots
  else cat(FBLACK,X1,0); // Empty gots
  fshift=TRUE;
  for(byte i=0,x=X1; i<ASCCOLS; i++,x+=FWW){ // Ascii menu
    cat(ascrow*ASCCOLS+i+' ',x,1); if(i==asccol){x+=FWW; cat(FBLACK,x,1);}
  }
}


//--v----1----v----2----v----3----v----4----v----5----v----6----v----7----v----8
//  P H Y S I C A L   C O N S T A N T S

static byte ispc=FALSE, pcnr=0;

static long double const pc[]={ // Physical constants
  299792458, 9.80665, 6.67430e-11, 0.02271095464, 6.02214076e23, 10973731.568160,
  // c: Speed of light, g: Acceleration of gravity, G: Newton constant of gravity
  // Vm: Molar volume of ideal gas, NA: Avogadro constant, Rinf: Rydberg constant
  6.62607015e-34, 2.067833848e-15, 5.29177210903e-11, 1.380649e-23, 8.314462618, 96485.33212,
  // h: Planck constant,  Phi0: Magnetic flux quantum, a0: Bohr radius
  // k: Boltzmann constant, R: Molar gas constant, F: Faraday constant
  273.15, 101325, 1.602176634e-19, 8.8541878128e-12, 1.25663706212e-6, 376.730313668,
  // t: Celsius temperature, atm: Standard atmosphere, e: Elementary charge
  // eps0: Vacuum electric permittivity, mu0: Vacuum magnetic permeability, Z0: Impedance of vacuum
  1.6605390666e-27, 2.8179403262e-15, 9.1093837015e-31, 1.67262192369e-27, 1.67492749804e-27, 1.883531627e-28,
  // mU: Atomic mass constant, re: Electron radius, me:Electron mass
  // mp: Proton mass, mn: Neutron mass, Mmu: Muon mass
  9.2740100783e-24, 5.0507837461e-27, -9.2847647043e-24, 1.41060679736e-26, -9.6623651e-27, -4.4904483e-26,
  // B: Bohr magneton, muN: Nuclear magneton, mue: Electron magnetic moment
  // mup: Proton magnetic moment, mun: Neutron magnetic moment, mumu: Muon magnetic moment
  7.2973525693e-3, 5.670374419e-8, 7.748091729, 2.6752218744e8, 3.741771852e-16, 1.438776877e-2,
  // alpha: Fine structure constant, sigma: Stefan-Boltzmann constant, G0: Conductance quantum
  // gamp: Proton gyromagnetic ratio, C1: First radiation constant, C2: Second radiation constant
};
static byte sizeofpc(void){return((sizeof(pc)/sizeof(long double)));} // Count of physical constants

const char* const pcname[]={ // Command names
  "c", "g", "G", "Vm", "NA", "Rinf",
  "h", "PHI0", "a0", "k", "R", "F",
  "t", "atm", "e", "eps0", c2s(FMU), "Z0",
  "mU", "re", "me", "mp", "mn", cc2s('m',FMU),
  cc2s(FMU,'B'), cc2s(FMU,'N'), cc2s(FMU,'e'), cc2s(FMU,'p'), cc2s(FMU,'n'), cc2s(FMU,FMU),
  c2s(FALPHA), c2s(FSIGMA), "G0", "gamp", "C1", "C2",
};

static void printpc(void){ // Print physical constants menu
  fshift=FALSE; printnum(pc[pcnr],X1,0); // Constant
  fshift=TRUE; cat(FCURUD,X1,1); intat2(pcnr+1,X1+2*FWW,1); sat((char*)pcname[pcnr],X1+5*FWW,1); // Menu
}


//--v----1----v----2----v----3----v----4----v----5----v----6----v----7----v----8
//  P L E X  -  Complex Calculator

static byte isplex=FALSE, ispmenu=0, isplotcalc=FALSE;
static byte issave=FALSE, isload=FALSE; // Save/load demanded

#define _DOT 10 // Dot
#define MAXCMD (3*KEYS) // 3*39 Commands (regular, f and g)

static byte isrect=TRUE; // Rectangular or polar display
static byte isfg=0, ishyp=FALSE, ishypa=FALSE; // F/G-key status, hyperbolics selection
# define MAXREC 50 // Maximum of recordable keys
static byte isplay=FALSE, isrec=FALSE, rec[MAXREC]={END}, recp=0; // Keypress recorder
static byte pstore[6][MAXREC]; // Plex function storage (6 slots)
static char pslotname[6][4]={"-","-","-","-","-","-"}; // Save/load slot names
#define DELTAX 0.001F // Analysis specs
#define MAXLAPS 20
#define STRIPES 10
static byte runs=0, laps=0, isslope=FALSE, issolve=FALSE, isint=FALSE; // Slope, Solver, Integrate
static long double intf=0.0F, intdelta=0.0F, slopex=0.0F;

struct data {long double r,i;}; // Structure for complex numbers
#define PLEXSTACKSIZE 8
struct data ds[PLEXSTACKSIZE]; // Data stack
static byte dp=0, islift=FALSE; // Data stack pointer, Num and Lift indicator, Decimals
struct data store={0.0F,0.0F}, lastx={0.0F,0.0F}; // Store, LastX
static byte sn=0; // Statistics
struct data sx={0.0F,0.0F}, sy={0.0F,0.0F}, sxx={0.0F,0.0F}, sxy={0.0F,0.0F}; // Store, LastX

static void push(struct data c){ // Push number to data stack
  if(dp>=PLEXSTACKSIZE){ // Float stack if full
    memmove(ds,ds+1,(PLEXSTACKSIZE-1)*sizeof(struct data));
    dp--;
  }
  ds[dp++]=c;
}
static long double pushr(long double f){ // Push real number to data stack
  push((struct data){f,0.0F});
  return(f);
}
static struct data pop(void){ // Pop value from data stack
  if(dp) return(ds[--dp]);
  return((struct data){0.0F,0.0F});
}
static long double popr(void) { // Pop real number from data stack
  return(dp?pop().r:0.0F);
}

static void push1(void){pushr(1.0F);} // Push 1
static void push1add(void){pushr(1.0F); _add();} // Push 1 +
static void push1sub(void){pushr(1.0F); _sub();} // Push 1 -
static void push2(void){pushr(2.0F);} // Push 2
static void pushi(void){push((struct data){0.0F,1.0F});} // Push i
static void push100mult(void){pushr(100.0F); _mult();} // Push 100 *
static void push100div(void){pushr(100.0F); _div();} // Push 100 /

#define REFSTACKSIZE 5 // Reference address stack
static byte refstack[REFSTACKSIZE], refp=0;
static void pushrefstack(byte n){
  if(refp>=REFSTACKSIZE){memmove(refstack, &refstack[1], (REFSTACKSIZE-1)*sizeof(byte)); refp--;} // Float stack
  refstack[refp++]=n;
}

// MATH

#define _rad(x) ((x)*PI/180.0F) // DEG -> RAD
#define _deg(x) ((x)*180.0F/PI) // RAD -> DEG

#define _dec(x,n) (((x)+((n)-1))%(n)) // Decrement pointer
#define _inc(x,n) (((x)+1)%(n)) // Increment pointer

static long double h2hms(long double a){ // H->HMS
  a=a*3600.0F+1e-10; // Add delta to avoid rounding leap
  long double hh=(long)(a/3600.0F), mm=(long)((a-hh*3600.0F)/60.0F), ss=(a-mm*60.0F-hh*3600.0F);
  return(hh+mm/100.0F+ss/10000.0F);
}
static long double hms2h(long double a){ // HMS->H
  a+=1e-10; // Add delta to avoid rounding leap
  long double hh=(long)a, mm=(long)((a-hh)*100.0F), ss=((a-hh)*100.0F-mm)*100.0F;
  return((ss/60.0F+mm)/60.0F+hh);
}

static long double absolute(long double a, long double b){ // Absolute of complex
  return(sqrt(a*a+b*b));
}
static long double angle(long double a, long double b){ // Angle of complex
  long double tmp=_deg(atan(b/a));
  if(a<0.0F) return(b<0.0F?tmp-180.0F:tmp+180.0F); // Quadrant 2 or 3
  else return(tmp); // Quadrant 1 or 4
}
static byte isreal(void) { // True, if TOS is real
  if(dp && _abs(ds[dp-1].i)>ALMOSTZERO) return(FALSE); // Imaginary part almost 0
  return(TRUE);
}

//  F U N C T I O N   P O I N T E R   A R R A Y

static void nop(){} // No operation
static void _s(void){decimals=0; dnum=islift=FALSE;} // Clear stack behavior
static void _f(void){isfg=ispmenu=0; ishyp=ishypa=FALSE;} // Clear f keys

static void numinput(byte n){ // Manage number (and dot) input
  if(n==_DOT && !ishex){ // Dot
    if(!decimals) decimals=1;
    if(!dnum){if(islift) pop(); pushr(0.0F); dnum=islift=TRUE;}
  }
  else{ // Numeral
    if(!dnum){ // Push new numeral
      if(islift) pop();
      pushr((long double)n); dnum=islift=TRUE;
    }
    else if(decimals){push((struct data){(pop().r+n/p10(decimals++)),0.0F});} // Append decimal
    else push((struct data){(pop().r*(ishex?16.0F:10.0F)+n),0.0F}); // Append numeral
  }
}
static void _n0(void){numinput(0);} // 0
static void _n1(void){numinput(isAF?10:1); isAF=FALSE;} // 1a
static void _n2(void){numinput(isAF?11:2); isAF=FALSE;} // 2b
static void _n3(void){numinput(isAF?12:3); isAF=FALSE;} // 3c
static void _n4(void){numinput(isAF?13:4); isAF=FALSE;} // 4d
static void _n5(void){numinput(isAF?14:5); isAF=FALSE;} // 5e
static void _n6(void){numinput(isAF?15:6); isAF=FALSE;} // 6f
static void _n7(void){numinput(7);} // 7
static void _n8(void){numinput(8);} // 8
static void _n9(void){numinput(9);} // 9
static void _dot(void){if(ishex)isAF=TRUE; else numinput(_DOT);} // DOT or hex input demand

static void _2deg(void){pushr(_deg(popr()));} // RAD2DEG
static void _2rad(void){pushr(_rad(popr()));} // DEG2RAD
static void _absolute(void){pushr(_abs(popr()));} // ABS
static void _acos(void){ // ACOS =PI/2-asin(x)
  _asin(); _neg();
  if(isreal()) pushr(90.0F); else pushr(PI/2.0F);
  _add();
}
static void _acosh(void){_dup(); _sqr(); push1sub(); _sqrt(); _add(); _ln();} // ACOSH =ln(x+sqrt(x*x-1))
static void _add(void){ // ADD +
  struct data b=pop(), a=pop();
  push((struct data){a.r+b.r,a.i+b.i});
}
static void _asin(void){ // ASIN =-i*ln(i*x+sqrt(1-x*x))
  _dup(); _sqr(); _neg(); push1add(); _sqrt(); _swap();
  pushi(); _mult(); _add(); _ln(); pushi(); _neg(); _mult();
  if(isreal()){pushr(_deg(popr()));}
}
static void _asinh(void){ // ASINH =ln(x+sqrt(x*x+1))
  _dup(); _sqr(); push1add(); _sqrt(); _add(); _ln();
}
static void _atan(void){ // ATAN =asin(x/(sqrt(1+x*x)))
  _dup(); _sqr(); push1add(); _sqrt(); _inv(); _mult(); _asin();
}
static void _atanh(void){ // ATANH =ln(sqrt((1+x)/(1-x)))
  _dup(); push1add(); _swap(); _neg(); push1add(); _div(); _sqrt(); _ln();
}
static void _bat(void){pushr(battery_voltage()/1000.0F);} // Push battery voltage
static void _cla(void){dp=0; _statclr();} // CLEAR STACK
static void _clx(void){ // CLX
  if(ishex){
    if(dnum){
      long long a=popr()/16.0F;
      if(!a) _s(); else pushr(a);
    }
    else lastx=pop(); // Clear X
  }
  else if(dnum){ // Clear last entry
    if(decimals){if(--decimals){long double a=p10(decimals-1);pushr((long long)(popr()*a)/a);}} // After dot
    else{long long a=popr()/10.0F; if(!a) _s(); else pushr(a);} // Integer
  }
  else lastx=pop();
}
static void _comb(void){ // COMB nCr=n!/r!/(n-r)!=nPr/r!
  byte k=pushr(popr()); _perm(); for(byte i=1;i<=k;i++) pushr(popr()/i);
}
static void _conj(void){struct data a=pop(); push((struct data){a.r,-a.i});} // Conjugate
static void _cos(void){ // COS cos(a+i*b)=cos(a)*cosh(b)-i*sin(a)*sinh(b)
  if(isreal()) pushr(cos(_rad(popr())));
  else{
    struct data a=pop(); long double e=exp(a.i);
    push((struct data){sin(PI/2.0F-a.r)*(e +1.0F/e)/2.0F, -1.0F*sin(a.r)*(e-1.0F/e)/2.0F});
  }
}
static void _cosh(void){_exp(); _dup(); _inv(); _add(); push2(); _div();} // COSH =(exp(x)+exp(-x))/2
static void _cvc2f(void){pushr(popr()*1.8F+32.0F);} // C2F
static void _cvcm2in(void){pushr(popr()/CM2IN);} // cm2inch
static void _cvf2c(void){pushr((popr()-32.0F)/1.8F);} // F2C
static void _cvgal2l(void){pushr(popr()*L2GAL);} // gal2l
static void _cvin2cm(void){pushr(popr()*CM2IN);} // inch2cm
static void _cvkg2lbs(void){pushr(popr()*KG2LBS);} // kg2lbs
static void _cvkm2nmi(void){pushr(popr()*KM2NAUTMI);} // km2nauticmiles
static void _cvkm2smi(void){pushr(popr()*KM2STATMI);} // km2statuemiles
static void _cvl2gal(void){pushr(popr()/L2GAL);} // l2gal
static void _cvlbs2kg(void){pushr(popr()/KG2LBS);} // lbs2kg
static void _cvnmi2km(void){pushr(popr()/KM2NAUTMI);} // nauticmiles2km
static void _cvsmi2km(void){pushr(popr()/KM2STATMI);} // statuemiles2km
static void _disp(void){isbigdisplay=!isbigdisplay;} // Toggle display format
static void _div(void){_inv(); _mult();} // DIV /
static void _dtgetd(void){ // Get date
  dt_t d; tm_t t; getdate(&d,&t);
  pushr(d.year+d.month/100.0F+d.day/10000.0F+(julian_day(&d)%7)/100000.0F);
}
static void _dtgett(void){dt_t d; tm_t t; getdate(&d,&t); pushr(t.hour+t.min/100.0F);} // Get time
static void _dtsetd(void){ // Set date
  dt_t d; tm_t t; long double a=popr();
  getdate(&d,&t); // Rescue t
  d.year=(byte)a; // Year
  pushr(a); _frac(); pushr(0.005F); _add(); // Month
  push100mult(); d.month=(byte)popr();
  pushr(a); push100mult(); _frac(); pushr(0.005F); _add(); // Day
  push100mult(); d.day=(byte)popr();
  rtc_write_datetime(&d,&t,0);
}
static void _dtsett(void){ // Set time
  dt_t d; tm_t t; byte wday=0; long double a=popr();
  getdate(&d,&t); // Rescue d
  t.hour=(byte)a;
  pushr(a+0.005F); _frac(); a=popr()*100.0F; t.min=(byte)a;
  rtc_write_datetime(&d,&t,wday);
}
static void _dup(void){ // DUP
  if(dp) push(lastx=ds[dp-1]);  // LastX
  dnum=FALSE; decimals=0; // islift remains
}
static void _ee(void){push((struct data){p10((sbyte)pop().r),0.0F}); _mult();} // EE
static void _exp(void){ // EXP
  struct data a=pop();
  long double e=exp(a.r);
  push((struct data){e*cos(a.i), e*sin(a.i)});
}
static void _fkeyfon(void){ishyp=ishypa=FALSE; isfg=1;} // F-key f on
static void _fkeygon(void){ishyp=ishypa=FALSE; isfg=2;} // F-key g on
static void _fkeyoff(void){ishyp=ishypa=FALSE; isfg=0;} // F-key off
static void _frac(void){_dup(); _int(); _sub();} // FRAC
static void _h2hms(void){pushr(h2hms(popr()));} // H2HMS
static void _hex(void){ishex=!ishex;} // HEX
static void _hms2h(void){pushr(hms2h(popr()));} // HMS2H
static void _hyp(void){ishyp=TRUE; isfg=0;} // Set HYP
static void _hypa(void){ishypa=TRUE; isfg=0;} // Set HYP-1
static void _integrate(void){ // INTEGRATE
  _swap(); limita=popr(); intdelta=(pushr(popr())-limita)/2/STRIPES;
  intf=0.0F; isint=TRUE; runs=isfg=0;
}
static void _int(void){pushr((long long)popr());} // INT
static void _inv(void){ // INV inv(a+jb)=a/(a*a+b*b)-i*b/(a*a+b*b)
  struct data a=pop();
  push((struct data){1.0F/(a.r+a.i/a.r*a.i), -1.0F/(a.i+a.r/a.i*a.r)});
}
static void _lastx(void){push(lastx);} // LASTx
static void _ln(void){ // LN ln(a+i*b)=ln(r*exp(i*f))=ln(r)+i*f r=|a+i*b| f=atan(b/a)
  struct data a=pop();
  push((struct data){log(absolute(a.r,a.i)), _rad(angle(a.r,a.i))});
}
static void _log(void){_ln(); pushr(10.0F); _ln(); _div();} // LOG  log(z)=ln(z)/ln(10)
static void _lngamma(void){ // LNGAMMA  =(ln(2*PI)-ln(z))/2+z*(ln(z+1/(12*z-1/10/z))-1)
  push1add();
  _dup(); _dup(); _dup(); _dup(); pushr(12.0F); _mult();
  _swap(); pushr(10.0F); _mult(); _inv(); _sub(); _inv(); _add(); _ln(); push1sub(); _mult();
  _swap(); _ln(); _neg(); pushr(2.0F*PI); _ln(); _add(); push2(); _div(); _add();
}
static void _mult(void){ // MULT * (a+i*b)*(c+i*d)=(a*c-b*d)+i*(b*c+a*d)
  struct data b=pop(), a=pop();
  push((struct data){a.r*b.r-a.i*b.i, a.r*b.i+a.i*b.r});
}
static void _nand(void){ // NAND
  long long b=popr(); pushr(~((long long)popr() & b));
}
static void _neg(void){ // NEGATE
  if(isreal()) push((struct data){-pop().r,0.0F}); // While num input or real
  else{struct data a=pop(); push((struct data){-a.r,-a.i});}
}
static void _p10(void){ // 10^
  pushr(10.0F); _ln(); _mult(); _exp();
}
static void _pc(void){ispc=TRUE;} // Physical constant

static void _percent(void){_swap(); _dup(); _rotup(); push100div(); _mult();} // % = B*x/100% (keep B)
static void _percentdelta(void){ // DELTA% =(x-B)/B*100%
  _swap(); _dup(); _rotup(); _swap(); _sub(); _swap(); _div(); push100mult();
}
static void _perm(void){ // PERM nPr=n!/(n-r)!
  byte a=popr(), b=popr(); a=b-a; push1();
  for(byte i=a;i<b;i++) pushr(popr()*(i+1));
}
static void _pi(void){pushr(PI);} // PI
static void _play(void){ // PLAY
  if(isrec) rec[recp-1]=END;
  isrec=FALSE; isplay=TRUE; recp=0;
}
static void _plot(void){ // PLOT
  memset(plot,0,sizeof(byte)*PLOTX);
  limitb=popr(); limita=pushr(popr()); intdelta=(limitb-limita)/(PLOTX-1);
  isplotcalc=TRUE; runs=laps=isfg=0;
}
static void _pmenu(void){ispmenu=(ispmenu?0:1);} // Menu
static void _pmenuf(void){ispmenu=2; isfg=0;} // Menu f
static void _pmenug(void){ispmenu=3; isfg=0;} // Menu g
static void _pow(void){ // PWR a^b=exp(b*ln(a))
  struct data a=pop(), b=pop();
  if(b.r==0.0F && b.i==0.0F){
    if(a.r==0.0F && a.i==0.0F) push((struct data){NAN,NAN}); // 0^0
    else push((struct data){0.0F,0.0F}); // 0^a
  }
  else{push(b); _ln(); push(a); _mult(); _exp();} // Regular b^a=exp(a*ln(b))
}
static void _pv(void){ // PV PV(i,n)=((1+i)^n-1)/(1+i)^n/i
  _swap(); push100div(); _dup(); _rot();
  push1add(); _swap(); _pow(); _dup(); push1sub(); _swap(); _div(); _swap(); _div();
}
static void _qe(void){  // Quadratic equation xx+px+q=0 (-p/2+-sqrt(pp/4-q))
  _swap(); push2(); _div(); _dup(); _dup(); _mult(); _rotup(); _sub(); _sqrt(); // p/2 sqrt
  _dup(); _rotup(); _neg(); _dup(); _rotup(); _add(); _rot(); _swap(); _sub(); // A B
}
static void _quit(void){isplex=FALSE;} // QUIT
static void _r2c(void){ // RealReal to complex and vice versa
  if(dp && isreal()){ // TOS real
    long double a=popr(); // Rescue real part of TOS
    if(dp && isreal()){ // Next TOS
      long double b=popr();
      if(isrect) push((struct data){a,b});
      else push((struct data){a*cos(_rad(b)),a*sin(_rad(b))}); // Convert from polar to rect
    }
    else pushr(a); // Repair nonexisting Y register
  }
  else{ // Complex to RealReal
    struct data a=pop();
    if(isrect){push((struct data){a.i,0.0F}); push((struct data){a.r,0.0F});}
    else{push((struct data){angle(a.r,a.i),0.0F}); push((struct data){absolute(a.r,a.i),0.0F});} // Convert
  }
}
static void _r2i(void){ // Swap real and imaginary part
  struct data a=pop();
  push((struct data){a.i,a.r});
}
static void _rec(void){recp=0; isrec=TRUE;} // REC
static void _rot(void){if(dp>2){struct data a=pop(), b=pop(), c=pop(); push(a); push(c); push(b);}} // ROT
static void _rotup(void){_rot(); _rot();} // ROT up
static void _sin(void){ // SIN  sin(a+i*b)=sin(a)*cosh(b)+i*cos(a)*sinh(b)
  if(isreal()) pushr(sin(_rad(popr())));
  else{
    struct data a=pop(); long double e=exp(a.i);
    push((struct data){sin(a.r)*(e +1.0F/e)/2.0F, sin(PI/2.0F-a.r)*(e-1.0F/e)/2.0F});
  }
}
static void _sinh(void){_exp(); _dup(); _inv(); _neg(); _add(); push2(); _div();} // SINH =(exp(x)-exp(-x))/2
static void _sqr(void){_dup(); _mult();} // SQR
static void _sqrt(void){ // SQRT =exp(0.5*ln(x))
  struct data a=pop();
  if(a.r==0.0F){pushr(0.0F);} // sqrt(0)
  else{push(a);_ln(); pushr(0.5F); _mult(); _exp();}
}
static void _slope(void){ // SLOPE
  slopex=pushr(popr()-2.0F*DELTAX); // f2-
  intf=0.0F; runs=0; isslope=TRUE; isfg=0;
}
static void _solve(void){_dup(); _dup(); issolve=TRUE; runs=laps=0;} // SOLVE
static void _statadd(void){ // SUM+
  sn++; // n
  _dup(); push(sx); _add(); sx=pop(); // X
  _dup(); _dup(); _mult(); push(sxx); _add(); sxx=pop(); // XX
  _swap(); _dup(); _rotup(); _mult(); push(sxy); _add(); sxy=pop(); // XY
  push(sy); _add(); sy=pop(); // Y
  pushr(sn); // Push n
}
static void _statclr(void){sn=0; sx=sxx=sxy=sy=(struct data){0.0F,0.0F};} // Clear sum
static void _statlr(void){ // LR y=a*x+b
  push(sxy); pushr(sn); _mult(); push(sx); push(sy); _mult(); _sub(); // a
  push(sxx); pushr(sn); _mult(); push(sx); _dup(); _mult(); _sub(); _div();
  _dup(); push(sx); _mult(); _neg(); push(sy); _add(); pushr(sn); _div(); _swap(); // b
}
static void _statmean(void){ // MEAN value =X/n
  push(sx); pushr(sn); _div();
}
static void _statsub(void){ // SUM-
  sn--; // n
  _dup(); push(sx); _swap(); _sub(); sx=pop(); // X
  _dup(); _dup(); _mult(); push(sxx); _swap(); _sub(); sxx=pop(); // XX
  _swap(); _dup(); _rotup(); _mult(); push(sxy); _swap(); _sub(); sxy=pop(); // XY
  push(sy); _swap(); _sub(); sy=pop(); // Y
  pushr(sn); // Push n
}
static void _statstdev(void){ // STDEV (XX-n*m^2)/(n-1)
  _statmean();
  _dup(); _mult(); pushr(sn); _mult(); _neg(); push(sxx); _add();
  pushr(sn); push1sub(); _div(); _sqrt();
}
static void _storcl(void){push(store);} // RCL
static void _stosto(void){push(store=pop());} // STO
static void _sub(void){_neg(); _add();} // SUB -
static void _swap(void){if(dp>1){struct data a=pop(), b=pop(); push(a); push(b);}} // SWAP
static void _tan(void){_dup(); _sin(); _swap(); _cos(); _div();} // TAN =sin(z)/cos(z)
static void _tanh(void){_dup(); _sinh(); _swap(); _cosh(); _div();} // TANH =sinh(z)/cosh(z)
static void _timeout(void){int sec=popr(); if(sec>=5 && sec<=300) offtime=sec;} // Set TIMEOUT
static void _viewrec(void){isrect=TRUE; isfg=0;} // Set rect view
static void _viewpol(void){isrect=FALSE; isfg=0;} // Set polar view
static void _zcos(void){if(ishyp) _cosh(); else if(ishypa) _acosh(); else _cos();} // Key COS
static void _zsin(void){if(ishyp) _sinh(); else if(ishypa) _asinh(); else _sin();} // Key SIN
static void _ztan(void){if(ishyp) _tanh(); else if(ishypa) _atanh(); else _tan();} // Key TAN

static const void (*dispatch[])(void)={ // Function array
  &_n0, &_n1, &_n2, &_n3, &_n4, &_n5, &_n6, &_n7, &_n8, &_n9, //0 Main keys
  &_dot, &_statadd, &_add, &_sub, &_mult, &_div, //10 Dot
  &_neg, &_ee, &_dup, //16 CHS
  &_sqrt, &_exp, &_p10, &_pow, &_inv, //19 SQRT
  &nop, &nop, &_zsin, &_zcos, &_ztan, //24 SST
  &_play, &_pmenu, &_rot, &_swap, &_clx, //29 RS
  &nop, &_fkeyfon, &_fkeygon, &_stosto, &_storcl, //34 ON

  &_lngamma, &_viewrec, &_h2hms, &_2rad, &_cvkg2lbs, &_cvc2f, &_cvl2gal, &_cvcm2in, &_cvkm2smi, &_cvkm2nmi, //39 f-keys
  &nop, &_statlr, &_perm, &_r2i, &_integrate, &_solve, //49 Dot
  &_conj, &nop, &_nand, //55 CHS
  &nop, &nop, &nop, &nop, &nop, //58 SQRT
  &nop, &_hyp, &nop, &_pv, &_r2c, //63 SST
  &nop, &_pmenuf, &nop, &nop, &nop, //68 RS
  &nop, &_fkeyoff, &_fkeygon, &_frac, &nop, //73 ON

  &_statmean, &_viewpol, &_hms2h, &_2deg, &_cvlbs2kg, &_cvf2c, &_cvgal2l, &_cvin2cm, &_cvsmi2km, &_cvnmi2km, //78 g-keys
  &_statstdev, &_statsub, &_comb, &_qe, &_plot, &_slope, //88 Dot
  &_absolute, &_pi, &_lastx, //94 CHS
  &_sqr, &_ln, &_log, &_percent, &_percentdelta, //97 SQRT
  &nop, &_hypa, &_asin, &_acos, &_atan, //102 SST
  &_rec, &_pmenug, &_rotup, &nop, &_cla, //107 RS
  &nop, &_fkeyfon, &_fkeyoff, &_int, &nop, //112 ON
};

static void execute(byte cmd){ // Execute command
  if(cmd<MAXCMD) (*dispatch[cmd+isfg*KEYS])();
  if(cmd>_DOT && cmd!=KENTER && cmd!=KBSP) _s(); // New number (except 0-9. and dup)
  if(cmd!=KF && cmd!=KG && cmd!=KGTO && cmd!=KGSB) _f(); // Reset f keys (except f, g, GTO/hyp, GSB/menu)
}

static void _lcd1(void){ // Set LCD brightness (0...64)
  byte b=popr();
  if(b>=0 && b<64){lcd_brightness=b; set_lcd_params();}
}
static void _lcd2(void){ // Set LCD voltage (0...7)
  byte v=popr();
  if(v>=0 && v<=7){lcd_oper_voltage=v; set_lcd_params();}
}

static void _save(void){issave=TRUE;} // Demand save function
static void _load(void){isload=TRUE;} // Demand load function
static void _fsave(byte n){ // Save function
  memcpy(pstore[n],rec,MAXREC);
  if(rec[0]==END){pslotname[n][0]='-'; pslotname[n][1]='\0';}
  else for(byte i=0; i<4 && rec[i]!=END; i++) pslotname[n][i]=keyname[rec[i]];
}
static void _fload(byte n){memcpy(rec,pstore[n],MAXREC);} // Load function

static const void (*pmdispatch[])(void)={ // Plex menu dispatch (offset=4)
  &_pc, &_disp, &_hex, &_quit, &_save, &_load,
  &_lcd1, &_lcd2, &_timeout, &_bat, &nop, &nop,
  &_dtsetd, &_dtsett, &nop, &_dtgetd, &_dtgett, &nop,
};
static void printpmenu(void){ // Print plex menu
  char s[24+1]="QUITSAVELOADCST SIZEHEX ";
  if(ispmenu==2){strcpy (s,"BATT        D1  D2  Toff"); s[12]=s[16]=FSCREEN;}
  else if(ispmenu==3){strcpy(s,"DGetTGet    DSetTSet    "); s[0]=s[12]=FCAL; s[4]=s[16]=FCLOCK;}
  printmenu(s);
}

static void printplex(void){ // Print PLEX
  byte x1=8, x2=59;
if(issave || isload) printslot(); // Save/load menu
else
  if(ispmenu) printpmenu(); // Menu
  else if(isbigdisplay){ // Big
    byte xbig=2*FWW;
    fsize=FSIZEL; fshift=FALSE;
    if(dp){
      long double a=ds[dp-1].r; if(!isrect) a=absolute(a,ds[dp-1].i);
      isprintx=TRUE; printnum(a,xbig,0); isprintx=FALSE;
      if(dnum) cat(FCURR,0,0); // Num input indicator
    }
    else cat('_',xbig,0);
    fsize=FSIZES;
  }
  else if(!dp) cat('_',x1,1);  // Print underscore if stack is empty
  else for(byte i=0; i<2; i++) if(dp>i){ // Stack (up to 2 register)
    fshift=1-i;
    long double a=ds[dp-i-1].r, b=ds[dp-i-1].i, re=a, im=b;
    if(!isrect){a=absolute(re,im); b=angle(re,im);}
    if(!i){isprintx=TRUE;} printnum(a,x1,1-i); isprintx=FALSE; // Re
    if(b!=0.0F) printnum(b,x2,1-i); // Im
    if(dnum && !i){fshift=TRUE; cat(FCURR,0,1);} // Num input indicator
  }
}


//--v----1----v----2----v----3----v----4----v----5----v----6----v----7----v----8
//  R A X C O M M O N

#define TXT 254 // Text cell
#define REF 253 // Reference cell

#define RMEM 10 // Average formula memory per cell (>1)
#define RC 4 // Spreadsheet dimensions
#define RR 8
#define RCELLS (RR*RC) // Max number of cells (<256)
#define RMEMMAX (RR*RC*RMEM) // Max size of rmem
#define DC 2 // Display cell dimensions
#define DR 2
#define MAXTXT 7 // Max chars per text cell

static long double rval[RCELLS]; // Cell values
static byte rmem[RMEMMAX], rbuf[2*MAXGETS]; // Rax memory
static byte rstore[6][RMEMMAX]; // Rax sheet storage (6 slots)
static char rslotname[6][4]={"-","-","-","-","-","-"}; // Save/load slot names
static byte isref=FALSE; // Reference demanded (RCL)

static byte selcell=0, oldselcell=0; // Selected cell

static byte editcurpos=0; // Cursor position in edited cell

static byte n2c(byte n){return(n%RC+1);} // n->row
static byte n2r(byte n){return(n/RC+1);} // n->row

static unsigned int rmseek(byte n){ // Seek start address of n-th cell
  byte cell=0; unsigned int p=0; if(n>RCELLS) n=RCELLS; // Minimum
  while(cell<n) if(rmem[p++]==END) cell++;
  return(p);
}

static void cell2s(char* s, byte n){*s++=n2c(n)+'A'-1; *s=n2r(n)+'0';} // Convert cell number to cell name

static byte mlen(void){return(rmseek(selcell+1)-rmseek(selcell)-1);} // Length of selcell
static void seteditcurpos(void){ // Set editcurpos to end of formula of selcell
  byte delta=mlen()+1;
  editcurpos=(delta ? delta-1:0);
}

static byte createeditstring(char* s, byte iscursor){ // Create editable string
  byte cmd, pos=0, txtpos=0, curtxtpos=0;
  unsigned int raxp=rmseek(selcell);
  while((cmd=rmem[raxp+pos])!=END){ // Create string
    if(cmd==REF){ // Reference
      if(txtpos<2*MAXGETS-2){ // End of string
        cell2s(s+txtpos, rmem[raxp+pos+1]); txtpos+=2;
        if(iscursor && editcurpos && pos==editcurpos-2) strcharat(s, FBLACK, txtpos++); // Cursor
        pos+=2;
      }
    }
    else{ // Insert command
      if(txtpos<2*MAXGETS-1){ // End of string
        s[txtpos++]=keyname[cmd];
        if(iscursor && editcurpos && pos==editcurpos-1){
          curtxtpos=txtpos;
          strcharat(s, FBLACK, txtpos++);
        } // Cursor
        pos++;
      }
    }
  }
  return(curtxtpos);
}

static void memcmdat(byte n, byte c, byte pos){ // Insert comand c to rmem to cell n at pos
  unsigned int eomem=rmseek(RCELLS);
  if(eomem<RMEMMAX){ // Space left
    unsigned int raxp=rmseek(n)+pos; memmove(rmem+raxp+1, rmem+raxp, eomem-raxp); // Space left
    rmem[raxp]=c; // Insert command
  }
}
static void memdelat(byte n, byte pos){ // Delete mem at pos
  unsigned int raxp=rmseek(n)+pos;
  memcpy(rmem+raxp,rmem+raxp+1,rmseek(RCELLS)-raxp);
}

static byte iscelltxt(byte n){ // Check if cell is text
  if(rmem[rmseek(n)]==TXT) return(TRUE);
  return(FALSE);
}
static byte iscellempty(byte n){ // Check if cell is empty
  if(rmem[rmseek(n)]==END) return(TRUE);
  return(FALSE);
}

static byte isforbidden(byte cmd){ // True, if cmd is forbidden (leads to crash)
  const byte blacklist[]={
    KMUL+KEYS, KMUL+2*KEYS, // integral, plot
    KDIV+KEYS, KDIV+2*KEYS, // solve, slope
    KRS, KRS+2*KEYS // play, p/r
  };
  for(byte i=0;i<sizeof(blacklist);i++) if(blacklist[i]==cmd) return(TRUE);
  return(FALSE);
}

static long double eval(byte n){ // Eval mem of cell n
  long double oldval=rval[n]; // To calculate squared error
  unsigned int raxp=rmseek(n);
  byte cmd;
  _s(); _cla(); // Reset stack
  while((cmd=rmem[raxp++])!=END){ // Execute commands
    if(cmd==REF){ // Reference
      byte addr=rmem[raxp++];
      pushrefstack(addr); pushr(rval[addr]);
    }
    else if(!isforbidden(cmd+isfg*KEYS)) execute(cmd);
  }
  rval[n]=popr(); // Assign val to cell
  long double d=rval[n]-oldval; return(d*d); // To calculate SSE in evalall()
}
static void evalall(void){ // Eval all cells
  //for(byte i=0; i<RCELLS; i++) eval(i); // One time calculation
  //for(byte j=0; j<RCELLS; j++) for(byte i=0; i<RCELLS; i++) eval(i); // n² times
//  byte frequ[RCELLS]={0};
//  for(unsigned int i=0; i<rmseek(RCELLS); i++) if(rmem[i]==_REF) frequ[rmem[i+1]]++; // Count frequency of REFs
//  byte maxf=0; // Evaluate frequency maximum
//  for(byte i=0; i<RCELLS; i++) if(frequ[i]>maxf) maxf=frequ[i];
//  for(byte f=maxf+1; f>0; f--) for(byte i=0; i<RCELLS; i++) if(frequ[i]==f-1) eval(i); // Eval frequ cells first
  for(byte j=0;j<RCELLS;j++){ // Eval n² times with SSE break - Outer loop
    long double sse=0.0F; // Sum of squares error (SSE)
    for(byte i=0;i<RCELLS;i++) if(!iscelltxt(i)) sse+=eval(i); // Eval and SSE (not for text cell)
    if(sse<DELTAX) break; // Break outer loop if SSE is low
  }
}


//--v----1----v----2----v----3----v----4----v----5----v----6----v----7----v----8
//  R A X E D I T   -  Edit RAX Cell

static byte israxedit=FALSE;

static void printraxedit(void){ // Print edit screen
  fshift=FALSE;
  char s[2*MAXGETS+1]={0};
  byte curpos=createeditstring(s,TRUE);
  byte len=strlen(s);
  if(!len) cat(FBLACK,X1,0); // Empty cell
  else{
    byte d=MAXGETS-2; // Distance
    if(curpos>d) for(byte i=curpos-d; i<=curpos; i++) cat(s[i],X1+(i-(curpos-d))*FWW,0);
    else for(byte i=0; i<=d && s[i]; i++) cat(s[i],X1+i*FWW,0);
  }
  fshift=TRUE; printnum(rval[selcell],X1,1); // Print value
}


//--v----1----v----2----v----3----v----4----v----5----v----6----v----7----v----8
//  R A X   -  Spreadsheet

static byte israx=FALSE, isrmenu=FALSE;

static byte shiftleft=0, shiftup=0, oldshiftleft=0, oldshiftup=0; // View shift, save for reference

static void rquit(void){isbigdisplay=isbigdtmp; israx=FALSE;} // Quit

static void delcell(byte n){ // Delete cell
  rval[n]=0.0F;
  unsigned int raxp=rmseek(n), rpnext=rmseek(n+1);
  if(rmem[raxp]!=END) memcpy(rmem+raxp,rmem+rpnext-1,rmseek(RCELLS)-rpnext+1);
}
static void rnew(void){ // New sheet
  memset(rmem,END,RMEMMAX);
  for(byte i=0;i<RCELLS;i++) rval[i]=0.0F;
  selcell=0; shiftleft=shiftup=FALSE;
}
static void rcopy(void){ // Select copycell
  unsigned int p=rmseek(selcell);
  byte cmd, pos=0;
  while((cmd=rmem[p+pos])!=END && pos<2*MAXGETS) rbuf[pos++]=cmd;
  rbuf[pos]=END;
}
static void rpaste(void){ // Paste copied cell
  if(!iscellempty(selcell)) delcell(selcell);
  byte cmd, pos=0;
  while((cmd=rbuf[pos])!=END && pos<2*MAXGETS) memcmdat(selcell, cmd, pos++);
  evalall();
}

static void rsave(byte n){ // Save rmem to slot n
  memcpy(rstore[n],rmem,RMEMMAX);
  if(iscellempty(RCELLS-1)){rslotname[n][0]='-'; rslotname[n][1]='\0';}
  else{
    unsigned int p=rmseek(RCELLS-1);
    for(byte i=0; i<4 && rmem[p+1+i]!=END; i++) rslotname[n][i]=rmem[p+1+i];
  }
}
static void rload(byte n){memcpy(rmem,rstore[n],RMEMMAX);} // Load rmem from slot n

static const void (*prdispatch[])(void)={ // Rax menu dispatch (offset=4)
  &rcopy, &rpaste, &_hex, &rquit, &rnew, &nop,
};
static void printrmenu(void){printmenu("QUITNEW     COPYGLUEHEX ");} // Print rax menu

static void rup(void){shiftup=0; if(selcell>=RC) selcell-=RC; else selcell=0;} // Up
static void rdown(void){shiftup=1; if(selcell<RCELLS-RC) selcell+=RC;} // Down
static void rleft(void){ // Left
  if(selcell) selcell--;
  shiftleft=0; if(n2c(selcell)==RC) shiftleft=1;
}
static void rright(void){ // Right
  if(selcell<RCELLS-1) selcell++;
  shiftleft=1; if(n2c(selcell)==1) shiftleft=0;
}

static void raxcontent(char* s){ // Write content of cell short to string
  if(iscelltxt(selcell)){ // Text
    unsigned int p=rmseek(selcell);
    for(byte i=0; i<4 && rmem[p+1+i]!=END; i++) s[i]=rmem[p+1+i];
  }
  else{ // Formula
    char st[2*MAXGETS+1]={0}; createeditstring(st,FALSE);
    for(byte i=0; i<4 && st[i]; i++) s[i]=st[i];
  }
}

static void printcell(byte c, byte x, byte y){ // Print cell (incl. marker matrix)
  if(iscelltxt(c)){ // Text
    unsigned int p=rmseek(c);
    for(byte i=0; i<MAXTXT && rmem[p+1+i]!=END; i++) cat(rmem[p+1+i],x+i*FWW,y);
  }
  else{ // Value
    long double a=rval[c];
    if(a==0.0F) cat(F3DOT,x,y); else printnum(a,x,y);
  }
  if(c==selcell) cat(FCURR,x-FWW,y); // Cursor
}

static void printsheet(void){ // Print sheet
  static byte x1=FWW, x2=53+FWW;
  byte c=selcell; if(shiftup && c>=RC){c-=RC;} if(shiftleft && c){c--;} // Active cell
  fshift=FALSE;
  printcell(c,x1,0); c++; printcell(c,x2,0); // 1st and 2nd cell
  fshift=TRUE;
  c+=(RC-1); printcell(c,x1,1); c++; printcell(c,x2,1); // 3th and 4th cell
}
static void printrax(void){ // Print RAX screen
  if(isrmenu) printrmenu(); // Menu
  else if(issave || isload) printslot(); // Save/load menu
  else printsheet(); // Print rax
}


//--v----1----v----2----v----3----v----4----v----5----v----6----v----7----v----8
//  F L E X - The symbolic calculator

static byte isflex=FALSE, isfnum=FALSE;

static void fquit(void){isbigdisplay=isbigdtmp; isflex=FALSE;} // Quit

static void fptrswap(unsigned int p1, unsigned int p2, unsigned int pe){ // SWAP rmem at pointers
  memmove(rmem+p2-p1,rmem,pe); // Make space for Y
  memcpy(rmem,rmem+p2,p2-p1); // Copy Y to free space
  memcpy(rmem+p2,rmem+p2+p2-p1,pe-(p2-p1)-p1-(p2-p1)); // Delete former Y
}
static void fconnect(void){ // Connect Y and X with key
  unsigned int rp1=rmseek(1), rp2=rmseek(2), rpe=rmseek(RCELLS);
  fptrswap(rp1,rp2,rpe);
  memcpy(rmem+rp2-rp1-1,rmem+rp2-rp1,rpe-(rp2-rp1)); // Connect
  memmove(rmem+rp2-1,rmem+rp2-2,rpe-(rp2-2)); // Make space for key
  rmem[rp2-2]=key; // Insert key at end of formula
  isfnum=FALSE;
}
static void fins(byte n){ // Insert n at end of X
  unsigned int rp=rmseek(1);
  memmove(rmem+rp,rmem+rp-1,rmseek(RCELLS)-(rp-1)); // Make space for key
  rmem[rp-1]=n; // Insert key at end of formula
  isfnum=FALSE;
}
static void fnuminput(void){ // Add number
  if(isfnum){
    unsigned int rp=rmseek(1);
    memmove(rmem+rp,rmem+rp-1,rmseek(RCELLS)-(rp-1)); // Make space for key
    rmem[rp-1]=key; // Insert key at end of formula
  }
  else{ // Enter value in new cell
    memmove(rmem+2,rmem,rmseek(RCELLS)); // Make 2 spaces for key and _END
    rmem[0]=key; rmem[1]=END; // Insert key and _END
    isfnum=TRUE;
  }
}
static void fbsp(void){ // BSP
  if(isfnum){ // Clear entry
    unsigned int rp=rmseek(1), rpe=rmseek(RCELLS);
    if(rp>=2) memcpy(rmem+rp-2,rmem+rp-1,rpe-(rp-2));
    else{
      memcpy(rmem+rp-1,rmem+rp,rpe-(rp-1));
      isfnum=FALSE;
    }
  }
  else{ // CLX
    unsigned int rp=rmseek(1);
    memcpy(rmem,rmem+rp,rmseek(RCELLS)-rp);
  }
}

static void fenter(void){ // ENTER
  if(isfnum) fins(KENTER); // Insert enter command
  else memmove(rmem+rmseek(1),rmem,rmseek(RCELLS)); // Duplicate X
}

static void flink(void){fconnect();} // Connect stack entries (with flexkey)

static void printflex(void){ // Print FLEX
  fshift=FALSE;
  char s[2*MAXGETS+1]={0};
  createeditstring(s,FALSE); s[17]='\0';
  if(!*s) cat('_',X1,0); // Empty cell
  else sat(s,X1,0); // Print edit string
  fshift=TRUE; printnum(rval[selcell],X1,1); // Print value
}


//--v----1----v----2----v----3----v----4----v----5----v----6----v----7----v----8
//  T T  -  Tabletop Calculator

static byte istt=FALSE, isttdec=TRUE, isttmenu=FALSE, isttdot=FALSE;

#define MAXTTKEYS 18 // Maximal number of dispatchable keys
#define MAXTTDIG 19 // Maximal digits of tt string

#define TTSTACKSIZE 4
static long long tts[TTSTACKSIZE], ttsto=0LL;
static byte ttp=0;
static byte ttnum=FALSE, ttlift=FALSE; // Stack operation variables

static void ttpush(long long n){ // Push number to data stack
  if(ttp>=TTSTACKSIZE){ // Float stack if full
    memmove(tts,tts+1,(TTSTACKSIZE-1)*sizeof(long long));
    ttp--;
  }
  tts[ttp++]=n;
}
static long long ttpop(void){ // Pop value from data stack
  if(ttp) return(tts[--ttp]);
  return(0LL);
}

static long long p16(sbyte e){ // Returns 16 raised to the power of e
  long long n=1LL;
  if(e<0) e=-e;
  while(e--) n*=16LL;
  return(n);
}

static void _t(void){ttnum=ttlift=isttdot=FALSE;} // Clear stack behavior

static void ttnuminput(byte n){ // Manage number (and dot) input
  if(isttdot){
    if(ttnum){
      long long a=ttpop();
      byte one=a%10LL; a/=100LL;
      ttpush((a*10LL+one)*10LL+n);
    }
  }
  else{ // Numeral
    if(!ttnum){ // Push new numeral
      if(ttlift) ttpop();
      if(isttdec) ttpush(n*100LL); else ttpush(n);
      ttnum=ttlift=TRUE;
    }
    else{ // Append numeral
      if(isttdec) ttpush((ttpop()/10LL+n)*100LL);
      else ttpush((ttpop()*(ishex?16LL:10LL)+n));
    }
  }
}

static void tt0(void){ttnuminput(0);} // 0
static void tt1(void){ttnuminput(isAF?10:1); isAF=FALSE;} // 1a
static void tt2(void){ttnuminput(isAF?11:2); isAF=FALSE;} // 2b
static void tt3(void){ttnuminput(isAF?12:3); isAF=FALSE;} // 3c
static void tt4(void){ttnuminput(isAF?13:4); isAF=FALSE;} // 4d
static void tt5(void){ttnuminput(isAF?14:5); isAF=FALSE;} // 5e
static void tt6(void){ttnuminput(isAF?15:6); isAF=FALSE;} // 6f
static void tt7(void){ttnuminput(7);} // 7
static void tt8(void){ttnuminput(8);} // 8
static void tt9(void){ttnuminput(9);} // 9
static void ttdot(void){ // DOT or hex input demand
  if(ishex) isAF=TRUE;
  else{
    if(!ttnum){ // New numeral
      if(ttlift) ttpop();
      ttpush(0LL); ttnum=ttlift=TRUE;
    }
    isttdot=TRUE;
  }
}

static void ttadd(void){ttpush(ttpop()+ttpop());} // ADD +
static void ttchs(void){ttpush(-ttpop());} // CHS
static void ttclx(void){ // CLX
  if(ttnum){ // Clear last entry
    if(isttdec){
      long long a=ttpop();
      byte dec=a%100LL;
      a/=1000LL;
      if(!a) _t(); else ttpush(a*100LL+dec);
    }
    else{
      long long a=ttpop()/(ishex?16LL:10LL);
      if(!a) _t(); else ttpush(a);
    }
  }
  else ttpop();
}
static void ttdec(void){isttdec=!isttdec; ishex=FALSE;} // Toggle decimal view
static void ttdiv(void){ // DIV /
  long long a=ttpop(), b=ttpop();
  if(isttdec) ttpush(b*100LL/a); else ttpush(b/a);
}
static void ttdup(void){ // DUP
  if(ttp) ttpush(tts[ttp-1]);
  ttnum=isttdot=FALSE; // islift remains
}
static void ttee(void){ // EE
  if(ishex){ttpush(p16(ttpop())); ttmult();}
  else if(isttdec){ttpush(p10(ttpop()/100LL)*100LL); ttmult();}
  else{ttpush(p10(ttpop())); ttmult();}
}
static void tthex(void){ // Hex mode
  if(ishex){ishex=FALSE;}
  else{ishex=TRUE; isttdec=FALSE;}
}
static void ttmult(void){ // MULT *
  if(isttdec) ttpush(ttpop()*ttpop()/100LL);
  else ttpush(ttpop()*ttpop());
}

static void ttnand(void){ // NAND
  ttpush(~(ttpop() & ttpop()));
}

static void ttpercent(void){ // % = B*x/100% (keep B)
  ttswap(); ttdup(); ttrot(); ttmult();
  ttpush(isttdec?10000LL:100LL); ttdiv();
}
static void ttquit(void){istt=FALSE;} // Quit
static void ttrot(void){ // ROT
  if(ttp>2){
    long long a=ttpop(), b=ttpop(), c=ttpop();
    ttpush(a); ttpush(c); ttpush(b);
  }
}
static void ttsqrt(void){ttpush(sqrt(ttpop())*(isttdec?10.0F:1.0F));} // SQRT
static void ttstorcl(void){ttpush(ttsto);} // RCL
static void ttstosto(void){ttpush(ttsto=ttpop());} // STO
static void ttsub(void){ttchs(); ttadd();} // SUB -
static void ttswap(void){if(ttp>1){long long  a=ttpop(), b=ttpop(); ttpush(a); ttpush(b);}} // SWAP


static const void (*ttdispatch[])(void)={ // Function array
  &tt0, &tt1, &tt2, &tt3, &tt4, &tt5, &tt6, &tt7, &tt8, &tt9, //0 Main keys
  &ttdot, &ttnand, &ttadd, &ttsub, &ttmult, &ttdiv, //10 Dot
  &ttchs, &ttee, &ttdup, //16 CHS
};

static const void (*ttmdispatch[])(void)={ // TTOP menu dispatch (offset=4)
  &ttdec, &nop, &tthex, &ttquit, &nop, &nop,
};
static void printttmenu(void){printmenu("QUIT        -.-     HEX ");} // Print TTOP menu

static void sattt(char* s, byte x, byte row){ // Print string at x|row with smaller spaces
  slead(s); // Delete trailing spaces
  while(*s){cat(*s,x,row); x+=FWW; if(*s++==' ') x-=3;}
}

static void tt2s(char* str, long long n){ // Convert tt number to string
  char* s=str+MAXTTDIG; // String pointer (right aligned)
  byte isneg=FALSE; if(n<0LL){isneg=TRUE; n=-n;} // Negative number
  if(n==0LL){ // Zero
    if(isttdec && !ishex) *--s='.';
    *--s='0';
  }
  else if(ishex){ // Hex number
    byte k=0; // Counter for separators
    while(n && s>&str[1]){ // Limit length to (MAXTTDIG-1)
      if(!(k++%4)) *--s=' '; // Separator
      char c=n%16LL+'0'; if(c>'9') c+=('a'-'9'-1); // Mantissa
      *--s=c; n/=16LL;
    }
  }
  else if(isttdec){
    for(byte i=0;i<2;i++){*--s=(n%10LL)+'0'; n/=10LL;} // Decimals
    *--s='.'; // Dot
    byte k=1; // Counter for separators
    while(n && s>&str[1]){ // Limit length to (MAXTTDIG-1)
      if(*s!='.' && !(k++%3)) *--s=' '; // Separator
      *--s=(n%10LL)+'0'; n/=10LL; // Mantissa
    }
  }
  else{
    byte k=0; // Counter for separators
    while(n && s>str){ // Limit length to MAXTTDIG
      if(!(k++%3)) *--s=' '; // Separator
      *--s=(n%10LL)+'0'; n/=10LL; // Mantissa
    }
  }
  //if(isneg) *--s='-'; // Negative number
  //if(n) strcpy(str,"---"); // Overflow
  if(isneg){
    if(s<=str+1) strcpy(str,"---"); // Overflow - no space for '-'
    *--s='-'; // Negative number
  }
  if(n) strcpy(str,"---"); // Overflow
}

static void printtt(void){
  if(isttmenu) printttmenu(); // Menu
  else{
    char s[MAXTTDIG+1];
    if(!ttp){strfill(s,' ',MAXTTDIG); s[0]='_'; sat(s,X1,1);} // Empty stack
    else for(byte i=0;i<2;i++) if(ttp>i){ // Stack (up to 2 register)
      fshift=1-i;
      strfill(s,' ',MAXTTDIG); tt2s(s,tts[ttp-i-1]); sattt(s,FWW,1-i); // Print
      if(ttnum && !i) cat(FCURR,0,1); // Num input indicator
    }
  }
}


//--v----1----v----2----v----3----v----4----v----5----v----6----v----7----v----8
//  R U L E  -  Slide Rule

static byte isrule=FALSE;

static void ruleinit(void){
  byte const rulebuf[SBYTES]={
  0b11110111, 0b11100000, 0b11000000, 0b10000000, 0b00000000, //0
  0b00000011, 0b00000000, 0b00000000, 0b00000000, 0b00000000, //5
  0b00000011, 0b00000000, 0b00000000, 0b00000000, 0b00000000, //10
  0b00000011, 0b00000000, 0b00000000, 0b00000000, 0b00000011, //15
  0b00000000, 0b00000000, 0b00000000, 0b00001111, 0b00000000, //20
  0b00000000, 0b00000000, 0b00000011, 0b00000000, 0b00000000, //25
  0b00000000, 0b00000011, 0b00000000, 0b00000000, 0b00000011, //30
  0b00000000, 0b00000000, 0b00000011, 0b00000000, 0b10111000, //35
  0b10101011, 0b11101000, 0b00000000, 0b00000011, 0b00000000, //40
  0b00000000, 0b00000011, 0b00000000, 0b00000000, 0b00000011, //45
  0b00000000, 0b00000011, 0b00000000, 0b00001111, 0b00000000, //50
  0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, //55
  0b00000000, 0b00000000, 0b10001000, 0b10101011, 0b11111000, //60
  0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, //65
  0b00000000, 0b00000000, 0b00001111, 0b00000000, 0b00000000, //70
  0b00000000, 0b00000000, 0b00000000, 0b11100000, 0b00100011, //75
  0b11111000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, //80
  0b00000000, 0b00001111, 0b00000000, 0b00000000, 0b00000000, //85
  0b00000000, 0b11101000, 0b10101011, 0b10111000, 0b00000000, //90
  0b00000000, 0b00000000, 0b00000000, 0b00001111, 0b00000000, //95
  0b00000000, 0b00000000, 0b11111000, 0b10101011, 0b00111000, //100
  0b00000000, 0b00000000, 0b00000000, 0b00001111, 0b00000000, //105
  0b00000000, 0b11000000, 0b10000011, 0b11111000, 0b00000000, //110
  0b00000000, 0b00000000, 0b00000000, 0b11111000, 0b10101011, //115
  0b11111000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, //120
  0b11100000, 0b10101011, 0b11111000, 0b00000000, 0b10000000, //125
  0b11000000, 0b11100000, 0b11101111, 0b00000111, 0b00000011, //130
  0b00000001, 0b00000000, 0b11000000, 0b00000000, 0b00000000, //135
  0b00000000, 0b00000000, 0b11000000, 0b00000000, 0b00000000, //140
  0b00000000, 0b00000000, 0b11000000, 0b00000000, 0b00000000, //145
  0b00000000, 0b11000000, 0b00000000, 0b00000000, 0b00000000, //150
  0b11110000, 0b00000000, 0b00000000, 0b00000000, 0b11000000, //155
  0b00000000, 0b00000000, 0b00000000, 0b11000000, 0b00000000, //160
  0b00000000, 0b11000000, 0b00000000, 0b00000000, 0b11000000, //165
  0b00000000, 0b00010111, 0b11010101, 0b00011101, 0b00000000, //170
  0b11000000, 0b00000000, 0b00000000, 0b11000000, 0b00000000, //175
  0b00000000, 0b11000000, 0b00000000, 0b11000000, 0b00000000, //180
  0b11110000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, //185
  0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00010101, //190
  0b11010101, 0b00011111, 0b00000000, 0b00000000, 0b00000000, //195
  0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b11110000, //200
  0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, //205
  0b00011100, 0b11000100, 0b00011111, 0b00000000, 0b00000000, //210
  0b00000000, 0b00000000, 0b00000000, 0b11110000, 0b00000000, //215
  0b00000000, 0b00000000, 0b00000000, 0b00011101, 0b11010101, //220
  0b00010111, 0b00000000, 0b00000000, 0b00000000, 0b00000000, //225
  0b11110000, 0b00000000, 0b00000000, 0b00000000, 0b00011111, //230
  0b11010101, 0b00000111, 0b00000000, 0b00000000, 0b00000000, //235
  0b11110000, 0b00000000, 0b00000000, 0b00011000, 0b11010000, //240
  0b00011111, 0b00000000, 0b00000000, 0b00000000, 0b00000000, //245
  0b00011111, 0b11010101, 0b00011111, 0b00000000, 0b00000000, //250
  0b00000000, 0b00000000, 0b00011100, 0b11010101, 0b00011111, //255
  0b00000000, 0b00000001, 0b00000011, 0b00000111, //260
  };
  memcpy(sbuf,rulebuf,SBYTES);
}

static void ruleleft(byte n){ // Rule n left
  for(byte i=0;i<n;i++){
    byte tmp=sbuf[0]; memcpy(sbuf,&sbuf[1],SX-1); sbuf[SX-1]=tmp;
  }
}
static void ruleright(byte n){ // Rule n right
  for(byte i=0;i<n;i++){
    byte tmp=sbuf[SX-1]; memmove(&sbuf[1],sbuf,SX-1); sbuf[0]=tmp;
  }
}


//--v----1----v----2----v----3----v----4----v----5----v----6----v----7----v----8
//  T E X - Text Editor

static byte istex=FALSE, istexup=FALSE, islinesplit=FALSE; // Indicate line split

#define MAXTEX 255 // Maximal length of edited text
#define LF 0x0a // Line feed

static char tex[MAXTEX+1]={LF,[1 ... MAXTEX]='\0'}; // Tex buffer
static byte texline=0;
static byte tstore[6][MAXTEX+1]; // Tex storage (6 slots)
static char tslotname[6][4]={"-","-","-","-","-","-"}; // Save/load slot names

static byte texseek(byte n){ // Seek start address of n-th line
  byte line=0, p=0;
  while(line<n && tex[p] && p<MAXTEX) if(tex[p++]==LF) line++;
  return(p);
}
static byte texsize(void){ // Tex size (first NUL)
  byte i=0;
  while(tex[i] && i<MAXTEX) i++;
  return(i+1); // +1 to include /0
}
static byte texlines(void){ // Seek last line
  byte line=0, p=0; // Minimum
  while(tex[p]!='\0' && p<MAXTEX) if(tex[p++]==LF) line++;
  return(line);
}

static void texstartedit(void){ // Edit selected line
  byte p1=texseek(texline), p2=texseek(texline+1);
  if(p2==0){tex[0]=LF; tex[1]=gots[0]='\0';} // Empty file
  else{memcpy(gots,&tex[p1],p2-p1-1); gots[p2-p1-1]='\0';}
  getscurpos=strlen(gots);
  isgets=TRUE;
}

static void texendedit(void){ // Insert edited line to tex
  byte p1=texseek(texline), p2=texseek(texline+1), len=strlen(gots);
  memmove(&tex[p1+len],&tex[p2-1],texsize()-p2+1);
  memcpy(&tex[p1],gots,len);
  if(islinesplit){
    memmove(&tex[p1+getscurpos+1],&tex[p1+getscurpos],texsize()-p1+getscurpos);
    tex[p1+getscurpos]=LF;
    islinesplit=FALSE;
  }
}

static void linedelete(void){ // Delete recent line
  byte p1=texseek(texline), p2=texseek(texline+1);
  memcpy(&tex[p1],&tex[p2],texsize()-p2);
}
static void linejoin(void){ // Join recent line with next
  byte p2=texseek(texline+1);
  if(tex[p2]!='\0') memcpy(&tex[p2-1],&tex[p2],texsize()-p2); // If there is a next line
}
static void linenew(void){ // Add new line before recent line
  byte p1=texseek(texline);
  memmove(&tex[p1+1],&tex[p1],texsize()-p1);
  tex[p1]=LF;
}

static void tsave(byte n){ // Save tex to slot n
  memcpy(tstore[n],tex,MAXTEX+1);
  for(byte i=0; i<4; i++){tslotname[n][i]=' '; if(tex[i]!=LF) tslotname[n][i]=tex[i];}
}
static void tload(byte n){memcpy(tex,tstore[n],MAXTEX+1);} // Load tex from slot n

static void printtex(void){ // Print TEX
  if(issave || isload) printslot(); // Save/load menu
  else{ // Display 2 lines
    char s[MAXGETS+1];
    for(byte i=0; i<2 && texline+i<texlines(); i++){
      fshift=i;
      byte p1=texseek(texline+i), p2=texseek(texline+i+1);
      memcpy(s,&tex[p1],p2-p1-1); s[p2-p1-1]='\0';
      sat(s,X1,i);
    }
  }
}


//--v----1----v----2----v----3----v----4----v----5----v----6----v----7----v----8
//  D E S K  -  Desk

static byte isdesk=FALSE; // For printing and correct status

static void printdesk(void){ // Print DESK screen
  printmenu("PLEXFLEXRAX TTOPRULETEX ");
}


//--v----1----v----2----v----3----v----4----v----5----v----6----v----7----v----8
//  P R I N T I N G ,   S E T U P ,   M A I N

static void printslot(void){ // Print slots
  char s[24+1]; strfill(s,' ',24);
  const byte order[6]={3,4,5,0,1,2};
  if(isplex) for(byte i=0; i<6; i++) strstrat(s,pslotname[order[i]],i*4);
  else if(israx) for(byte i=0; i<6; i++) strstrat(s,rslotname[order[i]],i*4);
  else if(istex) for(byte i=0; i<6; i++) strstrat(s,tslotname[order[i]],i*4);
  printmenu(s);
}


static void printstatus(void){ // Print stati
  char s[4+1]; strfill(s,' ',4);
  byte n=0,h=0,m=0; // Local date variables
  if(isdesk){dt_t d; tm_t t; getdate(&d,&t); n=d.day; h=t.hour; m=t.min;} // Get date and time

  fshift=FALSE; // 1st line
  s[3]=FBAT0-batt()/2; // Battery
  if(isdesk) i2s20(s,n); // Date
  else{
    if(ishex) s[2]=FHEX; // HEX
    if(isref) s[2]=FLINK; // Reference
    if(isplex) s[1]=(isrect?FANGLE:FANGLE45); // Rect or polar display
    if(isfg) s[0]='f'+isfg-1; // f/g key
    if(ishyp) s[0]='H'; else if(ishypa) s[0]='h'; // HYP
    if(isrec && recp<MAXREC) s[0]=FCIRCLEF; // REC
    if((israx || israxedit) && !isflex){cell2s(s, selcell);} // Cell name
  }
  sat(s,XS,0);

  fshift=TRUE; // 2nd line
  if(isdesk){i2s20(s,h); i2s2(s+2,m);} // Clock
  else{
    strfill(s,' ',4);
    if(israx) raxcontent(s);
    if(israxedit || isgets) strcpy(s,"EDIT");
    if(istex) i2s20(s+2,texline+1); // TEXline
    if(isplex && rec[0]!=END) s[2]=FSQUAREF; // f(x)
    if(((isplex || isflex) && (store.r!=0.0F||store.i!=0.0F)) || (istt && ttsto!=0LL)) s[3]=FDISK; // STO
    if(isplay || issolve || isslope || isint || isplotcalc) s[3]=FSAND; // Running symbol
    if(istt && isttdec) s[3]='.'; // Decimal TTOP mode
    if(isAF) s[3]=FARRU; // HEX input demanded
    if(issave) strcpy(s,"SAVE"); else if(isload) strcpy(s,"LOAD"); // Save/Load
  }
  sat(s,XS,1);
}

static byte printscreen(void){ // Print screen
  if(!isrule){ // If isrule: Leave sbuf as it was
    memset(sbuf,0x00,SBYTES); // Clear screen buffer
    isdesk=FALSE;
    if(isgets) printgets();
    else if(ispc) printpc();
    else if(isplot) printplot();
    else if(isplex) printplex();
    else if(israxedit) printraxedit();
    else if(israx) printrax();
    else if(isflex) printflex();
    else if(istt) printtt();
    else if(istex) printtex();
    else{printdesk(); isdesk=TRUE;} // isdesk needed for printstatus

    if(!isplot) printstatus();
  }
  sbuf2lcd(); // Print screenbuffer
  return(FALSE);
}

// KEY PROCEDURES

static void kdesk(void){ // DESK
  if(key==K7) isplex=TRUE;
  else if(key==K8){isbigdtmp=isbigdisplay; isbigdisplay=FALSE; isflex=TRUE; selcell=0;}
  else if(key==K9){isbigdtmp=isbigdisplay; isbigdisplay=FALSE; israx=TRUE;}
  else if(key==K4) istt=TRUE;
  else if(key==K5){isrule=TRUE; ruleinit();}
  else if(key==K6) istex=TRUE;
}

static void kpc(void){ // Physical const
  if(key==KGSB) ispc=FALSE; // Quit
  else if(key==KENTER){pushr(pc[pcnr]); ispc=FALSE;} // Exit
  else if(key==K8){if(pcnr) pcnr--;} // Up
  else if(key==K2){if(pcnr<(sizeofpc()-1)) pcnr++;} // Down
  else if(key==K9){if(pcnr>4) pcnr-=5; else pcnr=0;} // Pgup
  else if(key==K3){if(pcnr<(sizeofpc()-5)) pcnr+=5; else pcnr=sizeofpc()-1;} // Pgdown
}

static void kgets(void){ // Get string
  if(key==KRS || key==KENTER){ // Quit
    if(israx){ // Write gots to rmem
      unsigned int p=rmseek(selcell);
      delcell(selcell);
      memmove(rmem+p+strlen(gots), rmem+p-1, rmseek(RCELLS)-p);
      rmem[p]=TXT;
      for(byte i=0; i<MAXTXT && i<strlen(gots); i++) rmem[p+1+i]=gots[i];
    }
    else if(istex) texendedit(); // Write gots to tex
    isgets=FALSE;
  }
  else if(key==K1) asccol=ASCCOLS-1; // End
  else if(key==K2){if(ascrow<sizeof(font)/FW/ASCCOLS-1) ascrow++;} // Down
  else if(key==K4){if(asccol) asccol--;} // Left
  else if(key==K5) asccol=ASCCOLS/2; // Center
  else if(key==K6){if(asccol<ASCCOLS-1) asccol++;} // Right
  else if(key==K7) asccol=0; // Pos1
  else if(key==K8){if(ascrow) ascrow--;} // Up
  else if(key==KSST){if(getscurpos) getscurpos--;} // Cursor left
  else if(key==KGTO){if(getscurpos<strlen(gots)) getscurpos++;} // Cursor right
  else if(key==KBSP){if(getscurpos){strdelat(gots,getscurpos-1); getscurpos--;}} // Backspace
  else if(strlen(gots)<(israx?MAXTXT:MAXGETS)) // Insert selected character by any other key
    strcharat(gots,ascrow*ASCCOLS+asccol+' ',getscurpos++);
}

static void kplot(void){isplot=FALSE;} // PLOT

static void kplex(void){ // PLEX
  if(ispmenu && key>=4 && key<=9){ // Dispatch menu
    (*pmdispatch[(key-4)+(ispmenu-1)*6])();
    ispmenu=0;
  }
  else if(issave){ // Save
    if(key>=4 && key<=9) _fsave(key-4);
    issave=FALSE;
  }
  else if(isload){ // Load
    if(key>=4 && key<=9) _fload(key-4);
    evalall();
    isload=FALSE;
  }
  else execute(key); // Dispatch key
}

static void kraxedit(void){ // RAX edit cell
  if(key==KRS || key==KGSB || key==KENTER){israxedit=FALSE; evalall();} // Quit raxedit
  else if(key==KSST){ // Edit cursor left
    if(editcurpos==2 && rmem[rmseek(selcell)+editcurpos-2]==REF){}
    else if(editcurpos>1 && rmem[rmseek(selcell)+editcurpos-2]==REF) editcurpos-=2;
    else if(editcurpos>1) editcurpos--;
  }
  else if(key==KGTO && !isfg){ // Edit cursor right
    if(rmem[rmseek(selcell)+editcurpos]==REF) editcurpos+=2;
    else if(editcurpos<mlen()) editcurpos++;
  }
  else if(key==KBSP){ // BSP
    if(editcurpos){
      if(editcurpos>1 && rmem[rmseek(selcell)+editcurpos-2]==REF){
        memdelat(selcell,editcurpos-1); memdelat(selcell,editcurpos-2);
        editcurpos--;
      }
      else memdelat(selcell,editcurpos-1);
      editcurpos--;
      if(!editcurpos){ // Prevent curpos 0
        if(rmem[rmseek(selcell)]!=END){
          editcurpos++; if(rmem[rmseek(selcell)]==REF) editcurpos++;
        }
      }
    }
  }
  else if(key==KSUM) memcmdat(selcell, KENTER, editcurpos++); // Pipe SUM key to ENTER
  else if(key==KRCL){ // Reference demanded
    oldselcell=selcell; oldshiftleft=shiftleft; oldshiftup=shiftup; // Rescue position
    isref=TRUE; israxedit=FALSE;
  }
  else memcmdat(selcell, key, editcurpos++); // Store command
  eval(selcell); eval(selcell); // 2x workaround for f/g-key
}

static void entertxtcell(byte isnew){ // Enter text cell
  getscurpos=0; gots[0]='\0'; // New text cell
  if(!isnew){ // Text cell exists
    unsigned int p=rmseek(selcell);
    for(byte i=0; i<MAXTXT && rmem[p+1+i]!=END; i++) strcat(gots, c2s(rmem[p+1+i]));
    getscurpos=strlen(gots);
  }
  isgets=TRUE;
}
static void krax(void){ // RAX
  if(isrmenu){
    if(key>=4 && key<=9) (*prdispatch[(key-4)])(); // Dispatch menu
    isrmenu=FALSE;
  }
  else if(isgots){ // Valid string entered
    unsigned int p=rmseek(selcell);
    delcell(selcell);
    memmove(rmem+p+strlen(gots), rmem+p-1, rmseek(RCELLS)-p);
    rmem[p]=TXT;
    for(byte i=0; i<MAXTXT && i<strlen(gots); i++) rmem[p+1+i]=gots[i];
    isgots=FALSE; printsheet(); isprintscreen=TRUE;
  }
  else if(issave){ // Save
    if(key>=4 && key<=9) rsave(key-4);
    issave=FALSE;
  }
  else if(isload){ // Load
    if(key>=4 && key<=9) rload(key-4);
    evalall();
    isload=FALSE;
  }
  else if(key==KGSB) isrmenu=!isrmenu; // Menu
  else if(key==K8) rup(); // Up
  else if(key==K2) rdown(); // Down
  else if(key==K4) rleft(); // Left
  else if(key==K6) rright(); // Right
  else if(key==KENTER || key==K5){ // Edit/reference
    israxedit=TRUE;
    if(isref){ // Reference
      byte refcell=selcell; // Rescue referenced cell
      selcell=oldselcell; shiftleft=oldshiftleft; shiftup=oldshiftup; // Reset position
      memcmdat(selcell,REF,editcurpos++); memcmdat(selcell,refcell,editcurpos++);
      refcell=END; isref=FALSE;
      evalall(); // To print new val while edit
      printrax();
    }
    else if(iscelltxt(selcell)){entertxtcell(FALSE); israxedit=FALSE;} // Edit text cell
    else{seteditcurpos(); eval(selcell);} // Edit num cell
  }
  else if(key==KRS){ // Edit text cell
    unsigned int p=rmseek(selcell);
    if(rmem[p]==TXT) entertxtcell(FALSE); else entertxtcell(TRUE); // Existing or new text cell
  }
  else if(key==KBSP){delcell(selcell); evalall();} // Delete
  else if(key==KSTO) issave=TRUE; // Save
  else if(key==KRCL) isload=TRUE; // Load
}

static void kflex(void){ // FLEX
  if(key==KGSB) fquit(); // Quit
  else if(key==KRS){israxedit=TRUE; seteditcurpos(); /*eval(selcell);*/} // Edit
  else if(key==KENTER || key==KSUM) fenter(); // ENTER
  else if(key==KBSP) fbsp(); // BSP
  else if(key<=KDOT) fnuminput(); // Number (0-9.)
  else if(key<=KDIV) flink(); // Link cells with char (key)
  else fins(key); // Insert flex command (key)
  eval(selcell); eval(selcell); // 2x workaround for f/g-key
}

static void ktt(void){ // TT
  if(isttmenu){
    if(key>=4 && key<=9) (*ttmdispatch[(key-4)])(); // Dispatch menu
    isttmenu=FALSE;
  }
  else if(key==KGSB) isttmenu=!isttmenu; // Menu
  else if(key==KBSP) ttclx(); // Clear
  else if(key==KROT){ttrot(); _t();} // ROT
  else if(key==KSQRT){ttsqrt(); _t();} // SQRT
  else if(key==KSWAP){ttswap(); _t();} // SWAP
  else if(key==KSTO){ttstosto(); _t();} // STO
  else if(key==KRCL){ttstorcl(); _t();} // RCL
  else if(key==KPOW){ttpercent(); _t();} // %
  else if(key<=MAXTTKEYS){
    (*ttdispatch[key])(); // Dispatch
    if(key>_DOT && key!=KENTER) _t(); // New number (except 0-9. and dup)
  }
}

static void krule(void){ // Slide Rule
  if(key==KGSB) isrule=FALSE; // Quit
  else if(key==KSQRT) ruleleft(1); // Left
  else if(key==KDIV) ruleright(1); // Right
  else if(key==KEXP) ruleleft(5); // Left x5
  else if(key==K9) ruleright(5); // Right x5
  else if(key==KPOW10) ruleleft(10); // Left x10
  else if(key==K8) ruleright(10); // Right x10
  else if(key==KPOW) ruleleft(20); // Left x20
  else if(key==K7) ruleright(20); // Right x20
}

static void ktex(void){ // TEX
  if(issave){ // Save
    if(key>=4 && key<=9) tsave(key-4);
    issave=FALSE;
  }
  else if(isload){ // Load
    if(key>=4 && key<=9) tload(key-4);
    isload=FALSE;
  }
  else if(key==KGSB) istex=FALSE; // Quit
  else if(key==K8){istexup=FALSE; if(texline) texline--;} // Up
  else if(key==K2){istexup=TRUE; if(texline+1<texlines()) texline++;} // Down
  else if(key==K9){istexup=FALSE; if(texline>4) texline-=5; else texline=0;} // PgUp
  else if(key==K3){istexup=TRUE; if(texline+1+5<texlines()) texline+=5; else texline=texlines()-1;} // PgDown
  else if(key==KENTER) texstartedit(); // Edit line
  else if(key==KDIV){texstartedit(); islinesplit=TRUE;} // Edit line and split at cursor
  else if(key==KBSP || key==KSUB){linedelete(); if(texline) texline--;} // Delete line
  else if(key==KMUL){if(texlines()>1) linejoin();} // Join line
  else if(key==KADD) linenew(); // New line
  else if(key==KSTO) issave=TRUE; // Save
  else if(key==KRCL) isload=TRUE; // Load
}

static void setup(void){
  systemInit(); init_keyboard_pins(); // Configure cpu and mandatory peripherals
  gpioSetPullup(&IOCON_PIO1_11, gpioPullupMode_Inactive);  // Vref pins to idle state
  gpioSetPullup(&IOCON_PIO3_2,  gpioPullupMode_Inactive);
  vref_idle();
  setpin(0,4,1,0); setpin(0,5,1,0); // Configure unused i2c pins for lower energy consumption
  cpuSetClock(0); // Set CPU to 12 MHz (0/1...12/48 MHz)
  memset(rmem,END,RMEMMAX); memset(rstore,END,sizeof(rstore)); // Init rmem and rstore
}

int main(void){
  setup(); // Setup hardware
  byte keyold=0; // Debouncing key variable
  unsigned int timestamp=timer(); // Get timestamp (in sec)

  for(;;){ // Main loop
    if(isprintscreen) isprintscreen=printscreen(); // Print screen

    if(isplay){ // Play recorded keys
      key=rec[recp]; keyold=END;
      if(key==END || recp>=MAXREC){ // Stop
        isplay=FALSE; keyrelease();
        if(!isslope && !issolve && !isint && !isplotcalc) isprintscreen=TRUE;
      }
      else recp++;
    }
    else if(isslope){ // # Slope=(f2- - 8*f1- + 8*f1 - f2 )/12/DELTAX
      runs++; key=KRS; // Play recorded keys
      if(runs==1){} // First run - f2-
      else if(runs==2){ // Second run
        intf+=popr(); slopex+=DELTAX; pushr(slopex); // f1-
      }
      else if(runs==3){ // Third run
        intf-=8*popr(); slopex+=2*DELTAX; pushr(slopex); // f1
      }
      else if(runs==4){ // Fourth run
        intf+=8*popr(); slopex+=DELTAX; pushr(slopex); // f2
      }
      else{ // Last run
        pushr((intf-popr())/12.0F/DELTAX);
        isprintscreen=TRUE; isslope=FALSE; key=END; // Exit
      }
    }
    else if(issolve){ // Solve
      if(++runs<3){
        if(runs==2){ // Second run
          _swap(); pushr(DELTAX); _add(); // x0+DELTAX ... Prepare new x-value
        }
        key=KRS; // Play recorded keys
      }
      else{ // Third run
        _swap(); _div(); pushr(-1.0F); _add(); // f1/f0-1
        pushr(DELTAX); _swap(); _div(); // diffx=DELTAX/(f1/f0-1)
        long double diffx=pushr(popr()); // Rescue diffx for exit condition
        _sub(); // x1=x0-diffx ... improved x-value
        runs=0;
        if(_abs(diffx)<DELTAX || laps>MAXLAPS){ // Exit
          if(laps>MAXLAPS){pop(); push((struct data){NAN,NAN});}
          isprintscreen=TRUE; issolve=FALSE; key=END;
        }
        else{_dup(); _dup(); laps++;} // 3 x1 on stack
      }
    }
    else if(isint){ // Integrate
      runs++; key=KRS; // Play recorded keys
      if(runs==1){} // First run - f(b)
      else if(runs==2){ // Second run - f(a)
        intf+=popr(); pushr(limita); // F=F+f(b)
      }
      else if(runs==3){ // Third run - xa
        intf+=popr(); pushr(limita+intdelta); // F=F+f(a)
      }
      else if(runs<=2*STRIPES-1+3){ // 2n-1 stripes
        intf+=(((runs-3)%2)?4:2)*popr(); pushr(limita+(runs-2)*intdelta); // Multiplyer (2 even, 4 odd)
      }
      else{ // Last run
        popr(); pushr(intf*intdelta/3.0F);
        isprintscreen=TRUE; isint=FALSE; key=END; // Exit
      }
    }
    else if(isplotcalc){ // # Plot
      runs++; key=KRS; // Play recorded keys
      if(laps==0){ // LAP1 - Find min/max
        if(runs==1){}
        else if(runs==2){plotmin=plotmax=popr(); pushr(limita);} // Init min/max
        else if(runs<=PLOTX+2){
          long double y=popr(); if(y<plotmin) plotmin=y; if(y>plotmax) plotmax=y; // Min/Max
          pushr(limita+(runs-2)*intdelta);
        }
        else{runs=0; laps++; pushr(limita);} // Prepare 2nd lap
      }
      else{ // LAP2 - Fill plot[]
        if(runs==1){}
        else if(runs<=PLOTX+1){
          plot[runs-2]=round((plotmin-popr())/(plotmin-plotmax)*(PLOTY-1));
          pushr(limita+(runs-1)*intdelta);
        }
        else{
          pop(); pop(); // Delete last pushes
          isprintscreen=TRUE; isplotcalc=FALSE; key=END; plotstart();
        }
      }
    }

    else{
      sleep_ds(offtime*10, WT_ALL_KEYS); // Wait timespan (in dsec) or interupt (keypress or RTC)
      key=scankey(); // Scan key
    }

    if(timer()-timestamp>offtime) key=KON; // Timer suspend

    if(key!=END && key!=keyold){ // Evaluate key
      if(!isplay && !isslope && !issolve && !isint && !isplotcalc) isprintscreen=TRUE;
      if(isrec) rec[recp++]=key;
      if(key==KON){key=END; sleep();} // Suspend
      else if(isgets) kgets();
      else if(ispc) kpc();
      else if(isplot) kplot();
      else if(isplex) kplex();
      else if(israxedit) kraxedit();
      else if(israx) krax();
      else if(isflex) kflex();
      else if(istt) ktt();
      else if(isrule) krule();
      else if(istex) ktex();
      else kdesk();
      timestamp=timer(); // Reset timestamp
    } // End of key evaluation
    keyold=key;
  } // End main loop
}
