#pragma once
#include <iostream>
#include <typeinfo>

namespace DynamicCast {
    class Animal {
    public:
        virtual ~Animal() {}
        virtual void makeSound();
    };

    class Dog : public Animal {
    public:
        void makeSound() override;
        void bark();
        void wagTail();
    };

    class Cat : public Animal {
    public:
        void makeSound() override;
        void meow();
        void purr();
    };

    class Bird : public Animal {
    public:
        void makeSound() override;
        void fly();
    };

    void execute();
}