/* queue.h */

/* Queue structure declarations, constants, and inline functions	*/

/* Default # of queue entries: 1 per process plus 2 for ready list plus	*/
/*			2 for sleep list plus 2 per semaphore		*/

#ifndef NQENT
#define NQENT	(NPROC + 4 + NSEM + NSEM)
#endif

#define	EMPTY	(-1)		/* null value for qnext or qprev index	*/


//TODO - define queue's data members
struct queue
{
	// TODO - pointer to head qentry
	struct qentry* head;

	// TODO - pointer to tail qentry
	struct qentry* tail;

	// TODO - size of queue
	unsigned int size;

};


//TODO - define a queue entry's data members
struct qentry
{
	// TODO - process ID
	pid32 currpid;
	
	// TODO - other members
	struct qentry* prev;
	struct qentry* next;
};


/* Queue function prototypes (don't touch!) */
void    printqueue(struct queue *q);
void printhelper(struct qentry* entry);
int32 	size(struct queue *q);
int32 sizehelper(struct qentry* entry);
struct qentry *getbypidhelper(pid32 pid, struct qentry* entry);


bool8	isempty(struct queue *q);
bool8	nonempty(struct queue *q);
bool8	isfull(struct queue *q);

pid32	getfirst(struct queue *q);
pid32	getlast(struct queue *q);
pid32	remove(pid32 pid, struct queue *q);
pid32	dequeue(struct queue *q);
pid32	enqueue(pid32 pid, struct queue *q);

struct queue	*newqueue();
struct qentry	*getbypid(pid32 pid, struct queue *q);
