#include "TCA9554.h"
#include "USCI_I2C.h"
#include "BoosterPack.h"
//unsigned char convertArray[2];

extern unsigned char NACK;

// ****************************************************************************
//! @fn          void TCA9554InitDefault(TCA9554Regs* Regs)
//! @brief
//!				 Initializes the confRegs structure which is
//!              a local mirror of the TPL7200 config registers
//!              additional TPL7200writeConfigRegisters(confRegs) function call
//! 			 is needed in order to get the TPL7200 registers updated
//!
//! TODO 		 Implement I2C return (success/failure)
// ****************************************************************************
void TCA9554InitDefault(TCA9554Regs* Regs){
	Regs->Output.all = 0xFF;
	Regs->PolarityInversion.all = 0x00;
	Regs->Config.all = 0x00;
}


// ****************************************************************************
//! @fn          void TCA9554InitI2CReg(TCA9554Regs* Regs)
//! @brief
//!
//! TODO 		 Implement I2C return (success/failure)
// ****************************************************************************
unsigned char TCA9554InitI2CReg(TCA9554Regs* Regs){
	unsigned char return_Value = I2C_OPERATION_SUCCESSFUL;

	I2C_Write_Byte(TCA9554_ADDRESS, TCA9554_CONFIG_REG, Regs->Config.all);
	I2C_Write_Byte(TCA9554_ADDRESS, TCA9554_OUTPUT_REG, Regs->Output.all);
	I2C_Write_Byte(TCA9554_ADDRESS, TCA9554_POLARITY_REG, Regs->PolarityInversion.all);
	if(NACK)
	{
		NACK = 0;

		return_Value = I2C_OPERATION_FAIL;
	}

	return return_Value;
}

// ****************************************************************************
//! @fn          void TCA9554ReadInputReg(TCA9554Regs* Regs)
//! @brief
//!
//! TODO 		 Implement I2C return (success/failure)
// ****************************************************************************
void TCA9554ReadInputReg(TCA9554Regs* Regs){

	Regs->Input.all = (unsigned char) I2C_Read_Byte(TCA9554_ADDRESS, TCA9554_INPUT_REG);
	//Regs->Input.all = read_Buffer[1]<<8 + read_Buffer[0];
}


// ****************************************************************************
//! @fn          void TCA9554InitI2CReg(TCA9554Regs* Regs)
//! @brief
//!
//! TODO 		 Implement I2C return (success/failure)
// ****************************************************************************
void TCA9554WriteReg(unsigned char address, unsigned char regaddress, unsigned short regVal)
{
	//I2C_Write(2, address, regaddress, (regVal), 0);
	if(NACK)
	{


	}

}

unsigned char TCA9554ReadReg(unsigned char address, unsigned char regaddress)
{
	return (unsigned char) I2C_Read_Byte(address,regaddress);
}

void TCA9554WriteConfig(TCA9554Regs * Regs)
{
	unsigned char write_Buffer[1];
	write_Buffer[0] = Regs->Config.all;

	I2C_Write(1, TCA9554_ADDRESS, TCA9554_CONFIG_REG, write_Buffer, 0);
}

void TCA9554WriteOutput(TCA9554Regs * Regs)
{
	unsigned char write_Buffer[1];
	write_Buffer[0] = Regs->Output.all;

	I2C_Write(1, TCA9554_ADDRESS, TCA9554_OUTPUT_REG, write_Buffer, 0);
}

void TCA9554WritePolarity(TCA9554Regs * Regs)
{
	unsigned char write_Buffer[1];
	write_Buffer[0] = Regs->PolarityInversion.all;

	I2C_Write(1, TCA9554_ADDRESS, TCA9554_POLARITY_REG, write_Buffer, 0);
}

