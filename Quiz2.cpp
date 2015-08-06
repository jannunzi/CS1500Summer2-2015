#include <iostream>
#include <string>
using namespace std;

struct Document
{
    string title;
    Document* next = NULL;
    Document();
    Document(string title);
    void display();
};

struct PrinterQueue
{
    Document* front = NULL;
    Document* back = NULL;
    int size = 0;
    PrinterQueue();
    void enqueue(Document* document);
    Document* dequeue();
    void display();
    int getSize();
    bool isEmpty();
};

void display(Document* document);

int main(int argc, const char * argv[])
{
    PrinterQueue* queue = new PrinterQueue();
    cout << "Size: " << queue->getSize() << endl;
    cout << "Empty: " << queue->isEmpty() << endl;
    queue->display();
    cout << "=== Enqueueing ===" << endl;
    queue->enqueue(new Document("d1"));
    queue->enqueue(new Document("d2"));
    queue->enqueue(new Document("d3"));
    queue->enqueue(new Document("d4"));
    queue->enqueue(new Document("d5"));
    queue->enqueue(new Document("d6"));
    queue->display();
    cout << "Size: " << queue->getSize() << endl;
    cout << "Empty: " << queue->isEmpty() << endl;
    cout << "=== Dequeuing ===" << endl;
    display(queue->dequeue());
    display(queue->dequeue());
    display(queue->dequeue());
    display(queue->dequeue());
    queue->display();
    cout << "=== Enqueueing ===" << endl;
    queue->enqueue(new Document("d7"));
    queue->enqueue(new Document("d8"));
    queue->enqueue(new Document("d9"));
    queue->display();
    cout << "=== Dequeuing ===" << endl;
    display(queue->dequeue());
    display(queue->dequeue());
    display(queue->dequeue());
    display(queue->dequeue());
    display(queue->dequeue());
    display(queue->dequeue());
    queue->display();
}

/* Sample Output
Size: 0
Empty: 1
Sorry, queue is empty

=== Enqueueing ===

=== Queue ===
d1
d2
d3
d4
d5
d6
Size: 6
Empty: 0
=== Dequeuing ===
d1
d2
d3
d4

=== Queue ===
d5
d6
=== Enqueueing ===

=== Queue ===
d5
d6
d7
d8
d9
=== Dequeuing ===
d5
d6
d7
d8
d9
Sorry, queue is empty
Sorry, queue is empty
*/
