#include "MMA7660FCT_I2C.h"


/******************************* MODE options (0x07) **********************************/


const struct MODEs {
	uint_8 STBY;	// 0x00 - Standby mode
	uint_8 ACT;		// 0x01 - Active mode
	uint_8 TEST;	// 0x04 - Test mode
	uint_8 AWE;		// 0x08 - Autowake bit (1 - enable, 0 - disable)
	uint_8 ASE;		// 0x10 - Autosleep bit (1 - enable, 0 - disable)
	uint_8 SCPS;	// 0x20 - 0 - no prescaler, 1 - prescaler divide-by-16 bit
	uint_8 IPP;		// 0x40 - 0 - int is open-drain, 1 - is push-pull
	uint_8 IAH;		// 0x80 - 0 - int is active low, 1 - is active high
} MODE = { 0x00, 0x01, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80 };


/****************************** INTSU options (0x06) *********************************/


const struct INTSUs {
	uint_8 NOINT;	// 0x00 - No interrupts
	uint_8 FBINT;	// 0x01 - Front/Back position change cause an interrupt
	uint_8 PLINT;	// 0x02 - Up/Down/Left/Right position change cause an interrupt
	uint_8 PDINT;	// 0x04 - Tap cause an interrupt
	uint_8 ASINT;	// 0x08 - Autosleep cause an interrupt
	uint_8 GINT;	// 0x10 - Interrupt after every measurement
	uint_8 SHINTZ;	// 0x20 - Z-shake cause an interrupt (and shake bit in TILT)
	uint_8 SHINTY;	// 0x40 - Y-shake cause an interrupt (and shake bit in TILT)
	uint_8 SHINTX;	// 0x80 - X-shake cause an interrupt (and shake bit in TILT)
} INTSU = { 0x00, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80 };


/****************************** SR options (0x08) ************************************/


// Part AMSR of SR_REG options
struct AMSRs {
	uint_8 AMPD;	// 0x00 - Tap Detection Mode and 120 Samples/Second Active and Auto-Sleep Mode
	uint_8 AM64;	// 0x01 - 64 Samples/Second Active and Auto-Sleep Mode
	uint_8 AM32;	// 0x02 - 32 Samples/Second Active and Auto-Sleep Mode
	uint_8 AM16;	// 0x03 - 16 Samples/Second Active and Auto-Sleep Mode
	uint_8 AM8;		// 0x04 - 8  Samples/Second Active and Auto-Sleep Mode
	uint_8 AM4;		// 0x05 - 4  Samples/Second Active and Auto-Sleep Mode
	uint_8 AM2;		// 0x06 - 2  Samples/Second Active and Auto-Sleep Mode
	uint_8 AM1;		// 0x07 - 1  Sample /Second Active and Auto-Sleep Mode
};

// Part AWSR of SR_REG options
struct AWSRs {
	uint_8 AW32;	// 0x00 - 32 Samples/Second Auto-Wake Mode
	uint_8 AW16;	// 0x08 - 16 Samples/Second Auto-Wake Mode
	uint_8 AW8;		// 0x10 - 8 Samples/Second Auto-Wake Mode
	uint_8 AW1;		// 0x18 - 1 Sample/Second Auto-Wake Mode
};

// Part FILT of SR_REG options
struct FILTs {
	uint_8 NOFILT;	// 0x00 - No filtering
	uint_8 FILT2;	// 0x20 - 2 measurement samples at the rate
	uint_8 FILT3;	// 0x40 - 3 measurement samples at the rate
	uint_8 FILT4;	// 0x60 - 4 measurement samples at the rate
	uint_8 FILT5;	// 0x80 - 5 measurement samples at the rate
	uint_8 FILT6;	// 0xA0 - 6 measurement samples at the rate
	uint_8 FILT7;	// 0xC0 - 7 measurement samples at the rate
	uint_8 FILT8;	// 0xE0 - 8 measurement samples at the rate
};

// All SR options
const struct SRs {
	struct AMSRs AMSR;
	struct AWSRs AWSR;
	struct FILTs FILT;
} SR = {
	{ 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07 },
	{ 0x00, 0x08, 0x10, 0x18 },
	{ 0x00, 0x20, 0x40, 0x60, 0x80, 0xA0, 0xC0, 0xE0}
};


/******************************* PD options (0x09) ************************************/


struct PDTHs {
	uint_8 PDTH00; uint_8 PDTH01;	// Tap detection threshold is ±1 count
	uint_8 PDTH02;					// Tap detection threshold is ±2 count
	uint_8 PDTH03;					// Tap detection threshold is ±3 count
	uint_8 PDTH04;					// Tap detection threshold is ±4 count
	uint_8 PDTH05;					// Tap detection threshold is ±5 count
	uint_8 PDTH06;					// Tap detection threshold is ±6 count
	uint_8 PDTH07;					// Tap detection threshold is ±7 count
	uint_8 PDTH08;					// Tap detection threshold is ±8 count
	uint_8 PDTH09;					// Tap detection threshold is ±9 count
	uint_8 PDTH10;					// Tap detection threshold is ±10 count
	uint_8 PDTH11;					// Tap detection threshold is ±11 count
	uint_8 PDTH12;					// Tap detection threshold is ±12 count
	uint_8 PDTH13;					// Tap detection threshold is ±13 count
	uint_8 PDTH14;					// Tap detection threshold is ±14 count
	uint_8 PDTH15;					// Tap detection threshold is ±15 count
	uint_8 PDTH16;					// Tap detection threshold is ±16 count
	uint_8 PDTH17;					// Tap detection threshold is ±17 count
	uint_8 PDTH18;					// Tap detection threshold is ±18 count
	uint_8 PDTH19;					// Tap detection threshold is ±19 count
	uint_8 PDTH20;					// Tap detection threshold is ±20 count
	uint_8 PDTH21;					// Tap detection threshold is ±21 count
	uint_8 PDTH22;					// Tap detection threshold is ±22 count
	uint_8 PDTH23;					// Tap detection threshold is ±23 count
	uint_8 PDTH24;					// Tap detection threshold is ±24 count
	uint_8 PDTH25;					// Tap detection threshold is ±25 count
	uint_8 PDTH26;					// Tap detection threshold is ±26 count
	uint_8 PDTH27;					// Tap detection threshold is ±27 count
	uint_8 PDTH28;					// Tap detection threshold is ±28 count
	uint_8 PDTH29;					// Tap detection threshold is ±29 count
	uint_8 PDTH30;					// Tap detection threshold is ±30 count
	uint_8 PDTH31;					// Tap detection threshold is ±31 count
};

const struct PDs {
	uint_8 ZDA;						// 0x80 - Z-axes tap detection disabled
	uint_8 YDA;						// 0x40 - Y-axes tap detection disabled
	uint_8 XDA;						// 0x20 - X-axes tap detection disabled
	struct PDTHs PDTH;
} PD = {
		0x08, 0x04, 0x02,
		{ 0,  1,  2,  3,  4,  5,  6,  7,  8,  9,
		 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
		 20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
		 30, 31 }
};


/******************************** BASIC COMMUNICATION ***********************************/


void MMA7660_writeReg(uint_8 reg, uint_8 data) {
	uint_8 tmpMsg[2] = { reg, data };
	USCI_I2C_TX_Init(MMA7660FC_ADDR);
	while (USCI_I2C_NotReady());
	USCI_I2C_TX(2, tmpMsg);
	return;
}


uint_8 MMA7660_readReg(uint_8 reg) {
	return USCI_I2C_RX_single_noIV(MMA7660FC_ADDR, reg);
}


/************************************* ADVANCED ****************************************/


void MMA7660_setMODE(uint_8 params) {
	MMA7660_writeReg(MODE_REG, params);
}


void MMA7660_setINTSU(uint_8 params) {
	MMA7660_writeReg(INTSU_REG, params);
}


void MMA7660_Init(void) {
	MMA7660_setMODE(MODE.STBY);				// Set STBY mode to write other registers
	MMA7660_writeReg(SPCNT_REG, 0x00);		// Clear sleep counter
	MMA7660_setINTSU(INTSU.NOINT);			// Disable all interrupts
	MMA7660_writeReg(PDET_REG,				// No tap detection on all axes
			PD.ZDA + PD.YDA + PD.XDA);
	MMA7660_writeReg(SR_REG,				// 8 samples/sec, no filter
			SR.AMSR.AM8 + SR.AWSR.AW1 + SR.FILT.NOFILT);
	MMA7660_writeReg(PD_REG, 0x00);			// No tap detection so set zeros
	MMA7660_setMODE(						// Active mode, autowakeup/autosleep, prescaler 16
			MODE.ACT + MODE.AWE + MODE.ASE + MODE.SCPS);
}


void MMA7660_readAxes(int_8 *buffer) {
	int_8 tmp = 0x00;
	// reading while ALERT bit is 1
	do {
		tmp = MMA7660_readReg(XOUT_REG);
	} while (tmp & ALERT_MASK);
	if (tmp & BIT5) {
		tmp |= BIT7;
		tmp &= ~BIT5;
	}
	buffer[0] = tmp;
	// reading while ALERT bit is 1
	do {
		tmp = MMA7660_readReg(YOUT_REG);
	} while (tmp & ALERT_MASK);
	if (tmp & BIT5) {
		tmp |= BIT7;
		tmp &= ~BIT5;
	}
	buffer[1] = tmp;
	// reading while ALERT bit is 1
	do {
		tmp = MMA7660_readReg(ZOUT_REG);
	} while (tmp & ALERT_MASK);
	if (tmp & BIT5) {
		tmp |= BIT7;
		tmp &= ~BIT5;
	}
	buffer[2] = tmp;
}


/************************************* SPECIFIC ****************************************/


uint_8 MMA7660_isFall(void) {
	MMA7660_readAxes(axesData);
	__no_operation();
	if (axesData[0] <= -107 || axesData[0] >= 13) return 1;
	else if (axesData[2] <= -107 || axesData[2] >= 13) return 1;
	else return 0;
}


void MMA7660_test(void) {
	while(1) {
		MMA7660_readAxes(axesData);
		__no_operation();	// for breakpoint
	}
}
