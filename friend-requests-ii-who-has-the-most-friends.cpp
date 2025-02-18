WITH UserRequests AS (
    SELECT 
        COALESCE(a.requester_id, b.accepter_id) AS userid,
        COALESCE(a.count, 0) + COALESCE(b.count, 0) AS total_requests
    FROM (
        SELECT requester_id, COUNT(requester_id) AS count 
        FROM RequestAccepted 
        GROUP BY requester_id
    ) AS a
    FULL OUTER JOIN (
        SELECT accepter_id, COUNT(accepter_id) AS count 
        FROM RequestAccepted 
        GROUP BY accepter_id
    ) AS b
    ON a.requester_id = b.accepter_id
)
SELECT userid AS id, total_requests AS num
FROM UserRequests
WHERE total_requests = (SELECT MAX(total_requests) FROM UserRequests);
