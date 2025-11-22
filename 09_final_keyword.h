#pragma once
#include <iostream>

namespace FinalKeyword {
    class Animal {
    public:
        virtual void speak() final;
        virtual void move();
        virtual ~Animal() = default;
    };

    class Dog : public Animal {
    public:
        void move() override;
        // void speak() override; // Compilation Error
    };

    class Cat final : public Animal {
    public:
        void move() override;
    };

    // class Tiger : public Cat {}; // Compilation Error

    void execute();
}