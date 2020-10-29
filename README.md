# printer_on_button

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
sudo nano /etc/rc.local
/home/pi/buttons/button
*/
