#include "msp430g2553.h"

/************************** I2C Address ***************************************/
#define TCA9538_ADDRESS		0x73 		// I2C Address 0100 00 + ADDR + R/W
											// ADDR tied to Vcc (permanent)
/************************** I2C Registers *************************************/
#define TCA9538_INPUT_REG 		0x00		// Input status register
#define TCA9538_OUTPUT_REG		0x01		// Output register to change state of output BIT set to 1, output set HIGH
#define TCA9538_POLARITY_REG 	0x02		// Polarity inversion register. BIT '1' inverts input polarity of register 0x00
#define TCA9538_CONFIG_REG		0x03		// Configuration register. BIT = '1' sets port to input BIT = '0' sets port to output


struct TCA9538_sInput{
	unsigned char P0:1;
	unsigned char P1:1;
	unsigned char P2:1;
	unsigned char P3:1;
	unsigned char P4:1;
	unsigned char P5:1;
	unsigned char P6:1;
	unsigned char P7:1;
};

union TCA9538_uInput{
	unsigned char 		all;
	struct TCA9538_sInput	 	bit;
};

struct TCA9538_sOutput{
	unsigned char P0:1;
	unsigned char P1:1;
	unsigned char P2:1;
	unsigned char P3:1;
	unsigned char P4:1;
	unsigned char P5:1;
	unsigned char P6:1;
	unsigned char P7:1;
};

union TCA9538_uOutput{
	unsigned char 		all;
	struct TCA9538_sOutput		bit;
};

struct TCA9538_sPolarityInversion{
	unsigned char P0:1;
	unsigned char P1:1;
	unsigned char P2:1;
	unsigned char P3:1;
	unsigned char P4:1;
	unsigned char P5:1;
	unsigned char P6:1;
	unsigned char P7:1;
};

union TCA9538_uPolarityInversion{
	unsigned char				all;
	struct TCA9538_sPolarityInversion 	bit;
};

struct TCA9538_sConfig{
	unsigned char P0:1;
	unsigned char P1:1;
	unsigned char P2:1;
	unsigned char P3:1;
	unsigned char P4:1;
	unsigned char P5:1;
	unsigned char P6:1;
	unsigned char P7:1;
};

union TCA9538_uConfig{
	unsigned char				all;
	struct TCA9538_sConfig				bit;
};

struct sTCA9538Regs{
	union TCA9538_uInput 				Input;
	union TCA9538_uOutput 				Output;
	union TCA9538_uPolarityInversion 	PolarityInversion;
	union TCA9538_uConfig				Config;
};

typedef struct {
	union TCA9538_uInput 				Input;
	union TCA9538_uOutput				Output;
	union TCA9538_uPolarityInversion	PolarityInversion;
	union TCA9538_uConfig				Config;
} TCA9538Regs;

void TCA9538WriteConfig(TCA9538Regs * Regs);
void TCA9538WriteOutput(TCA9538Regs * Regs);
void TCA9538WritePolarity(TCA9538Regs * Regs);

void TCA9538InitDefault(TCA9538Regs* Regs);
unsigned char TCA9538InitI2CReg(TCA9538Regs* Regs);
void TCA9538ReadInputReg(TCA9538Regs* Regs);
