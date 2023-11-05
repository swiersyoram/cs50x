-- Keep a log of any SQL queries you execute as you solve the mystery.

-- select * from crime_scene_reports where street like 'Humphrey%' and day=28
select license_plate from bakery_security_logs where day=28 and month=7 and hour=10 and minute >=15 and minute <=25
-- select * from interviews where transcript like '%bakery%'
-- select account_number from atm_transactions where atm_location = 'Leggett Street' and transaction_type = 'withdraw' and month=7 and day=28

-- select person_id from bank_accounts where account_number in (select account_number from atm_transactions where atm_location = 'Leggett Street' and transaction_type = 'withdraw' and month=7 and day=28)

select * from people where id in (select person_id from bank_accounts where account_number in (select account_number from atm_transactions where atm_location = 'Leggett Street' and transaction_type = 'withdraw' and month=7 and day=28))
and license_plate in (select license_plate from bakery_security_logs where day=28 and month=7 and hour=10 and minute >=15 and minute <=25)
and passport_number in (select passengers.passport_number from passengers where flight_id=36)

select * from flights where month = 7 and day =29 order by hour

select * from passengers where flight_id=36

select * from phone_calls where caller='(367) 555-5533'

select * from people where phone_number='(375) 555-8161'