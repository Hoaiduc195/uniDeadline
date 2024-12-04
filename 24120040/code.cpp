#include <iostream>
#include <fstream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

struct LinkedList
{
	Node *head;
	Node *tail;
};

void createLinkedList(LinkedList &list)
{
	list.head = nullptr;
	list.tail = nullptr;
}

Node *createNode(int x)
{
	Node *p = new Node;
	p->data = x;
	p->next = nullptr;
	return p;
}

void insertTail(LinkedList &list, int x)
{
	Node *p = createNode(x);
	if (list.head == nullptr)
	{
		list.head = p;
		list.tail = p;
	}
	else
	{
		list.tail->next = p;
		list.tail = p;
	}
}

void inputList(LinkedList &list)
{
	int inp = -1;
	while (inp)
	{
		cin >> inp;
		if (!inp)
		{
			break;
		}
		insertTail(list, inp);
	}
}
void rmAfterNode(Node *p)
{
	if (!p->next)
	{
		return;
	}
	else
	{
		if (p->next->next == nullptr)
		{
			delete p->next;
			p->next = nullptr;
		}
		else
		{
			Node *u = p->next->next;
			delete p->next;
			p->next = u;
		}
	}
}

void rmHead(LinkedList &list)
{
	if (!list.head)
	{
		return;
	}
	else if (list.head == list.tail)
	{
		delete list.head;
		list.head = nullptr;
		list.tail = nullptr;
	}
	else
	{
		Node *tmp = list.head->next;
		delete list.head;
		list.head = tmp;
	}
}

void rmAllX(LinkedList &list, int x)
{
	if (!list.head)
	{
		return;
	}
	Node *cur = list.head;
	while (cur->data == x)
	{
		rmHead(list);
		cur = list.head;
	}
	while (cur->next)
	{
		if (cur->next->data == x)
		{
			rmAfterNode(cur);
			continue;
		}
		cur = cur->next;
	}
}

void outputList(LinkedList list)
{
	Node *cur = list.head;
	if (!cur)
	{
		return;
	}
	else
	{
		while (cur)
		{
			cout << cur->data << " ";
			cur = cur->next;
		}
	}
	cout <<"0"<< endl;
}
void insertHead(LinkedList &list, int x)
{
	Node *p = createNode(x);
	if (!list.head)
	{
		list.head = p;
		list.tail = p;
		return;
	}
	p->next = list.head;
	list.head = p;
}
LinkedList reverseList(LinkedList list)
{
	LinkedList tmp;
	createLinkedList(tmp);
	Node *cur = list.head;
	while (cur)
	{
		insertHead(tmp, cur->data);
		cur = cur->next;
	}
	return tmp;
}

void rmDupe(LinkedList &list)
{
	if (!list.head || list.head == list.tail)
	{
		return;
	}
	Node *cur = list.head;
	while (cur->next)
	{
		Node *move = cur;
		while (move->next)
		{
			if (move->next->data == cur->data)
			{
				rmAfterNode(move);
				continue;
			}
			move = move->next;
		}
		cur = cur->next;
	}
}

void rmAll(LinkedList &list)
{
	if (!list.head)
	{
		return;
	}
	while (list.head)
	{
		rmHead(list);
	}
}

void insertAfterNode(Node *p, int x)
{
	if (!p->next)
	{
		Node *v = createNode(x);
		p->next = v;
	}
	else
	{
		Node *tmp = p->next;
		Node *v = createNode(x);
		v->next = tmp;
		p->next = v;
	}
}
void saveListIntoText(char path[], LinkedList list)
{
	fstream input(path);
	if (!input)
	{
		cout << "Can not open the file." << endl;
		return;
	}
	Node *cur = list.head;
	while (cur)
	{
		input << cur->data << " ";
		cur = cur->next;
	}

	input.close();
}

void insertEven(LinkedList &list)
{
	int tmp = 1;
	Node *cur = list.head;
	while (cur)
	{
		if (cur == list.head)
		{
			insertHead(list, tmp * 2);
			tmp++;
			insertAfterNode(cur, tmp * 2);
			cur = cur->next->next;
			tmp++;
		}
		else if (cur == list.tail)
		{
			break;
		}
		else
		{
			insertAfterNode(cur, tmp * 2);
			tmp++;
			cur = cur->next->next;
		}
	}
}

void insertSortedList(LinkedList &list, int x)
{
	if (!list.head)
	{
		insertHead(list, x);
		return;
	}
	if (x >= list.tail->data)
	{
		insertTail(list, x);
		return;
	}
	else if (x <= list.head->data)
	{
		insertHead(list, x);
		return;
	}
	else
	{
		Node *cur = list.head;
		while (cur->next)
		{
			if (cur->data <= x && cur->next->data >= x)
			{
				insertAfterNode(cur, x);
				cur = cur->next->next;

			}
			cur = cur->next;
		}
	}
}

LinkedList sumList(LinkedList list)
{
	LinkedList tmp;
	createLinkedList(tmp);
	if (!list.head)
	{
		return tmp;
	}
	int sum = list.head->data;
	Node *cur = list.head;
	while (cur)
	{
		insertTail(tmp, sum);
		cur = cur->next;
		sum += cur->data;
	}
	return tmp;
}

void oneToTwoList(LinkedList list)
{
	if(!list.head)
	{
		return;
	}
	int tmp = 0;
	LinkedList odd,even;
	createLinkedList(odd);
	createLinkedList(even);

	Node* cur = list.head;
	while(cur)
	{
		if(!(tmp%2))
		{
			insertTail(even,cur->data);
		} else
		{
			insertTail(odd,cur->data);
		}
		tmp++;
		cur = cur->next;
	}
	cout<<"result:"<<endl;
	outputList(even);
	outputList(odd);

}



void insertTailNode(LinkedList &list, Node* after)
{
	if(!list.head)
	{
		Node* cur = after;
		while(cur->next)
		{
			cur = cur->next;
		}
		list.head = after;
		list.tail = cur;
	} else {
		Node* cur = after;
		list.tail->next = after;
		while(cur->next)
		{
			cur = cur->next;
		}
		list.tail = cur;
	}

}

LinkedList TwoToOneList(LinkedList list1, LinkedList list2)
{
	if(!list1.head)
	{
		return list2;
	}
	if(!list2.head)
	{
		return list1;
	}
	Node* cur1 = list1.head;
	Node* cur2 = list2.head;
	LinkedList tmp;
	createLinkedList(tmp);
	int cnt = 0;

	while(cur1||cur2)
	{
		if(!cur1)
		{
			insertTailNode(tmp,cur2);
			break;
		}
		if(!cur2)
		{
			insertTailNode(tmp,cur1);
			break;
		}
		if(!(cnt%2))
		{
			insertTail(tmp,cur1->data);
			cur1 = cur1->next;
		} else {
			insertTail(tmp,cur2->data);
			cur2 = cur2->next;
		}
		cnt++;
	}
	return tmp;

}

LinkedList join2List(LinkedList list1, LinkedList list2)
{
	LinkedList tmp  =list1;
	insertTailNode(tmp,list2.head);
	return tmp;
}

int main()
{
	LinkedList list;
// 	LinkedList list2;
	createLinkedList(list);
	inputList(list);
// 	createLinkedList(list2);
// 	inputList(list2);

	oneToTwoList(list);

	rmAll(list);
// 	rmAll(list2);

	return 0;
}