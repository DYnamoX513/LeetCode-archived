# 并查集
学习笔记：<https://zhuanlan.zhihu.com/p/93647900/>

## LeetCode template

```c++
class DisjointSet
{
    public:
    vector<int> parent;
    vector<int> rank;
    int count;

    DisjointSet(int n): count(n)
    {
        for (int i = 0; i < n; i++)
        {
            parent.push_back(i);
            rank.push_back(0);
        }
    }
    int find(int x)
    {
        return parent[x] == x ? x : (parent[x] = find(parent[x]));
    }

    void merge(int x, int y)
    {
        int rx = find(x), ry = find(y);
        if (rx != ry)
        {
            if (rank[rx] < rank[ry])
            {
                parent[rx] = ry;
            }else
            {
                parent[ry] = rx;
            }
            count--;
            if (rank[rx] == rank[ry])
                rank[rx] += 1;
        }
    }
};
```
