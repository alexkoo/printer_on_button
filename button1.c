#include <wiringPi.h>
int main (void) {
int but = 0;
int out = 0;
  wiringPiSetup();
  pinMode (24, INPUT) ;
  pinMode (25, OUTPUT);

  for (;;) 
 {
but = digitalRead(24);
out = digitalRead(25);
if (but== 0 && out == 0){
	digitalWrite(25, 1);
	delay (5000);
  	    }

if (but == 0 && out == 1){
	digitalWrite(25, 0);
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

	Компилируем:
sudo gcc button1.c -o button -lwiringPi -lpthread

	Кладем на место
mkdir buttons
mv -f  button button1.c  buttons/

	Запускаем
sudo buttons/button

	Добавляем в автозапуск:
	В файл /etc/rc.local перед  exit0  добавляем путь к файлу
sudo mcedit /etc/rc.local
/home/pi/buttons/button

*/