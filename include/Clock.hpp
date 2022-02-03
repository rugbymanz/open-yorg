#pragma once

#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

#include "ValuesAndTypes.hpp"

class Clock: sf::Clock{
public:
    enum class TimeOfDay{
        night,
        day
    };

    void tick();
    TimeOfDay getTimeOfDay() const;

private:
    sf::Time time = sf::seconds(ValuesAndTypes::none);
    TimeOfDay timeOfDay = TimeOfDay::day;
    
    void switchTime();
    bool needToSwitch();
};