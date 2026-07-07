# Write your MySQL query statement below
SELECT
    d.name as Department,
    e.name as Employee,
    e.salary as Salary
FROM Employee e
LEFT JOIN Department d
on e.departmentId = d.id
WHERE e.salary in 
(
    SELECT
        max(salary) FROM Employee 
        WHERE departmentId = e.departmentId
);