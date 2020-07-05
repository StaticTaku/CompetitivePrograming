#include <bits/stdc++.h>
using namespace std;

vector<int> primesArray() 
{
    vector<bool> judge(10001, true);
    vector<int> primes;
    
    for (int i = 2; i <= 10000; i++) 
    {
        if (judge[i]) 
        {
            primes.push_back(i);
            int j = 2*i;
            while (j < 10001) 
            {
                judge[j] = false;
                j += i;
            }
        }
    }
    return primes;
}

int main() {
    vector<int> primes = primesArray();
    int N;
    while (scanf("%d", &N) && N) 
    {
        int answer = 0, sum = 0, a = 0;

        for (int b = 0; b < primes.size(); ++b) 
        {
            sum += primes[b];
            while (a <= b && sum > N) 
            {
                sum -= primes[a];
                a++;
            }
            if (a > b)
                break;
            if (N == sum)
                answer++;
        }
        cout << answer << endl;
    }
    return 0;
}