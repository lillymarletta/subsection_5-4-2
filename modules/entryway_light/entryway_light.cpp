//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "entryway_light.h"
#include "smart_home_system.h"
#include "light_sensor.h"

//=====[Declaration of private defines]========================================

#define LS_DARKNESS_VALUE  0.5

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

DigitalOut entryLight(LED2);

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

static bool entryLightState = OFF;

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void entryLightInit()
{
    entryLight = OFF;
}

bool entryLightStateRead()
{
    return entryLightState;
}

void entryLightStateWrite( bool state )
{
    entryLightState = state;
}

void entryLightUpdate()
{
    if( lightSensorUpdate() < LS_DARKNESS_VALUE ) {
        entryLight = ON;
    } else {
        entryLight = OFF;
    }
}