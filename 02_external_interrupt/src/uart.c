/**
 * @file uart.c
 * @author Francisco Helder (helderhdw@gmail.com)
 * @brief Serial interface access functions.
 * @version 1.0
 * @date 2022-06-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "uart.h"

#include "bbb_regs.h"
#include "hw_types.h"

void putCh(char c){
	while(!(HWREG(UART0_LSR) & (1<<5)));
	HWREG(UART0_THR) = c;
}

char getCh(){
	while(!(HWREG(UART0_LSR) & (1<<0)));
	return HWREG(UART0_RHR);
}

int putString(char *str, unsigned int length){
	for(int i = 0; i < length; i++){
    	     putCh(str[i]);
	}
	return length;
}

int getString(char *buf, unsigned int length){
	for(int i = 0; i < length; i ++){
    		buf[i] = getCh();
   	}
	return length;
}