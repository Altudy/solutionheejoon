#define N 4

//void doUserImplementation에 필요한 자료형, 함수를 먼저 정의.
typedef struct {
	int strike;
	int ball;
} Result; // typedef 로 struct별칭 짓기.

// API : main.cpp와 같은 프로젝트로 묶여있을 것이므로 extern으로 함수가져옴.
extern Result query(int guess[]);

// 2개의 샘플을 비교하여 strike, ball 반환.
Result fake_query(int key, int obj){
	int count[10] = {0, };
	Result result = {0, 0 };

	for(int i=0; i<N; ++i){ //4 times
		if(key%10 == obj%10) 
			++result.strike;
		else{
			++count[key%10];
			++count[obj%10];
		}
		key /= 10;
		obj /= 10;
	}

	for(int i=0; i<10; ++i)
		if(count[i] == 2) ++ result.ball;

	return result;
}

int A[6000]; 		//순열 갯수: 10*9*8*7 = 5040개.
bool V[10000];		//hash변수. true면 후보가능.
int Count_guess; 	//후보 갯수
int flag_init = 0;

void init(){
	int i, j, k, l;

	if(flag_init == 0){ //init은 1번만 실행.
		flag_init = 1;
		Count_guess = 0;
		for(i=0; i<10; ++i)
			for(j=0; j<10; ++j){
				if(j==i) continue;
				for(k=0; k<10; ++k){
					if(k==i || k==j) continue;
					for(l=0; l<10; ++l){
						if(l==k || l==j || l==i) continue;
						//중복없는 후보를 A[]에 순서대로 넣고 Count_guess로 갯수파악.
						A[Count_guess++] = 1000*i + 100*j + 10*k + l;
					}
				}
			}
	}

	// 후보는 똑같이 다시 쓰이므로 flag_init으로 처리하지만
	// 모든 후보를 후보가능상태로 만들어줘야 한다.
	// register: 변수를 메모리가 아닌 register에서 바로 처리: 속도Up
	// 하지만 당연히 register의 갯수의 한계.
	for(register int i=0; i<Count_guess; ++i)
		V[A[i]] = true;
}

void doUserImplementation(int guess[]){
	Result result;
	Result sub;
	int key;

	init();

	while(1){
		for(register int i=0; i<Count_guess; ++i){
			if(V[A[i]]){ 		//가능 후보이면
				key = A[i];   	//추출해서 query로.
				guess[3] = A[i] % 10;
                guess[2] = (A[i] / 10) % 10;
                guess[1] = (A[i] / 100) % 10;
                guess[0] = A[i] / 1000;
                result = query(guess);
                break;
			}
		}

		if (result.strike == 4) break; //solution check;

		for(register int i=0; i<Count_guess; ++i){
			if(V[A[i]]){
				//key의 결과를 이용하여 후보군 축소.
				sub = fake_query(key, A[i]);
				if(sub.ball == result.ball && sub.strike == result.strike); //가능성 있음.
				else V[A[i]] = false; //가능성 없음. result와 똑같은 결과여야 함.
			}
		}
	}
}
