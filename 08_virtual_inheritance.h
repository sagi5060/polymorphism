#pragma once
#include <iostream>

namespace VirtualInheritance {
    class Animal {
    public:
        Animal();
        virtual void eat();
        virtual ~Animal() = default;
    };

    // Virtual inheritance prevents duplicate Animal objects
    class Horse : virtual public Animal {
    public:
        Horse();
        void gallop();
    };

    class Donkey : virtual public Animal {
    public:
        Donkey();
        void bray();
    };

    // Mule inherits from both Horse and Donkey
    class Mule : public Horse, public Donkey {
    public:
        Mule();
        void showAbilities();
    };

    void execute();
}