#include "msp430g2553.h"

/************************** I2C Address ***************************************/
#define TCA9535_ADDRESS		0x26 		// I2C Address 0100 00 + ADDR + R/W
											// ADDR tied to P2.2 of LaunchPad
/************************** I2C Registers *************************************/
#define TCA9535_INPUT_REG0 		0x00		// Input status register
#define TCA9535_INPUT_REG1 		0x01		// Input status register
#define TCA9535_OUTPUT_REG0		0x02		// Output register to change state of output BIT set to 1, output set HIGH
#define TCA9535_OUTPUT_REG1		0x03		// Output register to change state of output BIT set to 1, output set HIGH
#define TCA9535_POLARITY_REG0 	0x04		// Polarity inversion register. BIT '1' inverts input polarity of register 0x00
#define TCA9535_POLARITY_REG1 	0x05		// Polarity inversion register. BIT '1' inverts input polarity of register 0x00
#define TCA9535_CONFIG_REG0		0x06		// Configuration register. BIT = '1' sets port to input BIT = '0' sets port to output
#define TCA9535_CONFIG_REG1		0x07		// Configuration register. BIT = '1' sets port to input BIT = '0' sets port to output


struct TCA9535_sBit{
       unsigned char B0:1;
       unsigned char B1:1;
       unsigned char B2:1;
       unsigned char B3:1;
       unsigned char B4:1;
       unsigned char B5:1;
       unsigned char B6:1;
       unsigned char B7:1;
};

union TCA9535_uInputPort{
	unsigned char all;
	struct TCA9535_sBit bit;
};

struct TCA9535_sInput{
	union TCA9535_uInputPort P0;
	union TCA9535_uInputPort P1;
};


union TCA9535_uInput{
	unsigned short all;
	struct TCA9535_sInput Port;
};



union TCA9535_uBitAll{
	unsigned char 		all;
	struct TCA9535_sBit	bit;
};
/*
union TCA9535_uOutputP1{
	unsigned char 		all;
	struct TCA9535_sBit	bit;
};*/

struct TCA9535_sOutput{
	union TCA9535_uBitAll	P0;
	union TCA9535_uBitAll	P1;
};

union TCA9535_uOutput{
	unsigned short	all;
	struct TCA9535_sOutput	Port;
};
/*
union TCA9535_uPolarityInversionP0{
	unsigned char all;
	struct TCA9535_sBit bit;
};

union  TCA9535_uPolarityInversionP1{
	unsigned char	all;
	struct TCA9535_sBit bit;
};
*/
struct TCA9535_sPolarityInversion{
	union TCA9535_uBitAll P0;
	union TCA9535_uBitAll P1;
};

union TCA9535_uPolarityInversion{
	unsigned short all;
	struct TCA9535_sPolarityInversion Port;
};
/*
union TCA9535_uConfigP0{
	unsigned char all;
	struct TCA9535_sBit bit;
};

union  TCA9535_uConfigP1{
	unsigned char	all;
	struct TCA9535_sBit bit;
};*/

struct TCA9535_sConfig{
	union TCA9535_uBitAll P0;
	union TCA9535_uBitAll P1;
};

union TCA9535_uConfig{
	unsigned short all;
	struct TCA9535_sConfig Port;
};

struct sTCA9535Regs{
	union TCA9535_uInput 				Input;
	union TCA9535_uOutput 				Output;
	union TCA9535_uPolarityInversion 	PolarityInversion;
	union TCA9535_uConfig				Config;
};

typedef struct {
	union TCA9535_uInput 				Input;
	union TCA9535_uOutput				Output;
	union TCA9535_uPolarityInversion	PolarityInversion;
	union TCA9535_uConfig				Config;
} TCA9535Regs;

void TCA9535WriteConfig(TCA9535Regs * Regs);
void TCA9535WriteOutput(TCA9535Regs * Regs);
void TCA9535WritePolarity(TCA9535Regs * Regs);

void TCA9535InitDefault(TCA9535Regs* Regs);
unsigned char TCA9535InitI2CReg(TCA9535Regs* Regs);
void TCA9535ReadInputReg(TCA9535Regs* Regs);
