#pragma once
#include <iostream>

namespace ObjectSlicing {
    class Animal {
    public:
        virtual void speak();
        virtual ~Animal() = default;
    };

    class Dog : public Animal {
    public:
        void speak() override;
    };

    // BAD: Pass by value causes slicing
    void feedAnimal_Bad(Animal animal);

    // GOOD: Pass by reference preserves polymorphism
    void feedAnimal_Good(Animal& animal);

    void execute();
}