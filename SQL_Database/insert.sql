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

/*Inserting placeholder animals and physical characteristics*/
INSERT OR REPLACE INTO ANIMALS(animal_id, name)
  VALUES(20, "Chloe");
INSERT OR REPLACE INTO ANIMALS(animal_id, name)
  VALUES(21, "Lola");
INSERT OR REPLACE INTO ANIMALS(animal_id, name)
  VALUES(22, "Fetch");
INSERT OR REPLACE INTO ANIMALS(animal_id, name)
  VALUES(23, "Rufus");
INSERT OR REPLACE INTO ANIMALS(animal_id, name)
  VALUES(24, "Peter");
INSERT OR REPLACE INTO ANIMALS(animal_id, name)
  VALUES(25, "Gabriel");
INSERT OR REPLACE INTO ANIMALS(animal_id, name)
  VALUES(26, "Louis");
INSERT OR REPLACE INTO ANIMALS(animal_id, name)
  VALUES(27, "Tiffany");
INSERT OR REPLACE INTO ANIMALS(animal_id, name)
  VALUES(28, "Sandy");
INSERT OR REPLACE INTO ANIMALS(animal_id, name)
  VALUES(29, "Olivia");
INSERT OR REPLACE INTO ANIMALS(animal_id, name)
  VALUES(30, "Ollie");
INSERT OR REPLACE INTO ANIMALS(animal_id, name)
  VALUES(31, "Ezra");
INSERT OR REPLACE INTO ANIMALS(animal_id, name)
  VALUES(32, "Curt");
INSERT OR REPLACE INTO ANIMALS(animal_id, name)
  VALUES(33, "Snakey");
INSERT OR REPLACE INTO ANIMALS(animal_id, name)
  VALUES(34, "Spot");

INSERT OR REPLACE INTO PHYSICAL_ATTRIBUTES(a_id, gender, age, species, breed, hair_type, hair_colour,aggressiveness,hyperactivity,sleep,noise,appetite,maintainance,outside,space_required,child_friendly,animal_friendly,equipment,excitibility)
  VALUES(10, "Male", 5, "Dog", "German Sheperd", "Short Hair", "Brown/Black","Submissive","Calm","Flexible","3","Minimal","Minimal","Sometimes","Moderate","No Children","Neutral","Minimal","Moderate");
INSERT OR REPLACE INTO PHYSICAL_ATTRIBUTES(a_id, gender, age, species, breed, hair_type, hair_colour,aggressiveness,hyperactivity,sleep,noise,appetite,maintainance,outside,space_required,child_friendly,animal_friendly,equipment,excitibility)
  VALUES(11, "Male", 9, "Dog", "Terrier", "Long Hair", "White","Slighty Submissive","Calm","Flexible","6","Minimal","Minimal","Sometimes","Moderate","Neutral","Neutral","Minimal","Moderate");
INSERT OR REPLACE INTO PHYSICAL_ATTRIBUTES(a_id, gender, age, species, breed, hair_type, hair_colour,aggressiveness,hyperactivity,sleep,noise,appetite,maintainance,outside,space_required,child_friendly,animal_friendly,equipment,excitibility)
  VALUES(12, "Male", 2, "Snake", "Anaconda", "Scales", "Green","Submissive","Slighty Calm","Flexible","6","Minimal","Minimal","Sometimes","Moderate","Neutral","No Children","Minimal","Moderate");
INSERT OR REPLACE INTO PHYSICAL_ATTRIBUTES(a_id, gender, age, species, breed, hair_type, hair_colour,aggressiveness,hyperactivity,sleep,noise,appetite,maintainance,outside,space_required,child_friendly,animal_friendly,equipment,excitibility)
  VALUES(13, "Female", 3, "Cat", "Tabby", "Long Hair", "Ginger","Slighty Submissive","Slighty Hyper","Flexible","5","Minimal","Minimal","Sometimes","Moderate","Neutral","Neutral","Some Equipment","Moderate");
INSERT OR REPLACE INTO PHYSICAL_ATTRIBUTES(a_id, gender, age, species, breed, hair_type, hair_colour,aggressiveness,hyperactivity,sleep,noise,appetite,maintainance,outside,space_required,child_friendly,animal_friendly,equipment,excitibility)
  VALUES(14, "Male", 1, "Rat", "Brown Rat", "Short Hair", "Brown","Submissive","Hyper","Flexible","3","Minimal","Minimal","Sometimes","Moderate","Neutral","Neutral","Minimal","Moderate");
INSERT OR REPLACE INTO PHYSICAL_ATTRIBUTES(a_id, gender, age, species, breed, hair_type, hair_colour,aggressiveness,hyperactivity,sleep,noise,appetite,maintainance,outside,space_required,child_friendly,animal_friendly,equipment,excitibility)
  VALUES(15, "Female", 2, "Dog", "Dalmatian", "Short Hair", "White/Black","Slighty Submissive","Slighty Calm","Flexible","10","Minimal","Minimal","Sometimes","Moderate","Neutral","Neutral","Some Equipment","Moderate");
INSERT OR REPLACE INTO PHYSICAL_ATTRIBUTES(a_id, gender, age, species, breed, hair_type, hair_colour,aggressiveness,hyperactivity,sleep,noise,appetite,maintainance,outside,space_required,child_friendly,animal_friendly,equipment,excitibility)
  VALUES(16, "Male", 12, "Cat", "Russian Blue", "Short Hair", "Grey","Submissive","Slighty Hyper","Flexible","4","Minimal","Minimal","Sometimes","Moderate","No Children","Neutral","Minimal","Moderate");
INSERT OR REPLACE INTO PHYSICAL_ATTRIBUTES(a_id, gender, age, species, breed, hair_type, hair_colour,aggressiveness,hyperactivity,sleep,noise,appetite,maintainance,outside,space_required,child_friendly,animal_friendly,equipment,excitibility)
  VALUES(17, "Female", 8, "Dog", "Husky", "Short Hair", "White/Black","Slighty Aggressive","Hyper","Flexible","7","Minimal","Minimal","Sometimes","Moderate","Neutral","Neutral","Some Equipment","Moderate");
INSERT OR REPLACE INTO PHYSICAL_ATTRIBUTES(a_id, gender, age, species, breed, hair_type, hair_colour,aggressiveness,hyperactivity,sleep,noise,appetite,maintainance,outside,space_required,child_friendly,animal_friendly,equipment,excitibility)
  VALUES(18, "Female", 4, "Parrot", "Maine Coon", "Long Hair", "Brown/Grey","Submissive","Slighty Hyper","Flexible","3","Minimal","Minimal","Sometimes","Moderate","Neutral","Neutral","Minimal","Moderate");
INSERT OR REPLACE INTO PHYSICAL_ATTRIBUTES(a_id, gender, age, species, breed, hair_type, hair_colour,aggressiveness,hyperactivity,sleep,noise,appetite,maintainance,outside,space_required,child_friendly,animal_friendly,equipment,excitibility)
  VALUES(19, "Female", 2, "Dog", "Poodle", "Long Hair", "Ginger","Aggressive","Hyper","Flexible","3","Minimal","Minimal","Sometimes","Moderate","Neutral","Neutral","Some Equipment","Moderate");
INSERT OR REPLACE INTO PHYSICAL_ATTRIBUTES(a_id, gender, age, species, breed, hair_type, hair_colour,aggressiveness,hyperactivity,sleep,noise,appetite,maintainance,outside,space_required,child_friendly,animal_friendly,equipment,excitibility)
  VALUES(20, "Male", 2, "Bunny", "Dutch", "Short Hair", "Black","Submissive","Calm","Flexible","2","Average","Above Average","Rarely","Minimal","Child Friendly","Not Animal Friendly","Some Equipment","Not Easily Excited");
INSERT OR REPLACE INTO PHYSICAL_ATTRIBUTES(a_id, gender, age, species, breed, hair_type, hair_colour,aggressiveness,hyperactivity,sleep,noise,appetite,maintainance,outside,space_required,child_friendly,animal_friendly,equipment,excitibility)
  VALUES(21, "Male", 3, "Parrot", "Grey Parrott", "Feathers", "Grey","Aggressive","Hyper","Nocturnal","10","Above Average","Minimal","Multiple Times Daily","Above Average","No Children","Neutral","More Than Average Equipment","Easily Excited");
INSERT OR REPLACE INTO PHYSICAL_ATTRIBUTES(a_id, gender, age, species, breed, hair_type, hair_colour,aggressiveness,hyperactivity,sleep,noise,appetite,maintainance,outside,space_required,child_friendly,animal_friendly,equipment,excitibility)
  VALUES(22, "Male", 2, "Snake", "Anaconda", "Scales", "Green","Slightly Aggressive","Slighty Calm","Normal","1","Minimal","Minimal","Rarely","Minimal","No Children","Not Animal Friendly","Some Equipment","Moderate");
INSERT OR REPLACE INTO PHYSICAL_ATTRIBUTES(a_id, gender, age, species, breed, hair_type, hair_colour,aggressiveness,hyperactivity,sleep,noise,appetite,maintainance,outside,space_required,child_friendly,animal_friendly,equipment,excitibility)
  VALUES(23, "Female", 3, "Bunny", "Long-Haired", "Long Hair", "White","Slighty Submissive","Slighty Hyper","Flexible","3","Minimal","Minimal","Sometimes","Moderate","Neutral","Neutral","Above Average","Not Easily Excited");
INSERT OR REPLACE INTO PHYSICAL_ATTRIBUTES(a_id, gender, age, species, breed, hair_type, hair_colour,aggressiveness,hyperactivity,sleep,noise,appetite,maintainance,outside,space_required,child_friendly,animal_friendly,equipment,excitibility)
  VALUES(24, "Male", 1, "Rat", "Brown Rat", "Short Hair", "Brown","Submissive","Hyper","Flexible","4","Minimal","Minimal","Sometimes","Moderate","Neutral","Neutral","Minimal","Easily Excited");
INSERT OR REPLACE INTO PHYSICAL_ATTRIBUTES(a_id, gender, age, species, breed, hair_type, hair_colour,aggressiveness,hyperactivity,sleep,noise,appetite,maintainance,outside,space_required,child_friendly,animal_friendly,equipment,excitibility)
  VALUES(25, "Female", 2, "Dog", "Dalmatian", "Short Hair", "White/Black","Slighty Submissive","Slighty Calm","Flexible","10","Minimal","Minimal","Sometimes","Moderate","Neutral","Neutral","Some Equipment","Not Easily Excited");
INSERT OR REPLACE INTO PHYSICAL_ATTRIBUTES(a_id, gender, age, species, breed, hair_type, hair_colour,aggressiveness,hyperactivity,sleep,noise,appetite,maintainance,outside,space_required,child_friendly,animal_friendly,equipment,excitibility)
  VALUES(26, "Male", 12, "Cat", "Russian Blue", "Short Hair", "Grey","Submissive","Slighty Hyper","Flexible","9","Minimal","Minimal","Sometimes","Moderate","No Children","Neutral","Minimal","Not Easily Excited");
INSERT OR REPLACE INTO PHYSICAL_ATTRIBUTES(a_id, gender, age, species, breed, hair_type, hair_colour,aggressiveness,hyperactivity,sleep,noise,appetite,maintainance,outside,space_required,child_friendly,animal_friendly,equipment,excitibility)
  VALUES(27, "Female", 8, "Dog", "Husky", "Short Hair", "White/Black","Slighty Aggressive","Hyper","Flexible","7","Minimal","Minimal","Sometimes","Moderate","Neutral","Neutral","Some Equipment","Moderate");
INSERT OR REPLACE INTO PHYSICAL_ATTRIBUTES(a_id, gender, age, species, breed, hair_type, hair_colour,aggressiveness,hyperactivity,sleep,noise,appetite,maintainance,outside,space_required,child_friendly,animal_friendly,equipment,excitibility)
  VALUES(28, "Female", 4, "Cat", "Maine Coon", "Long Hair", "Brown/Grey","Submissive","Slighty Hyper","Flexible","3","Minimal","Minimal","Sometimes","Moderate","No Children","Neutral","Some Equipment","Easily Excited");
INSERT OR REPLACE INTO PHYSICAL_ATTRIBUTES(a_id, gender, age, species, breed, hair_type, hair_colour,aggressiveness,hyperactivity,sleep,noise,appetite,maintainance,outside,space_required,child_friendly,animal_friendly,equipment,excitibility)
  VALUES(29, "Female", 2, "Dog", "Poodle", "Long Hair", "Ginger","Aggressive","Hyper","Flexible","8","Minimal","Minimal","Sometimes","Moderate","Neutral","Neutral","More Than Average Equipment","Moderate");
INSERT OR REPLACE INTO PHYSICAL_ATTRIBUTES(a_id, gender, age, species, breed, hair_type, hair_colour,aggressiveness,hyperactivity,sleep,noise,appetite,maintainance,outside,space_required,child_friendly,animal_friendly,equipment,excitibility)
  VALUES(30, "Male", 5, "Dog", "German Sheperd", "Short Hair", "Brown/Black","Submissive","Calm","Flexible","3","Minimal","Minimal","Sometimes","Moderate","No Children","Neutral","Some Equipment","Not Easily Excited");
INSERT OR REPLACE INTO PHYSICAL_ATTRIBUTES(a_id, gender, age, species, breed, hair_type, hair_colour,aggressiveness,hyperactivity,sleep,noise,appetite,maintainance,outside,space_required,child_friendly,animal_friendly,equipment,excitibility)
  VALUES(31, "Male", 9, "Dog", "Terrier", "Long Hair", "White","Slighty Submissive","Calm","Flexible","3","Minimal","Minimal","Sometimes","Moderate","Neutral","Neutral","More Than Average Equipment","Moderate");
INSERT OR REPLACE INTO PHYSICAL_ATTRIBUTES(a_id, gender, age, species, breed, hair_type, hair_colour,aggressiveness,hyperactivity,sleep,noise,appetite,maintainance,outside,space_required,child_friendly,animal_friendly,equipment,excitibility)
  VALUES(32, "Male", 2, "Cat", "Tabby", "short", "Green","Submissive","Slighty Calm","Flexible","6","Minimal","Minimal","Sometimes","Moderate","Neutral","Neutral","Some Equipment","Not Easily Excited");
INSERT OR REPLACE INTO PHYSICAL_ATTRIBUTES(a_id, gender, age, species, breed, hair_type, hair_colour,aggressiveness,hyperactivity,sleep,noise,appetite,maintainance,outside,space_required,child_friendly,animal_friendly,equipment,excitibility)
  VALUES(33, "Female", 3, "Snake", "King Cobra", "Long Hair", "Ginger","Slighty Submissive","Slighty Hyper","Flexible","1","Minimal","Minimal","Sometimes","Moderate","No Children","Neutral","Some Equipment","Moderate");
INSERT OR REPLACE INTO PHYSICAL_ATTRIBUTES(a_id, gender, age, species, breed, hair_type, hair_colour,aggressiveness,hyperactivity,sleep,noise,appetite,maintainance,outside,space_required,child_friendly,animal_friendly,equipment,excitibility)
  VALUES(34, "Male", 1, "Rat", "Brown Rat", "Short Hair", "Brown","Submissive","Hyper","Flexible","5","Minimal","Minimal","Sometimes","Moderate","Neutral","Neutral","More Than Average Equipment","Easily Excited");

/*Inserting placeholder staff account*/
INSERT OR REPLACE INTO USERS(user_id, name, phone_number, address, postal_code, province)
  VALUES(10, "Henry", "613-220-1100", "125 Main St.", "K2P1M4", "Ontario");

INSERT OR REPLACE INTO STAFF(s_id, username, password)
  VALUES(10, "Staff_01", "Staff");

/*Inserting Client Accounts*/
INSERT OR REPLACE INTO USERS(user_id, name, phone_number, address, postal_code, province)
  VALUES(11, "John Doe", "613-100-0000", "514 Elgin St.", "K2P3T2", "Ontario");

INSERT OR REPLACE INTO USERS(user_id, name, phone_number, address, postal_code, province)
  VALUES(12, "Quinn Stevenson", "613-100-0001", "1180 Claymor Ave.", "K2P9B1", "Ontario");

INSERT OR REPLACE INTO USERS(user_id, name, phone_number, address, postal_code, province)
  VALUES(13, "Keegan Jones", "613-100-0002", "133 Bank St.", "K2P4M4", "Ontario");

INSERT OR REPLACE INTO USERS(user_id, name, phone_number, address, postal_code, province)
  VALUES(14, "Curtis Unrau", "613-100-0003", "222 Glebe Ave.", "K2P8R1", "Ontario");

INSERT OR REPLACE INTO USERS(user_id, name, phone_number, address, postal_code, province)
  VALUES(15, "Jared Cummings", "613-100-0004", "455 Waverley St.", "K2P7B7", "Ontario");

INSERT OR REPLACE INTO CLIENTS(u_id, username, password,animal_wanted,agression,hyperactivity,sleep,animal_loudness,food_budget,time_avail,house_type,child_friendly,equip_budget,have_animals,ex_stimuli,pref_age,pref_gender)
<<<<<<< HEAD
  VALUES(11, "Client_01", "Client",1,2,1,2,1,2,1,1,2,1,2,1,2,1);
=======
  VALUES(11, "Client_01", "Client",0,2,1,2,1,2,1,1,2,1,2,1,2,1);
>>>>>>> master

INSERT OR REPLACE INTO CLIENTS(u_id, username, password,animal_wanted,agression,hyperactivity,sleep,animal_loudness,food_budget,time_avail,house_type,child_friendly,equip_budget,have_animals,ex_stimuli,pref_age,pref_gender)
  VALUES(12, "Client_02", "Client",1,2,1,2,1,2,1,1,2,1,2,1,2,1);

INSERT OR REPLACE INTO CLIENTS(u_id, username, password,animal_wanted,agression,hyperactivity,sleep,animal_loudness,food_budget,time_avail,house_type,child_friendly,equip_budget,have_animals,ex_stimuli,pref_age,pref_gender)
<<<<<<< HEAD
  VALUES(13, "Client_03", "Client",1,2,1,2,1,2,1,1,2,1,2,1,2,1);
=======
  VALUES(13, "Client_03", "Client",0,2,1,2,1,2,1,1,2,1,2,1,2,1);
>>>>>>> master

INSERT OR REPLACE INTO CLIENTS(u_id, username, password,animal_wanted,agression,hyperactivity,sleep,animal_loudness,food_budget,time_avail,house_type,child_friendly,equip_budget,have_animals,ex_stimuli,pref_age,pref_gender)
  VALUES(14, "Client_04", "Client",1,2,1,2,1,2,1,1,2,1,2,1,2,1);

INSERT OR REPLACE INTO CLIENTS(u_id, username, password,animal_wanted,agression,hyperactivity,sleep,animal_loudness,food_budget,time_avail,house_type,child_friendly,equip_budget,have_animals,ex_stimuli,pref_age,pref_gender)
<<<<<<< HEAD
  VALUES(15, "Client_05", "Client",1,2,1,2,1,2,1,1,2,1,2,1,2,1);
=======
  VALUES(15, "Client_05", "Client",0,2,1,2,1,2,1,1,2,1,2,1,2,1);
>>>>>>> master
