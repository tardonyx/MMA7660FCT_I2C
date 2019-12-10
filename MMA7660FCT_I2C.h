/*******************************************************************************************************
 
     * File:                MMA7660FCT_I2C.c
     * Description:         Header for the MMA7660FCT_I2C.c
     * Created:             17 oct 2019
     * Author:              Andrey Bibea
     * Email:               andreybibea@gmail.com

********************************************************************************************************/

#include "USCI_I2C.h"

#ifndef MMA7660FCT_I2C_H_
#define MMA7660FCT_I2C_H_

// Communication
#define 		MMA7660FC_ADDR		0x4C		// Main address of the device
#define 		PRESCALER			4			// CLK prescaler on I2C bus

// Registers
#define			XOUT_REG			0x00		// 6-bit output value X (read-only)
#define			YOUT_REG			0x01		// 6-bit output value Y (read-only)
#define			ZOUT_REG			0x02		// 6-bit output value Z (read-only)
#define			TILT_REG			0x03		// Tilt Status (read-only)
#define			SRST_REG			0x04		// Sampling Rate Status
#define			SPCNT_REG			0x05		// Sleep Count
#define			INTSU_REG			0x06		// Interrupt Setup
#define			MODE_REG			0x07		// Mode
#define			SR_REG				0x08		// Auto-Wake/Sleep and Portrait/Landscape samples per seconds and Debounce Filter
#define			PDET_REG			0x09		// Tap Detection
#define			PD_REG				0x0A		// Tap Debounce Count

// Masks
#define			ALERT_MASK			0x40		// If alert bit is set, data reg should be re-read
#define			TILT_SHAKE_MASK		0x80		// Device detected a shake
#define			TILT_TAP_MASK		0x20		// Device detected a tap
#define			TILT_PoLa_MASK		0x1C		// Device orientation detection
#define			TILT_BaFro_MASK		0x03		// Lying front/back detection

typedef unsigned char uint_8;
typedef   signed char  int_8;

int_8 axesData[3];

void MMA7660_writeReg(uint_8 reg, uint_8 data);

uint_8 MMA7660_readReg(uint_8 reg);

void MMA7660_setMODE(uint_8 params);

void MMA7660_setINTSU(uint_8 params);

void MMA7660_Init(void);

void MMA7660_readAxes(int_8 *buffer);

#endif /* MMA7660FCT_I2C_H_ */














