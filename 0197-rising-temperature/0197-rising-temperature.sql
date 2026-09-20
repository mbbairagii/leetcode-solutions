# Write your MySQL query statement below
select w.id 
from Weather w
join Weather u
where datediff(w.recordDate, u.recordDate)=1
and w.temperature>u.temperature;
