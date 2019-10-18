# Nucleo32-L432kc-blink
Blink example with Nucleo32-L432KC board and stm32core (Using FreeRTOS, OpenCM3, and with debug on the USB Uart (stlinkv2)

This example is a first project to see how to use stm32core library.

To clone the project you need to use Git Recursive Clone:
```sh
git clone --recursive https://github.com/condo4/Nucleo32-L432kc-blink.git
```

To build the project, you just need arm-none-eabi-gcc
```sh
apt install gcc-arm-none-eabi
```
And use the Makefile:
```sh
cd Nucleo32-L432kc-blink
make
```

In order to flash the board, you can copy binary.bin on the USB Disk created by the Nucleo board, or if you have st-flash installed (stlinkv2 project) you can use:
```sh
make flash
```

If you want to see the debug console with GNU Screen:
```sh
screen /dev/ttyACM0 115200
```
