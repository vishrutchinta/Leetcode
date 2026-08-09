# Write your MySQL query statement below
SELECT DISTINCT 
    p.product_id,
    IFNULL(ROUND(
        (SELECT SUM(p2.price * u.units) 
         FROM Prices p2, UnitsSold u 
         WHERE p2.product_id = p.product_id 
           AND u.product_id = p.product_id 
           AND u.purchase_date BETWEEN p2.start_date AND p2.end_date)
        / 
        (SELECT SUM(u.units) 
         FROM UnitsSold u 
         WHERE u.product_id = p.product_id)
    , 2), 0) AS average_price
FROM Prices p;