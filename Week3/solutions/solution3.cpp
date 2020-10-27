#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

class CastleOnTheGrid
{
private:
    bool foundSolution, **used;
    pair<int, int> **predecessors;
    int n;
    stack<pair<int, int>> solution;

    void init(vector<string> grid)
    {
        n = grid.size();
        used = new bool *[n];
        foundSolution = false;
        predecessors = new pair<int, int> *[n];
        for (int i = 0; i < n; i++)
        {
            used[i] = new bool[n];
            predecessors[i] = new pair<int, int>[n];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                used[i][j] = false;
                predecessors[i][j].first = -1;
                predecessors[i][j].second = -1;
            }
        }
    }

public:
    CastleOnTheGrid(vector<string> grid, int startX, int startY, int goalX, int goalY)
    {
        init(grid);
        queue<pair<int, int>> q;
        q.push({startX, startY});
        used[startX][startY] = true;
        while (!q.empty() && !foundSolution)
        {
            pair<int, int> p = q.front();
            q.pop();
            for (int i = p.second + 1; i < n; i++)
            {
                if (grid[p.first][i] == 'X')
                {
                    break;
                }
                if (!used[p.first][i])
                {
                    q.push({p.first, i});
                    used[p.first][i] = true;
                    predecessors[p.first][i] = {p.first, p.second};
                }
                if (i == goalY && p.first == goalX)
                {
                    foundSolution = true;
                    break;
                }
            }
            for (int i = p.second - 1; i >= 0; i--)
            {
                if (grid[p.first][i] == 'X')
                {
                    break;
                }
                if (!used[p.first][i])
                {
                    q.push({p.first, i});
                    used[p.first][i] = true;
                    predecessors[p.first][i] = {p.first, p.second};
                }
                if (i == goalY && p.first == goalX)
                {
                    foundSolution = true;
                    break;
                }
            }
            for (int i = p.first + 1; i < n; i++)
            {
                if (grid[i][p.second] == 'X')
                {
                    break;
                }
                if (!used[i][p.second])
                {
                    q.push({i, p.second});
                    used[i][p.second] = true;
                    predecessors[i][p.second] = {p.first, p.second};
                }
                if (i == goalX && p.second == goalY)
                {
                    foundSolution = true;
                    break;
                }
            }
            for (int i = p.first - 1; i >= 0; i--)
            {
                if (grid[i][p.second] == 'X')
                {
                    break;
                }
                if (!used[i][p.second])
                {
                    q.push({i, p.second});
                    used[i][p.second] = true;
                    predecessors[i][p.second] = {p.first, p.second};
                }
                if (i == goalX && p.second == goalY)
                {
                    foundSolution = true;
                    break;
                }
            }
        }

        if (foundSolution)
        {
            int i = goalX, j = goalY;
            while (i != startX || j != startY)
            {
                if (i == -1 || j == -1)
                {
                    break;
                }
                solution.push({i, j});
                pair<int, int> temp = predecessors[i][j];
                i = temp.first;
                j = temp.second;
            }
        }
    }

    int minimumMoves()
    {
        return foundSolution ? solution.size() : -1;
    }

    void printSolution()
    {
        stack<pair<int, int>> s1 = solution;
        while (!s1.empty())
        {
            pair<int, int> p1 = s1.top();
            s1.pop();
            cout << '(' << p1.first << ", " << p1.second << ")";
            if (!s1.empty())
            {
                cout << " -> ";
            }
        }
    }
};

vector<string> split_string(string input_string)
{
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ')
    {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos)
    {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    vector<string> grid(n);

    for (int i = 0; i < n; i++)
    {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    string startXStartY_temp;
    getline(cin, startXStartY_temp);

    vector<string> startXStartY = split_string(startXStartY_temp);

    int startX = stoi(startXStartY[0]);

    int startY = stoi(startXStartY[1]);

    int goalX = stoi(startXStartY[2]);

    int goalY = stoi(startXStartY[3]);

    CastleOnTheGrid solution(grid, startX, startY, goalX, goalY);

    int result = solution.minimumMoves();

    cout << result << "\n";

    return 0;
}