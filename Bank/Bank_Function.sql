DELIMITER //
DROP FUNCTION IF EXISTS get_loan_lamt //
DROP FUNCTION IF EXISTS count_customer //


create function get_loan_lamt(branch_id int)
returns decimal(10,2)
deterministic 
begin
         declare total_loan decimal(10,2);

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
             from customer
             where bid=branch_id;

             return ifnull(total_customer,0);

end //
SELECT get_loan_lamt(104);
//

select count_customer(103);
//

