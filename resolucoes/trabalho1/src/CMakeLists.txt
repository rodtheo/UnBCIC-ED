#Bring the headers into the project
include_directories(${CMAKE_SOURCE_DIR}/include)

#Can manually add the sources using the set command as follows
#set(SOURCES pilha.c main.c)

#The file(GLOB...) allows for wildcard additions
file(GLOB SOURCES "*.c")

#add_executable(test ${PROJECT_SOURCE_DIR}/src/test.cpp)
add_executable(trabalho1 ${SOURCES})
