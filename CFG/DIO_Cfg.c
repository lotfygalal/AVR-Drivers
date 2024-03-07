#include "StdTypes.h"
#include "DIO_Interface.h"

/***********************************     *** Array for LED Pins Status ***     ****************************************/
const DIO_PinStatus_type DIO_PinsStatusArray[TOTAL_PINS]={
	INPULL,      /* Port A Pin 0 ADC0*/
	INPULL,      /* Port A Pin 1 ADC1*/
	OUTPUT,      /* Port A Pin 2 ADC2*/
	OUTPUT,      /* Port A Pin 3 ADC3*/
	OUTPUT,      /* Port A Pin 4 ADC4*/
	OUTPUT,      /* Port A Pin 5 ADC5*/
	OUTPUT,      /* Port A Pin 6 ADC6*/
	OUTPUT,      /* Port A Pin 7 ADC7*/
	OUTPUT,      /* Port B Pin 0   / */		    /*keypad*/ 
	OUTPUT,      /* Port B Pin 1   /*/	   	    /*keypad*/
	OUTPUT,		 /* Port B Pin 2 / INT2*/       /*keypad*/
	OUTPUT,		 /* Port B Pin 3   /OC0*/		/*keypad*/
	OUTPUT,		 /* Port B Pin 4 /ss*/		    /*keypad*/
	OUTPUT,		 /* Port B Pin 5 //mosi*/       /*keypad*/
	OUTPUT,		 /* Port B Pin 6 /miso*/		/*keypad*/
	OUTPUT,		 /* Port B Pin 7 clk*/			/*keypad*/
	OUTPUT,		 /* Port C Pin 0 */
	OUTPUT,		 /* Port C Pin 1 */
	OUTPUT,		 /* Port C Pin 2 */
	OUTPUT,		 /* Port C Pin 3 */
	OUTPUT,		 /* Port C Pin 4 */
	OUTPUT,		 /* Port C Pin 5 */
	OUTPUT,		 /* Port C Pin 6 */
	OUTPUT,		 /* Port C Pin 7 */
	OUTPUT,		 /* Port D Pin 0 */
	OUTPUT,		 /* Port D Pin 1 */
    OUTPUT,      /* Port D Pin 2 /INT0*/
	OUTPUT,      /* Port D Pin 3 / INT1 */    
	OUTPUT,		 /* Port D Pin 4  OC1B*/ 
	OUTPUT,		 /* Port D Pin 5 OC1A*/
	OUTPUT,		 /* Port D Pin 6 /   ICP*/
	OUTPUT		 /* Port D Pin 7 */
};