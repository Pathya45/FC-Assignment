DELIMITER //
DROP TRIGGER IF EXISTS acc_bal//
DROP TRIGGER IF EXISTS loan_validate//

CREATE TRIGGER acc_bal
BEFORE UPDATE ON account
FOR EACH ROW
BEGIN
	DECLARE dummy int;
	IF NEW.acc_balance < 1000 THEN
		SELECT 'Account balance cannot be less than 1000' into dummy FROM account WHERE OLD.acc_no = NEW.acc_no;
	END IF;
END
//

CREATE TRIGGER loan_validate
BEFORE INSERT ON loan_application
FOR EACH ROW
BEGIN
	DECLARE dummy int;
	IF NEW.lamtapproved > NEW.lamtrequired THEN
		SELECT 'Loan approved should be less than or equal to loan required' into dummy FROM loan_application;
	END IF; 
END
//

DELIMITER ;

update account set acc_balance = 500 where acc_no = 403;


insert into loan_application(lamtrequired, lamtapproved) values(400000, 500000);
