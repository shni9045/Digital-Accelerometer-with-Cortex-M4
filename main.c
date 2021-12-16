#include <stdio.h>
#include <stdint.h>
#include "msp.h"
#include "spi.h"
#include "adxl345.h"



/**
 * main.c
 */
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer


	ADXL345_SPI_Init();

	ADXL345_GPIO_Init();

	ADXL345_Init();

	ADXL345_Port4_Interrupt_Enable();

	while (1){


	}
}

void PORT4_IRQHandler()
{


  if(P4->IFG & BIT4)
  {
    /* clear interrupt */
    uint32_t i;
    for(i = 0; i < 10000; i++);

    ADXL345_SPI_Read(ADXL345_INT_SOURCE);
    P4->IFG &= ~(BIT4);

    /*
     *
     * Rough Surface Detected
     *
     * */

  }


  if(P4->IFG & BIT5)
  {
    P4->IFG &= ~(BIT5);

    /*
      *
      * Bot is Free Falling
      *
      * */


  }
}







