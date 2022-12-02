#include "TCA9535.h"
#include "USCI_I2C.h"
#include "BoosterPack.h"
//unsigned char convertArray[2];

extern unsigned char NACK;

// ****************************************************************************
//! @fn          void TCA9535InitDefault(TCA9535Regs* Regs)
//! @brief
//!				 Initializes the confRegs structure which is
//!              a local mirror of the TPL7200 config registers
//!              additional TPL7200writeConfigRegisters(confRegs) function call
//! 			 is needed in order to get the TPL7200 registers updated
//!
//! TODO 		 Implement I2C return (success/failure)
// ****************************************************************************
void TCA9535InitDefault(TCA9535Regs* Regs){
	Regs->Output.all = 0xFFFF;
	Regs->PolarityInversion.all = 0x0000;
	Regs->Config.all = 0x0000;
}


// ****************************************************************************
//! @fn          void TCA9535InitI2CReg(TCA9535Regs* Regs)
//! @brief
//!
//! TODO 		 Implement I2C return (success/failure)
// ****************************************************************************
unsigned char TCA9535InitI2CReg(TCA9535Regs* Regs){
	unsigned char return_Value = I2C_OPERATION_SUCCESSFUL;

	I2C_Write(2, TCA9535_ADDRESS, TCA9535_CONFIG_REG0, (unsigned char*)&Regs->Config, 0);
	I2C_Write(2, TCA9535_ADDRESS, TCA9535_OUTPUT_REG0, (unsigned char*)&Regs->Output, 0);
	I2C_Write(2, TCA9535_ADDRESS, TCA9535_POLARITY_REG0, (unsigned char*)&Regs->PolarityInversion, 0);
	if(NACK)
	{
		NACK = 0;

		return_Value = I2C_OPERATION_FAIL;
	}

	return return_Value;
}

// ****************************************************************************
//! @fn          void TCA9535ReadInputReg(TCA9535Regs* Regs)
//! @brief
//!
//! TODO 		 Implement I2C return (success/failure)
// ****************************************************************************
void TCA9535ReadInputReg(TCA9535Regs* Regs){
	I2C_Read(2,TCA9535_ADDRESS, TCA9535_INPUT_REG0, (unsigned char*)&Regs->Input);
}


// ****************************************************************************
//! @fn          void TCA9535InitI2CReg(TCA9535Regs* Regs)
//! @brief
//!
//! TODO 		 Implement I2C return (success/failure)
// ****************************************************************************
void TCA9535WriteReg(unsigned char address, unsigned char regaddress, unsigned short regVal)
{
	//I2C_Write(2, address, regaddress, (regVal), 0);
	if(NACK)
	{


	}

}

unsigned char TCA9535ReadReg(unsigned char address, unsigned char regaddress)
{
	return (unsigned char) I2C_Read_Byte(address,regaddress);
}

void TCA9535WriteConfig(TCA9535Regs * Regs)
{
	I2C_Write(2, TCA9535_ADDRESS, TCA9535_CONFIG_REG0, (unsigned char*)&Regs->Config, 0);
}

void TCA9535WriteOutput(TCA9535Regs * Regs)
{

	I2C_Write(2, TCA9535_ADDRESS, TCA9535_OUTPUT_REG0, (unsigned char*)&Regs->Output, 0);
}

void TCA9535WritePolarity(TCA9535Regs * Regs)
{

	I2C_Write(2, TCA9535_ADDRESS, TCA9535_POLARITY_REG0, (unsigned char*)&Regs->PolarityInversion, 0);
}



