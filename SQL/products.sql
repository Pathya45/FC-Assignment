drop table products;

create table products(product_ID int primary key, product_Code char(10), name varchar(20), quantity int, price decimal(10,2));

insert into products values(1, "PB45", "Pen", 50, 5.5),
(2, "HP99", "Bat", 10, 90.5),
(3, "VK18", "Balls", 20, 10.5),
(4, "PS7", "Stumps", 10, 15.5),
(5, "SY13", "Shoes", 25, 40.5);

select * from products;
select product_Code, price from products order by price desc;
select * from products where quantity > 10;
select * from products where product_Code like "P%";
select sum(price) from products where product_Code="Pen";
select * from products order by price desc limit 2;
update products set price = price*1.1;