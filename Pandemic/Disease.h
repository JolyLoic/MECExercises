#pragma once

#include "Organism.h"

class Disease
{
public:
    Disease() : myIndex(++lastIndex) {};
    Disease(Disease const &) = delete;
    Disease & operator = (Disease const &) = delete;
    virtual ~Disease() {};

    double virulence();
    double incubationTime();
    double deathlyness();
    double mutationRate();
    OrganismTypes affectedOrganisms(); // Returns a bitfield
    Disease * mutate(); // Create an new disease as a mutation of the current one
    void display(std::ostream &out);
    friend Disease * combine(Disease const &d1, Disease const &d2); // Associate two diseases to create a new one
    friend Disease * randomDisease();
private:
    double myMutationRate;
    int myIndex;
public:
    static int lastIndex;
};


