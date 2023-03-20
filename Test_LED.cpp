
/******************** C-Programm *****************************************************
** Programmname:  Vorlage_C_mbed                                                    **
** Beschreibung:  Projektvorlage mit Tedtprogramm PushButtom in Verbindung mit mbed **
**                                                                                  **
** ________________________________________________________________________________ **
**                                                                                  **
** Autor:                             Datum:  .  .2022                              **
*************************************************************************************/
#include "mbed.h"
/**** globale Konstantendeklaration *************************************************/
/**** globale Variablendeklaration **************************************************/
/* Pinnnamen sind durch mbed vorgegeben 
DigitalOut led(LED1);		// LED1 in PinNames.h  vordeklariert  (=  PC_13)
DigitalIn  button(USER_BUTTON);	// USER_BUTTON ebenso wie LED         (=  PA_5)

BusInOut  P1( PC_0,  PC_1, PC_2,  PC_3,  PC_4,  PC_5,  PC_6,  PC_7  );	// GPIOC_L
BusInOut  P2( PC_8,  PC_9, PC_10, PC_11, PC_12, PC_13, PC_14, PC_15 );	// GPIOC_H
BusInOut  P3( PB_0,  PB_1, PB_2,  PB_3,  PB_4,  PB_5,  PB_6,  PB_7  ); 	// GPIOB_L
------------
BusInOut  P4( PA_10, PA_9, PB_9,  PB_8,  PA_15, PA_6,  PA_5,  PA_7  );	// GPIO-Mixed
BusInOut  P5( PB_7,  PB_6, PB_9,  PB_8,  PA_15, PA_6,  PA_5,  PA_7  );	// GPIO-Mixed
BusInOut  P6( PC_6,  PC_7, PB_9,  PB_8,  PB_12, PB_14, PB_13, PB_15 );	// GPIO-Mixed
*/

//BusIn  funk( PC_0,  PC_1, PC_2,  PC_3,  PC_4,  PC_5,  PC_6,  PC_7  );		// GPIOC_L

InterruptIn T0(PC_0);

Serial monitor(SERIAL_TX, SERIAL_RX); // PA_2 , PA_3  = Serial 2

Timer eins;
Timer zwei;
/**** Funktionen ********************************************************************/

void eins_start(){
	eins.start();
}

void eins_stop(){
	eins.stop();
	if(eins.read_ms()>1000){
		
	}
}

/**** Hauptprogramm *****************************************************************/
int bitzaehler = 0;

int main() {	
	while(1) {							// Endlosschleife
			T0.rise(&eins_start);
			T0.fall(&eins_stop);
  }
}													// END main
