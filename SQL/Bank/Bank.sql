drop table account;
drop table loan_application;
drop table customer;
drop table branch;
drop view v1;
drop view v2;

create table branch(bid int primary key, brname char(30), brcitty char(10));
desc branch;

create table customer(cno int primary key , cname char(20), caddr char(35), city char(20),bid int , foreign key(bid) references branch(bid));
desc customer;

create table loan_application(lno int primary key, lamtrequired double(10,2), lamtapproved double(10,2), l_date date,cno int,foreign key(cno) references customer(cno),bid int , foreign key(bid) references branch(bid));
desc loan_application;

create table account(acc_no int primary key , acc_type char(10), acc_balance float(8,2),cno int,foreign key(cno) references customer(cno),bid int , foreign key(bid) references branch(bid));
desc account;

insert into branch values(101,'sbi01','Pune'),
                         (102,'sbi05','Dhule'),
                         (103,'houston','Texas'),
                         (104,'sbi61','Mumbai'),
                         (105,'sbi09','Surat');
select * from branch;

insert into customer values(201,'Pratik','lane 16','Pune',101),
                           (202,'Omkar','103 d','Sangli',102),
                           (203,'Yuvraj','lane 17','Mumbai',103),
                           (204,'Sanket','D 48','Nagar',104),
                           (205,'Ganesh','68 colony','Nashik',105);
select * from customer;

insert into loan_application values(301,50000,40000,'2024-06-09',201,101),
                           	   (302,80000,10000,'2023-04-19',202,102),
                           	   (303,4000,3000,'2022-10-06',203,103),
                                   (304,2000,3000,'2021-03-07',204,104),
                                   (305,7000,8000,'2023-05-01',205,105); 
select * from loan_application;

insert into account values(401,'Savings',45646,201,101),
                          (402,'Current',42146,202,102),
                          (403,'Salary',45236,203,103),
                          (404,'Savings',49046,204,104),
                          (405,'Current',44846,205,105);
select * from account;

/* customer name having loan amt > 10000 */
select cname from customer where cno in (select cno from loan_application where lamtrequired > 10000);

/*names of the customers who have loan at sbi01 branch */
select cname,cno,branch.brname from customer join branch on customer.bid = branch.bid where brname = 'sbi01';

/* total loan amount sanctioned by houston branch */
select sum(lamtapproved) as loan_sanctioned from loan_application join branch on branch.bid = loan_application.bid where branch.brname = 'houston';

/* Views */
create view v1 as select customer.cno,customer.cname,customer.caddr,customer.bid as Customer_branch_id,account.acc_no,account.acc_type,account.acc_balance, account.bid as Account_branch_id from customer join account on customer.cno=account.cno;
select * from v1;

create view v2 as select loan_application.lno,loan_application.lamtrequired,loan_application.lamtapproved from loan_application join branch on branch.bid=loan_application.bid where branch.brname='sbi01';
select * from v2;

