#include "10_stack_interface.h"

namespace StackInterface {
    void SimpleStack::push(int value) {
        data.push_back(value);
        std::cout << "Pushed " << value << "\n";
    }
    
    int SimpleStack::pop() {
        if (empty()) return -1;
        int value = data.back();
        data.pop_back();
        std::cout << "Popped " << value << "\n";
        return value;
    }
    
    bool SimpleStack::empty() {
        return data.empty();
    }

    void execute() {
        std::cout << "\n=== 10: STACK INTERFACE ===\n";
        std::cout << "Polymorphic Stack Implementation:\n";
        
        IStack* stack = new SimpleStack();
        
        stack->push(10);
        stack->push(20);
        stack->push(30);
        
        std::cout << "\nPopping elements:\n";
        stack->pop();
        stack->pop();
        
        std::cout << "Empty: " << (stack->empty() ? "Yes" : "No") << "\n";
        
        delete stack;
        
        std::cout << "\n• Interface defines contract for implementations\n";
        std::cout << "• Pure virtual functions must be implemented\n";
    }
}