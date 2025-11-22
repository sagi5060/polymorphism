#pragma once
#include <iostream>

namespace PolymorphismConcept {
    class Animal {
    public:
        virtual void speak() {
            std::cout << "Some animal sound\n";
        }
        virtual ~Animal() = default;
    };

    class Dog : public Animal {
    public:
        void speak() override {
            std::cout << "Woof!\n";
        }
    };

    class Cat : public Animal {
    public:
        void speak() override {
            std::cout << "Meow!\n";
        }
    };

    void execute();
}