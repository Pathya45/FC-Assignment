drop table ticket;
drop table passenger;
drop table train;

create table train(train_no int primary key, train_name varchar(20), depart_time time, arrival_time time, source_stn varchar(20), dest_stn varchar(20), no_of_res_bogies int , bogie_capacity int);
desc train;

create table passenger(passenger_id int primary key,passenger_name varchar(20), address varchar(30), age int, gender char);
desc passenger;

create table ticket(train_no int , passenger_id int , ticket_no int, primary key(train_no, passenger_id, ticket_no), bogie_no int , no_of_berths int , t_date date, ticket_amt decimal(7,2), status char check(status ='w' OR status='c'),foreign key(passenger_id) references passenger(passenger_id), foreign key(train_no) references train(train_no));
desc ticket;

insert into train values(101,'rajdhani','12:00','04:30','mumbai','pune',10,98),
                        (102,'demu express','09:30','04:00','kolhapur','mumbai',08,90),
                        (103,'duronto express','09:45','05:00','miraj','pune',06,80),
                        (104,'shatabdi','08:06','01:10','mumbai','pune',11,40),
                        (105,'kokan express','07:00','10:10','pune','ratanagiri',12,100);
select * from train;

insert into passenger values(201,'aviral','pune',38,'m'),
                            (202,'aditya','satara',39,'m'),
                            (203,'nisha','vashi',18,'f'),
                            (204,'monty','mumbai',48,'m'),
                            (205,'shanaya','jaipur',32,'f');
select * from passenger; 

insert into ticket values(101,201,301,08,17,'2024-08-09',456,'w'),
                         (101,203,302,09,97,'2024-11-09',454,'c'),
                         (102,204,303,10,18,'2024-12-04',456,'c'),
                         (104,205,304,09,27,'2024-07-05',46,'w'),
                         (103,202,305,04,67,'2024-02-02',450,'c'),
                         (103,202,306,04,67,'2024-02-02',450,'c'),
                         (103,202,307,04,67,'2024-02-02',450,'c');
                       
select * from ticket;

select * from train where source_stn='mumbai' and dest_stn='pune';

select * from train where source_stn='pune';

select count(passenger_id) from ticket where train_no = (select train_no from train where train_name='duronto express');
