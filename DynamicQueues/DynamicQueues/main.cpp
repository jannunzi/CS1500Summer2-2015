//
//  main.cpp
//  DynamicQueues
//
//  Created by Jose Annunziato on 6/4/15.
//  Copyright (c) 2015 Jose Annunziato. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

struct Document
{
    string name;
    Document(){}; // default constructor - aka no argument constructor
    Document(string name) // all arguments constructor
    {
        setName(name);
    }
    // API
    void setName(string name)
    {
        this->name = name;
    }
    string getName()
    {
        return name;
    }
};

struct PrinterQueue
{
    Document* *documents;
    int capacity = 0;
    int count = 0;
    
    int front = 0;
    int back = 0;
    
    PrinterQueue(){}
    PrinterQueue(int capacity)
    {
        this->count = 0;
        this->front = 0;
        this->back = 0;
        this->capacity = capacity;
        this->documents = new Document*[capacity];
        for(int i=0; i<capacity; i++)
        {
            this->documents[i] = NULL;
        }
    }
};

// utility functions
void displayDocument(Document* document)
{
    cout << "===" << endl;
    cout << document->name << endl;
}

void enqueueDocument(PrinterQueue* queue, Document* document)
{
    if(queue->count < queue->capacity)
    {
        queue->documents[queue->back] = document;
        queue->back = ++queue->back % queue->capacity;
        queue->count++;
        if(queue->back >= queue->capacity)
        {
            queue->back = 0;
        }
    }
}

Document* dequeueDocument(PrinterQueue* queue)
{
    if(queue->count > 0)
    {
        int front = queue->front;
        queue->front = ++queue->front % queue->capacity;
        queue->count--;
        return queue->documents[front];
    }
    return NULL;
}

void displayPrinterQueue(PrinterQueue* queue)
{
    cout << "=====" << endl;
    cout << "front:\t" << queue->front << endl;
    cout << "back:\t" << queue->back << endl;
    cout << "count:\t" << queue->count << endl;
    for(int i=0; i < queue->capacity; i++)
    {
        if(queue->documents[i] != NULL)
        {
            cout << "["<<i<<"] " << queue->documents[i]->name << endl;
        }
    }
}

int main(int argc, const char * argv[])
{
    Document* d1 = new Document("d1");
    Document* d2 = new Document("d2");
    Document* d3 = new Document("d3");
    Document* d4 = new Document("d4");
    Document* d5 = new Document("d5");
    Document* d6 = new Document("d6");
    Document* d7 = new Document("d7");

    PrinterQueue* queue = new PrinterQueue(5);
    enqueueDocument(queue, d1);
    
    displayPrinterQueue(queue);
    
    enqueueDocument(queue, d2);
    enqueueDocument(queue, d3);
    enqueueDocument(queue, d4);
    
    displayPrinterQueue(queue);
    
    enqueueDocument(queue, d5);
    enqueueDocument(queue, d6);
    enqueueDocument(queue, d7);

    displayPrinterQueue(queue);
    
    Document* doc = dequeueDocument(queue);
    displayDocument(doc);
    delete doc;
    
    doc = dequeueDocument(queue);
    displayDocument(doc);
    delete doc;
    
    displayPrinterQueue(queue);
    
    enqueueDocument(queue, d6);
    enqueueDocument(queue, d7);
    
    displayPrinterQueue(queue);
}
