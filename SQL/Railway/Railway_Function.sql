DELIMITER //
Drop function if exists total_ticket_amount //
Drop function if exists get_berth_reserved_count //

create function total_ticket_amount(train_name varchar(20), train_date date)
returns decimal(7,2)
deterministic
begin
	declare total_ticket_amt decimal(7,2);

	select sum(ticket_amt) into total_ticket_amt
	from ticket
	join train on train.train_no = ticket.train_no
	where train.train_name = train_name and ticket.t_date = train_date;

	return ifnull(total_ticket_amt,0);
end //

create function get_berth_reserved_count()
returns int
deterministic
begin 
	declare total_berth_reserved int;

	select sum(no_of_berths) as total_berth_reserved into total_berth_reserved
	from ticket
	join train on train.train_no = ticket.train_no
	where train.train_name = 'kokan express' and ticket.t_date = '2024-02-02';

	return ifnull(total_berth_reserved,0);
end //

select total_ticket_amt ('Mumbai express', '2024-07-05'); //

select get_berth_reserved_count(); //
