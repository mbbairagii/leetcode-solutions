# Write your MySQL query statement below
select w.id 
from Weather w
join Weather y
on datediff(w.recordDate,y.recordDate)=1
where w.temperature>y.temperature;