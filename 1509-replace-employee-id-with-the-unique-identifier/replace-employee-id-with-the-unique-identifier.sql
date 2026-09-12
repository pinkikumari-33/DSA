# Write your MySQL query statement below
select a.unique_id, b.name from
employeeUNI as a 
right join employees as b
on a.id = b.id;