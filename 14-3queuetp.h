template<typename T>
class QueueTP{
private:	
	struct Node{
		T item;
		Node * next;
	};
	enum {MAX=10};
	int items;
	const int qsize;
	Node * front;
	Node * rear;
public:
	QueueTP(int qs=MAX);
	~QueueTP();
	bool isempty() const {return items==0;}
	bool isfull() const {return items==qsize;}
	bool enqueue(const T &t);
	bool dequeue(T &t);
	int queuecount() const {return items;}
};
template<typename T>
QueueTP<T>::QueueTP(int qs):qsize(qs)
{
	front=rear=nullptr;
	items=0;
}
template<typename T>
QueueTP<T>::~QueueTP()
{
	Node * temp;
	while(front!=nullptr)
	{
		temp=front;
		front=front->next;
		delete temp;
	}
}
template<typename T>
bool QueueTP<T>::enqueue(const T &item)
{
	if(isfull())
		return false;
	Node * temp=new Node;
	temp->item=item;
	temp->next=nullptr;
	items++;
	if(front==nullptr)
		front=temp;
	else
	rear->next=temp;
	rear=temp;
	return true;
}
template<typename T> 
bool QueueTP<T>::dequeue(T &item)
{
	if(isempty())
		return false;
	item=front->item;
	items--;
	Node * temp=front;
	front=front->next;
	delete temp;
	if(items==0)
		rear==nullptr;
	return true;
}
