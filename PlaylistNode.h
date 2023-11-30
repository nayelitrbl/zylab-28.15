#include "iostream"
#include <string>
using namespace std;
class PlaylistNode{
   private: 
   string uniqueID;
   string songName; 
   string artistName;
   int songLength;
   PlaylistNode* nextNodePtr;
   
   public: 
   PlaylistNode();
   PlaylistNode(string id, string sName, string aName, int sLen);
   string GetID();
   string GetSongName();
   string GetArtistName();
   int GetSongLength();
   void PrintPlaylistNode();

   
   // PlaylistNode* GetNext();
   // void InsertAfter(PlaylistNode* nodePtr);
   // void SetNext(PlaylistNode* nodePtr);
   
};
