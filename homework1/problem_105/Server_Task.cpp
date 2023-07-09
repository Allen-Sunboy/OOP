#include "Server.h"
#include "Task.h"
#include <cstring>

Server::Server(int N, int M)
{
    n0 = N;
    m0 = M;
    for(int i = 1; i <= n0; i++)
    {
        aa[i] = m0; //from 1
    }
}

void Server::tick()
{
    ti++;
}

Task::Task(char s[], int d, int n, int m)
{
    strcpy(name,s);
    dur = d;
    task_num = n;
    task_cap = m;
}


bool Server::submit_task(Task task)
{
    for(int i = 0; i < server_num; i++)
    {
        if(ti >= finish_time[i])
        {
            for(int j = 0; j < num[i]; j++)
            {
                aa[put[i][j]] += cap[i];
            }
            memset(server_name[i], 0, sizeof(server_name[i]));
            finish_time[i] = 2000;
        }
    }
    int ansn = 0;
    for(int i = 1; i <= n0; i++)
    {
        if(aa[i] >= task.task_cap)
        {
            put[server_num][ansn] = i; 
            ansn++;
            continue;
        }
    }
    if(ansn>=task.task_num)
    {
        strcpy(server_name[server_num], task.name);
        num[server_num] = task.task_num;
        cap[server_num] = task.task_cap;
        for(int i = 0; i < num[server_num]; i++)
            aa[put[server_num][i]] -= task.task_cap;
        
        finish_time[server_num] = ti + task.dur;
        server_num++;
        return 1;
    }
    else
        return 0;

}

bool Server::cancel_task(char *s)
{
    for(int i = 0; i < server_num; i++)
    {
        if(strcmp(s, server_name[i]) == 0 && ti < finish_time[i])
        {
            for(int j = 0; j < num[i]; j++)
            {
                aa[put[i][j]] += cap[i];
            }
            memset(server_name[i], 0, sizeof(server_name[i]));
            cap[i] = 0;
            finish_time[i] = 2000;
            return 1;
        }
    }
    return 0;
}

