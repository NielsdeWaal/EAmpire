#ifndef TYPEDEFS_HPP
#define TYPEDEFS_HPP

#include "tower.hpp"
#include <memory>

typedef std::shared_ptr<Tower> tower_ptr;
typedef std::vector<tower_ptr> tower_vector;
typedef std::vector<std::pair<int, std::shared_ptr<Enemy>>> enemy_vector;

#endif // TYPEDEFS_HPP
