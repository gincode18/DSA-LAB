#include <iostream>
using namespace std;
class queue
{
public:
  int front, rear;
  int size;
  int *Q;
  queue(int y)
  {
    size = y;
    front = rear = 0;
    Q = (int *)malloc(size * (sizeof(int)));
  }
  int enqueue(int x)
  {

    if ((rear + 1) % size == front)
    {
      cout << "Queue is full";
    }
    else
    {
      rear = rear+1 ;
      *(Q + rear) = x;
    }
    return 0;
  }
  int deque()
  {

    if (rear == front)
    {
      cout << "queue is empty\n";
    }
    else
    {
      front = (front + 1) % size;
      check();
    }
    return 0;
  }
  int check()
  {
    for (int i = front + 1; i <= rear; i++)
    {
      cout << Q[i] << endl;
    }
    return 0;
  }
};
int main()
{
  queue a(5);
  int x;

  cout << "enter choice \n 1. for enque \n 2.for deque \n 3. print queue \n 4. to exit\n";
  while (x != 4)
  {
    cout << "enter choise \n";
    cin >> x;
    switch (x)
    {
    case (1):
    {
      int y;
      cout << "enter element";
      cin >> y;
      a.enqueue(y);
    }

    break;
    case (2):
    {
      a.deque();
    }
    break;
    case (3):
    {
      a.check();
    }
    break;
    case (4):
    {
    }
    break;
    default:
    {
      cout << "enter a valid argument\n";
    }
    break;
    }
  }
  cout << "exiting";

  return 0;
}