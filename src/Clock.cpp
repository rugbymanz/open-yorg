#include "Clock.hpp"

void Clock::tick(){
    if(needToSwitch()){
        switchTime();
    }
}

bool Clock::needToSwitch(){
#define COMPARE(timeOfDay_) timeOfDay == TimeOfDay::timeOfDay_ && getElapsedTime().asSeconds() > ValuesAndTypes::Clock::timeOfDay_##Duration

    if(COMPARE(day) || COMPARE(night)){
        
#undef COMPARE
        return true;
    }
    
    return false;
}

void Clock::switchTime(){
    timeOfDay = static_cast<TimeOfDay>( (static_cast<int>(timeOfDay) + 1) & 1);
}

Clock::TimeOfDay Clock::getTimeOfDay() const{
    return static_cast<TimeOfDay>(static_cast<int>(timeOfDay) % 2);
}