#ifndef ENEMY_GENERATOR_HPP
#define ENEMY_GENERATOR_HPP

/**
 * @brief Function which has only been written once but can serve
 * under multiple cases.
 *
 * This function adds (paramter * enemy type) to a vector.
 * It can be called with an arbitrary amount of paramters,
 * each parameter serve's for one type of enemy.
 *
 * E.g enemy_generator(vec, 10, 20) adds 10*enemy_a and
 * 20*enemy_b to vec.
 */

#include <memory>

#include "enemy_a.hpp"
#include "enemy_b.hpp"

typedef Enemy *(*Creator)(); ///< serves to my life easier with all the braces

/**
 * @brief Template to make an abitrary type
 */
template <typename T>
static Enemy *make() {
    return new T{};
}

/**
 * @brief Array with the dataypes of all the enemies
 */
static Creator const enemy_class_array[] = {make<Enemy_a>, make<Enemy_b>};

/**
 * @brief Template function to generate enemies and add them to a vector
 *
 * First the size of the paramter pack needs to be checked to make sure
 * there aren't too many type attempts. In the loop all the enemies get
 * generated with the correct amount.
 *
 * @param[in, out] std::vector Vector where all the enemies will be placed in.
 * @param[in] int paramter pack of ints which dictates the amount and type of
 * enemies placed in the vector.
 */
template <typename T, typename... Ts>
void enemy_generator(std::vector<T> &vec, Ts... ts) {
    if (sizeof...(ts) > sizeof(enemy_class_array)) {
        throw std::runtime_error("To many arguments in enemy_generator");
    }
    int args[] = {ts...};
    int index = 0;
    int index_counter = 0; // TODO(niels): Make generator function for this

    for (auto item : args) {
        for (auto i = 0; i < item; ++i) {
            vec.emplace_back(std::make_pair(
                index_counter, (Enemy *)enemy_class_array[index]()));
            index_counter += 1;
        }
        index += 1;
    }
}

#endif // ENEMY_GENERATOR_HPP
