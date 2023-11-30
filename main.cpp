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
   
   if(option == 'q'){
      return 0;
   }
   else if(option == 'o'){
      cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;
      if(currNode == nullptr){
         cout << "Playlist is empty" << endl;  
      }
      int i = 1;
      while(currNode != nullptr){
         cout << i << "." << endl;
         currNode->PrintPlaylistNode();
         currNode = currNode->GetNext();
         i++;
      }
   }
   else if(option == 'a'){    //FIXME add new song to the end of the list
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
      currNode->InsertAfter(newNode);
      currNode = newNode;
   }
   else if(option == 'd'){      //FIXME remove songs from list
      cout << "REMOVE SONG" << endl;
      cout << "Enter song's unique ID:" << endl;
      cin >> ids;
      while(currNode != nullptr){
         if(currNode->GetID() == ids){
            //delete node that matches the id
            delete currNode;
            currNode = headNode->GetNext();
         }
      }
      
   }
   return 0;
}

int main(){
   string pTitle; 
   char optChar;
   PlaylistNode* hNode;
   hNode = new PlaylistNode();
   
   cout << "Enter playlist's title:" << endl;
   getline(cin, pTitle);
   cout << endl;
   PrintMenu(pTitle);
   cout << "Choose an option:" << endl;
   cin >> optChar;
   ExecuteMenu(optChar, pTitle, hNode);

   return 0;
}
