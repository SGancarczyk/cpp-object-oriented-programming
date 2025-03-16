#include <iostream>
#include <unordered_map>
#include <string>


// Conversion map between m2 and other Units
std::unordered_map<std::string, double> conversionFactors = {   // This method of map creating required newer compiler version, enforced in CMakeLists.txt file
    {"mm2", 0.000001},   // 1 mm² = 0.000001 m²
    {"cm2", 0.0001},     
    {"dm2", 0.01},       
    {"m2", 1.0},         
    {"km2", 1000000.0},  
    {"a", 100.0},        
    {"ha", 10000.0},     
    {"acre", 4046.86}   
};


std::unordered_map<int, std::string> selectionTable = {
    {1, "mm2"},   
    {2, "cm2"},     
    {3, "dm2"},      
    {4, "m2"},         
    {5, "km2"},  
    {6, "a"},        
    {7, "ha"},     
    {8, "acre"}    
};

double convertArea(double value, std::string fromUnit, std::string toUnit) {
    double valueInMeters = value * conversionFactors[fromUnit];  // to m2 
    double result = valueInMeters / conversionFactors[toUnit];   // to target unit

    return result;
}


int main()
{
    int choice;
    double area;
    int previous_choice;

    previous_choice = 4;    // Default input unit - square meters
    std::cout << "Input the size of the area in square meters: "; 
    std::cin >> area;
    do{
        std::cout << "Select conversion of area units: " << std::endl;
        std::cout << "1. Millimeter" << std::endl;
        std::cout << "2. Centimeter " << std::endl;
        std::cout << "3. Decimeter" << std::endl;
        std::cout << "4. Meter" << std::endl;
        std::cout << "5. Kilometer" << std::endl;
        std::cout << "6. Ares" << std::endl;
        std::cout << "7. Acres" << std::endl;
        std::cout << "8. Hectares" << std::endl;
        std::cout << "9. Finish conversion" << std::endl;
        std::cin >> choice;
        if (choice != 9){
            std::cout << area << " " << selectionTable[previous_choice]; // displaying input unit
            area = convertArea(area, selectionTable[previous_choice], selectionTable[choice]); // converting units
            std::cout << " = " << area << " " << selectionTable[choice] << std::endl; // displaying conveted data
            previous_choice = choice;
        }
    }
    while (choice != 9);
    return 0;
}