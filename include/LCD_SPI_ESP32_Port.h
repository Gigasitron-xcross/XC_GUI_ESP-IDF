#include "driver/spi_master.h"




typedef void SPIM_CB_DONE( void );

typedef struct _tagPins_Config
{
	int mosi;
	int miso;
	int clk;
	int reset;
	int dc;
	int cs;
}PINS_CONFIG, PPINS_CONFIG;

typedef struct _tagPLCD_SPI_HANDLE
{
	uint8_t nPort;
	spi_device_handle_t pSpi;
	spi_transaction_t spi_async_trans;
	uint32_t freq;
    bool changed;
	SPIM_CB_DONE	*pfDone;
	
}LCD_SPI_HANDLE, *PLCD_SPI_HANDLE;



void  LCD_SPI_RESET_HIGH( void );
void  LCD_SPI_RESET_LOW( void );
void  LCD_SPI_DC_HIGH( void );
void  LCD_SPI_DC_LOW( void );
void  LCD_SPI_CS_HIGH( void );
void  LCD_SPI_CS_LOW( void );


void XC_LCD_SPI_Init( LCD_SPI_HANDLE *pHandle, uint8_t nPort );
void XC_LCD_SPI_ConfigurePins(LCD_SPI_HANDLE *pHandle, PINS_CONFIG *pPins);
void XC_LCD_SPI_ChangeSpeed( LCD_SPI_HANDLE *pHandle, uint32_t freq );
void XC_LCD_SPI_Transfer( LCD_SPI_HANDLE *pHandle, const uint8_t *tx, uint8_t *rx, size_t len );
void XC_LCD_SPI_AddCallbackOnComplete( LCD_SPI_HANDLE *pHandle, SPIM_CB_DONE *pfDone );
