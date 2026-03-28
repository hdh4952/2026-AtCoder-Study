#include <stdio.h>
#include <stdlib.h>
#include <map>

int compare_ints(const void* a, const void* b) //taken from cppreference
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

int main(void)
{
    int numberOfQueries;
    std::map<int, int> treeList;
    int numberOfTrees = 0;
    scanf("%d", &numberOfQueries);
    for(int i = 0; i < numberOfQueries; i++)
    {
        int queryType, height;
        scanf("%d %d", &queryType, &height);
        switch(queryType)
        {
        case 1:
            treeList[height] += 1;
            numberOfTrees++;
            break;
        case 2:
            while(!treeList.empty() && treeList.begin()->first <= height)
            {
                numberOfTrees -= treeList.begin()->second;
                treeList.erase(treeList.begin());
            }
            break;
        default:
            printf("oops\n");
            break;
        }
        printf("%d\n", numberOfTrees);
    }
    return 0;
}
