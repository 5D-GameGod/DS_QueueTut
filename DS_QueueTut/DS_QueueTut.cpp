#include <iostream>

using namespace std;

class Queue
{
    private:
        int arr[5];
        int front{};
        int rear{};

    public:
        Queue()
        {
            front = -1;
            rear = -1;
            for(int i{0}; i < 5; i++)
            {
                arr[i] = 0;
            }
        }

        bool isEmpty()
        {
            if(front == -1 && rear == -1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        bool isFull()
        {
            if(rear == 4)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        void enqueue(int val)
        {
            if(isEmpty())
            {
                front = 0;
                rear = 0;
                arr[rear] = val;
                cout << val << " has been succesfully added to the queue." << endl;
            }
            else if(isFull())
            {
                cout << "Queue is jam-packed bruh" << endl;
                return;
            }
            else
            {
                rear++;
                arr[rear] = val;
                cout << val << " has been succesfully added to the queue." << endl;
            }
        }

        int dequeue()
        {
            int x{};
            if(isEmpty())
            {
                return 0;
            }
            else if(front == rear)
            {
                x = arr[front];
                arr[front] = 0;
                front = -1;
                rear = -1;
                return x;
            }
            else
            {
                x = arr[front];
                arr[front] = 0;
                front++;
                return x;
            }
        }

        int count()
        {
            return (rear - (front + 1));
        }

        void display()
        {
            for(int i{0}; i < 5; i++)
            {
                cout << arr[i] << " ";
            }
        }
};

int main()
{
    Queue q1;
    int option{}, value{};

    do
    {
        cout << "\nWhat operation would you like to perform? Select option number. " << endl;
        cout << "0. Exit Application" << endl;
        cout << "1. Add a new number to the queue" << endl;
        cout << "2. Remove number from the queue" << endl;
        cout << "3. Check if the queue is empty" << endl;
        cout << "4. Check if the queue is full" << endl;
        cout << "5. Determine the number of items in the queue" << endl;
        cout << "6. Display all the items in the queue" << endl;
        cout << "7. Clear the screen" << endl;

        cin >> option;

        switch(option)
        {
            case 0:
                break;
            case 1:
                cout << "Please input the value to be added into the queue: ";
                cin >> value;
                q1.enqueue(value);
                break;
            case 2:
                if(q1.dequeue() == 0)
                {
                    cout << "Nothing to remove. Queue is empty." << endl;
                }
                else
                {
                    cout << q1.dequeue() << " has been removed from the queue" << endl;
                }
                break;
            case 3:
                if(q1.isEmpty())
                {
                    cout << "The queue is empty" << endl;
                }
                else
                {
                    cout << "The queue is not empty" << endl;
                }
                break;
            case 4:
                if (q1.isFull())
                {
                    cout << "The queue is full" << endl;
                }
                else
                {
                    cout << "The queue is not full" << endl;
                }
                break;
            case 5:
                cout << "The number of items in the queue is: " << q1.count() << endl;
                break;
            case 6:
                cout << "The numbers in the queue are: " << endl;
                q1.display();
                break;
            case 7:
                system("cls");
                break;
            default:
                cout << "Enter a valid option number!" << endl;
                break;
        }
    } while (option != 0);
    return 0;
}
