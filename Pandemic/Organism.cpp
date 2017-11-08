#include "stdafx.h"
#include "Organism.h"
#include "Disease.h"
#include <random>

Organism::Organism()
{
}


Organism::~Organism()
{
}

void Organism::nextStep()
{
    for (auto it = myDiseases.begin() ; it != myDiseases.end() ; ++it)
    {
        auto&[disease, severity] = *it;
        severity += disease->virulence() * (0.5 - condition()); // TODO: Better formula, outside the scope of the exercise
        if (severity < 0)
        {
            myDiseases.erase(it); // There is a bug here, please correct it :)
            continue;
        }
        if (randProbability() < disease->mutationRate())
        {
            myDiseases.insert(std::make_pair(disease->mutate(), 0.2)); // Bonus question: is this code correct?
        }
    }

}

double Organism::condition()
{
    return 0.51;
}

void Organism::giveMedecine(Disease * treatedDisease, double efficiency)
{
    auto it = myDiseases.find(treatedDisease);
    if (it != myDiseases.end())
    {
        it->second -= efficiency;
        if (it->second < 0)
        {
            myDiseases.erase(it);
        }
    }
}

void Organism::display(std::ostream & out)
{
    out << "Organism" << std::endl;
    for (auto&[disease, severity] : myDiseases)
    {
        out << "\t";
        disease->display(out);
        out << " : " << severity << std::endl;
    }
}

double randProbability()
{
    static std::mt19937 gen;
    static std::uniform_real_distribution<> dis(0, 1);
    return dis(gen);
}

void meet(Organism &o1, Organism &o2)
{
    // TODO: Better algorithms, outside the scope of the exercise
    if (!o1.myDiseases.empty() && !o2.myDiseases.empty())
    {
        auto &d1 = *o1.myDiseases.begin()->first;
        auto &d2 = *o2.myDiseases.begin()->first;
        if (randProbability() < d1.mutationRate() * d2.mutationRate())
        {
            o1.myDiseases.insert(std::make_pair(combine(d1, d2), 0.2));
        }
    }
    o1.myDiseases.insert(o2.myDiseases.begin(), o2.myDiseases.end());

}

std::unique_ptr<Organism> randomOrganism()
{
    auto result = std::make_unique<Organism>();
    result->myDiseases.insert(std::make_pair(randomDisease(), 0.5));
    return result;
}
