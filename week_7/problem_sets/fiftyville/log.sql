-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Find all reports mentioning the case on the day on the street
SELECT id, description FROM crime_scene_reports
WHERE year = 2025
AND month = 7
AND day = 28
AND street = "Humphrey Street";
-- The reports mentioned three interviews with witnesses were conducted
-- Each interview transcript mentions bakery
-- Theft took place at 10:15am

-- Select three interviews conducted on the day mentioning a thief or a theft
SELECT id, name, transcript FROM interviews
WHERE year = 2025
AND month = 7
AND day = 28
AND (transcript LIKE "%theft%"
    OR transcript lIKE "%thief%");
-- Ruth: car in bakery parking lot and to look at security footage
--       AND thief left with car within 10 minutes
-- Eugene: thief withdrew money from ATM on Leggett Street
-- Raymond: thief will take earliest flight out of Fiftyville on 29 July 2025
--          AND requested person on phone to purchase flight ticket
--          AND phone call lasted less than 60 seconds
-- Additional thoughts: suspect could have withdrawn money out of ATM for flight ticket


-- Find all cars that left within 10 minutes of the incident
SELECT license_plate FROM bakery_security_logs
WHERE activity = "exit"
AND year = 2025
AND month = 7
AND day = 28
AND hour = 10
AND minute >= 15
AND minute <= 25
ORDER BY minute ASC;
-- Provided list of suspicious cars the thief could have escaped with

-- Find all accounts that withdrew money on the day of the incident
SELECT account_number FROM atm_transactions
WHERE year = 2025
AND month = 7
AND day = 28
AND transaction_type = "withdraw"
AND atm_location = "Leggett Street";
-- Provided list of suspicious accounts that could be associated with the thief

-- Find all callers and receivers on the day of the incident
SELECT caller, receiver, duration FROM phone_calls
WHERE year = 2025
AND month = 7
AND day = 28
AND duration <= 60
ORDER BY duration;
-- Provided list of suspicious accounts taht could be associated with the thief and accomplice

-- determine the earliest flight on the morning of the day after the incident
SELECT id FROM flights
WHERE origin_airport_id IN (
    SELECT id FROM airports
    WHERE city = "Fiftyville"
)
AND year = 2025
AND month = 7
AND day = 29
ORDER BY hour ASC, minute ASC
LIMIT 1;
-- Returned flight the thief supposedly boarded

-- determine the people who boarded the earliest plane on the day after the incident
SELECT passport_number FROM passengers
WHERE flight_id IN (
    SELECT id FROM flights
    WHERE origin_airport_id IN (
        SELECT id FROM airports
        WHERE city = "Fiftyville"
    )
    AND year = 2025
    AND month = 7
    AND day = 29
    ORDER BY hour ASC, minute ASC
    LIMIT 1;
)
-- Provided passport numbers for people that boarded the flight


-- Collate all information gathered so far to find possible suspect(s)
SELECT name, id FROM people
JOIN bank_accounts ON bank_accounts.person_id = people.id
WHERE bank_accounts.account_number IN (
    SELECT account_number FROM atm_transactions
    WHERE year = 2025
    AND month = 7
    AND day = 28
    AND transaction_type = "withdraw"
    AND atm_location = "Leggett Street"
)
AND people.phone_number IN (
    SELECT caller FROM phone_calls
    WHERE year = 2025
    AND month = 7
    AND day = 28
    AND duration <= 60
    ORDER BY duration
)
AND people.license_plate IN (
    SELECT license_plate FROM bakery_security_logs
    WHERE activity = "exit"
    AND year = 2025
    AND month = 7
    AND day = 28
    AND hour = 10
    AND minute >= 15
    AND minute <= 25
    ORDER BY minute ASC
)
AND people.passport_number IN (
    SELECT passport_number FROM passengers
    WHERE flight_id IN (
        SELECT id FROM flights
        WHERE origin_airport_id IN (
            SELECT id FROM airports
            WHERE city = "Fiftyville"
        )
        AND year = 2025
        AND month = 7
        AND day = 29
        ORDER BY hour ASC, minute ASC
        LIMIT 1
    )
);
-- Narrowed down to one suspect: Bruce
-- Hence, Bruce must be the thief


-- Determine destination of flight
SELECT airports.city FROM airports, flights
WHERE flights.destination_airport_id = airports.id
AND flights.origin_airport_id IN (
    SELECT id FROM airports WHERE city = "Fiftyville"
)
AND flights.year = 2025
AND flights.month = 7
AND flights.day = 29
ORDER BY flights.hour ASC, flights.minute ASC
LIMIT 1;
-- Hence, thief fled to New York City

-- Determine accomplice of thief
SELECT people.name, phone_calls.receiver FROM people, phone_calls
WHERE phone_calls.caller IN (
    SELECT phone_number FROM people WHERE id = 686048
)
AND people.phone_number = phone_calls.receiver
AND phone_calls.duration <= 60
AND phone_calls.year = 2025
AND phone_calls.month = 7
AND phone_calls.day = 28;
-- Hence, the accomplice was Robin
