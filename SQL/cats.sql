drop table cats; 

create table cats(id int, name varchar(20), breed varchar(20), coloration varchar(20), age int, sex varchar(20), fav_toy varchar(20));
insert into cats values(1, "Jenny", "Siamese", "Black", 11, "Male", "Ball"),
(2, "Bunny", "Ragdoll", "Brown", 09, "Female", "Teddy Bear"),
(3, "Smokey", "Siamese", "White", 07, "Male", "Ball"),
(4, "Lisa", "Ragdoll", "Brown", 10, "Female", "Teddy Bear"),
(5, "Hunny", "Siamese", "Black", 06, "Female", "Ball");

select * from cats;
select * from cats where age <= 7;
select * from cats where Breed = "Ragdoll";
select * from cats order by age;