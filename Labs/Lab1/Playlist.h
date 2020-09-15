#ifndef PLAYLIST_H
#define PLAYLIST_H
#include <string>
using namespace std;

class Playlist;
class PlaylistNode{
private:
    string uniqueID;
    string songName;
    string artistName;
    int songLength;
    PlaylistNode* nextNodePtr;
public:
    PlaylistNode();
    PlaylistNode(string, string, string, int);
    void InsertAfter(PlaylistNode*);
    void SetNext(PlaylistNode*);
    string GetID() const;
    string GetSongName() const;
    string GetArtistName() const;
    int GetSongLength() const;
    PlaylistNode* GetNext() const;
    void PrintPlaylistNode();
};

class Playlist{
private:
    PlaylistNode* head;
    PlaylistNode* tail;
public:
    Playlist();
   // void PrintMenu(string);
    void addSong(string,string,string,int);
    void removeSong(string);
    void printAll();
    void changePosition(int, int);
    void outputByArtist(string);
    int totalTime();
    bool empty();
};

#endif
