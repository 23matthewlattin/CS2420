/* Matthew Lattin
 * 
 */
#define MAXSIZE 5

class intque {
	
public:
	bool isemptyq();
	
	bool isfullq();
	
	bool enqueue(int);
	
	int dequeue();
	
	int peek();

	intque();
		
	
private:
		int que[MAXSIZE];
		int head, tail, count;
};
