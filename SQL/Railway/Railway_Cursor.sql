DELIMITER //
DROP PROCEDURE waiting_booking;
DROP PROCEDURE total_no_berth;

create procedure waiting_booking()
begin
        DECLARE done int DEFAULT 0;
	DECLARE pname varchar(20);
	DECLARE tname varchar(30);
        DECLARE train_status varchar(10);


	DECLARE cur CURSOR FOR SELECT p.passenger_name , t.train_name t1.status FROM passenger p JOIN train t JOIN ticket t1 ON t.train_no=t1.train_no  and  p.passenger_id= t1.passenger_id  WHERE t1.t_date = '2024-08-09';
	DECLARE continue HANDLER FOR SQLSTATE '02000' SET done=1;
	OPEN cur;
	REPEAT
		FETCH cur INTO pname, tname, train_status;
		IF NOT done THEN
			SELECT pname, tname, train_status;
		END IF;
	UNTIL done END REPEAT;
	CLOSE cur;
END //
call waiting_booking;
//

create procedure total_no_berth()
begin
        DECLARE done int DEFAULT 0;
	DECLARE tname varchar(30);
        DECLARE no_of_berth int(10);


	DECLARE cur1 CURSOR FOR SELECT t.train_name , t1.no_of_berths FROM train t JOIN ticket t1 ON t.train_no=t1.train_no  where t1.t_date = '2024-08-09';
	DECLARE continue HANDLER FOR SQLSTATE '02000' SET done=1;
	OPEN cur1;
	REPEAT
		FETCH cur1 INTO tname, no_of_berth;
		IF NOT done THEN
			SELECT tname, no_of_berth;
		END IF;
	UNTIL done END REPEAT;
	CLOSE cur1;
END //


