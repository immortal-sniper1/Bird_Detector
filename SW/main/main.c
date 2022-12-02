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

//I2C libs
//#include <stdio.h>
#include "esp_log.h"
#include "driver/i2c.h"
#include "sdkconfig.h"  // needed for self test for some reason


#define debug_lvl 1

#if debug_lvl
#define Error_Logger(...) printf(0 __VA_OPT__(,) __VA_ARGS__)
#endif

//-------------------------------------CONSTANTS---------------------------------------------

#define MOUNT_POINT "/sdcard"

// uSD card pins
const int8_t SD_DATAO_PIN = 6;
const int8_t SD_DATA1_PIN = 5;
const int8_t SD_DATA2_PIN = 17;
const int8_t SD_DATA3_PIN = 16;
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
//global error variables
esp_err_t Error_var;

// wifi variables
char found_nets[20][20];

//SD variables
int8_t SD_bit_mode = 4;
static const char *TAG = "example";
uint32_t SD_Speed = 20 * 1000; // in KHz 40MHz is max and only int fractions can be used 20 10 8 5 1
//bool ddr_mode = FALSE; // if enable it requires good signal integrity , maybe later

//-------------------------------------------------FUNCTIONS------------------------------------------
/*
 void
 WIFI_SCANNER (char *foundd_nets[][])
 {
 sleep (1);
 }
 */

/*
 void
 SD_MMC_CONFIG_FUNCTION_v1 (void)
 {

 sdmmc_host_init_slot (SDMMC_HOST_SLOT_1, d);

 sdmmc_host_deinit ();

 sdmmc_card_t *MY_card;
 const char mount_point[] = MOUNT_POINT;
 ESP_LOGI(TAG, "Initializing SD card");

 // Use settings defined above to initialize SD card and mount FAT filesystem.
 // Note: esp_vfs_fat_sdmmc/sdspi_mount is all-in-one convenience functions.
 // Please check its source code and implement error recovery when developing
 // production applications.

 ESP_LOGI(TAG, "Using SDMMC peripheral");

 // By default, SD card frequency is initialized to SDMMC_FREQ_DEFAULT (20MHz)
 // For setting a specific frequency, use host.max_freq_khz (range 400kHz - 40MHz for SDMMC)
 // Example: for fixed frequency of 10MHz, use host.max_freq_khz = 10000;
 sdmmc_host_t MY_SD = SDMMC_HOST_DEFAULT();
 MY_SD.max_freq_khz = SDMMC_FREQ_HIGHSPEED;
 sdmmc_slot_config_t SD_slot = SDMMC_SLOT_CONFIG_DEFAULT();
 SD_slot.width = SD_bit_mode;   // can also be 1
 SD_slot.gpio_cd = SD_DETECT_PIN;

 SD_slot.clk = SD_CLK_PIN;
 SD_slot.cmd = SD_CMD_PIN;
 SD_slot.d0 = SD_DATAO_PIN;
 SD_slot.d1 = SD_DATA1_PIN;
 SD_slot.d2 = SD_DATA2_PIN;
 SD_slot.d3 = SD_DATA3_PIN;

 ESP_LOGI(TAG, "Mounting filesystem");
 ret = esp_vfs_fat_sdmmc_mount (mount_point, &host, &slot_config,
 &mount_config, &MY_card);

 if (ret != ESP_OK)
 {
 if (ret == ESP_FAIL)
 {
 ESP_LOGE(
 TAG,
 "Failed to mount filesystem. " "If you want the card to be formatted, set the EXAMPLE_FORMAT_IF_MOUNT_FAILED menuconfig option.");
 }
 else
 {
 ESP_LOGE(
 TAG,
 "Failed to initialize the card (%s). " "Make sure SD card lines have pull-up resistors in place.",
 esp_err_to_name (ret));
 }
 return;
 }
 ESP_LOGI(TAG, "Filesystem mounted");
 // Card has been initialized, print its properties
 sdmmc_card_print_info (stdout, MY_card);
 }
 */

void
SD_MMC_CONFIG_FUNCTION_v2 (void)
{
  sdmmc_card_t *MY_CARD;
  sdmmc_slot_config_t MY_SD_SLOT;
  MY_SD_SLOT.gpio_cd = SD_DETECT_PIN;
  MY_SD_SLOT.gpio_wp = SDMMC_SLOT_NO_WP;
  MY_SD_SLOT.clk = SD_CLK_PIN;
  MY_SD_SLOT.cmd = SD_CMD_PIN;
  MY_SD_SLOT.d0 = SD_DATAO_PIN;
  MY_SD_SLOT.d1 = SD_DATA1_PIN;
  MY_SD_SLOT.d2 = SD_DATA2_PIN;
  MY_SD_SLOT.d3 = SD_DATA3_PIN;

  Error_var = sdmmc_host_init_slot (1, MY_SD_SLOT);
  Error_Logger(Error_var);
  //only integer fractions of 40MHz clock can be used. For High Speed cards, 40MHz can be used.
  //For Default Speed cards, 20MHz can be used.
  Error_var = sdmmc_host_set_card_clk (MY_SD_SLOT, SD_Speed);
  Error_Logger(Error_var);
  Error_var = sdmmc_host_set_bus_width (MY_SD_SLOT, SD_bit_mode);
  Error_Logger(Error_var);
  //sdmmc_host_set_bus_ddr_mode (MY_SD_SLOT, ddr_mode);
  Error_var = sdmmc_host_set_bus_ddr_mode (MY_SD_SLOT, FALSE);
  Error_Logger(Error_var);
  Error_var = sdmmc_card_print_info (stdout, MY_CARD);
  Error_Logger(Error_var);
  Error_var = sdmmc_host_init ();
  Error_Logger(Error_var);


  /*
  sdmmc_host_init_slot (1, MY_SD_SLOT);
  //only integer fractions of 40MHz clock can be used. For High Speed cards, 40MHz can be used.
  //For Default Speed cards, 20MHz can be used.
  sdmmc_host_set_card_clk (MY_SD_SLOT, SD_Speed);
  sdmmc_host_set_bus_width (MY_SD_SLOT, SD_bit_mode);
  //sdmmc_host_set_bus_ddr_mode (MY_SD_SLOT, ddr_mode);
  sdmmc_host_set_bus_ddr_mode (MY_SD_SLOT, FALSE);
  sdmmc_card_print_info (stdout, MY_CARD);
  sdmmc_host_init ();
  */

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
