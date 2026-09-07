struct queue *newqueue(size_t _size);
int isfull(struct queue *q);
int isempty(struct queue *q);
int front(struct queue *q);
void enque(struct queue *q,int data);
void deque(struct queue *q);
void print(struct queue *q);
int operateQueue();