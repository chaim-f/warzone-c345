## Following the format from http://domination.sourceforge.net/makemaps.shtml

[continents]
North-America 6 yellow <~~ name of the continent (try keep them in that order if you are doing a map of the "real world" as then the missions work. The number is the army value, and the color does totally nothing


[countries]
1 Alaska 1 44 83 <~~ the first number is the number of the country (they do have to be in order) the next one is what continent it belongs to. the other two numbers are the x and y co-ordinates of the circle that will be put on that country

[borders]
1 2 3 38 <~~ the first number is the number of the country (need to be in order here as well I think) and the other numbers that follow are what countries that country is adjacent too

```
i(int):
	continent index
name(string):
	continent name
bunos(int):
	continent bunos
		
Continent c = Continent(i, name, bunos);
```
```
i(int):
	territory index or the number of the country
name(string):
	territory name or country name
continent(Continent):
	what continent it belongs to
adjacencies(list<int>):
	borders (what countries that country or territory is adjacent to)
	
Territory t = Territory(i, name, continent, adjacencies);
```
```c++
Continent c = Continent(1, "North-America", 6);
Territory alaska = Territory(1, "Alaska", c, {2,3,38})
```