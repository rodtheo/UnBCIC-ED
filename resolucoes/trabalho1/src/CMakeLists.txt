#Bring the headers into the project
include_directories(${CMAKE_SOURCE_DIR}/include)

set(LIB_SOURCES
    pilha.c
)

set(HEADERS
    ${CMAKE_SOURCE_DIR}/include/pilha.h
)

#Can manually add the sources using the set command as follows
set(SOURCES pilha.c main.c)

add_library(pilha STATIC ${LIB_SOURCES} ${HEADERS})

#The file(GLOB...) allows for wildcard additions
#file(GLOB SOURCES "*.c")

#add_executable(test ${PROJECT_SOURCE_DIR}/src/test.cpp)
add_executable(trabalho1 ${SOURCES})
target_link_libraries(pilha)
