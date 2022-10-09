CC = g++
CFLAGS = -Wall -g
TARGET1 = Sensor
TARGET2 = Temperature
TARGET3 = Pressure
TARGET4 = Light
TARGET5 = Humidity
TARGET6 = Scheduler
TARGET7 = Server
TARGET8 = Packet

main: main.o $(TARGET2).o $(TARGET3).o $(TARGET4).o $(TARGET5).o $(TARGET6).o $(TARGET7).o $(TARGET8).o
	$(CC) $(CFLAGS) -o main main.o $(TARGET1).o $(TARGET2).o $(TARGET3).o $(TARGET4).o $(TARGET5).o $(TARGET6).o $(TARGET7).o $(TARGET8).o

main.o: main.cpp $(TARGET1).hpp $(TARGET2).hpp $(TARGET3).hpp $(TARGET4).hpp $(TARGET5).hpp $(TARGET6).hpp $(TARGET7).hpp $(TARGET8).hpp
	$(CC) $(CFLAGS) -c main.cpp

$(TARGET1).o: $(TARGET1).hpp

$(TARGET2).o: $(TARGET2).hpp

$(TARGET3).o: $(TARGET3).hpp

$(TARGET5).o: $(TARGET5).hpp

$(TARGET6).o: $(TARGET6).hpp

$(TARGET7).o: $(TARGET7).hpp

$(TARGET8).o: $(TARGET8).hpp