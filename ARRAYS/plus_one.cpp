  vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
    
    // Start from the last digit and handle carry
    for (int i = n - 1; i >= 0; --i) {
        if (digits[i] < 9) {
            digits[i] += 1;  // No carry, just add 1 to the current digit
            return digits;
        }
        digits[i] = 0;  // Set current digit to 0 and carry over
    }

    // If all digits are 9, a new digit is needed (e.g., 999 + 1 = 1000)
    digits.insert(digits.begin(), 1);  // Insert 1 at the beginning of the vector
    return digits;
    }
