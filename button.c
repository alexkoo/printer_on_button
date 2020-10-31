#include <wiringPi.h>
int main (void) {

const char  button_off = 1; //использовать ли функцию отключения
const char  sens_on = 1; //Функция совместимости с psu control (инвертирует пин который не жалко) https://github.com/kantlivelong/OctoPrint-PSUControl/wiki/Settings#sensing 	
const char  button_pin = 24;
const char  out_pin = 25;	
const char  sens_pin = 23; 
	
char  button_val = 1;
char  out_val = 0;

  wiringPiSetup();
  pinMode (button_pin, INPUT) ;
  pinMode (out_pin, OUTPUT);
 if   (sens_on == 1){
	pinMode (sens_pin, OUTPUT);	
 }

  for (;;) 
 {
button_val = digitalRead(button_pin);
out_val = digitalRead(out_pin);

	  
if ( sens_on == 1 && out_val == 0){
	digitalWrite(sens_pin, 1);
	  	    }
if ( sens_on == 1 && out_val == 1){
	digitalWrite(sens_pin, 0);
	  	    }	 
	  
//Включение	  
if (button_val== 0 && out_val == 0){
	digitalWrite(out_pin, 1);
	delay (5000);
  	    }
// Если не нужно отключение кнопкой следующий if можно удалить
if (button_val == 0 && out_val == 1 && button_off == 1){
	digitalWrite(out_pin, 0);
	delay (5000);
  	    }

else{
	delay (500);
    }
	  
 }
return 0;
}
