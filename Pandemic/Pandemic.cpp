// Pandemic.cpp : Définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "Disease.h"
#include "Organism.h"
#include <iostream>
#include <random>
#include <assert.h>

using OrganismList = std::vector<std::unique_ptr<Organism>>;

Organism &randomOrganism(OrganismList &orgs)
{
    assert(!orgs.empty());
    static std::mt19937 gen;
    std::uniform_int_distribution<> dis(0, orgs.size()-1);
    return *orgs[dis(gen)].get();
}

int main()
{
    std::vector<std::unique_ptr<Organism>> orgs;
    for (int i = 0; i < 10; ++i)
    {
        orgs.push_back(randomOrganism());
    }
    for (auto &o : orgs)
    {
        o->display(std::cout);
    }
    for (int i = 0; i < 100; ++i)
    {
        std::cout << "Step " << i << std::endl;
        for (auto &o : orgs)
        {
            o->nextStep();
        }
        meet(randomOrganism(orgs), randomOrganism(orgs));
    }
    std::cout << std::endl << "#############################" << std::endl;
    for (auto &o : orgs)
    {
        o->display(std::cout);
    }
    std::cout << std::endl << "#############################" << std::endl;
    std::cout << "Total diseases " << Disease::lastIndex << std::endl;
    return 0;
}

