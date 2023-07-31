#include <bits/stdc++.h>

using namespace std;
vector<double> s1, s2, s3, s4;
vector<double> g1, g2, g3, g4;

vector<pair<int, vector<double> *>> s = {{0, &s1}, {1, &s2}, {2, &s3}, {3, &s4}};
vector<pair<int, vector<double> *>> g = {{0, &g1}, {1, &g2}, {2, &g3}, {3, &g4}};

double average(int numArray)
{
    double sum = 0;
    for (int i = 0; i < s[numArray].second->size(); i++)
    {
        sum += s[numArray].second->at(i);
    }
    return (sum * 1.0) / (s[numArray].second->size());
}

void printVector(vector<double> gvec)
{
    for (auto &val : gvec)
    {
        cout << val << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> numbers;
    cout << "Enter the range of numbers : (Lower limit  Upper limit) " << endl;
    int lowerLim, upperLim;
    cin >> lowerLim >> upperLim;
    int range = upperLim - lowerLim;
    srand(time(0));
    for (int i = 0; i < 100; i++)
    {
        int x = (rand() % (range + 1)) + lowerLim;
        numbers.push_back(x);
    }

    double seed;
    cout << "Enter Seed 1 : ";
    cin >> seed;
    s1.push_back(seed);
    cout << "Enter Seed 2 : ";
    cin >> seed;
    s2.push_back(seed);
    cout << "Enter Seed 3 : ";
    cin >> seed;
    s3.push_back(seed);
    cout << "Enter Seed 4 : ";
    cin >> seed;
    s4.push_back(seed);

    int epoch = 0;
    while (epoch < 10)
    {
        for (int i = 0; i < numbers.size(); i++)
        {
            int min_diff = abs(numbers[i] - s[0].second->at(0));
            int number = numbers[i];
            int numArray = 0;
            for (int j = 1; j < 4; j++)
            {
                if (abs(numbers[i] - s[j].second->at(0)) < min_diff)
                {
                    min_diff = abs(numbers[i] - s[j].second->at(0));
                    numArray = j;
                }
            }
            s[numArray].second->push_back(number);
            double avg = average(numArray);
            s[numArray].second->at(0) = avg;
        }
        for (int i = 0; i < 4; i++)
        {
            g[i].second->push_back(s[i].second->at(0));
        }

        epoch++;
        // cout << "After Epoch " << epoch << " : " << endl;
        // for (int i = 0; i < g.size(); i++)
        // {
        //     cout << "g" << (i + 1) << " : ";
        //     printVector(*(g[i].second));
        //     // cout << "s" << (i + 1) << " : ";
        //     // printVector(*(s[i].second));
        //     // cout<<endl;
        // }
        int flag = 0;

        for (int i = 0; i < 4; i++)
        {
            int num;
            if (g[i].second->size() >= 2)
            {
                num = g[i].second->size() - 2;
            }
            else
            {
                flag = 1;
                break;
            }
            if (abs(s[i].second->at(0) - (g[i].second)->at(num)) > 0.00005)
            {
                flag = 1;
            }
        }
        if (flag == 1)
        {
            double x = s1[0];
            s1.clear();
            s1.push_back(x);
            x = s2[0];
            s2.clear();
            s2.push_back(x);
            x = s3[0];
            s3.clear();
            s3.push_back(x);
            x = s4[0];
            s4.clear();
            s4.push_back(x);
        }
        else
        {
            cout<<endl;
            cout << "Number of epochs are : " << epoch << endl;
            for (int i = 0; i < s.size(); i++)
            {
                cout << "g" << (i + 1) << " :  ";
                printVector(*(g[i].second));
                cout << "s" << (i + 1) << " :  ";
                printVector(*(s[i].second));
                cout<<endl;
            }
            break;
        }
    }
    
    cout<<"The final mean values are : ";
    for(int i=0; i<s.size(); i++ )
    {
        cout<<g[i].second->at(g[i].second->size()-1)<<" ";
    }
    cout<<endl<<endl;
    return 0;
}