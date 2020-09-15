#include "Playlist.h"
#include <iostream>
#include <string>
using namespace std;


void PrintMenu(string title);

int main() {
    string nameOfList;
    Playlist list;
    string userInput;
    cout << "Enter playlist's title: " << endl;
    getline(cin,nameOfList);
    cout << endl;
    while (userInput != "q"){
        userInput = "";
        PrintMenu(nameOfList);
        while( userInput != "a" && userInput != "d" && userInput != "c" && userInput != "s" && userInput != "t" && userInput != "o" && userInput != "q" ){
            cout << "Chose and option: " << endl;
            cin >> userInput;
        }
        if (userInput == "o"){
            if( list.empty() == true){
            cout << "Playlist is empty" << endl;
        }
            else{
                list.printAll();
            }
        }
        
        else if(userInput == "q"){
            break;
        }
        
        else if(userInput == "a"){
            string artist;
            string songName;
            string iD;
            int length;
            cout << "Enter song's unique ID: " << endl;
            cin.ignore();
            getline(cin,iD);
            cout << "Enter song's name: " << endl;
            getline(cin,songName);
            cout << "Enter artist's name: " << endl;
            getline(cin, artist);
            cout << "Enter song's length (in seconds): " << endl;
            cin >> length;
        
            list.addSong(iD,songName,artist,length);
        }
        
        else if(userInput == "d"){
            if( list.empty() == true){
                cout << "Playlist is empty" << endl;
            }
            else{
                string iD;
                cout << "Enter song's unique ID: " << endl;
                cin >> iD;
                list.removeSong(iD);
            }
        }
        else if(userInput == "c"){
            if(list.empty() == true){
                cout << "Playlist is empty" << endl;
            }
            else{
                int currSongPos;
                int location;
                cout << "Enter songs current position: " << endl;
                cin >> currSongPos;
                cout << "Enter new position: " << endl;
                cin >> location;
                list.changePosition(currSongPos, location);
            }
        }
        
        else if (userInput == "s"){
            string name;
            cout << "Enter artist's name " << endl;
            cin.ignore();
            getline(cin, name);
            list.outputByArtist(name);
        }
        
        else if(userInput == "t"){
            if( list.empty() == true){
                cout << "Playlist is empty" << endl;
            }
        
            else{
                cout << list.totalTime() << endl;
            }
        
        }
        
    }
    
    
    return 0;
}

void PrintMenu(string title){
    cout << title << " PLAYLIST MENU" << endl;
    cout << "a - Add song" << endl;
    cout << "d - Remove song" << endl;
    cout << "c - Change position of song" << endl;
    cout << "s - Output songs by specific artist" << endl;
    cout << "t - Output total time of playlist (in seconds)" << endl;
    cout << "o - Output full playlist" << endl;
    cout << "q - Quit" << endl;
    cout << endl << endl;
   //  cout << "Choose an option" << endl;
}
