-- 9. Names of all people who starred in a movie released in 2004, ordered by birth year
SELECT DISTINCT people.id, people.name FROM movies, stars, people
WHERE stars.movie_id = movies.id
AND stars.person_id = people.id
AND movies.year = 2024
ORDER BY people.birth
