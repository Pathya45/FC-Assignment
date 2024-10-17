drop table games;
create table games(id int, title varchar(20), comapny varchar(20), type varchar(20), production_year int, system_type varchar(20), production_cost int, revenue int, rating float);

insert into games values
(1, "Pubg", "Krafton", "Action", 2018, "Mobile or PC", 120000, 480000, 9.6),
(2, "Asphalt Nitro", "Gamesoft", "Car Racing", 2021, "Mobile or Pc", 220000, 280000, 8.2),
(3, "WWE", "Gamekraft", "Action", 2015, "PC", 230000, 180000, 8.4),
(4, "Gta", "Games2Win", "Action", 2022, "PC", 450000, 550000, 9.8),
(5, "Gully Cricket", "99Games", "Sports", 2017, "Mobile or PC", 180000, 170000, 9.5);

select * from games;
select * from games order by production_cost, rating;
select avg (production_cost) from games;
select * from games where revenue > 200000;
select * from games where rating > 7;
select * from games production_cost > revenue;