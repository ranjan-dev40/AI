#include <bits/stdc++.h>
#include <math.h>
using namespace std;

vector<double> gradient, laplace;

void print_vector(vector<double> t)
{
    for (int i = 0; i < t.size(); i++)
    {
        cout << t[i] << " ";
    }

    cout << endl
         << endl
         << endl;
}

void grad(vector<double> x)
{
    for (int i = 1; i < x.size(); i++)
    {
        double m = x[i] - x[i - 1];
        gradient.push_back(m);
    }

    print_vector(gradient);

}

void laplacien(vector<double> x)
{
    for (int i = 1; i < x.size(); i++)
    {
        double m = x[i] - x[i - 1];
        laplace.push_back(m);
    }

    print_vector(laplace);
}

double avr(vector<double> x)
{
    int sum = 0;
    for (int i = 0; i < x.size(); i++)
    {
        sum += x[i];
    }

    return sum / x.size();
}

double variance(vector<double> x, int d)
{
    int sum = 0;

    for (int i = 0; i < x.size(); i++)
    {
        sum += pow(x[i] - d, 2);
    }

    return sum / x.size();
}

// Smoothening Filter of Size 5
void Smoothening(vector<double> data)
{
    vector<double> smoothened;

    for (int i = 0; i < data.size(); i++)
    {
        int sum = 0;
        for (int j = i - 2; j <= i + 2; j++)
        {
            if (j < 0)
            {
                sum += data[0];
            }
            else if (j >= data.size())
            {
                sum += data[data.size() - 1];
            }
            else
            {
                sum += data[j];
            }
        }
        smoothened.push_back(sum / 5);
    }
    cout << "Smoothened: ";
    print_vector(smoothened);
}

void moving_average(vector<double> &data)
{
    vector<double> moving_Average;
    for (double beta = 0.1; beta <= 1.0; beta += 0.1)
    {
        double movingAverageValue = 0.0;
        for (int i = 0; i < data.size(); i++)
        {
            movingAverageValue = beta * data[i] + (1 - beta) * movingAverageValue;
            moving_Average.push_back(movingAverageValue);
        }
        cout << "Beta: " << beta << endl;
        cout << "Moving Average: ";
        print_vector(moving_Average);
        cout << endl;
    }
}

void Normalisation(vector<double> &data)
{
    double mean = avr(data);
    int max = *max_element(data.begin(), data.end()),
        min = *min_element(data.begin(), data.end());

    vector<double> normalisedData;
    for (int i = 0; i < data.size(); i++)
        normalisedData.push_back((data[i] - mean) / (max - min));
    cout << "Normalised Data: ";
    print_vector(normalisedData);
    cout << endl;
}
void adamOptimization1(vector<double> &v, vector<double> &grad, vector<double> &lap)
{
    double alpha = 0.7;
    double epsilon = 1;
    double val;
    vector<double> adamOpt;
    for (int i = 1; i < v.size(); i++)
    {
        val = (v[i] - alpha * grad[i - 1]) / (sqrt((lap[i] * lap[i]) + epsilon));
        adamOpt.push_back(val);
    }
    cout << "adamOptimization" << endl;
    print_vector(adamOpt);
}

int main()
{
    vector<double> data = {0, 2, 1, 22, 2, 1, 3, 5, 9, 15, 8, 10, 10,
                           11, 10, 14, 20, 25, 27, 58, 78, 69, 94, 74, 86, 73, 153, 136, 120,
                           187, 309, 424, 486, 560, 579, 609, 484, 573, 565, 813, 871, 854, 758, 1243,
                           1031, 886, 1061, 922, 1371, 1580, 1239, 1537, 1292,
                           1667, 1408, 1835, 1607, 1568, 1902, 1705, 1801, 2391};

    double mean = avr(data);
    double var = variance(data, mean);
    double st_var = sqrt(var);

    cout << " Mean of dataset: " << mean << endl;
    cout << " Varience of dataset: " << var << endl;
    cout << " Standard deviation of dataset: " << st_var << endl;

    cout << "gredient of the data" << endl;
    grad(data);

    cout << "laplacian of the data" << endl;

    laplacien(gradient);

    Smoothening(data);

    moving_average(data);

    Normalisation(data);
    adamOptimization1(data, gradient, laplace);


    return 0;
}