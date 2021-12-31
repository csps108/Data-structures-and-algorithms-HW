#include<iostream>
#include<ctime>
#include<cstdlib>
#include<iomanip>
#include<windows.h>
using namespace std;
void Insertionsort(int *arr, int len){
    for (int i = 1; i < len; i++) {		//i���ثe�B�z����� 
        int a = arr[i];
        int j = i - 1;					//1~i-1����� 
        while (a < arr[j] && j >= 0) {	//�i���� 
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = a;
    }
}
void Quicksort(int *arr, int left, int right){
	if(left<right){
	int i=left+1,
		j=right,
		pivot=arr[left];
		while (1)
		{
			while (i <= right){
				if (arr[i] > pivot)
                  break;
				i = i + 1;
			}
			while (j > left){
				if (arr[j] < pivot)
                   break;
				j = j - 1;
			}
			if (i > j) 
				break; 
			swap(arr[i], arr[j]);
    }
		swap(arr[left], arr[j]);
        Quicksort(arr, left, j-1);  
        Quicksort(arr, j+1, right);
	}
}
void Adjust(int *arr,const int root,const int n){
	int e=arr[root];
	int j;
	for(j=2*root;j<=n;j*=2){
		if(j<n&&arr[j]<arr[j+1])
			j++;
		if(e>=arr[j])
			break;
		arr[j/2]=arr[j];
	}
	arr[j/2]=e;
}
void Heapsort(int *arr,const int n){
	for(int i=n/2;i>=0;i--)
		Adjust(arr,i,n);
	for(int i=n-2;i>=0;i--){
		swap(arr[0],arr[i+1]);
		Adjust(arr,0,i);
	}
}
void Merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;			//����}�C�� 
    int n2 =  r - m;			//�k��}�C��

    int L[n1], R[n2];			//�������b�M�k�b 
 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2)	 
    {
        if (L[i] <= R[j])		//����̤p<=�k��̤p
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1)				//���b�|��scan��,�k�b�w���� 
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
void Mergesort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
 
        Mergesort(arr, l, m);
        Mergesort(arr, m+1, r);
 
        Merge(arr, l, m, r);
    }
}
void Test(){
	int n1,n2;
	int i;
	srand(time(0));
	cout<<"�п�Jn��";
	cin>>n1;
	cout<<"�п�J0.Insertionsort 1.Quicksort 2.Heapsort 3.Mergesort:";
	cin>>n2;
	int *arr1,*arr2,*arr3,*arr4,*arr5;
	arr1=new int[n1];
	arr2=new int[n1];
	arr3=new int[n1];
	arr4=new int[n1];
	arr5=new int[n1];
	for(i=0;i<n1;i++){
		arr1[i]=(rand()%50000)+1;
		arr2[i]=arr1[i];
		arr3[i]=arr1[i];
		arr4[i]=arr1[i];
		arr5[i]=arr1[i];
	}
	for(i=0;i<n1;i++)
		cout << arr1[i] << endl;
	
	LARGE_INTEGER start,end,fre;
	double times;
	if(n2==0){	
		cout<<"Insertionsort"<<"\n";
		QueryPerformanceFrequency(&fre); //���oCPU�W�v
    	QueryPerformanceCounter(&start);//���o�}����{�b�g�L�X��CPU Cycle
		Insertionsort(arr2,n1);
		cout<<"�Ƨǫ�:";
		for (int i = 0; i < n1; i++) {
			cout << arr2[i] << " ";
		}
		QueryPerformanceCounter(&end); //���o�}����{�����槹���g�L�X��CPU Cycle
		times=((double)end.QuadPart-(double)start.QuadPart)/fre.QuadPart;
		cout <<"Time:"<< fixed << setprecision(8) << times << 's' << endl;
	}
	if(n2==1){	
		cout<<"Quicksort"<<"\n";	
		QueryPerformanceFrequency(&fre); 
    	QueryPerformanceCounter(&start);
		Quicksort(arr3,0,(n1)-1);
		cout<<"�Ƨǫ�:";
		for(i=0;i<n1;i++){
			cout<<arr3[i]<<" ";
		}
		QueryPerformanceCounter(&end); //���o�}����{�����槹���g�L�X��CPU Cycle
		times=((double)end.QuadPart-(double)start.QuadPart)/fre.QuadPart;
		cout <<"Time:"<< fixed << setprecision(8) << times << 's' << endl;
	}
	if(n2==2){
		cout<<"Heapsort:"<<"\n";
		QueryPerformanceFrequency(&fre); 
    	QueryPerformanceCounter(&start);
		Heapsort(arr4,n1);
		cout<<"�Ƨǫ�:";
		for(i=0;i<n1;i++){
			cout<<arr4[i] << " ";
		}
		QueryPerformanceCounter(&end); //���o�}����{�����槹���g�L�X��CPU Cycle
		times=((double)end.QuadPart-(double)start.QuadPart)/fre.QuadPart;
		cout <<"Time:"<< fixed << setprecision(8) << times << 's' << endl;
	}
	if(n2==3){
		cout<<"Mergesort:"<<"\n";
		QueryPerformanceFrequency(&fre); 
    	QueryPerformanceCounter(&start);
		Mergesort(arr5,0,n1-1);
		cout<<"�Ƨǫ�:";
		for(i=0;i<n1;i++){
			cout<<arr5[i] << " ";
		}
		QueryPerformanceCounter(&end); //���o�}����{�����槹���g�L�X��CPU Cycle
		times=((double)end.QuadPart-(double)start.QuadPart)/fre.QuadPart;
		cout <<"Time:"<< fixed << setprecision(8) << times << 's' << endl;
	}
}

int main(){
	srand(time(NULL));
	Test();
	system("pause");
	return 0;
}
