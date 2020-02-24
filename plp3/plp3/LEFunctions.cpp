#include "pch.h"
#include "LEHeader.h"

LineEditor::LineEditor()
{
	lineNo = 0;
}

int LineEditor::readFile(list<LineEditor>*l,string filename)
{
	
	LineEditor le;
	ifstream in;
	int count=0;
	
	in.open(filename);
	if (!in.is_open())
	{
		cout << "\nFile not found";
	}
	else
	{
		while (getline(in, le.line))
		{
			le.lineNo++;
			(*l).push_back(le);
		}
		count = le.lineNo;
		in.close();
	}
	
	return count;
}

void LineEditor::display()
{
	list<string>::iterator it;
	cout <<" "<< lineNo<<" "<<line;
}

void LineEditor::displayFile(list<LineEditor>l)
{
	LineEditor le;
	list<LineEditor>::iterator it;
	for (it = l.begin(); it != l.end(); it++)
	{
		(*it).display();
		cout << "\n";
	}
	
}

void LineEditor::displayTwelve(list<LineEditor>l,int count)
{
	LineEditor le;
	char ch;
	list<LineEditor>::iterator it;
	
		for (it = l.begin(); it != l.end(); it++)
		{
			if ((*it).lineNo <= 12)
			{
				(*it).display();
				cout << "\n";
			}
				
		}
	
	if (count>12)
	{
		ch = _getch();
		for (it = l.begin(); it != l.end(); it++)
		{
			if ((*it).lineNo > 12)
			{
				(*it).display();
				cout << "\n";
			}
				
		}
	}

}

void LineEditor::displayTentotwenty(list<LineEditor>l,int count,int fromline,int toline)
{
	LineEditor le;
	char ch;
	list<LineEditor>::iterator it;
	
		//cout << "Nothing to print";
	if (count >= fromline)
	{
		for (it = l.begin(); it != l.end(); it++)
		{
			if ((*it).lineNo >= fromline && (*it).lineNo <= toline)
			{
				(*it).display();
				cout << "\n";
			}
				
		}
	}

	

}

void LineEditor::findWord(list<LineEditor>*l)//to find and Replace word
{
	int count = 0;
	string word,newword;
	size_t pos,len;
	list<LineEditor>::iterator it,it1;
	cout << "\nEnter a word which u want to find and replace: ";
	cin >> word;
	cout << "\nEnter new word: ";
	cin >> newword;
	int flag = 0;
	for (it = (*l).begin(); it != (*l).end(); it++)
	{
		
			if (it->line == word) 
			{
				it->line = newword;
				flag = 1;
			}
			continue;
	}
	if (flag == 0)
	{
		cout << "\n Not found ";
	}
}

void LineEditor::saveFile(list<LineEditor>l,string filename)
{
	ofstream out;
	out.open(filename);
	if (!out.is_open())
	{
		cout << "\nFile not found";
    }
	else
	{
		list<LineEditor>::iterator it;
		for (it = l.begin(); it != l.end(); it++)
		{
			out<< it->line<<endl;
		}

	}
	out.close();

}

void LineEditor::gotoLine(list<LineEditor>l, int linenum)
{
	LineEditor le;
	char ch;
	int flag = 0;
	list<LineEditor>::iterator it;
     for (it = l.begin(); it != l.end(); it++)
		{
			if ((*it).lineNo == linenum)
			{
				(*it).display();
				flag = 1;
			}

		}
	 if (flag == 0)
	 {
		 cout << "\n Line Does not Exist";
	 }
}

void LineEditor::addLine(list<LineEditor>*l, int linenum)
{
	LineEditor le,le1;
	string temp;
	char ch;
	list<LineEditor>::iterator it;
	cout << "Enter string to add: ";
	cin >> temp;
	for (it = (*l).begin(); it != (*l).end(); it++)
	{
		if ((*it).lineNo == linenum+1)
		{
			le1.line = temp;
			le1.lineNo = (*it).lineNo;
			(*it).lineNo++;
			(*l).insert(it, le1);
			
        }
		else if ((*it).lineNo >= linenum + 1)
		{
			(*it).lineNo++;
		}
		
    }

}

void LineEditor::deleteLines(list<LineEditor>*l, int frmline,int toline)
{
	LineEditor le, le1;
	list<LineEditor>::iterator it;
	it = (*l).begin();
	/*for (it = (*l).begin(); it != (*l).end(); it++)
	{
		if (it->lineNo >= frmline && it->lineNo <=toline)
		{
		    it=(*l).erase(it);
		}
	}*/
	while (it != (*l).end())
	{
		if (it->lineNo >= frmline && it->lineNo <= toline)
		{
			(*l).erase(it++);
		}
		else
			it++;
		
	}
}
void LineEditor::appendLines(list<LineEditor>*l,int count)
{
	LineEditor le;
	string temp;
	
	list<LineEditor>::iterator it;
	cout << "Enter string to add: ";
	cin >> temp;
	le.lineNo = count;
	le.lineNo++;
	le.line = temp;
	l->push_back(le);
}
