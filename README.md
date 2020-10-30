# printer_on_button
git

Запускает и выключает питание принтера при нажатии на кнопку.
На основе https://pcminipro.ru/orangepi/wiringop-wiringpi-na-orange-pi/
Проверялось на OrangePI Lite / Armbian Armbian buster 20.08

Для работы требуется (скорее всего) WiringOP
https://micro-pi.ru/wiringop 

	git clone https://github.com/zhaolei/WiringOP.git -b h3
	cd WiringOP
	chmod +x ./build
	sudo ./build

Ставим с гитхаба:

	git clone https://github.com/alexkoo/printer_on_button
	cd printer_on_button
Правим button.c под свои нужды

	nano button.c
Компилируем

	gcc button.c -o button -lwiringPi -lpthread
Запускаем 

	sudo button

Добавляем в автозапуск:
В файл /etc/rc.local перед  exit0  добавляем путь к файлу

	sudo nano /etc/rc.local
	/home/pi/printer_on_button/button





Ручная установка
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
