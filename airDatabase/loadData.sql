create table AirQualityData (
	measureId integer,
	measureName varchar(256),
	measureType varchar(7),
	stratificationLevel varchar(14),
	stateFips integer,
	stateName varchar(20),
	countyFips int,
	countyName varchar(21),
	reportYear integer,
	value numeric(23,13),
	unit varchar(8),
	unitName varchar(25),
	dataOrigin varchar(17),
	monitorOnly integer
);