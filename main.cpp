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
   PlaylistNode* currNode = headNode->GetNext();
   
   if(option == 'q'){
      return 0;
   }
   else if(option == 'o'){
      cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;
      int i = 1;
      while(currNode != NULL){
         cout << i << "." << endl;
         currNode->PrintPlaylistNode();
         currNode = currNode->GetNext();
         i++;
      }
      
      if(currNode == NULL){
         cout << "Playlist is empty" << endl;  
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
