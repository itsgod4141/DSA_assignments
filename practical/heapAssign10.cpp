
/* Read the marks obtained by the student of second year in an online examination of particular subject.
Find out maximum and minimum marks obtained in that subject.Use heap data structure.
Analyze the algorithm.


*/
#include<iostream>
using namespace std;

void maxHeapify(int heap[],int i,int n)
{
    int left=2*i;
    int right=(2*i)+1;
    int largest=i;
     
    if(left<=n && heap[i]<heap[left])
    	{
	
        	largest=left;
        
		}
		
		
    if(right<=n && heap[largest]<heap[right])
    {
	
        largest=right;
         
        if(largest !=i)
        {
            int temp=heap[largest];
            heap[largest]=heap[i];
            heap[i]=temp;
            
            maxHeapify(heap,largest,n);
        }
	}
}
void buildHeap(int heap[],int n)
{
            for(int i=n/2;i>=1;i--)
            maxHeapify(heap,i,n);
             
             
}
int main()
{
    int n;
    int heap[n+1];   //heap array is created;
    
    
    cout<<"Enter No Of Elements ";
    cin>>n;

    cout<<"Enter Marks :";
    for(int i=1;i<=n;i++)
    {
		cin>>heap[i];
	}
	
    buildHeap(heap,n);
    
    int heapSize=n;
    
    for(int i=n;i>=2;i--)
    {  
        int temp=heap[1];
        heap[1]=heap[i];
        heap[i]=temp;
        --heapSize;
        maxHeapify(heap,1,heapSize);
    }
    
    cout<<"After Sorting "<<endl;
    for(int i=1;i<=n;i++)
    {
		cout<<heap[i]<<" ";
	}
    cout<<"MAXIMUM MARKS ::"<<heap[1]<<endl;
    cout<<"MINIMUM MARKS ::"<<heap[n]<<endl;
    return 0;
}
