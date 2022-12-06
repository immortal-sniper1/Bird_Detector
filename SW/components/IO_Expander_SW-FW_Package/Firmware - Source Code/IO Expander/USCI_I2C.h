/*******************************************************************************
*       USCI_I2C.c Set's up the MSP430 uC USCI in I2C mode.                    *
*                                                                              *
*       Author:             William Goh                                        *
*                                                                              *
*       Revision Date:      May 2011                                           *
*                                                                              *
*       Revision Level:     00.01                                              *
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
*       Change Description:       Initial creation                             *
*                                                                              *
*       Date Changed:			  07/19/12									   *
*       Developer:				  Chris Kraft								   *
*       Change Description:		  Adjusted function prototypes to match		   *
*       						  updated USCI_I2C.c						   *
*******************************************************************************/
/*******************************************************************************
*                                 Included Headers                             *
*******************************************************************************/

#include <msp430.h>                         // Definition Files for the MSP430

/*******************************************************************************
*                                 Definitions                                  *
*******************************************************************************/
/************************** I2C USIC Engine ***********************************/
#define I2C_SDA BIT7                        // SDA on P1.7
#define I2C_SCL BIT6                        // SCL on P1.6

#define I2C_WRITE 0x00
#define I2C_READ 0x01

#define I2C_BYTE 0x01
#define I2C_WORD 0x02

#define I2C_ACK  0x00
#define I2C_NAK  0x01

/*******************************************************************************
*                                 Prototypes                                   *
*******************************************************************************/
/************ System Configuration *************************/
void Set_I2C(void);

/************ I2C Interface *******************************/
void I2C_Read (unsigned char, unsigned char , unsigned char , unsigned char* );
unsigned int I2C_Read_Byte (unsigned char, unsigned char);
void I2C_Write (unsigned char, unsigned char, unsigned char, unsigned char[],unsigned char);
void I2C_Write_Byte (unsigned char, unsigned char, unsigned char);
unsigned short USCIAB0TX_ISR (void);
void USCIAB0RX_ISR (void);

unsigned int I2C_Read_Bytewrong ( unsigned char Slave_Address, unsigned char Register_Address, unsigned char data);
