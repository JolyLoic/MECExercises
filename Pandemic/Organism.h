#pragma once

enum class OrganismTypes
{
    Human = 1 << 0,
    Pet = 1 <<1,
    Livestock = 1 << 2,
    Bird = 1 << 3,
    Insect = 1 << 4,
    Rodent = 1 << 5,
    Fish = 1 << 6
};

double randProbability(); // Return random double in [0, 1]

class Disease;

class Organism
{
public:
    Organism();
    virtual ~Organism();
    void nextStep(); // evolves the internal state of the organism for the next simulation step
        // May create new diseases through mutation
    double condition(); // 1 means fully healthy (even if we are a carrier)
    void giveMedecine(Disease *treatedDisease, double efficiency);
    void display(std::ostream &out);
    friend void meet(Organism &o1, Organism &o2); // Simulate what happens when two organisms meet: Diseases may be shared
        // and new diseases can even be created through combinason
    friend std::unique_ptr<Organism> randomOrganism();

private:
    std::map <Disease*, double> myDiseases; // the double represents the severity of the disease, in [0, 1]
};


