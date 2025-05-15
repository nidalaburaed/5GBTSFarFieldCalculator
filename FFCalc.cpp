#include <iostream>
#include <algorithm>

int main() {
    double width_cm, length_cm, frequency_GHz;

    // Prompt user for antenna size
    std::cout << "Enter antenna width (cm): ";
    std::cin >> width_cm;
    std::cout << "Enter antenna length (cm): ";
    std::cin >> length_cm;

    // Validate antenna size range
    if (width_cm < 20 || width_cm > 100 || length_cm < 20 || length_cm > 100) {
        std::cerr << "Error: Antenna dimensions must be between 20 cm and 100 cm.\n";
        return 1;
    }

    // Prompt user for frequency
    std::cout << "Enter frequency (GHz): ";
    std::cin >> frequency_GHz;

    if (frequency_GHz <= 0) {
        std::cerr << "Error: Frequency must be a positive number.\n";
        return 1;
    }

    // Static Speed of Light value
    const double speed_of_light = 3e8; // in meters per second

    // Convert inputs
    double D_m = std::max(width_cm, length_cm) / 100.0;     // Convert to meters
    double frequency_Hz = frequency_GHz * 1e9;              // Convert GHz to Hz
    double lambda = speed_of_light / frequency_Hz;

    // Calculate Far Field distance
    double far_field_distance = (2 * D_m * D_m) / lambda;

    // Output result
    std::cout << "Far Field distance = " << far_field_distance << " meters\n";

    return 0;
}