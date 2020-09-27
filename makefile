text_inserter: text_inserter.c
	gcc -Wall -Werror -Wpedantic -std=gnu99 text_inserter.c -o text_inserter

con_def: con_def.cpp
	g++ -Wall -Werror -Wpedantic -O3 con_def.cpp -o con_def
