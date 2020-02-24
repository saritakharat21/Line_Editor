#include "pch.h"
#include "LEHeader.h"

//Developed by Sarita Kharat

void menu()
{    
	cout << "\n**************[Menu]**************";
	cout << "\n1. Read";
	cout << "\n2. Display content of file";
	cout << "\n3. Find Word and Replace the word";
	cout << "\n4. To display the Particular Line";
	cout << "\n5. To add Data at Particular lineno";
	cout << "\n6. To delete Data of Particular Range";
	cout << "\n7. To Append data";
	cout << "\n8. Quit";
	cout << "\n\n--------------------------------------------------------------------------------------------------------------";
	cout << "\n\n";
}

void DisplayMenu()
{   
	cout << "\n\n*********Display Menu**********";
	cout << "\n1. Display With no arguments";
	cout << "\n2. Display 12 Line";
	cout << "\n3. Display 10-20 Lines";
	cout << "\n\n__________________________________________________________________________________________________";
}


int main()
{
	string filename;
	LineEditor le;
	
	list<LineEditor> listofLine;
	
	int option,choice,cnt,fromline,toline,lineNum,lineNum1,frmline,tooline;
	char ch,ch1,ch2;
	cout << "\t\t\t********************************************************************";
	cout << "\n\t\t\t*                                                                  *";
	cout << "\n\t\t\t*                                                                  *";
	cout << "\n\t\t\t*                        ===============                           *";
	cout << "\n\t\t\t*                        |LINE   EDITOR|                           *";
	cout << "\n\t\t\t*                        ===============                           *";
	cout << "\n\t\t\t*                                                                  *";
	cout << "\n\t\t\t*                                                                  *";
	cout << "\n\t\t\t********************************************************************";
	cout << "\n\n--------------------------------------------------------------------------------------------------------------";
	cout << "\n\n";
	do {
		menu();
		cout << "\nEnter your choice: ";
		cin >> option;
		switch (option)
		{
		case 1:
			cout << "\nEnter filename to read: ";
			cin >> filename;
			cnt=le.readFile(&listofLine,filename);
            break;
		case 2:
			do
			{
				DisplayMenu();
				cout << "\nEnter your choice for displaying file: ";
				cin >> choice;
				switch (choice)
				{
				case 1:
					le.displayFile(listofLine);
					break;
				case 2:
					le.displayTwelve(listofLine,cnt);
					break;
				case 3:
					cout<< "Enter range to display: ";
					cin >> fromline;
					cout << "-";
					cin >> toline;
					le.displayTentotwenty(listofLine, cnt,fromline,toline);
					break;
				}

				cout << "\nDo u want to display again(Y/y): ";
				//while (getchar() != '\n');
				cin >> ch1;
			} while (ch1 == 'y' || ch1 == 'Y');
			
			break;
		case 3:
			le.findWord(&listofLine);
			break;
		
		case 4:
			cout << "Enter line number to display: ";
			cin >> lineNum;
			le.gotoLine(listofLine, lineNum);
			break;
		case 5:
			cout << "Enter line number to add: ";
			cin >> lineNum1;
			le.addLine(&listofLine, lineNum1);
			break;

		case 6:
			cout << "Enter range to delete: ";
			cin >> frmline;
			cout << "-";
			cin >> tooline;
			le.deleteLines(&listofLine,frmline,tooline);
			break;
		case 7:
			le.appendLines(&listofLine,cnt);
			break;
		case 8:
			exit(0);
		}
		cout << "\n Do you want to Save Changes to the File(Y/y):";
		cin >> ch2;
		if (ch2 == 'y'||ch2=='Y')
		{
			le.saveFile(listofLine,filename);
		}
		
		cout << "\nDo u want to continue(Y/y): ";
		while (getchar() != '\n');
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');

	

	
}

