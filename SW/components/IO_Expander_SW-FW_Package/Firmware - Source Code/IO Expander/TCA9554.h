#include "msp430g2553.h"

/************************** I2C Address ***************************************/
#define TCA9554_ADDRESS		0x27 		// I2C Address 0100 00 + ADDR + R/W
											// ADDR tied to Vcc (permanent)
/************************** I2C Registers *************************************/
#define TCA9554_INPUT_REG 		0x00		// Input status register
#define TCA9554_OUTPUT_REG		0x01		// Output register to change state of output BIT set to 1, output set HIGH
#define TCA9554_POLARITY_REG 	0x02		// Polarity inversion register. BIT '1' inverts input polarity of register 0x00
#define TCA9554_CONFIG_REG		0x03		// Configuration register. BIT = '1' sets port to input BIT = '0' sets port to output


struct TCA9554_sInput{
	unsigned char P0:1;
	unsigned char P1:1;
	unsigned char P2:1;
	unsigned char P3:1;
	unsigned char P4:1;
	unsigned char P5:1;
	unsigned char P6:1;
	unsigned char P7:1;
};

union TCA9554_uInput{
	unsigned char 		all;
	struct TCA9554_sInput	 	bit;
};

struct TCA9554_sOutput{
	unsigned char P0:1;
	unsigned char P1:1;
	unsigned char P2:1;
	unsigned char P3:1;
	unsigned char P4:1;
	unsigned char P5:1;
	unsigned char P6:1;
	unsigned char P7:1;
};

union TCA9554_uOutput{
	unsigned char 		all;
	struct TCA9554_sOutput		bit;
};

struct TCA9554_sPolarityInversion{
	unsigned char P0:1;
	unsigned char P1:1;
	unsigned char P2:1;
	unsigned char P3:1;
	unsigned char P4:1;
	unsigned char P5:1;
	unsigned char P6:1;
	unsigned char P7:1;
};

union TCA9554_uPolarityInversion{
	unsigned char				all;
	struct TCA9554_sPolarityInversion 	bit;
};

struct TCA9554_sConfig{
	unsigned char P0:1;
	unsigned char P1:1;
	unsigned char P2:1;
	unsigned char P3:1;
	unsigned char P4:1;
	unsigned char P5:1;
	unsigned char P6:1;
	unsigned char P7:1;
};

union TCA9554_uConfig{
	unsigned char				all;
	struct TCA9554_sConfig				bit;
};

struct sTCA9554Regs{
	union TCA9554_uInput 				Input;
	union TCA9554_uOutput 				Output;
	union TCA9554_uPolarityInversion 	PolarityInversion;
	union TCA9554_uConfig				Config;
};

typedef struct {
	union TCA9554_uInput 				Input;
	union TCA9554_uOutput				Output;
	union TCA9554_uPolarityInversion	PolarityInversion;
	union TCA9554_uConfig				Config;
} TCA9554Regs;

void TCA9554WriteConfig(TCA9554Regs * Regs);
void TCA9554WriteOutput(TCA9554Regs * Regs);
void TCA9554WritePolarity(TCA9554Regs * Regs);

void TCA9554InitDefault(TCA9554Regs* Regs);
unsigned char TCA9554InitI2CReg(TCA9554Regs* Regs);
void TCA9554ReadInputReg(TCA9554Regs* Regs);
