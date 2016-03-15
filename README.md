# usrLedController

This is a simple "Hello World" program for the Beaglebone Black. It is used
to control the User Leds on the BBB using the /sys/class directory.

After building, four symbolic links: on, off, blink and status, which links
to the executable file of the program is created. The program will execute a
different handler depending on the link used.


# Licensing Information: READ LICENSE


## Author and Contributor List

Dennis Law


## File List
```
.:
./src
./include
./obj
./bin
makefile
LICENSE
README.md

./src:
main.cpp
usrLed.cpp

./include:
usrLed.h
```

## Building the Program

1. `cd` into top level directory

2. Call `make clean` (optional)

3. Call `make all`


## Running the program

1. `cd` into the bin directory

2. Call either one of the symbolic links in the folder followed by the
   index of the user led that is to be controlled.
