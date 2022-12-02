/*******************************************************************************
*       USCI_I2C.c Set's up the MSP430 uC USCI in I2C mode.                    *
*                                                                              *
*       Author:             William Goh                                        *
*                                                                              *
*       Revision Date:      May 2011                                           *
*                                                                              *
*       Revision Level:     00.02                                              *
*                                                                              *
*       For Support:        https://e2e.ti.com/support/development_tools/mavrk/default.aspx*
*                                                                              *
********************************************************************************
* Copyright © 2009-2010 Texas Instruments Incorporated - http://www.ti.com/    *
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
*       Date Changed:             05/26/11                                     *
*       Developer:                William Goh                                  *
*       Change Description:       Initial creation							   *
*       																	   *
*       Date Changed:			  07/19/12									   *
*       Developer:				  Chris Kraft								   *
*       Change Description:		  Added NACK detection and recovery			   *
*       						  Added functionality for "infinite" # read	   *
*       						  and write	bytes							   *
*                              												   *
*                                                                              *
*******************************************************************************/
/*******************************************************************************
*                                 Included Headers                             *
*******************************************************************************/
#include "USCI_I2C.h"                       // Definition Files for USCI I2C module

/*******************************************************************************
*                                 Prototypes                                   *
*******************************************************************************/
// I2C write init
void I2CWriteInit(void);
// I2C read init
void I2CReadInit(void);

/*******************************************************************************
*                                 External Variables                           *
*******************************************************************************/

/*******************************************************************************
*                                 Global Variables                             *
*******************************************************************************/

// Transmit size pointer
int PtrTransmit;
// I2C transmit buffer array
unsigned char I2CBufferArray[100];
// I2C receive buffer
unsigned char I2CBuffer;
// fail gets set by USCIAB0RX_VECTOR if a NACK is detected
unsigned char NACK=0;

unsigned int I2C_Read_Byte ( unsigned char Slave_Address, unsigned char Register_Address)
{
    // Variable for transmitted data
    unsigned int MST_Data = 0;

    // Wait until I2C module has finished all operations
    while (UCB0STAT & UCBUSY);
	

    // Set slave address
    UCB0I2CSA  = Slave_Address;

    // Set register address
    I2CBufferArray[0] = Register_Address;
    // set I2CBufferArray Pointer
    PtrTransmit = 0;

    // Configure Write Address first
    I2CWriteInit();
    // Start condition generation => I2C communication is started
    UCB0CTL1 |= UCTXSTT;

    // Enable interrupts without entering LPM0.
    __bis_SR_register(GIE);
    // Wait till bus is free.

	while (UCB0STAT & UCBUSY);

	// Configure Read Data byte
	I2CReadInit();
	UCB0I2CIE |= UCNACKIE;
	// I2C restart condition
	UCB0CTL1 |= UCTXSTT;
		// Wait till Start condition sent
	while((UCB0CTL1 & UCTXSTT) && NACK==0);

	//Reading a byte, send stop bit immediately

	// I2C stop condition
	UCB0CTL1 |= UCTXSTP;

	// Enter LPM0 w/ interrupts only if ACK was received
	if(!(UCB0STAT & UCNACKIFG))
		__bis_SR_register(LPM0_bits + GIE);
	// Receive the byte
	MST_Data = I2CBuffer;

    // Ensure stop condition got sent
    while(UCB0CTL1 & UCTXSTP);

    // Return word
    return MST_Data;
}

void I2C_Read (unsigned char byte_Count, unsigned char Slave_Address, unsigned char Register_Address, unsigned char* read_buffer)
{
    unsigned char index_Count = 1;
    // Wait until I2C module has finished all operations
    while (UCB0STAT & UCBUSY);

    // Set slave address
    UCB0I2CSA  = Slave_Address;

    // Set register address
    I2CBufferArray[0] = Register_Address;
    // set I2CBufferArray Pointer
    PtrTransmit = 0;

    // Configure Write Address first
    I2CWriteInit();
    // Start condition generation => I2C communication is started
    UCB0CTL1 |= UCTXSTT;

    // Enable interrupts without entering LPM0.
    _bis_SR_register(GIE);
    // Wait till bus is free.

	while (UCB0STAT & UCBUSY);

	// Configure Read Data byte
	I2CReadInit();
	UCB0I2CIE |= UCNACKIE;
	// I2C restart condition
	UCB0CTL1 |= UCTXSTT;
	// Wait till Start condition sent exit if NACK
	while((UCB0CTL1 & UCTXSTT)&& !NACK);

	// If Reading one byte, send stop bit immediately
	if (byte_Count == 1)
	{
		// I2C stop condition
		UCB0CTL1 |= UCTXSTP;
	}
	// Enter LPM0 w/ interrupts if ACK was received
	if(!(UCB0STAT & UCNACKIFG))
		_bis_SR_register(LPM0_bits + GIE);
	// Receive the first byte
	read_buffer[0] = I2CBuffer;

	// Decrement counter;
	byte_Count -= 1;

    // If fill read buffer exit on NACK
    while (byte_Count && !NACK)
    {
        // On last byte to read send stop
        if(byte_Count==1)
        	UCB0CTL1 |= UCTXSTP;
        // Enter LPM0 w/ interrupts
        _bis_SR_register(LPM0_bits + GIE);
        // Shift Master data

        // Load data byte
        read_buffer[index_Count] = I2CBuffer;
        index_Count++;
        byte_Count--;
    }
    // Ensure stop condition got sent
    while(UCB0CTL1 & UCTXSTP);
}

void I2C_Write (unsigned char byte_Count, unsigned char Slave_Address, unsigned char Register_Address, unsigned char Register_Data[], unsigned char offset)
{
    // wait until I2C module has finished all operations.
    while (UCB0STAT & UCBUSY);

    // Set slave address
    UCB0I2CSA  = Slave_Address;

	I2CBufferArray[byte_Count] = Register_Address;
	// If word mode, write 2 bytes
	int x = byte_Count-1;
	unsigned char y=0;
	for (;x>=0;x--)
	{
		I2CBufferArray[x] = Register_Data[y+offset];
		y++;
	}

	PtrTransmit = byte_Count;


    // start condition generation
    I2CWriteInit();

    // => I2C communication is started
    UCB0CTL1 |= UCTXSTT;
    UCB0I2CIE |= UCNACKIE;

    // Enter LPM0 w/ interrupts
	__bis_SR_register(LPM0_bits + GIE);

	// I2C stop condition
	UCB0CTL1 |= UCTXSTP;

	// Ensure stop condition got sent
	while(UCB0CTL1 & UCTXSTP);

    UCB0I2CIE &= ~UCNACKIE;

}

void I2C_Write_Byte (unsigned char Slave_Address, unsigned char Register_Address, unsigned char Register_Data)
{
    // wait until I2C module has finished all operations.
    while (UCB0STAT & UCBUSY);

    // Set slave address
    UCB0I2CSA  = Slave_Address;

	// Set register address.
	I2CBufferArray[1] = Register_Address;
	// Data to be written
	I2CBufferArray[0] = Register_Data;
	// set I2CBufferArray size
	PtrTransmit = 1;

    // start condition generation
    I2CWriteInit();

    // => I2C communication is started
    UCB0CTL1 |= UCTXSTT;
    UCB0I2CIE |= UCNACKIE;

    // Enter LPM0 w/ interrupts
    __bis_SR_register(LPM0_bits + GIE);

    // I2C stop condition
    UCB0CTL1 |= UCTXSTP;

    // Ensure stop condition got sent
    while(UCB0CTL1 & UCTXSTP);

    UCB0I2CIE &= ~UCNACKIE;

}

unsigned int I2C_Read_Bytewrong ( unsigned char Slave_Address, unsigned char Register_Address, unsigned char data)
{
    // Variable for transmitted data
    unsigned int MST_Data = 0;

    // Wait until I2C module has finished all operations
    while (UCB0STAT & UCBUSY);


    // Set slave address
    UCB0I2CSA  = Slave_Address;

    // Set register address
    I2CBufferArray[1] = Register_Address;
    I2CBufferArray[0] = data;
    // set I2CBufferArray Pointer
    PtrTransmit = 1;

    // Configure Write Address first
    I2CWriteInit();
    // Start condition generation => I2C communication is started
    UCB0CTL1 |= UCTXSTT;
    UCB0I2CIE |= UCNACKIE;

    // Enable interrupts without entering LPM0.
    _bis_SR_register(GIE + LPM0_bits);
    // Wait till bus is free.

	while (UCB0STAT & UCBUSY);
	UCB0I2CIE &= ~UCNACKIE;
	// Configure Read Data byte
	I2CReadInit();
	UCB0I2CIE |= UCNACKIE;
	// I2C restart condition
	UCB0CTL1 |= UCTXSTT;
		// Wait till Start condition sent
	while((UCB0CTL1 & UCTXSTT) && NACK==0);

	//Reading a byte, send stop bit immediately

	// I2C stop condition
	UCB0CTL1 |= UCTXSTP;

	// Enter LPM0 w/ interrupts only if ACK was received
	if(!(UCB0STAT & UCNACKIFG))
		__bis_SR_register(LPM0_bits + GIE);
	// Receive the byte
	MST_Data = I2CBuffer;

    // Ensure stop condition got sent
    while(UCB0CTL1 & UCTXSTP);

    // Return word
    return MST_Data;
}






/*----------------------------------------------------------------------------*/
// Description:
//   Initialization of the I2C Module for Write operation.
/*----------------------------------------------------------------------------*/
void I2CWriteInit(void)
{
    // UCTR=1 => Transmit Mode (R/W bit = 0)
    UCB0CTL1 |= UCTR;
    // disable Receive ready interrupt
    IE2 &= ~UCB0RXIE;
    // disable Transmit ready interrupt
    IFG2 &= ~UCB0TXIFG;
    // enable Transmit ready interrupt
    IE2 |= UCB0TXIE;
}

/*----------------------------------------------------------------------------*/
// Description:
//   Initialization of the I2C Module for Read operation.
/*----------------------------------------------------------------------------*/
void I2CReadInit(void)
{
    // UCTR=0 => Receive Mode (R/W bit = 1)
    UCB0CTL1 &= ~UCTR;
    IFG2 &= ~UCB0RXIFG;
    // disable Transmit ready interrupt
    IE2 &= ~UCB0TXIE;
    // enable Receive ready interrupt
    IE2 |= UCB0RXIE;
}

/*******************************************************************************
*    USI interrupt service routine used for I2C State Machine                   *
*******************************************************************************/
/*
Transmit Register in Device

    Start       7 bit Address         W   ACK         Device Address                Register Address
      _    _______________________    _   _    ___________________________     ___________________________
_   _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |
SCL  |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_|

Followed by either Transmit of Data to the Register:

           Device High Byte                Device Low Byte
       ___________________________     ___________________________
_   _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _
SCL  |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_|

or Receive Data from the Register:

 Re-Start       7 bit Address         R   ACK      Device High Byte                Device Low Byte
      _    _______________________    _   _    ___________________________     ___________________________
_   _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ | _ |
SCL  |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_|

*/

/*
 *  USCI_B0 I2C Transmit ISR. Enable USCI_B0 I2C transmit interrupt and set USCIAB0TX_ISR as the interrupt handler.
 *  Then set the transmit interrupt to Manual on interrupt return.
 */
unsigned short USCIAB0TX_ISR (void)
{
    // Load TX buffer
    UCB0TXBUF = I2CBufferArray[PtrTransmit];

    // Decrement TX byte counter
    PtrTransmit--;

    if(PtrTransmit < 0)
    {
        // Wait until the last byte transmitted before exiting

    	while((!(IFG2 & UCB0TXIFG)) && (!(UCB0STAT & UCNACKIFG)));

        // disable interrupts.
        IE2 &= ~UCB0TXIE;

        // Clear USCI_B0 TX int flag
        IFG2 &= ~UCB0TXIFG;
        //UCB0STAT &= ~UCNACKIFG;
        // Exit LPM0
        return (LPM0_bits);
    }
    return 0;
}

/*
 *  USCI_B0 I2C Receive ISR. Enable USCI_B0 I2C receive interrupt and set USCIAB0RX_ISR as the interrupt handler.
 *  Then set the receive interrupt to Active on interrupt return.
 */
void USCIAB0RX_ISR (void)
{
    // store received data in buffer
    I2CBuffer = UCB0RXBUF;
}

