/*
  INSERTS 10 ANIMALS AS A BASIS FOR OUR DB
  LATER WE WILL HAVE TO GO THROUGH AND ASK THE STAFF TO INPUT NEW ANIMALS,
  IT WILL FOLLOW THIS SAME FORMAT (HAVE TO MAKE AN ENTRY INTO ANIMALS AND PHYSICAL_ATTRIBUTES)
*/

/*Inserting placeholder animals and physical characteristics*/
INSERT OR REPLACE INTO ANIMALS(animal_id, name)
  VALUES(10, "Buzz");
INSERT OR REPLACE INTO ANIMALS(animal_id, name)
  VALUES(11, "Spike");
INSERT OR REPLACE INTO ANIMALS(animal_id, name)
  VALUES(12, "Harold");
INSERT OR REPLACE INTO ANIMALS(animal_id, name)
  VALUES(13, "Stella");
INSERT OR REPLACE INTO ANIMALS(animal_id, name)
  VALUES(14, "Waltz");
INSERT OR REPLACE INTO ANIMALS(animal_id, name)
  VALUES(15, "Daisy");
INSERT OR REPLACE INTO ANIMALS(animal_id, name)
  VALUES(16, "Spits");
INSERT OR REPLACE INTO ANIMALS(animal_id, name)
  VALUES(17, "Luna");
INSERT OR REPLACE INTO ANIMALS(animal_id, name)
  VALUES(18, "Bella");
INSERT OR REPLACE INTO ANIMALS(animal_id, name)
  VALUES(19, "Molly");

INSERT OR REPLACE INTO PHYSICAL_ATTRIBUTES(a_id, gender, age, species, breed, hair_type, hair_colour)
  VALUES(10, "Male", 5, "Dog", "German Sheperd", "Short Hair", "Brown/Black");
INSERT OR REPLACE INTO PHYSICAL_ATTRIBUTES(a_id, gender, age, species, breed, hair_type, hair_colour)
  VALUES(11, "Male", 9, "Dog", "Terrier", "Long Hair", "White");
INSERT OR REPLACE INTO PHYSICAL_ATTRIBUTES(a_id, gender, age, species, breed, hair_type, hair_colour)
  VALUES(12, "Male", 2, "Snake", "Anaconda", "Scales", "Green");
INSERT OR REPLACE INTO PHYSICAL_ATTRIBUTES(a_id, gender, age, species, breed, hair_type, hair_colour)
  VALUES(13, "Female", 3, "Cat", "Tabby", "Long Hair", "Ginger");
INSERT OR REPLACE INTO PHYSICAL_ATTRIBUTES(a_id, gender, age, species, breed, hair_type, hair_colour)
  VALUES(14, "Male", 1, "Rat", "Brown Rat", "Short Hair", "Brown");
INSERT OR REPLACE INTO PHYSICAL_ATTRIBUTES(a_id, gender, age, species, breed, hair_type, hair_colour)
  VALUES(15, "Female", 2, "Dog", "Dalmatian", "Short Hair", "White/Black");
INSERT OR REPLACE INTO PHYSICAL_ATTRIBUTES(a_id, gender, age, species, breed, hair_type, hair_colour)
  VALUES(16, "Male", 12, "Cat", "Russian Blue", "Short Hair", "Grey");
INSERT OR REPLACE INTO PHYSICAL_ATTRIBUTES(a_id, gender, age, species, breed, hair_type, hair_colour)
  VALUES(17, "Female", 8, "Dog", "Husky", "Short Hair", "White/Black");
INSERT OR REPLACE INTO PHYSICAL_ATTRIBUTES(a_id, gender, age, species, breed, hair_type, hair_colour)
  VALUES(18, "Female", 4, "Cat", "Maine Coon", "Long Hair", "Brown/Grey");
INSERT OR REPLACE INTO PHYSICAL_ATTRIBUTES(a_id, gender, age, species, breed, hair_type, hair_colour)
  VALUES(19, "Female", 2, "Dog", "Poodle", "Long Hair", "Ginger");

/*Inserting placeholder staff account*/
INSERT OR REPLACE INTO USERS(user_id, name)
  VALUES(10, "Henry");

INSERT OR REPLACE INTO STAFF(staff_id, s_id, username, password)
  VALUES(10, 100, "Staff_01", "Staff");

