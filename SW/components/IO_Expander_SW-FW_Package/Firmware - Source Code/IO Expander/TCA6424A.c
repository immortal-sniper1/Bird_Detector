#include "TCA6424A.h"
#include "USCI_I2C.h"



extern unsigned char NACK;

// ****************************************************************************
//! @fn          void TCA6424AInitDefault(TCA6424ARegs* Regs)
//! @brief
//!				 Initializes the confRegs structure which is
//!              a local mirror of the TPL7200 config registers
//!              additional TPL7200writeConfigRegisters(confRegs) function call
//! 			 is needed in order to get the TPL7200 registers updated
//!
//! TODO 		 Implement I2C return (success/failure)
// ****************************************************************************
void TCA6424AInitDefault(TCA6424ARegs* Regs){
	Regs->Output.all = 0x00FFFFFF;
	Regs->PolarityInversion.all = 0x00000000;
	Regs->Config.all = 0x00000000;
}


// ****************************************************************************
//! @fn          void TCA6424AInitI2CReg(TCA6424ARegs* Regs)
//! @brief
//!
//! TODO 		 Implement I2C return (success/failure)
// ****************************************************************************
void TCA6424AInitI2CReg(TCA6424ARegs* Regs){
	I2C_Write(3, TCA6424A_ADDRESS, TCA6424A_POLARITY_REG0 | 0x80, (unsigned char*)&Regs->PolarityInversion, 0);
	I2C_Write(3, TCA6424A_ADDRESS, TCA6424A_CONFIG_REG0 | 0x80, (unsigned char*)&Regs->Config, 0);
	I2C_Write(3, TCA6424A_ADDRESS, TCA6424A_OUTPUT_REG0 | 0x80, (unsigned char*)&Regs->Output, 0);

}

// ****************************************************************************
//! @fn          void TCA6424AReadInputReg(TCA6424ARegs* Regs)
//! @brief
//!
//! TODO 		 Implement I2C return (success/failure)
// ****************************************************************************
void TCA6424AReadInputReg(TCA6424ARegs* Regs)
{
	I2C_Read(3,TCA6424A_ADDRESS, TCA6424A_INPUT_REG0 | 0x80, (unsigned char *)&Regs->Input);
}


// ****************************************************************************
//! @fn          void TCA6424AInitI2CReg(TCA6424ARegs* Regs)
//! @brief
//!
//! TODO 		 Implement I2C return (success/failure)
// ****************************************************************************
void TCA6424AWriteReg(unsigned char regaddress, unsigned char regVal)
{
	I2C_Write_Byte(TCA6424A_ADDRESS, regaddress, regVal);
	if(NACK)
	{
		//handle I2C failure later

	}

}

unsigned char TCA6424AReadReg(unsigned char address, unsigned char regaddress)
{
	return (unsigned char) I2C_Read_Byte(address,regaddress);
}

void TCA6424AWriteConfig(TCA6424ARegs * Regs)
{
	I2C_Write(3, TCA6424A_ADDRESS, TCA6424A_CONFIG_REG0 | 0x80, (unsigned char*)&Regs->Config, 0);
}

void TCA6424AWriteOutput(TCA6424ARegs * Regs)
{
	I2C_Write(3, TCA6424A_ADDRESS, TCA6424A_OUTPUT_REG0 | 0x80, (unsigned char*)&Regs->Output, 0);
}

void TCA6424AWritePolarity(TCA6424ARegs * Regs)
{
	I2C_Write(3, TCA6424A_ADDRESS, TCA6424A_POLARITY_REG0 | 0x80, (unsigned char*)&Regs->PolarityInversion, 0);
}



