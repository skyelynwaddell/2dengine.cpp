#pragma once

#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <iomanip>

class Utils {
public:
    // Check if a value is empty
    template <typename T>
    static bool isEmpty(const T& value) {
        return value.empty();
    }

    // Get unique elements from a vector
    template <typename T>
    static std::vector<T> getUniqueElements(const std::vector<T>& vec) {
        std::set<T> uniqueSet(vec.begin(), vec.end());
        return std::vector<T>(uniqueSet.begin(), uniqueSet.end());
    }

    // Flatten a nested vector (for simplicity, assuming a specific structure)
    template <typename T>
    static std::vector<T> flatten(const std::vector<std::vector<T>>& nested) {
        std::vector<T> flattened;
        for (const auto& subVec : nested) {
            flattened.insert(flattened.end(), subVec.begin(), subVec.end());
        }
        return flattened;
    }

    // Clamp a value between a minimum and maximum
    static int clamp_int(int value, int minValue, int maxValue) {
        return std::max(minValue, std::min(value, maxValue));
    }
    
    // Clamp a value between a minimum and maximum
    static float clamp_float(float value, float minValue, float maxValue) {
        return std::max(minValue, std::min(value, maxValue));
    }

    // Clamp a value between a minimum and maximum
    static double clamp_double(double value, double minValue, double maxValue) {
        return std::max(minValue, std::min(value, maxValue));
    }

    // Format a number as currency
    static std::string formatCurrency(double amount, const std::string& currencySymbol = "$") {
        std::ostringstream out;
        out << currencySymbol << std::fixed << std::setprecision(2) << amount;
        return out.str();
    }
};

#endif // UTILS_H