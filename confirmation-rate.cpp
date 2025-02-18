# Write your MySQL query statement below
SELECT user_id,ROUND(COUNT(case when action='confirmed' then 1 end)/(COUNT(case when action='timeout' then 1 end)+COUNT(case when action='confirmed' then 1 end)),2) as confirmation_rate from confirmations
group by user_id
union (select user_id,0.0 from signups where user_id not in (select distinct user_id from confirmations))