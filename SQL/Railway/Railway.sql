drop table ticket;
drop table passenger;
drop table train;
drop view v3;
drop view v4;

create table train(train_no int primary key, train_name varchar(20), depart_time timestamp, arrival_time timestamp, source_stn varchar(20), dest_stn varchar(20), no_of_res_bogies int , bogie_capacity int);
desc train;

create table passenger(passenger_id int primary key,passenger_name varchar(20), address varchar(30), age int, gender char);
desc passenger;

create table ticket(train_no int , passenger_id int , ticket_no int, primary key(train_no, passenger_id, ticket_no), bogie_no int , no_of_berths int , t_date date, ticket_amt decimal(7,2), status char check(status ='w' OR status='c'),foreign key(passenger_id) references passenger(passenger_id), foreign key(train_no) references train(train_no));
desc ticket;

insert into train values(101,'Demo Express','12:06:09','09:02:09','Pune','Ladakh',10,98),
                        (102,'Duranto Express','09:03:04','09:02:03','Mumbai','Pune',08,90),
                        (103,'Delhi Express','09:03:02','09:09:09','Delhi','Washi',06,80),
                        (104,'Shahu Express','08:06:09','08:08:08','Pune','Sangli',11,40),
                        (105,'Kokan Express','07:06:29','07:07:07','Shimla','Satara',12,100);
select * from train;

insert into passenger values(201,'Sanket','Pune',38,'M'),
                            (202,'Yuvraj','Lonavala',39,'M'),
                            (203,'Sonali','Vashi',20,'F'),
                            (204,'Ganesh','Mumbai',48,'M'),
                            (205,'Shravani','Jaipur',32,'F');

select * from passenger; 

insert into ticket values(101,201,301,08,17,'2024-08-09',456,'w'),
                         (102,202,302,09,97,'2024-11-09',454,'c'),
                         (103,203,303,10,18,'2024-12-04',456,'c'),
                         (104,204,304,09,27,'2024-07-05',46,'w'),
                         (105,205,305,04,67,'2024-02-02',450,'c'); 
select * from ticket;

/* information about the availability of trains between mumbai and pune */
select * from train where source_stn = 'Mumbai' and dest_stn = 'Pune';

/* names of all the trains which start from pune */
select train_name from train where source_stn= 'Pune';

/* count number of passangers for duranto express */
select COUNT(passenger_id) as Passangers_Count from ticket join train on train.train_no = ticket.train_no where train.train_name = 'Duranto Express';

/* views */
create view v3 as
select passenger.passenger_id,passenger.passenger_name from passenger
join ticket on ticket.passenger_id=passenger.passenger_id
join train on train.train_no=ticket.train_no
where ticket.t_date='2024-07-05'and train.train_name='Mumbai Express';
select * from v3;

create view v4 as select passenger.passenger_name from passenger
join ticket on ticket.passenger_id=passenger.passenger_id
join train on train.train_no=ticket.train_no
where train.train_name='duranto express'and ticket.status='c' and ticket.t_date='2024-11-09';
select * from v4;
