select title from movies where id in (select s1.movie_id from stars s1 join stars s2 on s1.movie_id = s2.movie_id
where s1.person_id = (select id  from people where name='Bradley Cooper')
and s2.person_id = (select id  from people where name='Jennifer Lawrence'))