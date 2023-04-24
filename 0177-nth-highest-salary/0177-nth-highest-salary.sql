CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
 DECLARE M INT;
SET M=N-1;
  RETURN (
      # Write your MySQL query statement below.
    
select ifnull(( select distinct salary
      from Employee
      order by salary desc 
      limit 1 offset M),null) 
      
  );
END