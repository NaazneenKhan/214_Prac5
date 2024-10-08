OBJS	= main.o Alarm.o AlarmSensor.o Camera.o CameraSensor.o CompositeRoom.o Doors.o DoorSensor.o HomeOwner.o IncDecTemp.o Lights.o LightSensor.o LockDoors.o MarcoRoutine.o OnOffAlarm.o OnOffCameras.o OnOffLights.o Remote.o SmartDevices.o SmartThermostatIntegrator.o Thermostat.o ThermostatSensor.o
SOURCE	= main.cpp Alarm.cpp AlarmSensor.cpp Camera.cpp CameraSensor.cpp CompositeRoom.cpp Doors.cpp DoorSensor.cpp HomeOwner.cpp IncDecTemp.cpp Lights.cpp LightSensor.cpp LockDoors.cpp MarcoRoutine.cpp OnOffAlarm.cpp OnOffCameras.cpp OnOffLights.cpp Remote.cpp SmartDevices.cpp SmartThermostatIntegrator.cpp Thermostat.cpp ThermostatSensor.cpp
HEADER	= Alarm.h AlarmSensor.h Camera.h CameraSensor.h Command.h CompositeRoom.h Doors.h DoorSensor.h HomeOwner.h IncDecTemp.h Lights.h LightSensor.h LockDoors.h MarcoRoutine.h OnOffAlarm.h OnOffCameras.h OnOffLights.h Remote.h Rooms.h Sensors.h SmartDevices.h SmartRoomAdapter.h SmartThermostat.h SmartThermostatIntegrator.h Thermostat.h ThermostatSensor.h
OUT	= a.out
FLAGS	= -g3 -c -Wall -std=c++17
LFLAGS	= 
CC	= g++

# Test files
TEST_SRC = test_composite.cpp test_adapter.cpp test_command.cpp test_observer.cpp
TEST_OBJS = $(TEST_SRC:.cpp=.o)
TEST_OUT = test.out

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

HomeOwner.o: HomeOwner.cpp
	$(CC) $(FLAGS) HomeOwner.cpp 

IncDecTemp.o: IncDecTemp.cpp
	$(CC) $(FLAGS) IncDecTemp.cpp 

Lights.o: Lights.cpp
	$(CC) $(FLAGS) Lights.cpp 

LightSensor.o: LightSensor.cpp
	$(CC) $(FLAGS) LightSensor.cpp 

LockDoors.o: LockDoors.cpp
	$(CC) $(FLAGS) LockDoors.cpp 

MacroRoutine.o: MarcoRoutine.cpp
	$(CC) $(FLAGS) MarcoRoutine.cpp 

OnOffAlarm.o: OnOffAlarm.cpp
	$(CC) $(FLAGS) OnOffAlarm.cpp 

OnOffCameras.o: OnOffCameras.cpp
	$(CC) $(FLAGS) OnOffCameras.cpp 

OnOffLights.o: OnOffLights.cpp
	$(CC) $(FLAGS) OnOffLights.cpp 

Remote.o: Remote.cpp
	$(CC) $(FLAGS) Remote.cpp 

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

test: $(TEST_OBJS)
	$(CC) -g $(TEST_OBJS) $(OBJS) -o $(TEST_OUT) -lcatch2

valgrind: a.out
	valgrind ./a.out

valgrind_leakcheck: a.out
	valgrind --leak-check=full ./a.out

valgrind_extreme: a.out
	valgrind --leak-check=full --show-leak-kinds=all --leak-resolution=high --track-origins=yes --vgdb=yes ./a.out
