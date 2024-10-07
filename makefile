OBJS	= Alarm.o AlarmSensor.o Camera.o CameraSensor.o CompositeRoom.o Doors.o DoorSensor.o Lights.o LightSensor.o SmartDevices.o SmartThermostatIntegrator.o Thermostat.o ThermostatSensor.o main.o
SOURCE	= Alarm.cpp AlarmSensor.cpp Camera.cpp CameraSensor.cpp CompositeRoom.cpp Doors.cpp DoorSensor.cpp Lights.cpp LightSensor.cpp SmartDevices.cpp SmartThermostatIntegrator.cpp Thermostat.cpp ThermostatSensor.cpp main.cpp
HEADER	= Alarm.h AlarmSensor.h Camera.h CameraSensor.h CompositeRoom.h Doors.h DoorSensor.h HomeOwner.h IncDecTemp.h Lights.h LightSensor.h LockDoors.h MacroRoutine.h OnOffAlarm.h OnOffCameras.h OnOffLights.h Remote.h Rooms.h Sensors.h SmartDevices.h SmartRoomAdapter.h SmartThermostat.h SmartThermostatIntegrator.h Thermostat.h ThermostatSensor.h
OUT	= a.out
FLAGS	= -g3 -c -Wall -std=c++20
LFLAGS	= 
CC	= g++

all:	a.out

a.out: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp 

Alarm.o: Alarm.cpp
	$(CC) $(FLAGS) Alarm.cpp 

AlarmSensor.o: AlarmSensor.cpp
	$(CC) $(FLAGS) AlarmSensor.cpp 

Camera.o: Camera.cpp
	$(CC) $(FLAGS) Camera.cpp 

CameraSensor.o: CameraSensor.cpp
	$(CC) $(FLAGS) CameraSensor.cpp 

CompositeRoom.o: CompositeRoom.cpp
	$(CC) $(FLAGS) CompositeRoom.cpp 

Doors.o: Doors.cpp
	$(CC) $(FLAGS) Doors.cpp 

DoorSensor.o: DoorSensor.cpp
	$(CC) $(FLAGS) DoorSensor.cpp 

Lights.o: Lights.cpp
	$(CC) $(FLAGS) Lights.cpp 

LightSensor.o: LightSensor.cpp
	$(CC) $(FLAGS) LightSensor.cpp 

SmartDevices.o: SmartDevices.cpp
	$(CC) $(FLAGS) SmartDevices.cpp 

SmartThermostatIntegrator.o: SmartThermostatIntegrator.cpp
	$(CC) $(FLAGS) SmartThermostatIntegrator.cpp 

Thermostat.o: Thermostat.cpp
	$(CC) $(FLAGS) Thermostat.cpp 

ThermostatSensor.o: ThermostatSensor.cpp
	$(CC) $(FLAGS) ThermostatSensor.cpp 

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
