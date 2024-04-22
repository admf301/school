-- NEEDS DATA INSERTED

-- USER INSERTS

INSERT INTO USER
    VALUES('TheOne', '1234567890');

INSERT INTO USER
    VALUES('Kyle', '7732025862');

INSERT INTO USER
    VALUES('Jessica', '7084568673');

INSERT INTO USER
    VALUES('WhiteWolf', '8064563592');

INSERT INTO USER
    VALUES('NotBatman', '2028972894');

-- STORE INSERTS
INSERT INTO STORE
    (NAME, ADDRESS)
    VALUES('Best Buy', '123 Cauliflower st, Jeans, IL'),
    ('Gamestop', '342 Carrots dr, Kale, IL');

-- Employees
INSERT INTO EMPLOYEES
    (USERNAME, STORE_ID, OWNER)
    VALUES('Kyle', 1, 1),
    ('Jessica', 2, 1);

-- PRODUCT DETAILS

INSERT INTO INVENTORY
    (PROD_NAME, PRICE)
    VALUES('GtaV', 19.99),
    ('Hades', 19.99),
    ('Returnal', 19.99),
    ('Spiderman', 14.99),
    ('Bloodborne', 9.99),
    ('Uncharted', 9.99),
    ('Injustice', 4.99),
    ('Witcher3', 19.99),
    ('Persona5', 19.99),
    ('Skyrim', 19.99),
    ('LastOfUs', 9.99),
    ('LastOfUs2', 19.99),
    ('GodOfWar', 39.99),
    ('KingdomHearts3', 29.99),
    ('EldenRing', 59.99),
    ('PlanetCoaster', 29.99),
    ('MK11', 19.99),
    ('LegoStarWars', 59.99),
    ('FF7Remake', 19.99),
    ('SlimeRancher', 19.99);

--Store Inventory
INSERT INTO STORE_INVENTORY
    (STORE_ID, PROD_ID, STOCK)
    VALUES(2, 1, 5),
    (2, 2, 5),
    (1, 3, 5),
    (2, 3, 5),
    (2, 4, 5),
    (1, 5, 5),
    (1, 6, 5),
    (2, 7, 5),
    (2, 8, 5),
    (2, 9, 5),
    (1, 10, 5),
    (2, 11, 5),
    (1, 12, 5),
    (2, 13, 5),
    (1, 14, 5),
    (2, 15, 5),
    (1, 16, 5),
    (2, 16, 5),
    (2, 17, 5),
    (2, 18, 5),
    (1, 19, 5),
    (2, 20, 5);


--ORDERS
INSERT INTO ORDERS
    (ORDER_ID, USERNAME, PAID_AMOUNT, TRACK_NUM, ORDSTATUS, CREDNUM, CVC, EXPDATE, ADDR)
    VALUES(1, 'Kyle', 34.98, 12345, 'processing', '9999111122226666', 123, '11/25', '123 Derrek rd, Selly, IL'),
    (2, 'Jessica', 9.99, 23456, 'shipped', '7777888833331111', 321, '04/24', '432 Ferris rd, Track, IL'),
    (3, 'NotBatman', 39.98, 56432, 'received', '555533432222777', 546, '05/25', '890 Valet rd, J, IL');

--Order_Inventory
INSERT INTO ORDER_INVENTORY
    (ORDER_ID, PROD_ID, STORE_ID)
    VALUES(1, 1, 2),
    (1, 4, 2),
    (2, 5, 1),
    (3, 2, 2),
    (3, 3, 1);

--Carts
INSERT INTO SHOPPING_CART
    (USERNAME)
    VALUES('TheOne'),
    ('Kyle'),
    ('Jessica'),
    ('WhiteWolf'),
    ('NotBatman');
