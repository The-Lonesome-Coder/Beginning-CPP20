module zoo;

import <format>;
import <iostream>;
import <string>;

import animals;

// Constructor from a vector of animals
Zoo::Zoo(const std::vector<pAnimalPtr>& animals)
    : m_animals { animals } {};


// Add an animal to the zoo
void Zoo::addAnimal(pAnimalPtr animal)
{
    m_animals.push_back(animal);
}


// Output the animals and the sound they make
void Zoo::showAnimals() const
{
    for (const auto& animal : m_animals)
    {
        std::cout << std::format("\n{}\nIt goes {}.", animal->who(), animal->sound()) << std::endl;
    }
}


// Collect all sheep in m_animals
std::vector<Sheep*> Zoo::herd() const
{
    std::vector<Sheep*> sheeps;

    for (auto& animal : m_animals)
    {
        auto* sheep = dynamic_cast<Sheep*>(animal.get());

        if (sheep)
        {
            sheeps.push_back(sheep);
        }
    }

    return sheeps;
}


/*
import <typeinfo>;

std::vector<Sheep*> Zoo::herd() const
{
    std::vector<Sheep*> sheep;
    for (auto animal : m_animals)
    {
        if (typeid(*animal) == typeid(Sheep))
        {
            sheep.push_back(static_cast<Sheep*>(animal.get()));
        }
    }
    return sheep;
}
*/