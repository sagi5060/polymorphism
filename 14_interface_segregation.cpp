#include "14_interface_segregation.h"

namespace InterfaceSegregation {
    // ------------------------------------------------------
    // StackContainer Implementation
    // ------------------------------------------------------

    void StackContainer::add(int value) {
        data.push_back(value);
    }

    int StackContainer::remove() {
        int v = data.back();
        data.pop_back();
        return v;
    }

    bool StackContainer::isEmpty() const {
        return data.empty();
    }

    int StackContainer::size() const {
        return data.size();
    }

    int StackContainer::at(int index) const {
        return data[index];
    }

    void StackContainer::filter(IFilterable& dest, bool (*pred)(int)) const {
        StackContainer* stackDest = dynamic_cast<StackContainer*>(&dest);
        if (!stackDest) return;

        for (int x : data) {
            if (pred(x)) stackDest->add(x);
        }
    }

    // ------------------------------------------------------
    // QueueContainer Implementation  
    // ------------------------------------------------------

    void QueueContainer::add(int value) {
        q.push(value);
    }

    int QueueContainer::remove() {
        int v = q.front();
        q.pop();
        return v;
    }

    bool QueueContainer::isEmpty() const {
        return q.empty();
    }

    int QueueContainer::size() const {
        cache.clear();
        std::queue<int> temp = q;
        while (!temp.empty()) {
            cache.push_back(temp.front());
            temp.pop();
        }
        return cache.size();
    }

    int QueueContainer::at(int index) const {
        return cache.at(index);
    }

    void QueueContainer::filter(IFilterable& dest, bool (*pred)(int)) const {
        QueueContainer* queueDest = dynamic_cast<QueueContainer*>(&dest);
        if (!queueDest) return;

        std::queue<int> temp = q;
        while (!temp.empty()) {
            int x = temp.front();
            temp.pop();
            if (pred(x)) queueDest->add(x);
        }
    }

    // ------------------------------------------------------
    // Helper Functions Implementation
    // ------------------------------------------------------

    void printIterable(const IIterable& it) {
        for (int i = 0; i < it.size(); i++) {
            std::cout << it.at(i) << " ";
        }
        std::cout << "\n";
    }

    bool isEven(int x) { 
        return x % 2 == 0; 
    }

    // ------------------------------------------------------
    // Main Demonstration
    // ------------------------------------------------------

    void execute() {
        std::cout << "\n=== 14: INTERFACE SEGREGATION ===\n";
        std::cout << "Multiple Inheritance with Segregated Interfaces:\n";
        
        StackContainer s;
        QueueContainer q;

        std::cout << "\n--- Adding elements ---\n";
        s.add(1); s.add(2); s.add(3); s.add(4);
        q.add(1); q.add(2); q.add(3); q.add(4);

        std::cout << "Original stack: ";
        printIterable(s);

        std::cout << "Original queue: ";
        printIterable(q);

        std::cout << "\n--- Filtering even numbers ---\n";
        StackContainer filteredStack;
        QueueContainer filteredQueue;

        s.filter(filteredStack, isEven);
        q.filter(filteredQueue, isEven);

        std::cout << "Filtered stack (even): ";
        printIterable(filteredStack);

        std::cout << "Filtered queue (even): ";
        printIterable(filteredQueue);

        std::cout << "\n--- Testing polymorphic behavior ---\n";
        IContainer* containers[] = { &s, &q };
        
        for (int i = 0; i < 2; i++) {
            std::cout << "Container " << (i+1) << " is empty: " 
                      << (containers[i]->isEmpty() ? "Yes" : "No") << "\n";
        }

        std::cout << "\n--- Key Learning Points ---\n";
        std::cout << "• Interface Segregation: Small, focused interfaces\n";
        std::cout << "• Multiple Inheritance: Classes implement multiple interfaces\n";
        std::cout << "• Clients depend only on interfaces they use\n";
        std::cout << "• Dynamic casting for safe type conversion\n";
    }
}