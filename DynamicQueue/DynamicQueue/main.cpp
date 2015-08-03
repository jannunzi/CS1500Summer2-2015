//
//  main.cpp
//  DynamicQueue
//
//  Created by Jose Annunziato on 7/29/15.
//  Copyright (c) 2015 Jose Annunziato. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

struct Document
{
    string name;
    int bytes;
    Document(string name, int bytes)
    {
        this->name = name;
        this->bytes = bytes;
    }
};

struct PrinterQueue
{
    Document** documents;
    int front = 0, back = 0, count = 0;
    int size;
    PrinterQueue(int size)
    {
        this->size = size;
        documents = new Document*[this->size];
    }
};

void displayDocument(Document* document)
{
    cout << document->name << " " << document->bytes << endl;
}

void displayQueue(PrinterQueue* queue)
{
    int j = queue->front;
    for(int i=0; i<queue->count; i++)
    {
        cout << "["<< j << "] ";
        displayDocument(queue->documents[j]);
        j = (j+1) % queue->size;
    }
}

void enQueue(PrinterQueue* queue, Document* document)
{
    if(queue->count >= queue->size)
    {
        cout << "Sorry, the queue is full" << endl;
        return;
    }
    
    queue->documents[queue->back] = document;
    queue->count++;
    queue->back = (queue->back + 1) % queue->size;
}

Document* deQueue(PrinterQueue* queue)
{
    if(queue->count == 0)
    {
        cout << "Sorry, the queue is empty" << endl;
        return NULL;
    }
    Document* theDoc = queue->documents[queue->front];
    queue->front = (queue->front + 1) % queue->size;
    queue->count--;
    return theDoc;
}

void print(Document* d)
{
    displayDocument(d);
}

int main(int argc, const char * argv[])
{
    Document* d1 = new Document("Document 1", 123);
    Document* d2 = new Document("Document 2", 234);
    Document* d3 = new Document("Document 3", 345);
    Document* d4 = new Document("Document 4", 456);
    
//    displayDocument(d1);
    
    PrinterQueue* queue = new PrinterQueue(5);
    
    enQueue(queue, d1);
    enQueue(queue, d2);
    enQueue(queue, d3);
    enQueue(queue, d4);
    
    displayQueue(queue);
    
    Document* d5 = new Document("Document 5", 567);
    Document* d6 = new Document("Document 6", 678);

    enQueue(queue, d5);
    enQueue(queue, d6);
    
    displayQueue(queue);
    
    Document* d = deQueue(queue);
    if(d!=NULL)
        print(d);
    delete d;
}
