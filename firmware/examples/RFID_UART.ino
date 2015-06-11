// RFID_UART.ino

#if defined (SPARK)
#include "SeeedRFID/SeeedRFID.h"
#else
#include <SoftwareSerial.h>
#include <SeeedRFID.h>
#endif

#define RFID_RX_PIN 10
#define RFID_TX_PIN 11

// #define DEBUG
#define TEST

void setup() {
	Serial.begin(57600);
	Serial.println("Hello, double bk!");
	
	SeeedRFID RFID(RFID_RX_PIN, RFID_TX_PIN); // Moved into setup from constructor, hard faults Spark Core
	RFIDdata tag;
}

void loop() { 
	if(RFID.isAvailable()){
		tag = RFID.data();
		Serial.print("RFID card number: ");
		Serial.println(RFID.cardNumber());
#ifdef TEST
	Serial.print("RFID raw data: ");
	for(int i=0; i<tag.dataLen; i++){
	    Serial.print(tag.raw[i], HEX);
	    Serial.print('\t');
		}
#endif
	}
}

