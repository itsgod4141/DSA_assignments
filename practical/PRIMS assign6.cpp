
/*
you have a business with several offices you want to lease phone lines to connect them up with each other
and the phone company charges different amount of money to connect different pairs of cities
You want a set of lines that connects all your offices with a minimum total cost .

Solve problem by suggesting approppriate data structure.

*/


#include <iostream>
using namespace std;
class PRIMS
{
    int G[10][10], visited[10];
    int n, e;   //n is for number of cities and e is for number of edges

public:
    PRIMS()
    {
        for (int i = 0; i < 10; i++)
        {
            visited[i] = 0;
            for (int j = 0; j < 10; j++)
            {
                G[i][j] = 0;
            }
        }
    }
    void Accept_graph()
    {
	    int vi, vj;
	    cout << " Enter the no of cities =" << endl;
	    cin >> n;
	    cout << " Enter the no of connecting lines=" << endl;
	    cin >> e;
	    for (int i = 0; i < e; i++)
	    {
	        cout << " Enter the connected pair of cities=" << endl;
	        cin >> vi >> vj;
	        cout << "Enter the cost to connect (" << vi << "," << vj << ") = " << endl;
	        cin >> G[vi][vj];
	        G[vj][vi] = G[vi][vj];
	    }	
    	
	}
    void Display_graph()
    {
	    for (int i = 1; i <= n; i++)
	    {
	        for (int j = i + 1; j <= n; j++)
	        {
	            if (G[i][j] != 0)
	                cout << " Cost to connect (" << i << "," << j << ") =" << G[i][j] << endl;
	        }
	    }
	    cout << " Matrix Representation=" << endl;
	    for (int i = 1; i <= n; i++)
	    {
	        for (int j = 1; j <= n; j++)
	        {
	            cout << " " << G[i][j];
	        }
	        cout << endl;
	    }
	}
	
    void Prims_MST(int v)
    {
    int min = 999, st = 0,  cost = 0, l,k  ;
    
    for (int i = 1; i <= n; i++)
    {
        visited[i] = 0;
    }
    visited[v] = 1;
    
    while (st < n - 1)
    {
	        min = 999;
	        for (int i = 1; i <= n; i++)
	        {
	            if (visited[i])
	            {
	                for (int j = 1; j <= n; j++)
	                {
	                    if ((G[i][j] != 0) && (!visited[j]))
	                    {
	                        if (G[i][j] < min)
	                        {
	                            min = G[i][j];
	                            l = i;
	                            k = j;
	                            
	                        }
	                    }
	                }
	            }
	        }
	        cout << "(" << l << "," << k << ") = " << G[l][k] << "\n ";
	        cost = cost + G[l][k];
	        visited[k] = 1;
	        st++;
	}
	
	cout << "\n Minimum cost required to connect different offices with phone lines=" << cost;
	
	}
};



int main()
{
    PRIMS p;
    int ch, z;
    do
    {
        cout << "\n ------------- MENU -------------";
        cout << "\n 1. Accept Graph ";
        cout << "\n 2. Display Graph ";
        cout << "\n 3. Minimum Spanning Tree ";
        cout << "\n 4. Exit ";
        cout << "\n --------------------------------";
        cout << "\n Enter your choice=>";
        cin >> ch;
        switch (ch)
        {
        case 1:
            
            p.Accept_graph();
            break;
        case 2:
            p.Display_graph();
            break;
        case 3:
            cout << "\n Enter the starting vertex=";
            cin >> z;
            p.Prims_MST(z);
            break;
        case 4:
            cout << "\n Exiting..........";
            break;
        default:
            cout << "\n Enter the correct choice......!";
        }
    } while (ch != 4);
    return 0;
}
