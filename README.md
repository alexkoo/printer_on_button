# printer_on_button

Запускает и выключает питание принтера при нажатии на кнопку.
На основе https://pcminipro.ru/orangepi/wiringop-wiringpi-na-orange-pi/
Проверялось на OrangePI Lite / Armbian Armbian buster 20.08

Для работы требуется (скорее всего) WiringOP
https://micro-pi.ru/wiringop 

	git clone https://github.com/zhaolei/WiringOP.git -b h3
	cd WiringOP
	chmod +x ./build
	sudo ./build

Для инициализации при загрузке добавить в файл строку

	sudo mcedit /etc/rc.local
	gpio mode 25 output
	
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
