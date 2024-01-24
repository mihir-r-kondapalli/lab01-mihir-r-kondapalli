// Mihir Kondapalli
// Perm #: A0P2A34
// This is the only file to submit.

#include "car.hpp"
#include <cstddef>
#include <cstring>
// #include .......

Car::Car()
{
    // Initializing all pointers to NULL
    manufacturer = NULL;
    model = NULL;
    zeroToSixtyNs = 0;
    headonDragCoeff = 0;
    horsepower = 0;
    backseatDoors = None;
    seatCount = 0;
}

Car::Car(char const* const manufacturerName, char const* const modelName, PerformanceStats perf, uint8_t numSeats, 
DoorKind backseatDoorDesign)
{
    manufacturer = new char[strlen(manufacturerName)+1];
    model = new char[strlen(modelName)+1];
    strcpy(manufacturer, manufacturerName);
    strcpy(model, modelName);
    zeroToSixtyNs = perf.zeroToSixtyNs;
    headonDragCoeff = perf.headonDragCoeff;
    horsepower = perf.horsepower;
    backseatDoors = backseatDoorDesign;
    seatCount = numSeats;
}

Car::Car(Car const& o)
{
    manufacturer = new char[strlen(o.getManufacturer())+1];
    model = new char[strlen(o.getModel())+1];
    strcpy(manufacturer, o.manufacturer);
    strcpy(model, o.model);
    zeroToSixtyNs = o.getStats().zeroToSixtyNs;
    headonDragCoeff = o.getStats().headonDragCoeff;
    horsepower = o.getStats().horsepower;
    backseatDoors = o.getBackseatDoors();
    seatCount = o.getSeatCount();
}

Car::Car::~Car()
{
    delete[] manufacturer;
    delete[] model;
}

Car& Car::operator=(Car const& o)
{
    strcpy(manufacturer, o.manufacturer);
    strcpy(model, o.model);
    zeroToSixtyNs = o.getStats().zeroToSixtyNs;
    headonDragCoeff = o.getStats().headonDragCoeff;
    horsepower = o.getStats().horsepower;
    backseatDoors = o.getBackseatDoors();
    seatCount = o.getSeatCount();

    return *this;
}

char const* Car::getManufacturer() const
{
    return manufacturer;
}

char const* Car::getModel() const
{
    return model;
}

PerformanceStats Car::getStats() const
{
    PerformanceStats* ps = new PerformanceStats(horsepower, zeroToSixtyNs, headonDragCoeff);
    return *ps;
}

uint8_t Car::getSeatCount() const
{
    return seatCount;
}

DoorKind Car::getBackseatDoors() const
{
    return backseatDoors;
}

void Car::manufacturerChange(char const* const newManufacturer)
{
    char* temp = manufacturer;
    manufacturer = char[strlen(newManufacturer)+1];
    delete temp;
    strcpy(manufacturer, newManufacturer);
}

void Car::modelNameChange(char const* const newModelName)
{
    char* temp = model;
    model = char[strlen(newModelName)+1];
    delete temp;
    strcpy(model, newModelName);
}

void Car::reevaluateStats(PerformanceStats newStats)
{
    zeroToSixtyNs = newStats.zeroToSixtyNs;
    headonDragCoeff = newStats.headonDragCoeff;
    horsepower = newStats.horsepower;
}

void Car::recountSeats(uint8_t newSeatCount)
{
    seatCount = newSeatCount;
}

void Car::reexamineDoors(DoorKind newDoorKind)
{
    backseatDoors = newDoorKind;
}