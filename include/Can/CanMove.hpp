#pragma once

#include "ValuesAndTypes.hpp"

class CanMove{
public:
    void setAzimuth(const Azimuth azimuth);

private:
    double speed = ValuesAndTypes::none;
    Azimuth movementAzimuth = ValuesAndTypes::none;
};