#include "StdTypes.h"
#include "DIO_Interface.h"

/***********************************     *** Array for LED Pins Status ***     ****************************************/
const DIO_PinStatus_type DIO_PinsStatusArray[TOTAL_PINS]={
	/***************************** Port A *********************************/
	INFREE,      /* Port A Pin 0 ADC0*/
	INFREE,      /* Port A Pin 1 ADC1*/
	INFREE,      /* Port A Pin 2 ADC2*/
	INFREE,      /* Port A Pin 3 ADC3*/
	INFREE,      /* Port A Pin 4 ADC4*/
	INFREE,      /* Port A Pin 5 ADC5*/
	INFREE,      /* Port A Pin 6 ADC6*/
	INFREE,      /* Port A Pin 7 ADC7*/
	
	/***************************** Port B *********************************/
	INFREE,      /* Port B Pin 0   / */		     
	INFREE,      /* Port B Pin 1   /*/	   	    
	INFREE,		 /* Port B Pin 2 /  INT2*/       
	OUTPUT,		 /* Port B Pin 3   /OC0*/		
	INFREE,		 /* Port B Pin 4 /  ss*/		    
	OUTPUT,		 /* Port B Pin 5 // mosi*/       
	INFREE,		 /* Port B Pin 6 /  miso*/		
	INFREE,		 /* Port B Pin 7    clk*/
	
	/***************************** Port c *********************************/
	
	INPULL,		 /* Port C Pin 0 */			/*keypad*/
	INPULL,		 /* Port C Pin 1 */			/*keypad*/
	INPULL,		 /* Port C Pin 2 */			/*keypad*/
	INPULL,		 /* Port C Pin 3 */			/*keypad*/
	OUTPUT,		 /* Port C Pin 4 */			/*keypad*/
	OUTPUT,		 /* Port C Pin 5 */			/*keypad*/
	OUTPUT,		 /* Port C Pin 6 */			/*keypad*/
	OUTPUT,		 /* Port C Pin 7 */			/*keypad*/
	
	/***************************** Port D *********************************/
	
	INFREE,		 /* Port D Pin 0 */
	INFREE,		 /* Port D Pin 1 */
    INFREE,      /* Port D Pin 2 /	INT0	*/
	INFREE,      /* Port D Pin 3 /  INT1	*/    
	INFREE,		 /* Port D Pin 4	OC1B	*/ 
	OUTPUT,		 /* Port D Pin 5	OC1A	*/
	INFREE,		 /* Port D Pin 6 /  ICP		*/
	INFREE		 /* Port D Pin 7 */
};