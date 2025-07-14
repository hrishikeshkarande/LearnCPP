#include <iostream> // For std::cout

int main() {
    char s1[] = "Apples and "; // C-style string, automatically null-terminated
    char s2[] = "oranges";     // C-style string, automatically null-terminated

    // --- Step 1: Manually calculate the length of s1 ---
    size_t len1 = 0; // Use size_t for lengths, as it's unsigned and typically large enough
    while (s1[len1] != '\0') { // Loop until the null terminator is found
        len1++;
    }

    // --- Step 2: Manually calculate the length of s2 ---
    size_t len2 = 0;
    while (s2[len2] != '\0') { // Loop until the null terminator is found
        len2++;
    }

    // --- Step 3: Determine the required size for the new string 's' ---
    // The new string needs space for all characters from s1, all characters from s2,
    // plus one extra space for the final null terminator ('\0').
    size_t total_length = len1 + len2;
    char s[total_length + 1]; // Declare the character array to hold the concatenated string

    // --- Step 4: Manually copy characters from s1 to the beginning of s ---
    for (size_t i = 0; i < len1; ++i) {
        s[i] = s1[i];
    }

    // --- Step 5: Manually copy characters from s2 to 's',
    //             starting immediately after where s1's content ended ---
    // The characters from s2 start at index 'len1' in the 's' array.
    for (size_t i = 0; i < len2; ++i) {
        s[len1 + i] = s2[i];
    }

    // --- Step 6: Add the null terminator at the very end of the concatenated string ---
    s[total_length] = '\0'; // This marks the end of the C-style string

    // --- Print the concatenated string ---
    std::cout << "Concatenated string: " << s << '\n';

    return 0; // Indicate successful program execution
}