#ifndef ENEMY_GENERATOR_HPP
#define ENEMY_GENERATOR_HPP

#include <memory>

#include "enemy_a.hpp"
#include "enemy_b.hpp"

template <typename T, typename ...Ts>
void enemy_generator(std::vector<T> &vec, Ts... ts) {
    if (sizeof...(ts) > 2) { //TODO(niels): Make container for length checking
        throw std::runtime_error("To many arguments");
    }
    int args[] =  {ts...};
    int index = 0;

    for (auto item : args) {
        for (auto i = 0; i < item; ++i) {
            if (index == 0) {
                vec.emplace_back(new Enemy_a());//TODO(niels): Build container for tower types
            } else if (index == 1) {
                vec.emplace_back(new Enemy_b());
            }
        }
        index += 1;
    }
}

/*int main() {
    std::vector<std::unique_ptr<Shape>> vec;
    someFunc(vec, 20, 30, 40);

    std::cout << vec.size() << std::endl;

    for (auto&& item: vec) {
        std::cout << item->getWidth() << std::endl;                                                     
    }

    return 0;
}*/

#endif // ENEMY_GENERATOR_HPP
