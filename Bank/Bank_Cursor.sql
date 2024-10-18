DELIMITER //
DROP PROCEDURE print_customer_details;
DROP PROCEDURE add_intrest;

CREATE PROCEDURE print_customer_details()
BEGIN
	DECLARE done int DEFAULT 0;
	DECLARE cname varchar(20);
	DECLARE lamt double(8,2);

	DECLARE cur CURSOR FOR SELECT c.cname, l.lamtapproved FROM customer c JOIN loan_application l ON l.cno = l.cnoc.cno JOIN branch b ON l.bid = b.bid WHERE l.lamtapproved > 20000 and l.lamtapproved < 50000 and b.brname = 'sbi01';

	DECLARE continue HANDLER FOR SQLSTATE  02000 SET done=1;
	OPEN cur;
	REPEAT
		FETCH cur INTO cname, lamt;
		IF NOT done THEN
			SELECT cname, lamt AS lamtapproved;
		END IF;
	UNTIL done END REPEAT;
	CLOSE cur;
END //

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

DELIMITER ;

CALL print_customer_details();

CALL add_interest();


