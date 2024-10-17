drop table movie;

create table movie(id int, movie_title varchar(20), rating float, year_realsed int, budget int, language varchar(50));

insert into movie values(1, "Special Ops", 9.8, 2021, 90000, "Hindi English Kannada"),
(2, "God of Dragon", 9.6, 2019, 98000, "Hindi English"),
(3, "LIO", 9.9, 2022, 89000, "Hindi English Kannada Tealgu"),
(4, "God of Galaxy", 9.7, 2023, 94000, "Hindi English"),
(5, "Premalu", 9.4, 2023, 87000, "Hindi Telgu Kannada");

select * from movie;

select movie_title, rating, year_realsed from movie;

alter table movie add box_office int;
update movie set box_office = 200000 where id = 1;
update movie set box_office = 100000 where id = 1;
update movie set box_office = 800000 where id = 1;
update movie set box_office = 300000 where id = 1;
update movie set box_office = 900000 where id = 1;
