# Write your MySQL query statement below
SELECT a.name as Customers 
FROM Customers a LEFT JOIN 
Orders b
ON a.id = b.customerId
WHERE b.customerId is NULL;