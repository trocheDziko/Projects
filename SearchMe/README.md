As commit message says it's just simple search engine using trees write in C++ (and in Polish ; ))
How does it work?
When you run it and start writing word which is in dictionary (Dictionary/slownik.txt) it gives you all word which starts wit letters you wrote.

E.g. if you start typing a word "carpet" and in dictoinary you have words (starting with 'c'): cat, car, castle, cuba, comics, carry, cause, call, carpenter and carpet, you will see those results for each letters:

Type: c
Results: cat, car, castle, cuba, comics, carry, cause, call, carpenter, carpet

Type: ca
Results: cat, car, castle, carry, cause, call, carpenter, carpet

Type: car
Results: car, carry, carpenter, carpet

Type: carp
Results: carpenter, carpet

And so on. :)
