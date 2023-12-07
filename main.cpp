//https://github.com/nayelitrbl/zylab-28.15.git
#include <iostream>
#include <string>
#include "PlaylistNode.h"

using namespace std;

void PrintMenu(const string playlistTitle){
   cout << playlistTitle << " PLAYLIST MENU" << endl;
   cout << "a - Add song" << endl;
   cout << "d - Remove song" << endl;
   cout << "c - Change position of song" << endl;
   cout << "s - Output songs by specific artist" << endl;
   cout << "t - Output total time of playlist (in seconds)" << endl;
   cout << "o - Output full playlist" << endl;
   cout << "q - Quit" << endl; 
   cout << endl;
}


PlaylistNode* ExecuteMenu(char option, string playlistTitle, PlaylistNode* headNode){
   PlaylistNode* currNode = headNode;
   string ids;
   string name;
   string artist;
   int len;
   
   if(option == 'q'){
      return 0;
   }
   else if(option == 'o'){
      cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;
      if(currNode == nullptr){
         cout << "Playlist is empty" << endl;  
      }
      else{
         int i = 1;
         while(currNode != nullptr){   //FIXME: number is set to the node
            cout << i << "." << endl;
            currNode->PrintPlaylistNode();
            currNode = currNode->GetNext();
            i++;
         }
      }
   }
   else if(option == 'a'){                 
      cout << "ADD SONG" << endl;
      cout << "Enter song's unique ID:" << endl;
      cin >> ids;
      cout << "Enter song's name:" << endl;
      getline(cin, name);
      cout << "Enter artist's name:" << endl;
      getline(cin, artist);
      cout << "Enter song's length (in seconds):" << endl;
      cin >> len;
      PlaylistNode* newNode = new PlaylistNode(ids, name, artist, len);
      if (currNode == nullptr) {    //FIXME add song to the playlist
         currNode = newNode;
         currNode = currNode->GetNext();
      } 
      else{
         currNode->InsertAfter(newNode);
         currNode = newNode;
      }
      
   }
   else if(option == 'd'){
      cout << "REMOVE SONG" << endl;
      cout << "Enter song's unique ID:" << endl;
      cin >> ids;
      while(currNode != nullptr){
         if(currNode->GetID() == ids){
            //FIXME: delete node that matches the id
            cout << "\"" << currNode->GetSongName() << "\"" << " removed." << endl; 
            delete currNode;
            currNode = currNode->GetNext();
            return 0;   
         }
      }
      
   }
   else if(option == 'c'){
      cout << "CHANGE POSITION OF SONG" << endl;       //not implementing 
   }
   else if(option == 's'){                               //FIXME: cin matches getartist of node, output
      cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
      cout << "Enter artist's name: " << endl;
      getline(cin, artist);
      while(currNode != nullptr){
         if(currNode->GetArtistName() == artist){
            cout << "FIXME: output songs by artist" << endl;
            currNode->PrintPlaylistNode();
            currNode = currNode->GetNext();
            
         }
      }
   }
   else if(option == 't'){
      cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
      int totalSec = 0; 
      while(currNode != nullptr){
         totalSec += currNode->GetSongLength();
      }
      currNode = currNode->GetNext();
      cout << "Total time: " << totalSec << " seconds" << endl;
   }

   return 0;
}

int main(){
   string pTitle; 
   char optChar;
   PlaylistNode* hNode;
   hNode = new PlaylistNode();
   
   cout << "Enter playlist's title:" << endl;
   cout << endl;
   getline(cin, pTitle);
   PrintMenu(pTitle);
   cout << "Choose an option:" << endl;
   cin >> optChar;
   while(optChar != 'q'){
      if(optChar == 'a' || optChar == 'd' ||  optChar == 'c' || optChar == 's' || optChar == 't' || optChar == 'o' || optChar == 'q'){
         ExecuteMenu(optChar, pTitle, hNode);
      }     
      PrintMenu(pTitle);
      cout << "Choose an option:" << endl;
      cin >> optChar;
   }
   return 0;
}
