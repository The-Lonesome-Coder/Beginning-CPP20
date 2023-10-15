export module zoo;

import <memory>;
import <vector>;

import animal;
import animal.sheep;


export using pAnimalPtr = std::shared_ptr<Animal>;


export class Zoo
{
    public:
        // Constructor
        Zoo() = default;
        Zoo(const std::vector<pAnimalPtr>& newAnimals);

        // Destructor
        virtual ~Zoo() {};

        // Add animal to Zoo
        void addAnimal(pAnimalPtr animal);

        // Output animals and the sound they make
        void showAnimals() const;


    private:
        std::vector<pAnimalPtr> m_animals;
};