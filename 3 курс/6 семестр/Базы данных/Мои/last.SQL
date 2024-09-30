/*
Created: 06.06.2023
Modified: 06.06.2023
Model: PostgreSQL 12
Database: PostgreSQL 12
*/

-- Create tables section -------------------------------------------------

-- Table Publication

CREATE TABLE "Publication"
(
  "ID_Publish" Serial NOT NULL,
  "NamePublish" Character varying(50) NOT NULL
)
WITH (
  autovacuum_enabled=true)
;

ALTER TABLE "Publication" ADD CONSTRAINT "PK_Publication" PRIMARY KEY ("ID_Publish")
;

-- Table Genre

CREATE TABLE "Genre"
(
  "ID_Genr" Serial NOT NULL,
  "NameGenre" Character varying(50) NOT NULL
)
WITH (
  autovacuum_enabled=true)
;

ALTER TABLE "Genre" ADD CONSTRAINT "PK_Genre" PRIMARY KEY ("ID_Genr")
;

-- Table Type_of_literature

CREATE TABLE "Type_of_literature"
(
  "ID_Typelitr" Serial NOT NULL,
  "NameTLitr" Character varying(50) NOT NULL
)
WITH (
  autovacuum_enabled=true)
;

ALTER TABLE "Type_of_literature" ADD CONSTRAINT "PK_Type_of_literature" PRIMARY KEY ("ID_Typelitr")
;

-- Table Author

CREATE TABLE "Author"
(
  "ID_Author" Serial NOT NULL,
  "NameAuthor" Character varying(50) NOT NULL
)
WITH (
  autovacuum_enabled=true)
;

ALTER TABLE "Author" ADD CONSTRAINT "PK_Author" PRIMARY KEY ("ID_Author")
;

-- Table Books

CREATE TABLE "Books"
(
  "ID_Books" Serial NOT NULL,
  "Name_N" Character varying(50) NOT NULL,
  "Rait" Numeric,
  "Place_Publish" Character varying(50),
  "Date_of_Publish" Numeric,
  "Annotation" Text,
  "ID_Typelitr" Integer
)
WITH (
  autovacuum_enabled=true)
;

CREATE INDEX "IX_Relationship6" ON "Books" ("ID_Typelitr")
;

ALTER TABLE "Books" ADD CONSTRAINT "PK_Books" PRIMARY KEY ("ID_Books")
;

-- Table Publish_Books

CREATE TABLE "Publish_Books"
(
  "ID_Publish" Integer NOT NULL,
  "ID_Books" Integer NOT NULL
)
WITH (
  autovacuum_enabled=true)
;

ALTER TABLE "Publish_Books" ADD CONSTRAINT "PK_Publish_Books" PRIMARY KEY ("ID_Publish","ID_Books")
;

-- Table Genre_Books

CREATE TABLE "Genre_Books"
(
  "ID_Genr" Integer NOT NULL,
  "ID_Books" Integer NOT NULL
)
WITH (
  autovacuum_enabled=true)
;

ALTER TABLE "Genre_Books" ADD CONSTRAINT "PK_Genre_Books" PRIMARY KEY ("ID_Genr","ID_Books")
;

-- Table Author_Books

CREATE TABLE "Author_Books"
(
  "ID_Author" Integer NOT NULL,
  "ID_Books" Integer NOT NULL
)
WITH (
  autovacuum_enabled=true)
;

ALTER TABLE "Author_Books" ADD CONSTRAINT "PK_Author_Books" PRIMARY KEY ("ID_Author","ID_Books")
;

-- Table instance

CREATE TABLE "instance"
(
  "ID_instance" Serial NOT NULL,
  "Cost" Money,
  "Date_Purchase" Date NOT NULL,
  "ID_Books" Integer,
  "ID_PlaceBuy" Integer,
  "ID_LibSection" Integer,
  "ID_Users" Integer,
  "ID_Giving" Integer
)
WITH (
  autovacuum_enabled=true)
;

CREATE INDEX "IX_Relationship10" ON "instance" ("ID_Books")
;

CREATE INDEX "IX_Relationship18" ON "instance" ("ID_PlaceBuy")
;

CREATE INDEX "IX_Relationship19" ON "instance" ("ID_LibSection")
;

CREATE INDEX "IX_Relationship23" ON "instance" ("ID_Users")
;

CREATE INDEX "IX_Relationship24" ON "instance" ("ID_Giving")
;

ALTER TABLE "instance" ADD CONSTRAINT "PK_instance" PRIMARY KEY ("ID_instance")
;

-- Table Giving

CREATE TABLE "Giving"
(
  "ID_Giving" Serial NOT NULL,
  "Date_Giv" Date NOT NULL,
  "Date_take" Numeric,
  "ID_Users" Integer
)
WITH (
  autovacuum_enabled=true)
;

CREATE INDEX "IX_Relationship22" ON "Giving" ("ID_Users")
;

ALTER TABLE "Giving" ADD CONSTRAINT "PK_Giving" PRIMARY KEY ("ID_Giving")
;

-- Table Library_sections

CREATE TABLE "Library_sections"
(
  "ID_LibSection" Serial NOT NULL,
  "Section_Name" Character varying(50) NOT NULL,
  "Section_Number" Numeric
)
WITH (
  autovacuum_enabled=true)
;

ALTER TABLE "Library_sections" ADD CONSTRAINT "PK_Library_sections" PRIMARY KEY ("ID_LibSection")
;

-- Table Placebuy

CREATE TABLE "Placebuy"
(
  "ID_PlaceBuy" Serial NOT NULL,
  "Place_B" Character varying(50) NOT NULL
)
WITH (
  autovacuum_enabled=true)
;

ALTER TABLE "Placebuy" ADD CONSTRAINT "PK_Placebuy" PRIMARY KEY ("ID_PlaceBuy")
;

-- Table Users

CREATE TABLE "Users"
(
  "Num_Us" Numeric NOT NULL,
  "ID_Users" Serial NOT NULL,
  "FIO" Character varying(50),
  "Adress" Character varying(50),
  "Place_J" Character varying(50),
  "Phone" Character varying(12)
)
WITH (
  autovacuum_enabled=true)
;

ALTER TABLE "Users" ADD CONSTRAINT "PK_Users" PRIMARY KEY ("ID_Users")
;

-- Create foreign keys (relationships) section -------------------------------------------------

ALTER TABLE "Publish_Books"
  ADD CONSTRAINT "Relationship2"
    FOREIGN KEY ("ID_Books")
    REFERENCES "Books" ("ID_Books")
      ON DELETE NO ACTION
      ON UPDATE NO ACTION
;

ALTER TABLE "Genre_Books"
  ADD CONSTRAINT "Relationship3"
    FOREIGN KEY ("ID_Genr")
    REFERENCES "Genre" ("ID_Genr")
      ON DELETE NO ACTION
      ON UPDATE NO ACTION
;

ALTER TABLE "Genre_Books"
  ADD CONSTRAINT "Relationship4"
    FOREIGN KEY ("ID_Books")
    REFERENCES "Books" ("ID_Books")
      ON DELETE NO ACTION
      ON UPDATE NO ACTION
;

ALTER TABLE "Publish_Books"
  ADD CONSTRAINT "Relationship1"
    FOREIGN KEY ("ID_Publish")
    REFERENCES "Publication" ("ID_Publish")
      ON DELETE NO ACTION
      ON UPDATE NO ACTION
;

ALTER TABLE "Books"
  ADD CONSTRAINT "Relationship6"
    FOREIGN KEY ("ID_Typelitr")
    REFERENCES "Type_of_literature" ("ID_Typelitr")
      ON DELETE NO ACTION
      ON UPDATE NO ACTION
;

ALTER TABLE "Author_Books"
  ADD CONSTRAINT "Relationship7"
    FOREIGN KEY ("ID_Author")
    REFERENCES "Author" ("ID_Author")
      ON DELETE NO ACTION
      ON UPDATE NO ACTION
;

ALTER TABLE "Author_Books"
  ADD CONSTRAINT "Relationship8"
    FOREIGN KEY ("ID_Books")
    REFERENCES "Books" ("ID_Books")
      ON DELETE NO ACTION
      ON UPDATE NO ACTION
;

ALTER TABLE "instance"
  ADD CONSTRAINT "Relationship10"
    FOREIGN KEY ("ID_Books")
    REFERENCES "Books" ("ID_Books")
      ON DELETE NO ACTION
      ON UPDATE NO ACTION
;

ALTER TABLE "instance"
  ADD CONSTRAINT "Relationship18"
    FOREIGN KEY ("ID_PlaceBuy")
    REFERENCES "Placebuy" ("ID_PlaceBuy")
      ON DELETE NO ACTION
      ON UPDATE NO ACTION
;

ALTER TABLE "instance"
  ADD CONSTRAINT "Relationship19"
    FOREIGN KEY ("ID_LibSection")
    REFERENCES "Library_sections" ("ID_LibSection")
      ON DELETE NO ACTION
      ON UPDATE NO ACTION
;

ALTER TABLE "Giving"
  ADD CONSTRAINT "Relationship22"
    FOREIGN KEY ("ID_Users")
    REFERENCES "Users" ("ID_Users")
      ON DELETE NO ACTION
      ON UPDATE NO ACTION
;

ALTER TABLE "instance"
  ADD CONSTRAINT "Relationship23"
    FOREIGN KEY ("ID_Users")
    REFERENCES "Users" ("ID_Users")
      ON DELETE NO ACTION
      ON UPDATE NO ACTION
;

ALTER TABLE "instance"
  ADD CONSTRAINT "Relationship24"
    FOREIGN KEY ("ID_Giving")
    REFERENCES "Giving" ("ID_Giving")
      ON DELETE NO ACTION
      ON UPDATE NO ACTION
;

