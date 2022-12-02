/*******************************************************************************
*       main.c IO Expander example code for development		                   *
*                                                                              *
*       Author:             Chris Kraft                                        *
*                                                                              *
*       Revision Date:      APR 2013                                           *
*                                                                              *
*       Revision Level:     00.02                                              *
*                                                                              *
*                                                                              *
********************************************************************************
* Copyright © 2011-2012 Texas Instruments Incorporated - http://www.ti.com/    *
********************************************************************************
*  Redistribution and use in source and binary forms, with or without          *
*  modification, are permitted provided that the following conditions are met: *
*                                                                              *
*    Redistributions of source code must retain the above copyright notice,    *
*    this list of conditions and the following disclaimer.                     *
*                                                                              *
*    Redistributions in binary form must reproduce the above copyright notice, *
*    this list of conditions and the following disclaimer in the               *
*    documentation and/or other materials provided with the distribution.      *
*                                                                              *
*    Neither the name of Texas Instruments Incorporated nor the names of its   *
*    contributors may be used to endorse or promote products derived           *
*    from this software without specific prior written permission.             *
*                                                                              *
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" *
*  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   *
*  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *
*  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE    *
*  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR         *
*  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF        *
*  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    *
*  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN     *
*  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)     *
*  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *
*  POSSIBILITY OF SUCH DAMAGE.                                                 *
********************************************************************************
*                                 MODULE CHANGE LOG                            *
*                                                                              *
*       Date Changed:             2/5/13                                       *
*       Developer:                David Fischer	                               *
*       Change Description:       Initial creation							   *
*                                                       					   *
*                                                       					   *
*       Date Changed:			  4/1/13									   *
*       Developer:				  Chris Kraft								   *
*       Change Description:		  Added functionality for all devices		   *
*                                 Added interrupt functionality		           *
*                                 										       *
*                                                                              *
*******************************************************************************/
/*******************************************************************************
*                                 Included Headers                             *
*******************************************************************************/
#include "msp430g2553.h"
#include "USCI_I2C.h"
#include "TCA6408A.h"
#include "TCA6416A.h"
#include "TCA6424A.h"
#include "TCA9535.h"
#include "TCA9539.h"
#include "TCA9554A.h"
#include "TCA9554.h"
#include "TCA9538.h"
#include "BoosterPack.h"

/*******************************************************************************
*                                 Prototypes                                   *
*******************************************************************************/
void write_UART_byte(unsigned char byte);
void CLOCK_INIT(void);
void PORT_INIT(void);
void UART_I2C_INIT(void);
void run_Booster_Demo(void);

/*******************************************************************************
*                                 External Variables                           *
*******************************************************************************/
//NACK detected if equal to 1; I2C failed
extern unsigned char NACK;

/*******************************************************************************
*                                 Global Variables                             *
*******************************************************************************/
//UART input buffer
unsigned char input_buffer[40];
//Index for input_buffer[]
unsigned char input_Buffer_Counter = 0;
//Bytes to be read by UART
unsigned char UART_byte_count = 0;
//Waiting for flag detection on UART
unsigned char UART_FLAG = 1;
unsigned char FLAG=1;
//Byte tells CPU what to handle after wake
unsigned short wake_Flag=0;

//Global array to be used for I2C read/write
unsigned char array[45];
/*
//WDT_Count used for TCA7313 Blink flip
unsigned char WDT_count = 0;
*/
//Global variables to handle Demo mode
unsigned char demo_MODE = 0;
unsigned char demo_Count = 0;

//Global variables for UART_FLAG_BYTE info
unsigned char Reg = 0;
unsigned char Port = 0;
unsigned char READ_ALL = 0;
unsigned char CONFIG_DEVICE = 0;

unsigned char DeviceID = 0;

unsigned char errChck;

unsigned char installed_Device = 0;

volatile TCA6408ARegs TCA6408A_Reg_map;
volatile TCA6416ARegs TCA6416A_Reg_map;
volatile TCA6424ARegs TCA6424A_Reg_map;
volatile TCA9535Regs  TCA9535_Reg_map;
volatile TCA9539Regs  TCA9539_Reg_map;
volatile TCA9554ARegs TCA9554A_Reg_map;
volatile TCA9554Regs TCA9554_Reg_map;
volatile TCA9538Regs TCA9538_Reg_map;

volatile UartInput Uart_Flag;


unsigned char* Uart_flag_ptr = (unsigned char*)&Uart_Flag;



void main(void)
{
	WDTCTL = WDTPW + WDTHOLD;                 	// Stop WDT

	CLOCK_INIT();								// Configure clock to 8 MHz
	//__delay_cycles(32000000);						// Allow I2C devices time to power up
	PORT_INIT();								// Configure ports
	UART_I2C_INIT();							// Configure I2C
	P1OUT = 0;
	__delay_cycles(100000);						// Allow I2C devices time to power up
	P1OUT = BIT5;

	//__delay_cycles(100000);						// Allow I2C devices time to power up

	I2C_Write_Byte(0x23,0x00,0x00); //Dummy I2C write

	/***************Initialize register values into MSP430 Memory map**********************/
	TCA9535InitDefault((TCA9535Regs*)&TCA9535_Reg_map);
	TCA9539InitDefault((TCA9539Regs*)&TCA9539_Reg_map);
	TCA9554AInitDefault((TCA9554ARegs*)&TCA9554A_Reg_map);
	TCA9554InitDefault((TCA9554Regs*)&TCA9554_Reg_map);
	TCA6408AInitDefault((TCA6408ARegs*)&TCA6408A_Reg_map);
	TCA6416AInitDefault((TCA6416ARegs*)&TCA6416A_Reg_map);
	TCA6424AInitDefault((TCA6424ARegs*)&TCA6424A_Reg_map);
	TCA9538InitDefault((TCA9538Regs*)&TCA9538_Reg_map);



	/***************Write default values to TCA6424****************************************/
	TCA6424AInitI2CReg((TCA6424ARegs*)&TCA6424A_Reg_map);



	while(1)
	{
		_bis_SR_register(LPM0_bits + GIE);

		/**********************Handle TCA6424 Interrupt************************************/
		while(wake_Flag & wake_INT_24)
		{
			wake_Flag &= ~wake_INT_24;

			/**Continue reading input port register until INT pin returns HIGH*************/
			/**While loop used to prevent missed edge on INT********************************/
			//while(!(P2IN & BIT0))
			//{
				TCA6424AReadInputReg((TCA6424ARegs*)&TCA6424A_Reg_map);

				/*********ECHO Information back to GUI*********************************/
				write_UART_byte(UART_GUI_Update_2);
				write_UART_byte(TCA6424A_Reg_map.Input.Port.P0.all);
				write_UART_byte(TCA6424A_Reg_map.Input.Port.P1.all);
				write_UART_byte(TCA6424A_Reg_map.Input.Port.P2.all);
			//}

			P2IE |= BIT0;
		}

		/**********************Handle TCA6416,TCA9535,TCA9539 Interrupt************************************/
		while(wake_Flag & wake_INT_16)
		{

			wake_Flag &= ~wake_INT_16;
			P1IE |= BIT4;
			/**Continue reading input port register until INT pin returns HIGH*************/
			/**While loop used to prevent missed edge on INT********************************/
			//while(!(P1IN & BIT4))
			//{
				switch(installed_Device)
				{
						case TCA6416A:
										TCA6416AReadInputReg((TCA6416ARegs*)&TCA6416A_Reg_map);

										/*********ECHO Information back to GUI*********************************/
										write_UART_byte(UART_GUI_Update_1);
										write_UART_byte(TCA6416A_Reg_map.Input.Port.P0.all);
										write_UART_byte(TCA6416A_Reg_map.Input.Port.P1.all);
										break;
						case TCA9535:
										TCA9535ReadInputReg((TCA9535Regs*)&TCA9535_Reg_map);

										/*********ECHO Information back to GUI*********************************/
										write_UART_byte(UART_GUI_Update_1);
										write_UART_byte(TCA9535_Reg_map.Input.Port.P0.all);
										write_UART_byte(TCA9535_Reg_map.Input.Port.P1.all);
										break;
						case TCA9539:
										TCA9539ReadInputReg((TCA9539Regs*)&TCA9539_Reg_map);

										/*********ECHO Information back to GUI*********************************/
										write_UART_byte(UART_GUI_Update_1);
										write_UART_byte(TCA9539_Reg_map.Input.Port.P0.all);
										write_UART_byte(TCA9539_Reg_map.Input.Port.P1.all);
						default: break;
				}

			//}
		}

		/**********************Handle TCA6408A, TCA9554A & TCA9554 Interrupt************************************/
		while(wake_Flag & wake_INT_08)
		{
			wake_Flag &= ~wake_INT_08;

			/**Continue reading input port register until INT pin returns HIGH*************/
			/**While loop used to prevent missed edge on INT********************************/
			//while(!(P2IN & BIT2))
			//{
				if(installed_Device == TCA6408A)
				{
					TCA6408AReadInputReg((TCA6408ARegs*)&TCA6408A_Reg_map);
					/*********ECHO Information back to GUI*********************************/
					write_UART_byte(UART_GUI_Update_1);
					write_UART_byte(TCA6408A_Reg_map.Input.all);
					write_UART_byte(0x00);
				}
				else if(installed_Device == TCA9554A)
				{
					TCA9554AReadInputReg((TCA9554ARegs*)&TCA9554A_Reg_map);
					/*********ECHO Information back to GUI*********************************/
					write_UART_byte(UART_GUI_Update_1);
					write_UART_byte(TCA9554A_Reg_map.Input.all);
					write_UART_byte(0x00);
				}
				else if(installed_Device == TCA9538)
				{
					TCA9538ReadInputReg((TCA9538Regs*)&TCA9538_Reg_map);
					/*********ECHO Information back to GUI*********************************/
					write_UART_byte(UART_GUI_Update_1);
					write_UART_byte(TCA9538_Reg_map.Input.all);
					write_UART_byte(0x00);
				}
				else
				{
					TCA9554ReadInputReg((TCA9554Regs*)&TCA9554_Reg_map);
					/*********ECHO Information back to GUI*********************************/
					write_UART_byte(UART_GUI_Update_1);
					write_UART_byte(TCA9554_Reg_map.Input.all);
					write_UART_byte(0x00);
				}
				P2IE |= BIT2;
			//}

		}


		if (wake_Flag & wake_TCA6408A)
		{

			if (CONFIG_DEVICE) // GUI Requested setup for TCA6408A
			{
				errChck = TCA6408AInitI2CReg((TCA6408ARegs*)&TCA6408A_Reg_map);
				if(errChck != I2C_OPERATION_SUCCESSFUL)							// Check to see if no device ACK
				{
					__delay_cycles(10000);
					write_UART_byte(0xF1);										// Send failure Flag back to GUI
				}
				else
				{
					P2DIR &= ~BIT2;
					P1IE = 0;
					P2IFG = 0;
					P2IE = BIT0 + BIT2;
										// Enable interrupts on TCA6424A and TCA6408 pins
					installed_Device = TCA6408A;								// Set installed device to TCA6408A

				}



				CONFIG_DEVICE = 0;												// Clear config device flag
			}
			//TODO Complete read all registers
			else if (READ_ALL)
			{			}
			else
			{
				switch(Uart_Flag.Register) //Determine the Register change
				{
					case Config_Reg:
						if(Uart_Flag.HighLow)									// Determine if the bit is to be set or cleared.
						{
							TCA6408A_Reg_map.Config.all |= input_buffer[1];
						}
						else
						{
							TCA6408A_Reg_map.Config.all &= ~input_buffer[1];
						}
						TCA6408AWriteConfig((TCA6408ARegs*) &TCA6408A_Reg_map);
						break;
					case Output_Reg:
						if(Uart_Flag.HighLow)
						{
							TCA6408A_Reg_map.Output.all |= input_buffer[1];
						}
						else
						{
							TCA6408A_Reg_map.Output.all &= ~input_buffer[1];
						}
						TCA6408AWriteOutput((TCA6408ARegs*) &TCA6408A_Reg_map);
						break;
					case Polarity_Reg:
						if(Uart_Flag.HighLow)
						{
							TCA6408A_Reg_map.PolarityInversion.all |= input_buffer[1];
						}
						else
						{
							TCA6408A_Reg_map.PolarityInversion.all &= ~input_buffer[1];
						}
						TCA6408AWritePolarity((TCA6408ARegs*) &TCA6408A_Reg_map);

						//** Auto-Refresh the Inputs when Polarity Inversion bit is Toggled **//
						TCA6408AReadInputReg((TCA6408ARegs*)&TCA6408A_Reg_map);
						/*********ECHO Information back to GUI*********************************/
						write_UART_byte(UART_GUI_Update_1); //Updates the 1st page of the GUI
						write_UART_byte(TCA6408A_Reg_map.Input.all);
						write_UART_byte(0x00);

						break;
					case I2C_Address_Reg:	//Change the I2C Address of the device
						break;
					default:	break;
				}
			}
			wake_Flag &= ~wake_TCA6408A;
		}

		if (wake_Flag & wake_TCA6416A)
		{
			if (CONFIG_DEVICE)
			{
				P2DIR |= BIT2;
				errChck = TCA6416AInitI2CReg((TCA6416ARegs*)&TCA6416A_Reg_map);
				if(errChck != I2C_OPERATION_SUCCESSFUL)
				{
					write_UART_byte(0xF1);
				}
				else
				{
					P1IE = BIT4;
					P2IE = BIT0;
					//Enable correct port configuration for Interrupt
					// Change installed device variable
					installed_Device = TCA6416A;

				}



				CONFIG_DEVICE = 0;
			}
			else if (READ_ALL)
			{


			}
			else
			{
				switch(Uart_Flag.Register) //Determine the Register change
				{
					case Config_Reg:
						switch(Uart_Flag.Port)	//Switch on which port being addressed
						{
							case PORT0:	//Alter configuration of Port0
								if(Uart_Flag.HighLow)
								{
									TCA6416A_Reg_map.Config.Port.P0.all |= input_buffer[1];
								}
								else
								{
									TCA6416A_Reg_map.Config.Port.P0.all &= ~input_buffer[1];
								}
								break;
							case PORT1:
								if(Uart_Flag.HighLow)
								{
									TCA6416A_Reg_map.Config.Port.P1.all  |= input_buffer[1];
								}
								else
								{
									TCA6416A_Reg_map.Config.Port.P1.all &= ~input_buffer[1];
								}
								break;
							default:	break;
						}
						TCA6416AWriteConfig((TCA6416ARegs*) &TCA6416A_Reg_map);
						break;
					case Output_Reg:
						switch(Uart_Flag.Port)	//Switch on which port being addressed
						{
							case PORT0:	//Alter configuration of Port0
								if(Uart_Flag.HighLow)
								{
									TCA6416A_Reg_map.Output.Port.P0.all |= input_buffer[1];
								}
								else
								{
									TCA6416A_Reg_map.Output.Port.P0.all &= ~input_buffer[1];
								}
								break;
							case PORT1:
								if(Uart_Flag.HighLow)
								{
									TCA6416A_Reg_map.Output.Port.P1.all  |= input_buffer[1];
								}
								else
								{
									TCA6416A_Reg_map.Output.Port.P1.all &= ~input_buffer[1];
								}
								break;
							default:	break;
						}
						TCA6416AWriteOutput((TCA6416ARegs*) &TCA6416A_Reg_map);
						break;
					case Polarity_Reg:
						switch(Uart_Flag.Port)	//Switch on which port being addressed
						{
							case PORT0:
								if(Uart_Flag.HighLow)
								{
									TCA6416A_Reg_map.PolarityInversion.Port.P0.all |= input_buffer[1];
								}
								else
								{
									TCA6416A_Reg_map.PolarityInversion.Port.P0.all &= ~input_buffer[1];
								}
								break;
							case PORT1:
								if(Uart_Flag.HighLow)
								{
									TCA6416A_Reg_map.PolarityInversion.Port.P1.all |= input_buffer[1];
								}
								else
								{
									TCA6416A_Reg_map.PolarityInversion.Port.P1.all &= ~input_buffer[1];
								}
								break;
							default:	break;
						}
						TCA6416AWritePolarity((TCA6416ARegs*) &TCA6416A_Reg_map);

						//** Auto-Refresh the Inputs when Polarity Inversion bit is Toggled **//
						TCA6416AReadInputReg((TCA6416ARegs*)&TCA6416A_Reg_map);
						/*********ECHO Information back to GUI*********************************/
						write_UART_byte(UART_GUI_Update_1); //Updates the 1st page of the GUI
						write_UART_byte(TCA6416A_Reg_map.Input.all);
						write_UART_byte(0x00);

						break;
					case I2C_Address_Reg:	//Change the I2C Address of the device
						break;
					default:	break;
				}
			}
			wake_Flag &= ~wake_TCA6416A;
		}

		if (wake_Flag & wake_TCA6424A)
		{

			if (READ_ALL)
			{


			}
			else
			{
				switch(Uart_Flag.Register) //Determine the Register change
				{
					case Config_Reg:
						switch(Uart_Flag.Port)	//Switch on which port being addressed
						{
							case PORT0:	//Alter configuration of Port0
								if(Uart_Flag.HighLow)
								{
									TCA6424A_Reg_map.Config.Port.P0.all |= input_buffer[1];
								}
								else
								{
									 TCA6424A_Reg_map.Config.Port.P0.all &= ~input_buffer[1];
								}
								break;
							case PORT1:
								if(Uart_Flag.HighLow)
								{
									 TCA6424A_Reg_map.Config.Port.P1.all  |= input_buffer[1];
								}
								else
								{
									 TCA6424A_Reg_map.Config.Port.P1.all &= ~input_buffer[1];
								}
								break;
							case PORT2:
								if(Uart_Flag.HighLow)
								{
									 TCA6424A_Reg_map.Config.Port.P2.all |= input_buffer[1];
								}
								else
								{
									 TCA6424A_Reg_map.Config.Port.P2.all &= ~input_buffer[1];
								}
								break;
							default:	break;
						}
						TCA6424AWriteConfig((TCA6424ARegs*) &TCA6424A_Reg_map);
						break;
					case Output_Reg:
						switch(Uart_Flag.Port)	//Switch on which port being addressed
						{
							case PORT0:	//Alter configuration of Port0
								if(Uart_Flag.HighLow)
								{
									TCA6424A_Reg_map.Output.Port.P0.all |= input_buffer[1];
								}
								else
								{
									 TCA6424A_Reg_map.Output.Port.P0.all &= ~input_buffer[1];
								}
								break;
							case PORT1:
								if(Uart_Flag.HighLow)
								{
									 TCA6424A_Reg_map.Output.Port.P1.all  |= input_buffer[1];
								}
								else
								{
									 TCA6424A_Reg_map.Output.Port.P1.all &= ~input_buffer[1];
								}
								break;
							case PORT2:
								if(Uart_Flag.HighLow)
								{
									 TCA6424A_Reg_map.Output.Port.P2.all |= input_buffer[1];
								}
								else
								{
									 TCA6424A_Reg_map.Output.Port.P2.all &= ~input_buffer[1];
								}
							default:	break;
						}
						TCA6424AWriteOutput((TCA6424ARegs*) &TCA6424A_Reg_map);
						break;
					case Polarity_Reg:
						switch(Uart_Flag.Port)	//Switch on which port being addressed
						{
							case PORT0:
								if(Uart_Flag.HighLow)
								{
									TCA6424A_Reg_map.PolarityInversion.Port.P0.all |= input_buffer[1];
								}
								else
								{
									 TCA6424A_Reg_map.PolarityInversion.Port.P0.all &= ~input_buffer[1];
								}
								break;
							case PORT1:
								if(Uart_Flag.HighLow)
								{
									 TCA6424A_Reg_map.PolarityInversion.Port.P1.all  |= input_buffer[1];
								}
								else
								{
									 TCA6424A_Reg_map.PolarityInversion.Port.P1.all &= ~input_buffer[1];
								}
								break;
							case PORT2:
								if(Uart_Flag.HighLow)
								{
									 TCA6424A_Reg_map.PolarityInversion.Port.P2.all |= input_buffer[1];
								}
								else
								{
									 TCA6424A_Reg_map.PolarityInversion.Port.P2.all &= ~input_buffer[1];
								}
								break;
							default:	break;
						}
						TCA6424AWritePolarity((TCA6424ARegs*) &TCA6424A_Reg_map);

						//** Auto-Refresh the Inputs when Polarity Inversion bit is Toggled **//
						TCA6424AReadInputReg((TCA6424ARegs*)&TCA6424A_Reg_map);

						/*********ECHO Information back to GUI*********************************/
						write_UART_byte(UART_GUI_Update_2);
						write_UART_byte(TCA6424A_Reg_map.Input.Port.P0.all);
						write_UART_byte(TCA6424A_Reg_map.Input.Port.P1.all);
						write_UART_byte(TCA6424A_Reg_map.Input.Port.P2.all);
						break;
					case I2C_Address_Reg:	//Change the I2C Address of the device
						break;
					default:	break;
				}
			}
			wake_Flag &= ~wake_TCA6424A;
		}

		if (wake_Flag & wake_TCA9535)
		{
			if (CONFIG_DEVICE)
			{
				P2DIR |= BIT2;
				errChck = TCA9535InitI2CReg((TCA9535Regs*)&TCA9535_Reg_map);
				if(errChck != I2C_OPERATION_SUCCESSFUL)
				{
					write_UART_byte(0xF1);
				}
				else
				{
					P1IE = BIT4;
					P2IE = BIT0;
					//Enable correct port configuration for Interrupt
					// Change installed device variable
					installed_Device = TCA9535;

				}



				CONFIG_DEVICE = 0;
			}
			else if (READ_ALL)
			{


			}
			else
			{
				switch(Uart_Flag.Register) //Determine the Register change
				{
					case Config_Reg:
						switch(Uart_Flag.Port)	//Switch on which port being addressed
						{
							case PORT0:	//Alter configuration of Port0
								if(Uart_Flag.HighLow)
								{
									TCA9535_Reg_map.Config.Port.P0.all |= input_buffer[1];
								}
								else
								{
									TCA9535_Reg_map.Config.Port.P0.all &= ~input_buffer[1];
								}
								break;
							case PORT1:
								if(Uart_Flag.HighLow)
								{
									TCA9535_Reg_map.Config.Port.P1.all  |= input_buffer[1];
								}
								else
								{
									TCA9535_Reg_map.Config.Port.P1.all &= ~input_buffer[1];
								}
								break;
							default:	break;
						}
						TCA9535WriteConfig((TCA9535Regs*) &TCA9535_Reg_map);
						break;
					case Output_Reg:
						switch(Uart_Flag.Port)	//Switch on which port being addressed
						{
							case PORT0:	//Alter configuration of Port0
								if(Uart_Flag.HighLow)
								{
									TCA9535_Reg_map.Output.Port.P0.all |= input_buffer[1];
								}
								else
								{
									TCA9535_Reg_map.Output.Port.P0.all &= ~input_buffer[1];
								}
								break;
							case PORT1:
								if(Uart_Flag.HighLow)
								{
									TCA9535_Reg_map.Output.Port.P1.all  |= input_buffer[1];
								}
								else
								{
									TCA9535_Reg_map.Output.Port.P1.all &= ~input_buffer[1];
								}
								break;
							default:	break;
						}
						TCA9535WriteOutput((TCA9535Regs*) &TCA9535_Reg_map);
						if(NACK)
						{
							NACK = 0;

						}
						break;
					case Polarity_Reg:
						switch(Uart_Flag.Port)	//Switch on which port being addressed
						{
							case PORT0:
								if(Uart_Flag.HighLow)
								{
									TCA9535_Reg_map.PolarityInversion.Port.P0.all |= input_buffer[1];
								}
								else
								{
									TCA9535_Reg_map.PolarityInversion.Port.P0.all &= ~input_buffer[1];
								}
								break;
							case PORT1:
								if(Uart_Flag.HighLow)
								{
									TCA9535_Reg_map.PolarityInversion.Port.P1.all |= input_buffer[1];
								}
								else
								{
									TCA9535_Reg_map.PolarityInversion.Port.P1.all &= ~input_buffer[1];
								}
								break;
							default:	break;
						}
						TCA9535WritePolarity((TCA9535Regs*) &TCA9535_Reg_map);

						//** Auto-Refresh the Inputs when Polarity Inversion bit is Toggled **//
						TCA9535ReadInputReg((TCA9535Regs*)&TCA9535_Reg_map);
						/*********ECHO Information back to GUI*********************************/
						write_UART_byte(UART_GUI_Update_1); //Updates the 1st page of the GUI
						write_UART_byte(TCA9535_Reg_map.Input.all);
						write_UART_byte(0x00);

						break;
					case I2C_Address_Reg:	//Change the I2C Address of the device
						break;
					default:	break;
				}
			}
			wake_Flag &= ~wake_TCA9535;
		}

		if (wake_Flag & wake_TCA9539)
		{
			if (CONFIG_DEVICE)
			{
				P2DIR |= BIT2;
				errChck = TCA9539InitI2CReg((TCA9539Regs*)&TCA9539_Reg_map);
				if(errChck != I2C_OPERATION_SUCCESSFUL)
				{
					write_UART_byte(0xF1);
				}
				else
				{
					P1IE = BIT4;
					P2IE = BIT0;
					//Enable correct port configuration for Interrupt
					// Change installed device variable
					installed_Device = TCA9539;

				}



				CONFIG_DEVICE = 0;
			}
			else if (READ_ALL)
			{


			}
			else
			{
				switch(Uart_Flag.Register) //Determine the Register change
				{
					case Config_Reg:
						switch(Uart_Flag.Port)	//Switch on which port being addressed
						{
							case PORT0:	//Alter configuration of Port0
								if(Uart_Flag.HighLow)
								{
									TCA9539_Reg_map.Config.Port.P0.all |= input_buffer[1];
								}
								else
								{
									TCA9539_Reg_map.Config.Port.P0.all &= ~input_buffer[1];
								}
								break;
							case PORT1:
								if(Uart_Flag.HighLow)
								{
									TCA9539_Reg_map.Config.Port.P1.all  |= input_buffer[1];
								}
								else
								{
									TCA9539_Reg_map.Config.Port.P1.all &= ~input_buffer[1];
								}
								break;
							default:	break;
						}
						TCA9539WriteConfig((TCA9539Regs*) &TCA9539_Reg_map);
						break;
					case Output_Reg:
						switch(Uart_Flag.Port)	//Switch on which port being addressed
						{
							case PORT0:	//Alter configuration of Port0
								if(Uart_Flag.HighLow)
								{
									TCA9539_Reg_map.Output.Port.P0.all |= input_buffer[1];
								}
								else
								{
									TCA9539_Reg_map.Output.Port.P0.all &= ~input_buffer[1];
								}
								break;
							case PORT1:
								if(Uart_Flag.HighLow)
								{
									TCA9539_Reg_map.Output.Port.P1.all  |= input_buffer[1];
								}
								else
								{
									TCA9539_Reg_map.Output.Port.P1.all &= ~input_buffer[1];
								}
								break;
							default:	break;
						}
						TCA9539WriteOutput((TCA9539Regs*) &TCA9539_Reg_map);
						break;
					case Polarity_Reg:
						switch(Uart_Flag.Port)	//Switch on which port being addressed
						{
							case PORT0:
								if(Uart_Flag.HighLow)
								{
									TCA9539_Reg_map.PolarityInversion.Port.P0.all |= input_buffer[1];
								}
								else
								{
									TCA9539_Reg_map.PolarityInversion.Port.P0.all &= ~input_buffer[1];
								}
								break;
							case PORT1:
								if(Uart_Flag.HighLow)
								{
									TCA9539_Reg_map.PolarityInversion.Port.P1.all |= input_buffer[1];
								}
								else
								{
									TCA9539_Reg_map.PolarityInversion.Port.P1.all &= ~input_buffer[1];
								}
								break;
							default:	break;
						}
						TCA9539WritePolarity((TCA9539Regs*) &TCA9539_Reg_map);

						//** Auto-Refresh the Inputs when Polarity Inversion bit is Toggled **//
						TCA9539ReadInputReg((TCA9539Regs*)&TCA9539_Reg_map);
						/*********ECHO Information back to GUI*********************************/
						write_UART_byte(UART_GUI_Update_1); //Updates the 1st page of the GUI
						write_UART_byte(TCA9539_Reg_map.Input.Port.P0.all);
						write_UART_byte(TCA9539_Reg_map.Input.Port.P1.all);

						//P1IFG |= BIT4;
						break;
					case I2C_Address_Reg:	//Change the I2C Address of the device
						break;
					default:	break;
				}
			}
			wake_Flag &= ~wake_TCA9539;
		}

		if (wake_Flag & wake_TCA9554A)
		{
			if (CONFIG_DEVICE)
			{
				errChck = TCA9554AInitI2CReg((TCA9554ARegs*)&TCA9554A_Reg_map);
				if(errChck != I2C_OPERATION_SUCCESSFUL)
				{
					write_UART_byte(0xF1);
				}
				else
				{
					P2DIR &= ~BIT2;
					P1IE = 0;
					P2IFG = 0;
					P2IE = BIT0 + BIT2;

					//Enable correct port configuration for Interrupt
					// Change installed device variable
					installed_Device = TCA9554A;

				}



				CONFIG_DEVICE = 0;
			}
			else if (READ_ALL)
			{


			}
			else
			{
				switch(Uart_Flag.Register) //Determine the Register change
				{
					case Config_Reg:
						if(Uart_Flag.HighLow)
						{
							TCA9554A_Reg_map.Config.all |= input_buffer[1];
						}
						else
						{
							TCA9554A_Reg_map.Config.all &= ~input_buffer[1];
						}
						TCA9554AWriteConfig((TCA9554ARegs*) &TCA9554A_Reg_map);
						break;
					case Output_Reg:
						if(Uart_Flag.HighLow)
						{
							TCA9554A_Reg_map.Output.all |= input_buffer[1];
						}
						else
						{
							TCA9554A_Reg_map.Output.all &= ~input_buffer[1];
						}
						TCA9554AWriteOutput((TCA9554ARegs*) &TCA9554A_Reg_map);
						break;
					case Polarity_Reg:
						if(Uart_Flag.HighLow)
						{
							TCA9554A_Reg_map.PolarityInversion.all |= input_buffer[1];
						}
						else
						{
							TCA9554A_Reg_map.PolarityInversion.all &= ~input_buffer[1];
						}
						TCA9554AWritePolarity((TCA9554ARegs*) &TCA9554A_Reg_map);

						//** Auto-Refresh the Inputs when Polarity Inversion bit is Toggled **//
						TCA9554AReadInputReg((TCA9554ARegs*)&TCA9554A_Reg_map);
						/*********ECHO Information back to GUI*********************************/
						write_UART_byte(UART_GUI_Update_1); //Updates the 1st page of the GUI
						write_UART_byte(TCA9554A_Reg_map.Input.all);
						write_UART_byte(0x00);

						break;
					case I2C_Address_Reg:	//Change the I2C Address of the device
						break;
					default:	break;
				}
			}
			wake_Flag &= ~wake_TCA9554A;
		}

		if (wake_Flag & wake_TCA9554)
		{
			if (CONFIG_DEVICE)
			{
				errChck = TCA9554InitI2CReg((TCA9554Regs*)&TCA9554_Reg_map);
				if(errChck != I2C_OPERATION_SUCCESSFUL)
				{
					write_UART_byte(0xF1);
				}
				else
				{
					P2DIR &= ~BIT2;
					P1IE = 0;
					P2IFG = 0;
					P2IE = BIT0 + BIT2;
					//Enable correct port configuration for Interrupt
					// Change installed device variable
					installed_Device = TCA9554;

				}



				CONFIG_DEVICE = 0;
			}
			else if (READ_ALL)
			{


			}
			else
			{
				switch(Uart_Flag.Register) //Determine the Register change
				{
					case Config_Reg:
						if(Uart_Flag.HighLow)
						{
							TCA9554_Reg_map.Config.all |= input_buffer[1];
						}
						else
						{
							TCA9554_Reg_map.Config.all &= ~input_buffer[1];
						}
						TCA9554WriteConfig((TCA9554Regs*) &TCA9554_Reg_map);
						break;
					case Output_Reg:
						if(Uart_Flag.HighLow)
						{
							TCA9554_Reg_map.Output.all |= input_buffer[1];
						}
						else
						{
							TCA9554_Reg_map.Output.all &= ~input_buffer[1];
						}
						TCA9554WriteOutput((TCA9554Regs*) &TCA9554_Reg_map);
						break;
					case Polarity_Reg:
						if(Uart_Flag.HighLow)
						{
							TCA9554_Reg_map.PolarityInversion.all |= input_buffer[1];
						}
						else
						{
							TCA9554_Reg_map.PolarityInversion.all &= ~input_buffer[1];
						}
						TCA9554WritePolarity((TCA9554Regs*) &TCA9554_Reg_map);

						//** Auto-Refresh the Inputs when Polarity Inversion bit is Toggled **//
						TCA9554ReadInputReg((TCA9554Regs*)&TCA9554_Reg_map);
						/*********ECHO Information back to GUI*********************************/
						write_UART_byte(UART_GUI_Update_1); //Updates the 1st page of the GUI
						write_UART_byte(TCA9554_Reg_map.Input.all);
						write_UART_byte(0x00);

						break;
					case I2C_Address_Reg:	//Change the I2C Address of the device
						break;
					default:	break;
				}
			}
			wake_Flag &= ~wake_TCA9554;
		}
		if (wake_Flag & wake_TCA9538) //Added by Brian Berner 7/23
		{
			if (CONFIG_DEVICE)
			{
				errChck = TCA9538InitI2CReg((TCA9538Regs*)&TCA9538_Reg_map);
				if(errChck != I2C_OPERATION_SUCCESSFUL)
				{
					write_UART_byte(0xF1);
				}
				else
				{
					P2DIR &= ~BIT2;
					P1IE = 0;
					P2IFG = 0;
					P2IE = BIT0 + BIT2;
					//Enable correct port configuration for Interrupt
					// Change installed device variable
					installed_Device = TCA9538;

				}



				CONFIG_DEVICE = 0;
			}
			else if (READ_ALL)
			{


			}
			else
			{
				switch(Uart_Flag.Register) //Determine the Register change
				{
					case Config_Reg:
						if(Uart_Flag.HighLow)
						{
							TCA9538_Reg_map.Config.all |= input_buffer[1];
						}
						else
						{
							TCA9538_Reg_map.Config.all &= ~input_buffer[1];
						}
						TCA9538WriteConfig((TCA9538Regs*) &TCA9538_Reg_map);
						break;
					case Output_Reg:
						if(Uart_Flag.HighLow)
						{
							TCA9538_Reg_map.Output.all |= input_buffer[1];
						}
						else
						{
							TCA9538_Reg_map.Output.all &= ~input_buffer[1];
						}
						TCA9538WriteOutput((TCA9538Regs*) &TCA9538_Reg_map);
						break;
					case Polarity_Reg:
						if(Uart_Flag.HighLow)
						{
							TCA9538_Reg_map.PolarityInversion.all |= input_buffer[1];
						}
						else
						{
							TCA9538_Reg_map.PolarityInversion.all &= ~input_buffer[1];
						}
						TCA9538WritePolarity((TCA9538Regs*) &TCA9538_Reg_map);

						//** Auto-Refresh the Inputs when Polarity Inversion bit is Toggled **//
						TCA9538ReadInputReg((TCA9538Regs*)&TCA9538_Reg_map);
						/*********ECHO Information back to GUI*********************************/
						write_UART_byte(UART_GUI_Update_1); //Updates the 1st page of the GUI
						write_UART_byte(TCA9538_Reg_map.Input.all);
						write_UART_byte(0x00);

						break;
					case I2C_Address_Reg:	//Change the I2C Address of the device
						break;
					default:	break;
				}
			}
			wake_Flag &= ~wake_TCA9538;
		}

	}


}

void write_UART_byte(unsigned char byte)
{
	while(!(IFG2&UCA0TXIFG));
	UCA0TXBUF = byte;
}




void CLOCK_INIT(void)
{
	BCSCTL2 = SELM_0 + DIVM_0 + DIVS_0;

	if (CALBC1_8MHZ != 0xFF)
	{
		/* Adjust this accordingly to your VCC rise time */
		__delay_cycles(100000);
		// Follow recommended flow. First, clear all DCOx and MODx bits. Then
		// apply new RSELx values. Finally, apply new DCOx and MODx bit values.
		DCOCTL = 0x00;
		BCSCTL1 = CALBC1_8MHZ;      							/* Set DCO to 8MHz */
		DCOCTL = CALDCO_8MHZ;
	}

	BCSCTL1 |= XT2OFF + DIVA_0;
	BCSCTL3 = XT2S_0 + LFXT1S_2 + XCAP_1;
}

void PORT_INIT(void)
{
	// P1.1 = RXD, P1.2=TXD P1.7=SDA P1.6=SCL
	P1SEL 	= BIT1 + BIT2 + BIT6 + BIT7;
	P1SEL2 	= BIT1 + BIT2 + BIT6 + BIT7;

	// Red LED on launchpad set to output P1.4 EN set to output
	P1DIR = BIT0 + BIT5;
	P1OUT = BIT5;

	P2DIR = BIT2 + BIT3;
	P2OUT = 	   BIT3;

	P1IES 	|= BIT4;
	P2IES 	|= BIT0 + BIT2;


	P2IE 	|= BIT0;
}

void UART_I2C_INIT(void)
{
	UCA0CTL1 |= UCSSEL_2 + UCSWRST;
	UCA0BR0 = 0x41;
	UCA0BR1 = 0x03;
	UCA0MCTL = UCBRS2 + UCBRS0;
	UCA0CTL1 &= ~UCSWRST;

	//Set UCSWRST to configure I2C bus
	UCB0CTL1 |= UCSWRST;

	//I2C, synchronous master mode
	UCB0CTL0 = UCMST + UCMODE_3 + UCSYNC;

	//Use 8MHz SMCLK
	UCB0CTL1 = UCSSEL_2 + UCSWRST;

	//Set Bitrate register 8MHz/20 = 400kHz
	UCB0BR0 = 80;

	//Reset UCSWRST to enable I2C communication
	UCB0CTL1 &= ~UCSWRST;

	// Enable USCI_A0 RX interrupt
	IE2 |= UCA0RXIE;
}

/*******************************************************
 * 		   Interrupt service routine for UART          *
 *-----------------------------------------------------*
 * Decodes serial flags and stores the resulting bytes *
 * into the array input_buffer[].					   *
 * 													   *
 * Also determines if the I2C transmission NACKed due  *
 * to a not acknowledge bit detection				   *
 *******************************************************/
#pragma vector=USCIAB0RX_VECTOR
__interrupt void USCI0RX_ISR(void)
{
	//Interrupt flagged due to UART event
	if(!(UCB0STAT & UCNACKIFG))
	{
		//Store input byte from UART receive buffer
		unsigned char UART_BYTE = UCA0RXBUF;


		//UART flag detection
		if(FLAG)
		{

			//Set number of Data Bytes coming in -1
			UART_byte_count = 0;

			// Reset UART flag
			FLAG = 0;

			// store flag byte in input_buffer[0]
			input_buffer[0] = UART_BYTE;
			*Uart_flag_ptr = UART_BYTE;
			if (Uart_Flag.Port==3) //change this
			{
				if(Uart_Flag.HighLow)
				{
					CONFIG_DEVICE = 1;
				}
				else
					READ_ALL = 1;

			}
		}
		else
		{
			//Fill the input buffer with the data bytes
			input_buffer[1] = UART_BYTE;

			FLAG = 1;

			switch (Uart_Flag.Device_ID)
			{
				case TCA6408A:
					wake_Flag |= wake_TCA6408A;
					break;
				case TCA6416A:
					wake_Flag |= wake_TCA6416A;
					break;
				case TCA6424A:
					wake_Flag |= wake_TCA6424A;
					break;
				case TCA9535:
					wake_Flag |= wake_TCA9535;
					break;
				case TCA9539:
					wake_Flag |= wake_TCA9539;
					break;
				case TCA9554A:
					wake_Flag |= wake_TCA9554A;
					break;
				case TCA9554:
					wake_Flag |= wake_TCA9554;
					break;
				case TCA9538: //Added by Brian Berner 7/23
					wake_Flag |= wake_TCA9538;
					break;
				default:  break;
			}

			_bic_SR_register_on_exit(LPM0_bits);


		}
	}
	else
	{
		UCB0STAT &= ~UCNACKIFG;
		UCB0I2CIE &= ~UCNACKIE;
		NACK = 1;
		_bic_SR_register_on_exit(LPM0_bits);
	}

}

/*******************************************************
 * 		   Interrupt service routine for PORT1         *
 *-----------------------------------------------------*
 * 	Used to detect INT for TCA6408A                    *
 * 	INT needs to be connected to P1.4 and through 10kOhm*
 * 	pull-up resistor to VCC to work correctly		   *
 *******************************************************/
#pragma vector=PORT1_VECTOR
__interrupt void PORT1_ISR_HOOK(void)
{
	P1IE &= ~BIT4;
	P1IFG &= ~BIT4;
	wake_Flag |= wake_INT_16;
	_bic_SR_register_on_exit(LPM0_bits);
}

#pragma vector=PORT2_VECTOR
__interrupt void PORT2_ISR_HOOK(void)
{
	if(P2IFG & BIT0)
	{
		P2IE &= ~BIT0;
		P2IFG &= ~BIT0;
		wake_Flag |= wake_INT_24;
	}
	else
	{
		P2IE &= ~BIT2;
		P2IFG &= ~BIT2;
		wake_Flag |= wake_INT_08;
	}


	_bic_SR_register_on_exit(LPM0_bits);
}


/*******************************************************
 * 		   Interrupt service routine for USCI          *
 *-----------------------------------------------------*
 * 	I2C interrupt routines for Transmit and Receive	   *
 *******************************************************/
#pragma vector=USCIAB0TX_VECTOR
__interrupt void USCI0TX_ISR_HOOK(void)
{
	unsigned short lowPowerBits = 0;

    if (IFG2 & UCB0TXIFG) {
		/* USCI_B0 Transmit Interrupt Handler */
		lowPowerBits = USCIAB0TX_ISR();

		/* Exit low power mode based on return bits */
		_bic_SR_register_on_exit(lowPowerBits);
    }
    else {
		/* USCI_B0 Receive Interrupt Handler */
		USCIAB0RX_ISR();

		/* Enter active mode on exit */
		_bic_SR_register_on_exit(LPM4_bits);
    }
}

/*******************************************************
 * 		   Interrupt service routine for WDT           *
 *-----------------------------------------------------*
 * Used for demo mode of the boosterPack         	   *
 *******************************************************/
#pragma vector=WDT_VECTOR
__interrupt void WDT_ISR_HOOK(void)
{
	//wake_Flag |= WDT_FLAG;
	_bic_SR_register_on_exit(LPM0_bits);
}
