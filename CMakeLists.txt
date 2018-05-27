cmake_minimum_required(VERSION 3.9)
project(psqlWork)

set(CMAKE_CXX_STANDARD 11)
set(PROJECT_NAME psqlWork)
set(CMAKE_AUTOMOC True)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Sql REQUIRED)

include_directories(src src/models)

set(PROJECT_SOURCE_DIR src)

set(SOURCES ${PROJECT_SOURCE_DIR}/main.cpp
        src/SQL/SQLConnection.cpp src/SQL/SQLConnection.h
        src/utils/Logger.cpp src/utils/Logger.h
        src/GUI/MainWindow.cpp src/GUI/MainWindow.h
        )


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
        src/models/interfaces/CountryDAO.h src/models/interfaces/DocumentTypeDAO.h
        src/models/interfaces/StatusDAO.h
        )


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
        src/models/ClientRest.cpp src/models/ClientRest.h
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
        src/models/DocumentType.cpp src/models/DocumentType.h src/models/Status.cpp src/models/Status.h
        )


set(REALIZATION src/models/interfaces/dao_realization/HotelDataBaseDAO.cpp
        src/models/interfaces/dao_realization/HotelDataBaseDAO.h
        src/models/interfaces/dao_realization/CityDataBaseDAO.cpp
        src/models/interfaces/dao_realization/CityDataBaseDAO.h
        src/models/interfaces/dao_realization/HotelRoomTypeDataBaseDAO.cpp
        src/models/interfaces/dao_realization/HotelRoomTypeDataBaseDAO.h
        src/models/interfaces/dao_realization/HotelRoomDataBaseDAO.cpp
        src/models/interfaces/dao_realization/HotelRoomDataBaseDAO.h
        src/models/interfaces/dao_realization/ReservationDataBaseDAO.cpp
        src/models/interfaces/dao_realization/ReservationDataBaseDAO.h
        src/models/interfaces/dao_realization/TourTypeDataBaseDAO.cpp
        src/models/interfaces/dao_realization/TourTypeDataBaseDAO.h
        src/models/interfaces/dao_realization/TourDataBaseDAO.cpp
        src/models/interfaces/dao_realization/TourDataBaseDAO.h
        src/models/interfaces/dao_realization/SightDataBaseDAO.cpp
        src/models/interfaces/dao_realization/SightDataBaseDAO.h
        src/models/interfaces/dao_realization/CityTypeDataBaseDAO.cpp
        src/models/interfaces/dao_realization/CityTypeDataBaseDAO.h
        src/models/interfaces/dao_realization/CountryDataBaseDAO.cpp
        src/models/interfaces/dao_realization/CountryDataBaseDAO.h
        src/models/interfaces/dao_realization/ContractDataBaseDAO.cpp
        src/models/interfaces/dao_realization/ContractDataBaseDAO.h
        src/models/interfaces/dao_realization/ClientRestDataBaseDAO.cpp
        src/models/interfaces/dao_realization/ClientRestDataBaseDAO.h
        src/models/interfaces/dao_realization/TicketDataBaseDAO.cpp
        src/models/interfaces/dao_realization/TicketDataBaseDAO.h
        src/models/interfaces/dao_realization/FlightDataBaseDAO.cpp
        src/models/interfaces/dao_realization/FlightDataBaseDAO.h
        src/models/interfaces/dao_realization/TransportNodeDataBaseDAO.cpp
        src/models/interfaces/dao_realization/TransportNodeDataBaseDAO.h
        src/models/interfaces/dao_realization/TransportNodeTypeDataBaseDAO.cpp
        src/models/interfaces/dao_realization/TransportNodeTypeDataBaseDAO.h
        src/models/interfaces/dao_realization/DocumentTypeDataBaseDAO.cpp
        src/models/interfaces/dao_realization/DocumentTypeDataBaseDAO.h
        src/models/interfaces/dao_realization/PlaceArrivalTypeDataBaseDAO.cpp
        src/models/interfaces/dao_realization/PlaceArrivalTypeDataBaseDAO.h
        src/models/interfaces/dao_realization/PlaceArrivalDataBaseDAO.cpp
        src/models/interfaces/dao_realization/PlaceArrivalDataBaseDAO.h
        src/models/interfaces/dao_realization/ClientDataBaseDAO.cpp
        src/models/interfaces/dao_realization/ClientDataBaseDAO.h
        src/models/interfaces/dao_realization/DocumentsDataBaseDAO.cpp
        src/models/interfaces/dao_realization/DocumentsDataBaseDAO.h
        src/models/interfaces/dao_realization/DocumentsForTourDataBaseDAO.cpp src/models/interfaces/dao_realization/DocumentsForTourDataBaseDAO.h src/models/interfaces/dao_realization/StatusDataBaseDAO.cpp src/models/interfaces/dao_realization/StatusDataBaseDAO.h src/models/interfaces/dao_realization/ReservByAgreementDataBaseDAO.cpp src/models/interfaces/dao_realization/ReservByAgreementDataBaseDAO.h)

add_executable(${PROJECT_NAME} ${SOURCES} ${MODELS} ${INTERFACES} ${REALIZATION})

target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
target_link_libraries(${PROJECT_NAME} Qt5::Sql)