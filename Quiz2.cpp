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
