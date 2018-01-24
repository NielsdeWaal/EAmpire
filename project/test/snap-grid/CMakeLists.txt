file(GLOB SRCS *.cpp)

include_directories("../../include")
include_directories("../../source")
include_directories("../../")

link_directories("${CMAKE_SOURCE_DIR}")

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/../../cmake_modules" ${CMAKE_MODULE_PATH})

find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
endif()

ADD_EXECUTABLE(GridTest ${SRCS})

TARGET_LINK_LIBRARIES(GridTest
    libgtest
    libgmock
    libgrid
    ${SFML_LIBRARIES}
)

add_test(NAME GridTest
        COMMAND GridTest)
