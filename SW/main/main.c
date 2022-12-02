#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>


// uSD card pins
const int8_t DATAO_PIN = 6;
const int8_t DATAO_PIN = 5;
const int8_t DATAO_PIN = 17;
const int8_t DATAO_PIN = 16;
const int8_t SD_CLK = 7;
const int8_t SD_DETECT = 4;
const int8_t SD_CMD = 15;


// I2C address list
const int8_t BME280 = 0x76; // or 0x77
const int8_t BME680 = 0x76; // or 0x77
const int8_t TLV320ADC3100 = 0x30;
const int8_t TCA9554A = 0x21;
const int8_t INA3221 = 0x40;
const int8_t TCA9545APWR = 0x20;
const int8_t MMA8452 = 0x??;


// I2C GPIO pins
const int8_t SDA_PIN=36;
const int8_t SCL_PIN=35;

// I2S GPIO pins
const int8_t SCK_PIN=48;
const int8_t WS_PIN=47;
const int8_t SD_PIN=21;
const int8_t I2S_RESET = 38;

// SIM808 UART GPIO pins (GSM+ GNSS+BT)

// MCP2561-H-SN UART GPIO pins (CAN BUS INTERFACE)
const int8_t CAN_TX = 42;
const int8_t CAN_RX = 41;
const int8_t STBY = 0x??;

//ENABLE pins
const int8_t heater = 40;
const int8_t charge_enable = 46;
const int8_t SIM808_ENABLE = 1;



void app_main(void)
{
    while (true) {
        printf("Hello from app_main!\n");
        sleep(1);
    }
}
