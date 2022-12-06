/*
 * @file tlv320adc3100_page1.h
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

#ifndef TLV320ADC3100_PAGE1_H_
#define TLV320ADC3100_PAGE1_H_

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


/* Register 0x1A (DITHER_CTRL) definition
 * |---------------------------------------------------------------------------------------------------------------|
 * |    Bit 7    |    Bit 6    |    Bit 5    |    Bit 4    |    Bit 3    |    Bit 2    |    Bit 1    |    Bit 0    |
 * |---------------------------------------------------------------------------------------------------------------|
 * |                    LADC_OFFET[3:0]                    |                    RADC_OFFSET[3:0]                   |
 * |---------------------------------------------------------------------------------------------------------------|
 */

    /* DITHER_CTRL register */
    #define DITHER_CTRL_ADDRESS												((uint8_t) 0x1A)
    #define DITHER_CTRL_DEFAULT												((uint8_t) 0x00)

    /* LADC_OFFET field */
    #define DITHER_CTRL_LADC_OFFET_MASK										((uint8_t) 0xF0)
    #define DITHER_CTRL_LADC_OFFET_M105mV									((uint8_t) 0xF0)
    #define DITHER_CTRL_LADC_OFFET_M90mV									((uint8_t) 0xE0)
    #define DITHER_CTRL_LADC_OFFET_M75mV									((uint8_t) 0xD0)
    #define DITHER_CTRL_LADC_OFFET_M60mV									((uint8_t) 0xC0)
    #define DITHER_CTRL_LADC_OFFET_M45mV									((uint8_t) 0xB0)
    #define DITHER_CTRL_LADC_OFFET_M30mV									((uint8_t) 0xA0)
    #define DITHER_CTRL_LADC_OFFET_M15mV									((uint8_t) 0x90)
    #define DITHER_CTRL_LADC_OFFET_0mV										((uint8_t) 0x00)    // DEFAULT
    #define DITHER_CTRL_LADC_OFFET_15mV										((uint8_t) 0x10)
    #define DITHER_CTRL_LADC_OFFET_30mV										((uint8_t) 0x20)
    #define DITHER_CTRL_LADC_OFFET_45mV										((uint8_t) 0x30)
    #define DITHER_CTRL_LADC_OFFET_60mV										((uint8_t) 0x40)
    #define DITHER_CTRL_LADC_OFFET_75mV										((uint8_t) 0x50)
    #define DITHER_CTRL_LADC_OFFET_90mV										((uint8_t) 0x60)
    #define DITHER_CTRL_LADC_OFFET_105mV									((uint8_t) 0x70)

    /* RADC_OFFSET field */
    #define DITHER_CTRL_RADC_OFFSET_MASK									((uint8_t) 0x0F)
    #define DITHER_CTRL_RADC_OFFSET_M105mV									((uint8_t) 0x0F)
    #define DITHER_CTRL_RADC_OFFSET_M90mV									((uint8_t) 0x0E)
    #define DITHER_CTRL_RADC_OFFSET_M75mV									((uint8_t) 0x0D)
    #define DITHER_CTRL_RADC_OFFSET_M60mV									((uint8_t) 0x0C)
    #define DITHER_CTRL_RADC_OFFSET_M45mV									((uint8_t) 0x0B)
    #define DITHER_CTRL_RADC_OFFSET_M30mV									((uint8_t) 0x0A)
    #define DITHER_CTRL_RADC_OFFSET_M15mV									((uint8_t) 0x09)
    #define DITHER_CTRL_RADC_OFFSET_0mV										((uint8_t) 0x00)    // DEFAULT
    #define DITHER_CTRL_RADC_OFFSET_15mV									((uint8_t) 0x01)
    #define DITHER_CTRL_RADC_OFFSET_30mV									((uint8_t) 0x02)
    #define DITHER_CTRL_RADC_OFFSET_45mV									((uint8_t) 0x03)
    #define DITHER_CTRL_RADC_OFFSET_60mV									((uint8_t) 0x04)
    #define DITHER_CTRL_RADC_OFFSET_75mV									((uint8_t) 0x05)
    #define DITHER_CTRL_RADC_OFFSET_90mV									((uint8_t) 0x06)
    #define DITHER_CTRL_RADC_OFFSET_105mV									((uint8_t) 0x07)



/* Register 0x33 (MICBIAS_CTRL) definition
 * |---------------------------------------------------------------------------------------------------------------|
 * |    Bit 7    |    Bit 6    |    Bit 5    |    Bit 4    |    Bit 3    |    Bit 2    |    Bit 1    |    Bit 0    |
 * |---------------------------------------------------------------------------------------------------------------|
 * |   RESERVED  |          VAL[1:0]         |                            RESERVED[4:0]                            |
 * |---------------------------------------------------------------------------------------------------------------|
 */

    /* MICBIAS_CTRL register */
    #define MICBIAS_CTRL_ADDRESS											((uint8_t) 0x33)
    #define MICBIAS_CTRL_DEFAULT											((uint8_t) 0x00)

    /* VAL field */
    #define MICBIAS_CTRL_VAL_MASK											((uint8_t) 0x60)
    #define MICBIAS_CTRL_VAL_Pwdn											((uint8_t) 0x00)    // DEFAULT
    #define MICBIAS_CTRL_VAL_2P0V											((uint8_t) 0x20)
    #define MICBIAS_CTRL_VAL_2P5V											((uint8_t) 0x40)
    #define MICBIAS_CTRL_VAL_AVDD											((uint8_t) 0x60)



/* Register 0x34 (LADC_INSEL_LPGA1) definition
 * |---------------------------------------------------------------------------------------------------------------|
 * |    Bit 7    |    Bit 6    |    Bit 5    |    Bit 4    |    Bit 3    |    Bit 2    |    Bit 1    |    Bit 0    |
 * |---------------------------------------------------------------------------------------------------------------|
 * |       LCH_SEL4[1:0]       |       LCH_SEL3[1:0]       |       LCH_SEL2[1:0]       |       RESERVED[1:0]       |
 * |---------------------------------------------------------------------------------------------------------------|
 */

    /* LADC_INSEL_LPGA1 register */
    #define LADC_INSEL_LPGA1_ADDRESS										((uint8_t) 0x34)
    #define LADC_INSEL_LPGA1_DEFAULT										((uint8_t) 0x55)

    /* LCH_SEL4 field */
    #define LADC_INSEL_LPGA1_LCH_SEL4_MASK									((uint8_t) 0xC0)
    #define LADC_INSEL_LPGA1_LCH_SEL4_0dB									((uint8_t) 0x00)
    #define LADC_INSEL_LPGA1_LCH_SEL4_6dB									((uint8_t) 0x40)    // DEFAULT
    #define LADC_INSEL_LPGA1_LCH_SEL4_NO_CONNECT							((uint8_t) 0x80)
    #define LADC_INSEL_LPGA1_LCH_SEL4_NO_CONNECT							((uint8_t) 0xC0)

    /* LCH_SEL3 field */
    #define LADC_INSEL_LPGA1_LCH_SEL3_MASK									((uint8_t) 0x30)
    #define LADC_INSEL_LPGA1_LCH_SEL3_CM_UNBIASED							((uint8_t) 0x00)
    #define LADC_INSEL_LPGA1_LCH_SEL3_CM_BIASED								((uint8_t) 0x10)    // DEFAULT

    /* LCH_SEL2 field */
    #define LADC_INSEL_LPGA1_LCH_SEL2_MASK									((uint8_t) 0x0C)
    #define LADC_INSEL_LPGA1_LCH_SEL2_0dB									((uint8_t) 0x00)
    #define LADC_INSEL_LPGA1_LCH_SEL2_6dB									((uint8_t) 0x04)    // DEFAULT
    #define LADC_INSEL_LPGA1_LCH_SEL2_NO_CONNECT							((uint8_t) 0x08)
    #define LADC_INSEL_LPGA1_LCH_SEL2_NO_CONNECT							((uint8_t) 0x0C)



/* Register 0x36 (LADC_INSEL_LPGA2) definition
 * |---------------------------------------------------------------------------------------------------------------|
 * |    Bit 7    |    Bit 6    |    Bit 5    |    Bit 4    |    Bit 3    |    Bit 2    |    Bit 1    |    Bit 0    |
 * |---------------------------------------------------------------------------------------------------------------|
 * | LPGA_BYPASS |  LCH_SELCM  |       LCH_SEL3X[1:0]      |       LCH_SEL2X[1:0]      |       RESERVED[1:0]       |
 * |---------------------------------------------------------------------------------------------------------------|
 */

    /* LADC_INSEL_LPGA2 register */
    #define LADC_INSEL_LPGA2_ADDRESS										((uint8_t) 0x36)
    #define LADC_INSEL_LPGA2_DEFAULT										((uint8_t) 0x15)

    /* LPGA_BYPASS field */
    #define LADC_INSEL_LPGA2_LPGA_BYPASS_MASK								((uint8_t) 0x80)
    #define LADC_INSEL_LPGA2_LPGA_BYPASS_NO_BYPASS							((uint8_t) 0x00)    // DEFAULT
    #define LADC_INSEL_LPGA2_LPGA_BYPASS_BYPASS								((uint8_t) 0x80)

    /* LCH_SELCM field */
    #define LADC_INSEL_LPGA2_LCH_SELCM_MASK									((uint8_t) 0x40)
    #define LADC_INSEL_LPGA2_LCH_SELCM_CM_UNBIASED							((uint8_t) 0x00)    // DEFAULT
    #define LADC_INSEL_LPGA2_LCH_SELCM_CM_BIASED							((uint8_t) 0x40)

    /* LCH_SEL3X field */
    #define LADC_INSEL_LPGA2_LCH_SEL3X_MASK									((uint8_t) 0x30)
    #define LADC_INSEL_LPGA2_LCH_SEL3X_0dB									((uint8_t) 0x00)
    #define LADC_INSEL_LPGA2_LCH_SEL3X_6dB									((uint8_t) 0x10)    // DEFAULT
    #define LADC_INSEL_LPGA2_LCH_SEL3X_NO_CONNECT							((uint8_t) 0x20)
    #define LADC_INSEL_LPGA2_LCH_SEL3X_NO_CONNECT							((uint8_t) 0x30)

    /* LCH_SEL2X field */
    #define LADC_INSEL_LPGA2_LCH_SEL2X_MASK									((uint8_t) 0x0C)
    #define LADC_INSEL_LPGA2_LCH_SEL2X_0dB									((uint8_t) 0x00)
    #define LADC_INSEL_LPGA2_LCH_SEL2X_6dB									((uint8_t) 0x04)    // DEFAULT
    #define LADC_INSEL_LPGA2_LCH_SEL2X_NO_CONNECT							((uint8_t) 0x08)
    #define LADC_INSEL_LPGA2_LCH_SEL2X_NO_CONNECT							((uint8_t) 0x0C)



/* Register 0x37 (RADC_INSEL_RPGA1) definition
 * |---------------------------------------------------------------------------------------------------------------|
 * |    Bit 7    |    Bit 6    |    Bit 5    |    Bit 4    |    Bit 3    |    Bit 2    |    Bit 1    |    Bit 0    |
 * |---------------------------------------------------------------------------------------------------------------|
 * |       RCH_SEL4[1:0]       |       RCH_SEL3[1:0]       |       RCH_SEL2[1:0]       |       RESERVED[1:0]       |
 * |---------------------------------------------------------------------------------------------------------------|
 */

    /* RADC_INSEL_RPGA1 register */
    #define RADC_INSEL_RPGA1_ADDRESS										((uint8_t) 0x37)
    #define RADC_INSEL_RPGA1_DEFAULT										((uint8_t) 0x55)

    /* RCH_SEL4 field */
    #define RADC_INSEL_RPGA1_RCH_SEL4_MASK									((uint8_t) 0xC0)
    #define RADC_INSEL_RPGA1_RCH_SEL4_0dB									((uint8_t) 0x00)
    #define RADC_INSEL_RPGA1_RCH_SEL4_6dB									((uint8_t) 0x40)    // DEFAULT
    #define RADC_INSEL_RPGA1_RCH_SEL4_NO_CONNECT							((uint8_t) 0x80)
    #define RADC_INSEL_RPGA1_RCH_SEL4_NO_CONNECT							((uint8_t) 0xC0)

    /* RCH_SEL3 field */
    #define RADC_INSEL_RPGA1_RCH_SEL3_MASK									((uint8_t) 0x30)
    #define RADC_INSEL_RPGA1_RCH_SEL3_0dB									((uint8_t) 0x00)
    #define RADC_INSEL_RPGA1_RCH_SEL3_6dB									((uint8_t) 0x10)    // DEFAULT
    #define RADC_INSEL_RPGA1_RCH_SEL3_NO_CONNECT							((uint8_t) 0x20)
    #define RADC_INSEL_RPGA1_RCH_SEL3_NO_CONNECT							((uint8_t) 0x30)

    /* RCH_SEL2 field */
    #define RADC_INSEL_RPGA1_RCH_SEL2_MASK									((uint8_t) 0x0C)
    #define RADC_INSEL_RPGA1_RCH_SEL2_0dB									((uint8_t) 0x00)
    #define RADC_INSEL_RPGA1_RCH_SEL2_6dB									((uint8_t) 0x04)    // DEFAULT
    #define RADC_INSEL_RPGA1_RCH_SEL2_NO_CONNECT							((uint8_t) 0x08)
    #define RADC_INSEL_RPGA1_RCH_SEL2_NO_CONNECT							((uint8_t) 0x0C)



/* Register 0x39 (RADC_INSEL_RPGA2) definition
 * |---------------------------------------------------------------------------------------------------------------|
 * |    Bit 7    |    Bit 6    |    Bit 5    |    Bit 4    |    Bit 3    |    Bit 2    |    Bit 1    |    Bit 0    |
 * |---------------------------------------------------------------------------------------------------------------|
 * | RPGA_BYPASS |  RCH_SELCM  |       RCH_SEL3X[1:0]      |       RCH_SEL2X[1:0]      |       RESERVED[1:0]       |
 * |---------------------------------------------------------------------------------------------------------------|
 */

    /* RADC_INSEL_RPGA2 register */
    #define RADC_INSEL_RPGA2_ADDRESS										((uint8_t) 0x39)
    #define RADC_INSEL_RPGA2_DEFAULT										((uint8_t) 0x15)

    /* RPGA_BYPASS field */
    #define RADC_INSEL_RPGA2_RPGA_BYPASS_MASK								((uint8_t) 0x80)
    #define RADC_INSEL_RPGA2_RPGA_BYPASS_NO_BYPASS							((uint8_t) 0x00)    // DEFAULT
    #define RADC_INSEL_RPGA2_RPGA_BYPASS_BYPASS								((uint8_t) 0x80)

    /* RCH_SELCM field */
    #define RADC_INSEL_RPGA2_RCH_SELCM_MASK									((uint8_t) 0x40)
    #define RADC_INSEL_RPGA2_RCH_SELCM_CM_UNBIASED							((uint8_t) 0x00)    // DEFAULT
    #define RADC_INSEL_RPGA2_RCH_SELCM_CM_BIASED							((uint8_t) 0x40)

    /* RCH_SEL3X field */
    #define RADC_INSEL_RPGA2_RCH_SEL3X_MASK									((uint8_t) 0x30)
    #define RADC_INSEL_RPGA2_RCH_SEL3X_0dB									((uint8_t) 0x00)
    #define RADC_INSEL_RPGA2_RCH_SEL3X_6dB									((uint8_t) 0x10)    // DEFAULT
    #define RADC_INSEL_RPGA2_RCH_SEL3X_NO_CONNECT							((uint8_t) 0x20)
    #define RADC_INSEL_RPGA2_RCH_SEL3X_NO_CONNECT							((uint8_t) 0x30)

    /* RCH_SEL2X field */
    #define RADC_INSEL_RPGA2_RCH_SEL2X_MASK									((uint8_t) 0x0C)
    #define RADC_INSEL_RPGA2_RCH_SEL2X_0dB									((uint8_t) 0x00)
    #define RADC_INSEL_RPGA2_RCH_SEL2X_6dB									((uint8_t) 0x04)    // DEFAULT
    #define RADC_INSEL_RPGA2_RCH_SEL2X_NO_CONNECT							((uint8_t) 0x08)
    #define RADC_INSEL_RPGA2_RCH_SEL2X_NO_CONNECT							((uint8_t) 0x0C)



/* Register 0x3B (LPGA) definition
 * |---------------------------------------------------------------------------------------------------------------|
 * |    Bit 7    |    Bit 6    |    Bit 5    |    Bit 4    |    Bit 3    |    Bit 2    |    Bit 1    |    Bit 0    |
 * |---------------------------------------------------------------------------------------------------------------|
 * |     MUTE    |                                            GAIN[6:0]                                            |
 * |---------------------------------------------------------------------------------------------------------------|
 */

    /* LPGA register */
    #define LPGA_ADDRESS													((uint8_t) 0x3B)
    #define LPGA_DEFAULT													((uint8_t) 0x80)

    /* MUTE field */
    #define LPGA_MUTE_MASK													((uint8_t) 0x80)
    #define LPGA_MUTE_UNMUTE												((uint8_t) 0x00)
    #define LPGA_MUTE_MUTE													((uint8_t) 0x80)    // DEFAULT

    /* GAIN field */
    #define LPGA_GAIN_MASK													((uint8_t) 0x7F)
    #define LPGA_GAIN_0dB													((uint8_t) 0x00)    // DEFAULT
    #define LPGA_GAIN_0P5dB													((uint8_t) 0x01)
    #define LPGA_GAIN_1dB													((uint8_t) 0x02)
    #define LPGA_GAIN_1P5dB													((uint8_t) 0x03)
    #define LPGA_GAIN_2dB													((uint8_t) 0x04)
    #define LPGA_GAIN_2P5dB													((uint8_t) 0x05)
    #define LPGA_GAIN_3dB													((uint8_t) 0x06)
    #define LPGA_GAIN_3P5dB													((uint8_t) 0x07)
    #define LPGA_GAIN_4dB													((uint8_t) 0x08)
    #define LPGA_GAIN_4P5dB													((uint8_t) 0x09)
    #define LPGA_GAIN_5dB													((uint8_t) 0x0A)
    #define LPGA_GAIN_5P5dB													((uint8_t) 0x0B)
    #define LPGA_GAIN_6dB													((uint8_t) 0x0C)
    #define LPGA_GAIN_6P5dB													((uint8_t) 0x0D)
    #define LPGA_GAIN_7dB													((uint8_t) 0x0E)
    #define LPGA_GAIN_7P5dB													((uint8_t) 0x0F)
    #define LPGA_GAIN_8dB													((uint8_t) 0x10)
    #define LPGA_GAIN_8P5dB													((uint8_t) 0x11)
    #define LPGA_GAIN_9dB													((uint8_t) 0x12)
    #define LPGA_GAIN_9P5dB													((uint8_t) 0x13)
    #define LPGA_GAIN_10dB													((uint8_t) 0x14)
    #define LPGA_GAIN_10P5dB												((uint8_t) 0x15)
    #define LPGA_GAIN_11dB													((uint8_t) 0x16)
    #define LPGA_GAIN_11P5dB												((uint8_t) 0x17)
    #define LPGA_GAIN_12dB													((uint8_t) 0x18)
    #define LPGA_GAIN_12P5dB												((uint8_t) 0x19)
    #define LPGA_GAIN_13dB													((uint8_t) 0x1A)
    #define LPGA_GAIN_13P5dB												((uint8_t) 0x1B)
    #define LPGA_GAIN_14dB													((uint8_t) 0x1C)
    #define LPGA_GAIN_14P5dB												((uint8_t) 0x1D)
    #define LPGA_GAIN_15dB													((uint8_t) 0x1E)
    #define LPGA_GAIN_15P5dB												((uint8_t) 0x1F)
    #define LPGA_GAIN_16dB													((uint8_t) 0x20)
    #define LPGA_GAIN_16P5dB												((uint8_t) 0x21)
    #define LPGA_GAIN_17dB													((uint8_t) 0x22)
    #define LPGA_GAIN_17P5dB												((uint8_t) 0x23)
    #define LPGA_GAIN_18dB													((uint8_t) 0x24)
    #define LPGA_GAIN_18P5dB												((uint8_t) 0x25)
    #define LPGA_GAIN_19dB													((uint8_t) 0x26)
    #define LPGA_GAIN_19P5dB												((uint8_t) 0x27)
    #define LPGA_GAIN_20dB													((uint8_t) 0x28)
    #define LPGA_GAIN_20P5dB												((uint8_t) 0x29)
    #define LPGA_GAIN_21dB													((uint8_t) 0x2A)
    #define LPGA_GAIN_21P5dB												((uint8_t) 0x2B)
    #define LPGA_GAIN_22dB													((uint8_t) 0x2C)
    #define LPGA_GAIN_22P5dB												((uint8_t) 0x2D)
    #define LPGA_GAIN_23dB													((uint8_t) 0x2E)
    #define LPGA_GAIN_23P5dB												((uint8_t) 0x2F)
    #define LPGA_GAIN_24dB													((uint8_t) 0x30)
    #define LPGA_GAIN_24P5dB												((uint8_t) 0x31)
    #define LPGA_GAIN_25dB													((uint8_t) 0x32)
    #define LPGA_GAIN_25P5dB												((uint8_t) 0x33)
    #define LPGA_GAIN_26dB													((uint8_t) 0x34)
    #define LPGA_GAIN_26P5dB												((uint8_t) 0x35)
    #define LPGA_GAIN_27dB													((uint8_t) 0x36)
    #define LPGA_GAIN_27P5dB												((uint8_t) 0x37)
    #define LPGA_GAIN_28dB													((uint8_t) 0x38)
    #define LPGA_GAIN_28P5dB												((uint8_t) 0x39)
    #define LPGA_GAIN_29dB													((uint8_t) 0x3A)
    #define LPGA_GAIN_29P5dB												((uint8_t) 0x3B)
    #define LPGA_GAIN_30dB													((uint8_t) 0x3C)
    #define LPGA_GAIN_30P5dB												((uint8_t) 0x3D)
    #define LPGA_GAIN_31dB													((uint8_t) 0x3E)
    #define LPGA_GAIN_31P5dB												((uint8_t) 0x3F)
    #define LPGA_GAIN_32dB													((uint8_t) 0x40)
    #define LPGA_GAIN_32P5dB												((uint8_t) 0x41)
    #define LPGA_GAIN_33dB													((uint8_t) 0x42)
    #define LPGA_GAIN_33P5dB												((uint8_t) 0x43)
    #define LPGA_GAIN_34dB													((uint8_t) 0x44)
    #define LPGA_GAIN_34P5dB												((uint8_t) 0x45)
    #define LPGA_GAIN_35dB													((uint8_t) 0x46)
    #define LPGA_GAIN_35P5dB												((uint8_t) 0x47)
    #define LPGA_GAIN_36dB													((uint8_t) 0x48)
    #define LPGA_GAIN_36P5dB												((uint8_t) 0x49)
    #define LPGA_GAIN_37dB													((uint8_t) 0x4A)
    #define LPGA_GAIN_37P5dB												((uint8_t) 0x4B)
    #define LPGA_GAIN_38dB													((uint8_t) 0x4C)
    #define LPGA_GAIN_38P5dB												((uint8_t) 0x4D)
    #define LPGA_GAIN_39dB													((uint8_t) 0x4E)
    #define LPGA_GAIN_39P5dB												((uint8_t) 0x4F)
    #define LPGA_GAIN_40dB													((uint8_t) 0x50)



/* Register 0x3C (RPGA) definition
 * |---------------------------------------------------------------------------------------------------------------|
 * |    Bit 7    |    Bit 6    |    Bit 5    |    Bit 4    |    Bit 3    |    Bit 2    |    Bit 1    |    Bit 0    |
 * |---------------------------------------------------------------------------------------------------------------|
 * |     MUTE    |                                            GAIN[6:0]                                            |
 * |---------------------------------------------------------------------------------------------------------------|
 */

    /* RPGA register */
    #define RPGA_ADDRESS													((uint8_t) 0x3C)
    #define RPGA_DEFAULT													((uint8_t) 0x80)

    /* MUTE field */
    #define RPGA_MUTE_MASK													((uint8_t) 0x80)
    #define RPGA_MUTE_UNMUTE												((uint8_t) 0x00)
    #define RPGA_MUTE_MUTE													((uint8_t) 0x80)    // DEFAULT

    /* GAIN field */
    #define RPGA_GAIN_MASK													((uint8_t) 0x7F)
    #define RPGA_GAIN_0dB													((uint8_t) 0x00)    // DEFAULT
    #define RPGA_GAIN_0P5dB													((uint8_t) 0x01)
    #define RPGA_GAIN_1dB													((uint8_t) 0x02)
    #define RPGA_GAIN_1P5dB													((uint8_t) 0x03)
    #define RPGA_GAIN_2dB													((uint8_t) 0x04)
    #define RPGA_GAIN_2P5dB													((uint8_t) 0x05)
    #define RPGA_GAIN_3dB													((uint8_t) 0x06)
    #define RPGA_GAIN_3P5dB													((uint8_t) 0x07)
    #define RPGA_GAIN_4dB													((uint8_t) 0x08)
    #define RPGA_GAIN_4P5dB													((uint8_t) 0x09)
    #define RPGA_GAIN_5dB													((uint8_t) 0x0A)
    #define RPGA_GAIN_5P5dB													((uint8_t) 0x0B)
    #define RPGA_GAIN_6dB													((uint8_t) 0x0C)
    #define RPGA_GAIN_6P5dB													((uint8_t) 0x0D)
    #define RPGA_GAIN_7dB													((uint8_t) 0x0E)
    #define RPGA_GAIN_7P5dB													((uint8_t) 0x0F)
    #define RPGA_GAIN_8dB													((uint8_t) 0x10)
    #define RPGA_GAIN_8P5dB													((uint8_t) 0x11)
    #define RPGA_GAIN_9dB													((uint8_t) 0x12)
    #define RPGA_GAIN_9P5dB													((uint8_t) 0x13)
    #define RPGA_GAIN_10dB													((uint8_t) 0x14)
    #define RPGA_GAIN_10P5dB												((uint8_t) 0x15)
    #define RPGA_GAIN_11dB													((uint8_t) 0x16)
    #define RPGA_GAIN_11P5dB												((uint8_t) 0x17)
    #define RPGA_GAIN_12dB													((uint8_t) 0x18)
    #define RPGA_GAIN_12P5dB												((uint8_t) 0x19)
    #define RPGA_GAIN_13dB													((uint8_t) 0x1A)
    #define RPGA_GAIN_13P5dB												((uint8_t) 0x1B)
    #define RPGA_GAIN_14dB													((uint8_t) 0x1C)
    #define RPGA_GAIN_14P5dB												((uint8_t) 0x1D)
    #define RPGA_GAIN_15dB													((uint8_t) 0x1E)
    #define RPGA_GAIN_15P5dB												((uint8_t) 0x1F)
    #define RPGA_GAIN_16dB													((uint8_t) 0x20)
    #define RPGA_GAIN_16P5dB												((uint8_t) 0x21)
    #define RPGA_GAIN_17dB													((uint8_t) 0x22)
    #define RPGA_GAIN_17P5dB												((uint8_t) 0x23)
    #define RPGA_GAIN_18dB													((uint8_t) 0x24)
    #define RPGA_GAIN_18P5dB												((uint8_t) 0x25)
    #define RPGA_GAIN_19dB													((uint8_t) 0x26)
    #define RPGA_GAIN_19P5dB												((uint8_t) 0x27)
    #define RPGA_GAIN_20dB													((uint8_t) 0x28)
    #define RPGA_GAIN_20P5dB												((uint8_t) 0x29)
    #define RPGA_GAIN_21dB													((uint8_t) 0x2A)
    #define RPGA_GAIN_21P5dB												((uint8_t) 0x2B)
    #define RPGA_GAIN_22dB													((uint8_t) 0x2C)
    #define RPGA_GAIN_22P5dB												((uint8_t) 0x2D)
    #define RPGA_GAIN_23dB													((uint8_t) 0x2E)
    #define RPGA_GAIN_23P5dB												((uint8_t) 0x2F)
    #define RPGA_GAIN_24dB													((uint8_t) 0x30)
    #define RPGA_GAIN_24P5dB												((uint8_t) 0x31)
    #define RPGA_GAIN_25dB													((uint8_t) 0x32)
    #define RPGA_GAIN_25P5dB												((uint8_t) 0x33)
    #define RPGA_GAIN_26dB													((uint8_t) 0x34)
    #define RPGA_GAIN_26P5dB												((uint8_t) 0x35)
    #define RPGA_GAIN_27dB													((uint8_t) 0x36)
    #define RPGA_GAIN_27P5dB												((uint8_t) 0x37)
    #define RPGA_GAIN_28dB													((uint8_t) 0x38)
    #define RPGA_GAIN_28P5dB												((uint8_t) 0x39)
    #define RPGA_GAIN_29dB													((uint8_t) 0x3A)
    #define RPGA_GAIN_29P5dB												((uint8_t) 0x3B)
    #define RPGA_GAIN_30dB													((uint8_t) 0x3C)
    #define RPGA_GAIN_30P5dB												((uint8_t) 0x3D)
    #define RPGA_GAIN_31dB													((uint8_t) 0x3E)
    #define RPGA_GAIN_31P5dB												((uint8_t) 0x3F)
    #define RPGA_GAIN_32dB													((uint8_t) 0x40)
    #define RPGA_GAIN_32P5dB												((uint8_t) 0x41)
    #define RPGA_GAIN_33dB													((uint8_t) 0x42)
    #define RPGA_GAIN_33P5dB												((uint8_t) 0x43)
    #define RPGA_GAIN_34dB													((uint8_t) 0x44)
    #define RPGA_GAIN_34P5dB												((uint8_t) 0x45)
    #define RPGA_GAIN_35dB													((uint8_t) 0x46)
    #define RPGA_GAIN_35P5dB												((uint8_t) 0x47)
    #define RPGA_GAIN_36dB													((uint8_t) 0x48)
    #define RPGA_GAIN_36P5dB												((uint8_t) 0x49)
    #define RPGA_GAIN_37dB													((uint8_t) 0x4A)
    #define RPGA_GAIN_37P5dB												((uint8_t) 0x4B)
    #define RPGA_GAIN_38dB													((uint8_t) 0x4C)
    #define RPGA_GAIN_38P5dB												((uint8_t) 0x4D)
    #define RPGA_GAIN_39dB													((uint8_t) 0x4E)
    #define RPGA_GAIN_39P5dB												((uint8_t) 0x4F)
    #define RPGA_GAIN_40dB													((uint8_t) 0x50)



/* Register 0x3D (ADC_LOW_CURRENT_MODE) definition
 * |---------------------------------------------------------------------------------------------------------------|
 * |    Bit 7    |    Bit 6    |    Bit 5    |    Bit 4    |    Bit 3    |    Bit 2    |    Bit 1    |    Bit 0    |
 * |---------------------------------------------------------------------------------------------------------------|
 * |                                          RESERVED[6:0]                                          |  MODULATOR  |
 * |---------------------------------------------------------------------------------------------------------------|
 */

    /* ADC_LOW_CURRENT_MODE register */
    #define ADC_LOW_CURRENT_MODE_ADDRESS									((uint8_t) 0x3D)
    #define ADC_LOW_CURRENT_MODE_DEFAULT									((uint8_t) 0x00)

    /* MODULATOR field */
    #define ADC_LOW_CURRENT_MODE_MODULATOR_MASK								((uint8_t) 0x01)
    #define ADC_LOW_CURRENT_MODE_MODULATOR_1X								((uint8_t) 0x00)    // DEFAULT
    #define ADC_LOW_CURRENT_MODE_MODULATOR_0P5X								((uint8_t) 0x01)



/* Register 0x3E (ADC_PGA_FLAGS) definition
 * |---------------------------------------------------------------------------------------------------------------|
 * |    Bit 7    |    Bit 6    |    Bit 5    |    Bit 4    |    Bit 3    |    Bit 2    |    Bit 1    |    Bit 0    |
 * |---------------------------------------------------------------------------------------------------------------|
 * |                                   RESERVED[5:0]                                   |   LADC_PGA  |   RADC_PGA  |
 * |---------------------------------------------------------------------------------------------------------------|
 */

    /* ADC_PGA_FLAGS register */
    #define ADC_PGA_FLAGS_ADDRESS											((uint8_t) 0x3E)
    #define ADC_PGA_FLAGS_DEFAULT											((uint8_t) 0x00)

    /* LADC_PGA field */
    #define ADC_PGA_FLAGS_LADC_PGA_MASK										((uint8_t) 0x02)
    #define ADC_PGA_FLAGS_LADC_PGA_NO										((uint8_t) 0x00)    // DEFAULT
    #define ADC_PGA_FLAGS_LADC_PGA_YES										((uint8_t) 0x02)

    /* RADC_PGA field */
    #define ADC_PGA_FLAGS_RADC_PGA_MASK										((uint8_t) 0x01)
    #define ADC_PGA_FLAGS_RADC_PGA_NO										((uint8_t) 0x00)    // DEFAULT
    #define ADC_PGA_FLAGS_RADC_PGA_YES										((uint8_t) 0x01)



#endif /* TLV320ADC3100_PAGE1_H_ */
