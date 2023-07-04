#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include<bits/stdc++.h>

using namespace std;

void listOfNoteFiles();

int main(int argc, char* argv[])
{
	int choice=0;
    cout << "Welcome to the CLI Application!" << endl;

    // Check if command-line arguments are provided
    // Provide any argument
    if (argc > 1)
    {
    	cout<<"You are in a CLI APP, enter your choice in integer:\n\n";
    	cout<<"1. To add content to a specific note from the CLI. \n2. To create new note file from the CLI\n";
    	cout<<"Enter your choice(1 or 2): ";
    	cin>>choice;
    	switch (choice)
    	{
	        case 1:
	       	{
			    cout << "You selected Option:  1. To add content to a specific note from the CLI." << endl;
			    cout<<"If you want, you can see the existing list of note file, give 1 to see and any other integer to move further: "<<"\n";
			    int choice2;
				cin>>choice2;
				
				if (choice2==1)
				{
					listOfNoteFiles();
				}
				
				
					cout<<"Enter your exact note file name from above list to modify :\n";
					//write your note file name here
					string notefileN;
					cin>>notefileN;
					fstream newfile;
				    newfile.open(notefileN,ios::out);  // open a file to perform write operation using file object
				    if(newfile.is_open())     //checking whether the file is open
				    {
				      cout<<"Enter your note to be saved in the note file " + notefileN<<endl;
				      string newNote;
				      while (getline(cin, newNote) && !newNote.empty())
				      {
				        newfile << newNote << endl;
				      }
					 
				      newfile.close(); //close the file object
				    }

				
				
				//wrong type of data for choice2 can cause error and can be handled, I haven't done here.		
								
				break;
	        
			}
	
	        case 2:
	        {
			    cout << "You selected Option 2. To create new note file and enter your note from the CLI" << endl;
			    cout<<"If you want, you can see the existing list of note file, give 1 to see and any other integer to move further: "<<"\n";
			    int choice2;
				cin>>choice2;
				
				if (choice2==1)
					listOfNoteFiles();
					
				string filePath; 
			    cout << "Enter the path and name of the new text file: ";
			    getline(cin, filePath);  // Example :-   C:\\Users\\pdil\\Documents\\C++ RBS\\noteFileNew.txt
			 
			    ofstream outputFile(filePath);
			    if (!outputFile)
			    {
			        cout << "Failed to create the file." << endl;
			        return 1;
			    }
			
			    string inputText;
			    cout << "Enter the text to save in the file (end with an empty line):" << endl;
			    while (getline(cin, inputText) && !inputText.empty())
			    {
			        outputFile << inputText << endl;
			    }
			    outputFile.close();
			    cout << "Text file created and saved successfully." << endl;
			
	            break;
			}
	        default:
	     	{   
			     cout << "Invalid choice. Please select a valid option (1-2)." << endl;
	            break;
	        }
   		}
    }
    else
    {
        cout << "No arguments provided." << endl;
    }

    return 0;
}


void listOfNoteFiles()
{
	cout<<"List of your existing notes\n";
			    
	//path is fixed so no need to take parameter in the above function
	string path("\"C:\\Users\\pdil\\Documents\\C++ RBS""");

    // I am doing the simple cmd command here to show all the note files in that path
    string command("dir /a-d ");
    command.append(path);
 
    // The string is converted to const char * as system function requires and as per the compile time error 
    const char* final_command = command.c_str();
 
    // Executing the final command 
    system(final_command);
				
	
}