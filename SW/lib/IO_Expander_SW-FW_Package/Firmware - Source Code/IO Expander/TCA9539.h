#include "msp430g2553.h"

/************************** I2C Address ***************************************/
#define TCA9539_ADDRESS		0x76 		// I2C Address 0100 00 + ADDR + R/W
											// ADDR tied to P2.2 of LaunchPad
/************************** I2C Registers *************************************/
#define TCA9539_INPUT_REG0 	0x00		// Input status register
#define TCA9539_OUTPUT_REG0	0x02		// Output register to change state of output BIT set to 1, output set HIGH
#define TCA9539_POLARITY_REG0 	0x04		// Polarity inversion register. BIT '1' inverts input polarity of register 0x00
#define TCA9539_CONFIG_REG0		0x06		// Configuration register. BIT = '1' sets port to input BIT = '0' sets port to output


struct TCA9539_sBit{
       unsigned char B0:1;
       unsigned char B1:1;
       unsigned char B2:1;
       unsigned char B3:1;
       unsigned char B4:1;
       unsigned char B5:1;
       unsigned char B6:1;
       unsigned char B7:1;
};

union TCA9539_uInputPort{
	unsigned char all;
	struct TCA9539_sBit bit;
};

struct TCA9539_sInput{
	union TCA9539_uInputPort P0;
	union TCA9539_uInputPort P1;
};


union TCA9539_uInput{
	unsigned short all;
	struct TCA9539_sInput Port;
};



union TCA9539_uOutputP0{
	unsigned char 		all;
	struct TCA9539_sBit	bit;
};

union TCA9539_uOutputP1{
	unsigned char 		all;
	struct TCA9539_sBit	bit;
};

struct TCA9539_sOutput{
	union TCA9539_uOutputP0	P0;
	union TCA9539_uOutputP1	P1;
};

union TCA9539_uOutput{
	unsigned short	all;
	struct TCA9539_sOutput	Port;
};

union TCA9539_uPolarityInversionP0{
	unsigned char all;
	struct TCA9539_sBit bit;
};

union  TCA9539_uPolarityInversionP1{
	unsigned char	all;
	struct TCA9539_sBit bit;
};

struct TCA9539_sPolarityInversion{
	union TCA9539_uPolarityInversionP0 P0;
	union TCA9539_uPolarityInversionP1 P1;
};

union TCA9539_uPolarityInversion{
	unsigned short all;
	struct TCA9539_sPolarityInversion Port;
};

union TCA9539_uConfigP0{
	unsigned char all;
	struct TCA9539_sBit bit;
};

union  TCA9539_uConfigP1{
	unsigned char	all;
	struct TCA9539_sBit bit;
};

struct TCA9539_sConfig{
	union TCA9539_uConfigP0 P0;
	union TCA9539_uConfigP1 P1;
};

union TCA9539_uConfig{
	unsigned short all;
	struct TCA9539_sConfig Port;
};

struct sTCA9539Regs{
	union TCA9539_uInput 				Input;
	union TCA9539_uOutput 				Output;
	union TCA9539_uPolarityInversion 	PolarityInversion;
	union TCA9539_uConfig				Config;
};

typedef struct {
	union TCA9539_uInput 				Input;
	union TCA9539_uOutput				Output;
	union TCA9539_uPolarityInversion	PolarityInversion;
	union TCA9539_uConfig				Config;
} TCA9539Regs;

void TCA9539WriteConfig(TCA9539Regs * Regs);
void TCA9539WriteOutput(TCA9539Regs * Regs);
void TCA9539WritePolarity(TCA9539Regs * Regs);

void TCA9539InitDefault(TCA9539Regs* Regs);
unsigned char TCA9539InitI2CReg(TCA9539Regs* Regs);
void TCA9539ReadInputReg(TCA9539Regs* Regs);
