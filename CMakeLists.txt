cmake_minimum_required(VERSION 3.9)
project(psqlWork)

set(CMAKE_CXX_STANDARD 11)
set(PROJECT_NAME psqlWork)


find_package(PostgreSQL REQUIRED)
include_directories(${PostgreSQL_INCLUDE_DIRS})
include_directories(src src/models)

set(PROJECT_SOURCE_DIR src)

set(SOURCES ${PROJECT_SOURCE_DIR}/main.cpp )
set(MODELS ${PROJECT_SOURCE_DIR}/models/Model.cpp ${PROJECT_SOURCE_DIR}/models/Model.h src/models/Client.cpp src/models/Client.h)
set(INTERFACES src/models/interfaces/ModelDAO.cpp src/models/interfaces/ModelDAO.h)

add_executable(${PROJECT_NAME} ${SOURCES} ${MODELS} ${INTERFACES})
target_link_libraries(${PROJECT_NAME} ${PostgreSQL_LIBRARIES})