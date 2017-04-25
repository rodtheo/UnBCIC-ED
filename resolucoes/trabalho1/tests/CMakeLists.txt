include_directories(${CMAKE_SOURCE_DIR}/src)

# If pkg-config is not installed on the system, then the
# CHECK_INSTALL_DIR variable must be set to the install
# location of Check. For example, on Windows, this may
# be: C:/Program Files/check
# set(CHECK_INSTALL_DIR "C:/Program Files/check")

set(CHECK_INSTALL_DIR "/usr/local/Cellar/check/0.11.0")

#find_package(Check REQUIRED)
include_directories(${CHECK_INCLUDE_DIRS})

file(GLOB SOURCES "*.c")
add_executable(check_pilha ${SOURCES})
