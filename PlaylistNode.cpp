#include "PlaylistNode.h"
#include <iostream>

PlaylistNode::PlaylistNode(){
   this->uniqueID = "none";
   this->songName = "none";
   this->artistName = "none";
   this->songLength = 0;
}

PlaylistNode::PlaylistNode(string id, string sName, string aName, int sLen){
   this->uniqueID = id;
   this->songName = sName;
   this->artistName = aName;
   this->songLength = sLen;
}

string PlaylistNode::GetID(){
   return uniqueID;
}

string PlaylistNode::GetSongName(){
   return songName;
}
 
string PlaylistNode::GetArtistName(){
  return artistName;
}

int PlaylistNode::GetSongLength(){
   return songLength;
}

PlaylistNode* PlaylistNode::GetNext(){
   return this->nextNodePtr;
}

void PlaylistNode::InsertAfter(PlaylistNode* nodePtr){
   PlaylistNode* tmpNode;
   tmpNode = this->nextNodePtr;
   this->nextNodePtr = nodePtr;
   nodePtr->nextNodePtr = tmpNode;
}

// void PlaylistNode::SetNext(PlaylistNode* nodePtr){
   
// }

void PlaylistNode::PrintPlaylistNode(){
   cout << "Unique ID: " << uniqueID << endl;
   cout << "Song Name: " << songName << endl;
   cout << "Artist Name: " << artistName << endl;
   cout << "Song Length (in seconds): " << songLength << endl;
}
