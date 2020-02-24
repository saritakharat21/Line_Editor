#pragma once
#include "pch.h"
#include <iostream>
#include<conio.h>
#include<list>
#include<string>
#include<sstream>
#include<fstream>
using namespace std;


class LineEditor
{
public:
	int lineNo;
	//list<string> words;
	string line;

	LineEditor();
	int readFile(list<LineEditor>*,string);

	//display functions
	void display();
	void displayFile(list<LineEditor>);
	void displayTwelve(list<LineEditor>,int);
	void displayTentotwenty(list<LineEditor>,int,int,int);

	//find function
	void findWord(list<LineEditor>*);

	//goto lineno function
	void gotoLine(list<LineEditor>, int);

	//add line function
	void addLine(list<LineEditor>*, int);

	//delete lines function
	void deleteLines(list<LineEditor>*,int,int);

	//append data to file
	void appendLines(list<LineEditor>*,int);

	//save function
	void saveFile(list<LineEditor>,string);
};