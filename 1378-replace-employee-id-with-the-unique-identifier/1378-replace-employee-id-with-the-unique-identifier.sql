# Write your MySQL query statement below
select e.name, y.unique_id
from Employees e
left join EmployeeUNI y
on e.id=y.id;