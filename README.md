# MMA4660FCT_I2C #

## Description ##

Basic communication library via I2C bus with MMA7660 accelerometer.

## Note ##

In this library uses [that](https://github.com/tardonyx/CC430F5137_USCI_B0_I2C) I2C lib.
You can also change BASIC COMMUNICATION functions to let it work with you I2C library.

## Example of usage ##

Just create you own settings in MMA7660_Init() finction and call it.
After that you can do anything you want.
NOTE: if you use interrupt mode, you should read TILT register to reset interrupts in MMA7660.

    
    uint_8 axesBuffer[3] = { 0x00, 0x00, 0x00 };
    MMA7660_Init();
    while(1) {
        MMA7660_readAxes(axesBuffer);
        // processing...
    }
