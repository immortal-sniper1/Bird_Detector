#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "driver/gpio.h"

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

//BME280 sensor lib
#include "lib/BME280_driver-master/bme280.h"

#define debug_lvl 1

#if debug_lvl
#define Error_Logger(...) printf(0 __VA_OPT__(,) __VA_ARGS__)
#else Error_Logger(...) //tf(0 __VA_OPT__(,) __VA_ARGS__)
#endif

//----------------------------------------------------------------------------------------------------
//----------------------------------------------CONSTANTS---------------------------------------------
//----------------------------------------------------------------------------------------------------

#define MOUNT_POINT "/sdcard"

// uSD card pins
const gpio_num_t SD_DATAO_PIN = GPIO_NUM_6;
const gpio_num_t SD_DATA1_PIN = GPIO_NUM_5;
const gpio_num_t SD_DATA2_PIN = GPIO_NUM_17;
const gpio_num_t SD_DATA3_PIN = GPIO_NUM_16;
const gpio_num_t SD_CLK_PIN = GPIO_NUM_7;
const gpio_num_t SD_DETECT_PIN = GPIO_NUM_4;
const gpio_num_t SD_CMD_PIN = GPIO_NUM_15;

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
const gpio_num_t SDA_PIN = GPIO_NUM_36;
const gpio_num_t SCL_PIN = GPIO_NUM_35;

// I2S GPIO pins
const gpio_num_t SCK_PIN = GPIO_NUM_48;
const gpio_num_t WS_PIN = GPIO_NUM_47;
const gpio_num_t SD_PIN = GPIO_NUM_21;
const gpio_num_t I2S_RESET = GPIO_NUM_38;

// SIM808 UART GPIO pins (GSM+ GNSS+BT)
const gpio_num_t SIM808_TX = GPIO_NUM_11;
const gpio_num_t SIM808_RX = GPIO_NUM_12;
const gpio_num_t SIM808_DTR = GPIO_NUM_37;
const gpio_num_t SIM808_RI = GPIO_NUM_18;
const gpio_num_t SIM808_DCD = GPIO_NUM_8;
const gpio_num_t SIM808_CTS = GPIO_NUM_14;
const gpio_num_t SIM808_RTS = GPIO_NUM_13;
const gpio_num_t SIM808_RESET = GPIO_NUM_10;
const gpio_num_t SIM808_STAT = GPIO_NUM_9;

// MCP2561-H-SN UART GPIO pins (CAN BUS INTERFACE)
const gpio_num_t CAN_TX = GPIO_NUM_42;
const gpio_num_t CAN_RX = GPIO_NUM_41;
const gpio_num_t STBY = GPIO_NUM_2;

//ENABLE pins
const gpio_num_t heater = GPIO_NUM_40;
const gpio_num_t charge_enable = GPIO_NUM_46;
const gpio_num_t SIM808_ENABLE = GPIO_NUM_1;

//USB OTG pin (NO OUTPUT POWER, ONLY INPUT POWER!)
const gpio_num_t D_pos = GPIO_NUM_14;
const gpio_num_t D_neg = GPIO_NUM_13;

//----------------------------------------------------------------------------------------------------
//-------------------------------------------------VARIABLES------------------------------------------
//----------------------------------------------------------------------------------------------------

//global error variables
esp_err_t Error_var;

// wifi variables
char found_nets[20][20];

//SD variables
int8_t SD_bit_mode = 4;
static const char *TAG = "example";
uint32_t SD_Speed = 20 * 1000; // in KHz 40MHz is max and only int fractions can be used 20 10 8 5 1
//bool ddr_mode = FALSE; // if enable it requires good signal integrity , maybe later

//----------------------------------------------------------------------------------------------------
//-------------------------------------------------FUNCTIONS------------------------------------------
//----------------------------------------------------------------------------------------------------

/*
 void
 WIFI_SCANNER (char *foundd_nets[][])
 {
 sleep (1);
 }
 */
//------------------------------------------------SD_FUNCTIONS
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

//------------------------------------------------Thermistor_FUNCTIONS
int32_t
Thermistor_Value (int8_t *channel, int8_t *iterations)
{
  // Summing filter version
int32_t R1 = 64000;
int32_t R3 = 64000;
int32_t R2;
int16_t Vcc = 3300;
int32_t sum = 0;
int8_t i;
int16_t Vo = 0;

if (iterations > 40)
{
  printf ("Dangerously high iteration count!\n");
  printf ("If truly needed use the active averaging filter!\n");
}

Vo = read (channel);
R2 = (Vo * R1) / (Vo - Vcc) * 1000 - R3;

for (i = 0; i < iterations; i++)
{
  sum = sum + R2;
  Vo = read (channel);
  R2 = (Vo * R1) / (Vo - Vcc) * 1000 - R3;

}
R2 = sum / iterations; // maybe simply bit shift by 4
return R2;

}

int32_t
Thermistor_Value_ALT (int8_t *channel, int8_t *iterations, int8_t alpha)
{
 // Averaging filter version
int32_t R1 = 64000;
int32_t R3 = 64000;
int32_t R2;
int16_t Vcc = 3300;
float sum = 0;
int8_t i;
int16_t Vo = 0;

if ((alpha >= 100) || (alpha <= 0))
{
  printf ("Incorrect ALPHA parameter!\n");
  Vo = read (channel);
  R2 = (Vo * R1) / (Vo - Vcc) * 1000 - R3;
  printf ("Calculating 1 Value and breaking function!!!!!\n");
  return R2;
  break;
}

for (i = 0; i < iterations; i++)
{
  Vo = read (channel);
  R2 = (Vo * R1) / (Vo - Vcc) * 1000 - R3;
  sum = sum + (1 - alpha / 100) + alpha * R2 / 100;
}

return R2;
}

int32_t
Resistance_At_Temperature (float *temperature, int16_t *BETA, int32_t *R25)
{
return R25 * expf (BETA * (1 / temperature - 1 / 298.15));
}

float
Temperature_At_Resistance (int32_t *Measured_Resistance, int16_t *BETA,
			   int32_t *R25)
{
return 1 / (logf (Measured_Resistance / R25) / BETA + 1 / R25);
}

float
Kelvin_to_Celsius (float *x)
{
return x - 273.15;
}
float
Celsius_to_Kelvin (float *x)
{
return x + 273.15;
}

float
Thermistor_Temperature (int8_t channel)
{
int32_t Themrmistor_resistance = 0;
float R25 = 100 * 1000;   // R at 25C
int16_t BETA = 4450;
int8_t BETA_temp = 25; // C
float tempetature = -1000;

Themrmistor_resistance = Thermistor_Value (channel);
tempetature = Temperature_At_Resistance (Themrmistor_resistance, BETA, R25);

return Kelvin_to_Celsius (tempetature);

}
//------------------------------------------------ADC_FUNCTIONS

//------------------------------------------------BME280_FUNCTIONS
struct bme280_dev MY_BME280;
int8_t rslt = BME280_OK;
uint8_t dev_addr = BME280_I2C_ADDR_PRIM;
/*
 In case of the macro "BME280_FLOAT_ENABLE" enabled,
 The outputs are in double and the units are

 - °C for temperature
 - % relative humidity
 - Pascal for pressure

 In case if "BME280_FLOAT_ENABLE" is not enabled, then it is

 - int32_t for temperature with the units 100 * °C
 - uint32_t for humidity with the units 1024 * % relative humidity
 - uint32_t for pressure
 If macro "BME280_64BIT_ENABLE" is enabled, which it is by default, the unit is 100 * Pascal
 If this macro is disabled, Then the unit is in Pascal
 */
MY_BME280.intf_ptr = &dev_addr;
MY_BME280.intf = BME280_I2C_INTF;
MY_BME280.read = user_i2c_read;
MY_BME280.write = user_i2c_write;
MY_BME280.delay_ms = user_delay_ms;

/*
 struct bme280_data
 {

 double pressure;  //< Compensated pressure //

 double temperature; //< Compensated temperature //

 double humidity; // Compensated humidity
 };
 */

//------------------------------------------------BME680_FUNCTIONS
//
//------------------------------------------------CAN_BUS_FUNCTIONS
//
//------------------------------------------------GPIO_FUNCTIONS
//
void Heater( bool *state)
{
  gpio_set_level(heater , state);  // state can be 1 or 0
}
void Disable_chargeing( bool *state)
{
  gpio_set_level(charge_enable , state);
}
void GPIO_Default_Config( void)
{
  gpio_set_direction( charge_enable, GPIO_MODE_OUTPUT);
  gpio_set_direction( heater, GPIO_MODE_OUTPUT);
  gpio_set_pull_mode( charge_enable , GPIO_PULLDOWN_ONLY);
  gpio_set_pull_mode( heater , GPIO_FLOATING);
}
//----------------------------------------------------------------------------------------------------
//-----------------------------------------------MAIN LOOPS-------------------------------------------
//----------------------------------------------------------------------------------------------------
void
app_main (void)
{
while (true)
{
  printf ("Hello from app_main!\n");

  sleep (1);
}
}
