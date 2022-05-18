#include <iostream>
using namespace std;
class JOB
{
    string job;
    int dead, profit;

public:
    JOB()
    {
        job = " ";
        dead = profit = 0;
    }
    friend class GREEDY_SEQUENCE;
};
class GREEDY_SEQUENCE
{
    JOB J[10];
    string sequence[11];
    int n;

public:
    void Init()
    {
        n = 0;
        for (int i = 0; i < 10; i++)
        {
            sequence[i] = J[i].job = " ";
            J[i].dead = J[i].profit = 0;
        }
    }
    void accept_jobs();
    void sort_jobs();
    void job_sequence();
};
void GREEDY_SEQUENCE::accept_jobs()
{
    cout << " Enter the no of jobs(max.10)=" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << " Enter the job name, deadline and profit=" << endl;
        cin >> J[i].job >> J[i].dead >> J[i].profit;
    }
    cout << "\n ---------------------------------";
    cout << "\n JOBS Deadlines Profit ";
    cout << "\n ---------------------------------";
    for (int i = 0; i < n; i++)
    {
        cout << "\n " << J[i].job << " " << J[i].dead << " " << J[i].profit;
    }
    cout << "\n ---------------------------------";
}
void GREEDY_SEQUENCE::sort_jobs()
{
    JOB temp;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < (n - i); j++)
        {
            if (J[j].profit < J[j + 1].profit)
            {
                temp = J[j];
                J[j] = J[j + 1];
                J[j + 1] = temp;
            }
        }
    }
}
void GREEDY_SEQUENCE::job_sequence()
{
    int dmax = 0, empty = 0, k, profit = 0;
    sort_jobs();
    cout << "\n Jobs sorted according decreasing profits=>";
    cout << "\n ---------------------------------";
    cout << "\n JOBS Deadlines Profit ";
    cout << "\n ---------------------------------";
    for (int i = 0; i < n; i++)
    {
        cout << "\n " << J[i].job << " " << J[i].dead << " " << J[i].profit;
    }
    cout << "\n ---------------------------------";
    for (int i = 0; i < n; i++)
    {
        if (J[i].dead > dmax)
            dmax = J[i].dead;
    }
    empty = dmax;
    for (int i = 0; i < n && empty > 0; i++)
    {
        k = J[i].dead;
        while (k > 0)
        {
            if (sequence[k] == " ")
            {
                sequence[k] = J[i].job;
                empty--;
                profit = profit + J[i].profit;
                break;
            }
            else
                k--;
        }
    }
    int TWT = 0;
    cout << "\n The GREEDY job sequence=>";
    for (int i = 1; i <= dmax; i++)
    {
        TWT = TWT + i - 1;
        cout << " " << sequence[i];
    }
    cout << "\n TOTAL PROFIT=>" << profit;
    cout << "\n TOTAL TIME SPENT BY ALL JOBS=>" << dmax + TWT;
}
int main()
{
    GREEDY_SEQUENCE S;
    int ch;
    do
    {
        cout << "\n -------------- MENU ---------------";
        cout << "\n 1.ACCEPT JOBS ";
        cout << "\n 2.GREEDY JOB SEQUENCE ";
        cout << "\n 3.EXIT ";
        cout << "\n -------------------------------------";
        cout << "\n Enter your choice=>";
        cin >> ch;
        switch (ch)
        {
        case 1:
            S.Init();
            S.accept_jobs();
            break;
        case 2:
            S.job_sequence();
            break;
        case 3:
            cout << "\n Exiting from Program.........!";
            break;
        default:
            cout << "\n Enter the correct choice........!";
        }
    } while (ch != 3);
    return 0;
}
