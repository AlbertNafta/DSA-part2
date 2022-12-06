#include "Header.h"

int main(){
	Book_ID *head = NULL;
	cout<<"Sorting...";
	loadData(head);
	Book_ID *cur = head;
	mergeSort(head, 0,cnt - 1);
	saveData(head);
	menu(head);
	destruct(head);
	return 0; 
}
