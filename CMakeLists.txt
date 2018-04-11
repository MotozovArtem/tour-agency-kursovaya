cmake_minimum_required(VERSION 3.9)
project(psqlWork)

set(CMAKE_CXX_STANDARD 11)
set(PROJECT_NAME psqlWork)


find_package(PostgreSQL REQUIRED)
find_package(Qt5Widgets REQUIRED)
#find_package(Boost 1.64 REQUIRED)


include_directories(${PostgreSQL_INCLUDE_DIRS})
#include_directories(${Boost_INCLUDE_DIRS})
include_directories(src src/models)

set(PROJECT_SOURCE_DIR src)

set(SOURCES ${PROJECT_SOURCE_DIR}/main.cpp)
set(INTERFACES src/models/interfaces/ModelDAO.cpp src/models/interfaces/ModelDAO.h)
set(MODELS ${PROJECT_SOURCE_DIR}/models/Model.cpp ${PROJECT_SOURCE_DIR}/models/Model.h
        src/models/Hotel.cpp src/models/Hotel.h
        src/models/HotelRoomType.cpp src/models/HotelRoomType.h
        src/models/HotelRoom.cpp src/models/HotelRoom.h
        src/models/Reservation.cpp src/models/Reservation.h
        src/models/TourType.cpp src/models/TourType.h
        src/models/Tour.cpp src/models/Tour.h
        src/models/Sight.cpp src/models/Sight.h
        src/models/City.cpp src/models/City.h
        src/models/CityType.cpp src/models/CityType.h
        src/models/Contract.cpp src/models/Contract.h src/models/ClientsRest.cpp src/models/ClientsRest.h src/models/Ticket.cpp src/models/Ticket.h src/models/Flight.cpp src/models/Flight.h)


add_executable(${PROJECT_NAME} ${SOURCES} ${MODELS} ${INTERFACES})
target_link_libraries(${PROJECT_NAME} ${PostgreSQL_LIBRARIES})
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)