#include <iostream>
#include "../1-Stacks/ArrayStack.h";
#include "../3-Queues/LinkedQueue.h"
using namespace std;

void CountPosNeg(ArrayStack<int>& S, int & pos, int & neg,int &zeros ) {
	pos = zeros = neg = 0;
	ArrayStack<int> temp(100);
	while (!S.isEmpty()) {
		int x;
		S.pop(x);
		temp.push(x);
		if (x < 0) neg++;
		else if (x > 0) pos++;
		else zeros++;
	}
	while (!temp.isEmpty()) {
		int x;
		temp.pop(x);
		S.push(x);
	}
}

void deleteEvens(LinkedQueue<int> &q) {
	LinkedQueue<int> r;
	while (!q.isEmpty()) {
		int f;
		q.dequeue(f);
		if(f%2!=0)
		r.enqueue(f);
	}
	while (!r.isEmpty()) {
			int f;
			r.dequeue(f);
			q.enqueue(f);
	}
}
void deleteConsequentEvens(LinkedQueue<int>& q) {
	LinkedQueue<int> r;
	while (!q.isEmpty()) {
		int f;
		q.dequeue(f);
		if (f % 2 == 0) {
			r.enqueue(f);
			q.peek(f);
			while (f % 2 == 0&&!q.isEmpty()) {
				q.dequeue(f);
				q.peek(f);
			}
		}
		else {
			r.enqueue(f);
		}
	}
	while (!r.isEmpty()) {
		int f;
		r.dequeue(f);
		q.enqueue(f);
	}
}
void InsertEvenOdds(ArrayStack<int>& s) {
	ArrayStack<int> r(1000);
	while (!s.isEmpty()) {
		int f;
		s.pop(f);
		if (f % 2 == 0) {
			r.push(-2);
		}
		else {
			r.push(-1);
		}
		r.push(f);
	}
	while (!r.isEmpty()) {
		int f;
		r.pop(f);
		s.push(f);
	}
}
void PrintQ(LinkedQueue<int> &q) {
	int t;
	LinkedQueue<int> r;
	cout << "Front ";
	while (!q.isEmpty()) {
		q.dequeue(t);
		cout << t << " ";
		r.enqueue(t);
	}
	cout << endl;
}

void PrintS(ArrayStack<int>& s) {
	int t;
	ArrayStack<int> r(1000);
	while (!s.isEmpty()) {
		s.pop(t);
		r.push(t);
	}
	while (!r.isEmpty()) {
		r.pop(t);
		cout << t << " ";
	}
	cout << " Top "<<endl;
}
int main() {
	int n, p,z;
	cout << "Counting the positive and negative.........\n";
	cout << "Enter the element of the stack, -9999 to terminate: \n";
	int in; 
	cin >> in;
	ArrayStack<int> StackTest(100);
	while (in != -9999) {
		StackTest.push(in);
		cin >> in;
	}
	CountPosNeg(StackTest, p, n, z);
	cout << "Positive: " << p << " Negative: " << n << " Zeros: " << z << endl;
	//DeleteEvens

	cout << "Deletig the evens of a queue\n";

	cout << "Enter the element of the queue, -9999 to terminate: \n";
	cin >> in;
	LinkedQueue<int> QueueTest;
	while (in != -9999) {
		QueueTest.enqueue(in);
		cin >> in;
	}
	deleteEvens(QueueTest);
	cout << "After Deletion:\n";
	PrintQ(QueueTest);

	cout << "Deletig the conseuquetive evens of a queue\n";

	cout << "Enter the element of the queue, -9999 to terminate: \n";
	cin >> in;
	while (in != -9999) {
		QueueTest.enqueue(in);
		cin >> in;
	}
	deleteConsequentEvens(QueueTest);
	cout << "After Deletion:\n";
	PrintQ(QueueTest);

	cout << "Inserting -1 and -2 \n";

	cout << "Enter the element of the stack, -9999 to terminate: \n";
	cin >> in;
	ArrayStack<int> StackTest2(100);
	while (in != -9999) {
		StackTest2.push(in);
		cin >> in;
	}
	InsertEvenOdds(StackTest2);
	cout << "After Insertion:\n";
	PrintS(StackTest2);

}
