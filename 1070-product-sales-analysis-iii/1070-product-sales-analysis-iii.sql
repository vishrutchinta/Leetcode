# Write your MySQL query statement below
-- select distinct product_id as product_id, min(year) as first_year,quantity,price from Sales group by product_id;

SELECT product_id, year AS first_year, quantity, price
FROM Sales
WHERE (product_id, year) IN (
    SELECT product_id, MIN(year)
    FROM Sales
    GROUP BY product_id
);