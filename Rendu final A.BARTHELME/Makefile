
all: main
main: main.cpp Scheduler.o Serveur.o Paquet.o Sensor.o Temperature.o Humidite.o Pression.o Luminosite.o
	g++ -o main.exe main.cpp Scheduler.o Serveur.o Paquet.o Sensor.o Temperature.o Humidite.o Pression.o Luminosite.o

Scheduler.o: Scheduler.cpp Scheduler.hpp 
	g++ -c Scheduler.cpp Scheduler.hpp 

Serveur.o: Serveur.cpp Serveur.hpp
	g++ -c Serveur.cpp Serveur.hpp

Paquet.o: Paquet.cpp Paquet.hpp
	g++ -c Paquet.cpp Paquet.hpp

Sensor.o: Sensor.cpp Sensor.hpp
	g++ -c Sensor.cpp Sensor.hpp

Temperature.o: Temperature.cpp AllSensor.hpp Sensor.hpp
	g++ -c Temperature.cpp AllSensor.hpp

Humidite.o: Humidite.cpp AllSensor.hpp Sensor.hpp
	g++ -c Humidite.cpp AllSensor.hpp

Pression.o: Pression.cpp AllSensor.hpp Sensor.hpp
	g++ -c Pression.cpp AllSensor.hpp

Luminosite.o: Luminosite.cpp AllSensor.hpp Sensor.hpp
	g++ -c Luminosite.cpp AllSensor.hpp

clean:
	rm -f *.o
	rm -f *.gch
	rm -f main.exe
	rm -f main
