Consider 

1. What is bipolar disorder? 
2. What do bats eat? 
3. What is the PH scale? 

Question 1 could belong to definition or disease medicine; 
Question 2 could belong to food, plant or animal; 
And Question 3 could be a numeric value or a definition. 

Question classification algorithm classifies whether a given question pertains to the class, abbrevation, 
entity, plant, sport, substance, definition, date etc.

Overall there are 6 coarse classes and 50 fine classes:

Coarse classes:			ABBREVATION, ENTITY,  DESCRIPTION, HUMAN, LOCATION, NUMERIC

Fine classes within coarse classes:
ABBREVATION -> {abbrevation, ..}
ENTITY -> {animal, body, color, plant, product, religion, substance, technique, term, ..}
DESCRIPTION -> {definition, description, manner, reason}
HUMAN -> {group, individual, title, ..}
LOCATION -> {city, country, mountain, ..}
NUMERIC -> {code, count, distance, order, percent, ...}

In the original paper referenced below, the classification took place in two stages, viz. 
classifiy into coarse class then into fine class. Our approach classifies it directly into
fine classes thanks to the use of Recurrent Neural Network (RNN).

Also, thanks to Denny Britz and WILDML as well as Roozbeh Shirvani and Ram Hari Dahal.

Referece:

Li, Xin, and Dan Roth. "Learning question classifiers." Proceedings of the 19th international conference on Computational linguistics-Volume 1. Association for Computational Linguistics, 2002.