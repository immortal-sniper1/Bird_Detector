/*
 * Pin_Assignments.h
 *
 *  Created on: Jan 30, 2023
 *      Author: robert alfred kecs
 */

#ifndef MAIN_PIN_ASSIGNMENTS_H_
#define MAIN_PIN_ASSIGNMENTS_H_


#include "driver/gpio.h"
#include <stdio.h>
#include "sdkconfig.h"

#define MOUNT_POINT "/sdcard"

// uSD card pins
static const gpio_num_t SD_DATAO_PIN = GPIO_NUM_6;
static const gpio_num_t SD_DATA1_PIN = GPIO_NUM_5;
static const gpio_num_t SD_DATA2_PIN = GPIO_NUM_17;
static const gpio_num_t SD_DATA3_PIN = GPIO_NUM_16;
static const gpio_num_t SD_CLK_PIN = GPIO_NUM_7;
static const gpio_num_t SD_DETECT_PIN = GPIO_NUM_4;
static const gpio_num_t SD_CMD_PIN = GPIO_NUM_15;

// I2C address list
static const int8_t BME280 = 0x77; // or 0x77              // HUM+TEMP+PRESS     SENSOR
static const int8_t BME680 = 0x76; // or 0x77              // HUM+TEMP+PRESS+VOC SENSOR
static const int8_t TLV320ADC3100 = 0x30;                  // AUDIO ADC
static const int8_t TCA9554A = 0x21;
static const int8_t INA3221 = 0x40;                        // CURRENT & VOLTAGE  SENSOR
static const int8_t TCA9545APWR = 0x20;
static const int8_t MMA8452 = 0x1C;                        // ACCELEROMETER      SENSOR
static const int8_t MAX11601 = 0x64;                       // ADC

// I2C GPIO pins
//static const gpio_num_t SDA_PIN = GPIO_NUM_36;
//static const gpio_num_t SCL_PIN = GPIO_NUM_35;
#define I2C_MASTER_SCL_IO 35               /*!< gpio number for I2C master clock */
#define I2C_MASTER_SDA_IO 39               /*!< gpio number for I2C master data  */
//400k is the max speed supported by ALL ICs used BUT some accept much higher speeds
#define I2C_MASTER_FREQ_HZ 400*000        /*!< I2C master clock frequency */
#define I2C_MASTER_TX_BUF_DISABLE 0                           /*!< I2C master doesn't need buffer */
#define I2C_MASTER_RX_BUF_DISABLE 0                           /*!< I2C master doesn't need buffer */
int i2c_master_port = 0;

// I2S GPIO pins
static const gpio_num_t SCK_PIN = GPIO_NUM_48;
static const gpio_num_t WS_PIN = GPIO_NUM_47;
static const gpio_num_t SD_PIN = GPIO_NUM_21;
static const gpio_num_t I2S_RESET = GPIO_NUM_38;

// SIM808 UART GPIO pins (GSM+ GNSS+BT)
static const gpio_num_t SIM808_TX = GPIO_NUM_11;
static const gpio_num_t SIM808_RX = GPIO_NUM_12;
static const gpio_num_t SIM808_DTR = GPIO_NUM_37;
static const gpio_num_t SIM808_RI = GPIO_NUM_18;
static const gpio_num_t SIM808_DCD = GPIO_NUM_8;
static const gpio_num_t SIM808_CTS = GPIO_NUM_14;
static const gpio_num_t SIM808_RTS = GPIO_NUM_13;
static const gpio_num_t SIM808_RESET = GPIO_NUM_10;
static const gpio_num_t SIM808_STAT = GPIO_NUM_9;

// MCP2561-H-SN UART GPIO pins (CAN BUS INTERFACE)
static const gpio_num_t CAN_TX = GPIO_NUM_42;
static const gpio_num_t CAN_RX = GPIO_NUM_41;
static const gpio_num_t STBY = GPIO_NUM_2;

//ENABLE pins
static const gpio_num_t heater = GPIO_NUM_40;
static const gpio_num_t charge_enable = GPIO_NUM_46;
static const gpio_num_t SIM808_ENABLE = GPIO_NUM_1;

//USB OTG pin (NO OUTPUT POWER, ONLY INPUT POWER!)
static const gpio_num_t D_pos = GPIO_NUM_14;
static const gpio_num_t D_neg = GPIO_NUM_13;










#endif /* MAIN_PIN_ASSIGNMENTS_H_ */
