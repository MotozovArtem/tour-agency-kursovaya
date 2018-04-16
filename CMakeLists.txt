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


set(INTERFACES src/models/interfaces/ModelDAO.h src/models/interfaces/HotelDAO.h
        src/models/interfaces/HotelRoomTypeDAO.h src/models/interfaces/HotelRoomDAO.h
        src/models/interfaces/ReservationDAO.h src/models/interfaces/TourTypeDAO.h
        src/models/interfaces/TourDAO.h src/models/interfaces/SightDAO.h
        src/models/interfaces/CityDAO.h src/models/interfaces/CityTypeDAO.h
        src/models/interfaces/ContractDAO.h src/models/interfaces/ClientsRestDAO.h
        src/models/interfaces/TicketDAO.h src/models/interfaces/FlightDAO.h
        src/models/interfaces/TransportNodeDAO.h src/models/interfaces/TransportNodeTypeDAO.h
        src/models/interfaces/PlaceArrivalDAO.h src/models/interfaces/PlaceArrivalTypeDAO.h
        src/models/interfaces/ClientDAO.h src/models/interfaces/DocumentsDAO.h
        src/models/interfaces/DocumentsForTourDAO.h src/models/interfaces/ReservByAgreementDAO.h
        src/models/interfaces/CountryDAO.h src/models/interfaces/DocumentTypeDAO.h)


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
        src/models/Contract.cpp src/models/Contract.h
        src/models/ClientsRest.cpp src/models/ClientsRest.h
        src/models/Ticket.cpp src/models/Ticket.h
        src/models/Flight.cpp src/models/Flight.h
        src/models/TransportNode.cpp src/models/TransportNode.h
        src/models/TransportNodeType.cpp src/models/TransportNodeType.h
        src/models/PlaceArrival.cpp src/models/PlaceArrival.h
        src/models/PlaceArrivalType.cpp src/models/PlaceArrivalType.h
        src/models/Client.cpp src/models/Client.h
        src/models/Documents.cpp src/models/Documents.h
        src/models/DocumentsForTour.cpp src/models/DocumentsForTour.h
        src/models/ReservByAgreement.cpp src/models/ReservByAgreement.h
        src/models/Country.cpp src/models/Country.h
        src/models/DocumentType.cpp src/models/DocumentType.h)


add_executable(${PROJECT_NAME} ${SOURCES} ${MODELS} ${INTERFACES})
target_link_libraries(${PROJECT_NAME} ${PostgreSQL_LIBRARIES})
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)