# Please write a DELETE statement and DO NOT write a SELECT statement.
# Write your MySQL query statement below
delete a.* from Person as a inner join Person as b on a.email=b.email where a.id>b.id;