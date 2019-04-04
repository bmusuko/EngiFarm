#ifndef __LINKEDLIST_HPP__
#define __LINKEDLIST_HPP__

#include<iostream>
using namespace std;

template <class T>
class LinkedList{
	public :
		struct Node{
			T x; // x adalah isi dari list
			Node *next; 
		};
		Node *head;
		int size;
		LinkedList(){
			head = NULL;
			size = 0;
		}
		
		LinkedList(const LinkedList& L){
			head = new Node();
			head->x = L.head->x;
			Node *P = head;
			Node *PL = L.head;
			while(PL->next){
				PL = PL->next;
				Node *node = new Node();
				node->x = PL->x;
				P->next = node;
				P = node;
			}
		}

		LinkedList& operator=(const LinkedList& L){
			head = new Node();
			head->x = L.head->x;
			Node *P = head;
			Node *PL = L.head;
			while(PL->next){
				PL = PL->next;
				Node *node = new Node();
				node->x = PL->x;
				P->next = node;
				P = node;
			}	
		}

		~LinkedList(){
			Node *P = head;
			while(P){
				Node *temp = P;
				P = P->next;
				delete temp;
			}
		}
		
		bool isEmpty() const{
			return (head == NULL);
		}

		void add(T element){
			Node *node = new Node();
			node->x = element;
			node->next = NULL;
			if(isEmpty()){
				head = node;
			} else{
				Node *P = head;
				while(P->next){
					P = P->next;
				}
				P->next = node;
			}
			size++;
		}

		int find(T element) const{
			int idx = 0;
			bool found = false;
			Node *P = head;
			while(P and !found){
				if(P->x ==element){
					found = true;
				} else{
					P = P->next;
					idx++;
				}
			}
			if(found){
				return idx;
			} else{
				return -1;
			}
		}

		T get(int indeks) const{
			int idx = indeks;
			Node *P = head;
			while(idx>0 and P){
				P = P->next;
				idx--;
			}
			if(P){
				return (P->x);
			}
		}

		void remove(T element){
			if(head->x == element){
				Node *Ptemp = head;
				head = head->next;
				delete Ptemp;
			} else{
				Node *P = head;
				Node *Prec = NULL;
				int y = find(element);
				if(y != -1){
					while(y>0){
						Prec = P;
						P = P->next;
						y--;
					}
					Prec->next = P->next;
					delete P;					
				}
			}
			size--;
		}	

		void PrintList() const{
			cout<<"[";
			if(!isEmpty()){
				Node *P = head;
				cout<<P->x;
				while(P->next){
					P = P->next;
					cout<<","<<P->x;
				}
			}
			cout<<"]"<<endl;
		}

};


#endif