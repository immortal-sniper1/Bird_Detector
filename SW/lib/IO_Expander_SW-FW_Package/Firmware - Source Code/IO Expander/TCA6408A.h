#include "msp430g2553.h"

/************************** I2C Address ***************************************/
#define TCA6408A_ADDRESS		0x21 		// I2C Address 0100 00 + ADDR + R/W
											// ADDR tied to Vcc (permanent)
/************************** I2C Registers *************************************/
#define TCA6408A_INPUT_REG 		0x00		// Input status register
#define TCA6408A_OUTPUT_REG		0x01		// Output register to change state of output BIT set to 1, output set HIGH
#define TCA6408A_POLARITY_REG 	0x02		// Polarity inversion register. BIT '1' inverts input polarity of register 0x00
#define TCA6408A_CONFIG_REG		0x03		// Configuration register. BIT = '1' sets port to input BIT = '0' sets port to output

/****************************************************************************************
 * 	The following structs and unions are used to configure a memory map of the TCA6408A *
 * 	on the MSP430																		*
 * 																						*
 * 	They allow the user to change the entire byte or alter the registers bit by bit		*
 ***************************************************************************************/

/************************** TCA6408A Bit struct *********************************/
struct TCA6408A_sbit{
	unsigned char P0:1;
	unsigned char P1:1;
	unsigned char P2:1;
	unsigned char P3:1;
	unsigned char P4:1;
	unsigned char P5:1;
	unsigned char P6:1;
	unsigned char P7:1;
};

union TCA6408A_uInput{
	unsigned char 				all;
	struct TCA6408A_sbit	 	bit;
};

union TCA6408A_uOutput{
	unsigned char 				all;
	struct TCA6408A_sbit		bit;
};

union TCA6408A_uPolarityInversion{
	unsigned char				all;
	struct TCA6408A_sbit 		bit;
};

union TCA6408A_uConfig{
	unsigned char						all;
	struct TCA6408A_sbit				bit;
};


typedef struct {
	union TCA6408A_uInput 				Input;
	union TCA6408A_uOutput				Output;
	union TCA6408A_uPolarityInversion	PolarityInversion;
	union TCA6408A_uConfig				Config;
} TCA6408ARegs;



unsigned char TCA6408AWriteConfig(TCA6408ARegs * Regs);
unsigned char TCA6408AWriteOutput(TCA6408ARegs * Regs);
unsigned char TCA6408AWritePolarity(TCA6408ARegs * Regs);

void TCA6408AInitDefault(TCA6408ARegs* Regs);
unsigned char TCA6408AInitI2CReg(TCA6408ARegs* Regs);
unsigned char TCA6408AReadInputReg(TCA6408ARegs* Regs);
