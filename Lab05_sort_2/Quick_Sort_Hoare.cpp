#include<iostream>
using namespace std;
int LomutoSwap, HoareSwap, LomutoComp, HoareComp;

int Lomuto_partition(int a[], int low, int high){

    int i,j;
    int pivot, pivotPos, tmp;

    pivot = a[low];
    j = low;

    for(i = low+1; i<=high; i++){
        LomutoComp++;
        if(a[i] < pivot){
            j++;
            LomutoSwap++;
            swap(a[i], a[j]);
        }
    }
    
    LomutoSwap++;
    pivotPos = j;
    swap(a[pivotPos], a[low]);

    return pivotPos;
}

int Hoare_partition(int a[], int low, int high){

    int i, j;
    int pivot, tmp;

    pivot = a[low];
    i = low - 1;
    j = high + 1;

    while(1){
        HoareComp++;
        while(a[++i] < pivot)
            HoareComp++;

        HoareComp++;
        while(a[--j] > pivot)
            HoareComp++;

        if(i < j){
            HoareSwap++;
            swap(a[i], a[j]);
        }

        else return j;
    }
}

void Lomuto_quickSort(int a[], int low, int high){
    int pivotPos;

    if(low >= high)
        return ;

    pivotPos = Lomuto_partition(a, low, high);
    Lomuto_quickSort(a, low, pivotPos-1);
    Lomuto_quickSort(a, pivotPos+1, high);

}

void Hoare_quickSort(int a[], int low, int high){

    int pivotPos;

    if(low >= high)
        return ;

    pivotPos = Hoare_partition(a, low, high);
    Hoare_quickSort(a, low, pivotPos);
    Hoare_quickSort(a, pivotPos+1, high);

}

int main(){
    //freopen("input.txt", "r", stdin);
    int tc, n;
    scanf("%d", &tc);
    for(int t=0;t<tc;t++){
        int h[1001], l[1001];

        scanf("%d", &n);
        for(int i=0;i<n;i++){
            scanf("%d",&h[i]);
            l[i] = h[i];
        }
        LomutoSwap = HoareSwap = LomutoComp = HoareComp = 0;
        Lomuto_quickSort(l, 0, n-1);
        Hoare_quickSort(h, 0, n-1);
        printf("%d %d %d %d\n", HoareSwap, LomutoSwap, HoareComp, LomutoComp);

    }

    return 0;
}