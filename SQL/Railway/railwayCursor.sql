DELIMITER //

DROP PROCEDURE IF EXISTS NotConfirmedBookings//
DROP PROCEDURE IF EXISTS reservedBerths//

CREATE PROCEDURE NotConfirmedBookings()
BEGIN
	DECLARE done int DEFAULT 0;
	DECLARE train_id int;
	DECLARE ticket_id int;
	DECLARE sts char(10);
	DECLARE t_date date;
	
	DECLARE book_cursor CURSOR FOR 
		SELECT tno,tcno,status,tdate
		FROM ticket 
		WHERE ticket_date = '2018-07-14' AND status = '_W_';
	DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = 1; 
	
	OPEN book_cursor;
		rloop: LOOP
			FETCH book_cursor INTO train_id, ticket_id, sts, t_date;
			
			IF done THEN
				LEAVE rloop;
			END IF;
			
			SELECT train_id, ticket_id, sts as status, t_date as ticket_date;
		END LOOP;
	CLOSE book_cursor;
END
//

CREATE PROCEDURE reservedBerths(dte date)
BEGIN
	DECLARE done int DEFAULT 0;
	DECLARE total_reserved_berth int;
	
	DECLARE res_berth CURSOR FOR 
		SELECT SUM(no_of_berths)
		FROM ticket
		where ticket_date = dte;
	DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = 1;
	
	OPEN res_berth;
		rloop: LOOP
			FETCH res_berth into total_reserved_berth;
			
			IF done THEN
				LEAVE rloop;
			END IF;
			
			SELECT total_reserved_berth; 
		END LOOP;
	CLOSE res_berth; 
END
//

DELIMITER ;
