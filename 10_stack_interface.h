#pragma once
#include <iostream>
#include <vector>

namespace StackInterface {
    class IStack {
    public:
        virtual void push(int value) = 0;
        virtual int pop() = 0;
        virtual bool empty() = 0;
        virtual ~IStack() = default;
    };

    class SimpleStack : public IStack {
    private:
        std::vector<int> data;
        
    public:
        void push(int value) override;
        int pop() override;
        bool empty() override;
    };

    void execute();
}