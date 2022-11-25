#include <iostream>
#include<thread>
#pragma comment(lib, "Winmm.lib")
#include <conio.h>
#include <windows.h>
#include<iostream>
#include<time.h>
#include<string>
#include<windows.h>
#include <windows.h>
#include<unistd.h>
#include<bits/stdc++.h>
#include<conio.h>
#include<math.h>
#include <cstdlib>
#include <ctime>
#include<vector>
#include <sstream>

//Title,Price,User_id,profileName,review/helpfulness,review/score,review/time,review/summary,review/text
using namespace std;
int cnt =0 ;
struct Data{
	string id;
    string title;
    string price;
    string user_id;
    string profileName;
    string review_helpfulness;
    string review_score;
    string review_time;
    string review_sumary;
    string review_text;
};
struct Book_ID{
    
    Data data;
    Book_ID *next;
};

Book_ID* getNode(Data x){

    Book_ID* newNode = new Book_ID;
    newNode->data = x;
    newNode->next = NULL;
  //  cout<<newNode->data.word<<endl;
    return newNode;

}

void addNode(Book_ID* &pHead, Data x){
	
    if (!pHead){
    
        pHead = getNode(x);
         
        return;
    }
    addNode(pHead->next, x);
   


}

void loadData(Book_ID* &head){
    ifstream fi;
    fi.open("Books_ratingS.CSV");
 	int q = 0;
    while(!fi.eof())
    {
    	
    	Data x;
    	getline(fi,x.id,',');
    	getline(fi,x.title,',');
    	getline(fi,x.price,',');
    	getline(fi,x.user_id,',');
    	getline(fi,x.profileName,',');
    	getline(fi,x.review_helpfulness,',');
    	getline(fi,x.review_score,',');
    	getline(fi,x.review_time,',');
    	getline(fi,x.review_sumary,',');
    	getline(fi,x.review_text,'\n');
    	if(q == 0){
    		q =1;
    		continue;
		}
    	addNode(head, x);
    	cnt ++;
	}
	
    fi.close();
}

void LNRlexi(Book_ID* pHead, vector<Data> &a){
    if (!pHead) return;
    a.push_back(pHead->data);
    LNRlexi(pHead->next, a);
    
    
}

void saveData(Book_ID *&pHead){
	fstream fout;
  
    fout.open("sorted_books_rating.CSV" );
	
  	vector <Data> a;
    LNRlexi(pHead, a);
    fout<<"ID,Title,Price,User_id,profileName,review/helpfulness,review/score,review/time,review/summary,review/text\n";

    int q=0;
    for (int i = 0; i < a.size(); i++){

            fout<< a[i].id << ","
            << a[i].title << ","
            << a[i].price << ","
            << a[i].user_id << ","
			<< a[i].profileName << ","
			<< a[i].review_helpfulness << ","
			<< a[i].review_score << ","
			<< a[i].review_time << ","
			<< a[i].review_sumary << ","  
            << a[i].review_text << "\n";
            
    }
	fout<<endl;
	fout.close();
}

Book_ID* access(Book_ID*& head, int num){
	Book_ID *cur = head;
	for(int i =0 ; i<num;i++)cur = cur->next;
	return cur;
}

Book_ID* access1(Book_ID*& head1, int num){
	Book_ID *cur = head1;
	for(int i =0 ; i<num;i++)cur = cur->next;
	return cur;
}

Book_ID* access2(Book_ID*& head2, int num){
	Book_ID *cur = head2;
	for(int i =0 ; i<num;i++)cur = cur->next;
	return cur;
}

void merge(Book_ID *&head, int p, int q, int r) {
  
  // Create L ? A[p..q] and M ? A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;
  
  
  Book_ID *cur0 ;
  Book_ID *cur1 = new Book_ID; //L[i]
  Book_ID *head1 = cur1;
  Book_ID *cur2 = new Book_ID; //M[j]
  Book_ID *head2 = cur2;

  for (int i = 0; i < n1; i++)
  {
  	
  	cur0 = access(head,p+i);
  	
  	cur1->data = cur0->data;
  	
  	//L[i] = arr[p + i];
  	
  	cur1->next = new Book_ID;
  	cur1=cur1->next;
  }
 for (int j = 0; j < n2; j++)
 {
 	//M[j] = arr[q + 1 + j];
 
  	cur0 = access(head,q+1+j);
  	cur2->data = cur0->data;
  	
  	
  	cur2->next = new Book_ID;
  	cur2=cur2->next;
 }
    

  
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  Book_ID *cur11 ;
  Book_ID *cur22 ;
  while (i < n1 && j < n2) {
  	cur11 = access1(head1,i);
  	cur22 = access2(head2,j);
  	cur0 = access(head,k);
    if (cur11->data.id < cur22->data.id) { //L[i] <= M[j]
      cur0->data = cur11->data;
      //arr[k] = L[i];
      i++;
    } else {
    	cur0->data = cur22->data;
      //arr[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
  	cur11 = access1(head1,i);
  	cur0 = access(head,k);
  	cur0->data = cur11->data;
    //arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
  	cur22 = access2(head2,j);
  	cur0 = access(head,k);
  	cur0->data = cur22->data;
    //arr[k] = M[j];
    j++;
    k++;
  }
 
}


void mergeSort(Book_ID *&head, int l, int r) {
  if (l < r) {
   
    int m = l + (r - l) / 2;

    mergeSort(head, l, m);
    mergeSort(head, m + 1, r);

    // Merge the sorted subarrays
    merge(head, l, m, r);
  }
}

void destruct(Book_ID* &pHead){
    if (!pHead) return;
    Book_ID* tmp = pHead;
    destruct(pHead->next);
    delete tmp;
}

int main(){
	Book_ID *head = NULL;
	loadData(head);
	
	mergeSort(head, 0,cnt - 1);
	saveData(head);
	destruct;
}
