DELIMITER //
DROP FUNCTION get_total_loan_amount //
DROP FUNCTION IF EXISTS count_customer //

create function get_total_loan_amount(branch_id int)
returns decimal(15,2)
deterministic
begin
	declare total_loan decimal(15,2);

	select sum(lamtapproved) into total_loan
	from loan_application
	where bid = branch_id;
	 
	return ifnull(total_loan,0);
end //

create function count_customer(branch_id int)
returns int
deterministic
begin
	declare total_customer int;

	select count(cno) into total_customer
	where bid = branch_id;

	return ifnull(total_customer,0);
end //

select get_total_loan_amount (104) ;//

