-- author: opat3
-- mailto: opat3@wp.pl

-- to execute in sqlite3, type:
-- .read <filename>

--==================================================
-- publisher
--==================================================
--This table will hold data about comics publishers
-- logo - path to logo image
CREATE TABLE publisher(
    id          INTEGER PRIMARY KEY ASC,
    name        TEXT,
    logo        TEXT,
    webpage     TEXT,
    notes       TEXT);

INSERT INTO publisher (name, webpage) VALUES ('DC Comics', 'www.marvel.com');
INSERT INTO publisher (name, webpage) VALUES ('Marvel Comics', 'www.dccomics.com');
INSERT INTO publisher (name, webpage) VALUES ('Dark Horse', 'www.darkhorse.com');

--==================================================
-- title
--==================================================
CREATE TABLE title(
    id          INTEGER PRIMARY KEY ASC,
    name        TEXT,
    publisher   INTEGER,
    notes       TEXT,
    FOREIGN     KEY(publisher) REFERENCES publisher(id));

INSERT INTO title (name, publisher) VALUES ('Action Comics', 1);
INSERT INTO title (name, publisher) VALUES ('The Amazing Spider-man', 2);

--==================================================
-- artist
--==================================================
CREATE TABLE artist(
    id          INTEGER PRIMARY KEY ASC,
    name        TEXT,
    surname     TEXT,
    notes       TEXT);

INSERT INTO artist (name, surname) VALUES ('Stan', 'Lee');
INSERT INTO artist (name, surname) VALUES ('Alex', 'Ross');
INSERT INTO artist (name, surname) VALUES ('Jim', 'Lee');

--==================================================
-- issue
--==================================================
CREATE TABLE issue(
    id          INTEGER PRIMARY KEY ASC,
    title       INTEGER,
    number      INTEGER,
    cover       TEXT,
    scenario    INTEGER,
    penciler    INTEGER,
    pages       INTEGER,
    price       INTEGER,
    payed       INTEGER,
    notes       TEXT,
    FOREIGN     KEY(title) REFERENCES title(id),
    FOREIGN     KEY(scenario) REFERENCES artist(id),
    FOREIGN     KEY(penciler) REFERENCES artist(id));

--==================================================
-- tradepaperback
--==================================================
CREATE TABLE tradepaperback(
    id          INTEGER PRIMARY KEY ASC,
    title       TEXT,
    pages       INTEGER,
    price       INTEGER,
    payed       INTEGER,
    issues      TEXT);

