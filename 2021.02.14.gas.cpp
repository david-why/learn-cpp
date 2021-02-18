#include <iostream>
#include <iomanip>

using namespace std;

struct station
{
    station() : p(0.0), d(0.0) {}
    station(double p, double d) : p(p), d(d) {}
    double p;
    double d;
};

int main()
{
    double cmax, d, davg, full, cost = 0.0, tank = 0.0;
    int n, now = 0;
    cin >> cmax >> d >> davg >> n;
    full = cmax * davg;
    struct station *stations[n + 1];
    for (int i = 0; i < n; i++)
    {
        struct station *s = new struct station();
        cin >> s->p >> s->d;
        stations[i] = s;
    }
    stations[n] = new struct station(0.0, d);

    for (int fin = 0; fin < n - 1; fin++)
    {
        int m = fin;
        for (int i = fin; i < n; i++)
        {
            if (stations[i]->d < stations[m]->d)
                m = i;
        }
        struct station *t = stations[m];
        stations[m] = stations[fin];
        stations[fin] = t;
    }
    // for (int i = 0; i < n + 1; i++) cout << fixed << setprecision(2) << i << " " << stations[i]->p << " " << stations[i]->d << endl;

    if (stations[0]->d != 0.0)
    {
        cout << "The maximum travel distance = 0.00" << endl;
        return 0;
    }

    while (1)
    {
        if (now == n)
        {
            //cost += stations[now]->p * davg / (d - stations[now]->d);
            cout << fixed << setprecision(2) << cost << endl;
            return 0;
        }
        int m = -1;
        int m2 = -1;
        for (int i = now + 1; i < n + 1 && stations[now]->d + full >= stations[i]->d; i++)
        {
            if (stations[i]->p < stations[now]->p)
            {
                m = i;
                break;
            }
            if (m2 < 0 || stations[i]->p < stations[m2]->p)
            {
                m2 = i;
            }
        }
        // cout << "next " << m << endl;
        if (m >= 0)
        {
            // cout << "I am more expensive than next... Nevertheless adding " << (stations[m]->d - stations[now]->d) / davg << "L, cost " << stations[now]->p * ((stations[m]->d - stations[now]->d) / davg - tank) << endl;
            cost += stations[now]->p * ((stations[m]->d - stations[now]->d) / davg - tank);
            //tank = (stations[m]->d - stations[now]->d) / davg - tank;
            tank = 0.0;
        }
        else if (m2 >= 0)
        {
            m = m2;
            //double t;
            //if ((t = ((stations[m]->d - stations[now]->d) / davg) - tank) != 0)
            //{
            //cost += stations[now]->p * t;
            // cout << "I am so cheap, only " << stations[now]->p << "/L! Adding to max, added " << cmax - tank << "L" << endl;
            cost += stations[now]->p * (cmax - tank);
            //tank = tank + t - ((stations[m]->d - stations[now]->d) / davg);
            tank = cmax - (stations[m]->d - stations[now]->d) / davg;
            //}
        }
        else
        {
            double got = stations[now]->d + full;
            cout << "The maximum travel distance is " << fixed << setprecision(2) << got;
            return 0;
        }
        now = m;
    }
    return 0;
}
