/*
  QUICKLY INITIALIZES THE TABLES IN THE DATABASE
*/

BEGIN TRANSACTION;

CREATE TABLE ANIMALS (
  animal_id INTEGER,
  name      TEXT,
  PRIMARY KEY(animal_id)
);

CREATE TABLE PHYSICAL_ATTRIBUTES (
  a_id        INTEGER UNIQUE,
  gender      TEXT,
  age         INTEGER,
  species     TEXT,
  breed       TEXT,
  hair_type   TEXT,
  hair_colour TEXT,
  FOREIGN KEY(a_id) REFERENCES ANIMALS(animal_id)
);

CREATE TABLE ANIMAL_CHARACTERISTICS (
  a_id	INTEGER UNIQUE,
  FOREIGN KEY(a_id) REFERENCES ANIMALS(animal_id)
);

CREATE TABLE USERS (
  user_id   INTEGER,
  name TEXT,
  PRIMARY KEY(user_id)
);

CREATE TABLE CLIENTS (
  client_id 	INTEGER,
  u_id 		INTEGER UNIQUE,
  username 	TEXT UNIQUE,
  password 	TEXT,
  PRIMARY KEY(client_id, username),
  FOREIGN KEY(u_id) REFERENCES USERS(user_id)
);

CREATE TABLE STAFF (
  staff_id 	INTEGER,
  s_id 		INTEGER UNIQUE,
  username 	TEXT UNIQUE,
  password 	TEXT,
  PRIMARY KEY(staff_id, username),
  FOREIGN KEY(s_id) REFERENCES USERS(user_id)
);

END TRANSACTION;
