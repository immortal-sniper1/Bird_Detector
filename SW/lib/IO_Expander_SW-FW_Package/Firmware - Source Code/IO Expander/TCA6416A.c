#include "TCA6416A.h"
#include "USCI_I2C.h"
#include "BoosterPack.h"

//unsigned char convertArray[2];

extern unsigned char NACK;

// ****************************************************************************
//! @fn          void TCA6416AInitDefault(TCA6416ARegs* Regs)
//! @brief
//!				 Initializes the confRegs structure which is
//!              a local mirror of the TPL7200 config registers
//!              additional TPL7200writeConfigRegisters(confRegs) function call
//! 			 is needed in order to get the TPL7200 registers updated
//!
//! TODO 		 Implement I2C return (success/failure)
// ****************************************************************************
void TCA6416AInitDefault(TCA6416ARegs* Regs){
	Regs->Output.all = 0xFFFF;
	Regs->PolarityInversion.all = 0x0000;
	Regs->Config.all = 0x0000;
}


// ****************************************************************************
//! @fn          void TCA6416AInitI2CReg(TCA6416ARegs* Regs)
//! @brief
//!
//! TODO 		 Implement I2C return (success/failure)
// ****************************************************************************
unsigned char TCA6416AInitI2CReg(TCA6416ARegs* Regs){
	unsigned char return_Value = I2C_OPERATION_SUCCESSFUL;
	I2C_Write(2, TCA6416A_ADDRESS, TCA6416A_CONFIG_REG0, (unsigned char*)&Regs->Config, 0);
	I2C_Write(2, TCA6416A_ADDRESS, TCA6416A_OUTPUT_REG0, (unsigned char*)&Regs->Output, 0);
	I2C_Write(2, TCA6416A_ADDRESS, TCA6416A_POLARITY_REG0, (unsigned char*)&Regs->PolarityInversion, 0);
	if(NACK)
	{
		NACK = 0;

		return_Value = I2C_OPERATION_FAIL;
	}

	return return_Value;
}

// ****************************************************************************
//! @fn          void TCA6416ReadInputReg(TCA6416ARegs* Regs)
//! @brief
//!
//! TODO 		 Implement I2C return (success/failure)
// ****************************************************************************
void TCA6416AReadInputReg(TCA6416ARegs* Regs)
{
	I2C_Read(2,TCA6416A_ADDRESS, TCA6416A_INPUT_REG0, (unsigned char*)&Regs->Input);
}


// ****************************************************************************
//! @fn          void TCA6416AInitI2CReg(TCA6416ARegs* Regs)
//! @brief
//!
//! TODO 		 Implement I2C return (success/failure)
// ****************************************************************************
void TCA6416AWriteReg(unsigned char address, unsigned char regaddress, unsigned short regVal)
{
	//I2C_Write(2, address, regaddress, (regVal), 0);
	if(NACK)
	{


	}

}

unsigned char TCA6416AReadReg(unsigned char address, unsigned char regaddress)
{
	return (unsigned char) I2C_Read_Byte(address,regaddress);
}

void TCA6416AWriteConfig(TCA6416ARegs * Regs)
{
	I2C_Write(2, TCA6416A_ADDRESS, TCA6416A_CONFIG_REG0, (unsigned char*)&Regs->Config, 0);
}

void TCA6416AWriteOutput(TCA6416ARegs * Regs)
{
	I2C_Write(2, TCA6416A_ADDRESS, TCA6416A_OUTPUT_REG0, (unsigned char*)&Regs->Output, 0);
}

void TCA6416AWritePolarity(TCA6416ARegs * Regs)
{
	I2C_Write(2, TCA6416A_ADDRESS, TCA6416A_POLARITY_REG0, (unsigned char*)&Regs->PolarityInversion, 0);
}


