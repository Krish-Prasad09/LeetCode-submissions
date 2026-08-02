# Write your MySQL query statement below
SELECT m.NAME FROM Employee as e INNER JOIN Employee as m ON e.managerId=m.id 
GROUP BY e.managerId  HAVING count(*)>=5  ;