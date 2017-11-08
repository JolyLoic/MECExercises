#include "stdafx.h"
#include "Disease.h"


int Disease::lastIndex = 0;

double Disease::virulence()
{
    return 1.0;
}

double Disease::incubationTime()
{
    return 0.0;
}

double Disease::deathlyness()
{
    return 0.0;
}

double Disease::mutationRate()
{
    return myMutationRate;
}

OrganismTypes Disease::affectedOrganisms()
{
    return OrganismTypes();
}

Disease * Disease::mutate()
{
    return randomDisease(); // TODO: Real implementation
}

void Disease::display(std::ostream & out)
{
    out << myIndex;
}

Disease * combine(Disease const & d1, Disease const & d2)
{
    return randomDisease(); // TODO: Real implementation
}

Disease * randomDisease()
{
    auto result =  new Disease();
    result->myMutationRate = randProbability() / 50;
    return result;
}
