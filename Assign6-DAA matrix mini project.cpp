//1nd method
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




//2nd method
/*
#include<bits/stdc++.h>
using namespace std;
int board[8][8]={0};
bool ispossible(int r,int c){
    for(int j=0;j<8;j++){
        if(board[r][j]==1){
            return false;
        }
    }
    for(int j=0;j<8;j++){
        if(board[j][c]==1){
            return false;
        }
    }
    for(int i=r,j=c;j>=0 && i>=0;i--,j--){
        if(board[i][j]==1){
            return false;
        }
    }
    for(int i=r,j=c;j<8 && i<8;i++,j++){
        if(board[i][j]==1){
            return false;
        }
    }
    for(int i=r,j=c;j>=0 && i<8;i++,j--){
        if(board[i][j]==1){
            return false;
        }
    }
    for(int i=r,j=c;j<8 && i>=0;i--,j++){
        if(board[i][j]==1){
            return false;
        }
    }
    return true;
}
void print(){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void fx(int r){
    if(r==8){
        print();
        cout<<"\n";
        return ;
    }
    for(int i=0;i<8;i++){
        if(board[r][i]==1){
            fx(r+1);
        }
        else if(ispossible(r,i)==true){
            board[r][i]=1;
            fx(r+1);
            board[r][i]=0;
        }
    }
    return ;
}
int main(){
    print();
    int r=0;
    int c=0;
    cout<<"\n"<<"Give Row and Column with space: ";
    cin>>r>>c;
    board[r][c]=1;
    fx(0);
}
*/