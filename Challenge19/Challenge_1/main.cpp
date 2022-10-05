// Section 19
// Challenge 1
// Formatting output
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

struct City {
    std::string name;
    long population;
    double cost;
};

// Assume each country has at least 1 city
struct Country {
    std::string name;
    std::vector<City> cities;
};

struct Tours {
    std::string title;
    std::vector<Country> countries;
};

void print_headers();
void print_rows(Tours &tour_data);

const int fw_1 {10};
const int fw_2 {15};
const int fw_3 {20};

int main()
{
    Tours tours
        { "Tour Ticket Prices from Miami",
            {
                {
                    "Colombia", { 
                        { "Bogota", 8778000, 400.98 },
                        { "Cali", 2401000, 424.12 },
                        { "Medellin", 2464000, 350.98 },
                        { "Cartagena", 972000, 345.34 } 
                    },
                },
                {
                    "Brazil", { 
                        { "Rio De Janiero", 13500000, 567.45 },
                        { "Sao Paulo", 11310000, 975.45 },
                        { "Salvador", 18234000, 855.99 }
                    },
                },
                {
                    "Chile", { 
                        { "Valdivia", 260000, 569.12 }, 
                        { "Santiago", 7040000, 520.00 }
                },
            },
                { "Argentina", { 
                    { "Buenos Aires", 3010000, 723.77 } 
                } 
            },
        }
    };

    print_headers();
    print_rows(tours);

    return 0;
}

void print_headers(){
    std::cout 
    << std::setw(fw_2) << std::left << "COUNTRY"
    << std::setw(fw_3) << std::left << "CITY"
    << std::setw(fw_2) << std::right << "POPULATION"
    << std::setw(fw_1) << std::right << "COST ($)"
    << std::endl;
    
    std::cout << "------------------------------------------------------------" << std::endl;
}

void print_rows(Tours &tour_data){
    
    bool first_row {true};
    for (auto country : tour_data.countries){
        
        std::cout << std::setw(15) << std::left << country.name;
        
        //NOTE: there is a clever way to use a conditional operator here
        //would need to refactor this as a control flow with an index value
        first_row = true;
        for (auto city : country.cities){
            if (first_row){
                first_row = false;
                std::cout 
                << std::setw(fw_3) << std::left << city.name
                << std::setw(fw_2) << std::right << std::setprecision(10) << city.population
                << std::setw(fw_1) << std::right << std::setprecision(2) << std::fixed << city.cost
                << std::endl;
            }
            else if (!first_row){
                std::cout 
                << std::setw(fw_2) << "" << std::setw(fw_3) << std::left << city.name
                << std::setw(fw_2) << std::right << std::setprecision(10) << city.population
                << std::setw(fw_1) << std::right << std::setprecision(2) << std::fixed << city.cost
                << std::endl;
            }
        }
    }
}