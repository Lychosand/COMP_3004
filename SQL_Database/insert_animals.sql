/*
  INSERTS 10 ANIMALS AS A BASIS FOR OUR DB
  LATER WE WILL HAVE TO GO THROUGH AND ASK THE STAFF TO INPUT NEW ANIMALS,
  IT WILL FOLLOW THIS SAME FORMAT (HAVE TO MAKE AN ENTRY INTO ANIMALS AND PHYSICAL_ATTRIBUTES)
*/



INSERT OR REPLACE INTO ANIMALS(animal_id, name)
  VALUES(00, "Buzz");
INSERT OR REPLACE INTO ANIMALS(animal_id, name)
  VALUES(01, "Spike");
INSERT OR REPLACE INTO ANIMALS(animal_id, name)
  VALUES(02, "Harold");
INSERT OR REPLACE INTO ANIMALS(animal_id, name)
  VALUES(03, "Stella");
INSERT OR REPLACE INTO ANIMALS(animal_id, name)
  VALUES(04, "Waltz");
INSERT OR REPLACE INTO ANIMALS(animal_id, name)
  VALUES(05, "Daisy");
INSERT OR REPLACE INTO ANIMALS(animal_id, name)
  VALUES(06, "Spits");
INSERT OR REPLACE INTO ANIMALS(animal_id, name)
  VALUES(07, "Luna");
INSERT OR REPLACE INTO ANIMALS(animal_id, name)
  VALUES(08, "Bella");
INSERT OR REPLACE INTO ANIMALS(animal_id, name)
  VALUES(09, "Molly");

INSERT OR REPLACE INTO PHYSICAL_ATTRIBUTES(a_id, gender, age, species, breed, hair_type, hair_colour)
  VALUES(00, "Male", 5, "Dog", "German Sheperd", "Short Hair", "Brown/Black");
INSERT OR REPLACE INTO PHYSICAL_ATTRIBUTES(a_id, gender, age, species, breed, hair_type, hair_colour)
  VALUES(01, "Male", 9, "Dog", "Terrier", "Long Hair", "White");
INSERT OR REPLACE INTO PHYSICAL_ATTRIBUTES(a_id, gender, age, species, breed, hair_type, hair_colour)
  VALUES(02, "Male", 2, "Snake", "Anaconda", "Scales", "Green");
INSERT OR REPLACE INTO PHYSICAL_ATTRIBUTES(a_id, gender, age, species, breed, hair_type, hair_colour)
  VALUES(03, "Female", 3, "Cat", "Tabby", "Long Hair", "Ginger");
INSERT OR REPLACE INTO PHYSICAL_ATTRIBUTES(a_id, gender, age, species, breed, hair_type, hair_colour)
  VALUES(04, "Male", 1, "Rat", "Brown Rat", "Short Hair", "Brown");
INSERT OR REPLACE INTO PHYSICAL_ATTRIBUTES(a_id, gender, age, species, breed, hair_type, hair_colour)
  VALUES(05, "Female", 2, "Dog", "Dalmatian", "Short Hair", "White/Black");
INSERT OR REPLACE INTO PHYSICAL_ATTRIBUTES(a_id, gender, age, species, breed, hair_type, hair_colour)
  VALUES(06, "Male", 12, "Cats", "Russian Blue", "Short Hair", "Grey");
INSERT OR REPLACE INTO PHYSICAL_ATTRIBUTES(a_id, gender, age, species, breed, hair_type, hair_colour)
  VALUES(07, "Female", 8, "Dog", "Husky", "Short Hair", "White/Black");
INSERT OR REPLACE INTO PHYSICAL_ATTRIBUTES(a_id, gender, age, species, breed, hair_type, hair_colour)
  VALUES(08, "Female", 4, "Cat", "Maine Coon", "Long Hair", "Brown/Grey");
INSERT OR REPLACE INTO PHYSICAL_ATTRIBUTES(a_id, gender, age, species, breed, hair_type, hair_colour)
  VALUES(09, "Female", 2, "Dog", "Poodle", "Long Hair", "Ginger");
