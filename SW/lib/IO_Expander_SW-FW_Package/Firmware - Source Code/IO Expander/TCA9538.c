#include "TCA9538.h"
#include "USCI_I2C.h"
#include "BoosterPack.h"
//unsigned char convertArray[2];

extern unsigned char NACK;

// ****************************************************************************
//! @fn          void TCA9538InitDefault(TCA9538Regs* Regs)
//! @brief
//!				 Initializes the confRegs structure which is
//!              a local mirror of the TPL7200 config registers
//!              additional TPL7200writeConfigRegisters(confRegs) function call
//! 			 is needed in order to get the TPL7200 registers updated
//!
//! TODO 		 Implement I2C return (success/failure)
// ****************************************************************************
void TCA9538InitDefault(TCA9538Regs* Regs){
	Regs->Output.all = 0xFF;
	Regs->PolarityInversion.all = 0x00;
	Regs->Config.all = 0x00;
}


// ****************************************************************************
//! @fn          void TCA9538InitI2CReg(TCA9538Regs* Regs)
//! @brief
//!
//! TODO 		 Implement I2C return (success/failure)
// ****************************************************************************
unsigned char TCA9538InitI2CReg(TCA9538Regs* Regs){
	unsigned char return_Value = I2C_OPERATION_SUCCESSFUL;

	I2C_Write_Byte(TCA9538_ADDRESS, TCA9538_CONFIG_REG, Regs->Config.all);
	I2C_Write_Byte(TCA9538_ADDRESS, TCA9538_OUTPUT_REG, Regs->Output.all);
	I2C_Write_Byte(TCA9538_ADDRESS, TCA9538_POLARITY_REG, Regs->PolarityInversion.all);
	if(NACK)
	{
		NACK = 0;

		return_Value = I2C_OPERATION_FAIL;
	}

	return return_Value;
}

// ****************************************************************************
//! @fn          void TCA9538ReadInputReg(TCA9538Regs* Regs)
//! @brief
//!
//! TODO 		 Implement I2C return (success/failure)
// ****************************************************************************
void TCA9538ReadInputReg(TCA9538Regs* Regs){

	Regs->Input.all = (unsigned char) I2C_Read_Byte(TCA9538_ADDRESS, TCA9538_INPUT_REG);
	//Regs->Input.all = read_Buffer[1]<<8 + read_Buffer[0];
}


// ****************************************************************************
//! @fn          void TCA9538InitI2CReg(TCA9538Regs* Regs)
//! @brief
//!
//! TODO 		 Implement I2C return (success/failure)
// ****************************************************************************
void TCA9538WriteReg(unsigned char address, unsigned char regaddress, unsigned short regVal)
{
	//I2C_Write(2, address, regaddress, (regVal), 0);
	if(NACK)
	{


	}

}

unsigned char TCA9538ReadReg(unsigned char address, unsigned char regaddress)
{
	return (unsigned char) I2C_Read_Byte(address,regaddress);
}

void TCA9538WriteConfig(TCA9538Regs * Regs)
{
	unsigned char write_Buffer[1];
	write_Buffer[0] = Regs->Config.all;

	I2C_Write(1, TCA9538_ADDRESS, TCA9538_CONFIG_REG, write_Buffer, 0);
}

void TCA9538WriteOutput(TCA9538Regs * Regs)
{
	unsigned char write_Buffer[1];
	write_Buffer[0] = Regs->Output.all;

	I2C_Write(1, TCA9538_ADDRESS, TCA9538_OUTPUT_REG, write_Buffer, 0);
}

void TCA9538WritePolarity(TCA9538Regs * Regs)
{
	unsigned char write_Buffer[1];
	write_Buffer[0] = Regs->PolarityInversion.all;

	I2C_Write(1, TCA9538_ADDRESS, TCA9538_POLARITY_REG, write_Buffer, 0);
}

