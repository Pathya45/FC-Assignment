DELIMITER //
DROP TRIGGER IF EXISTS arrival_time_validation//
DROP TRIGGER IF EXISTS status_update//


CREATE TRIGGER arrival_time_validation
BEFORE INSERT ON train
FOR EACH ROW
BEGIN
	DECLARE dummy int;
	IF NEW.arrival_time > NEW.depart_time THEN
		SELECT 'Arrival time must be less than departure time' into dummy FROM train;
	END IF;
END
//

CREATE TRIGGER status_update
BEFORE UPDATE ON ticket
FOR EACH ROW
BEGIN
	DECLARE dummy int;
	DECLARE messageText varchar(255);
	SET messageText = CONCAT('Changing status for ticket ', OLD.ticket_no, ' from ', OLD.status, ' to ', NEW.status);
	
	SELECT messageText into dummy FROM ticket;
END
//

DELIMITER ;

insert into train values(106, 'Delhi Express', '08:06:03', '09:05:06', 'Kolhapur', 'Pune', 10, 98);

update ticket set status = 'w' where ticket_no = 302;
