CREATE TABLE IF NOT EXISTS Hotel (
  id                 SERIAL PRIMARY KEY,
  hotel_name         VARCHAR(100),
  address            VARCHAR(255),
  stars              INTEGER,
  year_of_foundation DATE,
  id_city            INTEGER
);

CREATE TABLE IF NOT EXISTS HotelRoomType (
  id   SERIAL PRIMARY KEY,
  name VARCHAR(100)
);

CREATE TABLE IF NOT EXISTS HotelRoom (
  id                 SERIAL PRIMARY KEY,
  hotel_room_name    VARCHAR(20),
  places             INTEGER,
  shower             BOOL,
  second_restroom    BOOL,
  id_hotel           INTEGER,
  id_hotel_room_type INTEGER
);

CREATE TABLE IF NOT EXISTS Reservation (
  id               SERIAL PRIMARY KEY,
  date_of_begining DATE,
  date_of_ending   DATE,
  id_hotel_room    INTEGER,
  id_contract      INTEGER
);

CREATE TABLE IF NOT EXISTS TourType (
  id   SERIAL PRIMARY KEY,
  name VARCHAR(70)
);

CREATE TABLE IF NOT EXISTS Tour (
  id           SERIAL PRIMARY KEY,
  name         VARCHAR(200),
  days         INTEGER,
  id_city      INTEGER,
  id_tour_type INTEGER
);

CREATE TABLE IF NOT EXISTS Sight (
  id                 SERIAL PRIMARY KEY,
  name               VARCHAR(100),
  address            VARCHAR(150),
  year_of_foundation DATE,
  toponym            VARCHAR(100),
  id_city            INTEGER
);

CREATE TABLE IF NOT EXISTS City (
  id           SERIAL PRIMARY KEY,
  name         VARCHAR(100),
  id_country   INTEGER,
  id_city_type INTEGER
);

CREATE TABLE IF NOT EXISTS CityType (
  id   SERIAL PRIMARY KEY,
  name VARCHAR(80)
);

CREATE TABLE IF NOT EXISTS Country (
  id              SERIAL PRIMARY KEY,
  name            VARCHAR(100),
  foundation_date DATE
);

CREATE TABLE IF NOT EXISTS Contract (
  id              SERIAL PRIMARY KEY,
  name            VARCHAR(100),
  date_of_payment DATE,
  date_of_issue   DATE,
  total           NUMERIC(12, 2),
  id_status       INTEGER,
  id_tour_type    INTEGER,
  id_documents    INTEGER
);

CREATE TABLE IF NOT EXISTS ClientRest (
  id          SERIAL PRIMARY KEY,
  id_contract INTEGER,
  id_client   INTEGER
);

CREATE TABLE IF NOT EXISTS Ticket (
  id               SERIAL PRIMARY KEY,
  place            INTEGER,
  date_flight      DATE,
  price            NUMERIC(10, 2),
  date_of_purchase DATE,
  id_documents     INTEGER,
  id_flight        INTEGER
);

CREATE TABLE IF NOT EXISTS Flight (
  id                SERIAL PRIMARY KEY,
  date_of_purchase  DATE,
  date_of_departure DATE,
  departure_time    TIME,
  arrival_time      TIME,
  arrivale_date     DATE
);

CREATE TABLE IF NOT EXISTS TransportNode (
  id                     SERIAL PRIMARY KEY,
  node_name              VARCHAR(100),
  id_flight              INTEGER,
  id_transport_node_type INTEGER
);

CREATE TABLE IF NOT EXISTS PlaceArrival (
  id                    SERIAL PRIMARY KEY,
  name                  VARCHAR(100),
  address               VARCHAR(200),
  id_city               INTEGER,
  id_place_arrival_type INTEGER
);

CREATE TABLE IF NOT EXISTS PlaceArrivalType (
  id   SERIAL PRIMARY KEY,
  name VARCHAR(100)
);

CREATE TABLE IF NOT EXISTS Client (
  id             SERIAL PRIMARY KEY,
  passport_data  VARCHAR(200),
  surname        VARCHAR(50),
  name           VARCHAR(50),
  patronymic     VARCHAR(50),
  date_of_birth  DATE,
  place_of_birth VARCHAR(100),
  sex            BOOLEAN
);

CREATE TABLE IF NOT EXISTS Documents (
  id                  SERIAL PRIMARY KEY,
  document_serial     VARCHAR(50),
  date_of_issue       DATE,
  issuance_department VARCHAR(150)
);

CREATE TABLE IF NOT EXISTS DocumentsForTour (
  id               SERIAL PRIMARY KEY,
  id_document      INTEGER,
  id_client        INTEGER,
  id_document_type INTEGER
);

CREATE TABLE IF NOT EXISTS ReservByAgreement(
    id SERIAL PRIMARY KEY,
    date_of_begining DATE,
    id_hotel_room INTEGER,
    id_contract INTEGER
);

CREATE TABLE IF NOT EXISTS DocumentType(
    id SERIAL PRIMARY KEY,
    name VARCHAR(100)
);

CREATE TABLE IF NOT EXISTS TransportNodeType(
    id SERIAL PRIMARY KEY,
    name VARCHAR(100)
);

CREATE TABLE IF NOT EXISTS Status(
    id SERIAL PRIMARY KEY,
    name VARCHAR(100)
);