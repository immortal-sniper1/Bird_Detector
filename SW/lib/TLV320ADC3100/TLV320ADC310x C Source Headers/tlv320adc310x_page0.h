/*
 * @file tlv320adc3100_page0.h
 *
 * @brief TLV320ADC3100 Descriptor
 *
 * @copyright Copyright (C) 2021 Texas Instruments Incorporated - http://www.ti.com/
 *
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef TLV320ADC3100_PAGE0_H_
#define TLV320ADC3100_PAGE0_H_

#include <stdint.h>


//**********************************************************************************
//
// Function prototypes
//
//**********************************************************************************



//**********************************************************************************
//
// Device commands
//
//**********************************************************************************



//**********************************************************************************
//
// Register definitions
//
//**********************************************************************************


/* Register 0x00 (PAGE_SELECT) definition
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       Bit 7       |       Bit 6       |       Bit 5       |       Bit 4       |       Bit 3       |       Bit 2       |       Bit 1       |       Bit 0       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                                                           PAGE[7:0]                                                                           |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* PAGE_SELECT register */
    #define PAGE_SELECT_ADDRESS												((uint8_t) 0x00)
    #define PAGE_SELECT_DEFAULT												((uint8_t) 0x00)

    /* PAGE field */
    #define PAGE_SELECT_PAGE_MASK											((uint8_t) 0xFF)
    #define PAGE_SELECT_PAGE_0												((uint8_t) 0x00)    // DEFAULT
    #define PAGE_SELECT_PAGE_1												((uint8_t) 0x01)
    #define PAGE_SELECT_PAGE_2												((uint8_t) 0x02)
    #define PAGE_SELECT_PAGE_3												((uint8_t) 0x03)



/* Register 0x01 (SW_RESET) definition
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       Bit 7       |       Bit 6       |       Bit 5       |       Bit 4       |       Bit 3       |       Bit 2       |       Bit 1       |       Bit 0       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                   |                   |                   |                   |                   |                   |                   |       SW_RST      |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* SW_RESET register */
    #define SW_RESET_ADDRESS												((uint8_t) 0x01)
    #define SW_RESET_DEFAULT												((uint8_t) 0x00)

    /* SW_RST field */
    #define SW_RESET_SW_RST_MASK											((uint8_t) 0x01)
    #define SW_RESET_SW_RST_NOP												((uint8_t) 0x00)    // DEFAULT
    #define SW_RESET_SW_RST_RESET											((uint8_t) 0x01)



/* Register 0x04 (CLOCK_GEN) definition
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       Bit 7       |       Bit 6       |       Bit 5       |       Bit 4       |       Bit 3       |       Bit 2       |       Bit 1       |       Bit 0       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                 RESERVED[3:0]                                 |             PLL_CLKIN[1:0]            |            CODEC_CLKIN[1:0]           |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* CLOCK_GEN register */
    #define CLOCK_GEN_ADDRESS												((uint8_t) 0x04)
    #define CLOCK_GEN_DEFAULT												((uint8_t) 0x00)

    /* PLL_CLKIN field */
    #define CLOCK_GEN_PLL_CLKIN_MASK										((uint8_t) 0x0C)
    #define CLOCK_GEN_PLL_CLKIN_MCLK										((uint8_t) 0x00)    // DEFAULT
    #define CLOCK_GEN_PLL_CLKIN_BCLK										((uint8_t) 0x04)
    #define CLOCK_GEN_PLL_CLKIN_DIN											((uint8_t) 0x0C)

    /* CODEC_CLKIN field */
    #define CLOCK_GEN_CODEC_CLKIN_MASK										((uint8_t) 0x03)
    #define CLOCK_GEN_CODEC_CLKIN_MCLK										((uint8_t) 0x00)    // DEFAULT
    #define CLOCK_GEN_CODEC_CLKIN_BCLK										((uint8_t) 0x01)
    #define CLOCK_GEN_CODEC_CLKIN_PLL_CLK									((uint8_t) 0x03)



/* Register 0x05 (PLL_P_R) definition
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       Bit 7       |       Bit 6       |       Bit 5       |       Bit 4       |       Bit 3       |       Bit 2       |       Bit 1       |       Bit 0       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |      PLL_PWR      |                         P_DIV[2:0]                        |                                  R_MULT[3:0]                                  |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* PLL_P_R register */
    #define PLL_P_R_ADDRESS													((uint8_t) 0x05)
    #define PLL_P_R_DEFAULT													((uint8_t) 0x00)

    /* PLL_PWR field */
    #define PLL_P_R_PLL_PWR_MASK											((uint8_t) 0x80)
    #define PLL_P_R_PLL_PWR_DOWN											((uint8_t) 0x00)    // DEFAULT
    #define PLL_P_R_PLL_PWR_UP												((uint8_t) 0x80)

    /* P_DIV field */
    #define PLL_P_R_P_DIV_MASK												((uint8_t) 0x70)
    #define PLL_P_R_P_DIV_8													((uint8_t) 0x00)    // DEFAULT
    #define PLL_P_R_P_DIV_1													((uint8_t) 0x10)
    #define PLL_P_R_P_DIV_2													((uint8_t) 0x20)
    #define PLL_P_R_P_DIV_3													((uint8_t) 0x30)
    #define PLL_P_R_P_DIV_4													((uint8_t) 0x40)
    #define PLL_P_R_P_DIV_5													((uint8_t) 0x50)
    #define PLL_P_R_P_DIV_6													((uint8_t) 0x60)
    #define PLL_P_R_P_DIV_7													((uint8_t) 0x70)

    /* R_MULT field */
    #define PLL_P_R_R_MULT_MASK												((uint8_t) 0x0F)
    #define PLL_P_R_R_MULT_16												((uint8_t) 0x00)    // DEFAULT
    #define PLL_P_R_R_MULT_1												((uint8_t) 0x01)
    #define PLL_P_R_R_MULT_2												((uint8_t) 0x02)
    #define PLL_P_R_R_MULT_3												((uint8_t) 0x03)
    #define PLL_P_R_R_MULT_4												((uint8_t) 0x04)
    #define PLL_P_R_R_MULT_5												((uint8_t) 0x05)
    #define PLL_P_R_R_MULT_6												((uint8_t) 0x06)
    #define PLL_P_R_R_MULT_7												((uint8_t) 0x07)
    #define PLL_P_R_R_MULT_8												((uint8_t) 0x08)
    #define PLL_P_R_R_MULT_9												((uint8_t) 0x09)
    #define PLL_P_R_R_MULT_10												((uint8_t) 0x0A)
    #define PLL_P_R_R_MULT_11												((uint8_t) 0x0B)
    #define PLL_P_R_R_MULT_12												((uint8_t) 0x0C)
    #define PLL_P_R_R_MULT_13												((uint8_t) 0x0D)
    #define PLL_P_R_R_MULT_14												((uint8_t) 0x0E)
    #define PLL_P_R_R_MULT_15												((uint8_t) 0x0F)



/* Register 0x06 (PLL_J) definition
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       Bit 7       |       Bit 6       |       Bit 5       |       Bit 4       |       Bit 3       |       Bit 2       |       Bit 1       |       Bit 0       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |             RESERVED[1:0]             |                                                        VAL[5:0]                                                       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* PLL_J register */
    #define PLL_J_ADDRESS													((uint8_t) 0x06)
    #define PLL_J_DEFAULT													((uint8_t) 0x04)

    /* VAL field */
    #define PLL_J_VAL_MASK													((uint8_t) 0x3F)
    #define PLL_J_VAL_1														((uint8_t) 0x01)
    #define PLL_J_VAL_2														((uint8_t) 0x02)
    #define PLL_J_VAL_3														((uint8_t) 0x03)
    #define PLL_J_VAL_4														((uint8_t) 0x04)    // DEFAULT
    #define PLL_J_VAL_5														((uint8_t) 0x05)
    #define PLL_J_VAL_6														((uint8_t) 0x06)
    #define PLL_J_VAL_7														((uint8_t) 0x07)
    #define PLL_J_VAL_8														((uint8_t) 0x08)
    #define PLL_J_VAL_9														((uint8_t) 0x09)
    #define PLL_J_VAL_10													((uint8_t) 0x0A)
    #define PLL_J_VAL_11													((uint8_t) 0x0B)
    #define PLL_J_VAL_12													((uint8_t) 0x0C)
    #define PLL_J_VAL_13													((uint8_t) 0x0D)
    #define PLL_J_VAL_14													((uint8_t) 0x0E)
    #define PLL_J_VAL_15													((uint8_t) 0x0F)
    #define PLL_J_VAL_16													((uint8_t) 0x10)
    #define PLL_J_VAL_17													((uint8_t) 0x11)
    #define PLL_J_VAL_18													((uint8_t) 0x12)
    #define PLL_J_VAL_19													((uint8_t) 0x13)
    #define PLL_J_VAL_20													((uint8_t) 0x14)
    #define PLL_J_VAL_21													((uint8_t) 0x15)
    #define PLL_J_VAL_22													((uint8_t) 0x16)
    #define PLL_J_VAL_23													((uint8_t) 0x17)
    #define PLL_J_VAL_24													((uint8_t) 0x18)
    #define PLL_J_VAL_25													((uint8_t) 0x19)
    #define PLL_J_VAL_26													((uint8_t) 0x1A)
    #define PLL_J_VAL_27													((uint8_t) 0x1B)
    #define PLL_J_VAL_28													((uint8_t) 0x1C)
    #define PLL_J_VAL_29													((uint8_t) 0x1D)
    #define PLL_J_VAL_30													((uint8_t) 0x1E)
    #define PLL_J_VAL_31													((uint8_t) 0x1F)
    #define PLL_J_VAL_32													((uint8_t) 0x20)
    #define PLL_J_VAL_33													((uint8_t) 0x21)
    #define PLL_J_VAL_34													((uint8_t) 0x22)
    #define PLL_J_VAL_35													((uint8_t) 0x23)
    #define PLL_J_VAL_36													((uint8_t) 0x24)
    #define PLL_J_VAL_37													((uint8_t) 0x25)
    #define PLL_J_VAL_38													((uint8_t) 0x26)
    #define PLL_J_VAL_39													((uint8_t) 0x27)
    #define PLL_J_VAL_40													((uint8_t) 0x28)
    #define PLL_J_VAL_41													((uint8_t) 0x29)
    #define PLL_J_VAL_42													((uint8_t) 0x2A)
    #define PLL_J_VAL_43													((uint8_t) 0x2B)
    #define PLL_J_VAL_44													((uint8_t) 0x2C)
    #define PLL_J_VAL_45													((uint8_t) 0x2D)
    #define PLL_J_VAL_46													((uint8_t) 0x2E)
    #define PLL_J_VAL_47													((uint8_t) 0x2F)
    #define PLL_J_VAL_48													((uint8_t) 0x30)
    #define PLL_J_VAL_49													((uint8_t) 0x31)
    #define PLL_J_VAL_50													((uint8_t) 0x32)
    #define PLL_J_VAL_51													((uint8_t) 0x33)
    #define PLL_J_VAL_52													((uint8_t) 0x34)
    #define PLL_J_VAL_53													((uint8_t) 0x35)
    #define PLL_J_VAL_54													((uint8_t) 0x36)
    #define PLL_J_VAL_55													((uint8_t) 0x37)
    #define PLL_J_VAL_56													((uint8_t) 0x38)
    #define PLL_J_VAL_57													((uint8_t) 0x39)
    #define PLL_J_VAL_58													((uint8_t) 0x3A)
    #define PLL_J_VAL_59													((uint8_t) 0x3B)
    #define PLL_J_VAL_60													((uint8_t) 0x3C)
    #define PLL_J_VAL_61													((uint8_t) 0x3D)
    #define PLL_J_VAL_62													((uint8_t) 0x3E)
    #define PLL_J_VAL_63													((uint8_t) 0x3F)



/* Register 0x07 (PLL_D_MSB) definition
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       Bit 7       |       Bit 6       |       Bit 5       |       Bit 4       |       Bit 3       |       Bit 2       |       Bit 1       |       Bit 0       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |             RESERVED[1:0]             |                                                        VAL[5:0]                                                       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* PLL_D_MSB register */
    #define PLL_D_MSB_ADDRESS												((uint8_t) 0x07)
    #define PLL_D_MSB_DEFAULT												((uint8_t) 0x00)

    /* VAL field */
    #define PLL_D_MSB_VAL_MASK												((uint8_t) 0x3F)
    #define PLL_D_MSB_VAL_0													((uint8_t) 0x00)    // DEFAULT
    #define PLL_D_MSB_VAL_1													((uint8_t) 0x01)
    #define PLL_D_MSB_VAL_2													((uint8_t) 0x02)
    #define PLL_D_MSB_VAL_3													((uint8_t) 0x03)
    #define PLL_D_MSB_VAL_4													((uint8_t) 0x04)
    #define PLL_D_MSB_VAL_5													((uint8_t) 0x05)
    #define PLL_D_MSB_VAL_6													((uint8_t) 0x06)
    #define PLL_D_MSB_VAL_7													((uint8_t) 0x07)
    #define PLL_D_MSB_VAL_8													((uint8_t) 0x08)
    #define PLL_D_MSB_VAL_9													((uint8_t) 0x09)
    #define PLL_D_MSB_VAL_10												((uint8_t) 0x0A)
    #define PLL_D_MSB_VAL_11												((uint8_t) 0x0B)
    #define PLL_D_MSB_VAL_12												((uint8_t) 0x0C)
    #define PLL_D_MSB_VAL_13												((uint8_t) 0x0D)
    #define PLL_D_MSB_VAL_14												((uint8_t) 0x0E)
    #define PLL_D_MSB_VAL_15												((uint8_t) 0x0F)
    #define PLL_D_MSB_VAL_16												((uint8_t) 0x10)
    #define PLL_D_MSB_VAL_17												((uint8_t) 0x11)
    #define PLL_D_MSB_VAL_18												((uint8_t) 0x12)
    #define PLL_D_MSB_VAL_19												((uint8_t) 0x13)
    #define PLL_D_MSB_VAL_20												((uint8_t) 0x14)
    #define PLL_D_MSB_VAL_21												((uint8_t) 0x15)
    #define PLL_D_MSB_VAL_22												((uint8_t) 0x16)
    #define PLL_D_MSB_VAL_23												((uint8_t) 0x17)
    #define PLL_D_MSB_VAL_24												((uint8_t) 0x18)
    #define PLL_D_MSB_VAL_25												((uint8_t) 0x19)
    #define PLL_D_MSB_VAL_26												((uint8_t) 0x1A)
    #define PLL_D_MSB_VAL_27												((uint8_t) 0x1B)
    #define PLL_D_MSB_VAL_28												((uint8_t) 0x1C)
    #define PLL_D_MSB_VAL_29												((uint8_t) 0x1D)
    #define PLL_D_MSB_VAL_30												((uint8_t) 0x1E)
    #define PLL_D_MSB_VAL_31												((uint8_t) 0x1F)
    #define PLL_D_MSB_VAL_32												((uint8_t) 0x20)
    #define PLL_D_MSB_VAL_33												((uint8_t) 0x21)
    #define PLL_D_MSB_VAL_34												((uint8_t) 0x22)
    #define PLL_D_MSB_VAL_35												((uint8_t) 0x23)
    #define PLL_D_MSB_VAL_36												((uint8_t) 0x24)
    #define PLL_D_MSB_VAL_37												((uint8_t) 0x25)
    #define PLL_D_MSB_VAL_38												((uint8_t) 0x26)
    #define PLL_D_MSB_VAL_39												((uint8_t) 0x27)
    #define PLL_D_MSB_VAL_40												((uint8_t) 0x28)
    #define PLL_D_MSB_VAL_41												((uint8_t) 0x29)
    #define PLL_D_MSB_VAL_42												((uint8_t) 0x2A)
    #define PLL_D_MSB_VAL_43												((uint8_t) 0x2B)
    #define PLL_D_MSB_VAL_44												((uint8_t) 0x2C)
    #define PLL_D_MSB_VAL_45												((uint8_t) 0x2D)
    #define PLL_D_MSB_VAL_46												((uint8_t) 0x2E)
    #define PLL_D_MSB_VAL_47												((uint8_t) 0x2F)
    #define PLL_D_MSB_VAL_48												((uint8_t) 0x30)
    #define PLL_D_MSB_VAL_49												((uint8_t) 0x31)
    #define PLL_D_MSB_VAL_50												((uint8_t) 0x32)
    #define PLL_D_MSB_VAL_51												((uint8_t) 0x33)
    #define PLL_D_MSB_VAL_52												((uint8_t) 0x34)
    #define PLL_D_MSB_VAL_53												((uint8_t) 0x35)
    #define PLL_D_MSB_VAL_54												((uint8_t) 0x36)
    #define PLL_D_MSB_VAL_55												((uint8_t) 0x37)
    #define PLL_D_MSB_VAL_56												((uint8_t) 0x38)
    #define PLL_D_MSB_VAL_57												((uint8_t) 0x39)
    #define PLL_D_MSB_VAL_58												((uint8_t) 0x3A)
    #define PLL_D_MSB_VAL_59												((uint8_t) 0x3B)
    #define PLL_D_MSB_VAL_60												((uint8_t) 0x3C)
    #define PLL_D_MSB_VAL_61												((uint8_t) 0x3D)
    #define PLL_D_MSB_VAL_62												((uint8_t) 0x3E)
    #define PLL_D_MSB_VAL_63												((uint8_t) 0x3F)



/* Register 0x08 (PLL_D_LSB) definition
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       Bit 7       |       Bit 6       |       Bit 5       |       Bit 4       |       Bit 3       |       Bit 2       |       Bit 1       |       Bit 0       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                                                            VAL[7:0]                                                                           |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* PLL_D_LSB register */
    #define PLL_D_LSB_ADDRESS												((uint8_t) 0x08)
    #define PLL_D_LSB_DEFAULT												((uint8_t) 0x00)

    /* VAL field */
    #define PLL_D_LSB_VAL_MASK												((uint8_t) 0xFF)
    #define PLL_D_LSB_VAL_0													((uint8_t) 0x00)    // DEFAULT
    #define PLL_D_LSB_VAL_1													((uint8_t) 0x01)
    #define PLL_D_LSB_VAL_2													((uint8_t) 0x02)
    #define PLL_D_LSB_VAL_3													((uint8_t) 0x03)
    #define PLL_D_LSB_VAL_4													((uint8_t) 0x04)
    #define PLL_D_LSB_VAL_5													((uint8_t) 0x05)
    #define PLL_D_LSB_VAL_6													((uint8_t) 0x06)
    #define PLL_D_LSB_VAL_7													((uint8_t) 0x07)
    #define PLL_D_LSB_VAL_8													((uint8_t) 0x08)
    #define PLL_D_LSB_VAL_9													((uint8_t) 0x09)
    #define PLL_D_LSB_VAL_10												((uint8_t) 0x0A)
    #define PLL_D_LSB_VAL_11												((uint8_t) 0x0B)
    #define PLL_D_LSB_VAL_12												((uint8_t) 0x0C)
    #define PLL_D_LSB_VAL_13												((uint8_t) 0x0D)
    #define PLL_D_LSB_VAL_14												((uint8_t) 0x0E)
    #define PLL_D_LSB_VAL_15												((uint8_t) 0x0F)
    #define PLL_D_LSB_VAL_16												((uint8_t) 0x10)
    #define PLL_D_LSB_VAL_17												((uint8_t) 0x11)
    #define PLL_D_LSB_VAL_18												((uint8_t) 0x12)
    #define PLL_D_LSB_VAL_19												((uint8_t) 0x13)
    #define PLL_D_LSB_VAL_20												((uint8_t) 0x14)
    #define PLL_D_LSB_VAL_21												((uint8_t) 0x15)
    #define PLL_D_LSB_VAL_22												((uint8_t) 0x16)
    #define PLL_D_LSB_VAL_23												((uint8_t) 0x17)
    #define PLL_D_LSB_VAL_24												((uint8_t) 0x18)
    #define PLL_D_LSB_VAL_25												((uint8_t) 0x19)
    #define PLL_D_LSB_VAL_26												((uint8_t) 0x1A)
    #define PLL_D_LSB_VAL_27												((uint8_t) 0x1B)
    #define PLL_D_LSB_VAL_28												((uint8_t) 0x1C)
    #define PLL_D_LSB_VAL_29												((uint8_t) 0x1D)
    #define PLL_D_LSB_VAL_30												((uint8_t) 0x1E)
    #define PLL_D_LSB_VAL_31												((uint8_t) 0x1F)
    #define PLL_D_LSB_VAL_32												((uint8_t) 0x20)
    #define PLL_D_LSB_VAL_33												((uint8_t) 0x21)
    #define PLL_D_LSB_VAL_34												((uint8_t) 0x22)
    #define PLL_D_LSB_VAL_35												((uint8_t) 0x23)
    #define PLL_D_LSB_VAL_36												((uint8_t) 0x24)
    #define PLL_D_LSB_VAL_37												((uint8_t) 0x25)
    #define PLL_D_LSB_VAL_38												((uint8_t) 0x26)
    #define PLL_D_LSB_VAL_39												((uint8_t) 0x27)
    #define PLL_D_LSB_VAL_40												((uint8_t) 0x28)
    #define PLL_D_LSB_VAL_41												((uint8_t) 0x29)
    #define PLL_D_LSB_VAL_42												((uint8_t) 0x2A)
    #define PLL_D_LSB_VAL_43												((uint8_t) 0x2B)
    #define PLL_D_LSB_VAL_44												((uint8_t) 0x2C)
    #define PLL_D_LSB_VAL_45												((uint8_t) 0x2D)
    #define PLL_D_LSB_VAL_46												((uint8_t) 0x2E)
    #define PLL_D_LSB_VAL_47												((uint8_t) 0x2F)
    #define PLL_D_LSB_VAL_48												((uint8_t) 0x30)
    #define PLL_D_LSB_VAL_49												((uint8_t) 0x31)
    #define PLL_D_LSB_VAL_50												((uint8_t) 0x32)
    #define PLL_D_LSB_VAL_51												((uint8_t) 0x33)
    #define PLL_D_LSB_VAL_52												((uint8_t) 0x34)
    #define PLL_D_LSB_VAL_53												((uint8_t) 0x35)
    #define PLL_D_LSB_VAL_54												((uint8_t) 0x36)
    #define PLL_D_LSB_VAL_55												((uint8_t) 0x37)
    #define PLL_D_LSB_VAL_56												((uint8_t) 0x38)
    #define PLL_D_LSB_VAL_57												((uint8_t) 0x39)
    #define PLL_D_LSB_VAL_58												((uint8_t) 0x3A)
    #define PLL_D_LSB_VAL_59												((uint8_t) 0x3B)
    #define PLL_D_LSB_VAL_60												((uint8_t) 0x3C)
    #define PLL_D_LSB_VAL_61												((uint8_t) 0x3D)
    #define PLL_D_LSB_VAL_62												((uint8_t) 0x3E)
    #define PLL_D_LSB_VAL_63												((uint8_t) 0x3F)
    #define PLL_D_LSB_VAL_64												((uint8_t) 0x40)
    #define PLL_D_LSB_VAL_65												((uint8_t) 0x41)
    #define PLL_D_LSB_VAL_66												((uint8_t) 0x42)
    #define PLL_D_LSB_VAL_67												((uint8_t) 0x43)
    #define PLL_D_LSB_VAL_68												((uint8_t) 0x44)
    #define PLL_D_LSB_VAL_69												((uint8_t) 0x45)
    #define PLL_D_LSB_VAL_70												((uint8_t) 0x46)
    #define PLL_D_LSB_VAL_71												((uint8_t) 0x47)
    #define PLL_D_LSB_VAL_72												((uint8_t) 0x48)
    #define PLL_D_LSB_VAL_73												((uint8_t) 0x49)
    #define PLL_D_LSB_VAL_74												((uint8_t) 0x4A)
    #define PLL_D_LSB_VAL_75												((uint8_t) 0x4B)
    #define PLL_D_LSB_VAL_76												((uint8_t) 0x4C)
    #define PLL_D_LSB_VAL_77												((uint8_t) 0x4D)
    #define PLL_D_LSB_VAL_78												((uint8_t) 0x4E)
    #define PLL_D_LSB_VAL_79												((uint8_t) 0x4F)
    #define PLL_D_LSB_VAL_80												((uint8_t) 0x50)
    #define PLL_D_LSB_VAL_81												((uint8_t) 0x51)
    #define PLL_D_LSB_VAL_82												((uint8_t) 0x52)
    #define PLL_D_LSB_VAL_83												((uint8_t) 0x53)
    #define PLL_D_LSB_VAL_84												((uint8_t) 0x54)
    #define PLL_D_LSB_VAL_85												((uint8_t) 0x55)
    #define PLL_D_LSB_VAL_86												((uint8_t) 0x56)
    #define PLL_D_LSB_VAL_87												((uint8_t) 0x57)
    #define PLL_D_LSB_VAL_88												((uint8_t) 0x58)
    #define PLL_D_LSB_VAL_89												((uint8_t) 0x59)
    #define PLL_D_LSB_VAL_90												((uint8_t) 0x5A)
    #define PLL_D_LSB_VAL_91												((uint8_t) 0x5B)
    #define PLL_D_LSB_VAL_92												((uint8_t) 0x5C)
    #define PLL_D_LSB_VAL_93												((uint8_t) 0x5D)
    #define PLL_D_LSB_VAL_94												((uint8_t) 0x5E)
    #define PLL_D_LSB_VAL_95												((uint8_t) 0x5F)
    #define PLL_D_LSB_VAL_96												((uint8_t) 0x60)
    #define PLL_D_LSB_VAL_97												((uint8_t) 0x61)
    #define PLL_D_LSB_VAL_98												((uint8_t) 0x62)
    #define PLL_D_LSB_VAL_99												((uint8_t) 0x63)
    #define PLL_D_LSB_VAL_100												((uint8_t) 0x64)
    #define PLL_D_LSB_VAL_101												((uint8_t) 0x65)
    #define PLL_D_LSB_VAL_102												((uint8_t) 0x66)
    #define PLL_D_LSB_VAL_103												((uint8_t) 0x67)
    #define PLL_D_LSB_VAL_104												((uint8_t) 0x68)
    #define PLL_D_LSB_VAL_105												((uint8_t) 0x69)
    #define PLL_D_LSB_VAL_106												((uint8_t) 0x6A)
    #define PLL_D_LSB_VAL_107												((uint8_t) 0x6B)
    #define PLL_D_LSB_VAL_108												((uint8_t) 0x6C)
    #define PLL_D_LSB_VAL_109												((uint8_t) 0x6D)
    #define PLL_D_LSB_VAL_110												((uint8_t) 0x6E)
    #define PLL_D_LSB_VAL_111												((uint8_t) 0x6F)
    #define PLL_D_LSB_VAL_112												((uint8_t) 0x70)
    #define PLL_D_LSB_VAL_113												((uint8_t) 0x71)
    #define PLL_D_LSB_VAL_114												((uint8_t) 0x72)
    #define PLL_D_LSB_VAL_115												((uint8_t) 0x73)
    #define PLL_D_LSB_VAL_116												((uint8_t) 0x74)
    #define PLL_D_LSB_VAL_117												((uint8_t) 0x75)
    #define PLL_D_LSB_VAL_118												((uint8_t) 0x76)
    #define PLL_D_LSB_VAL_119												((uint8_t) 0x77)
    #define PLL_D_LSB_VAL_120												((uint8_t) 0x78)
    #define PLL_D_LSB_VAL_121												((uint8_t) 0x79)
    #define PLL_D_LSB_VAL_122												((uint8_t) 0x7A)
    #define PLL_D_LSB_VAL_123												((uint8_t) 0x7B)
    #define PLL_D_LSB_VAL_124												((uint8_t) 0x7C)
    #define PLL_D_LSB_VAL_125												((uint8_t) 0x7D)
    #define PLL_D_LSB_VAL_126												((uint8_t) 0x7E)
    #define PLL_D_LSB_VAL_127												((uint8_t) 0x7F)
    #define PLL_D_LSB_VAL_128												((uint8_t) 0x80)
    #define PLL_D_LSB_VAL_129												((uint8_t) 0x81)



/* Register 0x12 (ADC_NDAC) definition
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       Bit 7       |       Bit 6       |       Bit 5       |       Bit 4       |       Bit 3       |       Bit 2       |       Bit 1       |       Bit 0       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |      CLK_PWR      |                                                                  DIV[6:0]                                                                 |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* ADC_NDAC register */
    #define ADC_NDAC_ADDRESS												((uint8_t) 0x12)
    #define ADC_NDAC_DEFAULT												((uint8_t) 0x01)

    /* CLK_PWR field */
    #define ADC_NDAC_CLK_PWR_MASK											((uint8_t) 0x80)
    #define ADC_NDAC_CLK_PWR_DOWN											((uint8_t) 0x00)    // DEFAULT
    #define ADC_NDAC_CLK_PWR_UP												((uint8_t) 0x80)

    /* DIV field */
    #define ADC_NDAC_DIV_MASK												((uint8_t) 0x7F)
    #define ADC_NDAC_DIV_128												((uint8_t) 0x00)
    #define ADC_NDAC_DIV_1													((uint8_t) 0x01)    // DEFAULT
    #define ADC_NDAC_DIV_2													((uint8_t) 0x02)
    #define ADC_NDAC_DIV_3													((uint8_t) 0x03)
    #define ADC_NDAC_DIV_4													((uint8_t) 0x04)
    #define ADC_NDAC_DIV_5													((uint8_t) 0x05)
    #define ADC_NDAC_DIV_6													((uint8_t) 0x06)
    #define ADC_NDAC_DIV_7													((uint8_t) 0x07)
    #define ADC_NDAC_DIV_8													((uint8_t) 0x08)
    #define ADC_NDAC_DIV_9													((uint8_t) 0x09)
    #define ADC_NDAC_DIV_10													((uint8_t) 0x0A)
    #define ADC_NDAC_DIV_11													((uint8_t) 0x0B)
    #define ADC_NDAC_DIV_12													((uint8_t) 0x0C)
    #define ADC_NDAC_DIV_13													((uint8_t) 0x0D)
    #define ADC_NDAC_DIV_14													((uint8_t) 0x0E)
    #define ADC_NDAC_DIV_15													((uint8_t) 0x0F)
    #define ADC_NDAC_DIV_16													((uint8_t) 0x10)
    #define ADC_NDAC_DIV_17													((uint8_t) 0x11)
    #define ADC_NDAC_DIV_18													((uint8_t) 0x12)
    #define ADC_NDAC_DIV_19													((uint8_t) 0x13)
    #define ADC_NDAC_DIV_20													((uint8_t) 0x14)
    #define ADC_NDAC_DIV_21													((uint8_t) 0x15)
    #define ADC_NDAC_DIV_22													((uint8_t) 0x16)
    #define ADC_NDAC_DIV_23													((uint8_t) 0x17)
    #define ADC_NDAC_DIV_24													((uint8_t) 0x18)
    #define ADC_NDAC_DIV_25													((uint8_t) 0x19)
    #define ADC_NDAC_DIV_26													((uint8_t) 0x1A)
    #define ADC_NDAC_DIV_27													((uint8_t) 0x1B)
    #define ADC_NDAC_DIV_28													((uint8_t) 0x1C)
    #define ADC_NDAC_DIV_29													((uint8_t) 0x1D)
    #define ADC_NDAC_DIV_30													((uint8_t) 0x1E)
    #define ADC_NDAC_DIV_31													((uint8_t) 0x1F)
    #define ADC_NDAC_DIV_32													((uint8_t) 0x20)
    #define ADC_NDAC_DIV_33													((uint8_t) 0x21)
    #define ADC_NDAC_DIV_34													((uint8_t) 0x22)
    #define ADC_NDAC_DIV_35													((uint8_t) 0x23)
    #define ADC_NDAC_DIV_36													((uint8_t) 0x24)
    #define ADC_NDAC_DIV_37													((uint8_t) 0x25)
    #define ADC_NDAC_DIV_38													((uint8_t) 0x26)
    #define ADC_NDAC_DIV_39													((uint8_t) 0x27)
    #define ADC_NDAC_DIV_40													((uint8_t) 0x28)
    #define ADC_NDAC_DIV_41													((uint8_t) 0x29)
    #define ADC_NDAC_DIV_42													((uint8_t) 0x2A)
    #define ADC_NDAC_DIV_43													((uint8_t) 0x2B)
    #define ADC_NDAC_DIV_44													((uint8_t) 0x2C)
    #define ADC_NDAC_DIV_45													((uint8_t) 0x2D)
    #define ADC_NDAC_DIV_46													((uint8_t) 0x2E)
    #define ADC_NDAC_DIV_47													((uint8_t) 0x2F)
    #define ADC_NDAC_DIV_48													((uint8_t) 0x30)
    #define ADC_NDAC_DIV_49													((uint8_t) 0x31)
    #define ADC_NDAC_DIV_50													((uint8_t) 0x32)
    #define ADC_NDAC_DIV_51													((uint8_t) 0x33)
    #define ADC_NDAC_DIV_52													((uint8_t) 0x34)
    #define ADC_NDAC_DIV_53													((uint8_t) 0x35)
    #define ADC_NDAC_DIV_54													((uint8_t) 0x36)
    #define ADC_NDAC_DIV_55													((uint8_t) 0x37)
    #define ADC_NDAC_DIV_56													((uint8_t) 0x38)
    #define ADC_NDAC_DIV_57													((uint8_t) 0x39)
    #define ADC_NDAC_DIV_58													((uint8_t) 0x3A)
    #define ADC_NDAC_DIV_59													((uint8_t) 0x3B)
    #define ADC_NDAC_DIV_60													((uint8_t) 0x3C)
    #define ADC_NDAC_DIV_61													((uint8_t) 0x3D)
    #define ADC_NDAC_DIV_62													((uint8_t) 0x3E)
    #define ADC_NDAC_DIV_63													((uint8_t) 0x3F)
    #define ADC_NDAC_DIV_64													((uint8_t) 0x40)
    #define ADC_NDAC_DIV_65													((uint8_t) 0x41)
    #define ADC_NDAC_DIV_66													((uint8_t) 0x42)
    #define ADC_NDAC_DIV_67													((uint8_t) 0x43)
    #define ADC_NDAC_DIV_68													((uint8_t) 0x44)
    #define ADC_NDAC_DIV_69													((uint8_t) 0x45)
    #define ADC_NDAC_DIV_70													((uint8_t) 0x46)
    #define ADC_NDAC_DIV_71													((uint8_t) 0x47)
    #define ADC_NDAC_DIV_72													((uint8_t) 0x48)
    #define ADC_NDAC_DIV_73													((uint8_t) 0x49)
    #define ADC_NDAC_DIV_74													((uint8_t) 0x4A)
    #define ADC_NDAC_DIV_75													((uint8_t) 0x4B)
    #define ADC_NDAC_DIV_76													((uint8_t) 0x4C)
    #define ADC_NDAC_DIV_77													((uint8_t) 0x4D)
    #define ADC_NDAC_DIV_78													((uint8_t) 0x4E)
    #define ADC_NDAC_DIV_79													((uint8_t) 0x4F)
    #define ADC_NDAC_DIV_80													((uint8_t) 0x50)
    #define ADC_NDAC_DIV_81													((uint8_t) 0x51)
    #define ADC_NDAC_DIV_82													((uint8_t) 0x52)
    #define ADC_NDAC_DIV_83													((uint8_t) 0x53)
    #define ADC_NDAC_DIV_84													((uint8_t) 0x54)
    #define ADC_NDAC_DIV_85													((uint8_t) 0x55)
    #define ADC_NDAC_DIV_86													((uint8_t) 0x56)
    #define ADC_NDAC_DIV_87													((uint8_t) 0x57)
    #define ADC_NDAC_DIV_88													((uint8_t) 0x58)
    #define ADC_NDAC_DIV_89													((uint8_t) 0x59)
    #define ADC_NDAC_DIV_90													((uint8_t) 0x5A)
    #define ADC_NDAC_DIV_91													((uint8_t) 0x5B)
    #define ADC_NDAC_DIV_92													((uint8_t) 0x5C)
    #define ADC_NDAC_DIV_93													((uint8_t) 0x5D)
    #define ADC_NDAC_DIV_94													((uint8_t) 0x5E)
    #define ADC_NDAC_DIV_95													((uint8_t) 0x5F)
    #define ADC_NDAC_DIV_96													((uint8_t) 0x60)
    #define ADC_NDAC_DIV_97													((uint8_t) 0x61)
    #define ADC_NDAC_DIV_98													((uint8_t) 0x62)
    #define ADC_NDAC_DIV_99													((uint8_t) 0x63)
    #define ADC_NDAC_DIV_100												((uint8_t) 0x64)
    #define ADC_NDAC_DIV_101												((uint8_t) 0x65)
    #define ADC_NDAC_DIV_102												((uint8_t) 0x66)
    #define ADC_NDAC_DIV_103												((uint8_t) 0x67)
    #define ADC_NDAC_DIV_104												((uint8_t) 0x68)
    #define ADC_NDAC_DIV_105												((uint8_t) 0x69)
    #define ADC_NDAC_DIV_106												((uint8_t) 0x6A)
    #define ADC_NDAC_DIV_107												((uint8_t) 0x6B)
    #define ADC_NDAC_DIV_108												((uint8_t) 0x6C)
    #define ADC_NDAC_DIV_109												((uint8_t) 0x6D)
    #define ADC_NDAC_DIV_110												((uint8_t) 0x6E)
    #define ADC_NDAC_DIV_111												((uint8_t) 0x6F)
    #define ADC_NDAC_DIV_112												((uint8_t) 0x70)
    #define ADC_NDAC_DIV_113												((uint8_t) 0x71)
    #define ADC_NDAC_DIV_114												((uint8_t) 0x72)
    #define ADC_NDAC_DIV_115												((uint8_t) 0x73)
    #define ADC_NDAC_DIV_116												((uint8_t) 0x74)
    #define ADC_NDAC_DIV_117												((uint8_t) 0x75)
    #define ADC_NDAC_DIV_118												((uint8_t) 0x76)
    #define ADC_NDAC_DIV_119												((uint8_t) 0x77)
    #define ADC_NDAC_DIV_120												((uint8_t) 0x78)
    #define ADC_NDAC_DIV_121												((uint8_t) 0x79)
    #define ADC_NDAC_DIV_122												((uint8_t) 0x7A)
    #define ADC_NDAC_DIV_123												((uint8_t) 0x7B)
    #define ADC_NDAC_DIV_124												((uint8_t) 0x7C)
    #define ADC_NDAC_DIV_125												((uint8_t) 0x7D)
    #define ADC_NDAC_DIV_126												((uint8_t) 0x7E)
    #define ADC_NDAC_DIV_127												((uint8_t) 0x7F)



/* Register 0x13 (ADC_MDAC) definition
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       Bit 7       |       Bit 6       |       Bit 5       |       Bit 4       |       Bit 3       |       Bit 2       |       Bit 1       |       Bit 0       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |      CLK_PWR      |                                                                  DIV[6:0]                                                                 |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* ADC_MDAC register */
    #define ADC_MDAC_ADDRESS												((uint8_t) 0x13)
    #define ADC_MDAC_DEFAULT												((uint8_t) 0x01)

    /* CLK_PWR field */
    #define ADC_MDAC_CLK_PWR_MASK											((uint8_t) 0x80)
    #define ADC_MDAC_CLK_PWR_DOWN											((uint8_t) 0x00)    // DEFAULT
    #define ADC_MDAC_CLK_PWR_UP												((uint8_t) 0x80)

    /* DIV field */
    #define ADC_MDAC_DIV_MASK												((uint8_t) 0x7F)
    #define ADC_MDAC_DIV_128												((uint8_t) 0x00)
    #define ADC_MDAC_DIV_1													((uint8_t) 0x01)    // DEFAULT
    #define ADC_MDAC_DIV_2													((uint8_t) 0x02)
    #define ADC_MDAC_DIV_3													((uint8_t) 0x03)
    #define ADC_MDAC_DIV_4													((uint8_t) 0x04)
    #define ADC_MDAC_DIV_5													((uint8_t) 0x05)
    #define ADC_MDAC_DIV_6													((uint8_t) 0x06)
    #define ADC_MDAC_DIV_7													((uint8_t) 0x07)
    #define ADC_MDAC_DIV_8													((uint8_t) 0x08)
    #define ADC_MDAC_DIV_9													((uint8_t) 0x09)
    #define ADC_MDAC_DIV_10													((uint8_t) 0x0A)
    #define ADC_MDAC_DIV_11													((uint8_t) 0x0B)
    #define ADC_MDAC_DIV_12													((uint8_t) 0x0C)
    #define ADC_MDAC_DIV_13													((uint8_t) 0x0D)
    #define ADC_MDAC_DIV_14													((uint8_t) 0x0E)
    #define ADC_MDAC_DIV_15													((uint8_t) 0x0F)
    #define ADC_MDAC_DIV_16													((uint8_t) 0x10)
    #define ADC_MDAC_DIV_17													((uint8_t) 0x11)
    #define ADC_MDAC_DIV_18													((uint8_t) 0x12)
    #define ADC_MDAC_DIV_19													((uint8_t) 0x13)
    #define ADC_MDAC_DIV_20													((uint8_t) 0x14)
    #define ADC_MDAC_DIV_21													((uint8_t) 0x15)
    #define ADC_MDAC_DIV_22													((uint8_t) 0x16)
    #define ADC_MDAC_DIV_23													((uint8_t) 0x17)
    #define ADC_MDAC_DIV_24													((uint8_t) 0x18)
    #define ADC_MDAC_DIV_25													((uint8_t) 0x19)
    #define ADC_MDAC_DIV_26													((uint8_t) 0x1A)
    #define ADC_MDAC_DIV_27													((uint8_t) 0x1B)
    #define ADC_MDAC_DIV_28													((uint8_t) 0x1C)
    #define ADC_MDAC_DIV_29													((uint8_t) 0x1D)
    #define ADC_MDAC_DIV_30													((uint8_t) 0x1E)
    #define ADC_MDAC_DIV_31													((uint8_t) 0x1F)
    #define ADC_MDAC_DIV_32													((uint8_t) 0x20)
    #define ADC_MDAC_DIV_33													((uint8_t) 0x21)
    #define ADC_MDAC_DIV_34													((uint8_t) 0x22)
    #define ADC_MDAC_DIV_35													((uint8_t) 0x23)
    #define ADC_MDAC_DIV_36													((uint8_t) 0x24)
    #define ADC_MDAC_DIV_37													((uint8_t) 0x25)
    #define ADC_MDAC_DIV_38													((uint8_t) 0x26)
    #define ADC_MDAC_DIV_39													((uint8_t) 0x27)
    #define ADC_MDAC_DIV_40													((uint8_t) 0x28)
    #define ADC_MDAC_DIV_41													((uint8_t) 0x29)
    #define ADC_MDAC_DIV_42													((uint8_t) 0x2A)
    #define ADC_MDAC_DIV_43													((uint8_t) 0x2B)
    #define ADC_MDAC_DIV_44													((uint8_t) 0x2C)
    #define ADC_MDAC_DIV_45													((uint8_t) 0x2D)
    #define ADC_MDAC_DIV_46													((uint8_t) 0x2E)
    #define ADC_MDAC_DIV_47													((uint8_t) 0x2F)
    #define ADC_MDAC_DIV_48													((uint8_t) 0x30)
    #define ADC_MDAC_DIV_49													((uint8_t) 0x31)
    #define ADC_MDAC_DIV_50													((uint8_t) 0x32)
    #define ADC_MDAC_DIV_51													((uint8_t) 0x33)
    #define ADC_MDAC_DIV_52													((uint8_t) 0x34)
    #define ADC_MDAC_DIV_53													((uint8_t) 0x35)
    #define ADC_MDAC_DIV_54													((uint8_t) 0x36)
    #define ADC_MDAC_DIV_55													((uint8_t) 0x37)
    #define ADC_MDAC_DIV_56													((uint8_t) 0x38)
    #define ADC_MDAC_DIV_57													((uint8_t) 0x39)
    #define ADC_MDAC_DIV_58													((uint8_t) 0x3A)
    #define ADC_MDAC_DIV_59													((uint8_t) 0x3B)
    #define ADC_MDAC_DIV_60													((uint8_t) 0x3C)
    #define ADC_MDAC_DIV_61													((uint8_t) 0x3D)
    #define ADC_MDAC_DIV_62													((uint8_t) 0x3E)
    #define ADC_MDAC_DIV_63													((uint8_t) 0x3F)
    #define ADC_MDAC_DIV_64													((uint8_t) 0x40)
    #define ADC_MDAC_DIV_65													((uint8_t) 0x41)
    #define ADC_MDAC_DIV_66													((uint8_t) 0x42)
    #define ADC_MDAC_DIV_67													((uint8_t) 0x43)
    #define ADC_MDAC_DIV_68													((uint8_t) 0x44)
    #define ADC_MDAC_DIV_69													((uint8_t) 0x45)
    #define ADC_MDAC_DIV_70													((uint8_t) 0x46)
    #define ADC_MDAC_DIV_71													((uint8_t) 0x47)
    #define ADC_MDAC_DIV_72													((uint8_t) 0x48)
    #define ADC_MDAC_DIV_73													((uint8_t) 0x49)
    #define ADC_MDAC_DIV_74													((uint8_t) 0x4A)
    #define ADC_MDAC_DIV_75													((uint8_t) 0x4B)
    #define ADC_MDAC_DIV_76													((uint8_t) 0x4C)
    #define ADC_MDAC_DIV_77													((uint8_t) 0x4D)
    #define ADC_MDAC_DIV_78													((uint8_t) 0x4E)
    #define ADC_MDAC_DIV_79													((uint8_t) 0x4F)
    #define ADC_MDAC_DIV_80													((uint8_t) 0x50)
    #define ADC_MDAC_DIV_81													((uint8_t) 0x51)
    #define ADC_MDAC_DIV_82													((uint8_t) 0x52)
    #define ADC_MDAC_DIV_83													((uint8_t) 0x53)
    #define ADC_MDAC_DIV_84													((uint8_t) 0x54)
    #define ADC_MDAC_DIV_85													((uint8_t) 0x55)
    #define ADC_MDAC_DIV_86													((uint8_t) 0x56)
    #define ADC_MDAC_DIV_87													((uint8_t) 0x57)
    #define ADC_MDAC_DIV_88													((uint8_t) 0x58)
    #define ADC_MDAC_DIV_89													((uint8_t) 0x59)
    #define ADC_MDAC_DIV_90													((uint8_t) 0x5A)
    #define ADC_MDAC_DIV_91													((uint8_t) 0x5B)
    #define ADC_MDAC_DIV_92													((uint8_t) 0x5C)
    #define ADC_MDAC_DIV_93													((uint8_t) 0x5D)
    #define ADC_MDAC_DIV_94													((uint8_t) 0x5E)
    #define ADC_MDAC_DIV_95													((uint8_t) 0x5F)
    #define ADC_MDAC_DIV_96													((uint8_t) 0x60)
    #define ADC_MDAC_DIV_97													((uint8_t) 0x61)
    #define ADC_MDAC_DIV_98													((uint8_t) 0x62)
    #define ADC_MDAC_DIV_99													((uint8_t) 0x63)
    #define ADC_MDAC_DIV_100												((uint8_t) 0x64)
    #define ADC_MDAC_DIV_101												((uint8_t) 0x65)
    #define ADC_MDAC_DIV_102												((uint8_t) 0x66)
    #define ADC_MDAC_DIV_103												((uint8_t) 0x67)
    #define ADC_MDAC_DIV_104												((uint8_t) 0x68)
    #define ADC_MDAC_DIV_105												((uint8_t) 0x69)
    #define ADC_MDAC_DIV_106												((uint8_t) 0x6A)
    #define ADC_MDAC_DIV_107												((uint8_t) 0x6B)
    #define ADC_MDAC_DIV_108												((uint8_t) 0x6C)
    #define ADC_MDAC_DIV_109												((uint8_t) 0x6D)
    #define ADC_MDAC_DIV_110												((uint8_t) 0x6E)
    #define ADC_MDAC_DIV_111												((uint8_t) 0x6F)
    #define ADC_MDAC_DIV_112												((uint8_t) 0x70)
    #define ADC_MDAC_DIV_113												((uint8_t) 0x71)
    #define ADC_MDAC_DIV_114												((uint8_t) 0x72)
    #define ADC_MDAC_DIV_115												((uint8_t) 0x73)
    #define ADC_MDAC_DIV_116												((uint8_t) 0x74)
    #define ADC_MDAC_DIV_117												((uint8_t) 0x75)
    #define ADC_MDAC_DIV_118												((uint8_t) 0x76)
    #define ADC_MDAC_DIV_119												((uint8_t) 0x77)
    #define ADC_MDAC_DIV_120												((uint8_t) 0x78)
    #define ADC_MDAC_DIV_121												((uint8_t) 0x79)
    #define ADC_MDAC_DIV_122												((uint8_t) 0x7A)
    #define ADC_MDAC_DIV_123												((uint8_t) 0x7B)
    #define ADC_MDAC_DIV_124												((uint8_t) 0x7C)
    #define ADC_MDAC_DIV_125												((uint8_t) 0x7D)
    #define ADC_MDAC_DIV_126												((uint8_t) 0x7E)
    #define ADC_MDAC_DIV_127												((uint8_t) 0x7F)



/* Register 0x14 (ADC_AOSR) definition
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       Bit 7       |       Bit 6       |       Bit 5       |       Bit 4       |       Bit 3       |       Bit 2       |       Bit 1       |       Bit 0       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                                                            VAL[7:0]                                                                           |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* ADC_AOSR register */
    #define ADC_AOSR_ADDRESS												((uint8_t) 0x14)
    #define ADC_AOSR_DEFAULT												((uint8_t) 0x80)

    /* VAL field */
    #define ADC_AOSR_VAL_MASK												((uint8_t) 0xFF)
    #define ADC_AOSR_VAL_256												((uint8_t) 0x00)
    #define ADC_AOSR_VAL_1													((uint8_t) 0x01)
    #define ADC_AOSR_VAL_2													((uint8_t) 0x02)
    #define ADC_AOSR_VAL_3													((uint8_t) 0x03)
    #define ADC_AOSR_VAL_4													((uint8_t) 0x04)
    #define ADC_AOSR_VAL_5													((uint8_t) 0x05)
    #define ADC_AOSR_VAL_6													((uint8_t) 0x06)
    #define ADC_AOSR_VAL_7													((uint8_t) 0x07)
    #define ADC_AOSR_VAL_8													((uint8_t) 0x08)
    #define ADC_AOSR_VAL_9													((uint8_t) 0x09)
    #define ADC_AOSR_VAL_10													((uint8_t) 0x0A)
    #define ADC_AOSR_VAL_11													((uint8_t) 0x0B)
    #define ADC_AOSR_VAL_12													((uint8_t) 0x0C)
    #define ADC_AOSR_VAL_13													((uint8_t) 0x0D)
    #define ADC_AOSR_VAL_14													((uint8_t) 0x0E)
    #define ADC_AOSR_VAL_15													((uint8_t) 0x0F)
    #define ADC_AOSR_VAL_16													((uint8_t) 0x10)
    #define ADC_AOSR_VAL_17													((uint8_t) 0x11)
    #define ADC_AOSR_VAL_18													((uint8_t) 0x12)
    #define ADC_AOSR_VAL_19													((uint8_t) 0x13)
    #define ADC_AOSR_VAL_20													((uint8_t) 0x14)
    #define ADC_AOSR_VAL_21													((uint8_t) 0x15)
    #define ADC_AOSR_VAL_22													((uint8_t) 0x16)
    #define ADC_AOSR_VAL_23													((uint8_t) 0x17)
    #define ADC_AOSR_VAL_24													((uint8_t) 0x18)
    #define ADC_AOSR_VAL_25													((uint8_t) 0x19)
    #define ADC_AOSR_VAL_26													((uint8_t) 0x1A)
    #define ADC_AOSR_VAL_27													((uint8_t) 0x1B)
    #define ADC_AOSR_VAL_28													((uint8_t) 0x1C)
    #define ADC_AOSR_VAL_29													((uint8_t) 0x1D)
    #define ADC_AOSR_VAL_30													((uint8_t) 0x1E)
    #define ADC_AOSR_VAL_31													((uint8_t) 0x1F)
    #define ADC_AOSR_VAL_32													((uint8_t) 0x20)
    #define ADC_AOSR_VAL_33													((uint8_t) 0x21)
    #define ADC_AOSR_VAL_34													((uint8_t) 0x22)
    #define ADC_AOSR_VAL_35													((uint8_t) 0x23)
    #define ADC_AOSR_VAL_36													((uint8_t) 0x24)
    #define ADC_AOSR_VAL_37													((uint8_t) 0x25)
    #define ADC_AOSR_VAL_38													((uint8_t) 0x26)
    #define ADC_AOSR_VAL_39													((uint8_t) 0x27)
    #define ADC_AOSR_VAL_40													((uint8_t) 0x28)
    #define ADC_AOSR_VAL_41													((uint8_t) 0x29)
    #define ADC_AOSR_VAL_42													((uint8_t) 0x2A)
    #define ADC_AOSR_VAL_43													((uint8_t) 0x2B)
    #define ADC_AOSR_VAL_44													((uint8_t) 0x2C)
    #define ADC_AOSR_VAL_45													((uint8_t) 0x2D)
    #define ADC_AOSR_VAL_46													((uint8_t) 0x2E)
    #define ADC_AOSR_VAL_47													((uint8_t) 0x2F)
    #define ADC_AOSR_VAL_48													((uint8_t) 0x30)
    #define ADC_AOSR_VAL_49													((uint8_t) 0x31)
    #define ADC_AOSR_VAL_50													((uint8_t) 0x32)
    #define ADC_AOSR_VAL_51													((uint8_t) 0x33)
    #define ADC_AOSR_VAL_52													((uint8_t) 0x34)
    #define ADC_AOSR_VAL_53													((uint8_t) 0x35)
    #define ADC_AOSR_VAL_54													((uint8_t) 0x36)
    #define ADC_AOSR_VAL_55													((uint8_t) 0x37)
    #define ADC_AOSR_VAL_56													((uint8_t) 0x38)
    #define ADC_AOSR_VAL_57													((uint8_t) 0x39)
    #define ADC_AOSR_VAL_58													((uint8_t) 0x3A)
    #define ADC_AOSR_VAL_59													((uint8_t) 0x3B)
    #define ADC_AOSR_VAL_60													((uint8_t) 0x3C)
    #define ADC_AOSR_VAL_61													((uint8_t) 0x3D)
    #define ADC_AOSR_VAL_62													((uint8_t) 0x3E)
    #define ADC_AOSR_VAL_63													((uint8_t) 0x3F)
    #define ADC_AOSR_VAL_64													((uint8_t) 0x40)
    #define ADC_AOSR_VAL_65													((uint8_t) 0x41)
    #define ADC_AOSR_VAL_66													((uint8_t) 0x42)
    #define ADC_AOSR_VAL_67													((uint8_t) 0x43)
    #define ADC_AOSR_VAL_68													((uint8_t) 0x44)
    #define ADC_AOSR_VAL_69													((uint8_t) 0x45)
    #define ADC_AOSR_VAL_70													((uint8_t) 0x46)
    #define ADC_AOSR_VAL_71													((uint8_t) 0x47)
    #define ADC_AOSR_VAL_72													((uint8_t) 0x48)
    #define ADC_AOSR_VAL_73													((uint8_t) 0x49)
    #define ADC_AOSR_VAL_74													((uint8_t) 0x4A)
    #define ADC_AOSR_VAL_75													((uint8_t) 0x4B)
    #define ADC_AOSR_VAL_76													((uint8_t) 0x4C)
    #define ADC_AOSR_VAL_77													((uint8_t) 0x4D)
    #define ADC_AOSR_VAL_78													((uint8_t) 0x4E)
    #define ADC_AOSR_VAL_79													((uint8_t) 0x4F)
    #define ADC_AOSR_VAL_80													((uint8_t) 0x50)
    #define ADC_AOSR_VAL_81													((uint8_t) 0x51)
    #define ADC_AOSR_VAL_82													((uint8_t) 0x52)
    #define ADC_AOSR_VAL_83													((uint8_t) 0x53)
    #define ADC_AOSR_VAL_84													((uint8_t) 0x54)
    #define ADC_AOSR_VAL_85													((uint8_t) 0x55)
    #define ADC_AOSR_VAL_86													((uint8_t) 0x56)
    #define ADC_AOSR_VAL_87													((uint8_t) 0x57)
    #define ADC_AOSR_VAL_88													((uint8_t) 0x58)
    #define ADC_AOSR_VAL_89													((uint8_t) 0x59)
    #define ADC_AOSR_VAL_90													((uint8_t) 0x5A)
    #define ADC_AOSR_VAL_91													((uint8_t) 0x5B)
    #define ADC_AOSR_VAL_92													((uint8_t) 0x5C)
    #define ADC_AOSR_VAL_93													((uint8_t) 0x5D)
    #define ADC_AOSR_VAL_94													((uint8_t) 0x5E)
    #define ADC_AOSR_VAL_95													((uint8_t) 0x5F)
    #define ADC_AOSR_VAL_96													((uint8_t) 0x60)
    #define ADC_AOSR_VAL_97													((uint8_t) 0x61)
    #define ADC_AOSR_VAL_98													((uint8_t) 0x62)
    #define ADC_AOSR_VAL_99													((uint8_t) 0x63)
    #define ADC_AOSR_VAL_100												((uint8_t) 0x64)
    #define ADC_AOSR_VAL_101												((uint8_t) 0x65)
    #define ADC_AOSR_VAL_102												((uint8_t) 0x66)
    #define ADC_AOSR_VAL_103												((uint8_t) 0x67)
    #define ADC_AOSR_VAL_104												((uint8_t) 0x68)
    #define ADC_AOSR_VAL_105												((uint8_t) 0x69)
    #define ADC_AOSR_VAL_106												((uint8_t) 0x6A)
    #define ADC_AOSR_VAL_107												((uint8_t) 0x6B)
    #define ADC_AOSR_VAL_108												((uint8_t) 0x6C)
    #define ADC_AOSR_VAL_109												((uint8_t) 0x6D)
    #define ADC_AOSR_VAL_110												((uint8_t) 0x6E)
    #define ADC_AOSR_VAL_111												((uint8_t) 0x6F)
    #define ADC_AOSR_VAL_112												((uint8_t) 0x70)
    #define ADC_AOSR_VAL_113												((uint8_t) 0x71)
    #define ADC_AOSR_VAL_114												((uint8_t) 0x72)
    #define ADC_AOSR_VAL_115												((uint8_t) 0x73)
    #define ADC_AOSR_VAL_116												((uint8_t) 0x74)
    #define ADC_AOSR_VAL_117												((uint8_t) 0x75)
    #define ADC_AOSR_VAL_118												((uint8_t) 0x76)
    #define ADC_AOSR_VAL_119												((uint8_t) 0x77)
    #define ADC_AOSR_VAL_120												((uint8_t) 0x78)
    #define ADC_AOSR_VAL_121												((uint8_t) 0x79)
    #define ADC_AOSR_VAL_122												((uint8_t) 0x7A)
    #define ADC_AOSR_VAL_123												((uint8_t) 0x7B)
    #define ADC_AOSR_VAL_124												((uint8_t) 0x7C)
    #define ADC_AOSR_VAL_125												((uint8_t) 0x7D)
    #define ADC_AOSR_VAL_126												((uint8_t) 0x7E)
    #define ADC_AOSR_VAL_127												((uint8_t) 0x7F)
    #define ADC_AOSR_VAL_128												((uint8_t) 0x80)    // DEFAULT
    #define ADC_AOSR_VAL_129												((uint8_t) 0x81)



/* Register 0x15 (ADC_IADC) definition
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       Bit 7       |       Bit 6       |       Bit 5       |       Bit 4       |       Bit 3       |       Bit 2       |       Bit 1       |       Bit 0       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                                                            VAL[7:0]                                                                           |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* ADC_IADC register */
    #define ADC_IADC_ADDRESS												((uint8_t) 0x15)
    #define ADC_IADC_DEFAULT												((uint8_t) 0x80)

    /* VAL field */
    #define ADC_IADC_VAL_MASK												((uint8_t) 0xFF)
    #define ADC_IADC_VAL_2													((uint8_t) 0x01)
    #define ADC_IADC_VAL_4													((uint8_t) 0x02)
    #define ADC_IADC_VAL_6													((uint8_t) 0x03)
    #define ADC_IADC_VAL_8													((uint8_t) 0x04)
    #define ADC_IADC_VAL_10													((uint8_t) 0x05)
    #define ADC_IADC_VAL_12													((uint8_t) 0x06)
    #define ADC_IADC_VAL_14													((uint8_t) 0x07)
    #define ADC_IADC_VAL_16													((uint8_t) 0x08)
    #define ADC_IADC_VAL_18													((uint8_t) 0x09)
    #define ADC_IADC_VAL_20													((uint8_t) 0x0A)
    #define ADC_IADC_VAL_22													((uint8_t) 0x0B)
    #define ADC_IADC_VAL_24													((uint8_t) 0x0C)
    #define ADC_IADC_VAL_26													((uint8_t) 0x0D)
    #define ADC_IADC_VAL_28													((uint8_t) 0x0E)
    #define ADC_IADC_VAL_30													((uint8_t) 0x0F)
    #define ADC_IADC_VAL_32													((uint8_t) 0x10)
    #define ADC_IADC_VAL_34													((uint8_t) 0x11)
    #define ADC_IADC_VAL_36													((uint8_t) 0x12)
    #define ADC_IADC_VAL_38													((uint8_t) 0x13)
    #define ADC_IADC_VAL_40													((uint8_t) 0x14)
    #define ADC_IADC_VAL_42													((uint8_t) 0x15)
    #define ADC_IADC_VAL_44													((uint8_t) 0x16)
    #define ADC_IADC_VAL_46													((uint8_t) 0x17)
    #define ADC_IADC_VAL_48													((uint8_t) 0x18)
    #define ADC_IADC_VAL_50													((uint8_t) 0x19)
    #define ADC_IADC_VAL_52													((uint8_t) 0x1A)
    #define ADC_IADC_VAL_54													((uint8_t) 0x1B)
    #define ADC_IADC_VAL_56													((uint8_t) 0x1C)
    #define ADC_IADC_VAL_58													((uint8_t) 0x1D)
    #define ADC_IADC_VAL_60													((uint8_t) 0x1E)
    #define ADC_IADC_VAL_62													((uint8_t) 0x1F)
    #define ADC_IADC_VAL_64													((uint8_t) 0x20)
    #define ADC_IADC_VAL_66													((uint8_t) 0x21)
    #define ADC_IADC_VAL_68													((uint8_t) 0x22)
    #define ADC_IADC_VAL_70													((uint8_t) 0x23)
    #define ADC_IADC_VAL_72													((uint8_t) 0x24)
    #define ADC_IADC_VAL_74													((uint8_t) 0x25)
    #define ADC_IADC_VAL_76													((uint8_t) 0x26)
    #define ADC_IADC_VAL_78													((uint8_t) 0x27)
    #define ADC_IADC_VAL_80													((uint8_t) 0x28)
    #define ADC_IADC_VAL_82													((uint8_t) 0x29)
    #define ADC_IADC_VAL_84													((uint8_t) 0x2A)
    #define ADC_IADC_VAL_86													((uint8_t) 0x2B)
    #define ADC_IADC_VAL_88													((uint8_t) 0x2C)
    #define ADC_IADC_VAL_90													((uint8_t) 0x2D)
    #define ADC_IADC_VAL_92													((uint8_t) 0x2E)
    #define ADC_IADC_VAL_94													((uint8_t) 0x2F)
    #define ADC_IADC_VAL_96													((uint8_t) 0x30)
    #define ADC_IADC_VAL_98													((uint8_t) 0x31)
    #define ADC_IADC_VAL_100												((uint8_t) 0x32)
    #define ADC_IADC_VAL_102												((uint8_t) 0x33)
    #define ADC_IADC_VAL_104												((uint8_t) 0x34)
    #define ADC_IADC_VAL_106												((uint8_t) 0x35)
    #define ADC_IADC_VAL_108												((uint8_t) 0x36)
    #define ADC_IADC_VAL_110												((uint8_t) 0x37)
    #define ADC_IADC_VAL_112												((uint8_t) 0x38)
    #define ADC_IADC_VAL_114												((uint8_t) 0x39)
    #define ADC_IADC_VAL_116												((uint8_t) 0x3A)
    #define ADC_IADC_VAL_118												((uint8_t) 0x3B)
    #define ADC_IADC_VAL_120												((uint8_t) 0x3C)
    #define ADC_IADC_VAL_122												((uint8_t) 0x3D)
    #define ADC_IADC_VAL_124												((uint8_t) 0x3E)
    #define ADC_IADC_VAL_126												((uint8_t) 0x3F)
    #define ADC_IADC_VAL_128												((uint8_t) 0x40)



/* Register 0x16 (ADC_DEC) definition
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       Bit 7       |       Bit 6       |       Bit 5       |       Bit 4       |       Bit 3       |       Bit 2       |       Bit 1       |       Bit 0       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                 RESERVED[3:0]                                 |                                   RATIO[3:0]                                  |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* ADC_DEC register */
    #define ADC_DEC_ADDRESS													((uint8_t) 0x16)
    #define ADC_DEC_DEFAULT													((uint8_t) 0x04)

    /* RATIO field */
    #define ADC_DEC_RATIO_MASK												((uint8_t) 0x0F)
    #define ADC_DEC_RATIO_16												((uint8_t) 0x00)
    #define ADC_DEC_RATIO_1													((uint8_t) 0x01)
    #define ADC_DEC_RATIO_2													((uint8_t) 0x02)
    #define ADC_DEC_RATIO_3													((uint8_t) 0x03)
    #define ADC_DEC_RATIO_4													((uint8_t) 0x04)    // DEFAULT
    #define ADC_DEC_RATIO_5													((uint8_t) 0x05)
    #define ADC_DEC_RATIO_6													((uint8_t) 0x06)
    #define ADC_DEC_RATIO_7													((uint8_t) 0x07)
    #define ADC_DEC_RATIO_8													((uint8_t) 0x08)
    #define ADC_DEC_RATIO_9													((uint8_t) 0x09)
    #define ADC_DEC_RATIO_10												((uint8_t) 0x0A)
    #define ADC_DEC_RATIO_11												((uint8_t) 0x0B)
    #define ADC_DEC_RATIO_12												((uint8_t) 0x0C)
    #define ADC_DEC_RATIO_13												((uint8_t) 0x0D)
    #define ADC_DEC_RATIO_14												((uint8_t) 0x0E)
    #define ADC_DEC_RATIO_15												((uint8_t) 0x0F)



/* Register 0x19 (CLKOUT_MUX) definition
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       Bit 7       |       Bit 6       |       Bit 5       |       Bit 4       |       Bit 3       |       Bit 2       |       Bit 1       |       Bit 0       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                           RESERVED[4:0]                                           |                      CDIV_CLKIN[2:0]                      |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* CLKOUT_MUX register */
    #define CLKOUT_MUX_ADDRESS												((uint8_t) 0x19)
    #define CLKOUT_MUX_DEFAULT												((uint8_t) 0x00)

    /* CDIV_CLKIN field */
    #define CLKOUT_MUX_CDIV_CLKIN_MASK										((uint8_t) 0x07)
    #define CLKOUT_MUX_CDIV_CLKIN_MCLK										((uint8_t) 0x00)    // DEFAULT
    #define CLKOUT_MUX_CDIV_CLKIN_BCLK										((uint8_t) 0x01)
    #define CLKOUT_MUX_CDIV_CLKIN_PLL_CLK									((uint8_t) 0x03)
    #define CLKOUT_MUX_CDIV_CLKIN_ADC_CLK									((uint8_t) 0x06)
    #define CLKOUT_MUX_CDIV_CLKIN_ADC_MOD_CLK								((uint8_t) 0x07)



/* Register 0x1A (CLKOUT_M) definition
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       Bit 7       |       Bit 6       |       Bit 5       |       Bit 4       |       Bit 3       |       Bit 2       |       Bit 1       |       Bit 0       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        PWR        |                                                                  DIV[6:0]                                                                 |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* CLKOUT_M register */
    #define CLKOUT_M_ADDRESS												((uint8_t) 0x1A)
    #define CLKOUT_M_DEFAULT												((uint8_t) 0x01)

    /* PWR field */
    #define CLKOUT_M_PWR_MASK												((uint8_t) 0x80)
    #define CLKOUT_M_PWR_DOWN												((uint8_t) 0x00)    // DEFAULT
    #define CLKOUT_M_PWR_UP													((uint8_t) 0x80)

    /* DIV field */
    #define CLKOUT_M_DIV_MASK												((uint8_t) 0x7F)
    #define CLKOUT_M_DIV_128												((uint8_t) 0x00)
    #define CLKOUT_M_DIV_1													((uint8_t) 0x01)    // DEFAULT
    #define CLKOUT_M_DIV_2													((uint8_t) 0x02)
    #define CLKOUT_M_DIV_3													((uint8_t) 0x03)
    #define CLKOUT_M_DIV_4													((uint8_t) 0x04)
    #define CLKOUT_M_DIV_5													((uint8_t) 0x05)
    #define CLKOUT_M_DIV_6													((uint8_t) 0x06)
    #define CLKOUT_M_DIV_7													((uint8_t) 0x07)
    #define CLKOUT_M_DIV_8													((uint8_t) 0x08)
    #define CLKOUT_M_DIV_9													((uint8_t) 0x09)
    #define CLKOUT_M_DIV_10													((uint8_t) 0x0A)
    #define CLKOUT_M_DIV_11													((uint8_t) 0x0B)
    #define CLKOUT_M_DIV_12													((uint8_t) 0x0C)
    #define CLKOUT_M_DIV_13													((uint8_t) 0x0D)
    #define CLKOUT_M_DIV_14													((uint8_t) 0x0E)
    #define CLKOUT_M_DIV_15													((uint8_t) 0x0F)
    #define CLKOUT_M_DIV_16													((uint8_t) 0x10)
    #define CLKOUT_M_DIV_17													((uint8_t) 0x11)
    #define CLKOUT_M_DIV_18													((uint8_t) 0x12)
    #define CLKOUT_M_DIV_19													((uint8_t) 0x13)
    #define CLKOUT_M_DIV_20													((uint8_t) 0x14)
    #define CLKOUT_M_DIV_21													((uint8_t) 0x15)
    #define CLKOUT_M_DIV_22													((uint8_t) 0x16)
    #define CLKOUT_M_DIV_23													((uint8_t) 0x17)
    #define CLKOUT_M_DIV_24													((uint8_t) 0x18)
    #define CLKOUT_M_DIV_25													((uint8_t) 0x19)
    #define CLKOUT_M_DIV_26													((uint8_t) 0x1A)
    #define CLKOUT_M_DIV_27													((uint8_t) 0x1B)
    #define CLKOUT_M_DIV_28													((uint8_t) 0x1C)
    #define CLKOUT_M_DIV_29													((uint8_t) 0x1D)
    #define CLKOUT_M_DIV_30													((uint8_t) 0x1E)
    #define CLKOUT_M_DIV_31													((uint8_t) 0x1F)
    #define CLKOUT_M_DIV_32													((uint8_t) 0x20)
    #define CLKOUT_M_DIV_33													((uint8_t) 0x21)
    #define CLKOUT_M_DIV_34													((uint8_t) 0x22)
    #define CLKOUT_M_DIV_35													((uint8_t) 0x23)
    #define CLKOUT_M_DIV_36													((uint8_t) 0x24)
    #define CLKOUT_M_DIV_37													((uint8_t) 0x25)
    #define CLKOUT_M_DIV_38													((uint8_t) 0x26)
    #define CLKOUT_M_DIV_39													((uint8_t) 0x27)
    #define CLKOUT_M_DIV_40													((uint8_t) 0x28)
    #define CLKOUT_M_DIV_41													((uint8_t) 0x29)
    #define CLKOUT_M_DIV_42													((uint8_t) 0x2A)
    #define CLKOUT_M_DIV_43													((uint8_t) 0x2B)
    #define CLKOUT_M_DIV_44													((uint8_t) 0x2C)
    #define CLKOUT_M_DIV_45													((uint8_t) 0x2D)
    #define CLKOUT_M_DIV_46													((uint8_t) 0x2E)
    #define CLKOUT_M_DIV_47													((uint8_t) 0x2F)
    #define CLKOUT_M_DIV_48													((uint8_t) 0x30)
    #define CLKOUT_M_DIV_49													((uint8_t) 0x31)
    #define CLKOUT_M_DIV_50													((uint8_t) 0x32)
    #define CLKOUT_M_DIV_51													((uint8_t) 0x33)
    #define CLKOUT_M_DIV_52													((uint8_t) 0x34)
    #define CLKOUT_M_DIV_53													((uint8_t) 0x35)
    #define CLKOUT_M_DIV_54													((uint8_t) 0x36)
    #define CLKOUT_M_DIV_55													((uint8_t) 0x37)
    #define CLKOUT_M_DIV_56													((uint8_t) 0x38)
    #define CLKOUT_M_DIV_57													((uint8_t) 0x39)
    #define CLKOUT_M_DIV_58													((uint8_t) 0x3A)
    #define CLKOUT_M_DIV_59													((uint8_t) 0x3B)
    #define CLKOUT_M_DIV_60													((uint8_t) 0x3C)
    #define CLKOUT_M_DIV_61													((uint8_t) 0x3D)
    #define CLKOUT_M_DIV_62													((uint8_t) 0x3E)
    #define CLKOUT_M_DIV_63													((uint8_t) 0x3F)
    #define CLKOUT_M_DIV_64													((uint8_t) 0x40)
    #define CLKOUT_M_DIV_65													((uint8_t) 0x41)
    #define CLKOUT_M_DIV_66													((uint8_t) 0x42)
    #define CLKOUT_M_DIV_67													((uint8_t) 0x43)
    #define CLKOUT_M_DIV_68													((uint8_t) 0x44)
    #define CLKOUT_M_DIV_69													((uint8_t) 0x45)
    #define CLKOUT_M_DIV_70													((uint8_t) 0x46)
    #define CLKOUT_M_DIV_71													((uint8_t) 0x47)
    #define CLKOUT_M_DIV_72													((uint8_t) 0x48)
    #define CLKOUT_M_DIV_73													((uint8_t) 0x49)
    #define CLKOUT_M_DIV_74													((uint8_t) 0x4A)
    #define CLKOUT_M_DIV_75													((uint8_t) 0x4B)
    #define CLKOUT_M_DIV_76													((uint8_t) 0x4C)
    #define CLKOUT_M_DIV_77													((uint8_t) 0x4D)
    #define CLKOUT_M_DIV_78													((uint8_t) 0x4E)
    #define CLKOUT_M_DIV_79													((uint8_t) 0x4F)
    #define CLKOUT_M_DIV_80													((uint8_t) 0x50)
    #define CLKOUT_M_DIV_81													((uint8_t) 0x51)
    #define CLKOUT_M_DIV_82													((uint8_t) 0x52)
    #define CLKOUT_M_DIV_83													((uint8_t) 0x53)
    #define CLKOUT_M_DIV_84													((uint8_t) 0x54)
    #define CLKOUT_M_DIV_85													((uint8_t) 0x55)
    #define CLKOUT_M_DIV_86													((uint8_t) 0x56)
    #define CLKOUT_M_DIV_87													((uint8_t) 0x57)
    #define CLKOUT_M_DIV_88													((uint8_t) 0x58)
    #define CLKOUT_M_DIV_89													((uint8_t) 0x59)
    #define CLKOUT_M_DIV_90													((uint8_t) 0x5A)
    #define CLKOUT_M_DIV_91													((uint8_t) 0x5B)
    #define CLKOUT_M_DIV_92													((uint8_t) 0x5C)
    #define CLKOUT_M_DIV_93													((uint8_t) 0x5D)
    #define CLKOUT_M_DIV_94													((uint8_t) 0x5E)
    #define CLKOUT_M_DIV_95													((uint8_t) 0x5F)
    #define CLKOUT_M_DIV_96													((uint8_t) 0x60)
    #define CLKOUT_M_DIV_97													((uint8_t) 0x61)
    #define CLKOUT_M_DIV_98													((uint8_t) 0x62)
    #define CLKOUT_M_DIV_99													((uint8_t) 0x63)
    #define CLKOUT_M_DIV_100												((uint8_t) 0x64)
    #define CLKOUT_M_DIV_101												((uint8_t) 0x65)
    #define CLKOUT_M_DIV_102												((uint8_t) 0x66)
    #define CLKOUT_M_DIV_103												((uint8_t) 0x67)
    #define CLKOUT_M_DIV_104												((uint8_t) 0x68)
    #define CLKOUT_M_DIV_105												((uint8_t) 0x69)
    #define CLKOUT_M_DIV_106												((uint8_t) 0x6A)
    #define CLKOUT_M_DIV_107												((uint8_t) 0x6B)
    #define CLKOUT_M_DIV_108												((uint8_t) 0x6C)
    #define CLKOUT_M_DIV_109												((uint8_t) 0x6D)
    #define CLKOUT_M_DIV_110												((uint8_t) 0x6E)
    #define CLKOUT_M_DIV_111												((uint8_t) 0x6F)
    #define CLKOUT_M_DIV_112												((uint8_t) 0x70)
    #define CLKOUT_M_DIV_113												((uint8_t) 0x71)
    #define CLKOUT_M_DIV_114												((uint8_t) 0x72)
    #define CLKOUT_M_DIV_115												((uint8_t) 0x73)
    #define CLKOUT_M_DIV_116												((uint8_t) 0x74)
    #define CLKOUT_M_DIV_117												((uint8_t) 0x75)
    #define CLKOUT_M_DIV_118												((uint8_t) 0x76)
    #define CLKOUT_M_DIV_119												((uint8_t) 0x77)
    #define CLKOUT_M_DIV_120												((uint8_t) 0x78)
    #define CLKOUT_M_DIV_121												((uint8_t) 0x79)
    #define CLKOUT_M_DIV_122												((uint8_t) 0x7A)
    #define CLKOUT_M_DIV_123												((uint8_t) 0x7B)
    #define CLKOUT_M_DIV_124												((uint8_t) 0x7C)
    #define CLKOUT_M_DIV_125												((uint8_t) 0x7D)
    #define CLKOUT_M_DIV_126												((uint8_t) 0x7E)
    #define CLKOUT_M_DIV_127												((uint8_t) 0x7F)



/* Register 0x1B (ADC_AUDIO_IF_CONTROL1) definition
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       Bit 7       |       Bit 6       |       Bit 5       |       Bit 4       |       Bit 3       |       Bit 2       |       Bit 1       |       Bit 0       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |              ADC_IF[1:0]              |               WORD[1:0]               |        BCLK       |        WCLK       |      RESERVED     |   TRISTATE_DOUT   |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* ADC_AUDIO_IF_CONTROL1 register */
    #define ADC_AUDIO_IF_CONTROL1_ADDRESS									((uint8_t) 0x1B)
    #define ADC_AUDIO_IF_CONTROL1_DEFAULT									((uint8_t) 0x00)

    /* ADC_IF field */
    #define ADC_AUDIO_IF_CONTROL1_ADC_IF_MASK								((uint8_t) 0xC0)
    #define ADC_AUDIO_IF_CONTROL1_ADC_IF_I2S								((uint8_t) 0x00)    // DEFAULT
    #define ADC_AUDIO_IF_CONTROL1_ADC_IF_DSP								((uint8_t) 0x40)
    #define ADC_AUDIO_IF_CONTROL1_ADC_IF_RJF								((uint8_t) 0x80)
    #define ADC_AUDIO_IF_CONTROL1_ADC_IF_LJF								((uint8_t) 0xC0)

    /* WORD field */
    #define ADC_AUDIO_IF_CONTROL1_WORD_MASK									((uint8_t) 0x30)
    #define ADC_AUDIO_IF_CONTROL1_WORD_16									((uint8_t) 0x00)    // DEFAULT
    #define ADC_AUDIO_IF_CONTROL1_WORD_20									((uint8_t) 0x10)
    #define ADC_AUDIO_IF_CONTROL1_WORD_24									((uint8_t) 0x20)
    #define ADC_AUDIO_IF_CONTROL1_WORD_32									((uint8_t) 0x30)

    /* BCLK field */
    #define ADC_AUDIO_IF_CONTROL1_BCLK_MASK									((uint8_t) 0x08)
    #define ADC_AUDIO_IF_CONTROL1_BCLK_INPUT								((uint8_t) 0x00)    // DEFAULT
    #define ADC_AUDIO_IF_CONTROL1_BCLK_OUTPUT								((uint8_t) 0x08)

    /* WCLK field */
    #define ADC_AUDIO_IF_CONTROL1_WCLK_MASK									((uint8_t) 0x04)
    #define ADC_AUDIO_IF_CONTROL1_WCLK_INPUT								((uint8_t) 0x00)    // DEFAULT
    #define ADC_AUDIO_IF_CONTROL1_WCLK_OUTPUT								((uint8_t) 0x04)

    /* TRISTATE_DOUT field */
    #define ADC_AUDIO_IF_CONTROL1_TRISTATE_DOUT_MASK						((uint8_t) 0x01)
    #define ADC_AUDIO_IF_CONTROL1_TRISTATE_DOUT_DISABLED					((uint8_t) 0x00)    // DEFAULT
    #define ADC_AUDIO_IF_CONTROL1_TRISTATE_DOUT_ENABLED						((uint8_t) 0x01)



/* Register 0x1C (CH_OFFSET_1) definition
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       Bit 7       |       Bit 6       |       Bit 5       |       Bit 4       |       Bit 3       |       Bit 2       |       Bit 1       |       Bit 0       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                                                           BCLK[7:0]                                                                           |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* CH_OFFSET_1 register */
    #define CH_OFFSET_1_ADDRESS												((uint8_t) 0x1C)
    #define CH_OFFSET_1_DEFAULT												((uint8_t) 0x00)

    /* BCLK field */
    #define CH_OFFSET_1_BCLK_MASK											((uint8_t) 0xFF)
    #define CH_OFFSET_1_BCLK_0												((uint8_t) 0x00)    // DEFAULT
    #define CH_OFFSET_1_BCLK_1												((uint8_t) 0x01)
    #define CH_OFFSET_1_BCLK_2												((uint8_t) 0x02)
    #define CH_OFFSET_1_BCLK_3												((uint8_t) 0x03)
    #define CH_OFFSET_1_BCLK_4												((uint8_t) 0x04)
    #define CH_OFFSET_1_BCLK_5												((uint8_t) 0x05)
    #define CH_OFFSET_1_BCLK_6												((uint8_t) 0x06)
    #define CH_OFFSET_1_BCLK_7												((uint8_t) 0x07)
    #define CH_OFFSET_1_BCLK_8												((uint8_t) 0x08)
    #define CH_OFFSET_1_BCLK_9												((uint8_t) 0x09)
    #define CH_OFFSET_1_BCLK_10												((uint8_t) 0x0A)
    #define CH_OFFSET_1_BCLK_11												((uint8_t) 0x0B)
    #define CH_OFFSET_1_BCLK_12												((uint8_t) 0x0C)
    #define CH_OFFSET_1_BCLK_13												((uint8_t) 0x0D)
    #define CH_OFFSET_1_BCLK_14												((uint8_t) 0x0E)
    #define CH_OFFSET_1_BCLK_15												((uint8_t) 0x0F)
    #define CH_OFFSET_1_BCLK_16												((uint8_t) 0x10)
    #define CH_OFFSET_1_BCLK_17												((uint8_t) 0x11)
    #define CH_OFFSET_1_BCLK_18												((uint8_t) 0x12)
    #define CH_OFFSET_1_BCLK_19												((uint8_t) 0x13)
    #define CH_OFFSET_1_BCLK_20												((uint8_t) 0x14)
    #define CH_OFFSET_1_BCLK_21												((uint8_t) 0x15)
    #define CH_OFFSET_1_BCLK_22												((uint8_t) 0x16)
    #define CH_OFFSET_1_BCLK_23												((uint8_t) 0x17)
    #define CH_OFFSET_1_BCLK_24												((uint8_t) 0x18)
    #define CH_OFFSET_1_BCLK_25												((uint8_t) 0x19)
    #define CH_OFFSET_1_BCLK_26												((uint8_t) 0x1A)
    #define CH_OFFSET_1_BCLK_27												((uint8_t) 0x1B)
    #define CH_OFFSET_1_BCLK_28												((uint8_t) 0x1C)
    #define CH_OFFSET_1_BCLK_29												((uint8_t) 0x1D)
    #define CH_OFFSET_1_BCLK_30												((uint8_t) 0x1E)
    #define CH_OFFSET_1_BCLK_31												((uint8_t) 0x1F)
    #define CH_OFFSET_1_BCLK_32												((uint8_t) 0x20)
    #define CH_OFFSET_1_BCLK_33												((uint8_t) 0x21)
    #define CH_OFFSET_1_BCLK_34												((uint8_t) 0x22)
    #define CH_OFFSET_1_BCLK_35												((uint8_t) 0x23)
    #define CH_OFFSET_1_BCLK_36												((uint8_t) 0x24)
    #define CH_OFFSET_1_BCLK_37												((uint8_t) 0x25)
    #define CH_OFFSET_1_BCLK_38												((uint8_t) 0x26)
    #define CH_OFFSET_1_BCLK_39												((uint8_t) 0x27)
    #define CH_OFFSET_1_BCLK_40												((uint8_t) 0x28)
    #define CH_OFFSET_1_BCLK_41												((uint8_t) 0x29)
    #define CH_OFFSET_1_BCLK_42												((uint8_t) 0x2A)
    #define CH_OFFSET_1_BCLK_43												((uint8_t) 0x2B)
    #define CH_OFFSET_1_BCLK_44												((uint8_t) 0x2C)
    #define CH_OFFSET_1_BCLK_45												((uint8_t) 0x2D)
    #define CH_OFFSET_1_BCLK_46												((uint8_t) 0x2E)
    #define CH_OFFSET_1_BCLK_47												((uint8_t) 0x2F)
    #define CH_OFFSET_1_BCLK_48												((uint8_t) 0x30)
    #define CH_OFFSET_1_BCLK_49												((uint8_t) 0x31)
    #define CH_OFFSET_1_BCLK_50												((uint8_t) 0x32)
    #define CH_OFFSET_1_BCLK_51												((uint8_t) 0x33)
    #define CH_OFFSET_1_BCLK_52												((uint8_t) 0x34)
    #define CH_OFFSET_1_BCLK_53												((uint8_t) 0x35)
    #define CH_OFFSET_1_BCLK_54												((uint8_t) 0x36)
    #define CH_OFFSET_1_BCLK_55												((uint8_t) 0x37)
    #define CH_OFFSET_1_BCLK_56												((uint8_t) 0x38)
    #define CH_OFFSET_1_BCLK_57												((uint8_t) 0x39)
    #define CH_OFFSET_1_BCLK_58												((uint8_t) 0x3A)
    #define CH_OFFSET_1_BCLK_59												((uint8_t) 0x3B)
    #define CH_OFFSET_1_BCLK_60												((uint8_t) 0x3C)
    #define CH_OFFSET_1_BCLK_61												((uint8_t) 0x3D)
    #define CH_OFFSET_1_BCLK_62												((uint8_t) 0x3E)
    #define CH_OFFSET_1_BCLK_63												((uint8_t) 0x3F)
    #define CH_OFFSET_1_BCLK_64												((uint8_t) 0x40)



/* Register 0x1D (ADC_AUDIO_IF_CONTROL2) definition
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       Bit 7       |       Bit 6       |       Bit 5       |       Bit 4       |       Bit 3       |       Bit 2       |       Bit 1       |       Bit 0       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                 RESERVED[3:0]                                 |    BCLK_INVERT    |     BWCLK_PWR     |            BDIV_CLKIN[1:0]            |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* ADC_AUDIO_IF_CONTROL2 register */
    #define ADC_AUDIO_IF_CONTROL2_ADDRESS									((uint8_t) 0x1D)
    #define ADC_AUDIO_IF_CONTROL2_DEFAULT									((uint8_t) 0x02)

    /* BCLK_INVERT field */
    #define ADC_AUDIO_IF_CONTROL2_BCLK_INVERT_MASK							((uint8_t) 0x08)
    #define ADC_AUDIO_IF_CONTROL2_BCLK_INVERT_NOT_INVERTED					((uint8_t) 0x00)    // DEFAULT
    #define ADC_AUDIO_IF_CONTROL2_BCLK_INVERT_INVERTED						((uint8_t) 0x08)

    /* BWCLK_PWR field */
    #define ADC_AUDIO_IF_CONTROL2_BWCLK_PWR_MASK							((uint8_t) 0x04)
    #define ADC_AUDIO_IF_CONTROL2_BWCLK_PWR_INACTIVE						((uint8_t) 0x00)    // DEFAULT
    #define ADC_AUDIO_IF_CONTROL2_BWCLK_PWR_ACTIVE							((uint8_t) 0x04)

    /* BDIV_CLKIN field */
    #define ADC_AUDIO_IF_CONTROL2_BDIV_CLKIN_MASK							((uint8_t) 0x03)
    #define ADC_AUDIO_IF_CONTROL2_BDIV_CLKIN_ADC_CLK						((uint8_t) 0x02)    // DEFAULT
    #define ADC_AUDIO_IF_CONTROL2_BDIV_CLKIN_ADC_MOD_CLK					((uint8_t) 0x03)



/* Register 0x1E (BCLK_N) definition
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       Bit 7       |       Bit 6       |       Bit 5       |       Bit 4       |       Bit 3       |       Bit 2       |       Bit 1       |       Bit 0       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |        PWR        |                                                                  DIV[6:0]                                                                 |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* BCLK_N register */
    #define BCLK_N_ADDRESS													((uint8_t) 0x1E)
    #define BCLK_N_DEFAULT													((uint8_t) 0x01)

    /* PWR field */
    #define BCLK_N_PWR_MASK													((uint8_t) 0x80)
    #define BCLK_N_PWR_DOWN													((uint8_t) 0x00)    // DEFAULT
    #define BCLK_N_PWR_UP													((uint8_t) 0x80)

    /* DIV field */
    #define BCLK_N_DIV_MASK													((uint8_t) 0x7F)
    #define BCLK_N_DIV_128													((uint8_t) 0x00)
    #define BCLK_N_DIV_1													((uint8_t) 0x01)    // DEFAULT
    #define BCLK_N_DIV_2													((uint8_t) 0x02)
    #define BCLK_N_DIV_3													((uint8_t) 0x03)
    #define BCLK_N_DIV_4													((uint8_t) 0x04)
    #define BCLK_N_DIV_5													((uint8_t) 0x05)
    #define BCLK_N_DIV_6													((uint8_t) 0x06)
    #define BCLK_N_DIV_7													((uint8_t) 0x07)
    #define BCLK_N_DIV_8													((uint8_t) 0x08)
    #define BCLK_N_DIV_9													((uint8_t) 0x09)
    #define BCLK_N_DIV_10													((uint8_t) 0x0A)
    #define BCLK_N_DIV_11													((uint8_t) 0x0B)
    #define BCLK_N_DIV_12													((uint8_t) 0x0C)
    #define BCLK_N_DIV_13													((uint8_t) 0x0D)
    #define BCLK_N_DIV_14													((uint8_t) 0x0E)
    #define BCLK_N_DIV_15													((uint8_t) 0x0F)
    #define BCLK_N_DIV_16													((uint8_t) 0x10)
    #define BCLK_N_DIV_17													((uint8_t) 0x11)
    #define BCLK_N_DIV_18													((uint8_t) 0x12)
    #define BCLK_N_DIV_19													((uint8_t) 0x13)
    #define BCLK_N_DIV_20													((uint8_t) 0x14)
    #define BCLK_N_DIV_21													((uint8_t) 0x15)
    #define BCLK_N_DIV_22													((uint8_t) 0x16)
    #define BCLK_N_DIV_23													((uint8_t) 0x17)
    #define BCLK_N_DIV_24													((uint8_t) 0x18)
    #define BCLK_N_DIV_25													((uint8_t) 0x19)
    #define BCLK_N_DIV_26													((uint8_t) 0x1A)
    #define BCLK_N_DIV_27													((uint8_t) 0x1B)
    #define BCLK_N_DIV_28													((uint8_t) 0x1C)
    #define BCLK_N_DIV_29													((uint8_t) 0x1D)
    #define BCLK_N_DIV_30													((uint8_t) 0x1E)
    #define BCLK_N_DIV_31													((uint8_t) 0x1F)
    #define BCLK_N_DIV_32													((uint8_t) 0x20)
    #define BCLK_N_DIV_33													((uint8_t) 0x21)
    #define BCLK_N_DIV_34													((uint8_t) 0x22)
    #define BCLK_N_DIV_35													((uint8_t) 0x23)
    #define BCLK_N_DIV_36													((uint8_t) 0x24)
    #define BCLK_N_DIV_37													((uint8_t) 0x25)
    #define BCLK_N_DIV_38													((uint8_t) 0x26)
    #define BCLK_N_DIV_39													((uint8_t) 0x27)
    #define BCLK_N_DIV_40													((uint8_t) 0x28)
    #define BCLK_N_DIV_41													((uint8_t) 0x29)
    #define BCLK_N_DIV_42													((uint8_t) 0x2A)
    #define BCLK_N_DIV_43													((uint8_t) 0x2B)
    #define BCLK_N_DIV_44													((uint8_t) 0x2C)
    #define BCLK_N_DIV_45													((uint8_t) 0x2D)
    #define BCLK_N_DIV_46													((uint8_t) 0x2E)
    #define BCLK_N_DIV_47													((uint8_t) 0x2F)
    #define BCLK_N_DIV_48													((uint8_t) 0x30)
    #define BCLK_N_DIV_49													((uint8_t) 0x31)
    #define BCLK_N_DIV_50													((uint8_t) 0x32)
    #define BCLK_N_DIV_51													((uint8_t) 0x33)
    #define BCLK_N_DIV_52													((uint8_t) 0x34)
    #define BCLK_N_DIV_53													((uint8_t) 0x35)
    #define BCLK_N_DIV_54													((uint8_t) 0x36)
    #define BCLK_N_DIV_55													((uint8_t) 0x37)
    #define BCLK_N_DIV_56													((uint8_t) 0x38)
    #define BCLK_N_DIV_57													((uint8_t) 0x39)
    #define BCLK_N_DIV_58													((uint8_t) 0x3A)
    #define BCLK_N_DIV_59													((uint8_t) 0x3B)
    #define BCLK_N_DIV_60													((uint8_t) 0x3C)
    #define BCLK_N_DIV_61													((uint8_t) 0x3D)
    #define BCLK_N_DIV_62													((uint8_t) 0x3E)
    #define BCLK_N_DIV_63													((uint8_t) 0x3F)
    #define BCLK_N_DIV_64													((uint8_t) 0x40)
    #define BCLK_N_DIV_65													((uint8_t) 0x41)
    #define BCLK_N_DIV_66													((uint8_t) 0x42)
    #define BCLK_N_DIV_67													((uint8_t) 0x43)
    #define BCLK_N_DIV_68													((uint8_t) 0x44)
    #define BCLK_N_DIV_69													((uint8_t) 0x45)
    #define BCLK_N_DIV_70													((uint8_t) 0x46)
    #define BCLK_N_DIV_71													((uint8_t) 0x47)
    #define BCLK_N_DIV_72													((uint8_t) 0x48)
    #define BCLK_N_DIV_73													((uint8_t) 0x49)
    #define BCLK_N_DIV_74													((uint8_t) 0x4A)
    #define BCLK_N_DIV_75													((uint8_t) 0x4B)
    #define BCLK_N_DIV_76													((uint8_t) 0x4C)
    #define BCLK_N_DIV_77													((uint8_t) 0x4D)
    #define BCLK_N_DIV_78													((uint8_t) 0x4E)
    #define BCLK_N_DIV_79													((uint8_t) 0x4F)
    #define BCLK_N_DIV_80													((uint8_t) 0x50)
    #define BCLK_N_DIV_81													((uint8_t) 0x51)
    #define BCLK_N_DIV_82													((uint8_t) 0x52)
    #define BCLK_N_DIV_83													((uint8_t) 0x53)
    #define BCLK_N_DIV_84													((uint8_t) 0x54)
    #define BCLK_N_DIV_85													((uint8_t) 0x55)
    #define BCLK_N_DIV_86													((uint8_t) 0x56)
    #define BCLK_N_DIV_87													((uint8_t) 0x57)
    #define BCLK_N_DIV_88													((uint8_t) 0x58)
    #define BCLK_N_DIV_89													((uint8_t) 0x59)
    #define BCLK_N_DIV_90													((uint8_t) 0x5A)
    #define BCLK_N_DIV_91													((uint8_t) 0x5B)
    #define BCLK_N_DIV_92													((uint8_t) 0x5C)
    #define BCLK_N_DIV_93													((uint8_t) 0x5D)
    #define BCLK_N_DIV_94													((uint8_t) 0x5E)
    #define BCLK_N_DIV_95													((uint8_t) 0x5F)
    #define BCLK_N_DIV_96													((uint8_t) 0x60)
    #define BCLK_N_DIV_97													((uint8_t) 0x61)
    #define BCLK_N_DIV_98													((uint8_t) 0x62)
    #define BCLK_N_DIV_99													((uint8_t) 0x63)
    #define BCLK_N_DIV_100													((uint8_t) 0x64)
    #define BCLK_N_DIV_101													((uint8_t) 0x65)
    #define BCLK_N_DIV_102													((uint8_t) 0x66)
    #define BCLK_N_DIV_103													((uint8_t) 0x67)
    #define BCLK_N_DIV_104													((uint8_t) 0x68)
    #define BCLK_N_DIV_105													((uint8_t) 0x69)
    #define BCLK_N_DIV_106													((uint8_t) 0x6A)
    #define BCLK_N_DIV_107													((uint8_t) 0x6B)
    #define BCLK_N_DIV_108													((uint8_t) 0x6C)
    #define BCLK_N_DIV_109													((uint8_t) 0x6D)
    #define BCLK_N_DIV_110													((uint8_t) 0x6E)
    #define BCLK_N_DIV_111													((uint8_t) 0x6F)
    #define BCLK_N_DIV_112													((uint8_t) 0x70)
    #define BCLK_N_DIV_113													((uint8_t) 0x71)
    #define BCLK_N_DIV_114													((uint8_t) 0x72)
    #define BCLK_N_DIV_115													((uint8_t) 0x73)
    #define BCLK_N_DIV_116													((uint8_t) 0x74)
    #define BCLK_N_DIV_117													((uint8_t) 0x75)
    #define BCLK_N_DIV_118													((uint8_t) 0x76)
    #define BCLK_N_DIV_119													((uint8_t) 0x77)
    #define BCLK_N_DIV_120													((uint8_t) 0x78)
    #define BCLK_N_DIV_121													((uint8_t) 0x79)
    #define BCLK_N_DIV_122													((uint8_t) 0x7A)
    #define BCLK_N_DIV_123													((uint8_t) 0x7B)
    #define BCLK_N_DIV_124													((uint8_t) 0x7C)
    #define BCLK_N_DIV_125													((uint8_t) 0x7D)
    #define BCLK_N_DIV_126													((uint8_t) 0x7E)
    #define BCLK_N_DIV_127													((uint8_t) 0x7F)



/* Register 0x1F (SECOND_AUDIO_IF_CONTROL1) definition
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       Bit 7       |       Bit 6       |       Bit 5       |       Bit 4       |       Bit 3       |       Bit 2       |       Bit 1       |       Bit 0       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |      RESERVED     |             SEC_BCLK[1:0]             |             SEC_WCLK[1:0]             |             RESERVED[1:0]             |      RESERVED     |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* SECOND_AUDIO_IF_CONTROL1 register */
    #define SECOND_AUDIO_IF_CONTROL1_ADDRESS								((uint8_t) 0x1F)
    #define SECOND_AUDIO_IF_CONTROL1_DEFAULT								((uint8_t) 0x00)

    /* SEC_BCLK field */
    #define SECOND_AUDIO_IF_CONTROL1_SEC_BCLK_MASK							((uint8_t) 0x60)
    #define SECOND_AUDIO_IF_CONTROL1_SEC_BCLK_GPIO1							((uint8_t) 0x00)    // DEFAULT

    /* SEC_WCLK field */
    #define SECOND_AUDIO_IF_CONTROL1_SEC_WCLK_MASK							((uint8_t) 0x18)
    #define SECOND_AUDIO_IF_CONTROL1_SEC_WCLK_GPIO1							((uint8_t) 0x00)    // DEFAULT



/* Register 0x20 (SECOND_AUDIO_IF_CONTROL2) definition
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       Bit 7       |       Bit 6       |       Bit 5       |       Bit 4       |       Bit 3       |       Bit 2       |       Bit 1       |       Bit 0       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                 RESERVED[3:0]                                 |      BCLK_SEL     |      WCLK_SEL     |                   |      RESERVED     |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* SECOND_AUDIO_IF_CONTROL2 register */
    #define SECOND_AUDIO_IF_CONTROL2_ADDRESS								((uint8_t) 0x20)
    #define SECOND_AUDIO_IF_CONTROL2_DEFAULT								((uint8_t) 0x00)

    /* BCLK_SEL field */
    #define SECOND_AUDIO_IF_CONTROL2_BCLK_SEL_MASK							((uint8_t) 0x08)
    #define SECOND_AUDIO_IF_CONTROL2_BCLK_SEL_PRIMARY						((uint8_t) 0x00)    // DEFAULT
    #define SECOND_AUDIO_IF_CONTROL2_BCLK_SEL_SECONDARY						((uint8_t) 0x08)

    /* WCLK_SEL field */
    #define SECOND_AUDIO_IF_CONTROL2_WCLK_SEL_MASK							((uint8_t) 0x04)
    #define SECOND_AUDIO_IF_CONTROL2_WCLK_SEL_PRIMARY						((uint8_t) 0x00)    // DEFAULT
    #define SECOND_AUDIO_IF_CONTROL2_WCLK_SEL_SECONDARY						((uint8_t) 0x04)



/* Register 0x21 (SECOND_AUDIO_IF_CONTROL3) definition
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       Bit 7       |       Bit 6       |       Bit 5       |       Bit 4       |       Bit 3       |       Bit 2       |       Bit 1       |       Bit 0       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |    PRI_BCLK_SEL   |    SEC_BCLK_SEL   |           PRI_WCLK_SEL[1:0]           |           SEC_WCLK_SEL[1:0]           |             RESERVED[1:0]             |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* SECOND_AUDIO_IF_CONTROL3 register */
    #define SECOND_AUDIO_IF_CONTROL3_ADDRESS								((uint8_t) 0x21)
    #define SECOND_AUDIO_IF_CONTROL3_DEFAULT								((uint8_t) 0x00)

    /* PRI_BCLK_SEL field */
    #define SECOND_AUDIO_IF_CONTROL3_PRI_BCLK_SEL_MASK						((uint8_t) 0x80)
    #define SECOND_AUDIO_IF_CONTROL3_PRI_BCLK_SEL_INTERNAL					((uint8_t) 0x00)    // DEFAULT
    #define SECOND_AUDIO_IF_CONTROL3_PRI_BCLK_SEL_SECONDARY					((uint8_t) 0x80)

    /* SEC_BCLK_SEL field */
    #define SECOND_AUDIO_IF_CONTROL3_SEC_BCLK_SEL_MASK						((uint8_t) 0x40)
    #define SECOND_AUDIO_IF_CONTROL3_SEC_BCLK_SEL_PRIMARY					((uint8_t) 0x00)    // DEFAULT
    #define SECOND_AUDIO_IF_CONTROL3_SEC_BCLK_SEL_INTERNAL					((uint8_t) 0x40)

    /* PRI_WCLK_SEL field */
    #define SECOND_AUDIO_IF_CONTROL3_PRI_WCLK_SEL_MASK						((uint8_t) 0x30)
    #define SECOND_AUDIO_IF_CONTROL3_PRI_WCLK_SEL_INTERNAL					((uint8_t) 0x10)
    #define SECOND_AUDIO_IF_CONTROL3_PRI_WCLK_SEL_SECONDARY					((uint8_t) 0x20)

    /* SEC_WCLK_SEL field */
    #define SECOND_AUDIO_IF_CONTROL3_SEC_WCLK_SEL_MASK						((uint8_t) 0x0C)
    #define SECOND_AUDIO_IF_CONTROL3_SEC_WCLK_SEL_PRIMARY					((uint8_t) 0x00)    // DEFAULT
    #define SECOND_AUDIO_IF_CONTROL3_SEC_WCLK_SEL_INTERNAL					((uint8_t) 0x08)



/* Register 0x22 (I2S_SYNC) definition
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       Bit 7       |       Bit 6       |       Bit 5       |       Bit 4       |       Bit 3       |       Bit 2       |       Bit 1       |       Bit 0       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |      HANG_DET     |     HANG_FLAG     |      GEN_CALL     |                       RESERVED[2:0]                       |       RESYNC      |  RESYNC_SOFT_MUTE |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* I2S_SYNC register */
    #define I2S_SYNC_ADDRESS												((uint8_t) 0x22)
    #define I2S_SYNC_DEFAULT												((uint8_t) 0x00)

    /* HANG_DET field */
    #define I2S_SYNC_HANG_DET_MASK											((uint8_t) 0x80)
    #define I2S_SYNC_HANG_DET_ENABLED										((uint8_t) 0x00)    // DEFAULT
    #define I2S_SYNC_HANG_DET_DISABLED										((uint8_t) 0x80)

    /* HANG_FLAG field */
    #define I2S_SYNC_HANG_FLAG_MASK											((uint8_t) 0x40)
    #define I2S_SYNC_HANG_FLAG_NOT_DETECTED									((uint8_t) 0x00)    // DEFAULT
    #define I2S_SYNC_HANG_FLAG_DETECTED										((uint8_t) 0x40)

    /* GEN_CALL field */
    #define I2S_SYNC_GEN_CALL_MASK											((uint8_t) 0x20)
    #define I2S_SYNC_GEN_CALL_IGNORED										((uint8_t) 0x00)    // DEFAULT
    #define I2S_SYNC_GEN_CALL_ACCEPT										((uint8_t) 0x20)

    /* RESYNC field */
    #define I2S_SYNC_RESYNC_MASK											((uint8_t) 0x02)
    #define I2S_SYNC_RESYNC_DISABLED										((uint8_t) 0x00)    // DEFAULT
    #define I2S_SYNC_RESYNC_ENABLED											((uint8_t) 0x02)

    /* RESYNC_SOFT_MUTE field */
    #define I2S_SYNC_RESYNC_SOFT_MUTE_MASK									((uint8_t) 0x01)
    #define I2S_SYNC_RESYNC_SOFT_MUTE_NO									((uint8_t) 0x00)    // DEFAULT
    #define I2S_SYNC_RESYNC_SOFT_MUTE_YES									((uint8_t) 0x01)



/* Register 0x24 (ADC_FLAG) definition
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       Bit 7       |       Bit 6       |       Bit 5       |       Bit 4       |       Bit 3       |       Bit 2       |       Bit 1       |       Bit 0       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |     L_ADC_PGA     |     L_ADC_PWR     |     L_AGC_SAT     |      RESERVED     |     R_ADC_PGA     |     R_ADC_PWR     |     R_AGC_SAT     |      RESERVED     |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* ADC_FLAG register */
    #define ADC_FLAG_ADDRESS												((uint8_t) 0x24)
    #define ADC_FLAG_DEFAULT												((uint8_t) 0x00)

    /* L_ADC_PGA field */
    #define ADC_FLAG_L_ADC_PGA_MASK											((uint8_t) 0x80)
    #define ADC_FLAG_L_ADC_PGA_NOT_APPLIED									((uint8_t) 0x00)    // DEFAULT
    #define ADC_FLAG_L_ADC_PGA_APPLIED										((uint8_t) 0x80)

    /* L_ADC_PWR field */
    #define ADC_FLAG_L_ADC_PWR_MASK											((uint8_t) 0x40)
    #define ADC_FLAG_L_ADC_PWR_DOWN											((uint8_t) 0x00)    // DEFAULT
    #define ADC_FLAG_L_ADC_PWR_UP											((uint8_t) 0x40)

    /* L_AGC_SAT field */
    #define ADC_FLAG_L_AGC_SAT_MASK											((uint8_t) 0x20)
    #define ADC_FLAG_L_AGC_SAT_NOT_SATURATED								((uint8_t) 0x00)    // DEFAULT
    #define ADC_FLAG_L_AGC_SAT_SATURATED									((uint8_t) 0x20)

    /* R_ADC_PGA field */
    #define ADC_FLAG_R_ADC_PGA_MASK											((uint8_t) 0x08)
    #define ADC_FLAG_R_ADC_PGA_NOT_APPLIED									((uint8_t) 0x00)    // DEFAULT
    #define ADC_FLAG_R_ADC_PGA_APPLIED										((uint8_t) 0x08)

    /* R_ADC_PWR field */
    #define ADC_FLAG_R_ADC_PWR_MASK											((uint8_t) 0x04)
    #define ADC_FLAG_R_ADC_PWR_DOWN											((uint8_t) 0x00)    // DEFAULT
    #define ADC_FLAG_R_ADC_PWR_UP											((uint8_t) 0x04)

    /* R_AGC_SAT field */
    #define ADC_FLAG_R_AGC_SAT_MASK											((uint8_t) 0x02)
    #define ADC_FLAG_R_AGC_SAT_NOT_SATURATED								((uint8_t) 0x00)    // DEFAULT
    #define ADC_FLAG_R_AGC_SAT_SATURATED									((uint8_t) 0x02)



/* Register 0x25 (CH_OFFSET_2) definition
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       Bit 7       |       Bit 6       |       Bit 5       |       Bit 4       |       Bit 3       |       Bit 2       |       Bit 1       |       Bit 0       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                                                           BCLK[7:0]                                                                           |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* CH_OFFSET_2 register */
    #define CH_OFFSET_2_ADDRESS												((uint8_t) 0x25)
    #define CH_OFFSET_2_DEFAULT												((uint8_t) 0x00)

    /* BCLK field */
    #define CH_OFFSET_2_BCLK_MASK											((uint8_t) 0xFF)
    #define CH_OFFSET_2_BCLK_0												((uint8_t) 0x00)    // DEFAULT
    #define CH_OFFSET_2_BCLK_1												((uint8_t) 0x01)
    #define CH_OFFSET_2_BCLK_2												((uint8_t) 0x02)
    #define CH_OFFSET_2_BCLK_3												((uint8_t) 0x03)
    #define CH_OFFSET_2_BCLK_4												((uint8_t) 0x04)
    #define CH_OFFSET_2_BCLK_5												((uint8_t) 0x05)
    #define CH_OFFSET_2_BCLK_6												((uint8_t) 0x06)
    #define CH_OFFSET_2_BCLK_7												((uint8_t) 0x07)
    #define CH_OFFSET_2_BCLK_8												((uint8_t) 0x08)
    #define CH_OFFSET_2_BCLK_9												((uint8_t) 0x09)
    #define CH_OFFSET_2_BCLK_10												((uint8_t) 0x0A)
    #define CH_OFFSET_2_BCLK_11												((uint8_t) 0x0B)
    #define CH_OFFSET_2_BCLK_12												((uint8_t) 0x0C)
    #define CH_OFFSET_2_BCLK_13												((uint8_t) 0x0D)
    #define CH_OFFSET_2_BCLK_14												((uint8_t) 0x0E)
    #define CH_OFFSET_2_BCLK_15												((uint8_t) 0x0F)
    #define CH_OFFSET_2_BCLK_16												((uint8_t) 0x10)
    #define CH_OFFSET_2_BCLK_17												((uint8_t) 0x11)
    #define CH_OFFSET_2_BCLK_18												((uint8_t) 0x12)
    #define CH_OFFSET_2_BCLK_19												((uint8_t) 0x13)
    #define CH_OFFSET_2_BCLK_20												((uint8_t) 0x14)
    #define CH_OFFSET_2_BCLK_21												((uint8_t) 0x15)
    #define CH_OFFSET_2_BCLK_22												((uint8_t) 0x16)
    #define CH_OFFSET_2_BCLK_23												((uint8_t) 0x17)
    #define CH_OFFSET_2_BCLK_24												((uint8_t) 0x18)
    #define CH_OFFSET_2_BCLK_25												((uint8_t) 0x19)
    #define CH_OFFSET_2_BCLK_26												((uint8_t) 0x1A)
    #define CH_OFFSET_2_BCLK_27												((uint8_t) 0x1B)
    #define CH_OFFSET_2_BCLK_28												((uint8_t) 0x1C)
    #define CH_OFFSET_2_BCLK_29												((uint8_t) 0x1D)
    #define CH_OFFSET_2_BCLK_30												((uint8_t) 0x1E)
    #define CH_OFFSET_2_BCLK_31												((uint8_t) 0x1F)
    #define CH_OFFSET_2_BCLK_32												((uint8_t) 0x20)
    #define CH_OFFSET_2_BCLK_33												((uint8_t) 0x21)
    #define CH_OFFSET_2_BCLK_34												((uint8_t) 0x22)
    #define CH_OFFSET_2_BCLK_35												((uint8_t) 0x23)
    #define CH_OFFSET_2_BCLK_36												((uint8_t) 0x24)
    #define CH_OFFSET_2_BCLK_37												((uint8_t) 0x25)
    #define CH_OFFSET_2_BCLK_38												((uint8_t) 0x26)
    #define CH_OFFSET_2_BCLK_39												((uint8_t) 0x27)
    #define CH_OFFSET_2_BCLK_40												((uint8_t) 0x28)
    #define CH_OFFSET_2_BCLK_41												((uint8_t) 0x29)
    #define CH_OFFSET_2_BCLK_42												((uint8_t) 0x2A)
    #define CH_OFFSET_2_BCLK_43												((uint8_t) 0x2B)
    #define CH_OFFSET_2_BCLK_44												((uint8_t) 0x2C)
    #define CH_OFFSET_2_BCLK_45												((uint8_t) 0x2D)
    #define CH_OFFSET_2_BCLK_46												((uint8_t) 0x2E)
    #define CH_OFFSET_2_BCLK_47												((uint8_t) 0x2F)
    #define CH_OFFSET_2_BCLK_48												((uint8_t) 0x30)
    #define CH_OFFSET_2_BCLK_49												((uint8_t) 0x31)
    #define CH_OFFSET_2_BCLK_50												((uint8_t) 0x32)
    #define CH_OFFSET_2_BCLK_51												((uint8_t) 0x33)
    #define CH_OFFSET_2_BCLK_52												((uint8_t) 0x34)
    #define CH_OFFSET_2_BCLK_53												((uint8_t) 0x35)
    #define CH_OFFSET_2_BCLK_54												((uint8_t) 0x36)
    #define CH_OFFSET_2_BCLK_55												((uint8_t) 0x37)
    #define CH_OFFSET_2_BCLK_56												((uint8_t) 0x38)
    #define CH_OFFSET_2_BCLK_57												((uint8_t) 0x39)
    #define CH_OFFSET_2_BCLK_58												((uint8_t) 0x3A)
    #define CH_OFFSET_2_BCLK_59												((uint8_t) 0x3B)
    #define CH_OFFSET_2_BCLK_60												((uint8_t) 0x3C)
    #define CH_OFFSET_2_BCLK_61												((uint8_t) 0x3D)
    #define CH_OFFSET_2_BCLK_62												((uint8_t) 0x3E)
    #define CH_OFFSET_2_BCLK_63												((uint8_t) 0x3F)
    #define CH_OFFSET_2_BCLK_64												((uint8_t) 0x40)



/* Register 0x26 (I2S_TDM_CONTROL) definition
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       Bit 7       |       Bit 6       |       Bit 5       |       Bit 4       |       Bit 3       |       Bit 2       |       Bit 1       |       Bit 0       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                       RESERVED[2:0]                       |      CH_SWAP      |               CH_EN[1:0]              |   TRISTATE_EARLY  |   TIME_SLOT_MODE  |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* I2S_TDM_CONTROL register */
    #define I2S_TDM_CONTROL_ADDRESS											((uint8_t) 0x26)
    #define I2S_TDM_CONTROL_DEFAULT											((uint8_t) 0x02)

    /* CH_SWAP field */
    #define I2S_TDM_CONTROL_CH_SWAP_MASK									((uint8_t) 0x10)
    #define I2S_TDM_CONTROL_CH_SWAP_DISABLED								((uint8_t) 0x00)    // DEFAULT
    #define I2S_TDM_CONTROL_CH_SWAP_ENABLED									((uint8_t) 0x10)

    /* CH_EN field */
    #define I2S_TDM_CONTROL_CH_EN_MASK										((uint8_t) 0x0C)
    #define I2S_TDM_CONTROL_CH_EN_BOTH_ENABLED								((uint8_t) 0x00)    // DEFAULT
    #define I2S_TDM_CONTROL_CH_EN_LEFT_ENABLED								((uint8_t) 0x04)
    #define I2S_TDM_CONTROL_CH_EN_RIGHT_ENABLED								((uint8_t) 0x08)
    #define I2S_TDM_CONTROL_CH_EN_BOTH_DISABLED								((uint8_t) 0x0C)

    /* TRISTATE_EARLY field */
    #define I2S_TDM_CONTROL_TRISTATE_EARLY_MASK								((uint8_t) 0x02)
    #define I2S_TDM_CONTROL_TRISTATE_EARLY_DISABLED							((uint8_t) 0x00)
    #define I2S_TDM_CONTROL_TRISTATE_EARLY_ENABLED							((uint8_t) 0x02)    // DEFAULT

    /* TIME_SLOT_MODE field */
    #define I2S_TDM_CONTROL_TIME_SLOT_MODE_MASK								((uint8_t) 0x01)
    #define I2S_TDM_CONTROL_TIME_SLOT_MODE_DISABLED							((uint8_t) 0x00)    // DEFAULT
    #define I2S_TDM_CONTROL_TIME_SLOT_MODE_ENABLED							((uint8_t) 0x01)



/* Register 0x2A (OVERF_INT_FLAG_1) definition
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       Bit 7       |       Bit 6       |       Bit 5       |       Bit 4       |       Bit 3       |       Bit 2       |       Bit 1       |       Bit 0       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                 RESERVED[3:0]                                 |    L_ADC_OVERF    |    R_ADC_OVERF    |  ADC_BARREL_OVERF |      RESERVED     |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* OVERF_INT_FLAG_1 register */
    #define OVERF_INT_FLAG_1_ADDRESS										((uint8_t) 0x2A)
    #define OVERF_INT_FLAG_1_DEFAULT										((uint8_t) 0x00)

    /* L_ADC_OVERF field */
    #define OVERF_INT_FLAG_1_L_ADC_OVERF_MASK								((uint8_t) 0x08)
    #define OVERF_INT_FLAG_1_L_ADC_OVERF_NORMAL								((uint8_t) 0x00)    // DEFAULT
    #define OVERF_INT_FLAG_1_L_ADC_OVERF_OVERFLOW							((uint8_t) 0x08)

    /* R_ADC_OVERF field */
    #define OVERF_INT_FLAG_1_R_ADC_OVERF_MASK								((uint8_t) 0x04)
    #define OVERF_INT_FLAG_1_R_ADC_OVERF_NORMAL								((uint8_t) 0x00)    // DEFAULT
    #define OVERF_INT_FLAG_1_R_ADC_OVERF_OVERFLOW							((uint8_t) 0x04)

    /* ADC_BARREL_OVERF field */
    #define OVERF_INT_FLAG_1_ADC_BARREL_OVERF_MASK							((uint8_t) 0x02)
    #define OVERF_INT_FLAG_1_ADC_BARREL_OVERF_NORMAL						((uint8_t) 0x00)    // DEFAULT
    #define OVERF_INT_FLAG_1_ADC_BARREL_OVERF_OVERFLOW						((uint8_t) 0x02)



/* Register 0x2B (OVERF_INT_FLAG_2) definition
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       Bit 7       |       Bit 6       |       Bit 5       |       Bit 4       |       Bit 3       |       Bit 2       |       Bit 1       |       Bit 0       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                 RESERVED[3:0]                                 |    L_ADC_OVERF    |    R_ADC_OVERF    |  ADC_BARREL_OVERF |      RESERVED     |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* OVERF_INT_FLAG_2 register */
    #define OVERF_INT_FLAG_2_ADDRESS										((uint8_t) 0x2B)
    #define OVERF_INT_FLAG_2_DEFAULT										((uint8_t) 0x00)

    /* L_ADC_OVERF field */
    #define OVERF_INT_FLAG_2_L_ADC_OVERF_MASK								((uint8_t) 0x08)
    #define OVERF_INT_FLAG_2_L_ADC_OVERF_NORMAL								((uint8_t) 0x00)    // DEFAULT
    #define OVERF_INT_FLAG_2_L_ADC_OVERF_OVERFLOW							((uint8_t) 0x08)

    /* R_ADC_OVERF field */
    #define OVERF_INT_FLAG_2_R_ADC_OVERF_MASK								((uint8_t) 0x04)
    #define OVERF_INT_FLAG_2_R_ADC_OVERF_NORMAL								((uint8_t) 0x00)    // DEFAULT
    #define OVERF_INT_FLAG_2_R_ADC_OVERF_OVERFLOW							((uint8_t) 0x04)

    /* ADC_BARREL_OVERF field */
    #define OVERF_INT_FLAG_2_ADC_BARREL_OVERF_MASK							((uint8_t) 0x02)
    #define OVERF_INT_FLAG_2_ADC_BARREL_OVERF_NORMAL						((uint8_t) 0x00)    // DEFAULT
    #define OVERF_INT_FLAG_2_ADC_BARREL_OVERF_OVERFLOW						((uint8_t) 0x02)



/* Register 0x2D (AGC_INT_FLAG) definition
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       Bit 7       |       Bit 6       |       Bit 5       |       Bit 4       |       Bit 3       |       Bit 2       |       Bit 1       |       Bit 0       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |      RESERVED     | L_AGC_NOISE_THRES | R_AGC_NOISE_THRES |  ADC_STD_IO_PORT  |  ADC_AUX_IO_PORT  |                       RESERVED[2:0]                       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* AGC_INT_FLAG register */
    #define AGC_INT_FLAG_ADDRESS											((uint8_t) 0x2D)
    #define AGC_INT_FLAG_DEFAULT											((uint8_t) 0x00)

    /* L_AGC_NOISE_THRES field */
    #define AGC_INT_FLAG_L_AGC_NOISE_THRES_MASK								((uint8_t) 0x40)
    #define AGC_INT_FLAG_L_AGC_NOISE_THRES_GREATER							((uint8_t) 0x00)    // DEFAULT
    #define AGC_INT_FLAG_L_AGC_NOISE_THRES_LESS								((uint8_t) 0x40)

    /* R_AGC_NOISE_THRES field */
    #define AGC_INT_FLAG_R_AGC_NOISE_THRES_MASK								((uint8_t) 0x20)
    #define AGC_INT_FLAG_R_AGC_NOISE_THRES_GREATER							((uint8_t) 0x00)    // DEFAULT
    #define AGC_INT_FLAG_R_AGC_NOISE_THRES_LESS								((uint8_t) 0x20)



/* Register 0x2F (ADC_INT_FLAG) definition
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       Bit 7       |       Bit 6       |       Bit 5       |       Bit 4       |       Bit 3       |       Bit 2       |       Bit 1       |       Bit 0       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |      RESERVED     |   L_ADC_PWR_STAT  |   R_ADC_PWR_STAT  |   ADC_FILTER_STD  |   ADC_FILTER_AUX  |                       RESERVED[2:0]                       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* ADC_INT_FLAG register */
    #define ADC_INT_FLAG_ADDRESS											((uint8_t) 0x2F)
    #define ADC_INT_FLAG_DEFAULT											((uint8_t) 0x00)

    /* L_ADC_PWR_STAT field */
    #define ADC_INT_FLAG_L_ADC_PWR_STAT_MASK								((uint8_t) 0x40)
    #define ADC_INT_FLAG_L_ADC_PWR_STAT_DOWN								((uint8_t) 0x00)    // DEFAULT
    #define ADC_INT_FLAG_L_ADC_PWR_STAT_UP									((uint8_t) 0x40)

    /* R_ADC_PWR_STAT field */
    #define ADC_INT_FLAG_R_ADC_PWR_STAT_MASK								((uint8_t) 0x20)
    #define ADC_INT_FLAG_R_ADC_PWR_STAT_DOWN								((uint8_t) 0x00)    // DEFAULT
    #define ADC_INT_FLAG_R_ADC_PWR_STAT_UP									((uint8_t) 0x20)



/* Register 0x30 (INT1_CONTROL) definition
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       Bit 7       |       Bit 6       |       Bit 5       |       Bit 4       |       Bit 3       |       Bit 2       |       Bit 1       |       Bit 0       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                       RESERVED[2:0]                       |     ADC_NOISE     |      RESERVED     |        ENG        |      ADC_DRDY     |         0         |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* INT1_CONTROL register */
    #define INT1_CONTROL_ADDRESS											((uint8_t) 0x30)
    #define INT1_CONTROL_DEFAULT											((uint8_t) 0x00)

    /* ADC_NOISE field */
    #define INT1_CONTROL_ADC_NOISE_MASK										((uint8_t) 0x10)
    #define INT1_CONTROL_ADC_NOISE_DISABLE									((uint8_t) 0x00)    // DEFAULT
    #define INT1_CONTROL_ADC_NOISE_ENABLE									((uint8_t) 0x10)

    /* ENG field */
    #define INT1_CONTROL_ENG_MASK											((uint8_t) 0x04)
    #define INT1_CONTROL_ENG_DISABLE										((uint8_t) 0x00)    // DEFAULT
    #define INT1_CONTROL_ENG_ENABLE											((uint8_t) 0x04)

    /* ADC_DRDY field */
    #define INT1_CONTROL_ADC_DRDY_MASK										((uint8_t) 0x02)
    #define INT1_CONTROL_ADC_DRDY_DISABLE									((uint8_t) 0x00)    // DEFAULT
    #define INT1_CONTROL_ADC_DRDY_ENABLE									((uint8_t) 0x02)

    /* PULSES field */
    #define INT1_CONTROL_PULSES_MASK										((uint8_t) 0x01)
    #define INT1_CONTROL_PULSES_ONE											((uint8_t) 0x00)    // DEFAULT
    #define INT1_CONTROL_PULSES_MULTIPLE									((uint8_t) 0x01)



/* Register 0x31 (INT2_CONTROL) definition
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       Bit 7       |       Bit 6       |       Bit 5       |       Bit 4       |       Bit 3       |       Bit 2       |       Bit 1       |       Bit 0       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                       RESERVED[2:0]                       |     ADC_NOISE     |      RESERVED     |        ENG        |      ADC_DRDY     |         0         |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* INT2_CONTROL register */
    #define INT2_CONTROL_ADDRESS											((uint8_t) 0x31)
    #define INT2_CONTROL_DEFAULT											((uint8_t) 0x00)

    /* ADC_NOISE field */
    #define INT2_CONTROL_ADC_NOISE_MASK										((uint8_t) 0x10)
    #define INT2_CONTROL_ADC_NOISE_DISABLE									((uint8_t) 0x00)    // DEFAULT
    #define INT2_CONTROL_ADC_NOISE_ENABLE									((uint8_t) 0x10)

    /* ENG field */
    #define INT2_CONTROL_ENG_MASK											((uint8_t) 0x04)
    #define INT2_CONTROL_ENG_DISABLE										((uint8_t) 0x00)    // DEFAULT
    #define INT2_CONTROL_ENG_ENABLE											((uint8_t) 0x04)

    /* ADC_DRDY field */
    #define INT2_CONTROL_ADC_DRDY_MASK										((uint8_t) 0x02)
    #define INT2_CONTROL_ADC_DRDY_DISABLE									((uint8_t) 0x00)    // DEFAULT
    #define INT2_CONTROL_ADC_DRDY_ENABLE									((uint8_t) 0x02)

    /* PULSES field */
    #define INT2_CONTROL_PULSES_MASK										((uint8_t) 0x01)
    #define INT2_CONTROL_PULSES_ONE											((uint8_t) 0x00)    // DEFAULT
    #define INT2_CONTROL_PULSES_MULTIPLE									((uint8_t) 0x01)



/* Register 0x34 (GPIO1_CONTROL) definition
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       Bit 7       |       Bit 6       |       Bit 5       |       Bit 4       |       Bit 3       |       Bit 2       |       Bit 1       |       Bit 0       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |             RESERVED[1:0]             |                                    SEL[3:0]                                   |      BUFF_VAL     |         0         |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* GPIO1_CONTROL register */
    #define GPIO1_CONTROL_ADDRESS											((uint8_t) 0x34)
    #define GPIO1_CONTROL_DEFAULT											((uint8_t) 0x00)

    /* SEL field */
    #define GPIO1_CONTROL_SEL_MASK											((uint8_t) 0x3C)
    #define GPIO1_CONTROL_SEL_DISABLE										((uint8_t) 0x00)    // DEFAULT
    #define GPIO1_CONTROL_SEL_INPUT											((uint8_t) 0x04)
    #define GPIO1_CONTROL_SEL_GPI											((uint8_t) 0x08)
    #define GPIO1_CONTROL_SEL_GPO											((uint8_t) 0x0C)
    #define GPIO1_CONTROL_SEL_CLKOUT										((uint8_t) 0x10)
    #define GPIO1_CONTROL_SEL_INT1											((uint8_t) 0x14)
    #define GPIO1_CONTROL_SEL_INT2											((uint8_t) 0x18)
    #define GPIO1_CONTROL_SEL_SEC_BLCK										((uint8_t) 0x20)
    #define GPIO1_CONTROL_SEL_SEC_WCLK										((uint8_t) 0x24)
    #define GPIO1_CONTROL_SEL_ADC_MOD_CLK									((uint8_t) 0x28)

    /* BUFF_VAL field */
    #define GPIO1_CONTROL_BUFF_VAL_MASK										((uint8_t) 0x02)
    #define GPIO1_CONTROL_BUFF_VAL_DISABLE									((uint8_t) 0x00)    // DEFAULT
    #define GPIO1_CONTROL_BUFF_VAL_ENABLE									((uint8_t) 0x02)

    /* VAL field */
    #define GPIO1_CONTROL_VAL_MASK											((uint8_t) 0x01)
    #define GPIO1_CONTROL_VAL_LOW											((uint8_t) 0x00)    // DEFAULT
    #define GPIO1_CONTROL_VAL_HIGH											((uint8_t) 0x01)



/* Register 0x35 (DOUT_CONTROL) definition
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       Bit 7       |       Bit 6       |       Bit 5       |       Bit 4       |       Bit 3       |       Bit 2       |       Bit 1       |       Bit 0       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                       RESERVED[2:0]                       |      BUS_KEEP     |                          SEL[2:0]                         |         0         |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* DOUT_CONTROL register */
    #define DOUT_CONTROL_ADDRESS											((uint8_t) 0x35)
    #define DOUT_CONTROL_DEFAULT											((uint8_t) 0x12)

    /* BUS_KEEP field */
    #define DOUT_CONTROL_BUS_KEEP_MASK										((uint8_t) 0x10)
    #define DOUT_CONTROL_BUS_KEEP_ENABLE									((uint8_t) 0x00)
    #define DOUT_CONTROL_BUS_KEEP_DISABLE									((uint8_t) 0x10)    // DEFAULT

    /* SEL field */
    #define DOUT_CONTROL_SEL_MASK											((uint8_t) 0x0E)
    #define DOUT_CONTROL_SEL_DISABLE										((uint8_t) 0x00)
    #define DOUT_CONTROL_SEL_PRIMARY										((uint8_t) 0x02)    // DEFAULT
    #define DOUT_CONTROL_SEL_GPO											((uint8_t) 0x04)
    #define DOUT_CONTROL_SEL_CLKOUT											((uint8_t) 0x06)
    #define DOUT_CONTROL_SEL_INT1											((uint8_t) 0x08)
    #define DOUT_CONTROL_SEL_INT2											((uint8_t) 0x0A)
    #define DOUT_CONTROL_SEL_SEC_BLCK										((uint8_t) 0x0C)
    #define DOUT_CONTROL_SEL_SEC_WCLK										((uint8_t) 0x0E)

    /* VAL field */
    #define DOUT_CONTROL_VAL_MASK											((uint8_t) 0x01)
    #define DOUT_CONTROL_VAL_LOW											((uint8_t) 0x00)    // DEFAULT
    #define DOUT_CONTROL_VAL_HIGH											((uint8_t) 0x01)



/* Register 0x39 (ADC_SYNC_CONTROL1) definition
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       Bit 7       |       Bit 6       |       Bit 5       |       Bit 4       |       Bit 3       |       Bit 2       |       Bit 1       |       Bit 0       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |         0         |                                                       SYNC1[5:0]                                                      |                   |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* ADC_SYNC_CONTROL1 register */
    #define ADC_SYNC_CONTROL1_ADDRESS										((uint8_t) 0x39)
    #define ADC_SYNC_CONTROL1_DEFAULT										((uint8_t) 0x00)

    /* SEL field */
    #define ADC_SYNC_CONTROL1_SEL_MASK										((uint8_t) 0x80)
    #define ADC_SYNC_CONTROL1_SEL_DEFAULT									((uint8_t) 0x00)    // DEFAULT
    #define ADC_SYNC_CONTROL1_SEL_CUSTOM									((uint8_t) 0x80)

    /* SYNC1 field */
    #define ADC_SYNC_CONTROL1_SYNC1_MASK									((uint8_t) 0x7E)
    #define ADC_SYNC_CONTROL1_SYNC1_0										((uint8_t) 0x00)    // DEFAULT
    #define ADC_SYNC_CONTROL1_SYNC1_2										((uint8_t) 0x02)
    #define ADC_SYNC_CONTROL1_SYNC1_4										((uint8_t) 0x04)
    #define ADC_SYNC_CONTROL1_SYNC1_6										((uint8_t) 0x06)
    #define ADC_SYNC_CONTROL1_SYNC1_8										((uint8_t) 0x08)
    #define ADC_SYNC_CONTROL1_SYNC1_10										((uint8_t) 0x0A)
    #define ADC_SYNC_CONTROL1_SYNC1_12										((uint8_t) 0x0C)
    #define ADC_SYNC_CONTROL1_SYNC1_14										((uint8_t) 0x0E)



/* Register 0x3A (ADC_SYNC_CONTROL2) definition
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       Bit 7       |       Bit 6       |       Bit 5       |       Bit 4       |       Bit 3       |       Bit 2       |       Bit 1       |       Bit 0       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                                                 SYNC2[6:0]                                                                |                   |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* ADC_SYNC_CONTROL2 register */
    #define ADC_SYNC_CONTROL2_ADDRESS										((uint8_t) 0x3A)
    #define ADC_SYNC_CONTROL2_DEFAULT										((uint8_t) 0x00)

    /* SYNC2 field */
    #define ADC_SYNC_CONTROL2_SYNC2_MASK									((uint8_t) 0xFE)
    #define ADC_SYNC_CONTROL2_SYNC2_0										((uint8_t) 0x00)    // DEFAULT
    #define ADC_SYNC_CONTROL2_SYNC2_2										((uint8_t) 0x02)
    #define ADC_SYNC_CONTROL2_SYNC2_4										((uint8_t) 0x04)
    #define ADC_SYNC_CONTROL2_SYNC2_6										((uint8_t) 0x06)
    #define ADC_SYNC_CONTROL2_SYNC2_8										((uint8_t) 0x08)
    #define ADC_SYNC_CONTROL2_SYNC2_10										((uint8_t) 0x0A)
    #define ADC_SYNC_CONTROL2_SYNC2_12										((uint8_t) 0x0C)
    #define ADC_SYNC_CONTROL2_SYNC2_14										((uint8_t) 0x0E)



/* Register 0x3B (ADC_CIC_GAIN) definition
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       Bit 7       |       Bit 6       |       Bit 5       |       Bit 4       |       Bit 3       |       Bit 2       |       Bit 1       |       Bit 0       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                   LEFT[3:0]                                   |                                   RIGHT[3:0]                                  |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* ADC_CIC_GAIN register */
    #define ADC_CIC_GAIN_ADDRESS											((uint8_t) 0x3B)
    #define ADC_CIC_GAIN_DEFAULT											((uint8_t) 0x44)



/* Register 0x3D (ADC_PROC_BLOCK) definition
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       Bit 7       |       Bit 6       |       Bit 5       |       Bit 4       |       Bit 3       |       Bit 2       |       Bit 1       |       Bit 0       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                       RESERVED[2:0]                       |                                              SEL[4:0]                                             |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* ADC_PROC_BLOCK register */
    #define ADC_PROC_BLOCK_ADDRESS											((uint8_t) 0x3D)
    #define ADC_PROC_BLOCK_DEFAULT											((uint8_t) 0x01)

    /* SEL field */
    #define ADC_PROC_BLOCK_SEL_MASK											((uint8_t) 0x1F)
    #define ADC_PROC_BLOCK_SEL_PRB_R1										((uint8_t) 0x01)    // DEFAULT
    #define ADC_PROC_BLOCK_SEL_PRB_R2										((uint8_t) 0x02)
    #define ADC_PROC_BLOCK_SEL_PRB_R3										((uint8_t) 0x03)
    #define ADC_PROC_BLOCK_SEL_PRB_R4										((uint8_t) 0x04)
    #define ADC_PROC_BLOCK_SEL_PRB_R5										((uint8_t) 0x05)
    #define ADC_PROC_BLOCK_SEL_PRB_R6										((uint8_t) 0x06)
    #define ADC_PROC_BLOCK_SEL_PRB_R7										((uint8_t) 0x07)
    #define ADC_PROC_BLOCK_SEL_PRB_R8										((uint8_t) 0x08)
    #define ADC_PROC_BLOCK_SEL_PRB_R9										((uint8_t) 0x09)
    #define ADC_PROC_BLOCK_SEL_PRB_R10										((uint8_t) 0x0A)
    #define ADC_PROC_BLOCK_SEL_PRB_R11										((uint8_t) 0x0B)
    #define ADC_PROC_BLOCK_SEL_PRB_R12										((uint8_t) 0x0C)
    #define ADC_PROC_BLOCK_SEL_PRB_R13										((uint8_t) 0x0D)
    #define ADC_PROC_BLOCK_SEL_PRB_R14										((uint8_t) 0x0E)
    #define ADC_PROC_BLOCK_SEL_PRB_R15										((uint8_t) 0x0F)
    #define ADC_PROC_BLOCK_SEL_PRB_R16										((uint8_t) 0x10)
    #define ADC_PROC_BLOCK_SEL_PRB_R17										((uint8_t) 0x11)
    #define ADC_PROC_BLOCK_SEL_PRB_R18										((uint8_t) 0x12)



/* Register 0x51 (ADC_DIGITAL) definition
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       Bit 7       |       Bit 6       |       Bit 5       |       Bit 4       |       Bit 3       |       Bit 2       |       Bit 1       |       Bit 0       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |     L_ADC_PWR     |     R_ADC_PWR     |                                 RESERVED[3:0]                                 |                 0[1:0]                |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* ADC_DIGITAL register */
    #define ADC_DIGITAL_ADDRESS												((uint8_t) 0x51)
    #define ADC_DIGITAL_DEFAULT												((uint8_t) 0x00)

    /* L_ADC_PWR field */
    #define ADC_DIGITAL_L_ADC_PWR_MASK										((uint8_t) 0x80)
    #define ADC_DIGITAL_L_ADC_PWR_DOWN										((uint8_t) 0x00)    // DEFAULT
    #define ADC_DIGITAL_L_ADC_PWR_UP										((uint8_t) 0x80)

    /* R_ADC_PWR field */
    #define ADC_DIGITAL_R_ADC_PWR_MASK										((uint8_t) 0x40)
    #define ADC_DIGITAL_R_ADC_PWR_DOWN										((uint8_t) 0x00)    // DEFAULT
    #define ADC_DIGITAL_R_ADC_PWR_UP										((uint8_t) 0x40)

    /* SOFT_STEP field */
    #define ADC_DIGITAL_SOFT_STEP_MASK										((uint8_t) 0x03)
    #define ADC_DIGITAL_SOFT_STEP_ONE_OVER_FS								((uint8_t) 0x00)    // DEFAULT
    #define ADC_DIGITAL_SOFT_STEP_ONE_OVER_TWO_FS							((uint8_t) 0x01)
    #define ADC_DIGITAL_SOFT_STEP_DIABSLED									((uint8_t) 0x02)



/* Register 0x52 (ADC_FINE_VOL) definition
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       Bit 7       |       Bit 6       |       Bit 5       |       Bit 4       |       Bit 3       |       Bit 2       |       Bit 1       |       Bit 0       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |     L_ADC_MUTE    |                      L_ADC_GAIN[2:0]                      |     R_ADC_MUTE    |                      R_ADC_GAIN[2:0]                      |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* ADC_FINE_VOL register */
    #define ADC_FINE_VOL_ADDRESS											((uint8_t) 0x52)
    #define ADC_FINE_VOL_DEFAULT											((uint8_t) 0x88)

    /* L_ADC_MUTE field */
    #define ADC_FINE_VOL_L_ADC_MUTE_MASK									((uint8_t) 0x80)
    #define ADC_FINE_VOL_L_ADC_MUTE_UNMUTE									((uint8_t) 0x00)
    #define ADC_FINE_VOL_L_ADC_MUTE_MUTE									((uint8_t) 0x80)    // DEFAULT

    /* L_ADC_GAIN field */
    #define ADC_FINE_VOL_L_ADC_GAIN_MASK									((uint8_t) 0x70)
    #define ADC_FINE_VOL_L_ADC_GAIN_0dB										((uint8_t) 0x00)    // DEFAULT
    #define ADC_FINE_VOL_L_ADC_GAIN_0P1dB									((uint8_t) 0x10)
    #define ADC_FINE_VOL_L_ADC_GAIN_0P2dB									((uint8_t) 0x20)
    #define ADC_FINE_VOL_L_ADC_GAIN_0P3dB									((uint8_t) 0x30)
    #define ADC_FINE_VOL_L_ADC_GAIN_0P4dB									((uint8_t) 0x40)

    /* R_ADC_MUTE field */
    #define ADC_FINE_VOL_R_ADC_MUTE_MASK									((uint8_t) 0x08)
    #define ADC_FINE_VOL_R_ADC_MUTE_UNMUTE									((uint8_t) 0x00)
    #define ADC_FINE_VOL_R_ADC_MUTE_MUTE									((uint8_t) 0x08)    // DEFAULT

    /* R_ADC_GAIN field */
    #define ADC_FINE_VOL_R_ADC_GAIN_MASK									((uint8_t) 0x07)
    #define ADC_FINE_VOL_R_ADC_GAIN_0dB										((uint8_t) 0x00)    // DEFAULT
    #define ADC_FINE_VOL_R_ADC_GAIN_0P1dB									((uint8_t) 0x01)
    #define ADC_FINE_VOL_R_ADC_GAIN_0P2dB									((uint8_t) 0x02)
    #define ADC_FINE_VOL_R_ADC_GAIN_0P3dB									((uint8_t) 0x03)
    #define ADC_FINE_VOL_R_ADC_GAIN_0P4dB									((uint8_t) 0x04)



/* Register 0x53 (L_ADC_VOL) definition
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       Bit 7       |       Bit 6       |       Bit 5       |       Bit 4       |       Bit 3       |       Bit 2       |       Bit 1       |       Bit 0       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |      RESERVED     |                                                        VAL[5:0]                                                       |                   |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* L_ADC_VOL register */
    #define L_ADC_VOL_ADDRESS												((uint8_t) 0x53)
    #define L_ADC_VOL_DEFAULT												((uint8_t) 0x00)

    /* VAL field */
    #define L_ADC_VOL_VAL_MASK                                              ((uint8_t) 0x7E)
    #define L_ADC_VOL_VAL_0dB                                               ((uint8_t) 0x00)    // DEFAULT
    #define L_ADC_VOL_VAL_0P5dB                                             ((uint8_t) 0x01)
    #define L_ADC_VOL_VAL_1dB                                               ((uint8_t) 0x02)
    #define L_ADC_VOL_VAL_1P5dB                                             ((uint8_t) 0x03)
    #define L_ADC_VOL_VAL_2dB                                               ((uint8_t) 0x04)
    #define L_ADC_VOL_VAL_2P5dB                                             ((uint8_t) 0x05)
    #define L_ADC_VOL_VAL_3dB                                               ((uint8_t) 0x06)
    #define L_ADC_VOL_VAL_3P5dB                                             ((uint8_t) 0x07)
    #define L_ADC_VOL_VAL_4dB                                               ((uint8_t) 0x08)
    #define L_ADC_VOL_VAL_4P5dB                                             ((uint8_t) 0x09)
    #define L_ADC_VOL_VAL_5dB                                               ((uint8_t) 0x0A)
    #define L_ADC_VOL_VAL_5P5dB                                             ((uint8_t) 0x0B)
    #define L_ADC_VOL_VAL_6dB                                               ((uint8_t) 0x0C)
    #define L_ADC_VOL_VAL_6P5dB                                             ((uint8_t) 0x0D)
    #define L_ADC_VOL_VAL_7dB                                               ((uint8_t) 0x0E)
    #define L_ADC_VOL_VAL_7P5dB                                             ((uint8_t) 0x0F)
    #define L_ADC_VOL_VAL_8dB                                               ((uint8_t) 0x10)
    #define L_ADC_VOL_VAL_8P5dB                                             ((uint8_t) 0x11)
    #define L_ADC_VOL_VAL_9dB                                               ((uint8_t) 0x12)
    #define L_ADC_VOL_VAL_9P5dB                                             ((uint8_t) 0x13)
    #define L_ADC_VOL_VAL_10dB                                              ((uint8_t) 0x14)
    #define L_ADC_VOL_VAL_10P5dB                                            ((uint8_t) 0x15)
    #define L_ADC_VOL_VAL_11dB                                              ((uint8_t) 0x16)
    #define L_ADC_VOL_VAL_11P5dB                                            ((uint8_t) 0x17)
    #define L_ADC_VOL_VAL_12dB                                              ((uint8_t) 0x18)
    #define L_ADC_VOL_VAL_12P5dB                                            ((uint8_t) 0x19)
    #define L_ADC_VOL_VAL_13dB                                              ((uint8_t) 0x1A)
    #define L_ADC_VOL_VAL_13P5dB                                            ((uint8_t) 0x1B)
    #define L_ADC_VOL_VAL_14dB                                              ((uint8_t) 0x1C)
    #define L_ADC_VOL_VAL_14P5dB                                            ((uint8_t) 0x1D)
    #define L_ADC_VOL_VAL_15dB                                              ((uint8_t) 0x1E)
    #define L_ADC_VOL_VAL_15P5dB                                            ((uint8_t) 0x1F)
    #define L_ADC_VOL_VAL_16dB                                              ((uint8_t) 0x20)
    #define L_ADC_VOL_VAL_16P5dB                                            ((uint8_t) 0x21)
    #define L_ADC_VOL_VAL_17dB                                              ((uint8_t) 0x22)
    #define L_ADC_VOL_VAL_17P5dB                                            ((uint8_t) 0x23)
    #define L_ADC_VOL_VAL_18dB                                              ((uint8_t) 0x24)
    #define L_ADC_VOL_VAL_18P5dB                                            ((uint8_t) 0x25)
    #define L_ADC_VOL_VAL_19dB                                              ((uint8_t) 0x26)
    #define L_ADC_VOL_VAL_19P5dB                                            ((uint8_t) 0x27)
    #define L_ADC_VOL_VAL_20dB                                              ((uint8_t) 0x28)



/* Register 0x54 (R_ADC_VOL) definition
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       Bit 7       |       Bit 6       |       Bit 5       |       Bit 4       |       Bit 3       |       Bit 2       |       Bit 1       |       Bit 0       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |      RESERVED     |                                                        VAL[5:0]                                                       |                   |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* R_ADC_VOL register */
    #define R_ADC_VOL_ADDRESS												((uint8_t) 0x54)
    #define R_ADC_VOL_DEFAULT												((uint8_t) 0x00)

    /* VAL field */
    #define R_ADC_VOL_VAL_MASK                                              ((uint8_t) 0x7E)
    #define R_ADC_VOL_VAL_0dB                                               ((uint8_t) 0x00) // DEFAULT
    #define R_ADC_VOL_VAL_0P5dB                                             ((uint8_t) 0x01)
    #define R_ADC_VOL_VAL_1dB                                               ((uint8_t) 0x02)
    #define R_ADC_VOL_VAL_1P5dB                                             ((uint8_t) 0x03)
    #define R_ADC_VOL_VAL_2dB                                               ((uint8_t) 0x04)
    #define R_ADC_VOL_VAL_2P5dB                                             ((uint8_t) 0x05)
    #define R_ADC_VOL_VAL_3dB                                               ((uint8_t) 0x06)
    #define R_ADC_VOL_VAL_3P5dB                                             ((uint8_t) 0x07)
    #define R_ADC_VOL_VAL_4dB                                               ((uint8_t) 0x08)
    #define R_ADC_VOL_VAL_4P5dB                                             ((uint8_t) 0x09)
    #define R_ADC_VOL_VAL_5dB                                               ((uint8_t) 0x0A)
    #define R_ADC_VOL_VAL_5P5dB                                             ((uint8_t) 0x0B)
    #define R_ADC_VOL_VAL_6dB                                               ((uint8_t) 0x0C)
    #define R_ADC_VOL_VAL_6P5dB                                             ((uint8_t) 0x0D)
    #define R_ADC_VOL_VAL_7dB                                               ((uint8_t) 0x0E)
    #define R_ADC_VOL_VAL_7P5dB                                             ((uint8_t) 0x0F)
    #define R_ADC_VOL_VAL_8dB                                               ((uint8_t) 0x10)
    #define R_ADC_VOL_VAL_8P5dB                                             ((uint8_t) 0x11)
    #define R_ADC_VOL_VAL_9dB                                               ((uint8_t) 0x12)
    #define R_ADC_VOL_VAL_9P5dB                                             ((uint8_t) 0x13)
    #define R_ADC_VOL_VAL_10dB                                              ((uint8_t) 0x14)
    #define R_ADC_VOL_VAL_10P5dB                                            ((uint8_t) 0x15)
    #define R_ADC_VOL_VAL_11dB                                              ((uint8_t) 0x16)
    #define R_ADC_VOL_VAL_11P5dB                                            ((uint8_t) 0x17)
    #define R_ADC_VOL_VAL_12dB                                              ((uint8_t) 0x18)
    #define R_ADC_VOL_VAL_12P5dB                                            ((uint8_t) 0x19)
    #define R_ADC_VOL_VAL_13dB                                              ((uint8_t) 0x1A)
    #define R_ADC_VOL_VAL_13P5dB                                            ((uint8_t) 0x1B)
    #define R_ADC_VOL_VAL_14dB                                              ((uint8_t) 0x1C)
    #define R_ADC_VOL_VAL_14P5dB                                            ((uint8_t) 0x1D)
    #define R_ADC_VOL_VAL_15dB                                              ((uint8_t) 0x1E)
    #define R_ADC_VOL_VAL_15P5dB                                            ((uint8_t) 0x1F)
    #define R_ADC_VOL_VAL_16dB                                              ((uint8_t) 0x20)
    #define R_ADC_VOL_VAL_16P5dB                                            ((uint8_t) 0x21)
    #define R_ADC_VOL_VAL_17dB                                              ((uint8_t) 0x22)
    #define R_ADC_VOL_VAL_17P5dB                                            ((uint8_t) 0x23)
    #define R_ADC_VOL_VAL_18dB                                              ((uint8_t) 0x24)
    #define R_ADC_VOL_VAL_18P5dB                                            ((uint8_t) 0x25)
    #define R_ADC_VOL_VAL_19dB                                              ((uint8_t) 0x26)
    #define R_ADC_VOL_VAL_19P5dB                                            ((uint8_t) 0x27)
    #define R_ADC_VOL_VAL_20dB                                              ((uint8_t) 0x28)



/* Register 0x55 (L_ADC_PHASE) definition
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       Bit 7       |       Bit 6       |       Bit 5       |       Bit 4       |       Bit 3       |       Bit 2       |       Bit 1       |       Bit 0       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                                                 COMP[6:0]                                                                 |                   |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* L_ADC_PHASE register */
    #define L_ADC_PHASE_ADDRESS												((uint8_t) 0x55)
    #define L_ADC_PHASE_DEFAULT												((uint8_t) 0x00)



/* Register 0x56 (L_AGC_CONTROL1) definition
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       Bit 7       |       Bit 6       |       Bit 5       |       Bit 4       |       Bit 3       |       Bit 2       |       Bit 1       |       Bit 0       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |         EN        |                        TARGET[2:0]                        |                                 RESERVED[3:0]                                 |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* L_AGC_CONTROL1 register */
    #define L_AGC_CONTROL1_ADDRESS											((uint8_t) 0x56)
    #define L_AGC_CONTROL1_DEFAULT											((uint8_t) 0x00)

    /* EN field */
    #define L_AGC_CONTROL1_EN_MASK											((uint8_t) 0x80)
    #define L_AGC_CONTROL1_EN_DISABLE										((uint8_t) 0x00)    // DEFAULT
    #define L_AGC_CONTROL1_EN_ENABLE										((uint8_t) 0x80)

    /* TARGET field */
    #define L_AGC_CONTROL1_TARGET_MASK										((uint8_t) 0x70)
    #define L_AGC_CONTROL1_TARGET_M5P5dB									((uint8_t) 0x00)    // DEFAULT
    #define L_AGC_CONTROL1_TARGET_M8dB										((uint8_t) 0x10)
    #define L_AGC_CONTROL1_TARGET_M10dB										((uint8_t) 0x20)
    #define L_AGC_CONTROL1_TARGET_M12dB										((uint8_t) 0x30)
    #define L_AGC_CONTROL1_TARGET_M14dB										((uint8_t) 0x40)
    #define L_AGC_CONTROL1_TARGET_M17dB										((uint8_t) 0x50)
    #define L_AGC_CONTROL1_TARGET_M20dB										((uint8_t) 0x60)
    #define L_AGC_CONTROL1_TARGET_M24dB										((uint8_t) 0x70)



/* Register 0x57 (L_AGC_CONTROL2) definition
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       Bit 7       |       Bit 6       |       Bit 5       |       Bit 4       |       Bit 3       |       Bit 2       |       Bit 1       |       Bit 0       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |               HYST[1:0]               |                                          NOISE_THRES[4:0]                                         |         0         |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* L_AGC_CONTROL2 register */
    #define L_AGC_CONTROL2_ADDRESS											((uint8_t) 0x57)
    #define L_AGC_CONTROL2_DEFAULT											((uint8_t) 0x00)

    /* HYST field */
    #define L_AGC_CONTROL2_HYST_MASK										((uint8_t) 0xC0)
    #define L_AGC_CONTROL2_HYST_1dB											((uint8_t) 0x00)    // DEFAULT
    #define L_AGC_CONTROL2_HYST_2dB											((uint8_t) 0x40)
    #define L_AGC_CONTROL2_HYST_4dB											((uint8_t) 0x80)
    #define L_AGC_CONTROL2_HYST_DISABLED									((uint8_t) 0xC0)

    /* NOISE_THRES field */
    #define L_AGC_CONTROL2_NOISE_THRES_MASK									((uint8_t) 0x3E)
    #define L_AGC_CONTROL2_NOISE_THRES_DISABLED								((uint8_t) 0x00)    // DEFAULT
    #define L_AGC_CONTROL2_NOISE_THRES_M30dB								((uint8_t) 0x02)
    #define L_AGC_CONTROL2_NOISE_THRES_M32dB								((uint8_t) 0x04)
    #define L_AGC_CONTROL2_NOISE_THRES_M34dB								((uint8_t) 0x06)
    #define L_AGC_CONTROL2_NOISE_THRES_M36dB								((uint8_t) 0x08)
    #define L_AGC_CONTROL2_NOISE_THRES_M38dB								((uint8_t) 0x0A)
    #define L_AGC_CONTROL2_NOISE_THRES_M40dB								((uint8_t) 0x0C)
    #define L_AGC_CONTROL2_NOISE_THRES_M42dB								((uint8_t) 0x0E)
    #define L_AGC_CONTROL2_NOISE_THRES_M44dB								((uint8_t) 0x10)
    #define L_AGC_CONTROL2_NOISE_THRES_M46dB								((uint8_t) 0x12)
    #define L_AGC_CONTROL2_NOISE_THRES_M48dB								((uint8_t) 0x14)
    #define L_AGC_CONTROL2_NOISE_THRES_M50dB								((uint8_t) 0x16)
    #define L_AGC_CONTROL2_NOISE_THRES_M52dB								((uint8_t) 0x18)
    #define L_AGC_CONTROL2_NOISE_THRES_M54dB								((uint8_t) 0x1A)
    #define L_AGC_CONTROL2_NOISE_THRES_M56dB								((uint8_t) 0x1C)
    #define L_AGC_CONTROL2_NOISE_THRES_M58dB								((uint8_t) 0x1E)
    #define L_AGC_CONTROL2_NOISE_THRES_M60dB								((uint8_t) 0x20)
    #define L_AGC_CONTROL2_NOISE_THRES_M62dB								((uint8_t) 0x22)
    #define L_AGC_CONTROL2_NOISE_THRES_M64dB								((uint8_t) 0x24)
    #define L_AGC_CONTROL2_NOISE_THRES_M66dB								((uint8_t) 0x26)
    #define L_AGC_CONTROL2_NOISE_THRES_M68dB								((uint8_t) 0x28)
    #define L_AGC_CONTROL2_NOISE_THRES_M70dB								((uint8_t) 0x2A)
    #define L_AGC_CONTROL2_NOISE_THRES_M72dB								((uint8_t) 0x2C)
    #define L_AGC_CONTROL2_NOISE_THRES_M74dB								((uint8_t) 0x2E)
    #define L_AGC_CONTROL2_NOISE_THRES_M76dB								((uint8_t) 0x30)
    #define L_AGC_CONTROL2_NOISE_THRES_M78dB								((uint8_t) 0x32)
    #define L_AGC_CONTROL2_NOISE_THRES_M80dB								((uint8_t) 0x34)
    #define L_AGC_CONTROL2_NOISE_THRES_M82dB								((uint8_t) 0x36)
    #define L_AGC_CONTROL2_NOISE_THRES_M84dB								((uint8_t) 0x38)
    #define L_AGC_CONTROL2_NOISE_THRES_M86dB								((uint8_t) 0x3A)
    #define L_AGC_CONTROL2_NOISE_THRES_M88dB								((uint8_t) 0x3C)
    #define L_AGC_CONTROL2_NOISE_THRES_M90dB								((uint8_t) 0x3E)

    /* CLIP_STEP field */
    #define L_AGC_CONTROL2_CLIP_STEP_MASK									((uint8_t) 0x01)
    #define L_AGC_CONTROL2_CLIP_STEP_DISABLE								((uint8_t) 0x00)    // DEFAULT
    #define L_AGC_CONTROL2_CLIP_STEP_ENABLE									((uint8_t) 0x01)



/* Register 0x58 (L_AGC_MAX) definition
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       Bit 7       |       Bit 6       |       Bit 5       |       Bit 4       |       Bit 3       |       Bit 2       |       Bit 1       |       Bit 0       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |      RESERVED     |                                                                 GAIN[6:0]                                                                 |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* L_AGC_MAX register */
    #define L_AGC_MAX_ADDRESS												((uint8_t) 0x58)
    #define L_AGC_MAX_DEFAULT												((uint8_t) 0x7F)

    /* GAIN field */
    #define L_AGC_MAX_GAIN_MASK												((uint8_t) 0x7F)
    #define L_AGC_MAX_GAIN_0dB												((uint8_t) 0x00)
    #define L_AGC_MAX_GAIN_0P5dB											((uint8_t) 0x01)
    #define L_AGC_MAX_GAIN_1dB												((uint8_t) 0x02)
    #define L_AGC_MAX_GAIN_1P5dB											((uint8_t) 0x03)
    #define L_AGC_MAX_GAIN_2dB												((uint8_t) 0x04)
    #define L_AGC_MAX_GAIN_2P5dB											((uint8_t) 0x05)
    #define L_AGC_MAX_GAIN_3dB												((uint8_t) 0x06)
    #define L_AGC_MAX_GAIN_3P5dB											((uint8_t) 0x07)
    #define L_AGC_MAX_GAIN_4dB												((uint8_t) 0x08)
    #define L_AGC_MAX_GAIN_4P5dB											((uint8_t) 0x09)
    #define L_AGC_MAX_GAIN_5dB												((uint8_t) 0x0A)
    #define L_AGC_MAX_GAIN_5P5dB											((uint8_t) 0x0B)
    #define L_AGC_MAX_GAIN_6dB												((uint8_t) 0x0C)
    #define L_AGC_MAX_GAIN_6P5dB											((uint8_t) 0x0D)
    #define L_AGC_MAX_GAIN_7dB												((uint8_t) 0x0E)
    #define L_AGC_MAX_GAIN_7P5dB											((uint8_t) 0x0F)
    #define L_AGC_MAX_GAIN_8dB												((uint8_t) 0x10)
    #define L_AGC_MAX_GAIN_8P5dB											((uint8_t) 0x11)
    #define L_AGC_MAX_GAIN_9dB												((uint8_t) 0x12)
    #define L_AGC_MAX_GAIN_9P5dB											((uint8_t) 0x13)
    #define L_AGC_MAX_GAIN_10dB												((uint8_t) 0x14)
    #define L_AGC_MAX_GAIN_10P5dB											((uint8_t) 0x15)
    #define L_AGC_MAX_GAIN_11dB												((uint8_t) 0x16)
    #define L_AGC_MAX_GAIN_11P5dB											((uint8_t) 0x17)
    #define L_AGC_MAX_GAIN_12dB												((uint8_t) 0x18)
    #define L_AGC_MAX_GAIN_12P5dB											((uint8_t) 0x19)
    #define L_AGC_MAX_GAIN_13dB												((uint8_t) 0x1A)
    #define L_AGC_MAX_GAIN_13P5dB											((uint8_t) 0x1B)
    #define L_AGC_MAX_GAIN_14dB												((uint8_t) 0x1C)
    #define L_AGC_MAX_GAIN_14P5dB											((uint8_t) 0x1D)
    #define L_AGC_MAX_GAIN_15dB												((uint8_t) 0x1E)
    #define L_AGC_MAX_GAIN_15P5dB											((uint8_t) 0x1F)
    #define L_AGC_MAX_GAIN_16dB												((uint8_t) 0x20)
    #define L_AGC_MAX_GAIN_16P5dB											((uint8_t) 0x21)
    #define L_AGC_MAX_GAIN_17dB2											((uint8_t) 0x22)
    #define L_AGC_MAX_GAIN_17P5dB											((uint8_t) 0x23)
    #define L_AGC_MAX_GAIN_18dB												((uint8_t) 0x24)
    #define L_AGC_MAX_GAIN_18P5dB											((uint8_t) 0x25)
    #define L_AGC_MAX_GAIN_19dB												((uint8_t) 0x26)
    #define L_AGC_MAX_GAIN_19P5dB											((uint8_t) 0x27)
    #define L_AGC_MAX_GAIN_20dB												((uint8_t) 0x28)
    #define L_AGC_MAX_GAIN_20P5dB											((uint8_t) 0x29)
    #define L_AGC_MAX_GAIN_21dB												((uint8_t) 0x2A)
    #define L_AGC_MAX_GAIN_21P5dB											((uint8_t) 0x2B)
    #define L_AGC_MAX_GAIN_22dB												((uint8_t) 0x2C)
    #define L_AGC_MAX_GAIN_22P5dB											((uint8_t) 0x2D)
    #define L_AGC_MAX_GAIN_23dB												((uint8_t) 0x2E)
    #define L_AGC_MAX_GAIN_23P5dB											((uint8_t) 0x2F)
    #define L_AGC_MAX_GAIN_24dB												((uint8_t) 0x30)
    #define L_AGC_MAX_GAIN_24P5dB											((uint8_t) 0x31)
    #define L_AGC_MAX_GAIN_25dB												((uint8_t) 0x32)
    #define L_AGC_MAX_GAIN_25P5dB											((uint8_t) 0x33)
    #define L_AGC_MAX_GAIN_26dB												((uint8_t) 0x34)
    #define L_AGC_MAX_GAIN_26P5dB											((uint8_t) 0x35)
    #define L_AGC_MAX_GAIN_27dB												((uint8_t) 0x36)
    #define L_AGC_MAX_GAIN_27P5dB											((uint8_t) 0x37)
    #define L_AGC_MAX_GAIN_28dB												((uint8_t) 0x38)
    #define L_AGC_MAX_GAIN_28P5dB											((uint8_t) 0x39)
    #define L_AGC_MAX_GAIN_29dB												((uint8_t) 0x3A)
    #define L_AGC_MAX_GAIN_29P5dB											((uint8_t) 0x3B)
    #define L_AGC_MAX_GAIN_30dB												((uint8_t) 0x3C)
    #define L_AGC_MAX_GAIN_30P5dB											((uint8_t) 0x3D)
    #define L_AGC_MAX_GAIN_31dB												((uint8_t) 0x3E)
    #define L_AGC_MAX_GAIN_31P5dB											((uint8_t) 0x3F)
    #define L_AGC_MAX_GAIN_32dB												((uint8_t) 0x40)
    #define L_AGC_MAX_GAIN_32P5dB											((uint8_t) 0x41)
    #define L_AGC_MAX_GAIN_33dB												((uint8_t) 0x42)
    #define L_AGC_MAX_GAIN_33P5dB											((uint8_t) 0x43)
    #define L_AGC_MAX_GAIN_34dB												((uint8_t) 0x44)
    #define L_AGC_MAX_GAIN_34P5dB											((uint8_t) 0x45)
    #define L_AGC_MAX_GAIN_35dB												((uint8_t) 0x46)
    #define L_AGC_MAX_GAIN_35P5dB											((uint8_t) 0x47)
    #define L_AGC_MAX_GAIN_36dB												((uint8_t) 0x48)
    #define L_AGC_MAX_GAIN_36P5dB											((uint8_t) 0x49)
    #define L_AGC_MAX_GAIN_37dB												((uint8_t) 0x4A)
    #define L_AGC_MAX_GAIN_37P5dB											((uint8_t) 0x4B)
    #define L_AGC_MAX_GAIN_38dB												((uint8_t) 0x4C)
    #define L_AGC_MAX_GAIN_38P5dB											((uint8_t) 0x4D)
    #define L_AGC_MAX_GAIN_39dB												((uint8_t) 0x4E)
    #define L_AGC_MAX_GAIN_39P5dB											((uint8_t) 0x4F)
    #define L_AGC_MAX_GAIN_40dB												((uint8_t) 0x50)



/* Register 0x59 (L_AGC_ATTACK) definition
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       Bit 7       |       Bit 6       |       Bit 5       |       Bit 4       |       Bit 3       |       Bit 2       |       Bit 1       |       Bit 0       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                             TIME[4:0]                                             |                         MULT[2:0]                         |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* L_AGC_ATTACK register */
    #define L_AGC_ATTACK_ADDRESS											((uint8_t) 0x59)
    #define L_AGC_ATTACK_DEFAULT											((uint8_t) 0x00)

    /* TIME field */
    #define L_AGC_ATTACK_TIME_MASK											((uint8_t) 0xF8)
    #define L_AGC_ATTACK_TIME_1												((uint8_t) 0x00)    // DEFAULT
    #define L_AGC_ATTACK_TIME_3												((uint8_t) 0x08)
    #define L_AGC_ATTACK_TIME_5												((uint8_t) 0x10)
    #define L_AGC_ATTACK_TIME_7												((uint8_t) 0x18)
    #define L_AGC_ATTACK_TIME_9												((uint8_t) 0x20)
    #define L_AGC_ATTACK_TIME_11											((uint8_t) 0x28)
    #define L_AGC_ATTACK_TIME_13											((uint8_t) 0x30)
    #define L_AGC_ATTACK_TIME_15											((uint8_t) 0x38)
    #define L_AGC_ATTACK_TIME_17											((uint8_t) 0x40)
    #define L_AGC_ATTACK_TIME_19											((uint8_t) 0x48)
    #define L_AGC_ATTACK_TIME_21											((uint8_t) 0x50)
    #define L_AGC_ATTACK_TIME_23											((uint8_t) 0x58)
    #define L_AGC_ATTACK_TIME_25											((uint8_t) 0x60)
    #define L_AGC_ATTACK_TIME_27											((uint8_t) 0x68)
    #define L_AGC_ATTACK_TIME_29											((uint8_t) 0x70)
    #define L_AGC_ATTACK_TIME_31											((uint8_t) 0x78)
    #define L_AGC_ATTACK_TIME_33											((uint8_t) 0x80)
    #define L_AGC_ATTACK_TIME_35											((uint8_t) 0x88)
    #define L_AGC_ATTACK_TIME_37											((uint8_t) 0x90)
    #define L_AGC_ATTACK_TIME_39											((uint8_t) 0x98)
    #define L_AGC_ATTACK_TIME_41											((uint8_t) 0xA0)
    #define L_AGC_ATTACK_TIME_43											((uint8_t) 0xA8)
    #define L_AGC_ATTACK_TIME_45											((uint8_t) 0xB0)
    #define L_AGC_ATTACK_TIME_47											((uint8_t) 0xB8)
    #define L_AGC_ATTACK_TIME_49											((uint8_t) 0xC0)
    #define L_AGC_ATTACK_TIME_51											((uint8_t) 0xC8)
    #define L_AGC_ATTACK_TIME_53											((uint8_t) 0xD0)
    #define L_AGC_ATTACK_TIME_55											((uint8_t) 0xD8)
    #define L_AGC_ATTACK_TIME_57											((uint8_t) 0xE0)
    #define L_AGC_ATTACK_TIME_59											((uint8_t) 0xE8)
    #define L_AGC_ATTACK_TIME_61											((uint8_t) 0xF0)
    #define L_AGC_ATTACK_TIME_63											((uint8_t) 0xF8)

    /* MULT field */
    #define L_AGC_ATTACK_MULT_MASK											((uint8_t) 0x07)
    #define L_AGC_ATTACK_MULT_1												((uint8_t) 0x00)    // DEFAULT
    #define L_AGC_ATTACK_MULT_2												((uint8_t) 0x01)
    #define L_AGC_ATTACK_MULT_4												((uint8_t) 0x02)
    #define L_AGC_ATTACK_MULT_8												((uint8_t) 0x03)
    #define L_AGC_ATTACK_MULT_16											((uint8_t) 0x04)
    #define L_AGC_ATTACK_MULT_32											((uint8_t) 0x05)
    #define L_AGC_ATTACK_MULT_64											((uint8_t) 0x06)
    #define L_AGC_ATTACK_MULT_128											((uint8_t) 0x07)



/* Register 0x5A (L_AGC_DECAY) definition
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       Bit 7       |       Bit 6       |       Bit 5       |       Bit 4       |       Bit 3       |       Bit 2       |       Bit 1       |       Bit 0       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                             TIME[4:0]                                             |                         MULT[2:0]                         |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* L_AGC_DECAY register */
    #define L_AGC_DECAY_ADDRESS												((uint8_t) 0x5A)
    #define L_AGC_DECAY_DEFAULT												((uint8_t) 0x00)

    /* TIME field */
    #define L_AGC_DECAY_TIME_MASK											((uint8_t) 0xF8)
    #define L_AGC_DECAY_TIME_1												((uint8_t) 0x00)    // DEFAULT
    #define L_AGC_DECAY_TIME_3												((uint8_t) 0x08)
    #define L_AGC_DECAY_TIME_5												((uint8_t) 0x10)
    #define L_AGC_DECAY_TIME_7												((uint8_t) 0x18)
    #define L_AGC_DECAY_TIME_9												((uint8_t) 0x20)
    #define L_AGC_DECAY_TIME_11												((uint8_t) 0x28)
    #define L_AGC_DECAY_TIME_13												((uint8_t) 0x30)
    #define L_AGC_DECAY_TIME_15												((uint8_t) 0x38)
    #define L_AGC_DECAY_TIME_17												((uint8_t) 0x40)
    #define L_AGC_DECAY_TIME_19												((uint8_t) 0x48)
    #define L_AGC_DECAY_TIME_21												((uint8_t) 0x50)
    #define L_AGC_DECAY_TIME_23												((uint8_t) 0x58)
    #define L_AGC_DECAY_TIME_25												((uint8_t) 0x60)
    #define L_AGC_DECAY_TIME_27												((uint8_t) 0x68)
    #define L_AGC_DECAY_TIME_29												((uint8_t) 0x70)
    #define L_AGC_DECAY_TIME_31												((uint8_t) 0x78)
    #define L_AGC_DECAY_TIME_33												((uint8_t) 0x80)
    #define L_AGC_DECAY_TIME_35												((uint8_t) 0x88)
    #define L_AGC_DECAY_TIME_37												((uint8_t) 0x90)
    #define L_AGC_DECAY_TIME_39												((uint8_t) 0x98)
    #define L_AGC_DECAY_TIME_41												((uint8_t) 0xA0)
    #define L_AGC_DECAY_TIME_43												((uint8_t) 0xA8)
    #define L_AGC_DECAY_TIME_45												((uint8_t) 0xB0)
    #define L_AGC_DECAY_TIME_47												((uint8_t) 0xB8)
    #define L_AGC_DECAY_TIME_49												((uint8_t) 0xC0)
    #define L_AGC_DECAY_TIME_51												((uint8_t) 0xC8)
    #define L_AGC_DECAY_TIME_53												((uint8_t) 0xD0)
    #define L_AGC_DECAY_TIME_55												((uint8_t) 0xD8)
    #define L_AGC_DECAY_TIME_57												((uint8_t) 0xE0)
    #define L_AGC_DECAY_TIME_59												((uint8_t) 0xE8)
    #define L_AGC_DECAY_TIME_61												((uint8_t) 0xF0)
    #define L_AGC_DECAY_TIME_63												((uint8_t) 0xF8)

    /* MULT field */
    #define L_AGC_DECAY_MULT_MASK											((uint8_t) 0x07)
    #define L_AGC_DECAY_MULT_1												((uint8_t) 0x00)    // DEFAULT
    #define L_AGC_DECAY_MULT_2												((uint8_t) 0x01)
    #define L_AGC_DECAY_MULT_4												((uint8_t) 0x02)
    #define L_AGC_DECAY_MULT_8												((uint8_t) 0x03)
    #define L_AGC_DECAY_MULT_16												((uint8_t) 0x04)
    #define L_AGC_DECAY_MULT_32												((uint8_t) 0x05)
    #define L_AGC_DECAY_MULT_64												((uint8_t) 0x06)
    #define L_AGC_DECAY_MULT_128											((uint8_t) 0x07)



/* Register 0x5B (L_AGC_NOISE) definition
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       Bit 7       |       Bit 6       |       Bit 5       |       Bit 4       |       Bit 3       |       Bit 2       |       Bit 1       |       Bit 0       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                       RESERVED[2:0]                       |                                           DEBOUNCE[4:0]                                           |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* L_AGC_NOISE register */
    #define L_AGC_NOISE_ADDRESS												((uint8_t) 0x5B)
    #define L_AGC_NOISE_DEFAULT												((uint8_t) 0x00)

    /* DEBOUNCE field */
    #define L_AGC_NOISE_DEBOUNCE_MASK										((uint8_t) 0x1F)
    #define L_AGC_NOISE_DEBOUNCE_0											((uint8_t) 0x00)    // DEFAULT
    #define L_AGC_NOISE_DEBOUNCE_4											((uint8_t) 0x01)
    #define L_AGC_NOISE_DEBOUNCE_8											((uint8_t) 0x02)
    #define L_AGC_NOISE_DEBOUNCE_16											((uint8_t) 0x03)
    #define L_AGC_NOISE_DEBOUNCE_32											((uint8_t) 0x04)
    #define L_AGC_NOISE_DEBOUNCE_64											((uint8_t) 0x05)
    #define L_AGC_NOISE_DEBOUNCE_128										((uint8_t) 0x06)
    #define L_AGC_NOISE_DEBOUNCE_256										((uint8_t) 0x07)
    #define L_AGC_NOISE_DEBOUNCE_512										((uint8_t) 0x08)
    #define L_AGC_NOISE_DEBOUNCE_1024										((uint8_t) 0x09)
    #define L_AGC_NOISE_DEBOUNCE_2048										((uint8_t) 0x0A)
    #define L_AGC_NOISE_DEBOUNCE_4096										((uint8_t) 0x0B)
    #define L_AGC_NOISE_DEBOUNCE_8192										((uint8_t) 0x0C)
    #define L_AGC_NOISE_DEBOUNCE_12288										((uint8_t) 0x0D)
    #define L_AGC_NOISE_DEBOUNCE_16384										((uint8_t) 0x0E)
    #define L_AGC_NOISE_DEBOUNCE_20480										((uint8_t) 0x0F)



/* Register 0x5C (L_AGC_SIGNAL) definition
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       Bit 7       |       Bit 6       |       Bit 5       |       Bit 4       |       Bit 3       |       Bit 2       |       Bit 1       |       Bit 0       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                 RESERVED[3:0]                                 |                                 DEBOUNCE[3:0]                                 |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* L_AGC_SIGNAL register */
    #define L_AGC_SIGNAL_ADDRESS											((uint8_t) 0x5C)
    #define L_AGC_SIGNAL_DEFAULT											((uint8_t) 0x00)

    /* DEBOUNCE field */
    #define L_AGC_SIGNAL_DEBOUNCE_MASK										((uint8_t) 0x0F)
    #define L_AGC_SIGNAL_DEBOUNCE_0											((uint8_t) 0x00)    // DEFAULT
    #define L_AGC_SIGNAL_DEBOUNCE_4											((uint8_t) 0x01)
    #define L_AGC_SIGNAL_DEBOUNCE_8											((uint8_t) 0x02)
    #define L_AGC_SIGNAL_DEBOUNCE_16										((uint8_t) 0x03)
    #define L_AGC_SIGNAL_DEBOUNCE_32										((uint8_t) 0x04)
    #define L_AGC_SIGNAL_DEBOUNCE_64										((uint8_t) 0x05)
    #define L_AGC_SIGNAL_DEBOUNCE_128										((uint8_t) 0x06)
    #define L_AGC_SIGNAL_DEBOUNCE_256										((uint8_t) 0x07)
    #define L_AGC_SIGNAL_DEBOUNCE_512										((uint8_t) 0x08)
    #define L_AGC_SIGNAL_DEBOUNCE_1024										((uint8_t) 0x09)
    #define L_AGC_SIGNAL_DEBOUNCE_2048										((uint8_t) 0x0A)
    #define L_AGC_SIGNAL_DEBOUNCE_4096										((uint8_t) 0x0B)
    #define L_AGC_SIGNAL_DEBOUNCE_6144										((uint8_t) 0x0C)
    #define L_AGC_SIGNAL_DEBOUNCE_8192										((uint8_t) 0x0D)
    #define L_AGC_SIGNAL_DEBOUNCE_10240										((uint8_t) 0x0E)
    #define L_AGC_SIGNAL_DEBOUNCE_12288										((uint8_t) 0x0F)



/* Register 0x5D (L_AGC_GAIN) definition
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       Bit 7       |       Bit 6       |       Bit 5       |       Bit 4       |       Bit 3       |       Bit 2       |       Bit 1       |       Bit 0       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                                                  VAL[6:0]                                                                 |                   |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* L_AGC_GAIN register */
    #define L_AGC_GAIN_ADDRESS												((uint8_t) 0x5D)
    #define L_AGC_GAIN_DEFAULT												((uint8_t) 0x00)

    /* VAL field */
    #define L_AGC_GAIN_VAL_MASK												((uint8_t) 0xFE)
    #define L_AGC_GAIN_VAL_0dB												((uint8_t) 0x00)    // DEFAULT
    #define L_AGC_GAIN_VAL_0P5dB											((uint8_t) 0x02)
    #define L_AGC_GAIN_VAL_1dB												((uint8_t) 0x04)
    #define L_AGC_GAIN_VAL_1P5dB											((uint8_t) 0x06)
    #define L_AGC_GAIN_VAL_2dB												((uint8_t) 0x08)
    #define L_AGC_GAIN_VAL_2P5dB											((uint8_t) 0x0A)
    #define L_AGC_GAIN_VAL_3dB												((uint8_t) 0x0C)
    #define L_AGC_GAIN_VAL_3P5dB											((uint8_t) 0x0E)
    #define L_AGC_GAIN_VAL_4dB												((uint8_t) 0x10)
    #define L_AGC_GAIN_VAL_4P5dB											((uint8_t) 0x12)
    #define L_AGC_GAIN_VAL_5dB												((uint8_t) 0x14)
    #define L_AGC_GAIN_VAL_5P5dB											((uint8_t) 0x16)
    #define L_AGC_GAIN_VAL_6dB												((uint8_t) 0x18)
    #define L_AGC_GAIN_VAL_6P5dB											((uint8_t) 0x1A)
    #define L_AGC_GAIN_VAL_7dB												((uint8_t) 0x1C)
    #define L_AGC_GAIN_VAL_7P5dB											((uint8_t) 0x1E)
    #define L_AGC_GAIN_VAL_8dB												((uint8_t) 0x20)
    #define L_AGC_GAIN_VAL_8P5dB											((uint8_t) 0x22)
    #define L_AGC_GAIN_VAL_9dB												((uint8_t) 0x24)
    #define L_AGC_GAIN_VAL_9P5dB											((uint8_t) 0x26)
    #define L_AGC_GAIN_VAL_10dB												((uint8_t) 0x28)
    #define L_AGC_GAIN_VAL_10P5dB											((uint8_t) 0x2A)
    #define L_AGC_GAIN_VAL_11dB												((uint8_t) 0x2C)
    #define L_AGC_GAIN_VAL_11P5dB											((uint8_t) 0x2E)
    #define L_AGC_GAIN_VAL_12dB												((uint8_t) 0x30)
    #define L_AGC_GAIN_VAL_12P5dB											((uint8_t) 0x32)
    #define L_AGC_GAIN_VAL_13dB												((uint8_t) 0x34)
    #define L_AGC_GAIN_VAL_13P5dB											((uint8_t) 0x36)
    #define L_AGC_GAIN_VAL_14dB												((uint8_t) 0x38)
    #define L_AGC_GAIN_VAL_14P5dB											((uint8_t) 0x3A)
    #define L_AGC_GAIN_VAL_15dB												((uint8_t) 0x3C)
    #define L_AGC_GAIN_VAL_15P5dB											((uint8_t) 0x3E)
    #define L_AGC_GAIN_VAL_16dB												((uint8_t) 0x40)
    #define L_AGC_GAIN_VAL_16P5dB											((uint8_t) 0x42)
    #define L_AGC_GAIN_VAL_17dB2											((uint8_t) 0x44)
    #define L_AGC_GAIN_VAL_17P5dB											((uint8_t) 0x46)
    #define L_AGC_GAIN_VAL_18dB												((uint8_t) 0x48)
    #define L_AGC_GAIN_VAL_18P5dB											((uint8_t) 0x4A)
    #define L_AGC_GAIN_VAL_19dB												((uint8_t) 0x4C)
    #define L_AGC_GAIN_VAL_19P5dB											((uint8_t) 0x4E)
    #define L_AGC_GAIN_VAL_20dB												((uint8_t) 0x50)
    #define L_AGC_GAIN_VAL_20P5dB											((uint8_t) 0x52)
    #define L_AGC_GAIN_VAL_21dB												((uint8_t) 0x54)
    #define L_AGC_GAIN_VAL_21P5dB											((uint8_t) 0x56)
    #define L_AGC_GAIN_VAL_22dB												((uint8_t) 0x58)
    #define L_AGC_GAIN_VAL_22P5dB											((uint8_t) 0x5A)
    #define L_AGC_GAIN_VAL_23dB												((uint8_t) 0x5C)
    #define L_AGC_GAIN_VAL_23P5dB											((uint8_t) 0x5E)
    #define L_AGC_GAIN_VAL_24dB												((uint8_t) 0x60)
    #define L_AGC_GAIN_VAL_24P5dB											((uint8_t) 0x62)
    #define L_AGC_GAIN_VAL_25dB												((uint8_t) 0x64)
    #define L_AGC_GAIN_VAL_25P5dB											((uint8_t) 0x66)
    #define L_AGC_GAIN_VAL_26dB												((uint8_t) 0x68)
    #define L_AGC_GAIN_VAL_26P5dB											((uint8_t) 0x6A)
    #define L_AGC_GAIN_VAL_27dB												((uint8_t) 0x6C)
    #define L_AGC_GAIN_VAL_27P5dB											((uint8_t) 0x6E)
    #define L_AGC_GAIN_VAL_28dB												((uint8_t) 0x70)
    #define L_AGC_GAIN_VAL_28P5dB											((uint8_t) 0x72)
    #define L_AGC_GAIN_VAL_29dB												((uint8_t) 0x74)
    #define L_AGC_GAIN_VAL_29P5dB											((uint8_t) 0x76)
    #define L_AGC_GAIN_VAL_30dB												((uint8_t) 0x78)
    #define L_AGC_GAIN_VAL_30P5dB											((uint8_t) 0x7A)
    #define L_AGC_GAIN_VAL_31dB												((uint8_t) 0x7C)
    #define L_AGC_GAIN_VAL_31P5dB											((uint8_t) 0x7E)
    #define L_AGC_GAIN_VAL_32dB												((uint8_t) 0x80)
    #define L_AGC_GAIN_VAL_32P5dB											((uint8_t) 0x82)
    #define L_AGC_GAIN_VAL_33dB												((uint8_t) 0x84)
    #define L_AGC_GAIN_VAL_33P5dB											((uint8_t) 0x86)
    #define L_AGC_GAIN_VAL_34dB												((uint8_t) 0x88)
    #define L_AGC_GAIN_VAL_34P5dB											((uint8_t) 0x8A)
    #define L_AGC_GAIN_VAL_35dB												((uint8_t) 0x8C)
    #define L_AGC_GAIN_VAL_35P5dB											((uint8_t) 0x8E)
    #define L_AGC_GAIN_VAL_36dB												((uint8_t) 0x90)
    #define L_AGC_GAIN_VAL_36P5dB											((uint8_t) 0x92)
    #define L_AGC_GAIN_VAL_37dB												((uint8_t) 0x94)
    #define L_AGC_GAIN_VAL_37P5dB											((uint8_t) 0x96)
    #define L_AGC_GAIN_VAL_38dB												((uint8_t) 0x98)
    #define L_AGC_GAIN_VAL_38P5dB											((uint8_t) 0x9A)
    #define L_AGC_GAIN_VAL_39dB												((uint8_t) 0x9C)
    #define L_AGC_GAIN_VAL_39P5dB											((uint8_t) 0x9E)
    #define L_AGC_GAIN_VAL_40dB												((uint8_t) 0xA0)



/* Register 0x5E (R_AGC_CONTROL1) definition
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       Bit 7       |       Bit 6       |       Bit 5       |       Bit 4       |       Bit 3       |       Bit 2       |       Bit 1       |       Bit 0       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |         EN        |                        TARGET[2:0]                        |                                 RESERVED[3:0]                                 |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* R_AGC_CONTROL1 register */
    #define R_AGC_CONTROL1_ADDRESS											((uint8_t) 0x5E)
    #define R_AGC_CONTROL1_DEFAULT											((uint8_t) 0x00)

    /* EN field */
    #define R_AGC_CONTROL1_EN_MASK											((uint8_t) 0x80)
    #define R_AGC_CONTROL1_EN_DISABLE										((uint8_t) 0x00)    // DEFAULT
    #define R_AGC_CONTROL1_EN_ENABLE										((uint8_t) 0x80)

    /* TARGET field */
    #define R_AGC_CONTROL1_TARGET_MASK										((uint8_t) 0x70)
    #define R_AGC_CONTROL1_TARGET_M5P5dB									((uint8_t) 0x00)    // DEFAULT
    #define R_AGC_CONTROL1_TARGET_M8dB										((uint8_t) 0x10)
    #define R_AGC_CONTROL1_TARGET_M10dB										((uint8_t) 0x20)
    #define R_AGC_CONTROL1_TARGET_M12dB										((uint8_t) 0x30)
    #define R_AGC_CONTROL1_TARGET_M14dB										((uint8_t) 0x40)
    #define R_AGC_CONTROL1_TARGET_M17dB										((uint8_t) 0x50)
    #define R_AGC_CONTROL1_TARGET_M20dB										((uint8_t) 0x60)
    #define R_AGC_CONTROL1_TARGET_M24dB										((uint8_t) 0x70)



/* Register 0x5F (R_AGC_CONTROL2) definition
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       Bit 7       |       Bit 6       |       Bit 5       |       Bit 4       |       Bit 3       |       Bit 2       |       Bit 1       |       Bit 0       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |               HYST[1:0]               |                                          NOISE_THRES[4:0]                                         |         0         |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* R_AGC_CONTROL2 register */
    #define R_AGC_CONTROL2_ADDRESS											((uint8_t) 0x5F)
    #define R_AGC_CONTROL2_DEFAULT											((uint8_t) 0x00)

    /* HYST field */
    #define R_AGC_CONTROL2_HYST_MASK										((uint8_t) 0xC0)
    #define R_AGC_CONTROL2_HYST_1dB											((uint8_t) 0x00)    // DEFAULT
    #define R_AGC_CONTROL2_HYST_2dB											((uint8_t) 0x40)
    #define R_AGC_CONTROL2_HYST_4dB											((uint8_t) 0x80)
    #define R_AGC_CONTROL2_HYST_DISABLED									((uint8_t) 0xC0)

    /* NOISE_THRES field */
    #define R_AGC_CONTROL2_NOISE_THRES_MASK									((uint8_t) 0x3E)
    #define R_AGC_CONTROL2_NOISE_THRES_DISABLED								((uint8_t) 0x00)    // DEFAULT
    #define R_AGC_CONTROL2_NOISE_THRES_M30dB								((uint8_t) 0x02)
    #define R_AGC_CONTROL2_NOISE_THRES_M32dB								((uint8_t) 0x04)
    #define R_AGC_CONTROL2_NOISE_THRES_M34dB								((uint8_t) 0x06)
    #define R_AGC_CONTROL2_NOISE_THRES_M36dB								((uint8_t) 0x08)
    #define R_AGC_CONTROL2_NOISE_THRES_M38dB								((uint8_t) 0x0A)
    #define R_AGC_CONTROL2_NOISE_THRES_M40dB								((uint8_t) 0x0C)
    #define R_AGC_CONTROL2_NOISE_THRES_M42dB								((uint8_t) 0x0E)
    #define R_AGC_CONTROL2_NOISE_THRES_M44dB								((uint8_t) 0x10)
    #define R_AGC_CONTROL2_NOISE_THRES_M46dB								((uint8_t) 0x12)
    #define R_AGC_CONTROL2_NOISE_THRES_M48dB								((uint8_t) 0x14)
    #define R_AGC_CONTROL2_NOISE_THRES_M50dB								((uint8_t) 0x16)
    #define R_AGC_CONTROL2_NOISE_THRES_M52dB								((uint8_t) 0x18)
    #define R_AGC_CONTROL2_NOISE_THRES_M54dB								((uint8_t) 0x1A)
    #define R_AGC_CONTROL2_NOISE_THRES_M56dB								((uint8_t) 0x1C)
    #define R_AGC_CONTROL2_NOISE_THRES_M58dB								((uint8_t) 0x1E)
    #define R_AGC_CONTROL2_NOISE_THRES_M60dB								((uint8_t) 0x20)
    #define R_AGC_CONTROL2_NOISE_THRES_M62dB								((uint8_t) 0x22)
    #define R_AGC_CONTROL2_NOISE_THRES_M64dB								((uint8_t) 0x24)
    #define R_AGC_CONTROL2_NOISE_THRES_M66dB								((uint8_t) 0x26)
    #define R_AGC_CONTROL2_NOISE_THRES_M68dB								((uint8_t) 0x28)
    #define R_AGC_CONTROL2_NOISE_THRES_M70dB								((uint8_t) 0x2A)
    #define R_AGC_CONTROL2_NOISE_THRES_M72dB								((uint8_t) 0x2C)
    #define R_AGC_CONTROL2_NOISE_THRES_M74dB								((uint8_t) 0x2E)
    #define R_AGC_CONTROL2_NOISE_THRES_M76dB								((uint8_t) 0x30)
    #define R_AGC_CONTROL2_NOISE_THRES_M78dB								((uint8_t) 0x32)
    #define R_AGC_CONTROL2_NOISE_THRES_M80dB								((uint8_t) 0x34)
    #define R_AGC_CONTROL2_NOISE_THRES_M82dB								((uint8_t) 0x36)
    #define R_AGC_CONTROL2_NOISE_THRES_M84dB								((uint8_t) 0x38)
    #define R_AGC_CONTROL2_NOISE_THRES_M86dB								((uint8_t) 0x3A)
    #define R_AGC_CONTROL2_NOISE_THRES_M88dB								((uint8_t) 0x3C)
    #define R_AGC_CONTROL2_NOISE_THRES_M90dB								((uint8_t) 0x3E)

    /* CLIP_STEP field */
    #define R_AGC_CONTROL2_CLIP_STEP_MASK									((uint8_t) 0x01)
    #define R_AGC_CONTROL2_CLIP_STEP_DISABLE								((uint8_t) 0x00)    // DEFAULT
    #define R_AGC_CONTROL2_CLIP_STEP_ENABLE									((uint8_t) 0x01)



/* Register 0x60 (R_AGC_MAX) definition
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       Bit 7       |       Bit 6       |       Bit 5       |       Bit 4       |       Bit 3       |       Bit 2       |       Bit 1       |       Bit 0       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |      RESERVED     |                                                                 GAIN[6:0]                                                                 |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* R_AGC_MAX register */
    #define R_AGC_MAX_ADDRESS												((uint8_t) 0x60)
    #define R_AGC_MAX_DEFAULT												((uint8_t) 0x7F)

    /* GAIN field */
    #define R_AGC_MAX_GAIN_MASK												((uint8_t) 0x7F)
    #define R_AGC_MAX_GAIN_0dB												((uint8_t) 0x00)
    #define R_AGC_MAX_GAIN_0P5dB											((uint8_t) 0x01)
    #define R_AGC_MAX_GAIN_1dB												((uint8_t) 0x02)
    #define R_AGC_MAX_GAIN_1P5dB											((uint8_t) 0x03)
    #define R_AGC_MAX_GAIN_2dB												((uint8_t) 0x04)
    #define R_AGC_MAX_GAIN_2P5dB											((uint8_t) 0x05)
    #define R_AGC_MAX_GAIN_3dB												((uint8_t) 0x06)
    #define R_AGC_MAX_GAIN_3P5dB											((uint8_t) 0x07)
    #define R_AGC_MAX_GAIN_4dB												((uint8_t) 0x08)
    #define R_AGC_MAX_GAIN_4P5dB											((uint8_t) 0x09)
    #define R_AGC_MAX_GAIN_5dB												((uint8_t) 0x0A)
    #define R_AGC_MAX_GAIN_5P5dB											((uint8_t) 0x0B)
    #define R_AGC_MAX_GAIN_6dB												((uint8_t) 0x0C)
    #define R_AGC_MAX_GAIN_6P5dB											((uint8_t) 0x0D)
    #define R_AGC_MAX_GAIN_7dB												((uint8_t) 0x0E)
    #define R_AGC_MAX_GAIN_7P5dB											((uint8_t) 0x0F)
    #define R_AGC_MAX_GAIN_8dB												((uint8_t) 0x10)
    #define R_AGC_MAX_GAIN_8P5dB											((uint8_t) 0x11)
    #define R_AGC_MAX_GAIN_9dB												((uint8_t) 0x12)
    #define R_AGC_MAX_GAIN_9P5dB											((uint8_t) 0x13)
    #define R_AGC_MAX_GAIN_10dB												((uint8_t) 0x14)
    #define R_AGC_MAX_GAIN_10P5dB											((uint8_t) 0x15)
    #define R_AGC_MAX_GAIN_11dB												((uint8_t) 0x16)
    #define R_AGC_MAX_GAIN_11P5dB											((uint8_t) 0x17)
    #define R_AGC_MAX_GAIN_12dB												((uint8_t) 0x18)
    #define R_AGC_MAX_GAIN_12P5dB											((uint8_t) 0x19)
    #define R_AGC_MAX_GAIN_13dB												((uint8_t) 0x1A)
    #define R_AGC_MAX_GAIN_13P5dB											((uint8_t) 0x1B)
    #define R_AGC_MAX_GAIN_14dB												((uint8_t) 0x1C)
    #define R_AGC_MAX_GAIN_14P5dB											((uint8_t) 0x1D)
    #define R_AGC_MAX_GAIN_15dB												((uint8_t) 0x1E)
    #define R_AGC_MAX_GAIN_15P5dB											((uint8_t) 0x1F)
    #define R_AGC_MAX_GAIN_16dB												((uint8_t) 0x20)
    #define R_AGC_MAX_GAIN_16P5dB											((uint8_t) 0x21)
    #define R_AGC_MAX_GAIN_17dB2											((uint8_t) 0x22)
    #define R_AGC_MAX_GAIN_17P5dB											((uint8_t) 0x23)
    #define R_AGC_MAX_GAIN_18dB												((uint8_t) 0x24)
    #define R_AGC_MAX_GAIN_18P5dB											((uint8_t) 0x25)
    #define R_AGC_MAX_GAIN_19dB												((uint8_t) 0x26)
    #define R_AGC_MAX_GAIN_19P5dB											((uint8_t) 0x27)
    #define R_AGC_MAX_GAIN_20dB												((uint8_t) 0x28)
    #define R_AGC_MAX_GAIN_20P5dB											((uint8_t) 0x29)
    #define R_AGC_MAX_GAIN_21dB												((uint8_t) 0x2A)
    #define R_AGC_MAX_GAIN_21P5dB											((uint8_t) 0x2B)
    #define R_AGC_MAX_GAIN_22dB												((uint8_t) 0x2C)
    #define R_AGC_MAX_GAIN_22P5dB											((uint8_t) 0x2D)
    #define R_AGC_MAX_GAIN_23dB												((uint8_t) 0x2E)
    #define R_AGC_MAX_GAIN_23P5dB											((uint8_t) 0x2F)
    #define R_AGC_MAX_GAIN_24dB												((uint8_t) 0x30)
    #define R_AGC_MAX_GAIN_24P5dB											((uint8_t) 0x31)
    #define R_AGC_MAX_GAIN_25dB												((uint8_t) 0x32)
    #define R_AGC_MAX_GAIN_25P5dB											((uint8_t) 0x33)
    #define R_AGC_MAX_GAIN_26dB												((uint8_t) 0x34)
    #define R_AGC_MAX_GAIN_26P5dB											((uint8_t) 0x35)
    #define R_AGC_MAX_GAIN_27dB												((uint8_t) 0x36)
    #define R_AGC_MAX_GAIN_27P5dB											((uint8_t) 0x37)
    #define R_AGC_MAX_GAIN_28dB												((uint8_t) 0x38)
    #define R_AGC_MAX_GAIN_28P5dB											((uint8_t) 0x39)
    #define R_AGC_MAX_GAIN_29dB												((uint8_t) 0x3A)
    #define R_AGC_MAX_GAIN_29P5dB											((uint8_t) 0x3B)
    #define R_AGC_MAX_GAIN_30dB												((uint8_t) 0x3C)
    #define R_AGC_MAX_GAIN_30P5dB											((uint8_t) 0x3D)
    #define R_AGC_MAX_GAIN_31dB												((uint8_t) 0x3E)
    #define R_AGC_MAX_GAIN_31P5dB											((uint8_t) 0x3F)
    #define R_AGC_MAX_GAIN_32dB												((uint8_t) 0x40)
    #define R_AGC_MAX_GAIN_32P5dB											((uint8_t) 0x41)
    #define R_AGC_MAX_GAIN_33dB												((uint8_t) 0x42)
    #define R_AGC_MAX_GAIN_33P5dB											((uint8_t) 0x43)
    #define R_AGC_MAX_GAIN_34dB												((uint8_t) 0x44)
    #define R_AGC_MAX_GAIN_34P5dB											((uint8_t) 0x45)
    #define R_AGC_MAX_GAIN_35dB												((uint8_t) 0x46)
    #define R_AGC_MAX_GAIN_35P5dB											((uint8_t) 0x47)
    #define R_AGC_MAX_GAIN_36dB												((uint8_t) 0x48)
    #define R_AGC_MAX_GAIN_36P5dB											((uint8_t) 0x49)
    #define R_AGC_MAX_GAIN_37dB												((uint8_t) 0x4A)
    #define R_AGC_MAX_GAIN_37P5dB											((uint8_t) 0x4B)
    #define R_AGC_MAX_GAIN_38dB												((uint8_t) 0x4C)
    #define R_AGC_MAX_GAIN_38P5dB											((uint8_t) 0x4D)
    #define R_AGC_MAX_GAIN_39dB												((uint8_t) 0x4E)
    #define R_AGC_MAX_GAIN_39P5dB											((uint8_t) 0x4F)
    #define R_AGC_MAX_GAIN_40dB												((uint8_t) 0x50)



/* Register 0x61 (R_AGC_ATTACK) definition
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       Bit 7       |       Bit 6       |       Bit 5       |       Bit 4       |       Bit 3       |       Bit 2       |       Bit 1       |       Bit 0       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                             TIME[4:0]                                             |                         MULT[2:0]                         |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* R_AGC_ATTACK register */
    #define R_AGC_ATTACK_ADDRESS											((uint8_t) 0x61)
    #define R_AGC_ATTACK_DEFAULT											((uint8_t) 0x00)

    /* TIME field */
    #define R_AGC_ATTACK_TIME_MASK											((uint8_t) 0xF8)
    #define R_AGC_ATTACK_TIME_1												((uint8_t) 0x00)    // DEFAULT
    #define R_AGC_ATTACK_TIME_3												((uint8_t) 0x08)
    #define R_AGC_ATTACK_TIME_5												((uint8_t) 0x10)
    #define R_AGC_ATTACK_TIME_7												((uint8_t) 0x18)
    #define R_AGC_ATTACK_TIME_9												((uint8_t) 0x20)
    #define R_AGC_ATTACK_TIME_11											((uint8_t) 0x28)
    #define R_AGC_ATTACK_TIME_13											((uint8_t) 0x30)
    #define R_AGC_ATTACK_TIME_15											((uint8_t) 0x38)
    #define R_AGC_ATTACK_TIME_17											((uint8_t) 0x40)
    #define R_AGC_ATTACK_TIME_19											((uint8_t) 0x48)
    #define R_AGC_ATTACK_TIME_21											((uint8_t) 0x50)
    #define R_AGC_ATTACK_TIME_23											((uint8_t) 0x58)
    #define R_AGC_ATTACK_TIME_25											((uint8_t) 0x60)
    #define R_AGC_ATTACK_TIME_27											((uint8_t) 0x68)
    #define R_AGC_ATTACK_TIME_29											((uint8_t) 0x70)
    #define R_AGC_ATTACK_TIME_31											((uint8_t) 0x78)
    #define R_AGC_ATTACK_TIME_33											((uint8_t) 0x80)
    #define R_AGC_ATTACK_TIME_35											((uint8_t) 0x88)
    #define R_AGC_ATTACK_TIME_37											((uint8_t) 0x90)
    #define R_AGC_ATTACK_TIME_39											((uint8_t) 0x98)
    #define R_AGC_ATTACK_TIME_41											((uint8_t) 0xA0)
    #define R_AGC_ATTACK_TIME_43											((uint8_t) 0xA8)
    #define R_AGC_ATTACK_TIME_45											((uint8_t) 0xB0)
    #define R_AGC_ATTACK_TIME_47											((uint8_t) 0xB8)
    #define R_AGC_ATTACK_TIME_49											((uint8_t) 0xC0)
    #define R_AGC_ATTACK_TIME_51											((uint8_t) 0xC8)
    #define R_AGC_ATTACK_TIME_53											((uint8_t) 0xD0)
    #define R_AGC_ATTACK_TIME_55											((uint8_t) 0xD8)
    #define R_AGC_ATTACK_TIME_57											((uint8_t) 0xE0)
    #define R_AGC_ATTACK_TIME_59											((uint8_t) 0xE8)
    #define R_AGC_ATTACK_TIME_61											((uint8_t) 0xF0)
    #define R_AGC_ATTACK_TIME_63											((uint8_t) 0xF8)

    /* MULT field */
    #define R_AGC_ATTACK_MULT_MASK											((uint8_t) 0x07)
    #define R_AGC_ATTACK_MULT_1												((uint8_t) 0x00)    // DEFAULT
    #define R_AGC_ATTACK_MULT_2												((uint8_t) 0x01)
    #define R_AGC_ATTACK_MULT_4												((uint8_t) 0x02)
    #define R_AGC_ATTACK_MULT_8												((uint8_t) 0x03)
    #define R_AGC_ATTACK_MULT_16											((uint8_t) 0x04)
    #define R_AGC_ATTACK_MULT_32											((uint8_t) 0x05)
    #define R_AGC_ATTACK_MULT_64											((uint8_t) 0x06)
    #define R_AGC_ATTACK_MULT_128											((uint8_t) 0x07)



/* Register 0x62 (R_AGC_DECAY) definition
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       Bit 7       |       Bit 6       |       Bit 5       |       Bit 4       |       Bit 3       |       Bit 2       |       Bit 1       |       Bit 0       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                             TIME[4:0]                                             |                         MULT[2:0]                         |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* R_AGC_DECAY register */
    #define R_AGC_DECAY_ADDRESS												((uint8_t) 0x62)
    #define R_AGC_DECAY_DEFAULT												((uint8_t) 0x00)

    /* TIME field */
    #define R_AGC_DECAY_TIME_MASK											((uint8_t) 0xF8)
    #define R_AGC_DECAY_TIME_1												((uint8_t) 0x00)    // DEFAULT
    #define R_AGC_DECAY_TIME_3												((uint8_t) 0x08)
    #define R_AGC_DECAY_TIME_5												((uint8_t) 0x10)
    #define R_AGC_DECAY_TIME_7												((uint8_t) 0x18)
    #define R_AGC_DECAY_TIME_9												((uint8_t) 0x20)
    #define R_AGC_DECAY_TIME_11												((uint8_t) 0x28)
    #define R_AGC_DECAY_TIME_13												((uint8_t) 0x30)
    #define R_AGC_DECAY_TIME_15												((uint8_t) 0x38)
    #define R_AGC_DECAY_TIME_17												((uint8_t) 0x40)
    #define R_AGC_DECAY_TIME_19												((uint8_t) 0x48)
    #define R_AGC_DECAY_TIME_21												((uint8_t) 0x50)
    #define R_AGC_DECAY_TIME_23												((uint8_t) 0x58)
    #define R_AGC_DECAY_TIME_25												((uint8_t) 0x60)
    #define R_AGC_DECAY_TIME_27												((uint8_t) 0x68)
    #define R_AGC_DECAY_TIME_29												((uint8_t) 0x70)
    #define R_AGC_DECAY_TIME_31												((uint8_t) 0x78)
    #define R_AGC_DECAY_TIME_33												((uint8_t) 0x80)
    #define R_AGC_DECAY_TIME_35												((uint8_t) 0x88)
    #define R_AGC_DECAY_TIME_37												((uint8_t) 0x90)
    #define R_AGC_DECAY_TIME_39												((uint8_t) 0x98)
    #define R_AGC_DECAY_TIME_41												((uint8_t) 0xA0)
    #define R_AGC_DECAY_TIME_43												((uint8_t) 0xA8)
    #define R_AGC_DECAY_TIME_45												((uint8_t) 0xB0)
    #define R_AGC_DECAY_TIME_47												((uint8_t) 0xB8)
    #define R_AGC_DECAY_TIME_49												((uint8_t) 0xC0)
    #define R_AGC_DECAY_TIME_51												((uint8_t) 0xC8)
    #define R_AGC_DECAY_TIME_53												((uint8_t) 0xD0)
    #define R_AGC_DECAY_TIME_55												((uint8_t) 0xD8)
    #define R_AGC_DECAY_TIME_57												((uint8_t) 0xE0)
    #define R_AGC_DECAY_TIME_59												((uint8_t) 0xE8)
    #define R_AGC_DECAY_TIME_61												((uint8_t) 0xF0)
    #define R_AGC_DECAY_TIME_63												((uint8_t) 0xF8)

    /* MULT field */
    #define R_AGC_DECAY_MULT_MASK											((uint8_t) 0x07)
    #define R_AGC_DECAY_MULT_1												((uint8_t) 0x00)    // DEFAULT
    #define R_AGC_DECAY_MULT_2												((uint8_t) 0x01)
    #define R_AGC_DECAY_MULT_4												((uint8_t) 0x02)
    #define R_AGC_DECAY_MULT_8												((uint8_t) 0x03)
    #define R_AGC_DECAY_MULT_16												((uint8_t) 0x04)
    #define R_AGC_DECAY_MULT_32												((uint8_t) 0x05)
    #define R_AGC_DECAY_MULT_64												((uint8_t) 0x06)
    #define R_AGC_DECAY_MULT_128											((uint8_t) 0x07)



/* Register 0x63 (R_AGC_NOISE) definition
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       Bit 7       |       Bit 6       |       Bit 5       |       Bit 4       |       Bit 3       |       Bit 2       |       Bit 1       |       Bit 0       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                       RESERVED[2:0]                       |                                           DEBOUNCE[4:0]                                           |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* R_AGC_NOISE register */
    #define R_AGC_NOISE_ADDRESS												((uint8_t) 0x63)
    #define R_AGC_NOISE_DEFAULT												((uint8_t) 0x00)

    /* DEBOUNCE field */
    #define R_AGC_NOISE_DEBOUNCE_MASK										((uint8_t) 0x1F)
    #define R_AGC_NOISE_DEBOUNCE_0											((uint8_t) 0x00)    // DEFAULT
    #define R_AGC_NOISE_DEBOUNCE_4											((uint8_t) 0x01)
    #define R_AGC_NOISE_DEBOUNCE_8											((uint8_t) 0x02)
    #define R_AGC_NOISE_DEBOUNCE_16											((uint8_t) 0x03)
    #define R_AGC_NOISE_DEBOUNCE_32											((uint8_t) 0x04)
    #define R_AGC_NOISE_DEBOUNCE_64											((uint8_t) 0x05)
    #define R_AGC_NOISE_DEBOUNCE_128										((uint8_t) 0x06)
    #define R_AGC_NOISE_DEBOUNCE_256										((uint8_t) 0x07)
    #define R_AGC_NOISE_DEBOUNCE_512										((uint8_t) 0x08)
    #define R_AGC_NOISE_DEBOUNCE_1024										((uint8_t) 0x09)
    #define R_AGC_NOISE_DEBOUNCE_2048										((uint8_t) 0x0A)
    #define R_AGC_NOISE_DEBOUNCE_4096										((uint8_t) 0x0B)
    #define R_AGC_NOISE_DEBOUNCE_8192										((uint8_t) 0x0C)
    #define R_AGC_NOISE_DEBOUNCE_12288										((uint8_t) 0x0D)
    #define R_AGC_NOISE_DEBOUNCE_16384										((uint8_t) 0x0E)
    #define R_AGC_NOISE_DEBOUNCE_20480										((uint8_t) 0x0F)



/* Register 0x64 (R_AGC_SIGNAL) definition
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       Bit 7       |       Bit 6       |       Bit 5       |       Bit 4       |       Bit 3       |       Bit 2       |       Bit 1       |       Bit 0       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                 RESERVED[3:0]                                 |                                 DEBOUNCE[3:0]                                 |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* R_AGC_SIGNAL register */
    #define R_AGC_SIGNAL_ADDRESS											((uint8_t) 0x64)
    #define R_AGC_SIGNAL_DEFAULT											((uint8_t) 0x00)

    /* DEBOUNCE field */
    #define R_AGC_SIGNAL_DEBOUNCE_MASK										((uint8_t) 0x0F)
    #define R_AGC_SIGNAL_DEBOUNCE_0											((uint8_t) 0x00)    // DEFAULT
    #define R_AGC_SIGNAL_DEBOUNCE_4											((uint8_t) 0x01)
    #define R_AGC_SIGNAL_DEBOUNCE_8											((uint8_t) 0x02)
    #define R_AGC_SIGNAL_DEBOUNCE_16										((uint8_t) 0x03)
    #define R_AGC_SIGNAL_DEBOUNCE_32										((uint8_t) 0x04)
    #define R_AGC_SIGNAL_DEBOUNCE_64										((uint8_t) 0x05)
    #define R_AGC_SIGNAL_DEBOUNCE_128										((uint8_t) 0x06)
    #define R_AGC_SIGNAL_DEBOUNCE_256										((uint8_t) 0x07)
    #define R_AGC_SIGNAL_DEBOUNCE_512										((uint8_t) 0x08)
    #define R_AGC_SIGNAL_DEBOUNCE_1024										((uint8_t) 0x09)
    #define R_AGC_SIGNAL_DEBOUNCE_2048										((uint8_t) 0x0A)
    #define R_AGC_SIGNAL_DEBOUNCE_4096										((uint8_t) 0x0B)
    #define R_AGC_SIGNAL_DEBOUNCE_6144										((uint8_t) 0x0C)
    #define R_AGC_SIGNAL_DEBOUNCE_8192										((uint8_t) 0x0D)
    #define R_AGC_SIGNAL_DEBOUNCE_10240										((uint8_t) 0x0E)
    #define R_AGC_SIGNAL_DEBOUNCE_12288										((uint8_t) 0x0F)



/* Register 0x65 (R_AGC_GAIN) definition
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |       Bit 7       |       Bit 6       |       Bit 5       |       Bit 4       |       Bit 3       |       Bit 2       |       Bit 1       |       Bit 0       |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 * |                                                                  VAL[6:0]                                                                 |                   |
 * |---------------------------------------------------------------------------------------------------------------------------------------------------------------|
 */

    /* R_AGC_GAIN register */
    #define R_AGC_GAIN_ADDRESS												((uint8_t) 0x65)
    #define R_AGC_GAIN_DEFAULT												((uint8_t) 0x00)

    /* VAL field */
    #define R_AGC_GAIN_VAL_MASK												((uint8_t) 0xFE)
    #define R_AGC_GAIN_VAL_0dB												((uint8_t) 0x00)    // DEFAULT
    #define R_AGC_GAIN_VAL_0P5dB											((uint8_t) 0x02)
    #define R_AGC_GAIN_VAL_1dB												((uint8_t) 0x04)
    #define R_AGC_GAIN_VAL_1P5dB											((uint8_t) 0x06)
    #define R_AGC_GAIN_VAL_2dB												((uint8_t) 0x08)
    #define R_AGC_GAIN_VAL_2P5dB											((uint8_t) 0x0A)
    #define R_AGC_GAIN_VAL_3dB												((uint8_t) 0x0C)
    #define R_AGC_GAIN_VAL_3P5dB											((uint8_t) 0x0E)
    #define R_AGC_GAIN_VAL_4dB												((uint8_t) 0x10)
    #define R_AGC_GAIN_VAL_4P5dB											((uint8_t) 0x12)
    #define R_AGC_GAIN_VAL_5dB												((uint8_t) 0x14)
    #define R_AGC_GAIN_VAL_5P5dB											((uint8_t) 0x16)
    #define R_AGC_GAIN_VAL_6dB												((uint8_t) 0x18)
    #define R_AGC_GAIN_VAL_6P5dB											((uint8_t) 0x1A)
    #define R_AGC_GAIN_VAL_7dB												((uint8_t) 0x1C)
    #define R_AGC_GAIN_VAL_7P5dB											((uint8_t) 0x1E)
    #define R_AGC_GAIN_VAL_8dB												((uint8_t) 0x20)
    #define R_AGC_GAIN_VAL_8P5dB											((uint8_t) 0x22)
    #define R_AGC_GAIN_VAL_9dB												((uint8_t) 0x24)
    #define R_AGC_GAIN_VAL_9P5dB											((uint8_t) 0x26)
    #define R_AGC_GAIN_VAL_10dB												((uint8_t) 0x28)
    #define R_AGC_GAIN_VAL_10P5dB											((uint8_t) 0x2A)
    #define R_AGC_GAIN_VAL_11dB												((uint8_t) 0x2C)
    #define R_AGC_GAIN_VAL_11P5dB											((uint8_t) 0x2E)
    #define R_AGC_GAIN_VAL_12dB												((uint8_t) 0x30)
    #define R_AGC_GAIN_VAL_12P5dB											((uint8_t) 0x32)
    #define R_AGC_GAIN_VAL_13dB												((uint8_t) 0x34)
    #define R_AGC_GAIN_VAL_13P5dB											((uint8_t) 0x36)
    #define R_AGC_GAIN_VAL_14dB												((uint8_t) 0x38)
    #define R_AGC_GAIN_VAL_14P5dB											((uint8_t) 0x3A)
    #define R_AGC_GAIN_VAL_15dB												((uint8_t) 0x3C)
    #define R_AGC_GAIN_VAL_15P5dB											((uint8_t) 0x3E)
    #define R_AGC_GAIN_VAL_16dB												((uint8_t) 0x40)
    #define R_AGC_GAIN_VAL_16P5dB											((uint8_t) 0x42)
    #define R_AGC_GAIN_VAL_17dB2											((uint8_t) 0x44)
    #define R_AGC_GAIN_VAL_17P5dB											((uint8_t) 0x46)
    #define R_AGC_GAIN_VAL_18dB												((uint8_t) 0x48)
    #define R_AGC_GAIN_VAL_18P5dB											((uint8_t) 0x4A)
    #define R_AGC_GAIN_VAL_19dB												((uint8_t) 0x4C)
    #define R_AGC_GAIN_VAL_19P5dB											((uint8_t) 0x4E)
    #define R_AGC_GAIN_VAL_20dB												((uint8_t) 0x50)
    #define R_AGC_GAIN_VAL_20P5dB											((uint8_t) 0x52)
    #define R_AGC_GAIN_VAL_21dB												((uint8_t) 0x54)
    #define R_AGC_GAIN_VAL_21P5dB											((uint8_t) 0x56)
    #define R_AGC_GAIN_VAL_22dB												((uint8_t) 0x58)
    #define R_AGC_GAIN_VAL_22P5dB											((uint8_t) 0x5A)
    #define R_AGC_GAIN_VAL_23dB												((uint8_t) 0x5C)
    #define R_AGC_GAIN_VAL_23P5dB											((uint8_t) 0x5E)
    #define R_AGC_GAIN_VAL_24dB												((uint8_t) 0x60)
    #define R_AGC_GAIN_VAL_24P5dB											((uint8_t) 0x62)
    #define R_AGC_GAIN_VAL_25dB												((uint8_t) 0x64)
    #define R_AGC_GAIN_VAL_25P5dB											((uint8_t) 0x66)
    #define R_AGC_GAIN_VAL_26dB												((uint8_t) 0x68)
    #define R_AGC_GAIN_VAL_26P5dB											((uint8_t) 0x6A)
    #define R_AGC_GAIN_VAL_27dB												((uint8_t) 0x6C)
    #define R_AGC_GAIN_VAL_27P5dB											((uint8_t) 0x6E)
    #define R_AGC_GAIN_VAL_28dB												((uint8_t) 0x70)
    #define R_AGC_GAIN_VAL_28P5dB											((uint8_t) 0x72)
    #define R_AGC_GAIN_VAL_29dB												((uint8_t) 0x74)
    #define R_AGC_GAIN_VAL_29P5dB											((uint8_t) 0x76)
    #define R_AGC_GAIN_VAL_30dB												((uint8_t) 0x78)
    #define R_AGC_GAIN_VAL_30P5dB											((uint8_t) 0x7A)
    #define R_AGC_GAIN_VAL_31dB												((uint8_t) 0x7C)
    #define R_AGC_GAIN_VAL_31P5dB											((uint8_t) 0x7E)
    #define R_AGC_GAIN_VAL_32dB												((uint8_t) 0x80)
    #define R_AGC_GAIN_VAL_32P5dB											((uint8_t) 0x82)
    #define R_AGC_GAIN_VAL_33dB												((uint8_t) 0x84)
    #define R_AGC_GAIN_VAL_33P5dB											((uint8_t) 0x86)
    #define R_AGC_GAIN_VAL_34dB												((uint8_t) 0x88)
    #define R_AGC_GAIN_VAL_34P5dB											((uint8_t) 0x8A)
    #define R_AGC_GAIN_VAL_35dB												((uint8_t) 0x8C)
    #define R_AGC_GAIN_VAL_35P5dB											((uint8_t) 0x8E)
    #define R_AGC_GAIN_VAL_36dB												((uint8_t) 0x90)
    #define R_AGC_GAIN_VAL_36P5dB											((uint8_t) 0x92)
    #define R_AGC_GAIN_VAL_37dB												((uint8_t) 0x94)
    #define R_AGC_GAIN_VAL_37P5dB											((uint8_t) 0x96)
    #define R_AGC_GAIN_VAL_38dB												((uint8_t) 0x98)
    #define R_AGC_GAIN_VAL_38P5dB											((uint8_t) 0x9A)
    #define R_AGC_GAIN_VAL_39dB												((uint8_t) 0x9C)
    #define R_AGC_GAIN_VAL_39P5dB											((uint8_t) 0x9E)
    #define R_AGC_GAIN_VAL_40dB												((uint8_t) 0xA0)



#endif /* TLV320ADC3100_PAGE0_H_ */
