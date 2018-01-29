#ifndef TYPEDEFS_HPP
#define TYPEDEFS_HPP

#include "tower.hpp"
#include <memory>

typedef std::shared_ptr<Tower> tower_ptr;
typedef std::vector<tower_ptr> tower_vector;


#endif //TYPEDEFS_HPP
