#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

// MQTT5 libs
//#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include "esp_system.h"
#include "nvs_flash.h"
#include "esp_event.h"
#include "esp_netif.h"
//#include "protocol_examples_common.h"  ceva eroare si scot momentan
#include "esp_log.h"
#include "mqtt_client.h"

// WIFI libs
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include "esp_wifi.h"
//#include "esp_log.h"
//#include "esp_event.h"
//#include "nvs_flash.h"

//SD MMC libs
//#include <string.h>
#include <sys/unistd.h>
#include <sys/stat.h>
#include "esp_vfs_fat.h"
#include "sdmmc_cmd.h"
#include "driver/sdmmc_host.h"

//-------------------------------------CONSTANTS---------------------------------------------

// uSD card pins
const int8_t SD_DATAO_PIN = 6;
const int8_t SD_DATAO_PIN = 5;
const int8_t SD_DATAO_PIN = 17;
const int8_t SD_DATAO_PIN = 16;
const int8_t SD_CLK_PIN = 7;
const int8_t SD_DETECT_PIN = 4;
const int8_t SD_CMD_PIN = 15;

// I2C address list
const int8_t BME280 = 0x76; // or 0x77              // HUM+TEMP+PRESS     SENSOR
const int8_t BME680 = 0x76; // or 0x77              // HUM+TEMP+PRESS+VOC SENSOR
const int8_t TLV320ADC3100 = 0x30;                  // AUDIO ADC
const int8_t TCA9554A = 0x21;
const int8_t INA3221 = 0x40;                        // CURRENT & VOLTAGE  SENSOR
const int8_t TCA9545APWR = 0x20;
const int8_t MMA8452 = 0x1C;                        // ACCELEROMETER      SENSOR
const int8_t MAX11601 = 0x64;                       // ADC

// I2C GPIO pins
const int8_t SDA_PIN = 36;
const int8_t SCL_PIN = 35;

// I2S GPIO pins
const int8_t SCK_PIN = 48;
const int8_t WS_PIN = 47;
const int8_t SD_PIN = 21;
const int8_t I2S_RESET = 38;

// SIM808 UART GPIO pins (GSM+ GNSS+BT)
const int8_t SIM808_TX = 11;
const int8_t SIM808_RX = 12;
const int8_t SIM808_DTR = 37;
const int8_t SIM808_RI = 18;
const int8_t SIM808_DCD = 8;
const int8_t SIM808_CTS = 14;
const int8_t SIM808_RTS = 13;
const int8_t SIM808_RESET = 10;
const int8_t SIM808_STAT = 9;

// MCP2561-H-SN UART GPIO pins (CAN BUS INTERFACE)
const int8_t CAN_TX = 42;
const int8_t CAN_RX = 41;
const int8_t STBY = 2;

//ENABLE pins
const int8_t heater = 40;
const int8_t charge_enable = 46;
const int8_t SIM808_ENABLE = 1;

//USB OTG pin (NO OUTPUT POWER, ONLY INPUT POWER!)
const int8_t D_pos = 14;
const int8_t D_neg = 13;

//-------------------------------------------------VARIABLES------------------------------------------

char found_nets[20][20];
int8_t SD_bit_mode = 4;

//-------------------------------------------------FUNCTIONS------------------------------------------
void
WIFI_SCANNER (char *foundd_nets[][])
{
  sleep (1);
}

void
SD_MMC_CONFIG_FUNCTION (void)
{

  sdmmc_host_init_slot (SDMMC_HOST_SLOT_1);

  sdmmc_host_deinit ();

  // By default, SD card frequency is initialized to SDMMC_FREQ_DEFAULT (20MHz)
  // For setting a specific frequency, use host.max_freq_khz (range 400kHz - 40MHz for SDMMC)
  // Example: for fixed frequency of 10MHz, use host.max_freq_khz = 10000;
  sdmmc_host_t mySD = SDMMC_HOST_DEFAULT();
  mySD.max_freq_khz = SDMMC_FREQ_HIGHSPEED;
  sdmmc_slot_config_t SD_slot = SDMMC_SLOT_CONFIG_DEFAULT();
  SD_slot.width = SD_bit_mode;   // can also be 1
  SD_slot.gpio_cd = SD_DETECT_PIN;

  SD_slot.clk = CONFIG_EXAMPLE_PIN_CLK;
  SD_slot.cmd = CONFIG_EXAMPLE_PIN_CMD;
  SD_slot.d0 = CONFIG_EXAMPLE_PIN_D0;
  SD_slot.d1 = CONFIG_EXAMPLE_PIN_D1;
  SD_slot.d2 = CONFIG_EXAMPLE_PIN_D2;
  SD_slot.d3 = CONFIG_EXAMPLE_PIN_D3;
}

//-----------------------------------------------MAIN LOOPS-------------------------------------------

void
app_main (void)
{
  while (true)
    {
      printf ("Hello from app_main!\n");
      sleep (1);
    }
}
