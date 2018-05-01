CREATE TABLE IF NOT EXISTS Hotel(
    id SERIAL PRIMARY KEY,
    hotel_name VARCHAR(100),
    address VARCHAR(255),
    stars INTEGER,
    year_of_foundation DATE,
    id_city INTEGER
);

CREATE TABLE IF NOT EXISTS HotelRoomType(
    id SERIAL PRIMARY KEY,
    name VARCHAR(100)
);

CREATE TABLE IF NOT EXISTS HotelRoom(
    id SERIAL PRIMARY KEY,
    hotel_room_name VARCHAR(20),
    places INTEGER,
    shower BOOL,
    second_restroom BOOL,
    id_hotel INTEGER,
    id_hotel_room_type INTEGER
);

CREATE TABLE IF NOT EXISTS Reservation(
    id SERIAL PRIMARY KEY,
    date_of_begining DATE,
    date_of_ending DATE,
    id_hotel_room INTEGER,
    id_contract INTEGER
);

CREATE TABLE IF NOT EXISTS TourType(
    id SERIAL PRIMARY KEY,
    name VARCHAR(70)
);

CREATE TABLE IF NOT EXISTS Tour(
    id SERIAL PRIMARY KEY,
    name VARCHAR(200),
    days INTEGER,
    id_city INTEGER,
    id_tour_type INTEGER
);

CREATE TABLE IF NOT EXISTS Sight(
    id SERIAL PRIMARY KEY,
    name VARCHAR(100),
    address VARCHAR(150),
    year_of_foundation DATE,
    toponym VARCHAR(100),
    id_city INTEGER
);

CREATE TABLE IF NOT EXISTS City(
    id SERIAL PRIMARY KEY,
    name VARCHAR(100),
    id_country INTEGER,
    id_city_type INTEGER
);

CREATE TABLE IF NOT EXISTS CityType(
    id SERIAL PRIMARY KEY,
    name VARCHAR(80)
);

