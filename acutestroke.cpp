#include <iostream>
#include <queue>
using namespace std;

int pixel[1300][150][80];
int inqueue[1300][150][80] = {false};
int M, N, L, T;
int sum;
struct Node
{
    int x, y, z;
}node;
int X[6] = {1, -1, 0, 0, 0, 0};
int Y[6] = {0, 0, 1, -1, 0, 0};
int Z[6] = {0, 0, 0, 0, 1, -1};

bool judge(int x, int y, int z);
int BFS(int x, int y, int z);
void DFS(int x, int y, int z);

int main(int argc, const char * argv[])
{
    cin >> M >> N >> L >> T;
    for(int z = 0; z < L; z++)
        for(int x = 0; x < M; x++)
            for(int y = 0; y < N; y++)
                cin >> pixel[x][y][z];
    int ans = 0;
    for(int z = 0; z < L; z++)
        for(int x = 0; x < M; x++)
            for(int y = 0; y < N; y++)
                if(pixel[x][y][z] == 1 && inqueue[x][y][z] == false)
                {
                    //inqueue[x][y][z] = true;
                    // ans += BFS(x, y, z);
                    sum = 0;
                    DFS(x, y, z);
                    if(sum < T)
                        sum = 0;
                    ans += sum;
                }
    
    cout << ans << endl;
    

    return 0;
}

bool judge(int x, int y, int z)
{
    if(x >= M || x < 0 || y >= N || y < 0 || z >= L || z < 0)
        return false;
    else if(pixel[x][y][z] == 0 || inqueue[x][y][z] == true)
        return false;
    else
        return true;
}

int BFS(int x, int y, int z)
{
    int total = 1;
    queue<Node> Q;
    struct Node tmp;
    tmp.x = x; tmp.y = y; tmp.z = z;
    Q.push(tmp);
    // inqueue[x][y][z] = true;
    while(!Q.empty())
    {
        tmp = Q.front();
        Q.pop();
        for(int i = 0; i < 6; i++)
        {
            int newX = tmp.x + X[i];
            int newY = tmp.y + Y[i];
            int newZ = tmp.z + Z[i];
            if(judge(newX, newY, newZ))
            {
                struct Node n;
                n.x = newX; n.y = newY; n.z = newZ;
                Q.push(n);
                inqueue[newX][newY][newZ] = true;
                total++;
            }
        }
    }

    if(total >= T)
        return total;
    else
        return 0;
}

void DFS(int x, int y, int z)
{
    sum++;
    inqueue[x][y][z] = true;
    for(int i = 0; i < 6; i++)
    {
        int newX = x + X[i];
        int newY = y + Y[i];
        int newZ = z + Z[i];
        if(judge(newX, newY, newZ))
            DFS(newX, newY, newZ);
    }
}