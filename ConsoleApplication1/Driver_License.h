#pragma once
#include "Card.h"
class Driver_License :
    public Card
{ private: 
    int LicenseNumber;
    int ExpirationDate;
    Card::printname(); 
};

