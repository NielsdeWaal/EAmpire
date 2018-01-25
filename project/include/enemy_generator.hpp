#ifndef ENEMY_GENERATOR_HPP
#define ENEMY_GENERATOR_HPP

#include <memory>

#include "enemy_a.hpp"
#include "enemy_b.hpp"

typedef Enemy *(*Creator)();

template <typename T>
static Enemy* make() {
    return new T{};
}

static Creator const enemy_class_array[] = {make<Enemy_a>, make<Enemy_b>};

template <typename T, typename ...Ts>
void enemy_generator(std::vector<T> &vec, Ts... ts) {
    if (sizeof...(ts) > sizeof(enemy_class_array)) { 
        throw std::runtime_error("To many arguments in enemy_generator");
    }
    int args[] =  {ts...};
    int index = 0;
    int index_counter = 0; //TODO(niels): Make generator function for this 

    for (auto item : args) {
        for (auto i = 0; i < item; ++i) {
            vec.emplace_back(std::make_pair(index_counter, (Enemy*)enemy_class_array[index]()));
            index_counter += 1;
        }
        index += 1;
    }
}

#endif // ENEMY_GENERATOR_HPP
