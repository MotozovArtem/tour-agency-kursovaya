cmake_minimum_required(VERSION 3.9)
project(psqlWork)

set(CMAKE_CXX_STANDARD 11)
set(PROJECT_NAME psqlWork)


find_package(PostgreSQL REQUIRED)
#find_package(Boost 1.64 REQUIRED)


include_directories(${PostgreSQL_INCLUDE_DIRS})
#include_directories(${Boost_INCLUDE_DIRS})
include_directories(src src/models)

set(PROJECT_SOURCE_DIR src)

set(SOURCES ${PROJECT_SOURCE_DIR}/main.cpp )
set(INTERFACES src/models/interfaces/ModelDAO.cpp src/models/interfaces/ModelDAO.h)
set(MODELS ${PROJECT_SOURCE_DIR}/models/Model.cpp ${PROJECT_SOURCE_DIR}/models/Model.h
        src/models/Client.cpp src/models/Client.h
        src/models/Document.cpp src/models/Document.h
        src/models/Ticket.cpp src/models/Ticket.h
        src/models/Flight.cpp src/models/Flight.h
        src/models/DocumentType.cpp src/models/DocumentType.h
        src/models/Contract.cpp src/models/Contract.h src/models/Check.cpp src/models/Check.h src/models/Status.cpp src/models/Status.h)


add_executable(${PROJECT_NAME} ${SOURCES} ${MODELS} ${INTERFACES})
target_link_libraries(${PROJECT_NAME} ${PostgreSQL_LIBRARIES})