-- 13. Names of all people who starred in a movie in which Kevin Bacon also starred
SELECT DISTINCT people.name FROM people, movies, stars
WHERE movies.id IN (
    SELECT movie_id FROM stars, people
    WHERE people.id = stars.person_id
    AND people.name = "Kevin Bacon"
    AND people.birth = 1958
)
AND NOT people.name = "Kevin Bacon"
AND movies.id = stars.movie_id
AND stars.person_id = people.id;