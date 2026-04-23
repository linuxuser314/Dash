#include "myiolib.h"

int main(void){
	initSerial9600();
	initTimer2Millis();
	initTimer0PWM();
	msgStruct tempMsg = {'\0', 0};
	while(true){
		tempMsg = readSerialMsg();
		if(tempMsg.id != '\0'){
			serialTransmitMsg(tempMsg.id, tempMsg.val);
		}
	}
}