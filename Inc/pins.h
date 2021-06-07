#pragma once
#include "stm32f4xx_hal.h"

/*
   Ножки платы STM32F407G-DISC1
   
PA0   P1/12          WKUP (кнопка USER)
PA1   P1/11
PA2   P1/14          UART2_TX
PA3   P1/13          UART2_RX
PA4   P1/16          TRC_OUT_Pin (DAC)
PA5   P1/15          SPI1 SCK (74HC595, 4 шт.)
PA6   P1/18          SPI1 MISO
PA7   P1/17          SPI1 MOSI (74HC595, 4 шт.)
PA8   P2/43
PA9   P2/44, CN5/1   USB_OTG_FS_VBUS (VBUS_FS, GPIO input for VBUS sense)
PA10  P2/41, CN5/4   USB_OTG_FS_ID (input, LOW define host role)
PA11         CN5/2   OTG_FS_DM
PA12         CN5/3   OTG_FS_DP
PA13  P2/42, CN2/4   JTMS-SWDIO (SWD)
PA14  P2/39, CN2/2   JTCK-SWCLK (SWD)
PA15  P2/40

PB0   P1/22
PB1   P1/21
PB2   P1/24          BOOT1
PB3   P2/28, CN2/6   SWO
PB4   P2/25
PB5   P2/26
PB6   P2/23          SCL I2C1 для экрана
PB7   P2/24          SDA I2C1 для экрана
PB8   P2/19
PB9   P2/20
PB10  P1/34
PB11  P1/35
PB12  P1/36
PB13  P1/37          SPI2 SCK (CAN, ISM nRF24L01, 74HC595 экрана LCD, 74HC165 реле)
PB14  P1/38          SPI2 MISO (CAN, ISM nRF24L01, 74HC165 реле)
PB15  P1/39          SPI2 MOSI (CAN, ISM nRF24L01, 74HC595 экрана LCD)

PC0   P1/8           OTG_FS_PowerSwitchOn_Pin
PC1   P1/7           CP 74HC165 реле
PC2   P1/10
PC3   P1/9
PC4   P1/20
PC5   P1/19
PC6   P2/47
PC7   P2/48
PC8   P2/45          SD_DAT0
PC9   P2/46          SD_DAT1
PC10  P2/37          SD_DAT2
PC11  P2/38          SD_DAT3
PC12  P2/35          SD_CLK
PC13  P2/12
PC14  P2/9           OSC32_IN
PC15  P2/10          OSC32_OUT

PD0   P2/36
PD1   P2/33
PD2   P2/34          SD_CMD
PD3   P2/31          CE# 74HC165 реле
PD4   P2/32
PD5   P2/29
PD6   P2/30
PD7   P2/27          IRQ ISM nRF24L01
PD8   P1/40          INT CAN1 MCP2515
PD9   P1/41          INT CAN2 MCP2515
PD10  P1/42          INT CAN3 MCP2515
PD11  P1/43
PD12  P1/44          Green
PD13  P1/45          Orange
PD14  P1/46          Red
PD15  P1/47          Blue

PE0   P2/17
PE1   P2/18
PE2   P2/15          CSN ISM nRF24L01
PE3   P2/16
PE4   P2/13          CE ISM nRF24L01
PE5   P2/14          CS CAN1 MCP2515
PE6   P2/11          CS CAN2 MCP2515
PE7   P1/25          CS CAN3 MCP2515
PE8   P1/26          BUZZ1
PE9   P1/27          BUZZ2
PE10  P1/28          CE для 74HC595 экрана
PE11  P1/29          KEY_RIGHT
PE12  P1/30          KEY_LEFT
PE13  P1/31          KEY_MODE
PE14  P1/32
PE15  P1/33          NO_SD_CARD_IN_SLOT
*/

// Порт A:
#define B1_USER_Pin              GPIO_PIN_0
#define B1_USER_GPIO_Port        GPIOA
#define USART2_TX_Pin            GPIO_PIN_2
#define USART2_GPIO_Port         GPIOA
#define USART2_RX_Pin            GPIO_PIN_3
#define USART2_GPIO_Port         GPIOA
#define TRC_OUT_Pin              GPIO_PIN_4
#define TRC_OUT_GPIO_Port        GPIOA
#define SPI1_ISM_SCK_Pin         GPIO_PIN_5
#define SPI1_ISM_SCK_GPIO_Port   GPIOA
#define SPI1_ISM_MISO_Pin        GPIO_PIN_6
#define SPI1_ISM_MISO_GPIO_Port  GPIOA
#define SPI1_ISM_MOSI_Pin        GPIO_PIN_7
#define SPI1_ISM_MOSI_GPIO_Port  GPIOA
#define VBUS_FS_Pin              GPIO_PIN_9     // USB_OTG_FS_VBUS
#define VBUS_FS_GPIO_Port        GPIOA
#define OTG_FS_ID_Pin            GPIO_PIN_10    // USB_OTG_FS_ID
#define OTG_FS_ID_Port           GPIOA
#define OTG_FS_DM_Pin            GPIO_PIN_11    // USB_OTG_FS_DM
#define OTG_FS_DM_Port           GPIOA
#define OTG_FS_DP_Pin            GPIO_PIN_12    // USB_OTG_FS_DP
#define OTG_FS_DP_Port           GPIOA
#define TIM2_CH1_PWM_Pin         GPIO_PIN_15
#define TIM2_CH1_PWM_GPIO_Port   GPIOA

// Порт B:
#define BOOT1_Pin                GPIO_PIN_2
#define BOOT1_GPIO_Port          GPIOB
#define I2C1_LCD_SCL_Pin         GPIO_PIN_6
#define I2C1_LCD_SCL_GPIO_Port   GPIOB
#define I2C1_LCD_SDA_Pin         GPIO_PIN_7
#define I2C1_LCD_SDA_GPIO_Port   GPIOB
#define NRF_SCK_Pin              GPIO_PIN_13
#define NRF_SCK_Port             GPIOB
#define NRF_MISO_Pin             GPIO_PIN_14
#define NRF_MISO_Port            GPIOB
#define NRF_MOSI_Pin             GPIO_PIN_15
#define NRF_MOSI_Port            GPIOB
#define SPI2_CAN_SCK_Pin         GPIO_PIN_13
#define SPI2_CAN_SCK_GPIO_Port   GPIOB
#define SPI2_CAN_MISO_Pin        GPIO_PIN_14
#define SPI2_CAN_MISO_GPIO_Port  GPIOB
#define SPI2_CAN_MOSI_Pin        GPIO_PIN_15
#define SPI2_CAN_MOSI_GPIO_Port  GPIOB

// Порт C:
//#define SPI2_CAN_MISO_Pin        GPIO_PIN_2
//#define SPI2_CAN_MISO_GPIO_Port  GPIOC
//#define SPI2_CAN_MOSI_Pin        GPIO_PIN_3
//#define SPI2_CAN_MOSI_GPIO_Port  GPIOC
#define OTG_FS_PowerSwitchOn_Pin       GPIO_PIN_0
#define OTG_FS_PowerSwitchOn_GPIO_Port GPIOC
#define HC595_STCP_Pin                 GPIO_PIN_3
#define HC595_STCP_PORT                GPIOC
#define SD_DAT0_Pin              GPIO_PIN_8
#define SD_DAT1_Pin              GPIO_PIN_9
#define SD_DAT2_Pin              GPIO_PIN_10
#define SD_DAT3_Pin              GPIO_PIN_11
#define SD_DAT3_Pin              GPIO_PIN_11
#define SD_CLK_Pin               GPIO_PIN_12
#define SD_GPIO_AF12_DATCK_Port  GPIOC

// Порт D:
#define NRF_IRQ_Port             GPIOD
#define NRF_IRQ_Pin              GPIO_PIN_7
#define LED_G_Pin                GPIO_PIN_12    // Green
#define LED_G_Port               GPIOD
#define LED_Y_Pin                GPIO_PIN_13    // Orange
#define LED_Y_Port               GPIOD
#define LED_R_Pin                GPIO_PIN_14    // Red
#define LED_R_Port               GPIOD
#define LED_B_Pin                GPIO_PIN_15
#define LED_B_Port               GPIOD
#define SD_CMD_Pin               GPIO_PIN_2
#define SD_GPIO_AF12_CMD_Port    GPIOD

// Порт E:
#define NRF_CSN_Pin              GPIO_PIN_2
#define NRF_CSN_GPIO_Port        GPIOE
#define NRF_CE_Pin               GPIO_PIN_4
#define NRF_CE_GPIO_Port         GPIOE
#define BEEP_N_Pin               GPIO_PIN_8
#define BEEP_N_GPIO_Port         GPIOE
#define BEEP_P_Pin               GPIO_PIN_9
#define BEEP_P_GPIO_Port         GPIOE
#define BEEP_P_Pin               GPIO_PIN_9
#define BEEP_P_GPIO_Port         GPIOE
#define SDCARD_Pin               GPIO_PIN_15
#define SDCARD_GPIO_Port         GPIOE

#define GREENled(on) HAL_GPIO_WritePin(LED_G_Port,\
                                       LED_G_Pin, \
                                       on?GPIO_PIN_SET:GPIO_PIN_RESET)
#define TOGGLE_GREEN() HAL_GPIO_TogglePin(LED_G_Port, LED_G_Pin)

#define ORANGEled(on) HAL_GPIO_WritePin(LED_Y_Port,\
                                       LED_Y_Pin, \
                                       on?GPIO_PIN_SET:GPIO_PIN_RESET)
#define TOGGLE_ORANGE() HAL_GPIO_TogglePin(LED_Y_Port, LED_Y_Pin)

#define REDled(on) HAL_GPIO_WritePin(LED_R_Port,\
                                     LED_R_Pin, \
                                     on?GPIO_PIN_SET:GPIO_PIN_RESET)
#define TOGGLE_RED() HAL_GPIO_TogglePin(LED_R_Port, LED_R_Pin)

#define BLUEled(on) HAL_GPIO_WritePin(LED_B_Port,\
                                      LED_B_Pin, \
                                      on?GPIO_PIN_SET:GPIO_PIN_RESET)
#define TOGGLE_BLUE() HAL_GPIO_TogglePin(LED_B_Port, LED_B_Pin)

#define SDCARD_IN_SLOT() (GPIO_PIN_RESET==HAL_GPIO_ReadPin(SDCARD_GPIO_Port, SDCARD_Pin))

#define LED_G_ON()          HAL_GPIO_WritePin(LED_G_Port, LED_G_Pin, GPIO_PIN_SET)
#define LED_G_OFF()         HAL_GPIO_WritePin(LED_G_Port, LED_G_Pin, GPIO_PIN_RESET)
#define LED_G_TG()          HAL_GPIO_TogglePin(LED_G_Port, LED_G_Pin)
#define LED_Y_ON()          HAL_GPIO_WritePin(LED_Y_Port, LED_Y_Pin, GPIO_PIN_SET)
#define LED_Y_OFF()         HAL_GPIO_WritePin(LED_Y_Port, LED_Y_Pin, GPIO_PIN_RESET)
#define LED_Y_TG()          HAL_GPIO_TogglePin(LED_Y_Port, LED_Y_Pin)
#define LED_R_ON()          HAL_GPIO_WritePin(LED_R_Port, LED_R_Pin, GPIO_PIN_SET)
#define LED_R_OFF()         HAL_GPIO_WritePin(LED_R_Port, LED_R_Pin, GPIO_PIN_RESET)
#define LED_R_TG()          HAL_GPIO_TogglePin(LED_R_Port, LED_R_Pin)

#define LED_ALL_ON()        do { LED_G_ON(); LED_Y_ON(); LED_R_ON(); } while(0)
#define LED_ALL_OFF()       do { LED_G_OFF(); LED_Y_OFF(); LED_R_OFF(); } while(0)

#define IS_BTN_PRESSED()    ((HAL_GPIO_ReadPin(B1_USER_GPIO_Port, B1_USER_Pin) == GPIO_PIN_RESET) ? 0 : 1)

void GPIO_Init(void);
void GPIO_DeInit(void);
