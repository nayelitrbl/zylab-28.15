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
   string ids = "";
   string name = "";
   string artist = "";
   int len = 0;

   if(option == 'q'){
      return 0;
   }
   else if(option == 'o'){
      cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;
      if (headNode == nullptr) {
        cout << "Playlist is empty" << endl;
        cout << endl;
      } 
      else {
        int i = 1;
        currNode = currNode->GetNext();
        PlaylistNode* tempNode = currNode;
        while (tempNode != nullptr) {
            cout << i << "." << endl;
            tempNode->PrintPlaylistNode();
            tempNode = tempNode->GetNext();
            i++;
        }
      }
   }
   else if(option == 'a'){    
     
      cout << "ADD SONG" << endl;
      cout << "Enter song's unique ID:" << endl;
      cin >> ids;
     cin.ignore(1,'\n');
      
      cout << "Enter song's name:" << endl;
      getline(cin, name);
      
      cout << "Enter artist's name:" << endl;
      getline(cin, artist);
     
      cout << "Enter song's length (in seconds):" << endl;
      cin >> len;
      cout << endl;
      PlaylistNode* newNode = new PlaylistNode(ids, name, artist, len);

      if(headNode == nullptr){
         headNode = newNode;  
      }
      else{
         while(currNode->GetNext()){
            currNode = currNode->GetNext();  
         }
         currNode->InsertAfter(newNode);
      }
   }
   else if(option == 'd'){
      cout << "REMOVE SONG" << endl;
      cout << "Enter song's unique ID:" << endl;
      cin >> ids;
      currNode = headNode;
      PlaylistNode* prevNode = nullptr;
      while(currNode != nullptr){
         if(currNode->GetID() == ids){
            cout << "\"" << currNode->GetSongName() << "\"" << " removed." << endl; 
            if(prevNode != nullptr){
               prevNode->SetNext(currNode->GetNext());  
            }
            else{
               headNode = currNode->GetNext();  
            }
            delete currNode;
            return 0;
         }
      }

   }
   else if(option == 'c'){
      cout << "CHANGE POSITION OF SONG" << endl;       //not implementing 
   }
   else if(option == 's'){ 
      cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
      cout << "Enter artist's name: " << endl;
      getline(cin, artist);
      int num = 1;
      while(currNode != nullptr){
         num++;
         if(currNode->GetArtistName() == artist){
            cout << num << "." << endl;
            currNode->PrintPlaylistNode();
         }
         currNode = currNode->GetNext();
      }
   }
   else if(option == 't'){
      cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
      int totalSec = 0; 
      while(currNode != nullptr){
         totalSec += currNode->GetSongLength();
         currNode = currNode->GetNext();
      }
      cout << "Total time: " << totalSec << " seconds" << endl;
      cout << endl;
   }
   return 0;
}

int main(){
   string pTitle; 
   char optChar;
   PlaylistNode* hNode = new PlaylistNode();

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
