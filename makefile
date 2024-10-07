OBJS	= Alarm.o Camera.o CompositeRoom.o Doors.o Lights.o main.o SmartThermostatIntegrator.o Thermostat.o HomeOwner.o Remote.o
SOURCE	= Alarm.cpp Camera.cpp CompositeRoom.cpp Doors.cpp Lights.cpp main.cpp SmartThermostatIntegrator.cpp Thermostat.cpp HomeOwner.cpp Remote.cpp
HEADER	= Alarm.h AlarmSensor.h Camera.h CameraSensor.h CompositeRoom.h Doors.h DoorSensor.h HomeOwner.h IncDecTemp.h Lights.h LightSensor.h LockDoors.h MarcoRoutine.h OnOffAlarm.h OnOffCameras.h OnOffLights.h Remote.h Rooms.h Sensors.h SmartDevices.h SmartRoomAdapter.h SmartThermostat.h SmartThermostatIntegrator.h Thermostat.h ThermostatSensor.h HomeOwner.h Remote.h
OUT	= a.out
FLAGS	= -g3 -c -Wall -std=c++20 
LFLAGS	= 
CC	= g++

all:	a.out

a.out: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

Alarm.o: Alarm.cpp
	$(CC) $(FLAGS) Alarm.cpp -lcppunit

Camera.o: Camera.cpp
	$(CC) $(FLAGS) Camera.cpp -lcppunit

CompositeRoom.o: CompositeRoom.cpp
	$(CC) $(FLAGS) CompositeRoom.cpp -lcppunit

Doors.o: Doors.cpp
	$(CC) $(FLAGS) Doors.cpp -lcppunit

Lights.o: Lights.cpp
	$(CC) $(FLAGS) Lights.cpp -lcppunit

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp -lcppunit

SmartThermostatIntegrator.o: SmartThermostatIntegrator.cpp
	$(CC) $(FLAGS) SmartThermostatIntegrator.cpp -lcppunit

Thermostat.o: Thermostat.cpp
	$(CC) $(FLAGS) Thermostat.cpp -lcppunit

HomeOwner.o: HomeOwner.cpp
	$(CC) $(FLAGS) HomeOwner.cpp -lcppunit

Remote.o: Remote.cpp
	$(CC) $(FLAGS) Remote.cpp -lcppunit

clean:
	rm -f $(OBJS) $(OUT)

run: a.out
	./a.out

valgrind: a.out
	valgrind a.out

valgrind_leakcheck: a.out
	valgrind --leak-check=full a.out

valgrind_extreme: a.out
	valgrind --leak-check=full --show-leak-kinds=all --leak-resolution=high --track-origins=yes --vgdb=yes a.out