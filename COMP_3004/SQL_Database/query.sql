/*
  QUERY THAT JOINS THE ANIMALS TABLE TO THE PHYSICAL_ATTRIBUTES TABLE
  THIS RESULTING QUERY IS ALL THAT IS REQUIRED OF US FOR DELIVERABLE 1
  IT WILL RETURN A TABLE WITH ALL ANIMAL NAMES + THEIR SPECIFIC PHYSICAL PHYSICAL_ATTRIBUTES
  WHAT NEEDS TO BE DONE IS TO INCORPORATE THIS INTO OUR C++ PROGRAM AND MAKE IT VIEWABLE USING THE QTFRAMEWORK
*/

SELECT animal_id,
       NAME,
       gender,
       age,
       species,
       breed,
       hair_type,
       hair_colour
FROM   ANIMALS
       INNER JOIN PHYSICAL_ATTRIBUTES
               ON ANIMALS.animal_id = PHYSICAL_ATTRIBUTES.a_id;


/*
OUTPUT:
  0|Buzz|Male|5|Dog|German Sheperd|Short Hair|Brown/Black
  1|Spike|Male|9|Dog|Terrier|Long Hair|White
  2|Harold|Male|2|Snake|Anaconda|Scales|Green
  3|Stella|Female|3|Cat|Tabby|Long Hair|Ginger
  4|Waltz|Male|1|Rat|Brown Rat|Short Hair|Brown
  5|Daisy|Female|2|Dog|Dalmatian|Short Hair|White/Black
  6|Spits|Male|12|Cats|Russian Blue|Short Hair|Grey
  7|Luna|Female|8|Dog|Husky|Short Hair|White/Black
  8|Bella|Female|4|Cat|Maine Coon|Long Hair|Brown/Grey
  9|Molly|Female|2|Dog|Poodle|Long Hair|Ginger
*/
