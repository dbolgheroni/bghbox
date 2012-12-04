#include <iostream>
#include <string>
#include <vector>

class component {
    public:
        std::string getDescription();
        void setDescription(std::string d);
    private:
        std::string description;
        std::string manufacturer;
        int qty;
        std::string supplier;

        struct cost {
            int date;           // how to represent dates in cpp?
            float value;
        };

        std::vector<cost> history;
};

int main() {
    std::cout << "Hello, world!" << std::endl;
}
