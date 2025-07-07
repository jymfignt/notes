#include <iostream>
using namespace std;

//1.linear search
int linearSearch(int n,int x,int *a)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==x) return i;
    }
    return -1;
}
//2.1 binary search（recursion)
int BinarySearch1(int low,int high,int *a,int x)
{
    int mid=(low+high)/2;
    if(low<high)
    {
        if(a[mid]==x) return mid;
        else if(a[mid]<x) return BinarySearch1(mid+1,high,a,x);
        else return BinarySearch1(low,mid-1,a,x);
    }
    return -1;
}
//2.2 binary search（loop)
int BinarySearch2(int low,int high,int* a,int x)
{
    while(low<high)
    {
        int mid=(low+high)/2;
        if(a[mid]==x) return mid;
        else if(a[mid]<x) low=mid+1;
        else high=mid-1;
    }
    return -1;
}
//3.merge sort
void Merge(int*a,int first,int mid,int last)
{
    int n1 = mid - first + 1;
    int n2 = last - mid;
    int *left = new int[n1];
    int *right = new int[n2];
    for(int i = 0; i < n1; i++)
        left[i] = a[first + i];
    for(int j = 0; j < n2; j++)
        right[j] = a[mid + 1 + j];

    int i = 0, j = 0, k = first;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j])
            a[k++] = left[i++];
        else
            a[k++] = right[j++];
    }

    while (i < n1)
        a[k++] = left[i++];
    while (j < n2)
        a[k++] = right[j++];

    delete[] left;
    delete[] right;
}
void mergeSort(int* a,int first,int last)
{
    if(first<last)
    {
        int mid=(first+last)/2;
        mergeSort(a,first,mid);
        mergeSort(a,mid+1,last);
        Merge(a,first,mid,last);
    }
}
//4.quick sort
int partion(int*a,int first,int last)
{
    int i=first;

    for(int j=first+1;j<=last;j++)
    {
        if(a[j]<a[first])
        {
            i++;
            if (i!=j) swap(a[i],a[j]);
        }
    }
    swap(a[first],a[i]);
    return i;
}
void quickSort(int*a,int first,int last)
{
    if(first<last)
    {
        int pivot=partion(a,first,last);
        quickSort(a,first,pivot-1);
        quickSort(a,pivot+1,last);
    }
}
//5.finding maximum and minimum
void Finding(int* a,int first,int last,int&maxi,int&mini)
{
    if(first==last)
    {
        maxi=mini=a[first];
    }
    else if(last-first==1)
    {
        if(a[first]<a[last])
        {
            mini=a[first];
            maxi=a[last];
        }
        mini=a[last];
        maxi=a[first];
    }
    else
        {
            int mid=(first+last)/2;
            int max1, min1, max2, min2;
            Finding(a,first,mid,max1,min1);
            Finding(a,mid+1,last,max2,min2);
            maxi = (max1 > max2) ? max1 : max2;
            mini = (min1 < min2) ? min1 : min2;
        }
  }
//6.bubble sort(method 2)
void bubbleSort(int* a, int n)
{
    bool sorted = false;
    for (int i = 0; i < n - 1 && !sorted; i++)
    {
        sorted = true;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                sorted = false;
            }
        }
    }
}
//7.selection sort
void selectionSort(int* a,int n)
{
    for(int i=0;i<n-1;i++)
    {
        int minIndex=i;
        for (int j=i+1;j<n;j++)
        {
            if(a[j]<a[minIndex])
            {
                swap(a[minIndex],a[j]);
                minIndex=j;
            }

        }
    }
}
int main()
{
    //1.
    int arr1[5]={1,3,4,5,2};
    int result1=linearSearch(5,3,arr1);
    if(result1!=-1) cout<<"The number is in the index of "<<result1+1<<endl;
    else cout<<"Failed to find the value!\n";
    cout<<endl;
    //2.1
    int arr2[10]={1,3,4,5,7,8,11,12,15,16};
    int result2=BinarySearch1(0,9,arr2,8);
    if(result2!=-1) cout<<"The number is in the index of "<<result2+1<<endl;
    else cout<<"Failed to find the value!\n";
    cout<<endl;
    //2.2
    int result2_2=BinarySearch2(0,9,arr2,8);
    if(result2_2!=-1) cout<<"The number is in the index of "<<result2_2+1<<endl;
    else cout<<"Failed to find the value!\n";
    cout<<endl;
    //3
    int arr3[5]={1,9,8,5,15};
    mergeSort(arr3,0,4);
    for(int n=0;n<5;n++)
        cout<<arr3[n]<<" ";
    cout<<endl<<endl;
    //4
    int arr4[5]={1,5,4,21,18};
    quickSort(arr4,0,4);
    for(int n=0;n<5;n++)
        cout<<arr4[n]<<" ";
    cout<<endl<<endl;
    //5
    int arr5[10]={1,5,8,4,16,61,45,24,19,23};
    int maximum,minimum;
    Finding(arr5,0,9,maximum,minimum);
    cout<<"Maximum: "<<maximum<<endl;
    cout<<"Minimum: "<<minimum<<endl;
    cout<<endl;
    //6
    int arr6[5]={1,5,3,8,7};
    bubbleSort(arr6,5);
    for(int n=0;n<5;n++)
        cout<<arr6[n]<<" ";
    cout<<endl<<endl;
    //7
    int arr7[5]={1,8,4,9,15};
    selectionSort(arr7,5);
    for(int n=0;n<5;n++)
        cout<<arr7[n]<<" ";
    cout<<endl<<endl;
    return 0;
}








