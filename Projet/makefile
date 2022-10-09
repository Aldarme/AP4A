CC = g++
CFLAGS = -Wall -g
TARGET1 = Sensor
TARGET2 = Scheduler
TARGET3 = Server

main: main.o $(TARGET1).o $(TARGET2).o $(TARGET3).o
	$(CC) $(CFLAGS) -o main main.o $(TARGET1).o $(TARGET2).o $(TARGET3).o

main.o: main.cpp $(TARGET1).hpp $(TARGET2).hpp $(TARGET3).hpp
	$(CC) $(CFLAGS) -c main.cpp

$(TARGET1).o: $(TARGET1).hpp

$(TARGET2).o: $(TARGET2).hpp

$(TARGET3).o: $(TARGET3).hpp