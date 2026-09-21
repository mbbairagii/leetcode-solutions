SELECT 
    p.product_id,
    ROUND(
        coalesce(
            SUM(u.units * p.price) / SUM(u.units), 0
        ), 2
    ) AS average_price
FROM Prices p
left JOIN UnitsSold u
    ON p.product_id = u.product_id
    and u.purchase_date between p.start_date and p.end_date
GROUP BY p.product_id;