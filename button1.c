#include <wiringPi.h>
int main (void) {

const bool button_off = 1; //использовать ли функцию отключения
condt int button_pin = 24;
const int out_pin = 25;	

int button_val = 1;
int out_val = 0;

  wiringPiSetup();
  pinMode (button_pin, INPUT) ;
  pinMode (out_pin, OUTPUT);

  for (;;) 
 {
button_val = digitalRead(button_pin);
out_val = digitalRead(out_pin);
	  
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
