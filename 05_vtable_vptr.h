#pragma once
#include <iostream>

namespace VTableAndVPtr {
    class Base {
    public:
        virtual void func1();
        virtual void func2();
        virtual ~Base() = default;
    };

    class Derived : public Base {
    public:
        void func1() override;
        void func2() override;
    };

    void execute();
}