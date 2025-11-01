#include <iostream>
#include <cstdint> // Required for uint8_t

/**
 * @brief Sets a specific bit to 1 in the 8-bit register.
 * @param reg The register value (uint8_t) to modify.
 * @param bit_pos The 0-indexed position of the bit to set (0-7).
 * @return The modified register value.
 */
uint8_t set_bit(uint8_t reg, int bit_pos) {
    // Cast '1' to uint8_t before shifting to ensure the operation 
    // stays within the 8-bit domain, avoiding potential integer promotion issues.
    uint8_t mask = (static_cast<uint8_t>(1) << bit_pos); 
    
    // Use Bitwise OR (|) to set the bit.
    return reg | mask;
}

/**
 * @brief Clears a specific bit to 0 in the 8-bit register.
 * @param reg The register value (uint8_t) to modify.
 * @param bit_pos The 0-indexed position of the bit to clear (0-7).
 * @return The modified register value.
 */
uint8_t clear_bit(uint8_t reg, int bit_pos) {
    uint8_t mask = (static_cast<uint8_t>(1) << bit_pos); 
    
    // Create the clear mask by inverting the set mask (~mask).
    // Use Bitwise AND (&) with the inverted mask to clear the bit.
    return reg & (~mask);
}

/**
 * @brief Toggles the state of a specific bit (0 <-> 1) in the 8-bit register.
 * @param reg The register value (uint8_t) to modify.
 * @param bit_pos The 0-indexed position of the bit to toggle (0-7).
 * @return The modified register value.
 */
uint8_t toggle_bit(uint8_t reg, int bit_pos) {
    uint8_t mask = (static_cast<uint8_t>(1) << bit_pos); 
    
    // Use Bitwise XOR (^) to flip the state of the bit.
    return reg ^ mask;
}

// Helper function to print a uint8_t in binary format (8 bits)
void print_binary(uint8_t val) {
    for (int i = 7; i >= 0; --i) {
        // Check if the i-th bit is 1.
        std::cout << ((val & (static_cast<uint8_t>(1) << i)) ? '1' : '0');
    }
    std::cout << "\n";
}

int main() {
    uint8_t reg = 0b00000000; // Start with a register value of 0

    std::cout << "--- Starting Value ---\n";
    std::cout << "Initial Reg: " << (int)reg << " ("; 
    print_binary(reg);
    std::cout << ")\n";

    // 1. SET BIT 3
    int bit_to_set = 3;
    reg = set_bit(reg, bit_to_set);
    std::cout << "\n--- Set Bit " << bit_to_set << " ---\n";
    std::cout << "New Reg:     " << (int)reg << " (";
    print_binary(reg);
    std::cout << ") (Expected: 00001000)\n";

    // 2. TOGGLE BIT 7
    int bit_to_toggle_1 = 7;
    reg = toggle_bit(reg, bit_to_toggle_1); 
    std::cout << "\n--- Toggle Bit " << bit_to_toggle_1 << " ---\n";
    std::cout << "New Reg:     " << (int)reg << " (";
    print_binary(reg);
    std::cout << ") (Expected: 10001000)\n";

    // 3. CLEAR BIT 3
    int bit_to_clear = 3;
    reg = clear_bit(reg, bit_to_clear);
    std::cout << "\n--- Clear Bit " << bit_to_clear << " ---\n";
    std::cout << "New Reg:     " << (int)reg << " (";
    print_binary(reg);
    std::cout << ") (Expected: 10000000)\n";
    
    // 4. TOGGLE BIT 7 (Toggle again to clear it)
    int bit_to_toggle_2 = 7;
    reg = toggle_bit(reg, bit_to_toggle_2);
    std::cout << "\n--- Toggle Bit " << bit_to_toggle_2 << " (Again) ---\n";
    std::cout << "New Reg:     " << (int)reg << " (";
    print_binary(reg);
    std::cout << ") (Expected: 00000000)\n";

    return 0; 
}





