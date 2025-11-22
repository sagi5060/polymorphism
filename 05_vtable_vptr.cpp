#include "05_vtable_vptr.h"

namespace VTableAndVPtr {
    void Base::func1() { std::cout << "Base::func1\n"; }
    void Base::func2() { std::cout << "Base::func2\n"; }

    void Derived::func1() { std::cout << "Derived::func1\n"; }
    void Derived::func2() { std::cout << "Derived::func2\n"; }

    void execute() {
        std::cout << "\n=== 05: VTABLE AND VPTR ===\n";
        std::cout << "vtable demonstration:\n";
        std::cout << "Each object has hidden vptr pointing to its class vtable\n\n";
        
        Base* obj1 = new Base();
        Base* obj2 = new Derived();
        
        std::cout << "obj1 (Base): ";
        obj1->func1();  // Base vtable -> Base::func1
        
        std::cout << "obj2 (Derived): ";
        obj2->func1();  // Derived vtable -> Derived::func1
        
        std::cout << "\nRuntime looks up function address in vtable\n";
        
        delete obj1;
        delete obj2;
    }
}