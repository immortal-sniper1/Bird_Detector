#include "msp430g2553.h"


#define MACRO *(unsigned char*)&

/************************** I2C Address ***************************************/
#define TCA6424A_ADDRESS		0x23 		// I2C Address 0100 01 + ADDR + R/W
											// ADDR tied to P2.3 of LaunchPad
/************************** I2C Registers *************************************/
#define TCA6424A_INPUT_REG0		0x00		// Input status register
#define TCA6424A_INPUT_REG1		0x01		// Input status register
#define TCA6424A_INPUT_REG2		0x02		// Input status register
#define TCA6424A_OUTPUT_REG0	0x04		// Output register to change state of output BIT set to 1, output set HIGH
#define TCA6424A_OUTPUT_REG1	0x05		// Output register to change state of output BIT set to 1, output set HIGH
#define TCA6424A_OUTPUT_REG2	0x06		// Output register to change state of output BIT set to 1, output set HIGH
#define TCA6424A_POLARITY_REG0 	0x08		// Polarity inversion register. BIT '1' inverts input polarity of register 0x00
#define TCA6424A_POLARITY_REG1 	0x09		// Polarity inversion register. BIT '1' inverts input polarity of register 0x00
#define TCA6424A_POLARITY_REG2 	0x0A		// Polarity inversion register. BIT '1' inverts input polarity of register 0x00
#define TCA6424A_CONFIG_REG0   	0x0C		// Configuration register. BIT = '1' sets port to input BIT = '0' sets port to output
#define TCA6424A_CONFIG_REG1   	0x0D		// Configuration register. BIT = '1' sets port to input BIT = '0' sets port to output
#define TCA6424A_CONFIG_REG2   	0x0E		// Configuration register. BIT = '1' sets port to input BIT = '0' sets port to output



struct TCA6424A_sBit{
	unsigned char B0:1;
	unsigned char B1:1;
	unsigned char B2:1;
	unsigned char B3:1;
	unsigned char B4:1;
	unsigned char B5:1;
	unsigned char B6:1;
	unsigned char B7:1;

};

union TCA6424_uInput{
	unsigned char	all;
	struct TCA6424A_sBit bit;
};

struct TCA6424A_sInputP{
	union TCA6424_uInput P0;
	union TCA6424_uInput P1;
	union TCA6424_uInput P2;
};

union TCA6424A_uInputA{
	unsigned long 		all;
	struct TCA6424A_sInputP	 	Port;
};



union TCA6424A_uOutputP0{
	unsigned char 		all;
	struct TCA6424A_sBit	bit;
};


struct TCA6424A_sOutput{
	union TCA6424A_uOutputP0	P0;
	union TCA6424A_uOutputP0	P1;
	union TCA6424A_uOutputP0	P2;
};

union TCA6424A_uOutput{
	unsigned long	all;
	struct TCA6424A_sOutput	Port;
};

union TCA6424A_uPolarityInversionP0{
	unsigned char all;
	struct TCA6424A_sBit bit;
};

union  TCA6424A_uPolarityInversionP1{
	unsigned char	all;
	struct TCA6424A_sBit bit;
};

union  TCA6424A_uPolarityInversionP2{
	unsigned char	all;
	struct TCA6424A_sBit bit;
};

struct TCA6424A_sPolarityInversion{
	union TCA6424A_uPolarityInversionP0	P0;
	union TCA6424A_uPolarityInversionP0	P1;
	union TCA6424A_uPolarityInversionP0	P2;
};

union TCA6424A_uPolarityInversion{
	unsigned long all;
	struct TCA6424A_sPolarityInversion Port;
};

union TCA6424A_uConfigP0{
	unsigned char all;
	struct TCA6424A_sBit bit;
};

union  TCA6424A_uConfigP1{
	unsigned char	all;
	struct TCA6424A_sBit bit;
};

union  TCA6424A_uConfigP2{
	unsigned char	all;
	struct TCA6424A_sBit bit;
};

struct TCA6424A_sConfig{
	union TCA6424A_uConfigP0	P0;
	union TCA6424A_uConfigP0	P1;
	union TCA6424A_uConfigP0	P2;
};

union TCA6424A_uConfig{
	unsigned long all;
	struct TCA6424A_sConfig Port;
};



typedef struct {
	union TCA6424A_uInputA 				Input;
	union TCA6424A_uOutput				Output;
	union TCA6424A_uPolarityInversion	PolarityInversion;
	union TCA6424A_uConfig				Config;
} TCA6424ARegs;

void TCA6424AWriteConfig(TCA6424ARegs * Regs);
void TCA6424AWriteOutput(TCA6424ARegs * Regs);
void TCA6424AWritePolarity(TCA6424ARegs * Regs);

void TCA6424AInitDefault(TCA6424ARegs* Regs);
void TCA6424AInitI2CReg(TCA6424ARegs* Regs);
void TCA6424AReadInputReg(TCA6424ARegs* Regs);
