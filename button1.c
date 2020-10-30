#include <wiringPi.h>
int main (void) {
	
int button_pin = 24
int out_pin = 25	
int button_val = 0;
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
if (button_val == 0 && out_val == 1){
	digitalWrite(out_pin, 0);
	delay (5000);
  	    }

else{
	delay (500);
    }
	  
 }
return 0;
}


/*

	Запускает и выключает питание принтера при нажатии на кнопку
	На основе https://pcminipro.ru/orangepi/wiringop-wiringpi-na-orange-pi/
	Для работы, возможно, требуется WiringOP
	https://github.com/zhaolei/WiringOP.git -b h3
	Компилируем:
sudo gcc button1.c -o button -lwiringPi -lpthread
	Кладем на место
mkdir buttons
mv -f  button button1.c  buttons/
	Запускаем
sudo buttons/button
	Добавляем в автозапуск:
	В файл /etc/rc.local перед  exit0  добавляем путь к файлу
sudo nano /etc/rc.local
/home/pi/buttons/button

*/
