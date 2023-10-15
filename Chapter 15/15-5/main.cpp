import animals;
import zoo;

import <array>;
import <functional>;
import <iostream>;
import <random>;
import <string_view>;


auto createUniformPseudoRandomNumberGenerator(unsigned min, unsigned max)
{
    std::random_device seeder;
    std::default_random_engine generator { seeder() };
    std::uniform_int_distribution distribution { min, max };
    return std::bind(distribution, generator);
}


int main()
{
    const size_t num_name_options { 10 };
    using NameOptions = std::array<std::string_view, num_name_options>;

    const NameOptions dogNames {
      "Fido", "Rover"  , "Lassie" , "Lambikins",  "Poochy",
      "Spit", "Gnasher", "Samuel" , "Wellington", "Patch"
    };

    const NameOptions sheepNames {
      "Bozo",    "Killer", "Tasty", "Pete", "Chops",
      "Blackie", "Whitey", "Eric" , "Sean", "Shep"
    };

    const NameOptions cowNames {
      "Dolly", "Daisy",   "Shakey", "Amy",   "Dilly",
      "Dizzy", "Eleanor", "Zippy" , "Zappy", "Happy"
    };

    const unsigned minDogWt { 1 };     // Minimum weight of a dog in pounds
    const unsigned maxDogWt { 120 };   // Maximum weight of a dog in pounds
    const unsigned minSheepWt { 80 };  // Minimum weight of a dog in pounds
    const unsigned maxSheepWt { 150 }; // Maximum weight of a dog in pounds
    const unsigned minCowWt { 800 };   // Minimum weight of a dog in pounds
    const unsigned maxCowWt { 1500 };  // Maximum weight of a dog in pounds

    auto randomAnimalType { createUniformPseudoRandomNumberGenerator(0, 2) }; // 0, 1, or 2
    auto randomNameIndex { createUniformPseudoRandomNumberGenerator(0, num_name_options - 1) };
    auto randomDogWeight { createUniformPseudoRandomNumberGenerator(minDogWt, maxDogWt) };
    auto randomSheepWeight { createUniformPseudoRandomNumberGenerator(minSheepWt, maxSheepWt) };
    auto randomCowWeight { createUniformPseudoRandomNumberGenerator(minCowWt, maxCowWt) };

    std::vector<pAnimalPtr> animals;   // Stores smart pointers to animals
    size_t numAnimals {};             // Number of animals to be created
    std::cout << "How many animals in the zoo? ";
    std::cin >> numAnimals;

    Zoo zoo;                  // Create an empty Zoo

    // Create random animals and add them to the Zoo
    for (size_t i {}; i < numAnimals; ++i)
    {
        switch (randomAnimalType())
        {
        case 0:                // Create a sheep
            zoo.addAnimal(std::make_shared<Sheep>(sheepNames[randomNameIndex()], randomSheepWeight()));
            break;
        case 1:                // Create a dog
            zoo.addAnimal(std::make_shared<Dog>(dogNames[randomNameIndex()], randomDogWeight()));
            break;
        case 2:                // Create a cow
            zoo.addAnimal(std::make_shared<Cow>(cowNames[randomNameIndex()], randomCowWeight()));
            break;
        }
    }

    zoo.showAnimals();                             // Display the animals

    std::cout << "\nHerding and shearing all sheep..." << std::endl;
    for (auto sheep : zoo.herd())
    {
        sheep->shear();
    }

    zoo.showAnimals();       // Display the animals again
}