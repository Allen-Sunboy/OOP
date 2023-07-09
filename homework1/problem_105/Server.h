class Task;
class Server{
    public:
    int n0; //num
    int m0; //capacity
    int aa[200];
    int ti; //cur_time
    char server_name[220][30];
    int put[220][150]; //pointer
    int cap[220];
    int num[220];
    int finish_time[220];
    int server_num; //store
    Server(int N, int M);
    bool cancel_task(char *s);
    bool submit_task(Task task);
    void tick();
};