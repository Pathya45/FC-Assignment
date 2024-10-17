drop table sales;

create table sales(sale_Id int primary key, product_Id int, quantity_Sold int, sale_Date date, total_Price decimal(10,2));

insert into sales values(1, 011, 5, "2024-01-03", 57.5),
(2, 012, 1, "2024-01-03", 78.9),
(3, 013, 6, "2024-02-03", 124.4),
(4, 014, 9, "2024-09-03", 96.6),
(5, 015, 3, "2024-11-03", 112.7);

select * from sales;
select sale_Id, sale_Date from sales;
select * from sales where total_Price > 100;
select sale_Id, total_Price from sales where sale_Date = "2024-01-03";
select sale_Id, product_Id, total_Price from sales where quantity_Sold > 4;
select sale_Id, total_Price from sales order by total_Price desc;
select total_Price from sales where total_Price between 100 and 500;