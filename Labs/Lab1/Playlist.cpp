#include "Playlist.h"
#include <iostream>
using namespace std;

PlaylistNode::PlaylistNode(){
    uniqueID = "none";
    songName = "none";
    artistName = "none";
    songLength = 0;
    nextNodePtr = nullptr;
}

PlaylistNode::PlaylistNode(string id, string name, string artist, int length): uniqueID(id), songName(name), artistName(artist), songLength(length) {
    nextNodePtr = nullptr;
    
}


void PlaylistNode::InsertAfter(PlaylistNode* node){
    this->SetNext(node->GetNext());
    node->SetNext(this);
}
void PlaylistNode::SetNext(PlaylistNode* node){
    nextNodePtr = node;
}

string PlaylistNode::GetID() const {
    return uniqueID;
}

string PlaylistNode::GetSongName() const {
    return songName;
}

string PlaylistNode::GetArtistName() const{
    return artistName;
}

int PlaylistNode::GetSongLength() const{
    return songLength;
}

PlaylistNode* PlaylistNode::GetNext() const {
    return nextNodePtr;
}

void PlaylistNode::PrintPlaylistNode(){
    cout << "Unique ID: " << uniqueID << endl;
    cout << "Song name: " << songName << endl;
    cout << "Artist name: " << artistName << endl;
    cout << "Song length (in seconds): " << songLength << endl;
    
}

 Playlist::Playlist(){
    head = nullptr;
    tail = nullptr;
}

void Playlist::addSong(string iD, string songName, string artist, int length){
    if(head == nullptr){
        head = new PlaylistNode(iD, songName, artist, length);
        tail = head;
    }
    else {
     tail->SetNext(new PlaylistNode(iD, songName, artist, length));
        tail = tail->GetNext();
   }
}

void Playlist::removeSong(string iD){
    PlaylistNode* prevNode = head;
    PlaylistNode* currNode = head;
    if( head == nullptr){
        return;
    }
    while (currNode != nullptr) {
        if(currNode->GetID() == iD){
            if (currNode == head) {
                PlaylistNode* temp = head->GetNext();
                delete currNode;
                head = temp;
                prevNode = head;
                break;
            }
            else {
                prevNode->SetNext(currNode->GetNext());
                if(tail == currNode){
                    tail = prevNode;
                }
                delete[] currNode;
               
            }
        }
        else{
            if(currNode != head){
                prevNode = prevNode->GetNext();
            }
            currNode = currNode->GetNext();
        }
    }
    
}

bool Playlist::empty(){
    if(head == nullptr){
        return true;
    }
    return false;
}

void Playlist::printAll(){
    PlaylistNode* currNode = head;
    if(currNode == nullptr){
        return;
    }
    else{
        while (currNode != nullptr) {
            currNode->PrintPlaylistNode();
            cout << endl;
            currNode = currNode->GetNext();
        }
    }
   
}

void Playlist::outputByArtist(string name){
    PlaylistNode* currNode = head;
    int songCount = 1;
    while (currNode != nullptr) {
        
        if (currNode->GetArtistName() == name) {
            cout << songCount << "." <<endl;
            currNode->PrintPlaylistNode();
            cout << endl;
        }
        currNode = currNode->GetNext();
        ++songCount;
    }
    
}

int Playlist::totalTime(){
    PlaylistNode* currNode = head;
    int counter = 0;
    while(currNode != nullptr){
        counter += currNode->GetSongLength();
        currNode = currNode->GetNext();
    }
    return counter;
}

void Playlist::changePosition(int currpos, int loc){
   
    
   // if(is)
}

