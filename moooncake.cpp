#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Cake
{
    double num, value, price;
};

int main(int argc, const char *argv[])
{
    int N;
    double D;
    cin >> N >> D;
    Cake moon[N];
    for(int i = 0; i < N; i++)
        cin >> moon[i].num;
    for(int i = 0; i < N; i++)
    {
        cin >> moon[i].value;
        moon[i].price = moon[i].value / moon[i].num;
    }
    double sum = 0.0;
    bool vis[N];
    fill(vis, vis + N, false);
    while(D)
    {
        int index = -1;
        double max = -1;
        for(int i = 0; i < N; i++)
            if(vis[i] == false && moon[i].price > max)
            {
                index = i;
                max = moon[i].price;
            }
        
        vis[index] = true;
        if(moon[index].num <= D)
        {
            sum += moon[index].value;
            D -= moon[index].num;
        }
        else
        {
            double tmp = moon[index].num - D;
            D = 0;
            sum += tmp * moon[index].price;
        }

    }

    cout << fixed << setprecision(2) << sum << endl;

    return 0;
}