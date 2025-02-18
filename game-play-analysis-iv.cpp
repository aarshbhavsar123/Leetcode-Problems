# Write your MySQL query statement below
select ROUND(COUNT(*)/(select count(distinct player_id) as dis from activity),2) as FRACTION from (select player_id,min(event_date) as med from activity group by player_id ) as a join activity b on (a.player_id=b.player_id and b.event_date = DATE_ADD(a.med, INTERVAL 1 DAY)) 

