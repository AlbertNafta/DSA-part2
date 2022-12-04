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


using namespace std;

struct Node{
	int id;
	string name;
	float gpa;
	Node *left;
	Node *right;
};

void addNode(Node *&root, Node *cur)
{
	
	Node *cur1=root;
	if(root==NULL )
	{
		root= new Node;
		root->id = cur->id;
		root->name = cur->name;
		root->gpa = cur->gpa;
		root->left=NULL;
		root->right= NULL;
		
		return;
	}
	while(cur1 !=NULL)
	{
		cout<<"h";
		
		if(cur1->id > cur->id) cur1 = cur1->left;
		else cur1 = cur1->right;	
	}
	cur1= new Node;
	cur1->id = cur->id;
	cur1->name = cur->name;
	cur1->gpa = cur->gpa;
	cur1->left=NULL;
	cur1->right= NULL;
	cout<<cur->id;
	return;	

	
}

void loadData(Node *&root)
{
	Node *cur = new Node;
	for(int i = 0;i<4;i++)
	{
	
		if(i==0)
		{
			cur->id = 3;
			cur->name = "Nguyen Van A";
			cur->gpa = 8.6;
			cur->left = NULL;
			cur->right = NULL;
		}
		if(i==1)
		{
			cur->id = 2;
			cur->name = "Tran Thi B";
			cur->gpa = 5.5;
			cur->left = NULL;
			cur->right = NULL;
		}
		if(i==2)
		{
			cur->id = 1;
			cur->name = "Vo Van C";
			cur->gpa = 9.9;
			cur->left = NULL;
			cur->right = NULL;
		}
		if(i==3)
		{
			cur->id = 4;
			cur->name = "Truong Ngoc D";
			cur->gpa = 7.2;
			cur->left = NULL;
			cur->right = NULL;
		}
	
		
		addNode(root,cur);
	}
}

void LNR(Node *root){
	cout<<"f";
	if (!root) return;
    LNR(root->left);
    cout<<root->id<<endl;
    LNR(root->right);
}


int main()
{
	Node *root=NULL;
	loadData(root);
	LNR(root);
}
