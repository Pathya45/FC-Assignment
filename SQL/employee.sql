drop table employe;

create table employee(emp_Id int primary key, field_Name varchar(20), emp_Name varchar(20), b_Date date, joining_Date date, salary int);

insert into employee values(1, "FrontEnd Developer", "Omkar", "2003-07-31", "2021-05-01", 48000),
(2, "Tester", "Yuvraj", "2003-04-11", "2022-02-01", 20000),
(3, "UI Designer", "Ganesh", "2003-11-16", "2020-08-16", 35000),
(4, "BackEnd Developer", "Sanket", "2002-07-31", "2021-05-01", 46000),
(5, "Marketing", "Pratik", "2002-12-22", "2021-11-01", 40000);

select * from employee;
alter table employee add department varchar(20);
alter table employee modify column salary int;
alter table employee add constraint unique_name unique(name);
