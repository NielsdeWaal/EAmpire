file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(testTesting ${SRCS})

TARGET_LINK_LIBRARIES(testTesting
    libgtest
    libgmock
)

add_test(NAME testTesting
        COMMAND testTesting)
