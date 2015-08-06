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
    cout << "Size: " << queue->getSize() << endl;   // Size: 0
    cout << "Empty: " << queue->isEmpty() << endl;  // Empty: 1
    queue->display();                               // Sorry, queue is empty
    cout << "=== Enqueueing ===" << endl;           // === Enqueueing ===
    queue->enqueue(new Document("d1"));
    queue->enqueue(new Document("d2"));
    queue->enqueue(new Document("d3"));
    queue->enqueue(new Document("d4"));
    queue->enqueue(new Document("d5"));
    queue->enqueue(new Document("d6"));
    queue->display();                               // === Queue === ...
    cout << "Size: " << queue->getSize() << endl;   // Size: 6
    cout << "Empty: " << queue->isEmpty() << endl;  // Empty: 0
    cout << "=== Dequeuing ===" << endl;            // === Dequeuing ===
    display(queue->dequeue());                      // d1
    display(queue->dequeue());                      // d2
    display(queue->dequeue());                      // d3
    display(queue->dequeue());                      // d4
    queue->display();
    cout << "=== Enqueueing ===" << endl;           // === Enqueueing ===
    queue->enqueue(new Document("d7"));
    queue->enqueue(new Document("d8"));
    queue->enqueue(new Document("d9"));
    queue->display();                               // === Queue === ...
    cout << "=== Dequeuing ===" << endl;            // === Dequeuing ===
    display(queue->dequeue());                      // d5
    display(queue->dequeue());                      // d6
    display(queue->dequeue());                      // d7
    display(queue->dequeue());                      // d8
    display(queue->dequeue());                      // d9
    display(queue->dequeue());                      // Sorry, queue is empty
    queue->display();                               // Sorry, queue is empty
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
