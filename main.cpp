#include<iostream>

#include "SmartThermostat.h"           
#include "Thermostat.h"               
#include "SmartThermostatIntegrator.h"

void TestComponent1 (){

}

void TestComponent2 (){

    Thermostat* oldThermostat = new Thermostat();

    SmartThermostat* smartThermo = new SmartThermostatIntegrator(oldThermostat);

    std::cout << "Setting old thermostat to 25 degrees." << std::endl;
    smartThermo->setTemperature(25);  
    std::cout << "Smart Thermostat Temperature: " << smartThermo->getTemperature() << " degrees." << std::endl;

    std::cout << "Setting old thermostat to 18 degrees." << std::endl;
    smartThermo->setTemperature(18);  
    std::cout << "Smart Thermostat Temperature: " << smartThermo->getTemperature() << " degrees." << std::endl;

    delete smartThermo;
    
}

void TestComponent3(){
    
}

void TestComponent4 (){
    
}

int main(){
   
//    TestComponent1();
   TestComponent2();
//    TestComponent3();
//    TestComponent4();


    return 0;
}