#include "msp430g2553.h"

/************************** I2C Address ***************************************/
#define TCA9554A_ADDRESS		0x3F 		// I2C Address 0100 00 + ADDR + R/W
											// ADDR tied to Vcc (permanent)
/************************** I2C Registers *************************************/
#define TCA9554A_INPUT_REG 		0x00		// Input status register
#define TCA9554A_OUTPUT_REG		0x01		// Output register to change state of output BIT set to 1, output set HIGH
#define TCA9554A_POLARITY_REG 	0x02		// Polarity inversion register. BIT '1' inverts input polarity of register 0x00
#define TCA9554A_CONFIG_REG		0x03		// Configuration register. BIT = '1' sets port to input BIT = '0' sets port to output


struct TCA9554A_sInput{
	unsigned char P0:1;
	unsigned char P1:1;
	unsigned char P2:1;
	unsigned char P3:1;
	unsigned char P4:1;
	unsigned char P5:1;
	unsigned char P6:1;
	unsigned char P7:1;
};

union TCA9554A_uInput{
	unsigned char 		all;
	struct TCA9554A_sInput	 	bit;
};

struct TCA9554A_sOutput{
	unsigned char P0:1;
	unsigned char P1:1;
	unsigned char P2:1;
	unsigned char P3:1;
	unsigned char P4:1;
	unsigned char P5:1;
	unsigned char P6:1;
	unsigned char P7:1;
};

union TCA9554A_uOutput{
	unsigned char 		all;
	struct TCA9554A_sOutput		bit;
};

struct TCA9554A_sPolarityInversion{
	unsigned char P0:1;
	unsigned char P1:1;
	unsigned char P2:1;
	unsigned char P3:1;
	unsigned char P4:1;
	unsigned char P5:1;
	unsigned char P6:1;
	unsigned char P7:1;
};

union TCA9554A_uPolarityInversion{
	unsigned char				all;
	struct TCA9554A_sPolarityInversion 	bit;
};

struct TCA9554A_sConfig{
	unsigned char P0:1;
	unsigned char P1:1;
	unsigned char P2:1;
	unsigned char P3:1;
	unsigned char P4:1;
	unsigned char P5:1;
	unsigned char P6:1;
	unsigned char P7:1;
};

union TCA9554A_uConfig{
	unsigned char				all;
	struct TCA9554A_sConfig				bit;
};

struct sTCA9554ARegs{
	union TCA9554A_uInput 				Input;
	union TCA9554A_uOutput 				Output;
	union TCA9554A_uPolarityInversion 	PolarityInversion;
	union TCA9554A_uConfig				Config;
};

typedef struct {
	union TCA9554A_uInput 				Input;
	union TCA9554A_uOutput				Output;
	union TCA9554A_uPolarityInversion	PolarityInversion;
	union TCA9554A_uConfig				Config;
} TCA9554ARegs;

void TCA9554AWriteConfig(TCA9554ARegs * Regs);
void TCA9554AWriteOutput(TCA9554ARegs * Regs);
void TCA9554AWritePolarity(TCA9554ARegs * Regs);

void TCA9554AInitDefault(TCA9554ARegs* Regs);
unsigned char TCA9554AInitI2CReg(TCA9554ARegs* Regs);
void TCA9554AReadInputReg(TCA9554ARegs* Regs);
