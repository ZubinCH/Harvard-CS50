-- 11. Titles of the five highest rated movies (in order) that Chadwick Boseman starred in, starting with the highest rated
SELECT DISTINCT movies.title FROM movies, people, ratings, stars
WHERE movies.id = ratings.movie_id
AND stars.person_id = people.id
AND stars.movie_id = movies.id
AND people.name = "Chadwick Boseman"
ORDER BY ratings.rating DESC
LIMIT 5;

