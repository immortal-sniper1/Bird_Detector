#include "TCA6408A.h"
#include "USCI_I2C.h"
#include "BoosterPack.h"

#define CLR_NACK NACK = 0


extern unsigned char NACK;

// ****************************************************************************
//! @fn          void TCA6408AInitDefault(TCA6408ARegs* Regs)
//! @brief
//!				 Initializes the confRegs structure which is
//!              a local mirror of the TPL7200 config registers
//!              additional TPL7200writeConfigRegisters(confRegs) function call
//! 			 is needed in order to get the TPL7200 registers updated
//!
//! ****************************************************************************
void TCA6408AInitDefault(TCA6408ARegs* Regs)
{
	Regs->Output.all = 0xFF;
	Regs->PolarityInversion.all = 0x00;
	Regs->Config.all = 0x00;
}


// ****************************************************************************
//! @fn          void TCA6408AInitI2CReg(TCA6408ARegs* Regs)
//! @brief
//! @return		 Returns I2C success or failure
//!
// ****************************************************************************
unsigned char TCA6408AInitI2CReg(TCA6408ARegs* Regs)
{
	unsigned char return_Value = I2C_OPERATION_SUCCESSFUL;
	CLR_NACK;
	I2C_Write_Byte(TCA6408A_ADDRESS, TCA6408A_CONFIG_REG, Regs->Config.all);
	I2C_Write_Byte(TCA6408A_ADDRESS, TCA6408A_OUTPUT_REG, Regs->Output.all);
	I2C_Write_Byte(TCA6408A_ADDRESS, TCA6408A_POLARITY_REG, Regs->PolarityInversion.all);
	if(NACK)
	{
		NACK = 0;

		return_Value = I2C_OPERATION_FAIL;
	}
	return return_Value;
}

// ****************************************************************************
//! @fn          void TCA6408AReadInputReg(TCA6408ARegs* Regs)
//! @brief		 Stores input register values to MSP430 Memory map
//! @return		 Returns I2C success or failure
//!
// ****************************************************************************
unsigned char TCA6408AReadInputReg(TCA6408ARegs* Regs)
{
	unsigned char return_Value = I2C_OPERATION_SUCCESSFUL;
	CLR_NACK;
	I2C_Read(1,TCA6408A_ADDRESS, TCA6408A_INPUT_REG, (unsigned char*)&Regs->Input);
	if(NACK)
	{
		NACK = 0;
		return_Value = I2C_OPERATION_FAIL;
	}
	return return_Value;
}

// ****************************************************************************
//! @fn          void TCA6408AWriteConfig(TCA6408ARegs* Regs)
//! @brief		 Writes config value from MSP430 memory map to TCA6408A
//! @return		 Returns I2C success or failure
//!
// ****************************************************************************
unsigned char TCA6408AWriteConfig(TCA6408ARegs * Regs)
{
	unsigned char return_Value = I2C_OPERATION_SUCCESSFUL;
	CLR_NACK;
	I2C_Write(1, TCA6408A_ADDRESS, TCA6408A_CONFIG_REG, (unsigned char*)&Regs->Config, 0);
	if(NACK)
	{
		NACK = 0;
		return_Value = I2C_OPERATION_FAIL;
	}
	return return_Value;
}

// ****************************************************************************
//! @fn          void TCA6408AWriteOutput(TCA6408ARegs* Regs)
//! @brief		 Writes output value from MSP430 memory map to TCA6408A
//! @return		 Returns I2C success or failure
//!
// ****************************************************************************
unsigned char TCA6408AWriteOutput(TCA6408ARegs * Regs)
{
	unsigned char return_Value = I2C_OPERATION_SUCCESSFUL;
	CLR_NACK;
	I2C_Write(1, TCA6408A_ADDRESS, TCA6408A_OUTPUT_REG, (unsigned char*)&Regs->Output, 0);
	if(NACK)
	{
		NACK = 0;
		return_Value = I2C_OPERATION_FAIL;
	}
	return return_Value;
}

// ****************************************************************************
//! @fn          void TCA6408AWritePolarity(TCA6408ARegs* Regs)
//! @brief		 Writes polarity inversion value from MSP430 memory map to TCA6408A
//! @return		 Returns I2C success or failure
//!
// ****************************************************************************
unsigned char TCA6408AWritePolarity(TCA6408ARegs * Regs)
{
	unsigned char return_Value = I2C_OPERATION_SUCCESSFUL;
	CLR_NACK;
	I2C_Write(1, TCA6408A_ADDRESS, TCA6408A_POLARITY_REG, (unsigned char*)&Regs->PolarityInversion, 0);
	if(NACK)
	{
		NACK = 0;
		return_Value = I2C_OPERATION_FAIL;
	}
	return return_Value;
}



