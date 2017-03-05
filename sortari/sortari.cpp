#include <iostream>
using namespace std;

void selectie(int n,int k[100]);
void citire(int n,int k[100]);
void afisare(int n,int k[100]);
void insertie(int n,int k[100]);
void bublle_sort(int n,int k[100]);
void sortare_rapida(int n,int k[100]);
void quicksort(int n,int k[100],int st,int dr);
void meniu();

void selectie(int n, int k[100]){
	int i,j,ind,t;
	for(i=0;i<n-1;i++){
		ind=i;
		for(j=i;j<n;j++){
			if(k[j]<k[ind]){
				ind=j;
			}
		}
		if(i<ind){
			t=k[i];
			k[i]=k[ind];
			k[ind]=t;
		}
	}
	cout << "Sirul sortat prin selectie:" << endl;
	afisare(n,k);
	cout << "End!" << endl;

}

void insertie(int n,int k[100]){
	int i,ind,a;
	for(i=1;i<n;i++){
		ind=i-1;
		a=k[i];
		while( (ind>=0) && (a<k[ind]) ){
			k[ind+1]=k[ind];
			ind-=1;
		}
		k[ind+1]=a;
	}
	cout << "Sirul sortat prin insertie:" << endl;
	afisare(n,k);
	cout << "End!" << endl;
}

void bublle_sort(int n,int k[100]){
	int i,t;
	bool sortat=true;
	while(sortat){
		sortat=false;
		for(i=0;i<n;i++){
			if(k[i-1]>k[i]){
				t=k[i-1];
				k[i-1]=k[i];
				k[i]=t;
				sortat=true;
			}
		}
	}
	cout << "Buble sort:" << endl;
	afisare(n,k);
	cout << "End!" << endl;
}

void sortare_rapida(int n,int k[100]){
	quicksort(n,k,0,n-1);
}

void quicksort(int n,int k[100],int st,int dr){
	int i,j=dr,a;
	i=st;
	a=k[i];
	do{
		while(k[j]>=a && i<j){
			j=j-1;
		}
		k[i]=k[j];
		while(k[i]<=a && i<j){
			i=i+1;
		}
		k[j]=k[i];
	}while(i!=j);
	k[i]=a;
	if(st<i-1){
		return quicksort(n,k,st,(i-1));
	}
	if(i+1 >dr){
		return quicksort(n,k,(i+1),dr);
	}
	
}



void citire(int n,int k[100]){
	int i;
	for(i=0;i<n;i++){
		cout << "sir[" << i << "]= ";
		cin >> k[i];
	}
}

void afisare(int n,int k[100]){
	int i;
	for(i=0;i<n;i++){
		cout << "sir[" << i << "]= " << k[i] << endl;
	}
}

void meniu(){
	cout << "Pentru a sorta un sir de elemente prima data trebuie sa introduceti unul!" << endl;
	int n,sir[100],x;
	


	do{

		cout << "Introduceti un nr:" << endl;
		cout << "Daca nu doriti citirea unui sir apasati tasta 0" << endl;
		cin >> n;
		if(n==0){
			cout << "Buh bye" << endl;
			break;	
		}
		else{
			citire(n,sir);
		

		
			cout << "1.Sortare prin selectie." << endl;
			cout << "2.Sortare insertie. " << endl;
			cout << "3.Sortare prin buble sort." << endl;
			cout << "4.Sortare rapida. " << endl;
			cout << "0.Iesire" << endl;
			cin >> x;
			switch (x)
		{
		
		case 1:
			selectie(n,sir);
			break;
		case 2:
			insertie(n,sir);
			break;
		case 3:
			bublle_sort(n,sir);
			break;
		case 4:
			sortare_rapida(n,sir);
			afisare(n,sir);
			break;
		case 0:
			cout << "Buh bye!" << endl;
			break;
	
		
		default:
			cout << "Optiune gresita!" << endl;
			break;
			}
		}
	}while(x!=0 && n!=0);

	
}

int main(){
	
	/*cout << "Introduceti un nr:" << endl;
	cin >> n;
	citire(n,sir);
	selectie(n,sir);
	cout << "Introduceti un nr:" << endl;
	cin >> n;
	citire(n,sir);
	insertie(n,sir);
	cout << "Introduceti un nr:" << endl;
	cin >> n;
	citire(n,sir);
	bublle_sort(n,sir);
	
	cout << "Introduceti un nr:" << endl;
	cin >> n;
	citire(n,sir);
	sortare_rapida(n,sir);
	cout << "Qucik sort:" << endl;
	afisare(n,sir);
	cout << "end" << endl;*/
	meniu();
	
	system("pause");
	return 0;
}
