
#include <bits/stdc++.h>
using namespace std;

#define MAX 4

#define MAX_THREAD 4

int matA[MAX][MAX];
int matB[MAX][MAX];
int matC[MAX][MAX];
int step_i = 0;

void* multi(void* arg)
{
	int i = step_i++; 

	for (int j = 0; j < MAX; j++)
	for (int k = 0; k < MAX; k++)
		matC[i][j] += matA[i][k] * matB[k][j];
}


int main()
{

	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			matA[i][j] = rand() % 10;
			matB[i][j] = rand() % 10;
		}
	}


	cout << endl
		<< "Matrix A" << endl;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++)
			cout << matA[i][j] << " ";
		cout << endl;
	}

	
	cout << endl
		<< "Matrix B" << endl;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++)
			cout << matB[i][j] << " ";	
		cout << endl;
	}


	pthread_t threads[MAX_THREAD];

	
	for (int i = 0; i < MAX_THREAD; i++) {
		int* p;
		pthread_create(&threads[i], NULL, multi, (void*)(p));
	}

	for (int i = 0; i < MAX_THREAD; i++)
		pthread_join(threads[i], NULL);


	cout << endl
		<< "Multiplication of A and B" << endl;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++)
			cout << matC[i][j] << " ";	
		cout << endl;
	}
	return 0;
}
//g++ -pthread program_name.cpp

/*


#include <bits/stdc++.h>
using namespace std;

vector <vector<int>> mat1, mat2, mat3;
int n;

void compute(int r, int c){
	for(int i = 0; i < n; i++){
		mat3[r][c] = mat3[r][c] + mat1[r][i] * mat2[i][c];
	}
}

int main(){


	cin >> n;
	mat1 = mat2 = mat3 = std::vector<vector<int>> (n, vector <int> (n, 0));


	
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cin >> mat1[i][j];
		}
	}

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cin >> mat2[i][j];
		}
	}

	thread threads[n][n];

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			threads[i][j] = thread(compute, i, j);
		}
	}

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			threads[i][j].join();
		}
	}

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cout << mat3[i][j] << " ";
		}
		cout << "\n";
	}


	return 0;
}




*/