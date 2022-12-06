/*******************************************************************************
*       boosterPack.h Header file for TCA7313 & TCA6507 boosterpack EVM        *
*                                                                              *
*       Author:             Chris Kraft                                        *
*                                                                              *
*       Revision Date:      NOV 2012                                           *
*                                                                              *
*       Revision Level:     00.01                                              *
*                                                                              *
*                                                                              *
********************************************************************************
* Copyright © 20011-2012 Texas Instruments Incorporated - http://www.ti.com/    *
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
*       Date Changed:             11/7/12	                                   *
*       Developer:                Chris Kraft	                               *
*       Change Description:       Initial creation							   *
*       																	   *
*                                                                              *
*******************************************************************************/

/*******************************************************************************
*                                 Definitions                                  *
*******************************************************************************/
#define wake_INT_08 0x01
#define wake_TCA6408A 0x02
#define wake_TCA6416A 0x04
#define wake_TCA6424A 0x08
#define wake_TCA9535 0x10
#define wake_TCA9539 0x20
#define wake_TCA9554A 0x40
#define wake_INT_24 0x80
#define wake_INT_16 0x100
#define wake_TCA9554 0x200
#define wake_TCA9538 0x400 //Added by Brian Berner 7/23
#define UART_GUI_Update_1 0xDF
#define UART_GUI_Update_2 0xDE
//#define DEMO_FLAG 0x80 //Demo flag not used for this EVM


//------My defines-------
//Port
#define PORT0 0x00
#define PORT1 0x01
#define PORT2 0x02
//Device ID

enum device_IDs{
	TCA6408A = 0x00,
	TCA6416A,
	TCA6424A,
	TCA9535,
	TCA9539,
	TCA9554A,
	TCA9554,
	TCA9538 //Added by Brian Berner 7/23
};



/*#define TCA6408A 0x00
#define TCA6416A 0x01
#define TCA6424A 0x02
#define TCA9535 0x03
#define TCA9539 0x04
#define TCA9554A 0x05*/
//Register

enum IO_Registers{
	Config_Reg = 0x00,
	Output_Reg,
	Polarity_Reg,
	I2C_Address_Reg
};

/*#define Config_Reg		0x00
#define Output_Reg		0x01
#define Polarity_Reg	0x02
#define I2C_Address_Reg	0x03*/
//----------------------------

#define UART_RECOVER_I2C 0x0A



typedef struct UARTin{
	unsigned char HighLow:1;
	unsigned char Register:2;
	unsigned char Device_ID:3;
	unsigned char Port:2;

} UartInput;


enum I2C_State{
	I2C_OPERATION_SUCCESSFUL =0,
	I2C_OPERATION_FAIL = 1

};


