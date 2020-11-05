# Запускает и выключает питание принтера при нажатии на кнопку.
##UPDATE 
 cd#; cd printer_on_button; git pull; gcc button.c -o button -lwiringPi -lpthread

Программа к статье https://3dtoday.ru/blogs/alexalexk/octoprint-vklyucenie-vyklyucenie-bloka-pitaniya-knopkoi

На основе https://pcminipro.ru/orangepi/wiringop-wiringpi-na-orange-pi/
Проверялось на OrangePI Lite / Armbian Armbian buster 20.08

Для работы требуется WiringOP

	git clone https://github.com/zhaolei/WiringOP.git -b h3
	cd WiringOP
	chmod +x ./build
	sudo ./build


Ставим с гитхаба:

	cd #
	git clone https://github.com/alexkoo/printer_on_button
Если папка уже имеется

	cd printer_on_button
	git pull
	
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

Добавлена функция инвертирования сигнала для работы PsuControl 
https://github.com/kantlivelong/OctoPrint-PSUControl/wiki/Settings#sensing



