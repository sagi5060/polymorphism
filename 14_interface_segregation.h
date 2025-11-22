#pragma once
#include <iostream>
#include <vector>
#include <queue>

namespace InterfaceSegregation {
    // ------------------------------------------------------
    // Interfaces (Abilities)
    // ------------------------------------------------------

    class IContainer {
    public:
        virtual ~IContainer() {}
        virtual void add(int value) = 0;
        virtual int remove() = 0;
        virtual bool isEmpty() const = 0;
    };

    class IIterable {
    public:
        virtual ~IIterable() {}
        virtual int size() const = 0;
        virtual int at(int index) const = 0;
    };

    class IFilterable {
    public:
        virtual ~IFilterable() {}
        virtual void filter(IFilterable& dest, bool (*pred)(int)) const = 0;
    };

    // ------------------------------------------------------
    // StackContainer (LIFO)
    // Implements: IContainer, IIterable, IFilterable
    // ------------------------------------------------------

    class StackContainer :
        public IContainer,
        public IIterable,
        public IFilterable
    {
    private:
        std::vector<int> data;

    public:
        // IContainer
        void add(int value) override;
        int remove() override;
        bool isEmpty() const override;

        // IIterable
        int size() const override;
        int at(int index) const override;

        // IFilterable
        void filter(IFilterable& dest, bool (*pred)(int)) const override;
    };

    // ------------------------------------------------------
    // QueueContainer (FIFO)
    // Implements: IContainer, IIterable, IFilterable
    // ------------------------------------------------------

    class QueueContainer :
        public IContainer,
        public IIterable,
        public IFilterable
    {
    private:
        std::queue<int> q;
        mutable std::vector<int> cache; // temporary for iteration

    public:
        // IContainer
        void add(int value) override;
        int remove() override;
        bool isEmpty() const override;

        // IIterable
        int size() const override;
        int at(int index) const override;

        // IFilterable
        void filter(IFilterable& dest, bool (*pred)(int)) const override;
    };

    // ------------------------------------------------------
    // Helper Functions
    // ------------------------------------------------------

    void printIterable(const IIterable& it);
    bool isEven(int x);

    void execute();
}