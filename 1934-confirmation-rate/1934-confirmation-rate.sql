# Write your MySQL query statement below
SELECT 
-- s.user_id, as confirmation_rate 
s.user_id as user_id,
ROUND(
    IFNULL(
        SUM(action = 'confirmed') / COUNT(c.action),
        0
    ),
    2
) AS confirmation_rate
FROM Signups as s 
LEFT JOIN Confirmations as c ON s.user_id=c.user_id 
GROUP BY 
s.user_id
;