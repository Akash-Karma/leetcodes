# Write your MySQL query statement below
SELECT(
    SELECT
    salary FROM Employee 
    GROUP BY salary
    ORDER BY salary desc
    LIMIT 1
    OFFSET 1
) as SecondHighestSalary;