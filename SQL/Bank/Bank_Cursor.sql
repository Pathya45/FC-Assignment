DELIMITER //
DROP PROCEDURE GetCustomerWithLoan;
DROP PROCEDURE add_interest;


CREATE PROCEDURE GetCustomerWithLoan()
BEGIN
	DECLARE done int DEFAULT 0;
	DECLARE cno int;
	DECLARE cname varchar(255);

	DECLARE cus_cursor CURSOR FOR
		SELECT customer.cno, customer.cname
		FROM customer JOIN loan_application on loan.cno = customer.cno JOIN branch on branch.bid = loan.bid
		WHERE loan.lamtapproved BETWEEN 10000 AND 30000
		AND branch.brname = 'houston';

	DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = 1;
	
	OPEN cus_cursor;
	
	rloop: LOOP
		FETCH cus_cursor into cno, cname;
		IF done THEN
			LEAVE rloop;
		END IF;

		SELECT cno, cname;
	END LOOP;

	CLOSE cus_cursor;
END
//


CALL print_customer_details();
//


CREATE PROCEDURE add_interest()
BEGIN
	DECLARE done int DEFAULT 0;
	DECLARE cname varchar(20);
	DECLARE balance double(8,2);
        DECLARE interest_4_percent float(9,2);

	DECLARE cur1 CURSOR FOR SELECT c.cname, a.acc_balance ,(a.acc_balance * 0.4)FROM customer c JOIN account a ON a.cno = c.cno   WHERE a.acc_balance > 49000;
	DECLARE continue HANDLER FOR SQLSTATE '02000' SET done=1;
	OPEN cur1;
	REPEAT
		FETCH cur1 INTO cname, balance,interest_4_percent;
		IF NOT done THEN
			SELECT cname, balance ,interest_4_percent;
		END IF;
	UNTIL done END REPEAT;
	CLOSE cur1;
END //

call add_interest();
//


