-- 12. Titles of all of movies in which both Jennifer Lawrence and Bradley Cooper starred
SELECT DISTINCT movies.title
FROM movies
JOIN stars ON stars.movie_id = movies.id
JOIN people on stars.person_id = people.id
WHERE people.name IN ('Jennifer Lawrence', 'Bradley Cooper')
GROUP BY movies.id, movies.title
HAVING COUNT(DISTINCT people.id) = 2;


