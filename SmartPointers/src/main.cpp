/**
 * @file smart_pointers_demo.cpp
 * @brief This program demonstrates the usage and key differences between C++ smart pointers: `unique_ptr`, `shared_ptr`, and `weak_ptr`.
 *
 * Smart pointers are essential for modern C++ development as they automate memory management.
 * Instead of manually calling `new` and `delete`, smart pointers use a feature called RAII (Resource Acquisition Is Initialization)
 * to automatically free memory when a pointer goes out of scope.
 *
 * - **std::unique_ptr:** Provides exclusive ownership of a dynamically allocated object. It's a lightweight pointer that cannot be copied,
 * only moved. When a `unique_ptr` goes out of scope, the object it manages is automatically deleted.
 * - **std::shared_ptr:** Allows multiple pointers to share ownership of a single object. It uses a reference count to keep track of how
 * many `shared_ptr`s point to the object. The object is only deleted when the last `shared_ptr` is destroyed or reset, and the reference count becomes zero.
 * - **std::weak_ptr:** A non-owning observer of an object managed by a `shared_ptr`. It does not affect the reference count. This is useful for
 * breaking circular references between `shared_ptr`s, which can cause memory leaks. You must first lock a `weak_ptr` to get a `shared_ptr`
 * to access the object, which checks if the object is still alive.
 *
 * This code demonstrates these behaviors through three separate blocks, showing how each pointer type manages the lifetime of an `Entity` object.
 */
#include <iostream>
#include <memory>

class Entity
{
public:
    Entity()
    {
        std::cout << "Entity Created!" << std::endl;
    }
    ~Entity()
    {
        std::cout << "Entity Destroyed!" << std::endl;
    }
    void Print() const
    {
        std::cout << "Printing from Entity." << std::endl;
    }
};

int main()
{
    // --- Demonstrating std::unique_ptr ---
    std::cout << "--- unique_ptr Demonstration ---" << std::endl;
    {
        // unique_ptr 1: Declaration using 'new' keyword.
        // The unique_ptr now owns the Entity object allocated on the heap.
        // It's less safe and less efficient than std::make_unique.
        std::unique_ptr<Entity> my_unique_ptr1_of_type_Entity(new Entity());

        // unique_ptr 2: Declaration using std::make_unique (C++14).
        // This is the recommended way to create a unique_ptr. It's safer and more efficient.
        std::unique_ptr<Entity> my_unique_ptr2_of_type_Entity = std::make_unique<Entity>();

        std::cout << "Both unique pointers created within this scope. We will see two 'Created' messages.\n";

        // Error: A unique_ptr cannot be copied because it holds exclusive ownership.
        // The following line would result in a compile-time error.
        // std::unique_ptr<Entity> another_unique_ptr = my_unique_ptr1_of_type_Entity;

        my_unique_ptr1_of_type_Entity->Print();
        my_unique_ptr2_of_type_Entity->Print();
    } // As the scope ends, both unique_ptr objects are destroyed.
    std::cout << "Scope for unique_ptr ends. Objects will be destroyed." << std::endl;
    // Each unique_ptr automatically calls delete on its raw pointer,
    // so we will see "Entity Destroyed!" printed twice.
    std::cout << "\n";

    // --- Demonstrating std::shared_ptr ---
    std::cout << "--- shared_ptr Demonstration ---" << std::endl;
    {
        std::shared_ptr<Entity> name_ptr1_shared; // Declaration of a shared pointer without initialization. Its reference count is 0.
        std::cout << "Reference count of name_ptr1_shared after declaration: " << name_ptr1_shared.use_count() << std::endl;

        {
            // The object is created using std::make_shared.
            // The reference count is now 1.
            std::shared_ptr<Entity> name_ptr2_shared = std::make_shared<Entity>();
            std::cout << "Reference count of name_ptr2_shared after creation: " << name_ptr2_shared.use_count() << std::endl;
            
            // This copies the shared pointer, increasing the reference count to 2.
            // Both name_ptr1_shared and name_ptr2_shared now point to the same object.
            name_ptr1_shared = name_ptr2_shared;
            std::cout << "Reference count of name_ptr1_shared after assignment: " << name_ptr1_shared.use_count() << std::endl;
            std::cout << "Reference count of name_ptr2_shared after assignment: " << name_ptr2_shared.use_count() << std::endl;
        } // The inner scope ends here.
        std::cout << "Inner shared_ptr scope ends. name_ptr2_shared is destroyed, but the object is NOT." << std::endl;
        // name_ptr2_shared is destroyed, but the reference count only drops to 1 because name_ptr1_shared still exists.
        std::cout << "Reference count of name_ptr1_shared after inner scope ends: " << name_ptr1_shared.use_count() << std::endl;

    } // The outer scope ends here.
    std::cout << "Outer shared_ptr scope ends. name_ptr1_shared is destroyed." << std::endl;
    // name_ptr1_shared is destroyed. The reference count drops to 0, so the Entity object is finally deleted.
    std::cout << "\n";

    // --- Demonstrating std::weak_ptr ---
    std::cout << "--- weak_ptr Demonstration ---" << std::endl;
    {
        std::weak_ptr<Entity> name_ptr1_weak; // Declaration of a weak pointer.
        
        std::cout << "Before creating shared pointer. weak_ptr is empty.\n";

        {
            // A shared pointer is created. Its reference count is 1.
            std::shared_ptr<Entity> name_ptr3_shared = std::make_shared<Entity>();
            std::cout << "Reference count of name_ptr3_shared after creation: " << name_ptr3_shared.use_count() << std::endl;
            
            // The weak pointer is assigned from the shared pointer.
            // It observes the object but does NOT increase the reference count.
            name_ptr1_weak = name_ptr3_shared;
            std::cout << "Reference count of name_ptr3_shared after weak_ptr assignment: " << name_ptr3_shared.use_count() << std::endl;
        } // The inner scope ends here.
        
        std::cout << "Inner weak_ptr scope ends. name_ptr3_shared is destroyed." << std::endl;
        // name_ptr3_shared is destroyed, the reference count drops to 0, and the Entity object is destroyed.
        std::cout << "The weak pointer is still active but now points to a destroyed object." << std::endl;
        
        // We can check if the object is still alive using the expired() method.
        std::cout << "Is the object expired? " << std::boolalpha << name_ptr1_weak.expired() << std::endl;
    }
}
