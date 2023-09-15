#include <bits/stdc++.h>
using namespace std;

bool cmpW(pair<int, int> &a, pair<int, int> &b)
{
    return a.first < b.first;
}

bool cmpP(pair<int, int> &a, pair<int, int> &b)
{
    return a.second > b.second;
}

bool cmpPW(pair<int, int> &a, pair<int, int> &b)
{
    
    double t1 = a.first;
    double t2 = b.first;
    if (t1 == 0)
    {
        t1 = 1;
    }
    if (t2 == 0)
    {
        t2 = 1;
    }
    double r1 = (double)a.second / t1;
    double r2 = (double)b.second / t2;
   
    return r1 > r2;
}

void MaxW(vector<pair<int, int>> &items, int mw)
{

    sort(items.begin(), items.end(), cmpW);

    double weight = 0, profit = 0;
    for (auto i : items)
    {
        if (weight + i.first <= mw)
        {
            profit += i.second;
        }
        else
        {
            int temp = mw - weight;
            double frac = (double)temp / i.first;
            profit += frac * i.second;
            break;
        }
        weight += i.first;
    }
    cout << "Max Weight : " << profit << endl;
}

void MaxPW(vector<pair<int, int>> &items, int mw)
{

    sort(items.begin(), items.end(), cmpPW);

    double weight = 0, profit = 0;
 
    for (auto i : items)
    {
        if (weight + i.first <= mw)
        {
            profit += i.second;
        }
        else
        {
            int temp = mw - weight;
            double frac = (double)temp / i.first;
            profit += frac * i.second;
            break;
        }
        weight += i.first;
    }
    cout << "Max Profit/Weight : " << profit << endl;
}

void MaxP(vector<pair<int, int>> &items, int mw)
{

    sort(items.begin(), items.end(), cmpP);

    double weight = 0, profit = 0;
    for (auto i : items)
    {
        if (weight + i.first <= mw)
        {
            profit += i.second;
        }
        else
        {
            int temp = mw - weight;
            double frac = (double)temp / i.first;
            profit += frac * i.second;
            break;
        }
        weight += i.first;
    }
    cout << "Max Profit : " << profit << endl;
}

int main()
{
    int p[50], w[50], n, mw;
    cin >> n >> mw;

    vector<pair<int, int>> items;

    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++)
    {
        items.push_back({w[i], p[i]});
    }

    MaxW(items, mw);
    MaxP(items, mw);
    MaxPW(items, mw);

    return 0;
}
