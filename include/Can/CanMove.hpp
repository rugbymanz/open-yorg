#pragma once

#include "ValuesAndTypes.hpp"

class CanMove{
public:
    void setAzimuth(const Azimuth azimuth);

protected:
    double speed = NONE;
    Azimuth movementAzimuth = NONE;
};